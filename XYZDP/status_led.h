#pragma once


extern void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern);
extern void update_status_led(const fast_timer_t now);
