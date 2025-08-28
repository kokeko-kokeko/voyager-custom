#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "overlay_layer_mod.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#include "layer_num.h"

// ime state from LANG1/LANG2 key
static bool ime_on = false;
static bool ime_kk = false;  //KataKana

// Ime State Sync system
static bool iss_enable = true; 
static bool iss_sync = false;

static fast_timer_t iss_trigger = 0;
static const fast_timer_t iss_sync_delay = 15013; //ms
static const fast_timer_t iss_idle_delay = 600011; //ms

void ime_state_sync_enable(void) {
  iss_enable = true;
  iss_sync = false;
  fast_timer_t now = timer_read_fast();
  iss_trigger = now +  (UINT32_MAX / 2) - 1;
}

void ime_state_sync_disable(void) {
  iss_enable = false;
  iss_sync = false;
  fast_timer_t now = timer_read_fast();
  iss_trigger = now +  (UINT32_MAX / 2) - 1;
}

bool pre_process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if(iss_sync) {
      if (ime_on) {
        if (ime_kk) {
          tap_code16(LSFT(KC_LANGUAGE_1));
        } else {
          tap_code16(KC_LANGUAGE_1);
        }
      } else {
        tap_code16(KC_LANGUAGE_2);
      }
    }
  }
  return true;
}

bool process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //IME state display (update flag & re-calc status)
    case LT(L_Function, KC_LANGUAGE_1):
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          if (layer_state_is(L_LeftPinky) | layer_state_is(L_RightPinky) | layer_state_is(L_Function) |
            layer_state_is(L_Number) | layer_state_is(L_Cursor)) {
            // reverse side (upper layer)
            if ((get_mods() & MOD_MASK_CSAG) == 0) {
              ime_on = false;
            }
            tap_code16(KC_LANGUAGE_2);
            return false;
          } else {
            // normal side (base layer)
            if ((get_mods() & MOD_MASK_CAG) == 0) {
              ime_on = true;
              if (get_mods() & MOD_MASK_SHIFT) {
                ime_kk = true;
              } else {
                ime_kk = false;
              }
            }
          }
        }
      }
      return true;
    
    case KC_LANGUAGE_2:
      if (record->event.pressed) {
        if (layer_state_is(L_LeftPinky) | layer_state_is(L_RightPinky) | layer_state_is(L_Function) |
          layer_state_is(L_Number) | layer_state_is(L_Cursor)) {
          // reverse side (upper layer)
          if ((get_mods() & MOD_MASK_CAG) == 0) {
            ime_on = true;
            if (get_mods() & MOD_MASK_SHIFT) {
              ime_kk = true;
            } else {
              ime_kk = false;
            }
          }
          tap_code16(KC_LANGUAGE_1);
          return false;
        } else {
          // normal side (base layer)
          if ((get_mods() & MOD_MASK_CSAG) == 0) {
            ime_on = false;
          }
        }
      }
      return true;
  }
  return true;
}

void activate_ime_state_sync(const fast_timer_t now) {
  iss_sync = false;
  if (iss_enable) {
    iss_trigger = now + iss_sync_delay;
  } else {
    iss_trigger = now + (UINT32_MAX / 2) - 1;
  }
}

void update_ime_state_sync(const fast_timer_t now) {
  if (!(timer_expired_fast(now, iss_trigger))) return;

  if (iss_sync == false) {
    iss_sync = true;
    iss_trigger += iss_idle_delay;
  } else {
    ime_on = false;
    iss_sync = false;
    iss_trigger += (UINT32_MAX / 2) - 1;
  }
}

void set_layer_color_overlay_ime_state_sync(void) {
  // use golden angle 255 * phi
  const uint8_t h_diff = 97;
  
  HSV hsv = rgb_matrix_get_hsv();
  hsv.h -= g_rgb_timer >> 4;
  hsv.s = 255;
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  uint8_t speed = rgb_matrix_get_speed(); 
  uint16_t time = scale16by8(g_rgb_timer, speed / 3);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

  // IME state sync syntem state
  if (ime_on) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(44, rgb.r, rgb.g, rgb.b);
    
    if (ime_kk) {
      rgb_matrix_set_color(38, rgb.r, rgb.g, rgb.b);
    } else {
      rgb_matrix_set_color(38, 0, 0, 0);
    }
    
    if (iss_sync) {
      rgb_matrix_set_color(23, rgb.r, rgb.g, rgb.b);
    } else {
      rgb_matrix_set_color(23, 0, 0, 0);
    }
    rgb_matrix_set_color(5, 0, 0, 0);
    rgb_matrix_set_color(11, 0, 0, 0);
    rgb_matrix_set_color(17, 0, 0, 0);
    rgb_matrix_set_color(26, 0, 0, 0);
    rgb_matrix_set_color(32, 0, 0, 0);
  }
}

void set_layer_color_firmware_map_ime_state_sync(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  if (iss_enable) {
    rgb_matrix_set_color(2, 0, f, 0);
    rgb_matrix_set_color(8, o, o, o);
  } else {
    //ANSI base
    rgb_matrix_set_color(2, o, o, o);
    rgb_matrix_set_color(8, f, f, f);
  }
}
