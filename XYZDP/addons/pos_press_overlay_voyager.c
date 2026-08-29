#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "get_pos_from_keyrecord.h"

#include "addons/pos_press_overlay.h"

#define POSITION_COUNT 52

#define HOLD_INIT_TIME 1009
#define HOLD_REPEAT_TIME 337
#define INV_THROTTLE_TIME 31

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

static fast_timer_t pos_inv_throttle_trigger = 0;

bool pre_process_record_pos_press_overlay(uint16_t keycode, keyrecord_t *record) {
    // record tap or hold
    const fast_timer_t now = timer_read_fast();
    const uint8_t pos = get_pos_from_keyrecord(record);

    // common on tap & hold
    if (record->event.pressed) {
        pos_pressed[pos] = true;
        pos_inv_trigger[pos] = now + HOLD_INIT_TIME;
    } else {
        pos_pressed[pos] = false;
        pos_inv_trigger[pos] = now + (UINT32_MAX / 2) - 1;
    }

    return true;
}
void housekeeping_task_pos_press_overlay(void) {
    // invert press
    const fast_timer_t now = timer_read_fast();

    if (timer_expired_fast(now, pos_inv_throttle_trigger) == false) return;
    pos_inv_throttle_trigger += INV_THROTTLE_TIME;

    for (uint8_t pos = 0; pos < POSITION_COUNT; pos++) {
        if (timer_expired_fast(now, pos_inv_trigger[pos]) == false) continue;
        
        pos_inv_trigger[pos] += HOLD_REPEAT_TIME;
        pos_pressed[pos] = !(pos_pressed[pos]);
    }

    return;
}

bool rgb_matrix_indicators_pos_press_overlay(void) {
    for (uint8_t pos = 0; pos < POSITION_COUNT; pos++) {
        if (pos_pressed[pos]) rgb_matrix_set_color(pos, 0, 0, 0);
    }

    return true;
}