#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "overlay_layer_mod.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#include "layer_num.h"

void set_layer_color_overlay_layer(void) {
  // use golden angle 255 * phi
  const uint8_t h_diff = 97;
  
  HSV hsv = rgb_matrix_get_hsv();
  hsv.h -= g_rgb_timer >> 4;
  hsv.s = 255;
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  uint8_t speed = rgb_matrix_get_speed(); 
  uint16_t time = scale16by8(g_rgb_timer, speed / 3);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
  
  // layer display with priority
  if (layer_state_is(L_BothPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_BothPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_BothThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_RightPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    
    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);

    return;
  }
  if (layer_state_is(L_LeftPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_RightPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_LeftPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_Cursor)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    //rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_Number)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);
    return;
  }
}

void set_layer_color_overlay_mod(void) {
  // use golden angle 255 * phi
  const uint8_t h_diff = 97;
  
  HSV hsv = rgb_matrix_get_hsv();
  hsv.h -= g_rgb_timer >> 5;
  hsv.s = 255;
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  uint8_t speed = rgb_matrix_get_speed(); 
  uint16_t time = scale16by8(g_rgb_timer, speed / 5);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

  // CAPS WORD inidication
  if (is_caps_word_on()) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
  }

  // mods display
  if (get_mods() & MOD_BIT_LCTRL) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LSHIFT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(18, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LALT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LGUI) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(7, rgb.r, rgb.g, rgb.b);
  }
  
  if (get_mods() & MOD_BIT_RCTRL) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(27, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(42, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(43, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RSHIFT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(28, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(41, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(49, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RALT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(35, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RGUI) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(36, rgb.r, rgb.g, rgb.b);
  }
}
