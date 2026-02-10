#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/firmware_halt_map.h"

#include "addons/fade_matrix.h"
#include "addons/ime_state_sync.h"
#include "addons/status_led.h"

enum key_pos {
  P_JIS = 0,
  P_ANSI = 6,
  P_Tran_off = 1,
  P_Tran_on = 7,
  P_ISS_on = 3,
  P_ISS_off = 9,
  P_MJ_on = 5,
  P_MJ_off = 11,

  P_RST = 31,
  P_SW_RST = 37,
  P_CLEAR = 49,
  
  P_Caps_Lock = 19,
  P_Num_Lock = 44,
  P_Scroll_Lock = 45,
  P_Compose = 46,
  P_Kana = 20,

  P_OS1 = 22,
  P_OS2 = 23,
  
  P_Halt = 31
};

// call mouse jiggler
void mouse_jiggler_enable(void);
void mouse_jiggler_disable(void);
bool mouse_jiggler_is_enabled(void);

bool firmware_map_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == false) return false;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return false;

  if (pos == P_JIS) {
    layer_on(L_Base);
    layer_off(L_Base_ANSI);
        
    return false;
  }
      
  if (pos == P_ANSI) {
    layer_on(L_Base);
    layer_on(L_Base_ANSI);
        
    return false;
  }
      
  if (pos == P_Tran_off) {
    layer_on(L_Base);
    layer_off(L_Transition);
        
    return false;
  }
      
  if (pos == P_Tran_on) {
    layer_on(L_Base);
    layer_on(L_Transition);
        
    return false;
  }
      
  if (pos == P_ISS_on) {
    ime_state_sync_enable();
        
    return false;
  }
      
  if (pos == P_ISS_off) {
    ime_state_sync_disable();
        
    return false;
  }

  if (pos == P_MJ_on) {
    mouse_jiggler_enable();
        
    return false;
  }
      
  if (pos == P_MJ_off) {
    mouse_jiggler_disable();
        
    return false;
  }
      
  if (pos == P_RST) {
    reset_keyboard();
        
    return false;
  }
      
  if (pos == P_SW_RST) {
    soft_reset_keyboard();
        
    return false;
  }
      
  if (pos == P_CLEAR) {
    clear_keyboard();
        
    return false;
  }

  // default false
  return false;
}

void set_layer_color_firmware_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  rgb_matrix_set_color_all(0, 0, 0);

  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  //rgb_matrix_set_color(44, f, f, 0);
  //rgb_matrix_set_color(45, f, f, 0);
  rgb_matrix_set_color(50, q, q, 0);
  rgb_matrix_set_color(51, q, 0, 0);
  
  //ANSI/JIS
  if (layer_state_is(L_Base_ANSI)) {
    //ANSI base enable
    rgb_matrix_set_color(P_JIS, q, q, q);
    rgb_matrix_set_color(P_ANSI, f, 0, 0);
  } else {
    //JIS base
    rgb_matrix_set_color(P_JIS, 0, f, 0);
    rgb_matrix_set_color(P_ANSI, q, q, q);
  }

  // Transition
  if (layer_state_is(L_Transition)) {
    // on
    rgb_matrix_set_color(P_Tran_off, q, q, q);
    rgb_matrix_set_color(P_Tran_on, f, f, 0);
  } else {
    // off
    rgb_matrix_set_color(P_Tran_off, 0, 0, f);
    rgb_matrix_set_color(P_Tran_on, q, q, q);
  }

  // ISS system
  if (ime_state_sync_is_enabled()) {
    rgb_matrix_set_color(P_ISS_on, 0, f, 0);
    rgb_matrix_set_color(P_ISS_off, o, o, o);
  } else {
    //ANSI base
    rgb_matrix_set_color(P_ISS_on, o, o, o);
    rgb_matrix_set_color(P_ISS_off, f, f, 0);
  }

  // mouse jiggler
  if (mouse_jiggler_is_enabled()) {
    // on
    rgb_matrix_set_color(P_MJ_on, 0, 0, f);
    rgb_matrix_set_color(P_MJ_off, q, q, q);
  } else {
    // off
    rgb_matrix_set_color(P_MJ_on, q, q, q);
    rgb_matrix_set_color(P_MJ_off, f, 0, 0);
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
  rgb_matrix_set_color(P_OS1, rgb_os.r, rgb_os.g, rgb_os.b);
  rgb_matrix_set_color(P_OS2, rgb_os.r, rgb_os.g, rgb_os.b);
  
  //reset clear
  rgb_matrix_set_color(P_RST, f, 0, 0);
  rgb_matrix_set_color(P_SW_RST, f, h, 0);
  rgb_matrix_set_color(P_CLEAR, f, f, 0);

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
    rgb_matrix_set_color(P_Caps_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(P_Caps_Lock, q, q, q);
  }

  if (status.num_lock) {
    rgb_matrix_set_color(P_Num_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(P_Num_Lock, q, q, q);
  }

  if (status.scroll_lock) {
    rgb_matrix_set_color(P_Scroll_Lock, 0, h, 0);
  } else {
    rgb_matrix_set_color(P_Scroll_Lock, q, q, q);
  }

  if (status.compose) {
    rgb_matrix_set_color(P_Compose, 0, 0, h);
  } else {
    rgb_matrix_set_color(P_Compose, q, q, q);
  }

  if (status.kana) {
    rgb_matrix_set_color(P_Kana, h, 0, h);
  } else {
    rgb_matrix_set_color(P_Kana, q, q, q);
  }
}

bool firmware_map_enter_hue_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  static uint16_t press_time = 0;
    
  if (record->event.pressed) {
    // press
    press_time = record->event.time;
      
    return false;
  }

  if (TIMER_DIFF_16(record->event.time, press_time) < TAPPING_TERM) {
    // tap release
      
    return false;
  }
  
  // hold release
  layer_on(L_Set_Hue);

  // default false
  return false;
}

bool firmware_map_enter_halt_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  if (record->event.pressed) {
    // press
      
    return false;
  }
    
  const fast_timer_t now = timer_read_fast();

  // release
  static fast_timer_t release_time = 0;
  static uint8_t release_count = 0;
    
  if (TIMER_DIFF_FAST(now, release_time) >= 1000) {
    // single release (far from previous release)
    release_time = now;
    release_count = 1;
      
    return false;
  }

  // multi release
  release_time = now;
  if (release_count != 0) release_count++;

  if (release_count == 5) {
    // both on Hue for exit key
    layer_state_t layer_mask = 
      ((layer_state_t)1 << L_Set_Hue)   |
      ((layer_state_t)1 << L_Halt_Mask);
    layer_or(layer_mask);
      
    return false;
  }

  // default false
  return false;
}

bool firmware_map_exit_all_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  static uint16_t press_time = 0;
    
  if (record->event.pressed) {
    // press
    press_time = record->event.time;
      
    return false;
  }

  if (TIMER_DIFF_16(record->event.time, press_time) < TAPPING_TERM) {
    // tap release
      
    return false;
  }
    
  // hold release
  // off all setting layers
  layer_state_t layer_mask = 
    ((layer_state_t)1 << L_Firmware)  |
    ((layer_state_t)1 << L_Set_Hue)   |
    ((layer_state_t)1 << L_Set_Sat)   |
    ((layer_state_t)1 << L_Set_Val)   |
    ((layer_state_t)1 << L_Set_Speed) |
    ((layer_state_t)1 << L_Halt_Mask);
  layer_mask = ~layer_mask;
  layer_and(layer_mask);

  status_led(0b1111, led_pattern_oneshot);

  // default false
  return false;
}

bool halt_map_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == false) return false;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return false;
      
  if (pos == P_Halt) {
    // hang-up
    while (1);
        
    return false;
  }

  // default false
  return false;
}

void set_layer_color_halt_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  //RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color_all(0, 0, 0);

  rgb_matrix_set_color(P_Halt, hsv.v, 0, 0);
  //rgb_matrix_set_color(49, hsv.v, hsv.v, 0);
  //rgb_matrix_set_color(24, 0, hsv.v, 0);
  //rgb_matrix_set_color(25, 0, hsv.v, 0);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  //rgb_matrix_set_color(51, 0, hsv.v, 0);
}
