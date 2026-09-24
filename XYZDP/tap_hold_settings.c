#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/flexible_behavior_os_locale.h"

// per-key tapping parameter setting
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  // direct add to here (split func in more complicate)

  // PFON : Pos Func ONly, dummy in A -> no wait
  // only use with KC_A
  if (keycode == PFON(KC_A)) return 0;

  // MCFW : MaCro FirmWare
  // Macro
  if (keycode == MCFW(KC_M)) return 0;

  // Firmware main
  if (keycode == MCFW(KC_F)) return 0;

  // Color Palette main
  if (keycode == MCFW(KC_C)) return 0;

  // Halt (motre margin)
  if (keycode == MCFW(KC_H)) return 997;

  return TAPPING_TERM;
}

// flow tap target key
bool is_flow_tap_key(uint16_t keycode) {
  if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
    return false; // Disable Flow Tap on hotkeys.
  }
  switch (get_tap_keycode(keycode)) {
    case KC_SPC:
    case KC_A ... KC_Z:
    case KC_DOT:
    case KC_COMM:
    case KC_SCLN:
    case KC_SLSH:
      return true;
  }
  return false;
}

// tap flow control
// bool is_flow_tap_key(uint16_t keycode) is default
// disable (return 0)
// thumb space LT 
// cursor LT
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (keycode) {
			case PTMH(KC_SPACE):
			
			case PTMH(KC_B):
			case PTMH(KC_V):
		
			case ENSN(KC_L): 
			case ENSN(KC_R):
		
			case PTMH(KC_F11):
			case PTMH(KC_F12):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  
  return 0;  // Disable Flow Tap.
}
