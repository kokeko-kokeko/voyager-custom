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

// hue value 6 * 8 like NCS
static const uint8_t hue_tbl[48] = {
    0,   1,   3,   5,   7,   9, 
   10,  15,  20,  25,  30,  35,
   40,  43,  46,  49,  52,  55,
   58,  63,  67,  71,  75,  79,
   83,  86,  92,  98, 105, 111,
  118, 129, 137, 146, 154, 163,
  172, 179, 186, 193, 200, 207,
  215, 222, 229, 236, 243, 250
};

static const uint8_t sat_tbl[48] = {
    0,   8,  16,  24,  32,  40,  48,  56,
   64,  72,  80,  88,  96, 104, 112, 120,
  128, 135, 139, 143, 147, 151, 155, 159,
  163, 167, 171, 175, 179, 183, 187, 191,
  195, 199, 203, 207, 211, 215, 219, 223,
  227, 231, 235, 239, 243, 247, 251, 255
};

// val value max limit 175
static const uint8_t val_tbl[48] = {
    1,  11,  21,  31,  41,  46,  51,  53,
   55,  57,  59,  61,  63,  65,  67,  69,
   71,  73,  75,  77,  79,  81,  83,  85,
   87,  89,  91,  93,  95,  97,  99, 101,
  103, 105, 107, 109, 111, 113, 115, 117,
  119, 121, 128, 135, 145, 155, 165, 175
};

static const uint8_t spd_tbl[48] = {
   20,  25,  30,  35,  40,  45,  50,  55,
   60,  65,  70,  75,  80,  85,  90,  95,
  100, 105, 110, 115, 120, 125, 130, 135,
  140, 145, 150, 155, 160, 165, 170, 175,
  180, 185, 190, 195, 200, 205, 210, 215,
  220, 225, 230, 235, 240, 245, 250, 255
};

static const uint8_t idx2pos_tbl[48] = {
   0,  6, 12, 18,
   1,  7, 13, 19,  
   2,  8, 14, 20,  
   3,  9, 15, 21,
   4, 10, 16, 22,
   5, 11, 17, 23,
  
  26, 32, 38, 44,
  27, 33, 39, 45,
  28, 34, 40, 46,
  29, 35, 41, 47,
  30, 36, 42, 48,
  31, 37, 43, 49
};

static const uint8_t pos2idx_tbl[52] = {
    0,   4,  8, 12, 16, 20,
    1,   5,  9, 13, 17, 21,
    2,   6, 10, 14, 18, 22,
    3,   7, 11, 15, 19, 23,
  255, 255,
   24,  28, 32, 36, 40, 44,
   25,  29, 33, 37, 41, 45,
   26,  30, 34, 38, 42, 46,
   27,  31, 35, 39, 43, 47,
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

static void activate_fade_matrix(void) {
  const fast_timer_t now = timer_read_fast();

  fade_tamrix_trigger = now + fade_matrix_activate_delay;
  // transfer target to active, set rgb_matrix_config.enacle by api
  fade_matrix_active = fade_matrix_target.enable;
}

uint8_t get_pos_from_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return 255;
  return row_col2pos_tbl[record->event.key.row][record->event.key.col];
}

void fade_matrix_set_mode(const uint8_t mode) {
  fade_matrix_target.mode = mode;
  activate_fade_matrix();
}

void fade_matrix_set_hue_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.h = hue_tbl[idx];
  activate_fade_matrix();
}

void fade_matrix_set_sat_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.s = sat_tbl[idx];
  activate_fade_matrix();
}

void fade_matrix_set_val_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.hsv.v = val_tbl[idx];
  activate_fade_matrix();
}

void fade_matrix_set_speed_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return;
  uint8_t pos = get_pos_from_keyrecord(record);
  if (52 <= pos) return;
  uint8_t idx = pos2idx_tbl[pos];
  if (48 <= idx) return;
  fade_matrix_target.speed = spd_tbl[idx];
  activate_fade_matrix();
}

void fade_matrix_increase_hue(void) {
  fade_matrix_target.hsv.h++;
  activate_fade_matrix();
}

void fade_matrix_decrease_hue(void) {
  fade_matrix_target.hsv.h--;
  activate_fade_matrix();
}

void fade_matrix_increase_sat(void) {
  fade_matrix_target.hsv.s = qadd8(fade_matrix_target.hsv.s, 1);
  activate_fade_matrix();
}

void fade_matrix_decrease_sat(void) {
  fade_matrix_target.hsv.s = qsub8(fade_matrix_target.hsv.s, 1);
  activate_fade_matrix();
}

void fade_matrix_increase_val(void) {
  fade_matrix_target.hsv.v = qadd8(fade_matrix_target.hsv.v, 1);
  activate_fade_matrix();
}

void fade_matrix_decrease_val(void) {
  fade_matrix_target.hsv.v = qsub8(fade_matrix_target.hsv.v, 1);
  activate_fade_matrix();
}

void fade_matrix_increase_speed(void) {
  fade_matrix_target.speed = qadd8(fade_matrix_target.speed, 1);
  activate_fade_matrix();
}

void fade_matrix_decrease_speed(void) {
  fade_matrix_target.speed = qsub8(fade_matrix_target.speed, 1);
  activate_fade_matrix();
}

void fade_matrix_toggle(void) {
  fade_matrix_target.enable = !(fade_matrix_target.enable);
  activate_fade_matrix();
}

void fade_matrix_step(void) {
  fade_matrix_target.mode++;
  if (!(fade_matrix_target.mode < RGB_MATRIX_EFFECT_MAX)) fade_matrix_target.mode = 1;
  activate_fade_matrix();
}

void fade_matrix_load_preset(void) {
  fade_matrix_target.enable = true;
  fade_matrix_target.hsv.h = 86;
  fade_matrix_target.hsv.s = 128;
  fade_matrix_target.hsv.v = 105;
  fade_matrix_target.speed = 80;
  fade_matrix_target.mode = RGB_MATRIX_FLOWER_BLOOMING;
  
  fade_matrix_idle_delay = 180001; // use prime

  activate_fade_matrix();
}

void fade_matrix_load_preset_powersave(void) {
  fade_matrix_target.enable = true;
  //fade_matrix_target.hsv.h = 0;
  fade_matrix_target.hsv.s = 0;
  fade_matrix_target.hsv.v = 21;
  //fade_matrix_target.speed = 128;
  fade_matrix_target.mode = RGB_MATRIX_SOLID_COLOR;

  fade_matrix_idle_delay = 10007; // use prime

  activate_fade_matrix();
}

void post_init_fade_matrix(void) {
  rgb_matrix_sethsv_noeeprom(0, 0, 0);
  rgb_matrix_set_speed_noeeprom(0);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);

  fade_matrix_target.enable = false;
  fade_matrix_target.hsv.h = 0;
  fade_matrix_target.hsv.s = 0;
  fade_matrix_target.hsv.v = 0;
  fade_matrix_target.speed = 0;
  fade_matrix_target.mode = RGB_MATRIX_NONE;

  activate_fade_matrix();
}

void post_process_record_fade_matrix(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed == false) return;

  activate_fade_matrix();
  
  return;
}

report_mouse_t pointing_device_task_fade_matrix(report_mouse_t mouse_report) {
  // move detect
  bool move_or = false;
  
  move_or = move_or || (mouse_report.x != 0);
  move_or = move_or || (mouse_report.y != 0);
  move_or = move_or || (mouse_report.h != 0);
  move_or = move_or || (mouse_report.v != 0);

  if (move_or) {
    // wakeup RGB
    activate_fade_matrix();
  }
  
  return mouse_report;
}

layer_state_t layer_state_set_fade_matrix(layer_state_t state) {
  // layer change activate
  activate_fade_matrix();
  
  return state;
}

void housekeeping_task_fade_matrix(void) {
  const fast_timer_t now = timer_read_fast();
  
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
    if (key <= hsv.h) {
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
    if (key <= hsv.s) {
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
    if (key <= hsv.v) {
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
    if (key <= spd) {
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
  //rgb_matrix_set_color(49, hsv.v, hsv.v, 0);
  //rgb_matrix_set_color(24, 0, hsv.v, 0);
  //rgb_matrix_set_color(25, 0, hsv.v, 0);
  rgb_matrix_set_color(50, 0, hsv.v, 0);
  //rgb_matrix_set_color(51, 0, hsv.v, 0);
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
  if (layer_state_is(L_Base_ANSI)) {
    //ANSI base enable
    rgb_matrix_set_color(0, q, q, q);
    rgb_matrix_set_color(6, f, 0, 0);
  } else {
    //JIS base
    rgb_matrix_set_color(0, 0, f, 0);
    rgb_matrix_set_color(6, q, q, q);
  }

  //Engram v2021/v2025
  if (layer_state_is(L_Base_2021)) {
    //v2021 base enable
    rgb_matrix_set_color(1, q, q, q);
    rgb_matrix_set_color(7, f, f, 0);
  } else {
    //v2025 base
    rgb_matrix_set_color(1, 0, 0, f);
    rgb_matrix_set_color(7, q, q, q);
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

  led_t status = host_keyboard_led_state();

  if (status.caps_lock) {
    rgb_matrix_set_color(19, h, 0, 0);
  } else {
    rgb_matrix_set_color(19, q, q, q);
  }

  if (status.num_lock) {
    rgb_matrix_set_color(45, h, 0, 0);
  } else {
    rgb_matrix_set_color(45, q, q, q);
  }

  if (status.scroll_lock) {
    rgb_matrix_set_color(46, 0, h, 0);
  } else {
    rgb_matrix_set_color(46, q, q, q);
  }

  if (status.compose) {
    rgb_matrix_set_color(47, 0, 0, h);
  } else {
    rgb_matrix_set_color(47, q, q, q);
  }

  if (status.kana) {
    rgb_matrix_set_color(17, h, 0, h);
  } else {
    rgb_matrix_set_color(17, q, q, q);
  }
  
}

