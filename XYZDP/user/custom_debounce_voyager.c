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

// 2-level valid flag & expired time, global & each sample
// use last_s_idx for last value
//static bool hist_valid_g = false;
//static fast_timer_t hist_exp_time_g = 0;

static bool hist_valid_s[HISTORY_SAMPLE_COUNT] = {false};
static fast_timer_t hist_exp_time_s[HISTORY_SAMPLE_COUNT] = {0};

static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS] = {0};

static uint8_t last_s_idx = 0;
static uint8_t wr_s_idx = 0;

// memory previus changed status and tmp data
static bool cooked_changed = true;
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

    if (changed) {
        // chagde
        // write history buffer & flag & tmp
        //hist_valid_g = true;
        //hist_exp_time_g = now + DEBOUNCE;

        hist_valid_s[wr_s_idx] = true;
        hist_exp_time_s[wr_s_idx] = now + DEBOUNCE;
        
        for (uint8_t r = 0; r < num_rows; r++) {
            const matrix_row_t tmp_row = raw[r] & matrix_mask[r]; 

            hist_data[wr_s_idx][r] = tmp_row;
            tmp_cooked[r] = tmp_row;
        }

        // update last & write sample index
        last_s_idx = wr_s_idx;
        wr_s_idx++;
        if (HISTORY_SAMPLE_COUNT <= wr_s_idx) wr_s_idx = 0;
    } else {
        // non change
        // if valid history or last cooked change transfer tmp
        if(hist_valid_s[last_s_idx] || cooked_changed) {
            for (uint8_t r = 0; r < num_rows; r++) {
                const matrix_row_t tmp_row = raw[r] & matrix_mask[r]; 
                
                tmp_cooked[r] = tmp_row; 
            }
        }
    }

    if (hist_valid_s[last_s_idx]) {
        if (timer_expired_fast(now, hist_exp_time_s[last_s_idx]) == true) {
            // global valid flag clear
            // hist_exp_time_g, last timestamp skip all
            //hist_valid_g = false;

            // safety all sample valid clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                hist_valid_s[s] = false;
            }
        } else {
            // sample each history
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global, loop little deep
                if (hist_valid_s[s]) {
                    if (timer_expired_fast(now, hist_exp_time_s[s]) == true) {
                        // expired time, flag reset
                        hist_valid_s[s] = false;
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

    // no history and no last change, nothing to do
    // same as if valid history or last cooked change transfer tmp
    if(hist_valid_s[last_s_idx] || cooked_changed) {
        // apply cooked update
        cooked_changed = false;

        for (uint8_t r = 0; r < num_rows; r++) {
            // safety, mask again
            tmp_cooked[r] &= matrix_mask[r];
            
            if (cooked[r] != tmp_cooked[r]) {
                cooked[r] = tmp_cooked[r];
                cooked_changed = true;
            }
        }
    }

    return cooked_changed;
}

void debounce_init(uint8_t num_rows) {
    // only reset flags
    //hist_valid_g = false;
    //hist_exp_time_g = 0;

    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        hist_valid_s[s] = false;
        //hist_exp_time_s[s] = 0;
        
        //for (uint8_t r = 0; r < num_rows; r++) {
        //    hist_data[s][r] = 0;
        //}
    }

    last_s_idx = 0;
    wr_s_idx = 0;
    
    // init for run transfer
    cooked_changed = true;
}

void debounce_free(void) {
    // static value only, nothing to do
}