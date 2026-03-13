#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/user_lang_dual_func_macro.h"

static bool process_record_udfn1(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn2(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn3(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn4(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn5(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn6(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool process_record_udfn7(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user_lang_dual_func_macro(uint16_t keycode, keyrecord_t *record) {
  if (IS_QK_MOD_TAP(keycode) == false) return true;

  if (process_record_udfn1(keycode, record) == false) return false;
  if (process_record_udfn2(keycode, record) == false) return false;
  if (process_record_udfn3(keycode, record) == false) return false;
  if (process_record_udfn4(keycode, record) == false) return false;
  if (process_record_udfn5(keycode, record) == false) return false;
  if (process_record_udfn6(keycode, record) == false) return false;
  if (process_record_udfn7(keycode, record) == false) return false;
  
  return true;
}
