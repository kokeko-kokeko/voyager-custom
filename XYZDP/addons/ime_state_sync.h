#pragma once

void ime_state_sync_enable(void);
void ime_state_sync_disable(void);

bool pre_process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record);
bool process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record);
void post_process_record_ime_state_sync(uint16_t keycode, keyrecord_t *record);
void housekeeping_task_ime_state_sync(void);

void set_layer_color_overlay_ime_state_sync(void);

void set_layer_color_firmware_map_ime_state_sync(void);
