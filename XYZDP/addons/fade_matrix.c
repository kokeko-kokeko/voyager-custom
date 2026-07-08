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

// fade color system
static fast_timer_t fade_tamrix_trigger = (UINT32_MAX / 2) - 1;
static const fast_timer_t fade_matrix_activate_delay = 31; // use prime
static const fast_timer_t fade_matrix_activate_dim_key_add_delay = 2003; // when dimmed more slow start-up
static const fast_timer_t fade_matrix_repeat_delay = 7; // use prime
static const fast_timer_t fade_matrix_dimming_delay = 8009; // fixed
static const fast_timer_t fade_matrix_dimming_repeat_add_delay = 12; // fixed
static fast_timer_t fade_matrix_off_delay = 30011; // valiable

// system side rgb
extern rgb_config_t rgb_matrix_config;

// target setting
rgb_config_t fade_matrix_target;
static const uint8_t dimming_value = 31;  // linear val_tbl[-1] value

// flags, means current state 
static bool fade_matrix_active = false;
static bool fade_matrix_dimmed = false;

void activate_fade_matrix(void) {
  const fast_timer_t now = timer_read_fast();

  fade_tamrix_trigger = now + fade_matrix_activate_delay;
  // transfer target to active, set rgb_matrix_config.enacle by api
  fade_matrix_active = fade_matrix_target.enable;
}

void fade_matrix_load_default(void) {
  fade_matrix_target.enable = true;
  fade_matrix_target.hsv.h = 250;
  fade_matrix_target.hsv.s = 128;
  fade_matrix_target.hsv.v = 103;
  fade_matrix_target.speed = 50;
  fade_matrix_target.mode = RGB_MATRIX_FLOWER_BLOOMING;
  
  fade_matrix_off_delay = 600011; // 10 min
}

void fade_matrix_load_powersave(void) {
  fade_matrix_target.enable = true;
  fade_matrix_target.hsv.h = 92;
  fade_matrix_target.hsv.s = 255;
  fade_matrix_target.hsv.v = 70;
  fade_matrix_target.speed = 30;
  fade_matrix_target.mode = RGB_MATRIX_SOLID_COLOR;

  fade_matrix_off_delay = 90001; // use prime
}

bool fade_matrix_rgb_sld_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == false) return false;
  
  fade_matrix_target.mode = RGB_MATRIX_SOLID_COLOR;
  
  // default false
  return false;
}

void fade_matrix_enable(void) {
  rgb_matrix_enable_noeeprom();
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

void fade_matrix_disable(void) {
  fade_matrix_target.enable = false;
  fade_matrix_target.hsv.h = 0;
  fade_matrix_target.hsv.s = 0;
  fade_matrix_target.hsv.v = 0;
  fade_matrix_target.speed = 0;
  fade_matrix_target.mode = RGB_MATRIX_NONE;

  fade_tamrix_trigger = timer_read_fast() + (UINT32_MAX / 2) - 1;
  
  rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
  rgb_matrix_disable_noeeprom();
}

void keyboard_post_init_fade_matrix(void) {
  fade_matrix_enable();
}

bool pre_process_record_fade_matrix(uint16_t keycode, keyrecord_t *record) {
  // first activate
  if (record->event.pressed == false) {
    // release
    activate_fade_matrix();
    if (fade_matrix_dimmed) fade_tamrix_trigger += fade_matrix_activate_dim_key_add_delay;  // keep dim on start up
  }
  return true;
}

bool process_record_fade_matrix(uint16_t keycode, keyrecord_t *record) {
  // RGB inc/dec no eeprom override
  // always return false (sometime use upedge)
  if (keycode == QK_UNDERGLOW_HUE_UP) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.h++;
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_HUE_DOWN) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.h--;
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_SATURATION_UP) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.s = qadd8(fade_matrix_target.hsv.s, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_SATURATION_DOWN) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.s = qsub8(fade_matrix_target.hsv.s, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_VALUE_UP) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.v = qadd8(fade_matrix_target.hsv.v, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_VALUE_DOWN) {
    if (record->event.pressed) {
      fade_matrix_target.hsv.v = qsub8(fade_matrix_target.hsv.v, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_SPEED_UP) {
    if (record->event.pressed) {
      fade_matrix_target.speed = qadd8(fade_matrix_target.speed, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_SPEED_DOWN) {
    if (record->event.pressed) {
      fade_matrix_target.speed = qsub8(fade_matrix_target.speed, 1);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_TOGGLE) {
    if (record->event.pressed) {
      fade_matrix_target.enable = !(fade_matrix_target.enable);
    }
    
    return false;
  }
  
  if (keycode == QK_UNDERGLOW_MODE_NEXT) {
    if (record->event.pressed) {
      fade_matrix_target.mode++;
      if (!(fade_matrix_target.mode < RGB_MATRIX_EFFECT_MAX)) fade_matrix_target.mode = 1;
    }
    
    return false;
  }
  
  return true;
}

bool process_detected_host_os_fade_matrix(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
      fade_matrix_load_default();
      break;
    case OS_IOS:
      fade_matrix_load_powersave();
      break;
    case OS_WINDOWS:
      fade_matrix_load_default();
      break;
    case OS_LINUX:
      fade_matrix_load_powersave();
      break;
    case OS_UNSURE:
      break;
  }
  
  activate_fade_matrix();
  
  return true;
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

  // timer
  if (timer_expired_fast(now, fade_tamrix_trigger) == false) return;
  fade_tamrix_trigger += fade_matrix_repeat_delay;
  
  if (fade_matrix_active == true) {
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
      fade_matrix_dimmed = false;
      fade_tamrix_trigger += fade_matrix_dimming_delay;
    }
  } else if (fade_matrix_dimmed == false) {
    // not dim, do dimming mode
    if (layer_state_is(LAYER_Color_Palette)) {
      // if palette enable skip
      fade_tamrix_trigger += fade_matrix_dimming_delay;
    } else if (rgb_matrix_config.hsv.v > dimming_value) {
      rgb_matrix_config.hsv.v--;
      fade_tamrix_trigger += fade_matrix_dimming_repeat_add_delay;
    } else {
      fade_matrix_dimmed = true;
      fade_tamrix_trigger += fade_matrix_off_delay;
    }
  } else {
    // rgb to disable
    if (rgb_matrix_config.hsv.s != 0) {
      rgb_matrix_config.hsv.s--;
    } else if (rgb_matrix_config.hsv.v != 0) {
      rgb_matrix_config.hsv.v--;
    } else {
      fade_tamrix_trigger = now + (UINT32_MAX / 2) - 1;
      fade_matrix_dimmed = false;
      rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
      rgb_matrix_disable_noeeprom();
    }
  }
}
