#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/user_lang_dual_func_macro.h"



bool process_record_user_lang_dual_func_macro(uint16_t keycode, keyrecord_t *record) {
  if(IS_QK_MOD_TAP(keycode) == false) return true;

  return true;
}
