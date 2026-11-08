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

// pre calc both/single condition (only automatic calc, override clear)
// clear all flags
#undef HAS_SINGLE
#undef SINGLE_IS_AND    // not def, single is or
#undef SHORT_DEBOUNCE   // only def when HAS_SINGLE 
#undef LONG_DEBOUNCE    // always def

// 
// (now - long) --- single --- (now - short) --- both --- (now) -> adv
// ---- time0 | time1 -------------- time1 ! time2 ---------
// valid
//      false | true
//                                   false | true
// expired
//       true | false
//                                    true | false
//
// time0 = invalid, no action                                     
// time1 = single
// time2 = both
// short is near, long is far, timeout short first
//
// valid
// long  short convolution
// true  true  both    (time2)
// true  false single  (time1)
// false ---   invalid (time0)
//
// expired
// long  short convolution
// true  ---   invalid (time0), nothing to do
// false true  single  (time1)
// false false both    (time2)
//
// both = < short 
// single = short < long
#if HISTORY_AND_DEBOUNCE == HISTORY_OR_DEBOUNCE
#   define LONG_DEBOUNCE HISTORY_AND_DEBOUNCE
#elif HISTORY_AND_DEBOUNCE > HISTORY_OR_DEBOUNCE
#   define HAS_SINGLE
#   define SINGLE_IS_AND
#   define SHORT_DEBOUNCE HISTORY_OR_DEBOUNCE
#   define LONG_DEBOUNCE HISTORY_AND_DEBOUNCE
#else
#   define HAS_SINGLE
#   define SHORT_DEBOUNCE HISTORY_AND_DEBOUNCE
#   define LONG_DEBOUNCE HISTORY_OR_DEBOUNCE
#endif

// buffer size (only automatic calc, override clear)
// clear all flags
#undef HISTORY_SAMPLE_COUNT
#define HISTORY_SAMPLE_COUNT (LONG_DEBOUNCE+1) 

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

// history data & time buffer (time is data last or leave time for calc)
static matrix_row_t hist_data[HISTORY_SAMPLE_COUNT][MATRIX_ROWS];
static fast_timer_t hist_time[HISTORY_SAMPLE_COUNT];

// data accumulator, 1 sample size
static matrix_row_t and_acc[MATRIX_ROWS];
static matrix_row_t or_acc[MATRIX_ROWS];

// convolution sample list pre-alloc buffer memory with margin
static uint8_t convolution_s_both_buf[HISTORY_SAMPLE_COUNT+1]; 

#ifdef HAS_SINGLE
static uint8_t convolution_s_single_buf[HISTORY_SAMPLE_COUNT+1]; 
#endif

// last & write sample index
// last data is re-init, last time update every cycle
static uint8_t last_s_idx;
static uint8_t wr_s_idx;

// single history convolution flag, same as cooked_changed style
// reset on loop head, set again at condition hit
static bool do_convolution;

// momery last state for gen extra margin cycle
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

// debug to LED macro
#define DEBUG_LED_1(status) gpio_write_pin(B5, (bool)(status))
#define DEBUG_LED_2(status) gpio_write_pin(B4, (bool)(status))

// raw and cooked pass from caller, keep value, not local memory
// raw is must read-only, not write
// cooked is result
// add const for safety for flag
bool debounce(matrix_row_t raw[], matrix_row_t cooked[], const uint8_t num_rows, const bool changed) {
    const fast_timer_t now = timer_read_fast();

    if (changed) {
        // last time final decide here, 
        // when last data not use time, leave time here
        // equal continus update 1 cycle before
        hist_time[last_s_idx] = now - 1;

        // write max old value, convolution must skip, re-init value set
        // initial last_s_idx == wr_s_idx, works well
        hist_time[wr_s_idx] = now - UINT8_MAX - 1;        

        // raw transfer to history, only changed timing, use memcpy than upstream
        // only touch raw here, other pos uce hist_data
        const size_t matrix_size = num_rows * sizeof(matrix_row_t);
        uint8_t * const wr_dest = hist_data[wr_s_idx];

        memcpy(wr_dest, raw, matrix_size);

        // after update (write) new data to _acc
        // next cycle, re-init (last_s_idx) set this data with mask

        const uint8_t * const rd_src = wr_dest;

        for (uint8_t r = 0; r < num_rows; r++) {
            and_acc[r] &= rd_src[r];
            or_acc[r] |= rd_src[r];
        }

        // update last & write index
        last_s_idx = wr_s_idx;

        wr_s_idx++;
        if (wr_s_idx >= HISTORY_SAMPLE_COUNT) wr_s_idx = 0;

        // all flag set for re-run all check this cycle
        do_convolution = true;
        cooked_changed = true;
    } else {
        // non-change, flag update only
        // delay for gen safety 1 extra cycle for do_convolution 1 -> 0
        // short-circuit for keep true
        cooked_changed = cooked_changed || do_convolution;

        // time update, only write when change, last time not see (all time valid)
        //hist_time[last_s_idx] = now;
    }

    // valid history, do convolution, and/or to *_acc
    if (do_convolution) {
        // flag reset, if find valid sample set in loop, without last
        do_convolution = false;

        // 2-pass first gen list for condition, second exec from list
        // valid condition sample list, no init, must write first
        uint8_t * const both_s_list = convolution_s_both_buf;
        uint8_t both_count = 0;

        // build valid condition sample list,
        // calc expire time (minus offset from now), calc ahead 
        const fast_timer_t long_exp_time = now - LONG_DEBOUNCE;       

#ifdef HAS_SINGLE
        uint8_t * const single_s_list = convolution_s_single_buf;
        uint8_t single_count = 0;

        const fast_timer_t short_exp_time = now - SHORT_DEBOUNCE;
#endif

        // smple index to *_s_list, update flag
        for (uint8_t s = 0; s < HISTORY_SAMPLE_COUNT; s++) {
            // skip last, always valid no time, only last do_convolution keep false
            // last is max old value, must skip
            //if (s == last_s_idx) continue;
            
            // valid is not expired
            const bool long_expired = timer_expired_fast(long_exp_time, hist_time[s]);
            
            // like early return style, nothing to do, skip
            if (long_expired) continue;
#ifdef HAS_SINGLE
            const bool short_expired = timer_expired_fast(short_exp_time, hist_time[s]);
            
            // early return style
            if (short_expired) {
                // single
                single_s_list[both_count] = s;
                single_count++;

                do_convolution = true;
                continue; 
            }
#endif
            // both
            both_s_list[both_count] = s;
            both_count++;

            // reach here (and_valid || or_valid) is true
            //do_convolution = do_convolution || and_valid || or_valid; 
            do_convolution = true; 
        }

        // exec convolution from *_s_list
        if (do_convolution) {
            for (uint8_t i = 0; i < both_count; i++) {
                const uint8_t s = both_s_list[i];
                const uint8_t * const rd_src = hist_data[s];

                for (uint8_t r = 0; r < num_rows; r++) {
                    and_acc[r] &= rd_src[r];
                    or_acc[r] |= rd_src[r];
                } 
            }
#ifdef HAS_SINGLE
            for (uint8_t i = 0; i < single_count; i++) {
                const uint8_t s = single_s_list[i];
                const uint8_t * const rd_src = hist_data[s];

                for (uint8_t r = 0; r < num_rows; r++) {
#   ifdef SINGLE_IS_AND
                    and_acc[r] &= rd_src[r];
#   else
                    or_acc[r] |= rd_src[r];
#   endif
                } 
            }
#endif
        }
    }

    // debug status -> works good!
    //DEBUG_LED_1(and_valid);
    //DEBUG_LED_2(or_valid);

    // apply cooked update
    if (cooked_changed) {
        // flag reset, if find change set in loop
        cooked_changed = false;

        // find last pointer ahead
        const uint8_t * const rd_last_data = hist_data[last_s_idx];

        for (uint8_t r = 0; r < num_rows; r++) {
            // gen bit mask with matrix_mask
            // all 1  -> and=1 or=1 (stable 1)
            // all 0  -> and=0 or=0 (stable 0)
            // 0,1... -> and=0 or=1 (unstable, detect this)
            // none   -> and=1 or=0 (init invalid, check & mask)

            // new_data use stable 1, more safety
            // mask add to _acc on re-init, non apply here
            const matrix_row_t new_data = and_acc[r] & or_acc[r];

            // xor = 0 is stable, xor = 1 is unstable or init, not reverse 1 <-> 0
            const matrix_row_t stable_mask = ~(and_acc[r] ^ or_acc[r]);

            // if diff, tmp to final value, update flag
            // xor -> diff is 1, and mask -> stable only            
            if ((cooked[r] ^ new_data) & stable_mask) {
                // update cooked
                cooked[r] &= (~stable_mask);            // not stable bit keep current value, stable clear
                cooked[r] |= new_data & stable_mask;    // stable new data

                cooked_changed = true;
            }

            // must re-init mask data init and last data, simple is best
            and_acc[r] =   matrix_mask[r]  & rd_last_data[r];
            or_acc[r]  = (~matrix_mask[r]) | rd_last_data[r];
        }
    }

    return cooked_changed;
}

// add const for safety
void debounce_init(const uint8_t num_rows) {
    // init for invalid value
    for (uint8_t r = 0; r < num_rows; r++) {
        and_acc[r] =   matrix_mask[r];
        or_acc[r]  = (~matrix_mask[r]);

        // only first entry for init state
        hist_data[0][r] = 0;
    }

    last_s_idx = 0;
    wr_s_idx = 0;

    // only reset flags
    do_convolution = false;
    
    // first time run
    cooked_changed = true;
}

void debounce_free(void) {
    // static value only, nothing to do
    // upstream QMK remove this function
}
