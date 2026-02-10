#pragma once

extern const uint8_t led_pattern_off[];
extern const uint8_t led_pattern_on[];
extern const uint8_t led_pattern_blink[];
extern const uint8_t led_pattern_single[];
extern const uint8_t led_pattern_oneshot[];

void status_led(const uint8_t mask, const uint8_t * const pattern);

void keyboard_post_init_status_led(void);
void housekeeping_task_status_led(void);
