#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/get_pos_from_keyrecord.h"

#include "addons/pos_tap_hold_overlay.h"

#define POSITION_COUNT 52

#define HOLD_INIT_TIME 1009
#define HOLD_REPEAT_TIME 337

static bool pos_pressed[POSITION_COUNT] = {
    false, false, false, false, false, false,
    false, false, false, false, false, false, 
    false, false, false, false, false, false, 
    false, false, false, false, false, false, 
    false, false,
    false, false, false, false, false, false, 
    false, false, false, false, false, false, 
    false, false, false, false, false, false, 
    false, false, false, false, false, false, 
    false, false
};

static fast_timer_t pos_inv_trigger[POSITION_COUNT] = {
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1,
    (UINT32_MAX / 2) - 1, (UINT32_MAX / 2) - 1
};

bool pre_process_record_pos_tap_hold_overlay(uint16_t keycode, keyrecord_t *record) {
    // record tap or hold
    const fast_timer_t now = timer_read_fast();
    const uint8_t pos = get_pos_from_keyrecord(record);

    // MT template
    if (record->tap.count > 0) {
        // tep
        if (record->event.pressed) {
            pos_pressed[pos] = true;
            pos_inv_trigger[pos] = now + (UINT32_MAX / 2) - 1;
        } else {
            pos_pressed[pos] = false;
            pos_inv_trigger[pos] = now + (UINT32_MAX / 2) - 1;
        }
    } else {
        // hold
        if (record->event.pressed) {
            pos_pressed[pos] = true;
            pos_inv_trigger[pos] = now + HOLD_INIT_TIME;
        } else {
            pos_pressed[pos] = false;
            pos_inv_trigger[pos] = now + (UINT32_MAX / 2) - 1;
        }  
    }

    return true;
}
void housekeeping_task_pos_tap_hold_overlay(void) {
    // invert press
    const fast_timer_t now = timer_read_fast();

    for (uint8_t i = 0; i < POSITION_COUNT; i++) {
        if (timer_expired_fast(now, pos_inv_trigger[i]) == false) continue;
        pos_inv_trigger[i] += HOLD_REPEAT_TIME;
        pos_pressed[i] = !pos_pressed[i];
    }

    return;
}

bool rgb_matrix_indicators_pos_tap_hold_overlay(void) {
    for (uint8_t i = 0; i < POSITION_COUNT; i++) {
        if (pos_pressed[i]) rgb_matrix_set_color(i, 0, 0, 0);
    }

    return true;
}