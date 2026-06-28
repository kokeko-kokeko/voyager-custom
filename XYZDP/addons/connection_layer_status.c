#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/connection_layer_status.h"
#include "addons/status_led.h"

#include "addons/sub_trackball.h"

#include "navigator_trackpad_common.h"

static fast_timer_t connection_status_trigger = CONNECTION_STATUS_INIT_DELAY;

static bool connection_update_flag = false;

static bool right_side_flag = false;
static bool trackpad_flag = false;
static bool trackball_flag = false;

layer_state_t layer_state_set_connection_layer_status(layer_state_t state) {
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  //if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  
  switch (layer) {
    case LAYER_Base:
    case LAYER_Transition:
      status_led(0b1111, led_pattern_off);

      // state change overwrite status LED, re-calc
      // return to base layer update
      connection_update_flag = true;
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

void housekeeping_task_connection_layer_status(void) {
  const fast_timer_t now = timer_read_fast();

  // timer
  if (timer_expired_fast(now, connection_status_trigger) == false) return;
  connection_status_trigger += CONNECTION_STATUS_PROBE_DELAY;

  if (is_transport_connected() != right_side_flag) {
    right_side_flag = is_transport_connected();
    connection_update_flag = true;
  }

  if (trackpad_init != trackpad_flag) {
    trackpad_flag = trackpad_init; 
    connection_update_flag = true;
  }
  
  if (trackball_init != trackball_flag) {
    trackball_flag = trackball_init; 
    connection_update_flag = true;
  }
  
  // both on, both off, no error
  if (connection_update_flag) {
    // reset flag
    connection_update_flag = false;
    
    // Green for Right side
    if (right_side_flag == false) {
      status_led(0b0011, led_pattern_blink);
    } else {
      status_led(0b0011, led_pattern_off);  
    }

    // Red for mouse
    if (trackpad_flag != trackball_flag) {
      if (trackpad_flag == false) {
        status_led(0b1000, led_pattern_blink);
      }

      if (trackball_flag == false) {
        status_led(0b0100, led_pattern_blink);
      }
    } else {
      status_led(0b1100, led_pattern_off);
    }
  }
}

/*
  if (timer_expired_fast(now, fade_matrix_init_trigger)) {
  // connect check
    if (is_transport_connected() == false) {
      // connection error
      rgb_matrix_enable_noeeprom();
      rgb_matrix_config.mode = RGB_MATRIX_BREATHING;
      rgb_matrix_config.hsv.h = 43;
      rgb_matrix_config.hsv.s = 255;

      if (fade_matrix_target.hsv.v < val_tbl[FADE_MATRIX_INDEX_COUNT / 2]) {
        rgb_matrix_config.hsv.v = val_tbl[FADE_MATRIX_INDEX_COUNT / 2];
      } else {
        rgb_matrix_config.hsv.v = fade_matrix_target.hsv.v;
      }
      
      rgb_matrix_config.speed = 255;

      // after connect update fast
      activate_fade_matrix();

      return;
    }

    // trackpad & trackball check
    if (trackpad_init != trackball_init) {
      // both connect or both disconnect, nothing do
      if (trackpad_init == false) {
        // trackpad connection error
        rgb_matrix_enable_noeeprom();
        rgb_matrix_config.mode = RGB_MATRIX_BREATHING;
        rgb_matrix_config.hsv.h = 200;
        rgb_matrix_config.hsv.s = 255;

        if (fade_matrix_target.hsv.v < val_tbl[FADE_MATRIX_INDEX_COUNT / 2]) {
          rgb_matrix_config.hsv.v = val_tbl[FADE_MATRIX_INDEX_COUNT / 2];
        } else {
          rgb_matrix_config.hsv.v = fade_matrix_target.hsv.v;
        }
      
        rgb_matrix_config.speed = 255;

        // after connect update fast
        activate_fade_matrix();
        
        return;
      }

      if (trackball_init == false) {
        // trackball connection error
        rgb_matrix_enable_noeeprom();
        rgb_matrix_config.mode = RGB_MATRIX_BREATHING;
        rgb_matrix_config.hsv.h = 0;
        rgb_matrix_config.hsv.s = 255;

        if (fade_matrix_target.hsv.v < val_tbl[FADE_MATRIX_INDEX_COUNT / 2]) {
          rgb_matrix_config.hsv.v = val_tbl[FADE_MATRIX_INDEX_COUNT / 2];
        } else {
          rgb_matrix_config.hsv.v = fade_matrix_target.hsv.v;
        }
      
        rgb_matrix_config.speed = 255;

        // after connect update fast
        activate_fade_matrix();
        
        return;
      }
    }

*/
