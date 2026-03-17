#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/user_dual_func_macro_lang.h"

#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"

#include "layer_num.h"

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

static void reg16_wo_shift (uint16_t code16) {
  bool l_shift = get_mods() & MOD_BIT_LSHIFT;
  bool r_shift = get_mods() & MOD_BIT_RSHIFT;

  del_mods(MOD_MASK_SHIFT);
  register_code16(code16);
  if (l_shift) add_mods(MOD_BIT_LSHIFT);
  if (r_shift) add_mods(MOD_BIT_RSHIFT);      
}

static void unreg16_wo_shift (uint16_t code16) {
  bool l_shift = get_mods() & MOD_BIT_LSHIFT;
  bool r_shift = get_mods() & MOD_BIT_RSHIFT;

  del_mods(MOD_MASK_SHIFT);
  unregister_code16(code16);
  if (l_shift) add_mods(MOD_BIT_LSHIFT);
  if (r_shift) add_mods(MOD_BIT_RSHIFT);    
}

static uint16_t conv_kc_to_jp(uint16_t keycode) {
  switch (keycode) {
    case KC_NO:   return KC_NO;
    
    case KC_DQUO: return JP_DQUO;
    case KC_AMPR: return JP_AMPR;
    case KC_QUOT: return JP_QUOT;
    case KC_LPRN: return JP_LPRN;
    case KC_RPRN: return JP_RPRN;

    case KC_MINS: return JP_MINS;
    case KC_EQL:  return JP_EQL;

    case KC_CIRC: return JP_CIRC;
    case KC_TILD: return JP_TILD;

    case KC_PIPE: return JP_PIPE;

    case KC_AT:   return JP_AT;
    case KC_GRV:  return JP_GRV;
    
    case KC_LBRC: return JP_LBRC;
    case KC_LCBR: return JP_LCBR;
    
    case KC_RBRC: return JP_RBRC;
    case KC_RCBR: return JP_RCBR;

    case KC_SCLN: return JP_SCLN;
    case KC_PLUS: return JP_PLUS;

    case KC_COLN: return JP_COLN;
    case KC_ASTR: return JP_ASTR;

    case KC_BSLS: return JP_BSLS;
    case KC_UNDS: return JP_UNDS;
    
    default:      return keycode;
  }        
  return keycode;
}

static uint16_t search_tap_base_number(uint16_t keycode) {
  switch (keycode) {
    case KC_A: return KC_AT;
    case KC_B: return KC_HASH;
    case KC_C: return KC_QUOT;
    case KC_D: return KC_COMM;
    case KC_E: return KC_MINS;
    case KC_F: return KC_SLSH;
    case KC_G: return KC_DQUO;
    case KC_H: return KC_DOT;
    case KC_I: return KC_QUES;

    case KC_L: return KC_LBRC;
    case KC_R: return KC_RBRC;

    case KC_1: return KC_1;
    case KC_2: return KC_2;
    case KC_3: return KC_3;
    case KC_4: return KC_4;
    case KC_5: return KC_5;
    
    case KC_6: return KC_6;
    case KC_7: return KC_7;
    case KC_8: return KC_8;
    case KC_9: return KC_9;
    case KC_0: return KC_0;

    case KC_KP_1: return KC_1;
    case KC_KP_2: return KC_2;
    case KC_KP_3: return KC_3;
    case KC_KP_4: return KC_4;
    case KC_KP_5: return KC_5;
    
    case KC_KP_6: return KC_6;
    case KC_KP_7: return KC_7;
    case KC_KP_8: return KC_8;
    case KC_KP_9: return KC_9;
    case KC_KP_0: return KC_0;

    case KC_COMM: return KC_COMM;
    case KC_DOT:  return KC_DOT;

    case KC_PCMM: return KC_COMM;
    case KC_PDOT: return KC_DOT;

    default:   return KC_NO;
  }        
  return KC_NO;
}

static uint16_t engram_symbol_shift(uint16_t keycode) {
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

// key with shift overwrite (same as ko)
static bool process_record_udfn1(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN1) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = search_tap_base_number(id_code);
  uint8_t mods_hold = 0;
  uint8_t layer_hold = 0;

  if (id_code == KC_D) mods_hold = MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;
  if (id_code == KC_H) mods_hold = MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL; 
  
  if (id_code == KC_L) layer_hold = LAYER_L_pinky;
  if (id_code == KC_R) layer_hold = LAYER_R_pinky;

  if (id_code == KC_1) mods_hold = MOD_BIT_LSHIFT | MOD_BIT_LCTRL;
  if (id_code == KC_2) mods_hold = MOD_BIT_LGUI | MOD_BIT_LALT;
  if (id_code == KC_3) mods_hold = MOD_BIT_LSHIFT;
  if (id_code == KC_4) mods_hold = MOD_BIT_LCTRL;
  if (id_code == KC_5) mods_hold = MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;

  if (id_code == KC_KP_6) mods_hold = MOD_BIT_LALT | MOD_BIT_LCTRL; 
  if (id_code == KC_KP_5) mods_hold = MOD_BIT_RALT | MOD_BIT_RCTRL; 
  
  if (id_code == KC_6) mods_hold = MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL; 
  if (id_code == KC_7) mods_hold = MOD_BIT_RCTRL;
  if (id_code == KC_8) mods_hold = MOD_BIT_RSHIFT;
  if (id_code == KC_9) mods_hold = MOD_BIT_RGUI | MOD_BIT_RALT;
  if (id_code == KC_0) mods_hold = MOD_BIT_RSHIFT | MOD_BIT_RCTRL;

  if (id_code == KC_DOT) mods_hold = MOD_BIT_LALT | MOD_BIT_LSHIFT; 
  if (id_code == KC_PDOT) mods_hold = MOD_BIT_RALT | MOD_BIT_RSHIFT; 
  
  // finalize
  if (send_tap != KC_NO) {
    if (get_mods() & MOD_MASK_SHIFT) send_tap = engram_symbol_shift(send_tap);
    if (jis_flag) send_tap = conv_kc_to_jp(send_tap);
    
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        reg16_wo_shift(send_tap);
      } else {
        unreg16_wo_shift(send_tap);
      }
    } else {
      if (record->event.pressed) {
        if (layer_hold != 0) layer_on(layer_hold);
        else if (mods_hold != 0) register_mods(mods_hold);
        else reg16_wo_shift(send_tap);
      } else {
        if (layer_hold != 0) layer_off(layer_hold);
        else if (mods_hold != 0) unregister_mods(mods_hold);
        else unreg16_wo_shift(send_tap);
      }  
    }
    
    return false;
  }
  
  return true;
}

// key with always shift on (same as ko)
static bool process_record_udfn2(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN2) return true;
  
  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = search_tap_base_number(id_code);
  uint8_t mods_hold = 0;
  uint8_t layer_hold = 0;

  if (id_code == KC_D) mods_hold = MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;
  if (id_code == KC_H) mods_hold = MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;

  if (id_code == KC_L) mods_hold = MOD_BIT_LCTRL;
  if (id_code == KC_R) mods_hold = MOD_BIT_RCTRL;

  if (id_code == KC_1) mods_hold = MOD_BIT_LGUI;
  if (id_code == KC_2) mods_hold = MOD_BIT_LALT;
  if (id_code == KC_3) mods_hold = MOD_BIT_LGUI | MOD_BIT_LSHIFT;
  if (id_code == KC_4) mods_hold = MOD_BIT_LGUI | MOD_BIT_LCTRL;
  
  if (id_code == KC_7) mods_hold = MOD_BIT_RGUI | MOD_BIT_RCTRL;
  if (id_code == KC_8) mods_hold = MOD_BIT_RGUI | MOD_BIT_RSHIFT;
  if (id_code == KC_9) mods_hold = MOD_BIT_RALT;
  if (id_code == KC_0) mods_hold = MOD_BIT_RGUI;

  // finalize
  if (send_tap != KC_NO) {
    //always shift
    if (true) send_tap = engram_symbol_shift(send_tap);
    if (jis_flag) send_tap = conv_kc_to_jp(send_tap);
    
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        reg16_wo_shift(send_tap);
      } else {
        unreg16_wo_shift(send_tap);
      }
    } else {
      if (record->event.pressed) {
        if (layer_hold != 0) layer_on(layer_hold);
        else if (mods_hold != 0) register_mods(mods_hold);
        else reg16_wo_shift(send_tap);
      } else {
        if (layer_hold != 0) layer_off(layer_hold);
        else if (mods_hold != 0) unregister_mods(mods_hold);
        else unreg16_wo_shift(send_tap);      
      }  
    }

    return false;
  }
  
  return true;
}

static uint16_t search_tap_cursor(uint16_t keycode) {
  switch (keycode) {
    case KC_A: return LCTL(KC_A);
    case KC_B: return LCTL(KC_S);
    case KC_C: return LCTL(KC_C);
    case KC_D: return LCTL(KC_V);

    case KC_E: return KC_HOME;
    case KC_F: return KC_END;
    case KC_G: return KC_PGUP;
    case KC_H: return KC_PGDN;

    case KC_I: return KC_LBRC;
    case KC_J: return KC_LCBR;
    case KC_K: return KC_LABK;
    case KC_L: return KC_LPRN;

    case KC_M: return KC_EXLM;
    case KC_N: return KC_QUES;
    
    default:   return KC_NO;
  }        
  return KC_NO;
}

static uint16_t bracket_counter_shift(uint16_t keycode) {
  switch (keycode) {
    case KC_NO:   return KC_NO;
    
    case KC_LBRC: return KC_RBRC;
    case KC_LCBR: return KC_RCBR;
    case KC_LABK: return KC_RABK;
    case KC_LPRN: return KC_RPRN;

    case KC_RBRC: return KC_LBRC;
    case KC_RCBR: return KC_LCBR;
    case KC_RABK: return KC_LABK;
    case KC_RPRN: return KC_LPRN;
    
    default:      return keycode;
  }        
  return keycode;
}

static bool process_record_udfn3(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN3) return true;
  
  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = search_tap_cursor(id_code);
  uint8_t mods_hold = 0;
  uint8_t layer_hold = 0;

  if (id_code == KC_A) mods_hold = MOD_BIT_LSHIFT | MOD_BIT_LCTRL;
  if (id_code == KC_B) mods_hold = MOD_BIT_LGUI | MOD_BIT_LALT;
  if (id_code == KC_C) mods_hold = MOD_BIT_LSHIFT;
  if (id_code == KC_D) mods_hold = MOD_BIT_LCTRL;

  if (id_code == KC_E) mods_hold = MOD_BIT_LGUI;
  if (id_code == KC_F) mods_hold = MOD_BIT_LALT;
  if (id_code == KC_G) mods_hold = MOD_BIT_LGUI | MOD_BIT_LSHIFT;
  if (id_code == KC_H) mods_hold = MOD_BIT_LGUI | MOD_BIT_LCTRL;

  if (id_code == KC_I) mods_hold = MOD_BIT_RGUI | MOD_BIT_RCTRL;
  if (id_code == KC_J) mods_hold = MOD_BIT_RGUI | MOD_BIT_RSHIFT;
  if (id_code == KC_K) mods_hold = MOD_BIT_RALT;
  if (id_code == KC_L) mods_hold = MOD_BIT_RGUI;

  if (id_code == KC_M) mods_hold = MOD_BIT_LGUI;
  if (id_code == KC_N) mods_hold = MOD_BIT_LALT;
  
  // finalize
  if (send_tap != KC_NO) {
    if (get_mods() & MOD_MASK_SHIFT) send_tap = bracket_counter_shift(send_tap);
    if (jis_flag) send_tap = conv_kc_to_jp(send_tap);
    
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        reg16_wo_shift(send_tap);
      } else {
        unreg16_wo_shift(send_tap);
      }
    } else {
      if (record->event.pressed) {
        if (layer_hold != 0) layer_on(layer_hold);
        else if (mods_hold != 0) register_mods(mods_hold);
        else reg16_wo_shift(send_tap);
      } else {
        if (layer_hold != 0) layer_off(layer_hold);
        else if (mods_hold != 0) unregister_mods(mods_hold);
        else unreg16_wo_shift(send_tap);
      }  
    }
    
    return false;
  }
  
  return true;
}

static bool process_record_udfn4(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN4) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = search_tap_cursor(id_code);
  uint8_t mods_hold = 0;
  uint8_t layer_hold = 0;

  if (id_code == KC_I) mods_hold = MOD_BIT_RGUI | MOD_BIT_RCTRL;
  if (id_code == KC_J) mods_hold = MOD_BIT_RGUI | MOD_BIT_RSHIFT;
  if (id_code == KC_K) mods_hold = MOD_BIT_RALT;
  if (id_code == KC_L) mods_hold = MOD_BIT_RGUI;
  
  // finalize
  if (send_tap != KC_NO) {
    if (true) send_tap = bracket_counter_shift(send_tap);
    if (jis_flag) send_tap = conv_kc_to_jp(send_tap);
    
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        reg16_wo_shift(send_tap);
      } else {
        unreg16_wo_shift(send_tap);
      }
    } else {
      if (record->event.pressed) {
        if (layer_hold != 0) layer_on(layer_hold);
        else if (mods_hold != 0) register_mods(mods_hold);
        else reg16_wo_shift(send_tap);
      } else {
        if (layer_hold != 0) layer_off(layer_hold);
        else if (mods_hold != 0) unregister_mods(mods_hold);
        else unreg16_wo_shift(send_tap);
      }  
    }
    
    return false;
  }

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

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

  if (id_code == KC_A) {
    if (record->event.pressed) {
      uint8_t pos = get_pos_from_keyrecord(record);

      //` `
      if (pos == 2) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }

      if (pos == 3) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }

      if (pos == 4) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }

      if (pos == 7) {
        SEND_STRING(SS_LSFT(SS_TAP(X_1))SS_DELAY(100)  SS_LSFT(SS_TAP(X_SLASH)));
      }

      if (pos == 8) {
        SEND_STRING(SS_LSFT(SS_TAP(X_SLASH))SS_DELAY(100)  SS_LSFT(SS_TAP(X_1)));
      }

      if (pos == 9) {
        if (jis_flag) {
          SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
        } else {
          SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_8)));
        }
      }

      if (pos == 10) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_SLASH));
        } else {
          SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_TAP(X_SLASH));
        }
      }

      if (pos == 15) {
        SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
      }

      if (pos == 16) {
        if (jis_flag) {
          SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(100)  SS_TAP(X_INTERNATIONAL_1));
        } else {
          SEND_STRING(SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_BSLS));
        }
      }

      //[]
      if (pos == 33) {
        if (jis_flag) {
          SEND_STRING(SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }

      //{}
      if (pos == 34) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }

      //<>
      if (pos == 35) {
        SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
      }
     
      //()
      if (pos == 36) {
        if (jis_flag) {
          SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
        } else {
          SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_LSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
        }
      }
            
      // ...(jp)
      if (pos == 37) {
        SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
      }
    }

    return false;
  }

  return true;
}

static bool process_record_udfn8(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_UDFN8) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode); 
      
  // Firmware  
  if (id_code == KC_F1) return firmware_map_main_keyrecord(record);
  if (id_code == KC_F3) return firmware_map_invoke_halt_keyrecord(record);
    
  // Color Palette
  if (id_code == KC_F4) return fade_matrix_color_palette_main_keyrecord(record);
    
  if (id_code == KC_F5) return fade_matrix_color_palette_sel_sat_keyrecord(record);
  if (id_code == KC_F6) return fade_matrix_color_palette_sel_val_keyrecord(record);
    
  if (id_code == KC_F8) return fade_matrix_color_palette_load_preset_keyrecord(record);
    
  // layer move
  if (id_code == KC_F2) return firmware_map_enter_color_palette_keyrecord(record);
  if (id_code == KC_F7) return firmware_map_exit_all_keyrecord(record);
  
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
  
  return true;
}
