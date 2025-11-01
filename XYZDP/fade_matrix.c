#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "fade_matrix.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#include "layer_num.h"

// fade color system
static fast_timer_t fade_tamrix_trigger = (UINT32_MAX / 2) - 1;
static const fast_timer_t fade_matrix_activate_delay = 29; // use prime
static const fast_timer_t fade_matrix_repeat_delay = 5; // use prime
static fast_timer_t fade_matrix_idle_delay = 30011; // valiable

// system side rgb
extern rgb_config_t rgb_matrix_config;

// target setting
static rgb_config_t fade_matrix_target;

static bool fade_matrix_active = false;

// reverse sort order
// hue value 6 * 8 like NCS
static const uint8_t hue_tbl[48] = {
  250, 243, 236, 229, 222, 215,
  207, 200, 193, 186, 179, 172,
  163, 154, 146, 137, 129, 118,
  111, 105,  98,  92,  86,  83,
   79,  75,  71,  67,  63,  58,
   55,  52,  49,  46,  43,  40,
   35,  30,  25,  20,  15,  10,
    9,   7,   5,   3,   1,   0
};

static const uint8_t sat_tbl[48] = {
  255, 252, 249, 246, 243, 240, 237, 234,
  231, 228, 225, 222, 219, 216, 213, 210,
  207, 204, 201, 198, 195, 192, 189, 186,
  183, 180, 177, 174, 171, 168, 164, 160,
  150, 140, 130, 120, 110, 100,  90,  80,
   70,  60,  50,  40,  30,  20,  10,   0
};

// val value max limit 175
static const uint8_t val_tbl[48] = {
  175, 165, 155, 145, 135, 128, 121, 119,
  117, 115, 113, 111, 109, 107, 105, 103,
  101,  99,  97,  95,  93,  91,  89,  87,
   85,  83,  81,  79,  77,  75,  73,  71,
   69,  67,  65,  63,  61,  59,  57,  55,
   53,  51,  46,  41,  31,  21,  11,   1
};

static const uint8_t spd_tbl[48] = {
  255, 250, 245, 240, 235, 230, 225, 220,
  215, 210, 205, 200, 195, 190, 185, 180,
  175, 170, 165, 160, 155, 150, 145, 140,
  135, 130, 125, 120, 115, 110, 105, 100,
   95,  90,  85,  80,  75,  70,  65,  60,
   55,  50,  45,  40,  35,  30,  25,  20
};

static const uint8_t idx2pos_tbl[48] = {
   49, 43, 37, 31,
   48, 42, 36, 30,
   47, 41, 35, 29,
   46, 40, 34, 28,
   45, 39, 33, 27,
   44, 38, 32, 26,
   
   23, 17, 11,  5,
   22, 16, 10,  4,
   21, 15,  9,  3,
   20, 14,  8,  2,
   19, 13,  7,  1,
   18, 12,  6,  0
};

static const uint8_t pos2idx_tbl[52] = {
    47,  43,  39,  35,  31,  27,
    46,  42,  38,  34,  30,  26,
    45,  41,  37,  33,  29,  25,
    44,  40,  36,  32,  28,  24,
   255, 255,
    23,  19,  15,  11,   7,   3,
    22,  18,  14,  10,   6,   2,
    21,  17,  13,   9,   5,   1,
    20,  16,  12,   8,   4,   0,
   255, 255
};

static const uint8_t row_col2pos_tbl[MATRIX_ROWS][MATRIX_COLS] = {
  { 255,   0,   1,   2,   3,   4,   5 },
  { 255,   6,   7,   8,   9,  10,  11 },
  { 255,  12,  13,  14,  15,  16,  17 },
  { 255,  18,  19,  20,  21,  22, 255 },
  { 255, 255, 255, 255,  23, 255, 255 },
  {  24,  25, 255, 255, 255, 255, 255 },

  {  26,  27,  28,  29,  30,  31, 255 },
  {  32,  33,  34,  35,  36,  37, 255 },
  {  38,  39,  40,  41,  42,  43, 255 },
  { 255,  45,  46,  47,  48,  49, 255 },
  { 255, 255,  44, 255, 255, 255, 255 },
  { 255, 255, 255, 255, 255,  50,  51 }
};

uint8_t get_pos_from_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return 255;
  return row_col2pos_tbl[record->event.key.row][record->event.key.col];
}

void fade_matrix_set_mode(const uint8_t mode) {
  fade_matrix_target.mode = mode;
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_set_hue_pos(const uint8_t pos) {
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.h = hue_tbl[idx];
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_set_sat_pos(const uint8_t pos) {
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.s = sat_tbl[idx];
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_set_val_pos(const uint8_t pos) {
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.v = val_tbl[idx];
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_set_speed_pos(const uint8_t pos) {
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.speed = spd_tbl[idx];
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_increase_hue(void) {
  fade_matrix_target.hsv.h++;
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_decrease_hue(void) {
  fade_matrix_target.hsv.h--;
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_increase_sat(void) {
  fade_matrix_target.hsv.s = qadd8(fade_matrix_target.hsv.s, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_decrease_sat(void) {
  fade_matrix_target.hsv.s = qsub8(fade_matrix_target.hsv.s, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_increase_val(void) {
  fade_matrix_target.hsv.v = qadd8(fade_matrix_target.hsv.v, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_decrease_val(void) {
  fade_matrix_target.hsv.v = qsub8(fade_matrix_target.hsv.v, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_increase_speed(void) {
  fade_matrix_target.speed = qadd8(fade_matrix_target.speed, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_decrease_speed(void) {
  fade_matrix_target.speed = qsub8(fade_matrix_target.speed, 1);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_toggle(void) {
  fade_matrix_target.enable = !(fade_matrix_target.enable);
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_step(void) {
  fade_matrix_target.mode++;
  if (!(fade_matrix_target.mode < RGB_MATRIX_EFFECT_MAX)) fade_matrix_target.mode = 1;
  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_load_preset(void) {
  fade_matrix_target.enable = true;
  fade_matrix_target.hsv.h = 250;
  fade_matrix_target.hsv.s = 192;
  fade_matrix_target.hsv.v = 109;
  fade_matrix_target.speed = 80;
  fade_matrix_target.mode = RGB_MATRIX_FLOWER_BLOOMING;
  
  fade_matrix_idle_delay = 180001; // use prime

  activate_fade_matrix(timer_read_fast());
}

void fade_matrix_load_preset_powersave(void) {
  fade_matrix_target.enable = true;
  //fade_matrix_target.hsv.h = 0;
  fade_matrix_target.hsv.s = 0;
  fade_matrix_target.hsv.v = 21;
  //fade_matrix_target.speed = 128;
  fade_matrix_target.mode = RGB_MATRIX_SOLID_COLOR;

  fade_matrix_idle_delay = 10007; // use prime

  activate_fade_matrix(timer_read_fast());
}

void init_fade_matrix(const fast_timer_t now) {
  rgb_matrix_sethsv_noeeprom(0, 0, 0);
  rgb_matrix_set_speed_noeeprom(0);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);

  fade_matrix_target.enable = false;
  fade_matrix_target.hsv.h = 0;
  fade_matrix_target.hsv.s = 0;
  fade_matrix_target.hsv.v = 0;
  fade_matrix_target.speed = 0;
  fade_matrix_target.mode = RGB_MATRIX_NONE;

  activate_fade_matrix(now);
}

void activate_fade_matrix(const fast_timer_t now) {
  fade_tamrix_trigger = now + fade_matrix_activate_delay;
  // transfer target to active, set rgb_matrix_config.enacle by api
  fade_matrix_active = fade_matrix_target.enable;
}

void update_fade_matrix(const fast_timer_t now) {
  if (timer_expired_fast(now, fade_tamrix_trigger) == false) return;
  fade_tamrix_trigger += fade_matrix_repeat_delay;

  if (fade_matrix_active) {
    // rgb to enable
    rgb_matrix_enable_noeeprom();
    if ((rgb_matrix_config.speed != fade_matrix_target.speed) || (rgb_matrix_config.mode != fade_matrix_target.mode)) {
      if (rgb_matrix_config.hsv.v != 0) {
        rgb_matrix_config.hsv.v--;
      } else {
        // set sat 0 color
        rgb_matrix_config.hsv.s = 0;
        rgb_matrix_config.speed = fade_matrix_target.speed;

        // req additional func use api
        rgb_matrix_mode_noeeprom(fade_matrix_target.mode);
      }
    } else if (rgb_matrix_config.hsv.v != fade_matrix_target.hsv.v) {
      if (rgb_matrix_config.hsv.v < fade_matrix_target.hsv.v) {
        rgb_matrix_config.hsv.v++;
      } else {
        rgb_matrix_config.hsv.v--;
      }
    } else if (rgb_matrix_config.hsv.h != fade_matrix_target.hsv.h) {
      // search near direction
      if ((uint8_t)(fade_matrix_target.hsv.h - rgb_matrix_config.hsv.h) < (uint8_t)(rgb_matrix_config.hsv.h - fade_matrix_target.hsv.h)) {
        rgb_matrix_config.hsv.h++;
      } else {
        rgb_matrix_config.hsv.h--;
      }
    } else if (rgb_matrix_config.hsv.s != fade_matrix_target.hsv.s) {
      if (rgb_matrix_config.hsv.s < fade_matrix_target.hsv.s) {
        rgb_matrix_config.hsv.s++;
      } else {
        rgb_matrix_config.hsv.s--;
      }
    } else {
      fade_matrix_active = false;
      fade_tamrix_trigger += fade_matrix_idle_delay;
    }
  } else {
    // rgb to disable
    if (rgb_matrix_config.hsv.s != 0) {
      rgb_matrix_config.hsv.s--;
    } else if (rgb_matrix_config.hsv.v != 0) {
      rgb_matrix_config.hsv.v--;
    } else {
      fade_tamrix_trigger = now + (UINT32_MAX / 2) - 1;
      rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
      rgb_matrix_disable_noeeprom();
    }
  }
}

void set_layer_color_hue_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(24, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  rgb_matrix_set_color(51, hsv.v, hsv.v, 0);
  uint8_t key = hsv.h;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.h <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

void set_layer_color_sat_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  rgb_matrix_set_color(51, 0, 0, 0);
  uint8_t key = hsv.s;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.s <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

void set_layer_color_val_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(24, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  rgb_matrix_set_color(51, 0, 0, 0);
  uint8_t key = hsv.v;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.v <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

void set_layer_color_speed_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(50, 0, hsv.v, 0);
  rgb_matrix_set_color(51, 0, 0, hsv.v);
  
  // copy logic from breathing_anim.h   
  uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
  rgb = hsv_to_rgb(hsv);

  uint8_t key = rgb_matrix_get_speed();
  uint8_t i = 0;
  uint8_t spd = 0;
  for (i = 0; i < 48; i++) {
    spd = spd_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (spd <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

void set_layer_color_halt_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
  //RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color_all(0, 0, 0);

  rgb_matrix_set_color(31, hsv.v, 0, 0);
  rgb_matrix_set_color(49, hsv.v, hsv.v, 0);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
}

void set_layer_color_firmware_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  //const uint8_t o = q >> 1;

  rgb_matrix_set_color_all(0, 0, 0);

  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  //rgb_matrix_set_color(44, f, f, 0);
  //rgb_matrix_set_color(45, f, f, 0);
  rgb_matrix_set_color(50, q, q, 0);
  rgb_matrix_set_color(51, q, 0, 0);
  
  //ANSI/JIS
  if (layer_state_is(L_Base_JIS)) {
    //JIS base enable
    rgb_matrix_set_color(0, q, q, q);
    rgb_matrix_set_color(6, 0, f, 0);
  } else {
    //ANSI base
    rgb_matrix_set_color(0, f, 0, 0);
    rgb_matrix_set_color(6, q, q, q);
  }

  //OS detect
  RGB rgb_os = {0, 0, 0};
  switch (detected_host_os()) {
    case OS_WINDOWS:
      rgb_os.b = f;
      break;
    case OS_LINUX:
      rgb_os.g = f;
      break;
    case OS_MACOS:
      rgb_os.r = f;
      break;
    case OS_IOS:
      rgb_os.r = f;
      rgb_os.g = h;
      break;    
    case OS_UNSURE:
      rgb_os.r = f;
      rgb_os.g = f;
      break;
    default:
      rgb_os.r = f;
      rgb_os.g = f;
      rgb_os.b = f;
      break;
  }
  rgb_matrix_set_color(22, rgb_os.r, rgb_os.g, rgb_os.b);
  rgb_matrix_set_color(23, rgb_os.r, rgb_os.g, rgb_os.b);

  //tapping
  //rgb_matrix_set_color(18, 0, 0, f);
  //rgb_matrix_set_color(19, q, 0, q);
  //rgb_matrix_set_color(20, f, 0, f);

  //reset clear
  rgb_matrix_set_color(29, f, h, 0);
  rgb_matrix_set_color(31, f, 0, 0);
  rgb_matrix_set_color(49, f, f, 0);

  //color test
  //rgb_matrix_set_color(26, f, 0, 0);
  //rgb_matrix_set_color(32, f, o, 0);
  //rgb_matrix_set_color(38, f, q, 0);
  //rgb_matrix_set_color(44, f, h, 0);

  //rgb_matrix_set_color(27, f, f, 0);
  //rgb_matrix_set_color(33, h, f, 0);
  //rgb_matrix_set_color(39, q, f, 0);
  //rgb_matrix_set_color(45, o, f, 0);
  
  //rgb_matrix_set_color(28, 0, f, 0);
  //rgb_matrix_set_color(34, 0, f, q);
  //rgb_matrix_set_color(40, 0, f, f);
  //rgb_matrix_set_color(46, 0, q, f);
  
  //rgb_matrix_set_color(29, 0, 0, f);
  //rgb_matrix_set_color(35, q, 0, f);
  //rgb_matrix_set_color(41, f, 0, f);
  //rgb_matrix_set_color(47, f, 0, q);
}

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;

void set_layer_color_mouse_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  rgb_matrix_set_color_all(0, 0, 0);

  // left side
  rgb_matrix_set_color( 4, f, f, 0);
  rgb_matrix_set_color( 5, f, 0, h);
  
  rgb_matrix_set_color(10, 0, h, f);
  rgb_matrix_set_color(11, 0, f, h);

  rgb_matrix_set_color(16, h, 0, f);
  
  rgb_matrix_set_color(23, 0, 0, f);
  
  rgb_matrix_set_color(24, 0, f, 0);
  rgb_matrix_set_color(25, f, 0, 0);

  // right side
  rgb_matrix_set_color(26, 0, f, h);
  rgb_matrix_set_color(27, f, 0, h);
  rgb_matrix_set_color(28, f, f, 0);
  rgb_matrix_set_color(29, 0, h, f); 
  rgb_matrix_set_color(30, h, 0, f);
  
  rgb_matrix_set_color(32, 0, 0, f);
  rgb_matrix_set_color(33, 0, f, 0);
  
  rgb_matrix_set_color(38, o, q, 0);
  rgb_matrix_set_color(39, f, 0, 0);

  //rgb_matrix_set_color(44, q, q, q);
  rgb_matrix_set_color(47, q, q, q);
  rgb_matrix_set_color(48, f, f, f);
  
  // scroll
  if (set_scrolling) {
    rgb_matrix_set_color( 9, q, 0, 0);
    rgb_matrix_set_color(17, h, 0, 0);
    rgb_matrix_set_color(22, h, 0, 0);
    rgb_matrix_set_color(34, q, 0, 0);
    rgb_matrix_set_color(45, h, 0, 0);
    rgb_matrix_set_color(50, h, 0, 0);
  } else {
    rgb_matrix_set_color( 9, q, q, q);
    rgb_matrix_set_color(17, h, h, h);
    rgb_matrix_set_color(22, h, h, h);
    rgb_matrix_set_color(34, q, q, q);
    rgb_matrix_set_color(45, h, h, h);
    rgb_matrix_set_color(50, h, h, h);
  }

  if (navigator_turbo) {
    rgb_matrix_set_color(36, f, h, 0);
  } else {
    rgb_matrix_set_color(36, f, f, f);
  }
  if (navigator_aim) {
    rgb_matrix_set_color(35, q, o, 0);
  } else {
    rgb_matrix_set_color(35, q, q, q);    
  }
}
