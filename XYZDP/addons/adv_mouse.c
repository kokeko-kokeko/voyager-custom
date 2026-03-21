#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/adv_mouse.h"
#include "addons/status_led.h"

#include "automouse.h"

// zsa side
extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;

static bool lock_scrolling = false;

// auto_mouse_layer_off() only on housekeeping, other set timer
static fast_timer_t auto_mouse_early_off_trigger = 0;

// 0 to 7 = left, 8 to 15 = right, button 8 count
static const fast_timer_t btn_early_off_delay[16] = {
  AUTO_MOUSE_TIME_LONG,  AUTO_MOUSE_TIME_LONG,  AUTO_MOUSE_TIME_MID,   AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_MID,   AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT
};

static void post_process_record_non_mouse(uint16_t keycode, keyrecord_t *record) {
  // mouse non-active skip
  if (layer_state_is(LAYER_Mouse) == false) return;

  // keep on mouse number and cursor
  if (layer_state_is(LAYER_Mouse_Upper_Left) == true) return;
  if (layer_state_is(LAYER_Mouse_Upper_Right) == true) return;
  if (layer_state_is(LAYER_Number) == true) return;
  if (layer_state_is(LAYER_Cursor) == true) return;

  // keycode check
  if (IS_MOUSEKEY(keycode) == true) return;
  if (IS_QK_MOMENTARY(keycode) == true) return;
  //if (IS_QK_LAYER_TAP(keycode) == true) return;
  if (keycode ==  LGUI(KC_TAB)) return;
  
  if (record->event.pressed) {
    // non-mouse key press 
    auto_mouse_early_off_trigger = timer_read_fast() + (UINT32_MAX / 2) - 1;
  } else {
    // non-mouse key release, exit 
    auto_mouse_early_off_trigger = timer_read_fast() + 1;
  } 

  return;
}

static void post_process_record_mouse_button(uint16_t keycode, keyrecord_t *record) {
  // only mouse button
  if (IS_MOUSEKEY_BUTTON(keycode) == false) return;

  const fast_timer_t now = timer_read_fast();

  uint8_t index = keycode - QK_MOUSE_BUTTON_1;
  
  // right hand
  if (record->event.key.row >= MATRIX_ROWS / 2) index += 8;
  
    // 0 to 7 = left, 8 to 15 = right, button 8 count
  static uint16_t press_time[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
  };
  
  if (record->event.pressed) {
    // press
    press_time[index] = record->event.time;
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    // early trigger reset on auto_mouse_activation

    return;
  }
  
  // release
  static fast_timer_t release_time[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
  };

  if (TIMER_DIFF_16(record->event.time, press_time[index]) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset
    release_time[index] = now + (UINT32_MAX / 2) - 1;
    
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    return;
  }
    
  //tap
  if (TIMER_DIFF_FAST(now, release_time[index]) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //single tap (far from previous release)
    release_time[index] = now;
    
    auto_mouse_early_off_trigger = now + btn_early_off_delay[index];
    
    return;
  }
  
  //double tap or more
  //keep continue
  release_time[index] = now;
  
  auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
  
  return;
}

static void post_process_record_mouse_button_multi_release(uint16_t keycode, keyrecord_t *record) {
  // only mouse button
  if (IS_MOUSEKEY_BUTTON(keycode) == false) return;

  const fast_timer_t now = timer_read_fast();

  if (record->event.pressed) {
    // press, ignore

    return;
  }
  
  // release
  static fast_timer_t release_time = 0;
  
  //tap
  if (TIMER_DIFF_FAST(now, release_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //single tap (far from previous release)
    release_time = now;
        
    return;
  }
  
  //double tap or more
  //keep continue
  release_time = now;
  
  auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
  
  return;
}

// -----------------------------------------------------------------------------
//
//
// Split set layer impl
// after func overwrite before result
//
//
// -----------------------------------------------------------------------------

static layer_state_t layer_state_set_mouse_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, LAYER_Mouse)) return state;
  layer_on = !layer_on;

  if (layer_on) {
    // entered
    
    return state;
  }

  // exited
  // reset state
  set_scrolling = false;
  lock_scrolling = false;
  
  navigator_turbo = false;
  navigator_aim = false;
  status_led(0b0111, led_pattern_off);

  return state;
}

static layer_state_t layer_state_set_mouse_upper_left_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, LAYER_Mouse_Upper_Left)) return state;
  layer_on = !layer_on;
  
  const fast_timer_t now = timer_read_fast();

  static fast_timer_t enter_time = 0;
  
  if (layer_on) {
    // entered
    enter_time = now;
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    return state;
  }
  
  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }

  // multi tap (use ==)
  exit_time = now;
  if (exit_count != 0) exit_count++;
  
  return state;
}

static layer_state_t layer_state_set_mouse_upper_right_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, LAYER_Mouse_Upper_Right)) return state;
  layer_on = !layer_on;
  
  const fast_timer_t now = timer_read_fast();

  static fast_timer_t enter_time = 0;
  
  if (layer_on) {
    // entered
    enter_time = now;
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    return state;
  }
  
  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }

  // multi tap (use ==)
  exit_time = now;
  if (exit_count != 0) exit_count++;
  
  return state;
}

static layer_state_t layer_state_set_mouse_number_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, LAYER_Number)) return state;
  layer_on = !layer_on;
  
  const fast_timer_t now = timer_read_fast();

  static fast_timer_t enter_time = 0;
  
  if (layer_on) {
    // entered
    enter_time = now;
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    return state;
  }
  
  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }

  // multi tap (use ==)
  exit_time = now;
  if (exit_count != 0) exit_count++;

  if (exit_count == 2) {
    auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
        
    lock_scrolling = true;

    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
      
    return state;
  }  

  if (exit_count == 3) {
    auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = true;
    
    navigator_turbo = true;
    navigator_aim = false;
    status_led(0b0010, led_pattern_off);
    status_led(0b0001, led_pattern_delayed_on);

    return state;
  }
  
  return state;
}

static layer_state_t layer_state_set_mouse_cursor_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, LAYER_Cursor)) return state;
  layer_on = !layer_on;

  const fast_timer_t now = timer_read_fast();

  static fast_timer_t enter_time = 0;

  if (layer_on) {
    // entered
    enter_time = now;
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    
    return state;
  }

  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
  
    lock_scrolling = false;
  
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;   
    
    navigator_turbo = false;
    navigator_aim = false;
    status_led(0b0011, led_pattern_off);
    
    return state;
  }
    
  // multi tap (use ==)
  exit_time = now;
  if (exit_count != 0) exit_count++;
  
  if (exit_count == 2) {
    auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = false;
      
    navigator_turbo = false;
    navigator_aim = true;
    status_led(0b0001, led_pattern_off);
    status_led(0b0010, led_pattern_delayed_on);
    
    return state;
  }
  
  if (exit_count == 3) {
    auto_mouse_early_off_trigger = now + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = false;
    
    navigator_turbo = true;
    navigator_aim = false;
    status_led(0b0010, led_pattern_off);
    status_led(0b0001, led_pattern_delayed_on);
    
    return state;
  }
  
  return state;
}

static layer_state_t layer_state_set_mouse_auto_block_scrolling(layer_state_t state) {
  bool layer_state_or = false;
  
  layer_state_or = layer_state_or || layer_state_cmp(state, LAYER_Color_Palette);
  layer_state_or = layer_state_or || layer_state_cmp(state, LAYER_Firmware);
  
  if (layer_state_or) {
    set_scrolling = false;
    // not update mouse flag (LED)
    //state = remove_auto_mouse_layer(state, true);
    //set_auto_mouse_enable(false);
    automouse_disable();
    
    return state;
  }
  
  //layer_state_or = layer_state_or || layer_state_cmp(state, L_Mouse_Cursor);
  //layer_state_or = layer_state_or || layer_state_cmp(state, L_Mouse_Number);
  layer_state_or = layer_state_or || lock_scrolling;

  if (layer_state_or) {
    set_scrolling = true;
    status_led(0b0100, led_pattern_delayed_on);
    
    return state;
  }
  
  layer_state_or = layer_state_or || layer_state_cmp(state, LAYER_Cursor);
  layer_state_or = layer_state_or || layer_state_cmp(state, LAYER_Number);
  
  //if (layer_state_or) {
  //  set_scrolling = true;
  //  activate_mouse_flag(true);
  //  if (is_auto_mouse_active() == false) {
  //    set_auto_mouse_enable(false);
  //  }
  //  
  //  return state;
  //}
  
  layer_state_or = layer_state_or || layer_state_cmp(state, LAYER_Function);

  if (layer_state_or) {
    set_scrolling = true;
    status_led(0b0100, led_pattern_delayed_on);
    
    if (automouse_is_active() == false) {
      automouse_disable();
    }
    
    return state;
  }

  if (layer_state_cmp(state, LAYER_Mouse)) {
    // update LED, no scroll
    set_scrolling = false;
    status_led(0b0100, led_pattern_off);

    //set_auto_mouse_enable(true);
    automouse_enable();
  
    return state;
  }

  // all test layers off
  set_scrolling = false;
  status_led(0b0100, led_pattern_off);

  automouse_enable();
  
  return state;
}

void keyboard_post_init_adv_mouse(void) {
  const fast_timer_t now = timer_read_fast();

  auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;

  return;
}

void post_process_record_adv_mouse(uint16_t keycode, keyrecord_t *record) {
  post_process_record_non_mouse(keycode, record);
  post_process_record_mouse_button(keycode, record);
  post_process_record_mouse_button_multi_release(keycode, record);

  return;
}

report_mouse_t pointing_device_task_adv_mouse(report_mouse_t mouse_report) {
  // move detect
  bool move_or = false;
  
  move_or = move_or || (mouse_report.x != 0);
  move_or = move_or || (mouse_report.y != 0);
  move_or = move_or || (mouse_report.h != 0);
  move_or = move_or || (mouse_report.v != 0);

  if (move_or) {
    auto_mouse_early_off_trigger =  timer_read_fast() + (UINT32_MAX / 2) - 1;
  }
  
  return mouse_report;
}

layer_state_t layer_state_set_adv_mouse(layer_state_t state) {
  // update pinkey overwrite
  state = update_tri_layer_state(state, LAYER_Mouse, LAYER_L_pinky, LAYER_Mouse_Upper_Left);
  state = update_tri_layer_state(state, LAYER_Mouse, LAYER_R_pinky, LAYER_Mouse_Upper_Right);
  
  state = layer_state_set_mouse_edge_detect(state);
  state = layer_state_set_mouse_upper_left_edge_detect(state);
  state = layer_state_set_mouse_upper_right_edge_detect(state);
  state = layer_state_set_mouse_number_edge_detect(state);
  state = layer_state_set_mouse_cursor_edge_detect(state);
  state = layer_state_set_mouse_auto_block_scrolling(state);

  return state;
}

void housekeeping_task_adv_mouse(void) {
  const fast_timer_t now = timer_read_fast();

  if (timer_expired_fast(now, auto_mouse_early_off_trigger)) {
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    //auto_mouse_layer_off();
    automouse_disable();
    layer_off(LAYER_Mouse);
    automouse_enable();
  }
  
  return;
}

void set_layer_color_overlay_mouse(void) {
  if (layer_state_is(LAYER_Mouse) == false) return;
  
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  rgb_matrix_set_color_all(o, o, o);

  if (layer_state_is(LAYER_Mouse_Upper_Left) == false) {
    // low
    
    // left side
    rgb_matrix_set_color(11, 0, f, h);
    
    rgb_matrix_set_color(17, 0, 0, f);
    
    rgb_matrix_set_color(24, 0, f, 0);
    rgb_matrix_set_color(25, f, 0, 0);
  } else {
    // up
    
    // left side
    rgb_matrix_set_color(11, h, 0, f);
    
    rgb_matrix_set_color(17, 0, h, f);
    
    rgb_matrix_set_color(24, f, f, 0);
    rgb_matrix_set_color(25, f, 0, h);
  }

  if (layer_state_is(LAYER_Mouse_Upper_Right) == false) {
    // low
    
    // right side
    rgb_matrix_set_color(26, 0, f, h);
    rgb_matrix_set_color(27, 0, f, 0);
    
    rgb_matrix_set_color(32, 0, 0, f);
    
    rgb_matrix_set_color(38, f, 0, 0);
  } else {
    // up
    
    // right side 
    rgb_matrix_set_color(26, h, 0, f);
    rgb_matrix_set_color(27, f, f, 0);
   
    rgb_matrix_set_color(32, 0, h, f);
    
    rgb_matrix_set_color(38, f, 0, h);
  }
  
  //rgb_matrix_set_color(44, q, q, q);
  rgb_matrix_set_color(47, q, o, 0);
  rgb_matrix_set_color(48, f, h, 0);
  
  // scroll
  if (set_scrolling) {
    if (navigator_turbo && navigator_aim) {
      rgb_matrix_set_color(0, f, f, 0);
    } else if (navigator_turbo) {
      rgb_matrix_set_color(0, f, h, 0);
    } else if (navigator_aim) {
      rgb_matrix_set_color(0, 0, f, h);
    } else {
      rgb_matrix_set_color(0, 0, h, f);
    }
    
    rgb_matrix_set_color(22, h, 0, 0);
    rgb_matrix_set_color(45, h, 0, 0);
  } else {
    if (navigator_turbo && navigator_aim) {
      rgb_matrix_set_color(0, f, f, f);
    } else if (navigator_turbo) {
      rgb_matrix_set_color(0, f, 0, 0);
    } else if (navigator_aim) {
      rgb_matrix_set_color(0, 0, f, 0);
    } else {
      rgb_matrix_set_color(0, 0, 0, f);
    }
    
    rgb_matrix_set_color(22, h, h, h);
    rgb_matrix_set_color(45, h, h, h);
  }
}
