#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/layer_mod_overlay.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

static void rgb_matrix_indicators_layer_overlay(void) {
  bool or_flag = false;

  // if mouse on exit
  //if (layer_state_is(LAYER_Mouse_L)) return;
  //if (layer_state_is(LAYER_Mouse_R)) return;
  
  // layer display with priority
  if (layer_state_is(LAYER_L_thumb_0)) {
    rgb_matrix_set_color(11, 0, 0, 0);

    or_flag = true;
  }

  if (layer_state_is(LAYER_R_thumb_0)) {
    rgb_matrix_set_color(32, 0, 0, 0);

    or_flag = true;
  }

  if (layer_state_is(LAYER_L_pinky_0)) {
    rgb_matrix_set_color(5, 0, 0, 0);

    or_flag = true;
  }

  if (layer_state_is(LAYER_L_pinky_1)) {
    or_flag = true;
  }  
  
  if (layer_state_is(LAYER_R_pinky_0)) {
    rgb_matrix_set_color(26, 0, 0, 0);

    or_flag = true;
  }

  if (layer_state_is(LAYER_R_pinky_1)) {
    or_flag = true;
  }

  if (or_flag) {
    rgb_matrix_set_color(19, 0, 0, 0);
    rgb_matrix_set_color(20, 0, 0, 0);
    rgb_matrix_set_color(47, 0, 0, 0);
    rgb_matrix_set_color(48, 0, 0, 0);
  }
}

static void rgb_matrix_indicators_mod_overlay(void) {
  // CAPS WORD inidication
  if (is_caps_word_on()) {
    rgb_matrix_set_color(0, 0, 0, 0);
    rgb_matrix_set_color(31, 0, 0, 0);
  }

  // swap hands
  //if (is_swap_hands_on()) {
  //  rgb_matrix_set_color(23, 0, 0, 0);
  //  rgb_matrix_set_color(46, 0, 0, 0);
  //}

  // mods display
  if (get_mods() & MOD_MASK_CTRL) {
    rgb_matrix_set_color(4, 0, 0, 0);
    rgb_matrix_set_color(27, 0, 0, 0);
  }

  if (get_mods() & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(3, 0, 0, 0);
    rgb_matrix_set_color(28, 0, 0, 0);
  }

  if (get_mods() & MOD_MASK_ALT) {
    rgb_matrix_set_color(2, 0, 0, 0);
    rgb_matrix_set_color(29, 0, 0, 0);
  }

  if (get_mods() & MOD_MASK_GUI) {
    rgb_matrix_set_color(1, 0, 0, 0);
    rgb_matrix_set_color(30, 0, 0, 0);
  }  
  
  if (get_mods() & MOD_BIT_LCTRL) {
    rgb_matrix_set_color(12, 0, 0, 0);
  }

  if (get_mods() & MOD_BIT_LSHIFT) {
    rgb_matrix_set_color(18, 0, 0, 0);
  }

  if (get_mods() & MOD_BIT_RCTRL) {
    rgb_matrix_set_color(43, 0, 0, 0);
  }

  if (get_mods() & MOD_BIT_RSHIFT) {
    rgb_matrix_set_color(49, 0, 0, 0);
  }
}

bool rgb_matrix_indicators_layer_mod_overlay(void) {
  rgb_matrix_indicators_mod_overlay();
  rgb_matrix_indicators_layer_overlay();

  // overlay pass to next
  return true;
}