#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// module safe-guard
#ifndef KEYBOARD_zsa_voyager
#    error "this file contains ZSA Voyager only magic number constants"
#endif

#include "debounce.h"
#include "timer.h"
#include <stdlib.h>

#ifndef DEBOUNCE
#    define DEBOUNCE 5
#endif

// Maximum debounce: 255ms
#if DEBOUNCE > UINT8_MAX
#    undef DEBOUNCE
#    define DEBOUNCE UINT8_MAX
#endif

#define HISTORY_SAMPLE_COUNT 8

static bool hist_valid[HISTORY_SAMPLE_COUNT] = {false};
static fast_timer_t hist_exp_time[HISTORY_SAMPLE_COUNT] = {0};

static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS] = {0};

static uint8_t wr_s_idx = 0;

static matrix_row_t tmp_cooked[MATRIX_ROWS] = {0};

// mask for unused cross-point, for voyager only
static const matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b01111110,
    0b01111110,
    0b01111110,
    0b00111110,
    0b00010000,
    0b00000011,

    0b00111111,
    0b00111111,
    0b00111111,
    0b00111110,
    0b00000100,
    0b01100000
};

// raw and cooked pass from caller, keep value, not local memory
// raw is must read-only, not write
// cooked is result
bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    const fast_timer_t now = timer_read_fast();

    // chagde, write history buffer & flag
    if (changed) {
        hist_valid[wr_s_idx] = true;
        hist_exp_time[wr_s_idx] = now + DEBOUNCE;

        for (uint8_t r = 0; r < num_rows; r++) {
            hist_data[wr_s_idx][r] = raw[r] & matrix_mask[r];
        }

        // update write sample index
        wr_s_idx++;
        if (HISTORY_SAMPLE_COUNT <= wr_s_idx) wr_s_idx = 0;
    }

    // init tmp current value
    for (uint8_t r = 0; r < num_rows; r++) {
        // safety, mask again
        tmp_cooked[r] = raw[r] & matrix_mask[r];
    }
    
    // sample or valid history
    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        // non valid sample skip
        if (hist_valid[s] == false) continue;

        // expired time, flag reset & skip
        if (timer_expired_fast(now, hist_exp_time[s]) == true) {
            hist_valid[s] = false; 
            continue;
        }
        
        // valid or sample
        for (uint8_t r = 0; r < num_rows; r++) {
            tmp_cooked[r] |= hist_data[s][r];  
        }
    }

    // apply cooked update
    bool cooked_changed = false;

    for (uint8_t r = 0; r < num_rows; r++) {
        // safety, mask again
        tmp_cooked[r] &= matrix_mask[r];

        if (cooked[r] != tmp_cooked[r]) {
            cooked[r] = tmp_cooked[r];
            cooked_changed = true;
        }
    }

    return cooked_changed;
}

void debounce_init(uint8_t num_rows) {
    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        hist_valid[s] = false;
        hist_exp_time[s] = 0;
        
        for (uint8_t r = 0; r < num_rows; r++) {
            hist_data[s][r] = 0;
        }
    }
    wr_s_idx = 0;
}

void debounce_free(void) {
    // static value only, nothing to do
}