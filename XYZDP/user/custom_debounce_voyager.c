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

#define SAMPLE_COUNT 8

static matrix_row_t hist_data_buf[SAMPLE_COUNT][MATRIX_ROWS] = {0};
static fast_timer_t hist_exp_time[SAMPLE_COUNT] = {0};
static bool hist_valid[SAMPLE_COUNT] = {false};

static uint8_t wr_smp = 0;

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

    // chagde, write history buffer
    if (changed) {
        for (uint8_t r = 0; r < num_rows; r++) {
            // value to history buffer
            hist_data_buf[wr_smp][r] = raw[r] & matrix_mask[r];
        }
        hist_exp_time[wr_smp] = now + DEBOUNCE;
        hist_valid[wr_smp] = true;

        // update write sample intex
        wr_smp++;
        if (SAMPLE_COUNT <= wr_smp) wr_smp = 0;
    }

    // init tmp current value
    for (uint8_t r = 0; r < num_rows; r++) {
        // safety, mask again
        tmp_cooked[r] = raw[r] & matrix_mask[r];
    }
    
    // sample or valid history
    for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
        // non valid sample skip
        if (hist_valid[s] == false) continue;

        // expired time, flag reset & skip
        if (timer_expired_fast(now, hist_exp_time[s]) == true) {
            hist_valid[s] = false; 
            continue;
        }
        
        // or sample
        for (uint8_t r = 0; r < num_rows; r++) {
            tmp_cooked[r] |= hist_data_buf[s][r];  
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
    for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
        for (uint8_t r = 0; r < num_rows; r++) {
            hist_data_buf[s][r] = 0;
        }
        hist_exp_time[s] = 0;
        hist_valid[s] = false;
    }
    wr_smp = 0;
}

void debounce_free(void) {
    // static value only, nothing to do
}