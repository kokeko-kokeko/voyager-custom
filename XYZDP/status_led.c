#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "status_led.h"

static const fast_timer_t maximum_delay = (UINT32_MAX / 2) - 14400000;

// status LED pattern list, no const limit, terminate symbol
// init value, scale, delay, delay, ...
// delay reduce data with shift by scale value
// 0: terminate, stop exec
// MAX: restart pattern 
// MAX - 1: move to before patten (stack)
const uint8_t led_pattern_off[] = {0, 0, 0, UINT8_MAX, UINT8_MAX};
const uint8_t led_pattern_on[] = {1, 0, 0, UINT8_MAX, UINT8_MAX};
const uint8_t led_pattern_blink[] = {1, 2, 125, 62, UINT8_MAX, UINT8_MAX};
const uint8_t led_pattern_single[] = {1, 2, 125, 0, UINT8_MAX, UINT8_MAX};
const uint8_t led_pattern_oneshot[] = {1, 1, 200, 50, 200, 50, 200, 50, 200, 50, 200, 50, 200, 50, 200, 50, 200, 50, UINT8_MAX - 1 , UINT8_MAX - 1};
//static const uint8_t * const led_pattern_heartbeat = (uint8_t[]){250, 125, UINT8_MAX, UINT8_MAX, UINT8_MAX};

typedef struct PACKED {
  // 3-level pattern stack
  const uint8_t * ptr_2;
  const uint8_t * ptr_1;
  const uint8_t * ptr_0;
  const uint8_t * ptr;
  fast_timer_t trigger;
  void (*out_func)(bool);
  bool out_val;
  uint8_t scale;
} status_led_state_t;

static void out_func_status_1(bool out_val) {
  STATUS_LED_1(out_val);
}

static void out_func_status_2(bool out_val) {
  STATUS_LED_2(out_val);
}

static void out_func_status_3(bool out_val) {
  STATUS_LED_3(out_val);
}

static void out_func_status_4(bool out_val) {
  STATUS_LED_4(out_val);
}

static status_led_state_t status_led_state_1 = {led_pattern_off, led_pattern_off, led_pattern_off, led_pattern_off, maximum_delay, out_func_status_1, false, 0}

static void status_led_task_1(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t trigger = 0;
  // 3-level pattern stack
  static const uint8_t * ptr_2 = led_pattern_off;
  static const uint8_t * ptr_1 = led_pattern_off;
  static const uint8_t * ptr_0 = led_pattern_off;
  static const uint8_t * ptr = led_pattern_off;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_2 = ptr_1;
    ptr_1 = ptr_0;
    ptr_0 = pattern;
    
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  } else if (*ptr == UINT8_MAX - 1) {
    ptr_0 = ptr_1;
    ptr_1 = ptr_2;
    ptr_2 = led_pattern_off;

    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_1(out_val);
  out_val = !out_val;

  fast_timer_t delay = *(ptr++);
  if (delay == 0) {
    delay = maximum_delay;
  } else {
    delay <<= scale;
  }
  trigger += delay;
  
  return;
}

static void status_led_task_2(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t trigger = 0;
  // 3-level pattern stack
  static const uint8_t * ptr_2 = led_pattern_off;
  static const uint8_t * ptr_1 = led_pattern_off;
  static const uint8_t * ptr_0 = led_pattern_off;
  static const uint8_t * ptr = led_pattern_off;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_2 = ptr_1;
    ptr_1 = ptr_0;
    ptr_0 = pattern;
    
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  } else if (*ptr == UINT8_MAX - 1) {
    ptr_0 = ptr_1;
    ptr_1 = ptr_2;
    ptr_2 = led_pattern_off;

    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_2(out_val);
  out_val = !out_val;

  fast_timer_t delay = *(ptr++);
  if (delay == 0) {
    delay = maximum_delay;
  } else {
    delay <<= scale;
  }
  trigger += delay;
  
  return;
}

static void status_led_task_3(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t trigger = 0;
  // 3-level pattern stack
  static const uint8_t * ptr_2 = led_pattern_off;
  static const uint8_t * ptr_1 = led_pattern_off;
  static const uint8_t * ptr_0 = led_pattern_off;
  static const uint8_t * ptr = led_pattern_off;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_2 = ptr_1;
    ptr_1 = ptr_0;
    ptr_0 = pattern;
    
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  } else if (*ptr == UINT8_MAX - 1) {
    ptr_0 = ptr_1;
    ptr_1 = ptr_2;
    ptr_2 = led_pattern_off;

    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_3(out_val);
  out_val = !out_val;

  fast_timer_t delay = *(ptr++);
  if (delay == 0) {
    delay = maximum_delay;
  } else {
    delay <<= scale;
  }
  trigger += delay;
  
  return;
}

static void status_led_task_4(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t trigger = 0;
  // 3-level pattern stack
  static const uint8_t * ptr_2 = led_pattern_off;
  static const uint8_t * ptr_1 = led_pattern_off;
  static const uint8_t * ptr_0 = led_pattern_off;
  static const uint8_t * ptr = led_pattern_off;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_2 = ptr_1;
    ptr_1 = ptr_0;
    ptr_0 = pattern;
    
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  } else if (*ptr == UINT8_MAX - 1) {
    ptr_0 = ptr_1;
    ptr_1 = ptr_2;
    ptr_2 = led_pattern_off;

    ptr = ptr_0;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_4(out_val);
  out_val = !out_val;

  fast_timer_t delay = *(ptr++);
  if (delay == 0) {
    delay = maximum_delay;
  } else {
    delay <<= scale;
  }
  trigger += delay;
  
  return;
}

// 1 -> Red Left
// 3 -> Red Right
// 2 -> Green Left
// 4 -> Green Right
// re-order bit position
void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern) {
  //add prime pseudo rendom start
  if (mask & 0b1000) {
    status_led_task_1(now + 2, pattern);
  }
  if (mask & 0b0100) {
    status_led_task_3(now + 3, pattern);
  }
  if (mask & 0b0010) {
    status_led_task_2(now + 5, pattern);
  }
  if (mask & 0b0001) {
    status_led_task_4(now + 7, pattern);
  }
  return;
}

void update_status_led(const fast_timer_t now) {
  status_led_task_1(now, NULL);
  status_led_task_3(now, NULL);
  status_led_task_2(now, NULL);
  status_led_task_4(now, NULL);
  return;
}
