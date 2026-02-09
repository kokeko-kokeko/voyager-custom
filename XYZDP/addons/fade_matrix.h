#pragma once

uint8_t get_pos_from_keyrecord(const keyrecord_t * const record);

void fade_matrix_set_mode(const uint8_t mode);
void fade_matrix_set_hue_keyrecord(const keyrecord_t * const record);
void fade_matrix_set_sat_keyrecord(const keyrecord_t * const record);
void fade_matrix_set_val_keyrecord(const keyrecord_t * const record);
void fade_matrix_set_speed_keyrecord(const keyrecord_t * const record);

void fade_matrix_increase_hue(void);
void fade_matrix_decrease_hue(void);
void fade_matrix_increase_sat(void);
void fade_matrix_decrease_sat(void);
void fade_matrix_increase_val(void);
void fade_matrix_decrease_val(void);
void fade_matrix_increase_speed(void);
void fade_matrix_decrease_speed(void);
void fade_matrix_toggle(void);
void fade_matrix_step(void);

void fade_matrix_load_preset(void);
void fade_matrix_load_preset_powersave(void);

void keyboard_post_init_fade_matrix(void);
bool process_record_fade_matrix(uint16_t keycode, keyrecord_t *record);
void post_process_record_fade_matrix(uint16_t keycode, keyrecord_t *record);
report_mouse_t pointing_device_task_fade_matrix(report_mouse_t mouse_report);
layer_state_t layer_state_set_fade_matrix(layer_state_t state);
void housekeeping_task_fade_matrix(void);

void set_layer_color_hue_map(void);
void set_layer_color_sat_map(void);
void set_layer_color_val_map(void);
void set_layer_color_speed_map(void);
