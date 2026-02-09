#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/firmware_map.h"

#include "addons/fade_matrix.h"
#include "addons/ime_state_sync.h"

// call mouse jiggler
void mouse_jiggler_enable(void);
void mouse_jiggler_disable(void);
bool mouse_jiggler_is_enabled(void);

void firmware_map_set_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  if (record->event.pressed == false) return;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;

  if (pos == 0) {
    layer_on(L_Base);
    layer_off(L_Base_ANSI);
        
    return;
  }
      
  if (pos == 6) {
    layer_on(L_Base);
    layer_on(L_Base_ANSI);
        
    return;
  }
      
  if (pos == 1) {
    layer_on(L_Base);
    layer_off(L_Transition);
        
    return;
  }
      
  if (pos == 7) {
    layer_on(L_Base);
    layer_on(L_Transition);
        
    return;
  }
      
  if (pos == 3) {
    ime_state_sync_enable();
        
    return;
  }
      
  if (pos == 9) {
    ime_state_sync_disable();
        
    return;
  }

  if (pos == 5) {
    mouse_jiggler_enable();
        
    return;
  }
      
  if (pos == 11) {
    mouse_jiggler_disable();
        
    return;
  }
      
  if (pos == 31) {
    reset_keyboard();
        
    return;
  }
      
  if (pos == 37) {
    soft_reset_keyboard();
        
    return;
  }
      
  if (pos == 49) {
    clear_keyboard();
        
    return;
  }
}

void set_layer_color_firmware_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  //const uint8_t o = q >> 1;

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
    rgb_matrix_set_color(0, q, q, q);
    rgb_matrix_set_color(6, f, 0, 0);
  } else {
    //JIS base
    rgb_matrix_set_color(0, 0, f, 0);
    rgb_matrix_set_color(6, q, q, q);
  }

  // Transition
  if (layer_state_is(L_Transition)) {
    // on
    rgb_matrix_set_color(1, q, q, q);
    rgb_matrix_set_color(7, f, f, 0);
  } else {
    // off
    rgb_matrix_set_color(1, 0, 0, f);
    rgb_matrix_set_color(7, q, q, q);
  }

  // ISS system
  if (ime_state_sync_is_enabled()) {
    rgb_matrix_set_color(3, 0, f, 0);
    rgb_matrix_set_color(9, o, o, o);
  } else {
    //ANSI base
    rgb_matrix_set_color(3, o, o, o);
    rgb_matrix_set_color(9, f, f, 0);
  }

  // mouse jiggler
  if (mouse_jiggler_is_enabled()) {
    // on
    rgb_matrix_set_color(5, 0, 0, f);
    rgb_matrix_set_color(11, q, q, q);
  } else {
    // off
    rgb_matrix_set_color(5, q, q, q);
    rgb_matrix_set_color(11, f, 0, 0);
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
  rgb_matrix_set_color(22, rgb_os.r, rgb_os.g, rgb_os.b);
  rgb_matrix_set_color(23, rgb_os.r, rgb_os.g, rgb_os.b);

  //tapping
  //rgb_matrix_set_color(18, 0, 0, f);
  //rgb_matrix_set_color(19, q, 0, q);
  //rgb_matrix_set_color(20, f, 0, f);

  //reset clear
  rgb_matrix_set_color(31, f, 0, 0);
  rgb_matrix_set_color(37, f, h, 0);
  rgb_matrix_set_color(49, f, f, 0);

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
    rgb_matrix_set_color(19, h, 0, 0);
  } else {
    rgb_matrix_set_color(19, q, q, q);
  }

  if (status.num_lock) {
    rgb_matrix_set_color(45, h, 0, 0);
  } else {
    rgb_matrix_set_color(45, q, q, q);
  }

  if (status.scroll_lock) {
    rgb_matrix_set_color(46, 0, h, 0);
  } else {
    rgb_matrix_set_color(46, q, q, q);
  }

  if (status.compose) {
    rgb_matrix_set_color(47, 0, 0, h);
  } else {
    rgb_matrix_set_color(47, q, q, q);
  }

  if (status.kana) {
    rgb_matrix_set_color(17, h, 0, h);
  } else {
    rgb_matrix_set_color(17, q, q, q);
  }
}

void halt_map_set_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  if (record->event.pressed == false) return;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;
      
  if (pos == 31) {
    // hang-up
    while (1);
        
    return;
  }  
}

void set_layer_color_halt_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  //RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color_all(0, 0, 0);

  rgb_matrix_set_color(31, hsv.v, 0, 0);
  //rgb_matrix_set_color(49, hsv.v, hsv.v, 0);
  //rgb_matrix_set_color(24, 0, hsv.v, 0);
  //rgb_matrix_set_color(25, 0, hsv.v, 0);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  //rgb_matrix_set_color(51, 0, hsv.v, 0);
}
