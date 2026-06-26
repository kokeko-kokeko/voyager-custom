#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/connection_status.h"
#include "addons/status_led.h"

#include "addons/sub_trackball.h"

#include "navigator_trackpad_common.h"

static fast_timer_t connection_status_trigger = CONNECTION_STATUS_INIT_DELAY;
static bool connection_update_flag = false;

static bool right_side_flag = false;
static bool trackpad_flag = false;
static bool trackball_flag = false;

layer_state_t layer_state_set_connection_status(layer_state_t state) {
    connection_update_flag = true;

    return state;
}

void housekeeping_task_connection_status(void) {
  const fast_timer_t now = timer_read_fast();

  // timer
  if (timer_expired_fast(now, connection_status_trigger) == false) return;
  connection_status_trigger += CONNECTION_STATUS_PROBE_DELAY;

  if (is_transport_connected() != right_side_flag) {
    connection_update_flag = true;
    right_side_flag = is_transport_connected();
  }

  if (trackpad_init != trackpad_flag) {
    connection_update_flag = true;
    trackpad_flag = trackpad_init; 
  }
  
  if (trackball_init != trackball_flag) {
    connection_update_flag = true;
    trackball_flag = trackball_init; 
  }

  if (connection_update_flag) {
    if (right_side_flag == false) {
      status_led(0b1000, led_pattern_blink);
    } else {
      status_led(0b1000, led_pattern_off);  
    }

    if (trackpad_flag != trackball_flag) {
      if (trackpad_flag == false) {
        status_led(0b0010, led_pattern_on);
      }

      if (trackball_flag == false) {
        status_led(0b0010, led_pattern_blink);
      }
    } else {
      status_led(0b0010, led_pattern_off);
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
