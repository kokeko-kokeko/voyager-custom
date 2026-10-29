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

#if DEBOUNCE <= 0
#    undef DEBOUNCE
#    define DEBOUNCE 1
#endif

#ifndef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT (DEBOUNCE+1)
#endif

// Maximum buffer: 255
#if HISTORY_SAMPLE_COUNT > UINT8_MAX
#    undef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT UINT8_MAX
#endif

//
//
// history-based time domain bit-or debounce logic
// like upstream asym_eager_defer_pk waveform
// more light processing power
//
//

// history data buffer
static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS];

// 2-level valid flag & expired time, global & each sample
// use last_s_idx for last value
static bool hist_time_valid[HISTORY_SAMPLE_COUNT];
static fast_timer_t hist_exp_time[HISTORY_SAMPLE_COUNT];

static uint8_t last_s_idx;
static uint8_t wr_s_idx;

// memory previus changed status and tmp data
static matrix_row_t tmp_cooked[MATRIX_ROWS];
static bool cooked_changed;

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
// add const for safety for flag
bool debounce(matrix_row_t raw[], matrix_row_t cooked[], const uint8_t num_rows, const bool changed) {
    const fast_timer_t now = timer_read_fast();
    
    if (changed) {
        // raw value chagde, transfer raw to history buffer & tmp_cooked
        // must update tmp_cooked

        // safe attr safe_raw ptr for read-only use
        const matrix_row_t *const safe_raw = raw;

        // raw transfer with mask, only changed timing
        for (uint8_t r = 0; r < num_rows; r++) {
            const matrix_row_t tmp_row = safe_raw[r] & matrix_mask[r]; 

            hist_data[wr_s_idx][r] = tmp_row;
            tmp_cooked[r] = tmp_row;
        }

        // flag & expire time set
        hist_time_valid[wr_s_idx] = true;
        hist_exp_time[wr_s_idx] = now + DEBOUNCE;

        // last is last wrote index
        last_s_idx = wr_s_idx;

        // update write index
        wr_s_idx++;
        if (wr_s_idx >= HISTORY_SAMPLE_COUNT) wr_s_idx = 0;
    }

    // history or to tmp_cooked
    if (hist_time_valid[last_s_idx]) {
        if (timer_expired_fast(now, hist_exp_time[last_s_idx]) == true) {
            // expired time, all valid flag clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                hist_time_valid[s] = false;
            }
        } else {
            // process each history sample
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global(last), loop little deep
                if (hist_time_valid[s]) {
                    if (timer_expired_fast(now, hist_exp_time[s]) == true) {
                        // expired time, flag reset
                        hist_time_valid[s] = false;
                    } else {
                        // valid sample or to tmp
                        for (uint8_t r = 0; r < num_rows; r++) {
                            tmp_cooked[r] |= hist_data[s][r];
                        }
                    }
                }
            }
        }
    }

    // change is vilid history or last cooked_changed
    // no-change nothing to do
    if(hist_time_valid[last_s_idx] || cooked_changed) {
        // apply cooked update
        cooked_changed = false;

        for (uint8_t r = 0; r < num_rows; r++) {
            // safety, mask again
            tmp_cooked[r] &= matrix_mask[r];
            
            // if diff, tmp to final value, update flag
            if (cooked[r] != tmp_cooked[r]) {
                // update cooked
                cooked[r] = tmp_cooked[r];
                cooked_changed = true;
            }

            // re-init last value for next cycle, always last value, no-relation time valid
            tmp_cooked[r] = hist_data[last_s_idx][r];
        }
    }

    return cooked_changed;
}

// add const for safety
void debounce_init(const uint8_t num_rows) {
    // only reset flags
    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        hist_time_valid[s] = false;
    }

    last_s_idx = 0;
    wr_s_idx = 0;
    
    // init for run transfer
    cooked_changed = true;
}

void debounce_free(void) {
    // static value only, nothing to do
}
