#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "status_led.h"

// timer maximum delay
// #define timer_expired32(current, future) ((uint32_t)(current - future) < UINT32_MAX / 2)
// write direct

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

typedef struct status_led_state {
  fast_timer_t trigger;
  const uint8_t * ptr;
  // 3-level pattern stack
  const uint8_t * ptr_0;
  const uint8_t * ptr_1;
  const uint8_t * ptr_2;
  void (*const out_func)(const bool);
  bool out_val;
  uint8_t scale;
} status_led_state_t;

static void status_led_out_func_1(const bool out_val) { STATUS_LED_1(out_val); }
static void status_led_out_func_2(const bool out_val) { STATUS_LED_2(out_val); }
static void status_led_out_func_3(const bool out_val) { STATUS_LED_3(out_val); }
static void status_led_out_func_4(const bool out_val) { STATUS_LED_4(out_val); }

static status_led_state_t status_led_state_1 = {(UINT32_MAX / 2) - 1, led_pattern_off, led_pattern_off, led_pattern_off, led_pattern_off, status_led_out_func_1, false, 0};
static status_led_state_t status_led_state_2 = {(UINT32_MAX / 2) - 1, led_pattern_off, led_pattern_off, led_pattern_off, led_pattern_off, status_led_out_func_2, false, 0};
static status_led_state_t status_led_state_3 = {(UINT32_MAX / 2) - 1, led_pattern_off, led_pattern_off, led_pattern_off, led_pattern_off, status_led_out_func_3, false, 0};
static status_led_state_t status_led_state_4 = {(UINT32_MAX / 2) - 1, led_pattern_off, led_pattern_off, led_pattern_off, led_pattern_off, status_led_out_func_4, false, 0};

static void status_led_set_func(status_led_state_t * const state, const fast_timer_t now, const uint8_t * const pattern) {
  state->trigger = now;
  state->ptr_2 = state->ptr_1;
  state->ptr_1 = state->ptr_0;
  state->ptr_0 = pattern;
    
  state->ptr = state->ptr_0;
  state->out_val = *(state->ptr++);
  state->scale = *(state->ptr++);

  return;
}

static void status_led_update_func(status_led_state_t * const state, const fast_timer_t now) {
  if (!(timer_expired_fast(now, state->trigger))) return;

  if (*(state->ptr) == UINT8_MAX) {
    state->ptr = state->ptr_0;
    state->out_val = *(state->ptr++);
    state->scale = *(state->ptr++);
  } else if (*(state->ptr) == UINT8_MAX - 1) {
    state->ptr_0 = state->ptr_1;
    state->ptr_1 = state->ptr_2;
    state->ptr_2 = led_pattern_off;

    state->ptr = state->ptr_0;
    state->out_val = *(state->ptr++);
    state->scale = *(state->ptr++);
  }
  
  state->out_func(state->out_val);
  state->out_val = !(state->out_val);

  fast_timer_t delay = *(state->ptr++);
  if (delay == 0) {
    delay = (UINT32_MAX / 2) - 1;
  } else {
    delay <<= state->scale;
  }
  state->trigger += delay;
  
  return;
}

// 1 -> Red Left
// 3 -> Red Right
// 2 -> Green Left
// 4 -> Green Right
// re-order bit position
void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern) {
  if (pattern == NULL) return;
  
  //add prime pseudo rendom start
  if (mask & 0b1000) {
    status_led_set_func(&status_led_state_1, now + 2, pattern);
  }
  if (mask & 0b0100) {
    status_led_set_func(&status_led_state_3, now + 3, pattern);
  }
  if (mask & 0b0010) {
    status_led_set_func(&status_led_state_2, now + 5, pattern);
  }
  if (mask & 0b0001) {
    status_led_set_func(&status_led_state_4, now + 7, pattern);
  }
  return;
}

void update_status_led(const fast_timer_t now) {
  status_led_update_func(&status_led_state_1, now);
  status_led_update_func(&status_led_state_3, now);
  status_led_update_func(&status_led_state_2, now);
  status_led_update_func(&status_led_state_4, now);
  return;
}
