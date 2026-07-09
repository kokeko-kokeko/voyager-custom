#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

//#include "addons/overlay_layer_mod.h"

#include "addons/ime_state_sync.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

// ime state from LANG1/LANG2 key
extern bool ime_on;
extern bool ime_kk;  //KataKana
extern bool iss_sync;

bool rgb_matrix_indicators_ime_state_sync(void) {
  // if mouse on exit
  if (layer_state_is(LAYER_Mouse_L)) return true;
  if (layer_state_is(LAYER_Mouse_R)) return true;
  
  // IME state sync syntem state
  if (ime_on) {
    rgb_matrix_set_color(38, 0, 0, 0);
    
    if (ime_kk == false) {
      rgb_matrix_set_color(44, 0, 0, 0);
    }

    rgb_matrix_set_color(17, 0, 0, 0);
    
    if (iss_sync == false) {
      rgb_matrix_set_color(23, 0, 0, 0);
    }
  }
  // use golden angle 255 * phi
  //const uint8_t h_diff = 97;
  
  //HSV hsv = rgb_matrix_get_hsv();
  //hsv.h -= g_rgb_timer >> 4;
  //hsv.s = 255;
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  //uint8_t speed = rgb_matrix_get_speed(); 
  //uint16_t time = scale16by8(g_rgb_timer, speed / 3);
  //hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

  // IME state sync syntem state
  //if (ime_on) {
  //  hsv.h -= h_diff;
  //  RGB rgb = hsv_to_rgb(hsv);
  //  rgb_matrix_set_color(44, rgb.r, rgb.g, rgb.b);
    
  //  if (ime_kk) {
  //    rgb_matrix_set_color(38, rgb.r, rgb.g, rgb.b);
  //  } else {
  //    rgb_matrix_set_color(38, 0, 0, 0);
  //  }
    
  //  if (iss_sync) {
  //    rgb_matrix_set_color(23, rgb.r, rgb.g, rgb.b);
  //  } else {
  //    rgb_matrix_set_color(23, 0, 0, 0);
  //  }
  //  rgb_matrix_set_color(5, 0, 0, 0);
  //  rgb_matrix_set_color(11, 0, 0, 0);
  //  rgb_matrix_set_color(17, 0, 0, 0);
  //  rgb_matrix_set_color(26, 0, 0, 0);
  //  rgb_matrix_set_color(32, 0, 0, 0);
  //}

  // overlay pass to next
  return true;
}
