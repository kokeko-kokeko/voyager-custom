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
// history-based time domain bit-and/or debounce logic
// base like upstream asym_eager_defer_pk waveform
// more light processing power
//
//

// main principle
// memory history, bit level and/or time domain
// all 1  -> and=1 or=1
// all 0  -> and=0 or=0
// 0,1... -> and=0 or=1 (unstable, detect this)
//        -> and=1 or=0 (invalid, check system)
// 2 bit, 4 state
//

// history data buffer
static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS];

// 2-level valid flag & expired time, global & each sample
// use last_s_idx for last value
static bool hist_time_valid_and[HISTORY_SAMPLE_COUNT];
static fast_timer_t hist_exp_time_and[HISTORY_SAMPLE_COUNT];

static bool hist_time_valid_or[HISTORY_SAMPLE_COUNT];
static fast_timer_t hist_exp_time_or[HISTORY_SAMPLE_COUNT];

static uint8_t last_s_idx;
static uint8_t wr_s_idx;

// memory previus changed status and tmp data
static matrix_row_t tmp_cooked_and[MATRIX_ROWS];
static matrix_row_t tmp_cooked_or[MATRIX_ROWS];
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
        // raw value chagde, transfer raw to history buffer & tmp_cooked_or
        // must update tmp_cooked_or

        // safe attr safe_raw ptr for read-only use
        const matrix_row_t *const safe_raw = raw;

        // raw transfer with mask, only changed timing
        for (uint8_t r = 0; r < num_rows; r++) {
            const matrix_row_t tmp_row = safe_raw[r] & matrix_mask[r]; 

            hist_data[wr_s_idx][r] = tmp_row;

            tmp_cooked_and[r] = tmp_row;
            tmp_cooked_or[r] = tmp_row;
        }

        // flag & expire time set
        hist_time_valid_and[wr_s_idx] = true;
        hist_exp_time_and[wr_s_idx] = now + DEBOUNCE;

        hist_time_valid_or[wr_s_idx] = true;
        hist_exp_time_or[wr_s_idx] = now + DEBOUNCE;

        // last is last wrote index
        last_s_idx = wr_s_idx;

        // update write index
        wr_s_idx++;
        if (wr_s_idx >= HISTORY_SAMPLE_COUNT) wr_s_idx = 0;
    }

    // valid history and to tmp_cooked_and
    if (hist_time_valid_and[last_s_idx]) {
        if (timer_expired_fast(now, hist_exp_time_and[last_s_idx]) == true) {
            // expired time, all valid flag clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                hist_time_valid_and[s] = false;
            }
        } else {
            // process each history sample
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global(last), loop little deep
                if (hist_time_valid_and[s]) {
                    if (timer_expired_fast(now, hist_exp_time_and[s]) == true) {
                        // expired time, flag reset
                        hist_time_valid_and[s] = false;
                    } else {
                        // valid sample and to tmp
                        for (uint8_t r = 0; r < num_rows; r++) {
                            tmp_cooked_and[r] &= hist_data[s][r];
                        }
                    }
                }
            }
        }
    }

    // valid history or to tmp_cooked_or
    if (hist_time_valid_or[last_s_idx]) {
        if (timer_expired_fast(now, hist_exp_time_or[last_s_idx]) == true) {
            // expired time, all valid flag clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                hist_time_valid_or[s] = false;
            }
        } else {
            // process each history sample
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global(last), loop little deep
                if (hist_time_valid_or[s]) {
                    if (timer_expired_fast(now, hist_exp_time_or[s]) == true) {
                        // expired time, flag reset
                        hist_time_valid_or[s] = false;
                    } else {
                        // valid sample or to tmp
                        for (uint8_t r = 0; r < num_rows; r++) {
                            tmp_cooked_or[r] |= hist_data[s][r];
                        }
                    }
                }
            }
        }
    }

    // change is vilid history or last cooked_changed
    // no-change nothing to do
    if(hist_time_valid_and[last_s_idx] || hist_time_valid_or[last_s_idx] || cooked_changed) {
        // apply cooked update
        cooked_changed = false;

        for (uint8_t r = 0; r < num_rows; r++) {
            // safety, mask again
            //tmp_cooked_and[r] &= matrix_mask[r];
            //tmp_cooked_or[r] &= matrix_mask[r];

            // 0,1... -> and=0 or=1 (unstable, detect this)
            matrix_row_t unstable = ~tmp_cooked_and[r] & tmp_cooked_or[r] & matrix_mask[r];
            matrix_row_t stable = ~unstable & matrix_mask[r];
            
            // if diff, tmp to final value, update flag
            // xor -> diff is 1, and mask -> stable only
            if ((cooked[r] ^ tmp_cooked_or[r]) & stable) {
                // update cooked
                cooked[r] &= unstable;                  // unstable bit keep current value
                cooked[r] |= tmp_cooked_or[r] & stable; // stable new value
                cooked_changed = true;
            }

            // re-init last value for next cycle, always last value, no-relation time valid
            tmp_cooked_and[r] = hist_data[last_s_idx][r];
            tmp_cooked_or[r] = hist_data[last_s_idx][r];
        }
    }

    return cooked_changed;
}

// add const for safety
void debounce_init(const uint8_t num_rows) {
    // only reset flags
    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        hist_time_valid_and[s] = false;
        hist_time_valid_or[s] = false;
    }

    last_s_idx = 0;
    wr_s_idx = 0;
    
    // init for run transfer
    cooked_changed = true;
}

void debounce_free(void) {
    // static value only, nothing to do
}
