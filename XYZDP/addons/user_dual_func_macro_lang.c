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

static bool process_record_udfn1(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN1) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = KC_NO;
  uint16_t send_hold = KC_NO;

  bool l_shift = get_mods() & MOD_BIT_LSHIFT;
  bool r_shift = get_mods() & MOD_BIT_RSHIFT;
  bool shift_on = get_mods() & MOD_MASK_SHIFT;
  
  if (id_code == KC_A) {
    if (jis_flag) {
      if (shift_on) {
        send_tap = JP_GRV;
        send_hold = JP_GRV;
      } else {
        send_tap = JP_AT;
        send_hold = JP_AT;
      }
    } else {
      if (shift_on) {
        send_tap = KC_GRV;
        send_hold = KC_GRV;
      } else {
        send_tap = KC_AT;
        send_hold = KC_AT;
      }
    }
  }
  
  if (id_code == KC_B) {
    if (shift_on) {
      send_tap = KC_DLR;
      send_hold = KC_DLR;
    } else {
      send_tap = KC_HASH;
      send_hold = KC_HASH;
    }
  }

  if (id_code == KC_C) {
    if (jis_flag) {
      if (shift_on) {
        send_tap = JP_LPRN;
        send_hold = JP_LPRN;
      } else {
        send_tap = JP_QUOT;
        send_hold = JP_QUOT;
      }
    } else {
      if (shift_on) {
        send_tap = KC_LPRN;
        send_hold = KC_LPRN;
      } else {
        send_tap = KC_QUOT;
        send_hold = KC_QUOT;
      }
    }
  }
  
  if (id_code == KC_D) {
    if (shift_on) {
      send_tap = KC_SCLN;
      send_hold = KC_SCLN;
    } else {
      send_tap = KC_COMM;
      send_hold = HYPR(KC_NO);
    }
  }

  if (id_code == KC_E) {
    if (jis_flag) {
      if (shift_on) {
        send_tap = JP_UNDS;
        send_hold = JP_UNDS;
      } else {
        send_tap = JP_MINS;
        send_hold = JP_MINS;
      }
    } else {
      if (shift_on) {
        send_tap = KC_UNDS;
        send_hold = KC_UNDS;
      } else {
        send_tap = KC_MINS;
        send_hold = KC_MINS;
      }
    }
  }
  
  // finalize
  if ((send_tap != 0) && (send_hold != 0)) {
    if (shift_on) del_mods(MOD_MASK_SHIFT);
    
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

  uint16_t tapcode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode); 
      
  // Firmware  
  if (tapcode == KC_A) return firmware_map_main_keyrecord(record);
  if (tapcode == KC_C) return firmware_map_invoke_halt_keyrecord(record);
    
  // Color Palette
  if (tapcode == KC_D) return fade_matrix_color_palette_main_keyrecord(record);
    
  if (tapcode == KC_E) return fade_matrix_color_palette_sel_sat_keyrecord(record);
  if (tapcode == KC_F) return fade_matrix_color_palette_sel_val_keyrecord(record);
    
  if (tapcode == KC_H) return fade_matrix_color_palette_load_preset_keyrecord(record);
    
  // layer move
  if (tapcode == KC_B) return firmware_map_enter_color_palette_keyrecord(record);
  if (tapcode == KC_G) return firmware_map_exit_all_keyrecord(record);
  
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
