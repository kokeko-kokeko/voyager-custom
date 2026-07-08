#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/fade_matrix.h"
#include "addons/get_pos_from_keyrecord.h"
#include "addons/status_led.h"

#include "addons/sub_trackball.h"

#include "navigator_trackpad_common.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#define FADE_MATRIX_POSITION_COUNT 52
#define FADE_MATRIX_INDEX_COUNT 48
#define FADE_MATRIX_SELECT_COUNT 5

// access fade matrix
extern rgb_config_t fade_matrix_target;
extern void activate_fade_matrix(void);
extern void fade_matrix_load_powersave(void);
extern void fade_matrix_load_default(void);

// hue value 6 * 8 like NCS
static const uint8_t hue_tbl[FADE_MATRIX_INDEX_COUNT] = {
  0,   1,   3,   5,   7,   9, 
  10,  15,  20,  25,  30,  35,
  40,  43,  46,  49,  52,  55,
  58,  63,  67,  71,  75,  79,
  83,  86,  92,  98,  105, 111,
  118, 129, 137, 146, 154, 163,
  172, 179, 186, 193, 200, 207,
  215, 222, 229, 236, 243, 250
};

static const uint8_t sat_tbl[FADE_MATRIX_INDEX_COUNT] = {
  0,   8,   16,  24,  32,  40,  48,  56,
  64,  72,  80,  88,  96,  104, 112, 120,
  128, 135, 139, 143, 147, 151, 155, 159,
  163, 167, 171, 175, 179, 183, 187, 191,
  195, 199, 203, 207, 211, 215, 219, 223,
  227, 231, 235, 239, 243, 247, 251, 255
};

// val value max limit 175
static const uint8_t val_tbl[FADE_MATRIX_INDEX_COUNT] = {
  34,  37,  40,  43,  46,  49,  52,  55,
  58,  61,  64,  67,  70,  73,  76,  79,
  82,  85,  88,  91,  94,  97,  100, 103,
  106, 109, 112, 115, 118, 121, 124, 127,
  130, 133, 136, 139, 142, 145, 148, 151,
  154, 157, 160, 163, 166, 169, 172, 175
};

static const uint8_t spd_tbl[FADE_MATRIX_INDEX_COUNT] = {
  20,  25,  30,  35,  40,  45,  50,  55,
  60,  65,  70,  75,  80,  85,  90,  95,
  100, 105, 110, 115, 120, 125, 130, 135,
  140, 145, 150, 155, 160, 165, 170, 175,
  180, 185, 190, 195, 200, 205, 210, 215,
  220, 225, 230, 235, 240, 245, 250, 255
};

static const uint8_t idx2pos_tbl[FADE_MATRIX_INDEX_COUNT] = {
  0,  6,  12, 18,
  1,  7,  13, 19,  
  2,  8,  14, 20,  
  3,  9,  15, 21,
  4,  10, 16, 22,
  5,  11, 17, 23,
  
  26, 32, 38, 44,
  27, 33, 39, 45,
  28, 34, 40, 46,
  29, 35, 41, 47,
  30, 36, 42, 48,
  31, 37, 43, 49
};

static const uint8_t pos2idx_tbl[FADE_MATRIX_POSITION_COUNT] = {
  0,   4,  8,  12, 16, 20,
  1,   5,  9,  13, 17, 21,
  2,   6,  10, 14, 18, 22,
  3,   7,  11, 15, 19, 23,
  255, 255,
  24,  28, 32, 36, 40, 44,
  25,  29, 33, 37, 41, 45,
  26,  30, 34, 38, 42, 46,
  27,  31, 35, 39, 43, 47,
  255, 255
};

// palette select
static uint8_t plt_select = 0;

static void set_hue_idx (const uint8_t idx) { fade_matrix_target.hsv.h = hue_tbl[idx]; };
static void set_sat_idx (const uint8_t idx) { fade_matrix_target.hsv.s = sat_tbl[idx]; };
static void set_val_idx (const uint8_t idx) { fade_matrix_target.hsv.v = val_tbl[idx]; };
static void set_speed_idx (const uint8_t idx) { fade_matrix_target.speed = spd_tbl[idx]; };
static void set_mode_idx (const uint8_t idx) {
  if (idx == (FADE_MATRIX_INDEX_COUNT - 1)) {
    fade_matrix_load_powersave();
    status_led(0b1010, led_pattern_oneshot);
  } else if (idx == (FADE_MATRIX_INDEX_COUNT - 2)) {
    fade_matrix_load_default();
    status_led(0b1010, led_pattern_oneshot);
  } else if (idx == 0) {
    // idx 0 to disable
    fade_matrix_target.enable = false;
  } else {
    // not 0 enable
    fade_matrix_target.enable = true;
      
    // mode 1 origin
    uint8_t mode = idx;

    // if out of range, keep 
    if (mode >= RGB_MATRIX_EFFECT_MAX) mode = fade_matrix_target.mode;
      
    fade_matrix_target.mode = mode;
  }
}

static void (*const set_func_array[]) (const uint8_t) = {
  set_val_idx,
  set_sat_idx,
  set_hue_idx,
  set_mode_idx,
  set_speed_idx
};

#define SEL_SET_FUNC_COUNT (sizeof(set_func_array) / sizeof(set_func_array[0]))
_Static_assert(SEL_SET_FUNC_COUNT == FADE_MATRIX_SELECT_COUNT, "fade matrix select set function count missmatch!!");

bool color_palette_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  // MT template
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      
    } else {
      return false;
    }
  } else {
    if (record->event.pressed) {
      
    } else {
      return false;
    }  
  }
  
  uint8_t pos = get_pos_from_keyrecord(record);
  if (FADE_MATRIX_POSITION_COUNT <= pos) return false;
  uint8_t idx = pos2idx_tbl[pos];
  if (FADE_MATRIX_INDEX_COUNT <= idx) return false;

  set_func_array[plt_select](idx);

  activate_fade_matrix();

  // default false
  return false;
}

bool color_palette_select_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  // MT template
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      
    } else {
      // palette select
      // 3-bit Johnson counter (0-5)
      plt_select++;
      if (plt_select >= FADE_MATRIX_SELECT_COUNT) plt_select = 0;
    }
  } else {
    if (record->event.pressed) {
      plt_select = 0;
    } else {
      
    }  
  }

  // default false
  return false;
}

layer_state_t layer_state_set_color_palette(layer_state_t state) {
  // clear select
  if (layer_state_cmp(state, LAYER_Color_Palette) == false) plt_select = 0;
  
  return state;
}


static void set_layer_color_hue_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);
  
  uint8_t key = hsv.h;
  // fix for disp color
  hsv.s = 255;
  
  uint8_t i = 0;
  for (i = 0; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (key <= hsv.h) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_sat_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);
  
  uint8_t key = hsv.s;
  uint8_t i = 0;
  for (i = 0; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (key <= hsv.s) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_val_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);
  
  uint8_t key = hsv.v;
  uint8_t i = 0;
  for (i = 0; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (key <= hsv.v) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < FADE_MATRIX_INDEX_COUNT; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_speed_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);
  
  // copy logic from breathing_anim.h   
  uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
  rgb = hsv_to_rgb(hsv);

  uint8_t key = rgb_matrix_get_speed();
  uint8_t i = 0;
  uint8_t spd = 0;
  for (i = 0; i < FADE_MATRIX_INDEX_COUNT; i++) {
    spd = spd_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (key <= spd) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < FADE_MATRIX_INDEX_COUNT; i++) {
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_mode_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  
  rgb_matrix_set_color(idx2pos_tbl[FADE_MATRIX_INDEX_COUNT - 1], 0, hsv.v, 0);
  rgb_matrix_set_color(idx2pos_tbl[FADE_MATRIX_INDEX_COUNT - 2], 0, 0, hsv.v);
  
  // mode 1 origin
  rgb_matrix_set_color(idx2pos_tbl[rgb_matrix_config.mode], 0, 0, 0);
  rgb_matrix_set_color(idx2pos_tbl[RGB_MATRIX_EFFECT_MAX], hsv.v, hsv.v, 0);
}

static uint8_t const hue_idx_step = FADE_MATRIX_INDEX_COUNT / FADE_MATRIX_SELECT_COUNT;

static void (*const rgb_matrix_indicators_fade_matrix_array[]) (void) = {
  set_layer_color_val_map,
  set_layer_color_sat_map,
  set_layer_color_hue_map,
  set_layer_color_mode_map,
  set_layer_color_speed_map
};

#define SEL_LAYER_FUNC_COUNT (sizeof(rgb_matrix_indicators_fade_matrix_array) / sizeof(rgb_matrix_indicators_fade_matrix_array[0]))
_Static_assert(SEL_LAYER_FUNC_COUNT == FADE_MATRIX_SELECT_COUNT, "fade matrix select color function count missmatch!!");
_Static_assert(SEL_LAYER_FUNC_COUNT == SEL_SET_FUNC_COUNT, "fade matrix select set & color function count missmatch!!");
#undef SEL_LAYER_FUNC_COUNT
#undef SEL_SET_FUNC_COUNT

bool rgb_matrix_indicators_color_palette(void) {
  // if no active nothing to do, pass next
  if (layer_state_is(LAYER_Color_Palette) == false) return true;

  rgb_matrix_indicators_fade_matrix_array[plt_select]();
  
  HSV hsv = rgb_matrix_get_hsv();
  hsv.h = hue_tbl[hue_idx_step * plt_select];
  hsv.s = 255;

  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(24, rgb.r, rgb.g, rgb.b);

  rgb_matrix_set_color(25, 0, 0, 0);
  rgb_matrix_set_color(50, 0, 0, 0);
  
  rgb_matrix_set_color(51, 0, hsv.v, 0);

  // if run display terminate here
  return false;
}

