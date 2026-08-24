#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/get_pos_from_keyrecord.h"

#include "addons/pos_tap_hold_overlay.h"


bool pre_process_record_pos_tap_hold_overlay(uint16_t keycode, keyrecord_t *record) {

    return true;
}
void housekeeping_task_pos_tap_hold_overlay(void) {

    return;
}

bool rgb_matrix_indicators_pos_tap_hold_overlay(void) {

    return true;
}