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

static fast_timer_t auto_mouse_early_off_trigger = 0;





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
  rgb_matrix_set_color(47, q, o, 0);
  rgb_matrix_set_color(48, f, h, 0);
  
  // scroll
  if (set_scrolling) {
    if (navigator_turbo && navigator_aim) {
      rgb_matrix_set_color(0, f, f, 0);
    } else if (navigator_turbo) {
      rgb_matrix_set_color(0, f, h, 0);
    } else if (navigator_aim) {
      rgb_matrix_set_color(0, 0, f, h);
    } else {
      rgb_matrix_set_color(0, 0, h, f);
    }
    
    rgb_matrix_set_color(22, h, 0, 0);
    rgb_matrix_set_color(45, h, 0, 0);
  } else {
    if (navigator_turbo && navigator_aim) {
      rgb_matrix_set_color(0, f, f, f);
    } else if (navigator_turbo) {
      rgb_matrix_set_color(0, f, 0, 0);
    } else if (navigator_aim) {
      rgb_matrix_set_color(0, 0, f, 0);
    } else {
      rgb_matrix_set_color(0, 0, 0, f);
    }
    
    rgb_matrix_set_color(22, h, h, h);
    rgb_matrix_set_color(45, h, h, h);
  }
}
