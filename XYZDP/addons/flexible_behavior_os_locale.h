#pragma once

// use MT with 1 or 2 mod, must mod override hold side
// PTMH : Pass Tap, Mod Hold
// MCFW : MaCro FirmWare
// ENSN : ENgram Symbol Number
// ENSNS : ENgram Symbol Number Shifted
// CURE : CURsor and Etc
// CURES : CURsor and Etc Shifted
// TKSW : TasK SWitch OverRide, handle RALT 

// old name
// HOOR : Hold Only OverRide, tap pass to normal process
// THORn : Tap Hold OverRide, both override, shift and lang handle
// THORnS : Tap Hold OverRide, both override, fix shift


#define MOD_PTMH (MOD_LCTL)

#define MOD_MCFW (MOD_LCTL | MOD_LSFT)

#define MOD_ENSN (MOD_RCTL)
#define MOD_ENSNS (MOD_RCTL | MOD_RSFT)

#define MOD_CURE (MOD_LALT)
#define MOD_CURES (MOD_LALT | MOD_LSFT)

#define MOD_TKSW (MOD_RALT)

//#define MT(mod, kc) (QK_MOD_TAP | (((mod)&0x1F) << 8) | ((kc)&0xFF))
#define PTMH(kc) MT(MOD_PTMH, kc)

#define MCFW(kc) MT(MOD_MCFW, kc)

#define ENSN(kc) MT(MOD_ENSN, kc)
#define ENSNS(kc) MT(MOD_ENSNS, kc)

#define CURE(kc) MT(MOD_CURE, kc)
#define CURES(kc) MT(MOD_CURES, kc)

#define TKSW(kc) MT(MOD_TKSW, kc)

void jis_enable(void);
void jis_disable(void);
bool jis_is_enabled(void);

void mac_enable(void);
void mac_disable(void);
bool mac_is_enabled(void);

void flexible_behavior_clear_error(void);
bool flexible_behavior_has_error(void);

bool process_detected_host_os_flexible_behavior_os_locale(os_variant_t detected_os);
bool process_record_flexible_behavior_os_locale(uint16_t keycode, keyrecord_t *record);

// flexible tap hold behavior
// calc tap-hold by qmk MT(XXX) keycode
// following sequence
// 1. split tap or hold first, each independest chain
// 2. get action from eager base keycode func (QK_MOD_TAP_GET_TAP_KEYCODE), if nop next step
// 3. get action from position func and exec, if nop next step
// 4. get action from defer base keycode func (QK_MOD_TAP_GET_TAP_KEYCODE), if nop next step
// 5. send base keycode
//
// make universal function and make conf struct to args 

enum flexible_behavior_operation_identifier {
  FB_NOP = 0,               // nop command, pass next step, data not use
  FB_PASS_QMK,              // pass to qmk, terminate process here return true, data not use
  FB_SEND_TAP_KEYCODE,      // send tap keycode without mod, data not use
  FB_KEYCODE,               // keycode, data_u8 is option 8bit mods mask, data_u16 is 16bit keycode
  FB_KEYCODE_TAP,           // keycode tap, data_u8 is option 8bit mods mask, data_u16 is 16bit keycode
  FB_KEYCODE_TAP_KEEP_MODS, // keycode tap with keep mod, data_u8 is keep 8bit mods mask, data_u16 is 16bit keycode (base for taskswitch)
  FB_MODS,                  // only mods key, data_u8 is 8bit mods mask
  FB_LAYER,                 // activate layer, data_u8 is layer number
  FB_CAPS_WORD,             // caps word, data not use
  FB_SWAP_HANDS,            // swap hands, data not use
  FB_EXIT,                  // terminate here 
  FB_ERROR_EXIT             // terminate here, with error flag report (use on non-reach default value) 
};

typedef struct flexible_behavior {
  const uint8_t op_id;
  uint8_t data_u8;
  uint16_t data_u16;
} flexible_behavior_t;

