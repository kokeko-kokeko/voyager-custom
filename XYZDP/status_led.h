#pragma once

const uint8_t led_pattern_off[];
const uint8_t led_pattern_on[];
const uint8_t led_pattern_blink[];
const uint8_t led_pattern_single[];
const uint8_t led_pattern_oneshot[];

void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern);
void update_status_led(const fast_timer_t now);
