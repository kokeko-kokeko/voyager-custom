#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/flexible_tap_hold_behavior_os_locale.h"

#include "addons/color_palette.h"
#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/get_pos_from_keyrecord.h"

#include "layer_num.h"

// call JP keycode
#include "keymap_japanese.h"

extern bool jis_flag;
extern bool mac_flag;

// marco firmware not have common part, split 
bool process_record_macro_firmware(const uint16_t keycode, const keyrecord_t * const record) {
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
  if (base_code == KC_C) return color_palette_main_keyrecord(record);
    
  if (base_code == KC_S) return color_palette_select_keyrecord(record);
  if (base_code == KC_D) return false;
  if (base_code == KC_I) return false;
  
  return true;
}

flexible_behavior_t pos_home_row_mod(const uint8_t pos) {
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