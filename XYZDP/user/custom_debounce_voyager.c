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
//#include "timer.h"
//#include <stdlib.h>

#define SAMPLE_COUNT 8

static matrix_row_t hist_buf[MATRIX_ROWS][SAMPLE_COUNT] = {0};
static uint8_t wr_smp = 0;

// mask for unused cross-point, for voyager
static const matrix_row_t row_mask[MATRIX_ROWS] = {
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
bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    // cooked update flag
    bool cooked_changed = false;

    // process each row
    for (uint8_t r = 0; r < num_rows; r++) {
        // value to history buffer
        hist_buf[r][wr_smp] = raw[r] & row_mask[r];

        // bit or all history value, if 1< high report press, like upstream asym
        matrix_row_t tmp_row = 0;
        for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
            tmp_row |= hist_buf[r][s];
        }

        // safety, mask again
        tmp_row &= row_mask[r];

        if (cooked[r] != tmp_row) {
            cooked[r] = tmp_row;
            cooked_changed = true;
        }
    }

    // update write sample intex
    wr_smp++;
    if (SAMPLE_COUNT <= wr_smp) wr_smp = 0;

    return cooked_changed;
}

void debounce_init(uint8_t num_rows) {
    for (uint8_t r = 0; r < num_rows; r++) {
        for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
            hist_buf[r][s] = 0;
        }
    }
    wr_smp = 0;
}

void debounce_free(void) {
    // static value only, nothing to do
}