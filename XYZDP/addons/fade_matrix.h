#pragma once

bool fade_matrix_rgb_sld_keyrecord(const keyrecord_t * const record);

bool fade_matrix_color_palette_main_keyrecord(const keyrecord_t * const record);

bool fade_matrix_color_palette_select_keyrecord(const keyrecord_t * const record);

void fade_matrix_enable(void);
void fade_matrix_disable(void);

void keyboard_post_init_fade_matrix(void);
bool pre_process_record_fade_matrix(uint16_t keycode, keyrecord_t *record);
bool process_record_fade_matrix(uint16_t keycode, keyrecord_t *record);
bool process_detected_host_os_fade_matrix(os_variant_t detected_os);
report_mouse_t pointing_device_task_fade_matrix(report_mouse_t mouse_report);
layer_state_t layer_state_set_fade_matrix(layer_state_t state);
void housekeeping_task_fade_matrix(void);

bool rgb_matrix_indicators_fade_matrix(void);

