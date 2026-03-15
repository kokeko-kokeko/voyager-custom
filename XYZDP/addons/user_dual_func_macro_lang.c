#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/user_dual_func_macro_lang.h"

#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"

// call JP keycode
#include "keymap_japanese.h"

static bool jis_flag = false;

void jis_enable(void) {
  jis_flag = true;
}

void jis_disable(void) {
  jis_flag = false;
}

bool jis_is_enabled(void) {
  return jis_flag;
}

static uint16_t engram_symbol_shift (uint16_t keycode) {
  switch (keycode) {
    case KC_NO:   return KC_NO;
    
    case KC_AT:   return KC_GRV;
    case KC_HASH: return KC_DLR;
    case KC_SLSH: return KC_BSLS;
    
    case KC_QUOT: return KC_LPRN;
    case KC_DQUO: return KC_RPRN;
    
    case KC_COMM: return KC_SCLN;
    case KC_DOT:  return KC_COLN;
    
    case KC_MINS: return KC_UNDS;
    case KC_QUES: return KC_EXLM;
    
    case KC_LBRC: return KC_LCBR;
    case KC_RBRC: return KC_RCBR;
    
    case KC_1:    return KC_PIPE;
    case KC_2:    return KC_EQL;
    case KC_3:    return KC_TILD;
    case KC_4:    return KC_PLUS;
    case KC_5:    return KC_LABK;
    
    case KC_6:    return KC_RABK;
    case KC_7:    return KC_CIRC;
    case KC_8:    return KC_AMPR;
    case KC_9:    return KC_PERC;
    case KC_0:    return KC_ASTR;
    
    default:      return keycode;
  }        
  return keycode;
}

static uint16_t conv_kc_to_jp (uint16_t keycode) {
  switch (keycode) {
    case KC_NO:   return KC_NO;
    
    case KC_DQUO: return JP_DQUO;
    case KC_AMPR: return JP_AMPR;
    case KC_QUOT: return JP_QUOT;
    case KC_LPRN: return JP_LPRN;
    case KC_RPRN: return JP_RPRN;

    case KC_MINS: return JP_MINS;
    case KC_EQL:  return JP_EQL;

    case KC_CIRC:  return JP_CIRC;
    case KC_TILD:  return JP_TILD;

    case KC_BSLS:  return JP_BSLS;
    case KC_UNDS:  return JP_UNDS;
    
    case KC_PIPE:  return JP_PIPE;

    case KC_AT:   return JP_AT;
    case KC_GRV:  return JP_GRV;
    
    case KC_LBRC:  return JP_LBRC;
    case KC_LCBR:  return JP_LCBR;
    
    case KC_RBRC:  return JP_RBRC;
    case KC_RCBR:  return JP_RCBR;

    case KC_SCLN:  return JP_SCLN;
    case KC_PLUS:  return JP_PLUS;

    case KC_COLN:  return JP_COLN;
    case KC_ASTR:  return JP_ASTR;
    
    default:      return keycode;
  }        
  return keycode;
}

static bool process_record_udfn1(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN1) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = KC_NO;
  uint16_t send_hold = KC_NO;

  bool l_shift = get_mods() & MOD_BIT_LSHIFT;
  bool r_shift = get_mods() & MOD_BIT_RSHIFT;
  bool shift_on = get_mods() & MOD_MASK_SHIFT;
  
  if (id_code == KC_A) send_tap = KC_AT;
  if (id_code == KC_B) send_tap = KC_HASH;
  if (id_code == KC_C) send_tap = KC_QUOT;
  if (id_code == KC_D) {
    send_tap = KC_COMM;
    send_hold = HYPR(KC_NO);
  }
  if (id_code == KC_E) send_tap = KC_MINS;
  if (id_code == KC_F) send_tap = KC_SLSH;
  if (id_code == KC_G) send_tap = KC_DQUO;
  if (id_code == KC_H) {
    send_tap = KC_DOT;
    send_hold = MEH(KC_NO);
  }
  if (id_code == KC_I) send_tap = KC_QUES;

  // finalize
  if (send_tap != KC_NO) {
    if (send_hold == KC_NO) send_hold = send_tap;
    
    if (shift_on) {
      send_tap = engram_symbol_shift(send_tap);
      send_hold = engram_symbol_shift(send_hold);

      del_mods(MOD_MASK_SHIFT);
    }

    if (jis_flag) {
      send_tap = conv_kc_to_jp(send_tap);
      send_hold = conv_kc_to_jp(send_hold);
    }
    
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(send_tap);
      } else {
        unregister_code16(send_tap);
      }
    } else {
      if (record->event.pressed) {
        register_code16(send_hold);
      } else {
        unregister_code16(send_hold);
      }  
    }

    if (l_shift) add_mods(MOD_BIT_LSHIFT);
    if (r_shift) add_mods(MOD_BIT_RSHIFT);
    
    return false;
  }
  
  return true;
}

static bool process_record_udfn2(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN2) return true;

  return true;
}

static bool process_record_udfn3(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN3) return true;

  return true;
}

static bool process_record_udfn4(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN4) return true;

  return true;
}

static bool process_record_udfn5(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN5) return true;

  return true;
}

static bool process_record_udfn6(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN6) return true;

  return true;
}

static bool process_record_udfn7(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN7) return true;

  return true;
}

static bool process_record_udfn8(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN8) return true;

  return true;
}

static bool process_record_udfn9(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN9) return true;

  return true;
}

static bool process_record_udfn10(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN10) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode); 
      
  // Firmware  
  if (id_code == KC_A) return firmware_map_main_keyrecord(record);
  if (id_code == KC_C) return firmware_map_invoke_halt_keyrecord(record);
    
  // Color Palette
  if (id_code == KC_D) return fade_matrix_color_palette_main_keyrecord(record);
    
  if (id_code == KC_E) return fade_matrix_color_palette_sel_sat_keyrecord(record);
  if (id_code == KC_F) return fade_matrix_color_palette_sel_val_keyrecord(record);
    
  if (id_code == KC_H) return fade_matrix_color_palette_load_preset_keyrecord(record);
    
  // layer move
  if (id_code == KC_B) return firmware_map_enter_color_palette_keyrecord(record);
  if (id_code == KC_G) return firmware_map_exit_all_keyrecord(record);
  
  return true;
}

bool process_record_user_dual_func_macro_lang(uint16_t keycode, keyrecord_t *record) {
  // non-MT keycode, skip
  if (IS_QK_MOD_TAP(keycode) == false) return true;

  if (process_record_udfn1(keycode, record) == false) return false;
  if (process_record_udfn2(keycode, record) == false) return false;
  if (process_record_udfn3(keycode, record) == false) return false;
  if (process_record_udfn4(keycode, record) == false) return false;
  if (process_record_udfn5(keycode, record) == false) return false;
  if (process_record_udfn6(keycode, record) == false) return false;
  if (process_record_udfn7(keycode, record) == false) return false;
  if (process_record_udfn8(keycode, record) == false) return false;
  if (process_record_udfn9(keycode, record) == false) return false;
  if (process_record_udfn10(keycode, record) == false) return false;
  
  return true;
}
