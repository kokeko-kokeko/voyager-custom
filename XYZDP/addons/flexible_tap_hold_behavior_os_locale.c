#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/flexible_tap_hold_behavior_os_locale.h"

#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/get_pos_from_keyrecord.h"

#include "layer_num.h"

// call JP keycode
#include "keymap_japanese.h"

static bool jis_flag = false;
static bool mac_flag = false;

// flexible tap hold behavior
// calc tap-hold by qmk MT(XXX) keycode
// following sequence
// 1. split tap or hold first, each independest chain
// 2. get action from position func and exec, if nop next step
// 3. get action from base keycode func (QK_MOD_TAP_GET_TAP_KEYCODE), if nop next step
// 4. send base keycode
//
// make universal function and make conf struct to args 

enum flexible_behavior_operation_identifier {
  FB_NOP = 0,               // nop command, pass next step, data not use
  FB_PASS_QMK,              // pass to qmk, terminate process return true, data not use
  FB_KEYCODE,               // keycode, data8 is option 8bit mods mask, data16 is keycode
  FB_KEYCODE_TAP,           // keycode tap, data8 is option 8bit mods mask, data16 is keycode
  FB_KEYCODE_TAP_KEEP_MODS, // keycode tap keep mod, data8 is keep 8bit mods mask, data16 is keycode (for taskswitch)
  FB_MODS,                  // only mods key, data8 is 8bit mods mask
  FB_LAYER,                 // activate layer, data8 is layer number
  FB_CAPS_WORD,             // caps word, data not use
  FB_SWAP_HANDS,            // swap hands, data not use
  FB_NOP_ERROR              // nop with error report (use on non-reach default valueS) 
};

_Static_assert(FB_NOP_ERROR <= UINT8_MAX, "too many flexible_behavior_operation_identifier!!");

typedef struct flexible_behavior {
  uint8_t op_id;
  uint8_t data8;
  uint16_t data16;
} flexible_behavior_t;

// check udner 32-bit
_Static_assert(sizeof(flexible_behavior_t) <= sizeof(uint32_t), "flexible_behavior struct too large!!");

// use 8bit mod bitmask
// KC_NO = 0x0000,
// MOD_BIT_LCTRL  = 0b00000001,
// MOD_BIT_LSHIFT = 0b00000010,
// MOD_BIT_LALT   = 0b00000100,
// MOD_BIT_LGUI   = 0b00001000,
// MOD_BIT_RCTRL  = 0b00010000,
// MOD_BIT_RSHIFT = 0b00100000,
// MOD_BIT_RALT   = 0b01000000,
// MOD_BIT_RGUI   = 0b10000000,

static flexible_behavior_t pos_nop(const uint8_t pos) {
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static flexible_behavior_t pos_home_row_mod(const uint8_t pos) {
  switch (pos) {
    case  0: return (flexible_behavior_t){FB_CAPS_WORD, 0, 0};
    case  1: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL, 0};
    case  2: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LCTRL, 0};
    case  3: return (flexible_behavior_t){FB_MODS, MOD_BIT_LALT | MOD_BIT_LSHIFT, 0};
    case  4: return (flexible_behavior_t){FB_MODS, MOD_BIT_LALT | MOD_BIT_LCTRL, 0};
    case  5: return (flexible_behavior_t){FB_MODS, MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL, 0};

    case 31: return (flexible_behavior_t){FB_CAPS_WORD, 0, 0};
    case 30: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RALT | MOD_BIT_RSHIFT | MOD_BIT_RCTRL, 0};
    case 29: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RALT | MOD_BIT_RCTRL, 0};
    case 28: return (flexible_behavior_t){FB_MODS, MOD_BIT_RALT | MOD_BIT_RSHIFT, 0};
    case 27: return (flexible_behavior_t){FB_MODS, MOD_BIT_RALT | MOD_BIT_RCTRL, 0};
    case 26: return (flexible_behavior_t){FB_MODS, MOD_BIT_RALT | MOD_BIT_RSHIFT | MOD_BIT_RCTRL, 0};

    case  6: return (flexible_behavior_t){FB_LAYER, LAYER_L_pinky, 0};
    case  7: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT, 0};
    case  8: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LALT, 0};
    case  9: return (flexible_behavior_t){FB_MODS, MOD_BIT_LSHIFT, 0};
    case 10: return (flexible_behavior_t){FB_MODS, MOD_BIT_LCTRL, 0};
    case 11: return (flexible_behavior_t){FB_MODS, MOD_BIT_LSHIFT | MOD_BIT_LCTRL, 0};

    case 37: return (flexible_behavior_t){FB_LAYER, LAYER_R_pinky, 0};
    case 36: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RALT | MOD_BIT_RSHIFT, 0};
    case 35: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RALT, 0};
    case 34: return (flexible_behavior_t){FB_MODS, MOD_BIT_RSHIFT, 0};
    case 33: return (flexible_behavior_t){FB_MODS, MOD_BIT_RCTRL, 0};
    case 32: return (flexible_behavior_t){FB_MODS, MOD_BIT_RSHIFT | MOD_BIT_RCTRL, 0};

    case 12: return (flexible_behavior_t){FB_MODS, MOD_BIT_LCTRL, 0};
    case 13: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI, 0};
    case 14: return (flexible_behavior_t){FB_MODS, MOD_BIT_LALT, 0};
    case 15: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LSHIFT, 0};
    case 16: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LCTRL, 0};
    case 17: return (flexible_behavior_t){FB_MODS, MOD_BIT_LGUI | MOD_BIT_LSHIFT | MOD_BIT_LCTRL, 0};

    case 43: return (flexible_behavior_t){FB_MODS, MOD_BIT_RCTRL, 0};
    case 42: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI, 0};
    case 41: return (flexible_behavior_t){FB_MODS, MOD_BIT_RALT, 0};
    case 40: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RSHIFT, 0};
    case 39: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RCTRL, 0};
    case 38: return (flexible_behavior_t){FB_MODS, MOD_BIT_RGUI | MOD_BIT_RSHIFT | MOD_BIT_RCTRL, 0};

    case 18: return (flexible_behavior_t){FB_MODS, MOD_BIT_LSHIFT, 0};
    case 22: return (flexible_behavior_t){FB_LAYER, LAYER_Number, 0};
    case 23: return (flexible_behavior_t){FB_SWAP_HANDS, 0, 0};

    case 49: return (flexible_behavior_t){FB_MODS, MOD_BIT_RSHIFT, 0};
    case 46: return (flexible_behavior_t){FB_LAYER, LAYER_R_thumb_1, 0};    
    case 45: return (flexible_behavior_t){FB_LAYER, LAYER_Cursor, 0};
    case 44: return (flexible_behavior_t){FB_SWAP_HANDS, 0, 0};

    case 24: return (flexible_behavior_t){FB_LAYER, LAYER_Function, 0};
    case 25: return (flexible_behavior_t){FB_LAYER, LAYER_L_thumb_2, 0};

    case 50: return (flexible_behavior_t){FB_LAYER, LAYER_R_thumb_2, 0};
  }     
  
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static bool process_record_macro_firmware(const uint16_t keycode, const keyrecord_t * const record) {
  if ((IS_QK_MOD_TAP(keycode) == false) || (QK_MOD_TAP_GET_MODS(keycode) != MOD_MCFW)) return true;

  const uint16_t base_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode); 

  if (base_code == KC_M) {
    if (record->event.pressed) {
      const uint8_t pos = get_pos_from_keyrecord(record);

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
  
  // Firmware  
  if (base_code == KC_F) return firmware_map_main_keyrecord(record);
  if (base_code == KC_H) return firmware_map_invoke_halt_keyrecord(record);
    
  // Color Palette
  if (base_code == KC_C) return fade_matrix_color_palette_main_keyrecord(record);
    
  if (base_code == KC_S) return fade_matrix_color_palette_select_keyrecord(record);
  if (base_code == KC_D) return false;
  if (base_code == KC_I) return false;
  
  return true;
}

static void reg16_wo_shift(const uint16_t code16) {
  uint8_t seved_mods = get_mods();
  
  del_mods(MOD_MASK_SHIFT);
  register_code16(code16);
  add_mods(seved_mods);   
}

static void unreg16_wo_shift(const uint16_t code16) {
  uint8_t seved_mods = get_mods();

  del_mods(MOD_MASK_SHIFT);
  unregister_code16(code16);
  add_mods(seved_mods);
}

static void tap16_wo_shift(const uint16_t code16) {
  uint8_t seved_mods = get_mods();

  del_mods(MOD_MASK_SHIFT);
  tap_code16(code16);
  add_mods(seved_mods);
}

static bool process_record_user_task_switch_next_prev(const uint16_t keycode, const keyrecord_t * const record) {
  static bool is_active = false;
  
  if (keycode == TKSW(KC_N)) {
    // MT template
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        if (is_active == false) {
          is_active = true;
          if (mac_flag) register_mods(MOD_BIT_RGUI);
          else register_mods(MOD_BIT_RALT);
        }
        tap16_wo_shift(KC_TAB);
      } else {
        
      }
    } else {
      if (record->event.pressed) {
        is_active = false;
        if (mac_flag) unregister_mods(MOD_BIT_RGUI);
        else unregister_mods(MOD_BIT_RALT);

        if (mac_flag) tap16_wo_shift(LCTL(KC_UP));
        else tap16_wo_shift(LGUI(KC_TAB));
      } else {
        
      }
    }

    return false;
  } 
  
  if (keycode == TKSW(KC_P)) {
    // MT template
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        if (is_active == false) {
          is_active = true;
          if (mac_flag) register_mods(MOD_BIT_RGUI);
          else register_mods(MOD_BIT_RALT);
        }
        tap16_wo_shift(LSFT(KC_TAB));
      } else {
        
      }
    } else {
      if (record->event.pressed) {
        is_active = false;
        if (mac_flag) unregister_mods(MOD_BIT_RGUI);
        else unregister_mods(MOD_BIT_RALT);

        //if (mac_flag) tap16_wo_shift(LCTL(KC_UP));
        //else tap16_wo_shift(LGUI(KC_TAB));
      } else {
        
      }
    }
    
    return false;
  }

  // another key, release manu setting
  if (is_active) {
    // keep task switch for cursor
    if (
      (keycode == KC_RIGHT) || 
      (keycode == KC_LEFT) ||
      (keycode == KC_DOWN) ||
      (keycode == KC_UP)
      ) return true;
      
    is_active = false;
    if (mac_flag) unregister_mods(MOD_BIT_RGUI);
    else unregister_mods(MOD_BIT_RALT);
  }
  
  return true;
}

static bool process_record_user_hold_back(const uint16_t keycode, const keyrecord_t * const record) { 
  if (keycode == THOR1S(KC_E)) {
    // MT template
    if (record->tap.count > 0) {
      // tap pass after
      return true;
    } else {
      if (record->event.pressed) {
        if (mac_flag) tap16_wo_shift(LGUI(KC_LEFT));
        else tap16_wo_shift(LALT(KC_LEFT));
      } else {
        
      }
    }

    return false;
  } 
    
  return true;
}

static bool process_record_user_hold_reload(const uint16_t keycode, const keyrecord_t * const record) { 
  if (keycode == THOR2(KC_N)) {
    // MT template
    if (record->tap.count > 0) {
      // tap pass after
      return true;
    } else {
      if (record->event.pressed) {
        if (mac_flag) tap16_wo_shift(LGUI(KC_R));
        else tap16_wo_shift(LCTL(KC_R));
      } else {
        
      }
    }

    return false;
  } 
    
  return true;
}

static bool process_record_user_hold_force_reload(const uint16_t keycode, const keyrecord_t * const record) { 
  if (keycode == THOR2(KC_P)) {
    // MT template
    if (record->tap.count > 0) {
      // tap pass after
      return true;
    } else {
      if (record->event.pressed) {
        if (mac_flag) tap16_wo_shift(LGUI(LSFT(KC_R)));
        else tap16_wo_shift(LCTL(LSFT(KC_R)));
      } else {
        
      }
    }

    return false;
  } 
    
  return true;
}

static uint16_t conv_kc_to_jp(const uint16_t keycode) {
  switch (keycode) {
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
  }
  
  return keycode;
}

static uint8_t conv_mods_pc_to_mac(uint8_t mods) {
  if ((mods & MOD_MASK_CG) == 0) return mods;
  
  bool l_ctrl = mods & MOD_BIT_LCTRL;
  bool r_ctrl = mods & MOD_BIT_RCTRL;
  bool l_gui = mods & MOD_BIT_LGUI;
  bool r_gui = mods & MOD_BIT_RGUI;

  mods &= ~MOD_MASK_CG;

  if (l_ctrl) mods |= MOD_BIT_LGUI;
  if (r_ctrl) mods |= MOD_BIT_RGUI;
  if (l_gui) mods |= MOD_BIT_LCTRL;
  if (r_gui) mods |= MOD_BIT_RCTRL;

  return mods;
}
 
// pos keycode shift

typedef struct flexible_behavior_conf {
  flexible_behavior_t (* const tap_pos_func)(uint8_t);
  flexible_behavior_t (* const tap_keycode_func)(uint16_t);
  uint16_t (* const tap_shift_func)(uint16_t);
  flexible_behavior_t (* const hold_pos_func)(uint8_t);
  flexible_behavior_t (* const hold_keycode_func)(uint16_t);
  uint16_t (* const hold_shift_func)(uint16_t);
  const uint16_t match_mods;
  const bool force_shift;
} flexible_behavior_conf_t;

static bool process_record_generic_tap_hold_skel(const flexible_behavior_conf_t * const conf, const uint16_t keycode, const keyrecord_t * const record) {
  if ((IS_QK_MOD_TAP(keycode) == false) || (QK_MOD_TAP_GET_MODS(keycode) != conf->match_mods)) return true;
  
  // tap/hold first
  bool is_tap = (record->tap.count > 0);

  const uint8_t pos = get_pos_from_keyrecord(record);
  const uint16_t base_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

  flexible_behavior_t behav[2];
  behav[0] = (is_tap) ? conf->tap_pos_func(pos) : conf->hold_pos_func(pos);
  behav[1] = (is_tap) ? conf->tap_keycode_func(base_code) : conf->hold_keycode_func(base_code);

  // search behavior loop
  for (int i = 0; i < 2; i++) {
    if (behav[i].op_id == FB_NOP) {
      continue;
    }
    
    if (behav[i].op_id == FB_PASS_QMK) {
      return true;
    }

    if (behav[i].op_id == FB_KEYCODE) {
      // process shift & lang
      if ((get_mods() & MOD_MASK_SHIFT) || conf->force_shift) {
        behav[i].data16 = (is_tap) ? conf->tap_shift_func(behav[i].data16) : conf->hold_shift_func(behav[i].data16);
      } 
      
      if (jis_flag) behav[i].data16 = conv_kc_to_jp(behav[i].data16);
      
      if (record->event.pressed) reg16_wo_shift(behav[i].data16);
      else unreg16_wo_shift(behav[i].data16);
      
      return false;
    }
    
    if (behav[i].op_id == FB_MODS) {
      if (mac_flag) behav[i].data8 = conv_mods_pc_to_mac(behav[i].data8);

      if (record->event.pressed) register_mods(behav[i].data8);
      else unregister_mods(behav[i].data8);

      return false;
    }
    
    if (behav[i].op_id == FB_LAYER) {
      if (record->event.pressed) layer_on(behav[i].data8);
      else layer_off(behav[i].data8);

      return false;
    }

    if (behav[i].op_id == FB_CAPS_WORD) {
      if (record->event.pressed) caps_word_toggle();

      return false;
    }

    if (behav[i].op_id == FB_SWAP_HANDS) {
      if (record->event.pressed) swap_hands_on();
      else swap_hands_off();

      return false;
    }
  }

  // no hit behavior send base code
  if (record->event.pressed) register_code16(base_code);
  else unregister_code16(base_code);

  // if run function must terminate here
  return false;
}

static flexible_behavior_t keycode_pass_qmk(const uint16_t keycode) {  
  return (flexible_behavior_t){FB_PASS_QMK, 0, 0};
}

static flexible_behavior_t keycode_nop(const uint16_t keycode) {  
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static uint16_t shift_nop(const uint16_t keycode) {  
  return keycode;
}

static flexible_behavior_t keycode_base_number(const uint16_t keycode) {
  switch (keycode) {
    case KC_A: return (flexible_behavior_t){FB_KEYCODE, 0, KC_AT};
    case KC_B: return (flexible_behavior_t){FB_KEYCODE, 0, KC_HASH};
    case KC_C: return (flexible_behavior_t){FB_KEYCODE, 0, KC_QUOT};
    case KC_D: return (flexible_behavior_t){FB_KEYCODE, 0, KC_COMM};
    case KC_E: return (flexible_behavior_t){FB_KEYCODE, 0, KC_MINS};
    case KC_F: return (flexible_behavior_t){FB_KEYCODE, 0, KC_SLSH};
    case KC_G: return (flexible_behavior_t){FB_KEYCODE, 0, KC_DQUO};
    case KC_H: return (flexible_behavior_t){FB_KEYCODE, 0, KC_DOT};
    case KC_I: return (flexible_behavior_t){FB_KEYCODE, 0, KC_QUES};

    case KC_L: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LBRC};
    case KC_R: return (flexible_behavior_t){FB_KEYCODE, 0, KC_RBRC};

    case KC_1: return (flexible_behavior_t){FB_KEYCODE, 0, KC_1};
    case KC_2: return (flexible_behavior_t){FB_KEYCODE, 0, KC_2};
    case KC_3: return (flexible_behavior_t){FB_KEYCODE, 0, KC_3};
    case KC_4: return (flexible_behavior_t){FB_KEYCODE, 0, KC_4};
    case KC_5: return (flexible_behavior_t){FB_KEYCODE, 0, KC_5};
    
    case KC_6: return (flexible_behavior_t){FB_KEYCODE, 0, KC_6};
    case KC_7: return (flexible_behavior_t){FB_KEYCODE, 0, KC_7};
    case KC_8: return (flexible_behavior_t){FB_KEYCODE, 0, KC_8};
    case KC_9: return (flexible_behavior_t){FB_KEYCODE, 0, KC_9};
    case KC_0: return (flexible_behavior_t){FB_KEYCODE, 0, KC_0};
    
    case KC_COMM: return (flexible_behavior_t){FB_KEYCODE, 0, KC_COMM};
    case KC_DOT:  return (flexible_behavior_t){FB_KEYCODE, 0, KC_DOT};
  }
  
  return (flexible_behavior_t){FB_NOP_ERROR, 0, 0};
}

static uint16_t shift_engram_symbol(const uint16_t keycode) {
  switch (keycode) {
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
  }
  
  return keycode;
}

static flexible_behavior_t keycode_cursor(const uint16_t keycode) {
  // must use QK_ for bit position
  uint16_t sc_mod = QK_LCTL;
  if (mac_flag) sc_mod = QK_LGUI;
  
  switch (keycode) {
    case KC_P: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | LSFT(KC_TAB)};
    case KC_N: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | KC_TAB};
    
    case KC_Z: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | KC_Z};
    case KC_X: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | KC_X};
    case KC_C: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | KC_C};
    case KC_V: return (flexible_behavior_t){FB_KEYCODE, 0, sc_mod | KC_V};
    
    case KC_1: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LBRC};
    case KC_2: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LCBR};
    case KC_3: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LABK};
    case KC_4: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LPRN};

    case KC_5: return (flexible_behavior_t){FB_KEYCODE, 0, KC_EXLM};
    case KC_6: return (flexible_behavior_t){FB_KEYCODE, 0, KC_QUES};
  }
  
  return (flexible_behavior_t){FB_NOP_ERROR, 0, 0};
}

static uint16_t shift_bracket_counter(const uint16_t keycode) {
  switch (keycode) {
    case KC_LBRC: return KC_RBRC;
    case KC_LCBR: return KC_RCBR;
    case KC_LABK: return KC_RABK;
    case KC_LPRN: return KC_RPRN;

    case KC_RBRC: return KC_LBRC;
    case KC_RCBR: return KC_LCBR;
    case KC_RABK: return KC_LABK;
    case KC_RPRN: return KC_LPRN;
  }
  
  return keycode;
}

void jis_enable(void) {
  jis_flag = true;
}

void jis_disable(void) {
  jis_flag = false;
}

bool jis_is_enabled(void) {
  return jis_flag;
}

void mac_enable(void) {
  mac_flag = true;
}

void mac_disable(void) {
  mac_flag = false;
}

bool mac_is_enabled(void) {
  return mac_flag;
}

bool process_detected_host_os_flexible_tap_hold_behavior_os_locale(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
      jis_flag = true;
      mac_flag = true;
      break;
    case OS_IOS:
      jis_flag = false;
      mac_flag = true;
      break;
    case OS_WINDOWS:
      jis_flag = true;
      mac_flag = false;
      break;
    case OS_LINUX:
      jis_flag = false;
      mac_flag = false;
      break;
    case OS_UNSURE:
      break;
  }
  
  return true;
}

//                                                                       | tap                                                 | hold
static const flexible_behavior_conf_t hoor   = (flexible_behavior_conf_t){pos_nop, keycode_pass_qmk,    shift_nop,             pos_home_row_mod, keycode_nop,         shift_nop,             MOD_HOOR, false};
static const flexible_behavior_conf_t thor1  = (flexible_behavior_conf_t){pos_nop, keycode_base_number, shift_engram_symbol,   pos_home_row_mod, keycode_base_number, shift_engram_symbol,   MOD_THOR1, false};
static const flexible_behavior_conf_t thor1s = (flexible_behavior_conf_t){pos_nop, keycode_base_number, shift_engram_symbol,   pos_home_row_mod, keycode_base_number, shift_engram_symbol,   MOD_THOR1S, true};
static const flexible_behavior_conf_t thor2  = (flexible_behavior_conf_t){pos_nop, keycode_cursor,      shift_bracket_counter, pos_home_row_mod, keycode_cursor,      shift_bracket_counter, MOD_THOR2, false};
static const flexible_behavior_conf_t thor2s = (flexible_behavior_conf_t){pos_nop, keycode_cursor,      shift_bracket_counter, pos_home_row_mod, keycode_cursor,      shift_bracket_counter, MOD_THOR2S, true};

bool process_record_flexible_tap_hold_behavior_os_locale(uint16_t keycode, keyrecord_t *record) {  
  if (process_record_macro_firmware(keycode, record) == false) return false;

  if (process_record_user_task_switch_next_prev(keycode, record) == false) return false;
  if (process_record_user_hold_back(keycode, record) == false) return false;
  if (process_record_user_hold_reload(keycode, record) == false) return false;
  if (process_record_user_hold_force_reload(keycode, record) == false) return false;

  if (process_record_generic_tap_hold_skel(&hoor, keycode, record) == false) return false;
  
  if (process_record_generic_tap_hold_skel(&thor1, keycode, record) == false) return false;
  if (process_record_generic_tap_hold_skel(&thor1s, keycode, record) == false) return false;
  
  if (process_record_generic_tap_hold_skel(&thor2, keycode, record) == false) return false;
  if (process_record_generic_tap_hold_skel(&thor2s, keycode, record) == false) return false;
    
  return true;
}
