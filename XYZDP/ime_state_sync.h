#pragma once

extern void ime_state_sync_enable(void);
extern void ime_state_sync_disable(void);

extern bool pre_process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record);
extern bool process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record);

extern void activate_ime_state_sync(const fast_timer_t now);
extern void update_ime_state_sync(const fast_timer_t now);

extern void set_layer_color_overlay_ime_state_sync(void);

extern void set_layer_color_firmware_map_ime_state_sync(void);
