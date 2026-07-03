#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "addons/get_pos_from_keyrecord.h"

// voyager custom spec
static const uint8_t row_col2pos_tbl[MATRIX_ROWS][MATRIX_COLS] = {
  { 255, 0,   1,   2,   3,   4,   5   },
  { 255, 6,   7,   8,   9,   10,  11  },
  { 255, 12,  13,  14,  15,  16,  17  },
  { 255, 18,  19,  20,  21,  22,  255 },
  { 255, 255, 255, 255, 23,  255, 255 },
  { 24,  25,  255, 255, 255, 255, 255 },

  { 26,  27,  28,  29,  30,  31,  255 },
  { 32,  33,  34,  35,  36,  37,  255 },
  { 38,  39,  40,  41,  42,  43,  255 },
  { 255, 45,  46,  47,  48,  49,  255 },
  { 255, 255, 44,  255, 255, 255, 255 },
  { 255, 255, 255, 255, 255, 50,  51  }
};

uint8_t get_pos_from_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return 255;
  return row_col2pos_tbl[record->event.key.row][record->event.key.col];
}
