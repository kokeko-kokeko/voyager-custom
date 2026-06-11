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

#define TRACKPAD_AUTO_LAYER LAYER_Mouse_L

static void post_process_record_non_mouse(uint16_t keycode, keyrecord_t *record) {
  // mouse non-active skip
  if (layer_state_is(TRACKPAD_AUTO_LAYER) == false) return;

  // keep on mouse number and cursor
  if (layer_state_is(LAYER_Mouse_Upper_L) == true) return;
  if (layer_state_is(LAYER_Mouse_Upper_R) == true) return;
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

void housekeeping_task_adv_trackpad(void) {
  const fast_timer_t now = timer_read_fast();

  if (navigator_trackpad_finger_count > 0) {
    trackpad_early_off_trigger = now + AUTO_MOUSE_TIME_TRACKPAD;
    layer_on(TRACKPAD_AUTO_LAYER);

    // clear flag
    navigator_trackpad_finger_count = 0;
    
    return;
  }

  if (timer_expired_fast(now, trackpad_early_off_trigger)) {
    trackpad_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    layer_off(TRACKPAD_AUTO_LAYER);
  }
  
  return;
}
