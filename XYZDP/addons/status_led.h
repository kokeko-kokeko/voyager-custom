#pragma once

extern const uint8_t led_pattern_off[];
extern const uint8_t led_pattern_on[];
extern const uint8_t led_pattern_blink[];
extern const uint8_t led_pattern_single[];
extern const uint8_t led_pattern_oneshot[];
extern const uint8_t led_pattern_delayed_on[];

extern const uint8_t led_pattern_boot0[];
extern const uint8_t led_pattern_boot1[];
extern const uint8_t led_pattern_boot2[];
extern const uint8_t led_pattern_boot3[];

void status_led(const uint8_t mask, const uint8_t * const pattern);
void pop_status_led(const uint8_t mask);

void keyboard_post_init_status_led(void);
bool process_detected_host_os_status_led(os_variant_t detected_os);
layer_state_t layer_state_set_status_led(layer_state_t state);
void housekeeping_task_status_led(void);
