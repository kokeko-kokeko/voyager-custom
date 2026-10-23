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

#define SAMPLE_COUNT 7

static matrix_row_t hist_buf[SAMPLE_COUNT][MATRIX_ROWS] = {0};
static uint8_t wr_idx = 0;

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    // value to history buffer
    for (uint8_t r = 0; r < num_rows; r++) {
        hist_buf[wr_idx][r] = raw[r];
    }

    // update write index
    wr_idx++;
    if (SAMPLE_COUNT <= wr_idx) wr_idx = 0; 

    // or history value, if 1< high report press, like asym
    bool cooked_changed = false;
    for (uint8_t r = 0; r < num_rows; r++) {
        matrix_row_t tmp_row = 0;
        for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
            tmp_row |= hist_buf[s][r];
        }

        if (tmp_row != cooked[r]) {
            cooked[r] = tmp_row;
            cooked_changed = true;
        }
    }

    return cooked_changed;
}

void debounce_init(uint8_t num_rows) {
    for (uint8_t s = 0; s < SAMPLE_COUNT; s++) {
        for (uint8_t r = 0; r < num_rows; r++) {
            hist_buf[s][r] = 0;
        }
    }
    wr_idx = 0;
}

void debounce_free(void) {
    // static value only
}