#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// module safe-guard
#ifndef KEYBOARD_zsa_voyager
#    error "this file contains ZSA Voyager only magic number constants"
#endif

#include "layer/virt_layer.h"

#include "pos/get_pos_from_keyrecord.h"

#include "status/status_led.h"

#include "firmware_map.h"

#include "fade_matrix.h"
#include "ime_state_sync.h"

#include "navigator.h"
#include "navigator_trackpad_common.h"

// mouse jiggler fucn
bool mouse_jiggler_is_enabled(void);
void mouse_jiggler_enable(void);
void mouse_jiggler_disable(void);

enum key_position {
  POSITION_ANSI = 8,
  POSITION_JIS = 9,
 
  POSITION_Mac_off = 6,
  POSITION_Mac_on = 7,

  POSITION_FB_error = 11,
  
  POSITION_Tran_off = 2,
  POSITION_Tran_on = 3,

  POSITION_ISS_off = 0,
  POSITION_ISS_on = 1,

  POSITION_MJ_off = 48,
  POSITION_MJ_on = 49,

  POSITION_Nav_pad_DEC_CPI = 4,
  POSITION_Nav_pad_INC_CPI = 5,

  POSITION_Nav_ball_DEC_CPI = 26,
  POSITION_Nav_ball_INC_CPI = 27,
  
  POSITION_Nav_ball_Base_Scroll_off = 32,
  POSITION_Nav_ball_Base_Scroll_on = 33,

  POSITION_Nav_ball_Base_Aim = 41,
  POSITION_Nav_ball_Base_Normal = 42,
  POSITION_Nav_ball_Base_Turbo = 43,

  POSITION_RST = 31,
  POSITION_SW_RST = 17,
  POSITION_CLEAR = 16,
  
  POSITION_Caps_Lock = 19,
  POSITION_Num_Lock = 44,
  POSITION_Scroll_Lock = 45,
  POSITION_Compose = 46,
  POSITION_Kana = 20,

  POSITION_OS = 22,
  
  POSITION_Color_Palette = 51
};

bool firmware_map_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  // MT template
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      
    } else {
      return false;
    }
  } else {
    if (record->event.pressed) {
      
    } else {
      return false;
    }  
  }

  uint8_t pos = get_pos_from_keyrecord(record);
  //if (FADE_MATRIX_POSITION_COUNT <= pos) return false;
    
  if (pos == POSITION_ANSI) {
    virt_layer_off(VIRT_LAYER_FB_JIS);
        
    return false;
  }

  if (pos == POSITION_JIS) {
    virt_layer_on(VIRT_LAYER_FB_JIS);
        
    return false;
  }
      
  if (pos == POSITION_Mac_off) {
    virt_layer_off(VIRT_LAYER_FB_Mac);
        
    return false;
  }

  if (pos == POSITION_Mac_on) {
    virt_layer_on(VIRT_LAYER_FB_Mac);
        
    return false;
  }

  if (pos == POSITION_FB_error) {
    virt_layer_off(VIRT_LAYER_FB_error);
        
    return false;
  }
      
  if (pos == POSITION_Tran_off) {
    virt_layer_off(VIRT_LAYER_Transition);
        
    return false;
  }
      
  if (pos == POSITION_Tran_on) {
    virt_layer_on(VIRT_LAYER_Transition);
        
    return false;
  }
      
  if (pos == POSITION_ISS_off) {
    ime_state_sync_disable();
        
    return false;
  }

  if (pos == POSITION_ISS_on) {
    ime_state_sync_enable();
        
    return false;
  }
      
  if (pos == POSITION_MJ_off) {
    mouse_jiggler_disable();
        
    return false;
  }

  if (pos == POSITION_MJ_on) {
    mouse_jiggler_enable();
        
    return false;
  }

  if (pos == POSITION_Nav_pad_DEC_CPI) {
    navigator_trackpad_set_cpi(0);
        
    return false;
  }

  if (pos == POSITION_Nav_pad_INC_CPI) {
    navigator_trackpad_set_cpi(1);
        
    return false;
  }

  if (pos == POSITION_Nav_ball_DEC_CPI) {
    pointing_device_set_cpi(0);
        
    return false;
  }  

  if (pos == POSITION_Nav_ball_INC_CPI) {
    pointing_device_set_cpi(1);
        
    return false;
  }

  if (pos == POSITION_Nav_ball_Base_Scroll_off) {
    virt_layer_off(VIRT_LAYER_navigator_base_scroll);
        
    return false;
  }

  if (pos == POSITION_Nav_ball_Base_Scroll_on) {
    virt_layer_on(VIRT_LAYER_navigator_base_scroll);
        
    return false;
  }

  if (pos == POSITION_Nav_ball_Base_Aim) {
    virt_layer_on(VIRT_LAYER_navigator_base_aim);
    virt_layer_off(VIRT_LAYER_navigator_base_turbo);
            
    return false;
  }

  if (pos == POSITION_Nav_ball_Base_Normal) {
    virt_layer_off(VIRT_LAYER_navigator_base_aim);
    virt_layer_off(VIRT_LAYER_navigator_base_turbo);
        
    return false;
  }

  if (pos == POSITION_Nav_ball_Base_Turbo) {
    virt_layer_off(VIRT_LAYER_navigator_base_aim);
    virt_layer_on(VIRT_LAYER_navigator_base_turbo);
        
    return false;
  }

  if (pos == POSITION_RST) {
    reset_keyboard();
        
    return false;
  }
      
  if (pos == POSITION_SW_RST) {
    soft_reset_keyboard();
        
    return false;
  }
      
  if (pos == POSITION_CLEAR) {
    clear_keyboard();
    
    status_led(0b1111, led_pattern_oneshot);
        
    return false;
  }

  // default false
  return false;
}

bool rgb_matrix_indicators_firmware_map(void) {
  // if no active nothing to do, pass next
  if (virt_layer_state_is(VIRT_LAYER_Firmware) == false) return true;

  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  // exec halt module clear and write halt status, reach here
  
  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  //rgb_matrix_set_color(44, f, f, 0);
  //rgb_matrix_set_color(45, f, f, 0);
  
  rgb_matrix_set_color(POSITION_Color_Palette, 0, q, 0);
  
  //ANSI/JIS
  if (virt_layer_state_is(VIRT_LAYER_FB_JIS)) {
    //JIS
    rgb_matrix_set_color(POSITION_JIS, 0, f, 0);
    rgb_matrix_set_color(POSITION_ANSI, q, q, q);  
  } else {
    //ANSI base enable
    rgb_matrix_set_color(POSITION_JIS, q, q, q);
    rgb_matrix_set_color(POSITION_ANSI, f, 0, 0);
  }
  
  if (virt_layer_state_is(VIRT_LAYER_FB_Mac)) {
    //Mac
    rgb_matrix_set_color(POSITION_Mac_off, q, q, q);
    rgb_matrix_set_color(POSITION_Mac_on, f, 0, 0);  
  } else {
    //Win
    rgb_matrix_set_color(POSITION_Mac_off, 0, 0, f);
    rgb_matrix_set_color(POSITION_Mac_on, q, q, q);
  }

  if (virt_layer_state_is(VIRT_LAYER_FB_error)) {
    rgb_matrix_set_color(POSITION_FB_error, f, 0, 0);
  } else {
    rgb_matrix_set_color(POSITION_FB_error, 0, q, 0);
  }

  // Transition
  if (virt_layer_state_is(VIRT_LAYER_Transition)) {
    // on
    rgb_matrix_set_color(POSITION_Tran_off, q, q, q);
    rgb_matrix_set_color(POSITION_Tran_on, f, f, 0);
  } else {
    // off
    rgb_matrix_set_color(POSITION_Tran_off, 0, 0, f);
    rgb_matrix_set_color(POSITION_Tran_on, q, q, q);
  }

  // ISS system
  if (ime_state_sync_is_enabled()) {
    // on
    rgb_matrix_set_color(POSITION_ISS_on, 0, f, 0);
    rgb_matrix_set_color(POSITION_ISS_off, o, o, o);
  } else {
    // off
    rgb_matrix_set_color(POSITION_ISS_on, o, o, o);
    rgb_matrix_set_color(POSITION_ISS_off, f, f, 0);
  }

  // mouse jiggler
  if (mouse_jiggler_is_enabled()) {
    // on
    rgb_matrix_set_color(POSITION_MJ_on, 0, 0, f);
    rgb_matrix_set_color(POSITION_MJ_off, q, q, q);
  } else {
    // off
    rgb_matrix_set_color(POSITION_MJ_on, q, q, q);
    rgb_matrix_set_color(POSITION_MJ_off, f, 0, 0);
  }

  // navigator controll
  rgb_matrix_set_color(POSITION_Nav_pad_DEC_CPI, 0, o, q);
  rgb_matrix_set_color(POSITION_Nav_pad_INC_CPI, 0, h, f);
  
  rgb_matrix_set_color(POSITION_Nav_ball_DEC_CPI, q, 0, o);
  rgb_matrix_set_color(POSITION_Nav_ball_INC_CPI, f, 0, h);
  
  if (virt_layer_state_is(VIRT_LAYER_navigator_base_scroll)) {
    // on
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Scroll_on, 0, f, 0);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Scroll_off, q, q, q); 
  } else {
    // off
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Scroll_on, q, q, q);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Scroll_off, f, f, 0);
  }

  if ((virt_layer_state_is(VIRT_LAYER_navigator_base_aim) == false) && (virt_layer_state_is(VIRT_LAYER_navigator_base_turbo) == false)) {
    // normal
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Aim, q, q, q);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Normal, 0, f, 0);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Turbo, q, q, q);
  } else if ((virt_layer_state_is(VIRT_LAYER_navigator_base_aim) == true) && (virt_layer_state_is(VIRT_LAYER_navigator_base_turbo) == false)) {
    // aim
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Aim, 0, 0, f);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Normal, q, q, q);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Turbo, q, q, q);
  } else if ((virt_layer_state_is(VIRT_LAYER_navigator_base_aim) == false) && (virt_layer_state_is(VIRT_LAYER_navigator_base_turbo) == true)) {
    // turbo
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Aim, q, q, q);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Normal, q, q, q);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Turbo, f, 0, 0);
  } else {
    // error state
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Aim, f, f, 0);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Normal, f, f, 0);
    rgb_matrix_set_color(POSITION_Nav_ball_Base_Turbo, f, f, 0);
  }

  //OS detect
  RGB rgb_os = {0, 0, 0};
  switch (detected_host_os()) {
    case OS_WINDOWS:
      rgb_os.b = f;
      break;
    case OS_LINUX:
      rgb_os.g = f;
      break;
    case OS_MACOS:
      rgb_os.r = f;
      break;
    case OS_IOS:
      rgb_os.r = f;
      rgb_os.g = h;
      break;    
    case OS_UNSURE:
      rgb_os.r = f;
      rgb_os.g = f;
      break;
    default:
      rgb_os.r = f;
      rgb_os.g = f;
      rgb_os.b = f;
      break;
  }
  rgb_matrix_set_color(POSITION_OS, rgb_os.r, rgb_os.g, rgb_os.b);
  
  //reset clear
  rgb_matrix_set_color(POSITION_RST, f, 0, 0);
  rgb_matrix_set_color(POSITION_SW_RST, f, h, 0);
  rgb_matrix_set_color(POSITION_CLEAR, f, f, 0);

  //color test
  //rgb_matrix_set_color(26, f, 0, 0);
  //rgb_matrix_set_color(32, f, o, 0);
  //rgb_matrix_set_color(38, f, q, 0);
  //rgb_matrix_set_color(44, f, h, 0);

  //rgb_matrix_set_color(27, f, f, 0);
  //rgb_matrix_set_color(33, h, f, 0);
  //rgb_matrix_set_color(39, q, f, 0);
  //rgb_matrix_set_color(45, o, f, 0);
  
  //rgb_matrix_set_color(28, 0, f, 0);
  //rgb_matrix_set_color(34, 0, f, q);
  //rgb_matrix_set_color(40, 0, f, f);
  //rgb_matrix_set_color(46, 0, q, f);
  
  //rgb_matrix_set_color(29, 0, 0, f);
  //rgb_matrix_set_color(35, q, 0, f);
  //rgb_matrix_set_color(41, f, 0, f);
  //rgb_matrix_set_color(47, f, 0, q);

  led_t status = host_keyboard_led_state();

  if (status.caps_lock) {
    rgb_matrix_set_color(POSITION_Caps_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(POSITION_Caps_Lock, q, q, q);
  }

  if (status.num_lock) {
    rgb_matrix_set_color(POSITION_Num_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(POSITION_Num_Lock, q, q, q);
  }

  if (status.scroll_lock) {
    rgb_matrix_set_color(POSITION_Scroll_Lock, 0, h, 0);
  } else {
    rgb_matrix_set_color(POSITION_Scroll_Lock, q, q, q);
  }

  if (status.compose) {
    rgb_matrix_set_color(POSITION_Compose, 0, 0, h);
  } else {
    rgb_matrix_set_color(POSITION_Compose, q, q, q);
  }

  if (status.kana) {
    rgb_matrix_set_color(POSITION_Kana, h, 0, h);
  } else {
    rgb_matrix_set_color(POSITION_Kana, q, q, q);
  }

  // if run display terminate here
  return false;
}
