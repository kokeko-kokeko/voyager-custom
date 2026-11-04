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

// main principle
// memory history, bit level and/or time domain
// all 1  -> and=1 or=1 (stable 1)
// all 0  -> and=0 or=0 (stable 0)
// 0,1... -> and=0 or=1 (unstable, detect this)
// init   -> and=1 or=0 (init invalid, no another check & mask)
// 2 bit, 4 state
//

// 
// acc non-hit history detect
// and=1 or=0 on buffer init, some value apply change another
//
// idea gen init value from matrix_mask
// matrix_mask is 1 -> vanid cross point, 0 -> unused
// and_acc init value matrix_mask 
// or_acc init value not matrix_mask
// 1 to init invalid (can change to another state)
// 0 to unstable (can not change)
//

//
// event base thinking
// 0->1 (key press) or part 1 output immediately, and part stop chattering after HISTORY_AND_DEBOUNCE output 1, both 1 report 1 to after process
// 1->0 (key release) and part 0 output immediately, or part stop chattering after HISTORY_OR_DEBOUNCE output 0, both 0 report 0 to after process
// HISTORY_AND_DEBOUNCE -> rise (press) margin
// HISTORY_OR_DEBOUNCE -> fall (release) margin
//

// and acc pre-check update
// acc 1 and data 1 -> 1 no acc change
// acc 1 and data 0 -> 0 acc change (only pass here)
// acc 0 and data 1 -> 0 no acc change
// acc 0 and data 0 -> 0 no acc change

// acc 1 and data 0 -> 0 acc change (only pass here)
// const matrix_row_t and_req_update = and_acc[r] & (~hist_data[s][r]);

// or acc pre-check update
// acc 1 or data 1 -> 1 no acc change
// acc 1 or data 0 -> 1 no acc change
// acc 0 or data 1 -> 1 acc change (only pass here)
// acc 0 or data 0 -> 0 no acc change

// acc 0 or data 1 -> 1 acc change (only pass here)
// const matrix_row_t or_req_update = (~or_acc[r]) & hist_data[s][r];


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
#ifndef HISTORY_AND_DEBOUNCE
#    define HISTORY_AND_DEBOUNCE DEBOUNCE
#endif

// Maximum debounce: 255ms
#if HISTORY_AND_DEBOUNCE > UINT8_MAX
#    undef HISTORY_AND_DEBOUNCE
#    define HISTORY_AND_DEBOUNCE UINT8_MAX
#endif

#if HISTORY_AND_DEBOUNCE < 1
#    undef HISTORY_AND_DEBOUNCE
#    define HISTORY_AND_DEBOUNCE 1
#endif

// or side
#ifndef HISTORY_OR_DEBOUNCE
#    define HISTORY_OR_DEBOUNCE DEBOUNCE
#endif

// Maximum debounce: 255ms
#if HISTORY_OR_DEBOUNCE > UINT8_MAX
#    undef HISTORY_OR_DEBOUNCE
#    define HISTORY_OR_DEBOUNCE UINT8_MAX
#endif

#if HISTORY_OR_DEBOUNCE < 1
#    undef HISTORY_OR_DEBOUNCE
#    define HISTORY_OR_DEBOUNCE 1
#endif

// buffer size
#ifndef HISTORY_SAMPLE_COUNT
#    if HISTORY_AND_DEBOUNCE >= HISTORY_OR_DEBOUNCE
#        define HISTORY_SAMPLE_COUNT (HISTORY_AND_DEBOUNCE+1)
#    else
#        define HISTORY_SAMPLE_COUNT (HISTORY_OR_DEBOUNCE+1)
#    endif
#endif

// Maximum buffer: 255
#if HISTORY_SAMPLE_COUNT > UINT8_MAX
#    undef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT UINT8_MAX
#endif

// minimal 2 value for debounce
#if HISTORY_SAMPLE_COUNT < 2
#    undef HISTORY_SAMPLE_COUNT
#    define HISTORY_SAMPLE_COUNT 2
#endif

// history data & time buffer
static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS];
static fast_timer_t hist_time[HISTORY_SAMPLE_COUNT];

// data accumulator, 1 sample size
static matrix_row_t and_acc[MATRIX_ROWS];
static matrix_row_t or_acc[MATRIX_ROWS];

// last & write sample index 
// raw has evry time valid data, non last req
static uint8_t last_s_idx;
static uint8_t wr_s_idx;

// single valid flag, same as cooked_changed style
// reset on loop head, set at condition hit
static bool and_valid;
static bool or_valid;

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
    const size_t matrix_size = num_rows * sizeof(matrix_row_t);

    if (changed) {
        // raw transfer to history, only changed timing, use memcpy than upstream
        // only touch raw here, other pos uce hist_data
        memcpy(hist_data[wr_s_idx], raw, matrix_size);

        // time update after, outside of if (changed)

        // update last & write index for next
        last_s_idx = wr_s_idx;
        wr_s_idx++;
        if (wr_s_idx >= HISTORY_SAMPLE_COUNT) wr_s_idx = 0;

        // updated (change) last data to _acc
        // next cycle, re-init set this with mask
        for (uint8_t r = 0; r < num_rows; r++) {
            // acc 1 and data 0 -> 0 acc change (only pass here)
            const matrix_row_t and_req_update = and_acc[r] & (~hist_data[last_s_idx][r]);

            if (and_req_update) {
                and_acc[r] &= hist_data[last_s_idx][r];
            }

            const matrix_row_t or_req_update = (~or_acc[r]) & hist_data[last_s_idx][r];

            if (or_req_update) {
                or_acc[r] |= hist_data[last_s_idx][r];
            }
        }

        // all flag set for re-run all check this cycle
        and_valid = true;
        or_valid = true;
    }

    // every cycle update last sample time to current
    // if new data come, min 2 sample
    hist_time[last_s_idx] = now;

    // valid history and to and_acc
    if (and_valid) {
        // flag reset, if find valid sample set in loop, without last
        and_valid = false;

        // expire time (minus offset from now) calc ahead 
        const fast_timer_t exp_time = now - HISTORY_AND_DEBOUNCE;

        // process each history sample
        for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
            // skip last, only last valid false
            if (s == last_s_idx) continue;

            if (timer_expired_fast(exp_time, hist_time[s]) == false) {
                // not expired, valid sample and to tmp
                for (uint8_t r = 0; r < num_rows; r++) {
                    // acc 1 and data 0 -> 0 acc change (only pass here)
                    const matrix_row_t and_req_update = and_acc[r] & (~hist_data[s][r]);

                    if (and_req_update) {
                        and_acc[r] &= hist_data[s][r];
                    }
                }

                and_valid = true;
            }
        }
    }

    // valid history or to or_acc
    if (or_valid) {
        // flag reset, if find valid sample set in loop, without last
        or_valid = false;

        // expire time (minus offset from now) calc ahead 
        const fast_timer_t exp_time = now - HISTORY_OR_DEBOUNCE;

        // process each history sample
        for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
            // skip last, only last valid false
            if (s == last_s_idx) continue;

            if (timer_expired_fast(exp_time, hist_time[s]) == false) {
                // not expired, valid sample or to tmp
                for (uint8_t r = 0; r < num_rows; r++) {
                    // acc 0 or data 1 -> 1 acc change (only pass here)
                    const matrix_row_t or_req_update = (~or_acc[r]) & hist_data[s][r];

                    if (or_req_update) {
                        or_acc[r] |= hist_data[s][r];
                    }
                }

                or_valid = true;
            }
        }
    }

    // apply cooked update, must run every cycle
    bool cooked_changed = false;

    for (uint8_t r = 0; r < num_rows; r++) {
        // gen bit mask with matrix_mask
        // all 1  -> and=1 or=1 (stable 1)
        // all 0  -> and=0 or=0 (stable 0)
        // 0,1... -> and=0 or=1 (unstable, detect this)
        // none   -> and=1 or=0 (init invalid, check & mask)
        // new_data use stable 1, more safety
        const matrix_row_t new_data      =   and_acc[r]  &   or_acc[r]  & matrix_mask[r];
        const matrix_row_t unstable_mask = (~and_acc[r]) &   or_acc[r]  & matrix_mask[r];
        const matrix_row_t init_inv_mask =   and_acc[r]  & (~or_acc[r]) & matrix_mask[r];
        
        // not unstable, not invalid, -> stable
        const matrix_row_t stable_mask = (~unstable_mask) & (~init_inv_mask) & matrix_mask[r];
        //const matrix_row_t stable_mask = (~(and_acc[r] ^ or_acc[r])) & matrix_mask[r];

        // if diff, tmp to final value, update flag
        // xor -> diff is 1, and mask -> stable only
        const matrix_row_t req_update = (cooked[r] ^ new_data) & stable_mask;
        
        if (req_update) {
            // update cooked
            cooked[r] &= (~stable_mask);            // not stable bit keep current value, stable clear
            cooked[r] |= new_data & stable_mask;    // stable new data

            cooked_changed = true;
        }

        // must re-init last sample with mask data, simple is best
        and_acc[r] = hist_data[last_s_idx][r] &   matrix_mask[r];
        or_acc[r]  = hist_data[last_s_idx][r] | (~matrix_mask[r]);
    }

    return cooked_changed;
}

// add const for safety
void debounce_init(const uint8_t num_rows) {
    // init for invalid value
    for (uint8_t r = 0; r < num_rows; r++) {
        and_acc[r] =   matrix_mask[r];
        or_acc[r]  = (~matrix_mask[r]);
    }

    last_s_idx = 0;
    wr_s_idx = 0;

    // only reset flags
    and_valid = false;
    or_valid = false;
}

void debounce_free(void) {
    // static value only, nothing to do
}
