#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/adv_trackpad.h"
#include "addons/status_led.h"

// costom expose count
#include "navigator_trackpad_ptp.h"

static fast_timer_t trackpad_early_off_trigger = 0;

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
    trackpad_early_off_trigger = timer_read_fast() + (UINT32_MAX / 2) - 1;
  } else {
    // non-mouse key release, exit 
    trackpad_early_off_trigger = timer_read_fast() + 1;
  } 

  return;
}

void keyboard_post_init_adv_trackpad(void) {
  const fast_timer_t now = timer_read_fast();

  trackpad_early_off_trigger = now + (UINT32_MAX / 2) - 1;

  return;
}


void post_process_record_adv_trackpad(uint16_t keycode, keyrecord_t *record) {
  post_process_record_non_mouse(keycode, record);

  return;
}

layer_state_t layer_state_set_adv_trackpad(layer_state_t state) {
  // update pinkey overwrite
  state = update_tri_layer_state(state, LAYER_Mouse, LAYER_L_pinky, LAYER_Mouse_Upper_Left);
  state = update_tri_layer_state(state, LAYER_Mouse, LAYER_R_pinky, LAYER_Mouse_Upper_Right);
  
  return state;
}

void housekeeping_task_adv_trackpad(void) {
  const fast_timer_t now = timer_read_fast();

  if (navigator_trackpad_finger_count > 0) {
    trackpad_early_off_trigger = now + AUTO_MOUSE_TIME_MID;
    layer_on(LAYER_Mouse);
    return;
  }

  if (timer_expired_fast(now, trackpad_early_off_trigger)) {
    trackpad_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    //auto_mouse_layer_off();
    //automouse_disable();
    layer_off(LAYER_Mouse);
    //automouse_enable();
  }
  
  return;
}

void set_layer_color_overlay_trackpad(void) {
  if (layer_state_is(LAYER_Mouse) == false) return;
  
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  if (is_transport_connected() == false) {
    rgb_matrix_set_color_all(o, o, 0);
  } else {
    rgb_matrix_set_color_all(o, o, o);
  }
  
  if (layer_state_is(LAYER_Mouse_Upper_Left) == false) {
    // low
    
    // left side
    rgb_matrix_set_color(5, 0, f, h);  //4
    
    rgb_matrix_set_color(11, 0, 0, f);  //3
    
    rgb_matrix_set_color(17, 0, f, 0);  //2
  } else {
    // up
    
    // left side
    rgb_matrix_set_color(5, h, 0, f);  //8
    
    rgb_matrix_set_color(11, 0, h, f);  //7
    
    rgb_matrix_set_color(17, f, f, 0);  //6
    
    rgb_matrix_set_color(23, f, 0, h);  //5
  }

  // both up/low
  rgb_matrix_set_color(25, f, 0, 0);  //1

  if (layer_state_is(LAYER_Mouse_Upper_Right) == false) {
    // low
    
    // right side
    rgb_matrix_set_color(26, 0, f, h);  //4
    
    rgb_matrix_set_color(32, 0, 0, f);  //3
    
    rgb_matrix_set_color(38, f, 0, 0);  //1
  } else {
    // up
    
    // right side 
    rgb_matrix_set_color(26, h, 0, f);  //8
   
    rgb_matrix_set_color(32, 0, h, f);  //7
    
    rgb_matrix_set_color(38, f, 0, h);  //5

    rgb_matrix_set_color(44, f, f, 0);  //6
  }

  // both up/low
  rgb_matrix_set_color(27, 0, f, 0);  //2
  
  //rgb_matrix_set_color(44, q, q, q);
  //rgb_matrix_set_color(47, q, o, 0);
  //rgb_matrix_set_color(48, f, h, 0);
  
  // task veiw
  rgb_matrix_set_color(0, 0, 0, f);
}
