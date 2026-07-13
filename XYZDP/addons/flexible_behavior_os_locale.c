#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/flexible_behavior_os_locale.h"

#include "addons/color_palette.h"
#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/get_pos_from_keyrecord.h"

#include "layer_num.h"

// call JP keycode
#include "keymap_japanese.h"

// size check
_Static_assert(FB_TERMINATE_WITH_ERROR <= UINT8_MAX, "too many flexible_behavior_operation_identifier!!");

// check udner 32-bit, registor return
_Static_assert(sizeof(flexible_behavior_t) <= sizeof(uint32_t), "flexible_behavior struct too large!!");

bool flexible_behavior_jis_flag = false;
bool flexible_behavior_mac_flag = false;
bool flexible_behavior_error_flag = false;

// marco firmware not have common part, split 
extern bool process_record_macro_firmware(const uint16_t keycode, const keyrecord_t * const record);

// util, without shift command
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

// keep mod support func
static uint8_t flexible_behavior_keep_mods = 0;

static void add_keep_mods (uint8_t mods) {
  if (flexible_behavior_keep_mods != mods) {
    del_mods(flexible_behavior_keep_mods);
    add_mods(mods);
    flexible_behavior_keep_mods = mods;
  }
}

static void unreg_keep_mods (void) {
  if (flexible_behavior_keep_mods != 0) {
    unregister_mods(flexible_behavior_keep_mods);
    flexible_behavior_keep_mods = 0;
  }
}

// util, conv system wide 
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

// conf struct, pos keycode shift * tap hold

typedef struct flexible_behavior_conf {
  flexible_behavior_t (* const tap_eager_from_tap_keycode)(uint16_t);
  flexible_behavior_t (* const tap_from_pos)(uint8_t);
  flexible_behavior_t (* const tap_defer_from_tap_keycode)(uint16_t);
  uint16_t (* const tap_shift_func)(uint16_t);
  flexible_behavior_t (* const hold_eager_from_tap_keycode)(uint16_t);
  flexible_behavior_t (* const hold_from_pos)(uint8_t);
  flexible_behavior_t (* const hold_defer_from_tap_keycode)(uint16_t);
  uint16_t (* const hold_shift_func)(uint16_t);
  const uint16_t match_mods;
  const bool force_shift;
} flexible_behavior_conf_t;

static bool process_record_flexible_behavior_skel(const flexible_behavior_conf_t * const conf, const uint16_t keycode, const keyrecord_t * const record) {
  if ((IS_QK_MOD_TAP(keycode) == false) || (QK_MOD_TAP_GET_MODS(keycode) != conf->match_mods)) return true;
  
  // tap/hold first
  bool is_tap = (record->tap.count > 0);
  
  const uint16_t tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  const uint8_t pos = get_pos_from_keyrecord(record);
  
  flexible_behavior_t behav[3];
  behav[0] = (is_tap) ? conf->tap_eager_from_tap_keycode(tap_keycode) : conf->hold_eager_from_tap_keycode(tap_keycode);
  behav[1] = (is_tap) ? conf->tap_from_pos(pos)                       : conf->hold_from_pos(pos);
  behav[2] = (is_tap) ? conf->tap_defer_from_tap_keycode(tap_keycode) : conf->hold_defer_from_tap_keycode(tap_keycode);

  // search behavior loop
  for (int i = 0; i < 3; i++) {
    if (behav[i].op_id == FB_NOP) {
      continue;
    }

    if (behav[i].op_id == FB_PASS_QMK) {
      unreg_keep_mods();
      return true;
    }

    if (behav[i].op_id == FB_SEND_TAP_KEYCODE) {
      unreg_keep_mods();

      if (record->event.pressed) register_code16(tap_keycode);
      else unregister_code16(tap_keycode);
      
      return false;
    }

    if (behav[i].op_id == FB_KEYCODE) {
      // process shift & lang
      if ((get_mods() & MOD_MASK_SHIFT) || conf->force_shift) {
        behav[i].data_u16 = (is_tap) ? conf->tap_shift_func(behav[i].data_u16) : conf->hold_shift_func(behav[i].data_u16);
      } 
      
      if (flexible_behavior_jis_flag) behav[i].data_u16 = conv_kc_to_jp(behav[i].data_u16);
      
      // process opition mod
      if (flexible_behavior_mac_flag) behav[i].data_u8 = conv_mods_pc_to_mac(behav[i].data_u8);
      
      unreg_keep_mods();

      if (record->event.pressed) {
        add_mods(behav[i].data_u8);
        reg16_wo_shift(behav[i].data_u16);
      } else {
        del_mods(behav[i].data_u8);
        unreg16_wo_shift(behav[i].data_u16);
      }
      
      return false;
    }

    if (behav[i].op_id == FB_KEYCODE_TAP) {
      // process shift & lang
      if ((get_mods() & MOD_MASK_SHIFT) || conf->force_shift) {
        behav[i].data_u16 = (is_tap) ? conf->tap_shift_func(behav[i].data_u16) : conf->hold_shift_func(behav[i].data_u16);
      } 
      
      if (flexible_behavior_jis_flag) behav[i].data_u16 = conv_kc_to_jp(behav[i].data_u16);
      
      // process opition mod
      if (flexible_behavior_mac_flag) behav[i].data_u8 = conv_mods_pc_to_mac(behav[i].data_u8);

      unreg_keep_mods();

      if (record->event.pressed) {
        add_mods(behav[i].data_u8);
        tap16_wo_shift(behav[i].data_u16);
        unregister_mods(behav[i].data_u8);
      }

      return false;
    }

    if (behav[i].op_id == FB_KEYCODE_TAP_KEEP_MODS) {
      // process shift & lang
      if ((get_mods() & MOD_MASK_SHIFT) || conf->force_shift) {
        behav[i].data_u16 = (is_tap) ? conf->tap_shift_func(behav[i].data_u16) : conf->hold_shift_func(behav[i].data_u16);
      } 
      
      if (flexible_behavior_jis_flag) behav[i].data_u16 = conv_kc_to_jp(behav[i].data_u16);
      
      // process opition mod
      if (flexible_behavior_mac_flag) behav[i].data_u8 = conv_mods_pc_to_mac(behav[i].data_u8);

      if (record->event.pressed) {
        add_keep_mods(behav[i].data_u8);
        tap16_wo_shift(behav[i].data_u16);
      }

      return false;
    }
    if (behav[i].op_id == FB_MODS) {
      // process mod
      if (flexible_behavior_mac_flag) behav[i].data_u8 = conv_mods_pc_to_mac(behav[i].data_u8);

      unreg_keep_mods();

      if (record->event.pressed) register_mods(behav[i].data_u8);
      else unregister_mods(behav[i].data_u8);

      return false;
    }
    
    if (behav[i].op_id == FB_LAYER) {
      unreg_keep_mods();

      if (record->event.pressed) layer_on(behav[i].data_u8);
      else layer_off(behav[i].data_u8);

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

    if (behav[i].op_id == FB_TERMINATE_WITH_ERROR) {
      // add error flag
      flexible_behavior_error_flag = true;
      
      return false;
    }
  }

  // reach here error flag
  flexible_behavior_error_flag = true;

  // terminate here
  return false;
}

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

// fixed return functions
static flexible_behavior_t base_code_nop(const uint16_t tap_keycode) {  
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static flexible_behavior_t base_code_pass_qmk(const uint16_t tap_keycode) {  
  return (flexible_behavior_t){FB_PASS_QMK, 0, 0};
}

static flexible_behavior_t base_code_send_tap_keycode(const uint16_t tap_keycode) {  
  return (flexible_behavior_t){FB_SEND_TAP_KEYCODE, 0, 0};
}

static flexible_behavior_t base_code_term_error(const uint16_t tap_keycode) {  
  return (flexible_behavior_t){FB_TERMINATE_WITH_ERROR, 0, 0};
}

// non-reach with error
static flexible_behavior_t pos_term_error(const uint8_t pos) {
  return (flexible_behavior_t){FB_TERMINATE_WITH_ERROR, 0, 0};
}

static uint16_t shift_nop(const uint16_t keycode) {  
  return keycode;
}

extern flexible_behavior_t pos_home_row_mod(const uint8_t pos);

static flexible_behavior_t base_code_engram_sym_num(const uint16_t tap_keycode) {
  switch (tap_keycode) {
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
  
  return (flexible_behavior_t){FB_TERMINATE_WITH_ERROR, 0, 0};
}

static uint16_t shift_engram_sym_num(const uint16_t keycode) {
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

static flexible_behavior_t base_code_cursor(const uint16_t tap_keycode) {
  // must use QK_ for bit position
  //uint16_t sc_mod = QK_LCTL;
  //if (flexible_behavior_mac_flag) sc_mod = QK_LGUI;
  
  switch (tap_keycode) {
    // browser tab operation
    case KC_P: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, LSFT(KC_TAB)};
    case KC_N: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, KC_TAB};
    
    case KC_Z: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, KC_Z};
    case KC_X: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, KC_X};
    case KC_C: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, KC_C};
    case KC_V: return (flexible_behavior_t){FB_KEYCODE, MOD_BIT_LCTRL, KC_V};
    
    case KC_1: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LBRC};
    case KC_2: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LCBR};
    case KC_3: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LABK};
    case KC_4: return (flexible_behavior_t){FB_KEYCODE, 0, KC_LPRN};

    case KC_5: return (flexible_behavior_t){FB_KEYCODE, 0, KC_EXLM};
    case KC_6: return (flexible_behavior_t){FB_KEYCODE, 0, KC_QUES};
  }
  
  return (flexible_behavior_t){FB_TERMINATE_WITH_ERROR, 0, 0};
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

static flexible_behavior_t base_code_browser_back(const uint16_t tap_keycode) {
  switch (tap_keycode) {
    // hold side browser ENSNS symbol
    case KC_E: return (flexible_behavior_t){FB_KEYCODE_TAP, 0, LALT(KC_LEFT)};
  }
  
  // no-error on hit
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static flexible_behavior_t base_code_browser_reload(const uint16_t tap_keycode) {
  switch (tap_keycode) {
    // hold side browser tab operation
    case KC_P: return (flexible_behavior_t){FB_KEYCODE_TAP, MOD_BIT_LCTRL, LSFT(KC_R)};
    case KC_N: return (flexible_behavior_t){FB_KEYCODE_TAP, MOD_BIT_LCTRL, KC_R};
  }
  
  // no-error on hit
  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static flexible_behavior_t base_code_task_switch(const uint16_t tap_keycode) {
  uint8_t mod_bit = MOD_BIT_RALT;
  if (flexible_behavior_mac_flag) mod_bit = MOD_BIT_RCTRL; //conv to gui

  switch (tap_keycode) {
    // hold side browser tab operation
    case KC_P: return (flexible_behavior_t){FB_KEYCODE_TAP_KEEP_MODS, mod_bit, LSFT(KC_TAB)};
    case KC_N: return (flexible_behavior_t){FB_KEYCODE_TAP_KEEP_MODS, mod_bit, KC_TAB};
  }

  return (flexible_behavior_t){FB_NOP, 0, 0};
}

static flexible_behavior_t base_code_task_view(const uint16_t tap_keycode) {
  uint16_t keycode = KC_TAB;
  if (flexible_behavior_mac_flag) keycode = KC_UP;

  switch (tap_keycode) {
    // hold side browser tab operation
    case KC_P: return (flexible_behavior_t){FB_KEYCODE_TAP, MOD_BIT_RGUI, keycode};
    case KC_N: return (flexible_behavior_t){FB_KEYCODE_TAP, MOD_BIT_RGUI, keycode};
  }

  return (flexible_behavior_t){FB_NOP, 0, 0};
}

// public function

void jis_enable(void) {
  flexible_behavior_jis_flag = true;
}

void jis_disable(void) {
  flexible_behavior_jis_flag = false;
}

bool jis_is_enabled(void) {
  return flexible_behavior_jis_flag;
}

void mac_enable(void) {
  flexible_behavior_mac_flag = true;
}

void mac_disable(void) {
  flexible_behavior_mac_flag = false;
}

bool mac_is_enabled(void) {
  return flexible_behavior_mac_flag;
}

void flexible_behavior_clear_error(void) {
  flexible_behavior_error_flag = false;
}

bool flexible_behavior_has_error(void) {
  return flexible_behavior_error_flag;
}


bool process_detected_host_os_flexible_behavior_os_locale(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
      flexible_behavior_jis_flag = true;
      flexible_behavior_mac_flag = true;
      break;
    case OS_IOS:
      flexible_behavior_jis_flag = false;
      flexible_behavior_mac_flag = true;
      break;
    case OS_WINDOWS:
      flexible_behavior_jis_flag = true;
      flexible_behavior_mac_flag = false;
      //test
      //flexible_behavior_error_flag = true;
      break;
    case OS_LINUX:
      flexible_behavior_jis_flag = false;
      flexible_behavior_mac_flag = false;
      break;
    case OS_UNSURE:
      break;
  }
  
  return true;
}

//                                                                            | tap                                                                                  | hold                                                                                         | target   | shift
//                                                                            | eager                   | pos           | defer               | shift                | eager                   | pos             | defer                     | shift                |          |
static const flexible_behavior_conf_t conf_ptmh  = (flexible_behavior_conf_t){base_code_pass_qmk,       pos_term_error, base_code_term_error, shift_nop,             base_code_nop,            pos_home_row_mod, base_code_send_tap_keycode, shift_nop,             MOD_PTMH,  false};
static const flexible_behavior_conf_t conf_ensn  = (flexible_behavior_conf_t){base_code_engram_sym_num, pos_term_error, base_code_term_error, shift_engram_sym_num,  base_code_nop,            pos_home_row_mod, base_code_engram_sym_num,   shift_engram_sym_num,  MOD_ENSN,  false};
static const flexible_behavior_conf_t conf_ensns = (flexible_behavior_conf_t){base_code_engram_sym_num, pos_term_error, base_code_term_error, shift_engram_sym_num,  base_code_browser_back,   pos_home_row_mod, base_code_engram_sym_num,   shift_engram_sym_num,  MOD_ENSNS, true};
static const flexible_behavior_conf_t conf_cure  = (flexible_behavior_conf_t){base_code_cursor,         pos_term_error, base_code_term_error, shift_bracket_counter, base_code_browser_reload, pos_home_row_mod, base_code_cursor,           shift_bracket_counter, MOD_CURE,  false};
static const flexible_behavior_conf_t conf_cures = (flexible_behavior_conf_t){base_code_cursor,         pos_term_error, base_code_term_error, shift_bracket_counter, base_code_nop,            pos_home_row_mod, base_code_cursor,           shift_bracket_counter, MOD_CURES, true};
static const flexible_behavior_conf_t conf_tksw  = (flexible_behavior_conf_t){base_code_task_switch,    pos_term_error, base_code_term_error, shift_nop,             base_code_task_view,      pos_term_error,   base_code_term_error,       shift_nop,             MOD_TKSW,  false};

bool process_record_flexible_behavior_os_locale(uint16_t keycode, keyrecord_t *record) {  
  if (process_record_macro_firmware(keycode, record) == false) return false;

  if (process_record_flexible_behavior_skel(&conf_ptmh,  keycode, record) == false) return false;
  
  if (process_record_flexible_behavior_skel(&conf_ensn,  keycode, record) == false) return false;
  if (process_record_flexible_behavior_skel(&conf_ensns, keycode, record) == false) return false;
  
  if (process_record_flexible_behavior_skel(&conf_cure,  keycode, record) == false) return false;
  if (process_record_flexible_behavior_skel(&conf_cures, keycode, record) == false) return false;

  if (process_record_flexible_behavior_skel(&conf_tksw,  keycode, record) == false) return false;
  
  return true;
}
