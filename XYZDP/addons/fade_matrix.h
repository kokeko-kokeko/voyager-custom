#pragma once

uint8_t get_pos_from_keyrecord(const keyrecord_t * const record);

bool fade_matrix_rgb_sld_keyrecord(const keyrecord_t * const record);
bool fade_matrix_set_hue_keyrecord(const keyrecord_t * const record);
bool fade_matrix_set_sat_keyrecord(const keyrecord_t * const record);
bool fade_matrix_set_val_keyrecord(const keyrecord_t * const record);
bool fade_matrix_set_speed_keyrecord(const keyrecord_t * const record);
bool fade_matrix_load_preset_keyrecord(const keyrecord_t * const record);
bool fade_matrix_load_preset_powersave_keyrecord(const keyrecord_t * const record);

void keyboard_post_init_fade_matrix(void);
bool process_record_fade_matrix(uint16_t keycode, keyrecord_t *record);
bool process_detected_host_os_fade_matrix(os_variant_t detected_os);
report_mouse_t pointing_device_task_fade_matrix(report_mouse_t mouse_report);
layer_state_t layer_state_set_fade_matrix(layer_state_t state);
void housekeeping_task_fade_matrix(void);

void set_layer_color_hue_map(void);
void set_layer_color_sat_map(void);
void set_layer_color_val_map(void);
void set_layer_color_speed_map(void);
