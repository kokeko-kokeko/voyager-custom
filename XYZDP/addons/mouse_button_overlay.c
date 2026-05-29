#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/mouse_button_overlay.h"

void set_layer_color_overlay_mouse_button(void) {
  if ((layer_state_is(LAYER_Mouse_L) || layer_state_is(LAYER_Mouse_R)) == false) return;
  
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  if (is_transport_connected() == false) {
    rgb_matrix_set_color_all(o, o, 0);
  } else {
    rgb_matrix_set_color_all(o, o, o);
  }

  if (layer_state_is(LAYER_Mouse_L)) {
    // task veiw
    rgb_matrix_set_color(0, 0, 0, f);
    
    rgb_matrix_set_color(5, 0, f, h);   //4
    rgb_matrix_set_color(11, 0, 0, f);  //3
    rgb_matrix_set_color(17, 0, f, 0);  //2
    rgb_matrix_set_color(25, f, 0, 0);  //1

    rgb_matrix_set_color(26, 0, f, h);  //4
    rgb_matrix_set_color(27, 0, f, 0);  //2
    rgb_matrix_set_color(32, 0, 0, f);  //3
    rgb_matrix_set_color(38, f, 0, 0);  //1

    if (layer_state_is(LAYER_Number)) {
      rgb_matrix_set_color(22, f, h, 0);
    } else {
      //rgb_matrix_set_color(22, q, o, 0);
    }
  
    if (layer_state_is(LAYER_Cursor)) {
      rgb_matrix_set_color(45, f, h, 0);
    } else {
      rgb_matrix_set_color(45, q, o, 0);
    }

    if (layer_state_is(LAYER_Function)) {
      rgb_matrix_set_color(24, f, h, 0);
    } else {
      rgb_matrix_set_color(24 , q, o, 0);
    }
  }

  if (layer_state_is(LAYER_Mouse_R)) {
    // task veiw
    rgb_matrix_set_color(0, 0, 0, f); 
    
    rgb_matrix_set_color(26, 0, f, h);   //4
    rgb_matrix_set_color(32, 0, 0, f);  //3
    rgb_matrix_set_color(38, 0, f, 0);  //2
    rgb_matrix_set_color(50, f, 0, 0);  //1

    rgb_matrix_set_color(5, 0, f, h);  //4
    rgb_matrix_set_color(4, 0, f, 0);  //2
    rgb_matrix_set_color(11, 0, 0, f);  //3
    rgb_matrix_set_color(17, f, 0, 0);  //1
  }
  
  if (layer_state_is(LAYER_Mouse_Upper_L)) {  
    // left side
    rgb_matrix_set_color(5, h, 0, f);  //8
    rgb_matrix_set_color(11, 0, h, f);  //7
    rgb_matrix_set_color(17, f, f, 0);  //6
    rgb_matrix_set_color(23, f, 0, h);  //5
  }

  if (layer_state_is(LAYER_Mouse_Upper_R)) {
    // right side 
    rgb_matrix_set_color(26, h, 0, f);  //8
    rgb_matrix_set_color(32, 0, h, f);  //7
    rgb_matrix_set_color(38, f, f, 0);  //6
    rgb_matrix_set_color(44, f, 0, h);  //5
  }
}

