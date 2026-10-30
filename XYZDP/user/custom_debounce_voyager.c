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

//
//
// history-based time domain bit-and/or debounce logic
// base like upstream asym_eager_defer_pk waveform
// more light processing power
//
//

//
// main principle
// memory history, bit level and/or time domain
// all 1  -> and=1 or=1 (stable 1)
// all 0  -> and=0 or=0 (stable 0)
// 0,1... -> and=0 or=1 (unstable, detect this)
// none   -> and=1 or=0 (invalid, check & mask)
// 2 bit, 4 state
//

// from upstream
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

// and side
#ifndef AND_DEBOUNCE
#    define AND_DEBOUNCE DEBOUNCE
#endif

// Maximum debounce: 255ms
#if AND_DEBOUNCE > UINT8_MAX
#    undef AND_DEBOUNCE
#    define AND_DEBOUNCE UINT8_MAX
#endif

#if AND_DEBOUNCE <= 0
#    undef AND_DEBOUNCE
#    define AND_DEBOUNCE 1
#endif

// or side
#ifndef OR_DEBOUNCE
#    define OR_DEBOUNCE DEBOUNCE
#endif

// Maximum debounce: 255ms
#if OR_DEBOUNCE > UINT8_MAX
#    undef OR_DEBOUNCE
#    define OR_DEBOUNCE UINT8_MAX
#endif

#if OR_DEBOUNCE <= 0
#    undef OR_DEBOUNCE
#    define OR_DEBOUNCE 1
#endif

// buffer size
#ifndef HISTORY_SAMPLE_COUNT
#    if AND_DEBOUNCE >= OR_DEBOUNCE
#        define HISTORY_SAMPLE_COUNT (AND_DEBOUNCE+1)
#    else
#        define HISTORY_SAMPLE_COUNT (OR_DEBOUNCE+1)
#    endif
#endif

// Maximum buffer: 255
#if HISTORY_SAMPLE_COUNT > UINT8_MAX
#    undef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT UINT8_MAX
#endif

#if HISTORY_SAMPLE_COUNT <= 0
#    undef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT 1
#endif

// history data buffer
static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS];

// 2-level valid flag & expired time, global & each sample
// use last_s_idx for last value (global)
static bool and_valid[HISTORY_SAMPLE_COUNT];
static fast_timer_t and_exp_time[HISTORY_SAMPLE_COUNT];

static bool or_valid[HISTORY_SAMPLE_COUNT];
static fast_timer_t or_exp_time[HISTORY_SAMPLE_COUNT];

static uint8_t last_s_idx;
static uint8_t wr_s_idx;

// memory previus changed status and tmp data
static matrix_row_t and_tmp[MATRIX_ROWS];
static matrix_row_t or_tmp[MATRIX_ROWS];
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
            // mask apply final result only
            //const matrix_row_t tmp_row = safe_raw[r] & matrix_mask[r]; 
            const matrix_row_t tmp_row = safe_raw[r]; 

            hist_data[wr_s_idx][r] = tmp_row;

            and_tmp[r] = tmp_row;
            or_tmp[r] = tmp_row;
        }

        // flag & expire time set
        and_valid[wr_s_idx] = true;
        and_exp_time[wr_s_idx] = now + AND_DEBOUNCE;

        or_valid[wr_s_idx] = true;
        or_exp_time[wr_s_idx] = now + OR_DEBOUNCE;

        // last is last wrote index
        last_s_idx = wr_s_idx;

        // update write index
        wr_s_idx++;
        if (wr_s_idx >= HISTORY_SAMPLE_COUNT) wr_s_idx = 0;
    }

    // valid history and to tmp_and
    if (and_valid[last_s_idx]) {
        if (timer_expired_fast(now, and_exp_time[last_s_idx]) == true) {
            // expired time, all valid flag clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                and_valid[s] = false;
            }
        } else {
            // process each history sample
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global(last), loop little deep
                if (and_valid[s]) {
                    if (timer_expired_fast(now, and_exp_time[s]) == true) {
                        // expired time, flag reset
                        and_valid[s] = false;
                    } else {
                        // valid sample and to tmp
                        for (uint8_t r = 0; r < num_rows; r++) {
                            and_tmp[r] &= hist_data[s][r];
                        }
                    }
                }
            }
        }
    }

    // valid history or to tmp_or
    if (or_valid[last_s_idx]) {
        if (timer_expired_fast(now, or_exp_time[last_s_idx]) == true) {
            // expired time, all valid flag clear
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                or_valid[s] = false;
            }
        } else {
            // process each history sample
            for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
                // same as global(last), loop little deep
                if (or_valid[s]) {
                    if (timer_expired_fast(now, or_exp_time[s]) == true) {
                        // expired time, flag reset
                        or_valid[s] = false;
                    } else {
                        // valid sample or to tmp
                        for (uint8_t r = 0; r < num_rows; r++) {
                            or_tmp[r] |= hist_data[s][r];
                        }
                    }
                }
            }
        }
    }

    // change is vilid history or last cooked_changed
    // no-change nothing to do
    if(and_valid[last_s_idx] || or_valid[last_s_idx] || cooked_changed) {
        // apply cooked update
        cooked_changed = false;

        for (uint8_t r = 0; r < num_rows; r++) {
            // gen bit mask with matrix_mask
            // all 1  -> and=1 or=1 (stable 1)
            // all 0  -> and=0 or=0 (stable 0)
            // 0,1... -> and=0 or=1 (unstable, detect this)
            // none   -> and=1 or=0 (invalid, check & mask)
            const matrix_row_t unstable = (~and_tmp[r]) &   or_tmp[r]  & matrix_mask[r];
            const matrix_row_t invalid  =   and_tmp[r]  & (~or_tmp[r]) & matrix_mask[r];
            
            // not unstable, not invalid, -> stable
            const matrix_row_t stable = (~unstable) & (~invalid) & matrix_mask[r];
            
            // if diff, tmp to final value, update flag
            // xor -> diff is 1, and mask -> stable only
            // on stable, and & or is same 
            if ((cooked[r] ^ and_tmp[r]) & stable) {
                // update cooked
                cooked[r] &= unstable;            // unstable bit keep current value, stable clear
                cooked[r] |= and_tmp[r] & stable; // stable new value
                cooked_changed = true;
            }

            // re-init last value for next cycle, always last value, no-relation valid
            and_tmp[r] = hist_data[last_s_idx][r];
            or_tmp[r] = hist_data[last_s_idx][r];
        }
    }

    return cooked_changed;
}

// add const for safety
void debounce_init(const uint8_t num_rows) {
    // only reset flags
    for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
        and_valid[s] = false;
        or_valid[s] = false;
    }

    last_s_idx = 0;
    wr_s_idx = 0;
    
    // init for run transfer
    cooked_changed = true;
}

void debounce_free(void) {
    // static value only, nothing to do
}
