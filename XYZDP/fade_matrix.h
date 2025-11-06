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

void init_fade_matrix(const fast_timer_t now);
void activate_fade_matrix(const fast_timer_t now);
void update_fade_matrix(const fast_timer_t now);

void set_layer_color_hue_map(void);
void set_layer_color_sat_map(void);
void set_layer_color_val_map(void);
void set_layer_color_speed_map(void);
void set_layer_color_halt_map(void);

void set_layer_color_firmware_map(void);

void set_layer_color_mouse_map(void);
