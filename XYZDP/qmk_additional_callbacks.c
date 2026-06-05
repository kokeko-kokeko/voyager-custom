#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// module impl
#include "addons/adv_trackpad.h"
#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/ime_state_sync.h"
#include "addons/layer_mod_overlay.h"
#include "addons/mouse_button_overlay.h"
#include "addons/ortho_hold_os_locale_aware.h"
#include "addons/status_led.h"
#include "addons/sub_trackball.h"

#include "layer_num.h"

// access to voyager system-side flag
//extern keyboard_config_t keyboard_config;
//extern bool is_launching;

// idle loop to sleep 
#include "ch.h"
void chSysIdleHook(void) {
  __DSB();
  __WFI();
}

void keyboard_post_init_user(void) {
  // config.h
  //keymap_config.nkro = true;

  keyboard_post_init_addtional_power_setting();
  keyboard_post_init_adv_trackpad();
  keyboard_post_init_fade_matrix();
  keyboard_post_init_status_led();
	keyboard_post_init_sub_trackball();

  // no transition / jis / pc mode
  layer_move(LAYER_Base);
  layer_off(LAYER_Transition);
	
  jis_enable();
  mac_disable();
}

void matrix_scan_user(void) {
  matrix_scan_sub_trackball();
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  if (process_detected_host_os_fade_matrix(detected_os) == false) return false;
  if (process_detected_host_os_ortho_hold_os_locale_aware(detected_os) == false) return false;

  return true;
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
			case HOOR(KC_SPACE):
			
			case HOOR(KC_B):
			case HOOR(KC_V):
		
			case THOR1(KC_L): 
			case THOR1(KC_R):
		
			case HOOR(KC_F11):
			case HOOR(KC_F12):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  
  return 0;  // Disable Flow Tap.
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // same side thumb and pin
  state = update_tri_layer_state(state, LAYER_Number, LAYER_L_pinky, LAYER_L_thumb_L_pinky);
  state = update_tri_layer_state(state, LAYER_Cursor, LAYER_R_pinky, LAYER_R_thumb_R_pinky);
  
  // both outer pin
  state = update_tri_layer_state(state, LAYER_L_pinky, LAYER_R_pinky, LAYER_LR_pinky);
  
  // cross side thumb and pin
  state = update_tri_layer_state(state, LAYER_Number, LAYER_R_pinky, LAYER_L_thumb_R_pinky);
  state = update_tri_layer_state(state, LAYER_Cursor, LAYER_L_pinky, LAYER_R_thumb_L_pinky);

  // both thumb
  state = update_tri_layer_state(state, LAYER_Number, LAYER_Cursor, LAYER_LR_thumb);
    
  // call FwSys
  state = update_tri_layer_state(state, LAYER_Function, LAYER_L_thumb_2, LAYER_Firmware); 

  state = layer_state_set_fade_matrix(state);
  state = layer_state_set_firmware_map(state);
	state = layer_state_set_sub_trackball(state);
	
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  //if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  
  switch (layer) {
    case LAYER_Base:
    case LAYER_Transition:
      status_led(0b1111, led_pattern_off);
      break;
    case LAYER_Mouse_L:
    case LAYER_Mouse_R:
      // mouse indication
      status_led(0b1000, led_pattern_on);
      // clear scroll bit
      status_led(0b0100, led_pattern_off);
      break;
    case LAYER_Number:
    case LAYER_Cursor: 
    case LAYER_Function:   
	  // mouse on keep top bit
      status_led(0b0011, led_pattern_off);
      status_led(0b0100, led_pattern_delayed_on);
      break;
    case LAYER_R_thumb_1:
    case LAYER_L_thumb_2:
    case LAYER_R_thumb_2:
    case LAYER_L_pinky:
    case LAYER_R_pinky:  
      status_led(0b1111, led_pattern_off);
      break;
    case LAYER_L_thumb_L_pinky:
      status_led(0b1001, led_pattern_off);
      status_led(0b0110, led_pattern_on);
      break;
    case LAYER_R_thumb_R_pinky:
      status_led(0b1010, led_pattern_off);
      status_led(0b0101, led_pattern_on);
      break;
    case LAYER_LR_pinky:
      status_led(0b1100, led_pattern_off);
      status_led(0b0011, led_pattern_on);
      break;
    case LAYER_L_thumb_R_pinky:
    case LAYER_R_thumb_L_pinky:
    case LAYER_LR_thumb:
      status_led(0b1000, led_pattern_off);
      status_led(0b0111, led_pattern_on);
      break;
    case LAYER_Mouse_Upper_L:
    case LAYER_Mouse_Upper_R:
      // mouse indication
      status_led(0b1000, led_pattern_on);
      // DRAG_SCROLL add on key event
      // aim/turbo change without layer, direct write on process_record
      break;    
    case LAYER_Firmware:
      status_led(0b0101, led_pattern_off);
	  status_led(0b1010, led_pattern_on);
      break;
    case LAYER_Color_Palette:
      status_led(0b0100, led_pattern_off);
      status_led(0b1011, led_pattern_on);
      break;
    
    default:
      status_led(0b1111, led_pattern_off);
      break;
  }  
  return state;
}

bool rgb_matrix_indicators_user(void) {
  // disable rawhid
  //if (rawhid_state.rgb_control) {
  //    return false;
  //}
  if (keyboard_config.disable_layer_led) { return false; }
  switch (get_highest_layer(layer_state)) {
    case LAYER_Firmware:
      set_layer_color_firmware_map();
      break;
    case LAYER_Color_Palette:
      set_layer_color_palette_map();
      break;
    
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      } else {
        set_layer_color_overlay_mouse_button();
        set_layer_color_overlay_mod();
        set_layer_color_overlay_ime_state_sync();
        set_layer_color_overlay_layer();
      }
      break;
  }
  return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (pre_process_record_fade_matrix(keycode, record) == false) return false;
  if (pre_process_record_ime_state_sync(keycode, record) == false) return false;
  
  return true;
}

// process_record_user in waymap.c, use _additional and insert it
bool process_record_additional(uint16_t keycode, keyrecord_t *record) {
  //if (process_record_fade_matrix(keycode, record) == false) return false;
  if (process_record_ime_state_sync(keycode, record) == false) return false;
  if (process_record_ortho_hold_os_locale_aware(keycode, record) == false) return false;
  
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  post_process_record_adv_trackpad(keycode, record);
  post_process_record_ime_state_sync(keycode, record);
  post_process_record_sub_trackball(keycode, record);
	
  return;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  //mouse_report = pointing_device_task_adv_mouse(mouse_report);
  mouse_report = pointing_device_task_fade_matrix(mouse_report);
  
  return mouse_report;
}

void housekeeping_task_user(void) {
  housekeeping_task_adv_trackpad();
  housekeeping_task_fade_matrix();
  housekeeping_task_ime_state_sync();
  housekeeping_task_status_led();
	housekeeping_task_sub_trackball();

  // exec halt last
  housekeeping_task_exec_halt();

  return;
}
