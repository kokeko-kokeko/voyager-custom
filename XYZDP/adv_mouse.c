#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "adv_mouse.h"

#include "layer_num.h"

#include "status_led.h"

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

// mouse status delayed display
static bool set_scrolling_delayed = false;
static bool navigator_turbo_delayed = false;
static bool navigator_aim_delayed = false;

static fast_timer_t mouse_flag_update_trigger = 0;

bool get_mouse_flag_scrolling(void) {
  return set_scrolling_delayed;
}

bool get_mouse_flag_turbo(void) {
  return navigator_turbo_delayed;
}

bool get_mouse_flag_aim(void) {
  return navigator_aim_delayed;
}

static void activate_mouse_flag(const fast_timer_t now, const bool pressed) {
  
  
  if (pressed) {
    mouse_flag_update_trigger = now + TAPPING_TERM;
  } else {
    mouse_flag_update_trigger = now + 1;
  }
  return;
}

static void update_mouse_flag(const fast_timer_t now) {
  if (timer_expired_fast(now, mouse_flag_update_trigger) == false) return;
  mouse_flag_update_trigger = now + (UINT32_MAX / 2) - 1;
  
  // update
  set_scrolling_delayed = set_scrolling;
  navigator_turbo_delayed = navigator_turbo;
  navigator_aim_delayed = navigator_aim;
  
  if (get_mouse_flag_scrolling()) {
    status_led(0b0100, led_pattern_on);
  } else {
    status_led(0b0100, led_pattern_off);
  }
    
  if (get_mouse_flag_turbo()) {
    status_led(0b0001, led_pattern_on);
  } else {
    status_led(0b0001, led_pattern_off);
  }
    
  if (get_mouse_flag_aim()) {
    status_led(0b0010, led_pattern_on);
  } else {
    status_led(0b0010, led_pattern_off);
  }
  return;
}


static void post_process_record_non_mouse(uint16_t keycode, keyrecord_t *record) {
  // mouse non-active skip
  if (layer_state_is(L_Mouse) == false) return;

  // keep on mouse number and cursor
  if (layer_state_is(L_Mouse_Number) == true) return;
  if (layer_state_is(L_Mouse_Cursor) == true) return;

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

  uint8_t index = keycode - KC_MS_BTN1;
  
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
  if (layer_on == layer_state_cmp(state, L_Mouse)) return state;
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

  activate_mouse_flag(now_buffer, false);

  return state;
}

static layer_state_t layer_state_set_mouse_number_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, L_Mouse_Number)) return state;
  layer_on = !layer_on;

  static fast_timer_t enter_time = 0;
  
  if (layer_on) {
    // entered
    enter_time = now_buffer;
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    
    return state;
  }
  
  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now_buffer, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now_buffer;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now_buffer, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now_buffer;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;
    
    navigator_turbo = false;
    navigator_aim = false;
    
    return state;
  }

  // multi tap (use ==)
  exit_time = now_buffer;
  if (exit_count != 0) exit_count++;

  if (exit_count == 2) {
    auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
        
    lock_scrolling = true;

    navigator_turbo = false;
    navigator_aim = false;
      
    return state;
  }  

  if (exit_count == 3) {
    auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = true;
    
    navigator_turbo = true;
    navigator_aim = false;

    return state;
  }
  
  return state;
}

static layer_state_t layer_state_set_mouse_cursor_edge_detect(const layer_state_t state) {
  static bool layer_on = false;
  if (layer_on == layer_state_cmp(state, L_Mouse_Cursor)) return state;
  layer_on = !layer_on;
  
  static fast_timer_t enter_time = 0;

  if (layer_on) {
    // entered
    enter_time = now_buffer;
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    
    return state;
  }

  // exited
  static fast_timer_t exit_time = 0;
  static uint8_t exit_count = 0;
  
  if (TIMER_DIFF_FAST(now_buffer, enter_time) >= AUTO_MOUSE_DRAG_THRESHOLD) {
    // drag, reset all
    exit_time = now_buffer;
    exit_count = 1;
    
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
  
    lock_scrolling = false;
  
    navigator_turbo = false;
    navigator_aim = false;
    
    return state;
  }
  
  //tap
  if (TIMER_DIFF_FAST(now_buffer, exit_time) >= AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
    //1 tap (far from previous release)
    exit_time = now_buffer;
    exit_count = 1;
    
    if (lock_scrolling || navigator_turbo || navigator_aim) {
      auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
    } else {
      auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_SHORT;
    }
    
    lock_scrolling = false;   
    
    navigator_turbo = false;
    navigator_aim = false;
    
    return state;
  }
    
  // multi tap (use ==)
  exit_time = now_buffer;
  if (exit_count != 0) exit_count++;
  
  if (exit_count == 2) {
    auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = false;
      
    navigator_turbo = false;
    navigator_aim = true;
    
    return state;
  }
  
  if (exit_count == 3) {
    auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_LONG;
    
    lock_scrolling = false;
    
    navigator_turbo = true;
    navigator_aim = false;
    
    return state;
  }
  
  return state;
}

static layer_state_t layer_state_set_mouse_auto_block_scrolling(layer_state_t state) {
  bool layer_state_or = false;
  
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Halt_Mask);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Set_Speed);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Set_Val);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Set_Sat);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Set_Hue);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Firmware);
  
  if (layer_state_or) {
    set_scrolling = false;
    // not update mouse flag (LED)
    state = remove_auto_mouse_layer(state, true);
    set_auto_mouse_enable(false);
    
    return state;
  }
  
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Mouse_Cursor);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Mouse_Number);
  layer_state_or = layer_state_or || lock_scrolling;

  if (layer_state_or) {
    set_scrolling = true;
    activate_mouse_flag(now_buffer, true);
    
    return state;
  }
  
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Cursor);
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Number);
  
  if (layer_state_or) {
    set_scrolling = true;
    activate_mouse_flag(now_buffer, true);
    if (is_auto_mouse_active() == false) {
      set_auto_mouse_enable(false);
    }
    
    return state;
  }
  
  layer_state_or = layer_state_or || layer_state_cmp(state, L_Function);

  if (layer_state_or) {
    set_scrolling = true;
    // not update mouse flag (LED)
    if (is_auto_mouse_active() == false) {
      set_auto_mouse_enable(false);
    }
    
    return state;
  }

  // all test layers off
  set_scrolling = false;
  activate_mouse_flag(now_buffer, false);
  set_auto_mouse_enable(true);
  
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
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
  }
  
  return mouse_report;
}

layer_state_t layer_state_set_adv_mouse(const layer_state_t state) {
  state = layer_state_set_mouse_edge_detect(state);
  state = layer_state_set_mouse_number_edge_detect(state);
  state = layer_state_set_mouse_cursor_edge_detect(state);
  state = layer_state_set_mouse_auto_block_scrolling(state);

  return state;
}

void housekeeping_task_adv_mouse(void) {
  const fast_timer_t now = timer_read_fast();
  
  update_mouse_flag(now); 

  if (timer_expired_fast(now, auto_mouse_early_off_trigger)) {
    auto_mouse_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    auto_mouse_layer_off();
  }
  
  return;
}
