#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/orthogonality_mod_layer_lang.h"

#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"

#include "layer_num.h"

// call JP keycode
#include "keymap_japanese.h"

static bool jis_flag = false;

static uint8_t conv_pos_to_mods(uint8_t pos) {
  switch (pos) {
    case  3: return MOD_BIT_LALT | MOD_BIT_LSHIFT;
    case  4: return MOD_BIT_LALT | MOD_BIT_LCTRL;
    case  5: return MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;

    case 28: return MOD_BIT_RALT | MOD_BIT_RSHIFT;
    case 27: return MOD_BIT_RALT | MOD_BIT_RCTRL;
    case 26: return MOD_BIT_LALT | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;

    case  7: return MOD_BIT_LSHIFT | MOD_BIT_LCTRL;
    case  8: return MOD_BIT_LGUI | MOD_BIT_LALT;
    case  9: return MOD_BIT_LSHIFT;
    case 10: return MOD_BIT_LCTRL;
    case 11: return MOD_BIT_LGUI | MOD_BIT_LSHIFT | MOD_BIT_LCTRL;

    case 36: return MOD_BIT_RSHIFT | MOD_BIT_RCTRL;
    case 35: return MOD_BIT_RGUI | MOD_BIT_RALT;
    case 34: return MOD_BIT_RSHIFT;
    case 33: return MOD_BIT_RCTRL;
    case 32: return MOD_BIT_RGUI | MOD_BIT_RSHIFT | MOD_BIT_RCTRL;

    case 12: return MOD_BIT_LCTRL;
    case 13: return MOD_BIT_LGUI;
    case 14: return MOD_BIT_LALT;
    case 15: return MOD_BIT_LGUI | MOD_BIT_LSHIFT;
    case 16: return MOD_BIT_LGUI | MOD_BIT_LCTRL;
    case 17: return MOD_BIT_LGUI | MOD_BIT_LALT | MOD_BIT_LCTRL;

    case 43: return MOD_BIT_RCTRL;
    case 42: return MOD_BIT_RGUI;
    case 41: return MOD_BIT_RALT;
    case 40: return MOD_BIT_RGUI | MOD_BIT_RSHIFT;
    case 39: return MOD_BIT_RGUI | MOD_BIT_RCTRL;
    case 38: return MOD_BIT_RGUI | MOD_BIT_RALT | MOD_BIT_RCTRL;

    case 18: return MOD_BIT_LSHIFT;

    case 49: return MOD_BIT_RSHIFT;
  }     
  
  return 0;
}

static uint8_t conv_pos_to_layer(uint8_t pos) {
  switch (pos) {
    case  6: return LAYER_L_pinky;
    case 37: return LAYER_R_pinky;

    case 22: return LAYER_Number;
    case 45: return LAYER_Cursor;

    case 24: return LAYER_Function;
    case 46: return LAYER_R_thumb_1;
    
    case 25: return LAYER_L_thumb_2;
    case 50: return LAYER_R_thumb_2;
  }
  
  return 0;
}

static bool process_record_mcfw(uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != MOD_MCFW) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode); 

  if (id_code == KC_M) {
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
  // Firmware  
  if (id_code == KC_1) return firmware_map_main_keyrecord(record);
  if (id_code == KC_3) return firmware_map_invoke_halt_keyrecord(record);
    
  // Color Palette
  if (id_code == KC_4) return fade_matrix_color_palette_main_keyrecord(record);
    
  if (id_code == KC_5) return fade_matrix_color_palette_sel_sat_keyrecord(record);
  if (id_code == KC_6) return fade_matrix_color_palette_sel_val_keyrecord(record);
    
  if (id_code == KC_8) return fade_matrix_color_palette_load_preset_keyrecord(record);
    
  // layer move
  if (id_code == KC_2) return firmware_map_enter_color_palette_keyrecord(record);
  if (id_code == KC_7) return firmware_map_exit_all_keyrecord(record);
  
  return true;
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

typedef struct user_override_conf {
  uint16_t (*const replace_func)(uint16_t);
  uint16_t (*const shift_func)(uint16_t);
  const uint16_t match_mod;
  const bool force_shift;
} user_override_conf_t;

static bool process_record_user_override_skel(const user_override_conf_t * const conf, uint16_t keycode, keyrecord_t *record) {
  if (QK_MOD_TAP_GET_MODS(keycode) != conf->match_mod) return true;

  uint16_t id_code = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  uint16_t send_tap = conf->replace_func(id_code);
  uint8_t pos = get_pos_from_keyrecord(record);
  uint8_t mods_hold = conv_pos_to_mods(pos);
  uint8_t layer_hold = conv_pos_to_layer(pos);
  
  // process shift & lang
  if (send_tap != KC_NO) {
    if ((get_mods() & MOD_MASK_SHIFT) || conf->force_shift) send_tap = conf->shift_func(send_tap);
    if (jis_flag) send_tap = conv_kc_to_jp(send_tap);
  }

  // finalize
  if (record->tap.count > 0) {
    // tap, if no hit replace, pass to normal
    if (record->event.pressed) {
      if (send_tap != KC_NO) reg16_wo_shift(send_tap);
      else return true;
    } else {
      if (send_tap != KC_NO) unreg16_wo_shift(send_tap);
      else return true;
    }
    
    // tap, non-raplace, terminate here
    return false;
  } else {
    // hold, no pass to normal
    if (record->event.pressed) {
      if (layer_hold != 0) layer_on(layer_hold);
      else if (mods_hold != 0) register_mods(mods_hold);
      else if (send_tap != KC_NO) reg16_wo_shift(send_tap);
      else register_code16(id_code); 
    } else {
      if (layer_hold != 0) layer_off(layer_hold);
      else if (mods_hold != 0) unregister_mods(mods_hold);
      else if (send_tap != KC_NO) unreg16_wo_shift(send_tap);
      else unregister_code16(id_code); 
    }  

    // hold, terminate here
    return false;
  }
  
  return true;
}

static uint16_t replace_nop(uint16_t keycode) {  
  return KC_NO;
}

static uint16_t replace_base_number(uint16_t keycode) {
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

    //case KC_KP_1: return KC_1;
    //case KC_KP_2: return KC_2;
    //case KC_KP_3: return KC_3;
    //case KC_KP_4: return KC_4;
    //case KC_KP_5: return KC_5;
    
    //case KC_KP_6: return KC_6;
    //case KC_KP_7: return KC_7;
    //case KC_KP_8: return KC_8;
    //case KC_KP_9: return KC_9;
    //case KC_KP_0: return KC_0;

    case KC_COMM: return KC_COMM;
    case KC_DOT:  return KC_DOT;

    //case KC_PCMM: return KC_COMM;
    //case KC_PDOT: return KC_DOT;
  }
  
  return KC_NO;
}

static uint16_t engram_symbol_shift(uint16_t keycode) {
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

static uint16_t replace_cursor(uint16_t keycode) {
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
  }
  
  return KC_NO;
}

static uint16_t bracket_counter_shift(uint16_t keycode) {
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

static const user_override_conf_t hoor   = {replace_nop, replace_nop, MOD_HOOR, false};
static const user_override_conf_t thor1  = {replace_base_number, engram_symbol_shift, MOD_THOR1, false};
static const user_override_conf_t thor1s = {replace_base_number, engram_symbol_shift, MOD_THOR1S, true};
static const user_override_conf_t thor2  = {replace_cursor, bracket_counter_shift, MOD_THOR2, false};
static const user_override_conf_t thor2s = {replace_cursor, bracket_counter_shift, MOD_THOR2S, true};

void jis_enable(void) {
  jis_flag = true;
}

void jis_disable(void) {
  jis_flag = false;
}

bool jis_is_enabled(void) {
  return jis_flag;
}

bool process_record_orthogonality_mod_layer_lang(uint16_t keycode, keyrecord_t *record) {
  // non-MT keycode, skip
  if (IS_QK_MOD_TAP(keycode) == false) return true;
  
  if (process_record_mcfw(keycode, record) == false) return false;  

  if (process_record_user_override_skel(&hoor, keycode, record) == false) return false;
  
  if (process_record_user_override_skel(&thor1,  keycode, record) == false) return false;
  if (process_record_user_override_skel(&thor1s, keycode, record) == false) return false;
  
  if (process_record_user_override_skel(&thor2,  keycode, record) == false) return false;
  if (process_record_user_override_skel(&thor2s, keycode, record) == false) return false;
    
  return true;
}
