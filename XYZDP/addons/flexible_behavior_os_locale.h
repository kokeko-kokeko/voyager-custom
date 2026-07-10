#pragma once

// use MT with 1 or 2 mod, must mod override hold side
// HOOR : Hold Only OverRide, tap pass to normal process
// MCFW : MaCro FirmWare
// THORn : Tap Hold OverRide, both override, shift and land handle
// THORnS : Tap Hold OverRide, both override, fix shift
// TKSW : TasK SWitch OverRide, handle RALT 

#define MOD_HOOR (MOD_LCTL)

#define MOD_MCFW (MOD_LCTL | MOD_LSFT)

#define MOD_THOR1 (MOD_RCTL)
#define MOD_THOR1S (MOD_RCTL | MOD_RSFT)

#define MOD_THOR2 (MOD_LALT)
#define MOD_THOR2S (MOD_LALT | MOD_LSFT)

#define MOD_TKSW (MOD_RALT)

//#define MT(mod, kc) (QK_MOD_TAP | (((mod)&0x1F) << 8) | ((kc)&0xFF))
#define HOOR(kc) MT(MOD_HOOR, kc)

#define MCFW(kc) MT(MOD_MCFW, kc)

#define THOR1(kc) MT(MOD_THOR1, kc)
#define THOR1S(kc) MT(MOD_THOR1S, kc)

#define THOR2(kc) MT(MOD_THOR2, kc)
#define THOR2S(kc) MT(MOD_THOR2S, kc)

#define TKSW(kc) MT(MOD_TKSW, kc)

void jis_enable(void);
void jis_disable(void);
bool jis_is_enabled(void);

void mac_enable(void);
void mac_disable(void);
bool mac_is_enabled(void);

bool process_detected_host_os_flexible_behavior_os_locale(os_variant_t detected_os);
bool process_record_flexible_behavior_os_locale(uint16_t keycode, keyrecord_t *record);

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
  FB_PASS_QMK,              // pass to qmk, terminate process here return true, data not use
  FB_KEYCODE,               // keycode, data8 is option 8bit mods mask, data16 is keycode
  FB_KEYCODE_TAP,           // keycode tap, data8 is option 8bit mods mask, data16 is keycode
  FB_KEYCODE_TAP_KEEP_MODS, // keycode tap keep mod, data8 is keep 8bit mods mask, data16 is keycode (for taskswitch)
  FB_MODS,                  // only mods key, data8 is 8bit mods mask
  FB_LAYER,                 // activate layer, data8 is layer number
  FB_CAPS_WORD,             // caps word, data not use
  FB_SWAP_HANDS,            // swap hands, data not use
  FB_NOP_ERROR              // nop with error report (use on non-reach default valueS) 
};

typedef struct flexible_behavior {
  uint8_t op_id;
  uint8_t data8;
  uint16_t data16;
} flexible_behavior_t;

