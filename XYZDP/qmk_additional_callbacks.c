#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "virt_layer.h"

// module impl
#include "addons/color_palette.h"
#include "addons/connection_layer_os_swap_status.h"
#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/flexible_behavior_os_locale.h"
#include "addons/ime_state_sync.h"
#include "addons/layer_caps_word.h"
#include "addons/layer_mod_overlay.h"
#include "addons/mouse_button_indicator.h"
#include "addons/pos_press_overlay.h"
#include "addons/status_led.h"

// access to voyager system-side flag
//extern keyboard_config_t keyboard_config;
//extern bool is_launching;

// idle loop to sleep 
#include "ch.h"
void chSysIdleHook(void) {
  __DSB();
  __WFI();
}

// per-key tapping parameter
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  return TAPPING_TERM;
}

// flow tap target key
bool is_flow_tap_key(uint16_t keycode) {
  if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
    return false; // Disable Flow Tap on hotkeys.
  }
  switch (get_tap_keycode(keycode)) {
    case KC_SPC:
    case KC_A ... KC_Z:
    case KC_DOT:
    case KC_COMM:
    case KC_SCLN:
    case KC_SLSH:
      return true;
  }
  return false;
}

// tap flow control
// bool is_flow_tap_key(uint16_t keycode) is default
// disable (return 0)
// thumb space LT 
// cursor LT
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (keycode) {
			case PTMH(KC_SPACE):
			
			case PTMH(KC_B):
			case PTMH(KC_V):
		
			case ENSN(KC_L): 
			case ENSN(KC_R):
		
			case PTMH(KC_F11):
			case PTMH(KC_F12):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  
  return 0;  // Disable Flow Tap.
}

void keyboard_post_init_user(void) {
  keyboard_post_init_addtional_power_setting();
  keyboard_post_init_connection_layer_os_swap_status();
  keyboard_post_init_fade_matrix();
  keyboard_post_init_status_led();
  
  // no transition / jis / pc mode
  layer_move(0);
  
  virt_layer_on(VIRT_LAYER_Base);
  virt_layer_off(VIRT_LAYER_Transition);
  virt_layer_on(VIRT_LAYER_FB_JIS);
  virt_layer_off(VIRT_LAYER_FB_Mac);
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  if (process_detected_host_os_connection_layer_os_swap_status(detected_os) == false) return false;
  if (process_detected_host_os_fade_matrix(detected_os) == false) return false;
  if (process_detected_host_os_flexible_behavior_os_locale(detected_os) == false) return false;

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // update tri layer on virt first
  state = layer_state_set_virt_layer(state);

  // addon
  state = layer_state_set_color_palette(state);
  state = layer_state_set_connection_layer_os_swap_status(state);
  state = layer_state_set_fade_matrix(state);
  state = layer_state_set_firmware_map(state);
  state = layer_state_set_layer_caps_word(state);
  
  return state;
}

bool rgb_matrix_indicators_user(void) {
  // disable rawhid
  //if (rawhid_state.rgb_control) {
  //    return false;
  //}
  //if (keyboard_config.disable_layer_led) { return false; }
  
  // manual ordering
  if (rgb_matrix_indicators_color_palette() == false) return false;
  if (rgb_matrix_indicators_firmware_map() == false) return false;
  if (rgb_matrix_indicators_mouse_button_indicator() == false) return false;
  if (rgb_matrix_indicators_ime_state_sync() == false) return false;
  if (rgb_matrix_indicators_layer_mod_overlay() == false) return false;
  if (rgb_matrix_indicators_pos_press_overlay() == false) return false;

  return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (pre_process_record_fade_matrix(keycode, record) == false) return false;
  if (pre_process_record_ime_state_sync(keycode, record) == false) return false;
  if (pre_process_record_layer_caps_word(keycode, record) == false) return false;
  if (pre_process_record_pos_press_overlay(keycode, record) == false) return false;
  
  return true;
}

// process_record_user in keymap.c, create _additional and insert it
bool process_record_additional(uint16_t keycode, keyrecord_t *record) {
  //if (process_record_fade_matrix(keycode, record) == false) return false;
  if (process_record_flexible_behavior_os_locale(keycode, record) == false) return false;
  if (process_record_ime_state_sync(keycode, record) == false) return false;
  
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  post_process_record_ime_state_sync(keycode, record);
	
  return;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report = pointing_device_task_fade_matrix(mouse_report);
  
  return mouse_report;
}

void housekeeping_task_user(void) {
  housekeeping_task_connection_layer_os_swap_status();
  housekeeping_task_fade_matrix();
  housekeeping_task_ime_state_sync();
  housekeeping_task_pos_press_overlay();
  housekeeping_task_status_led();

  // exec halt last
  housekeeping_task_exec_halt();

  return;
}
