#pragma once

extern uint8_t get_pos_from_keyrecord(const keyrecord_t * const record);

extern void fade_matrix_set_mode(const uint8_t mode);
extern void fade_matrix_set_hue_pos(const uint8_t pos);
extern void fade_matrix_set_sat_pos(const uint8_t pos);
extern void fade_matrix_set_val_pos(const uint8_t pos);
extern void fade_matrix_set_speed_pos(const uint8_t pos);

extern void fade_matrix_increase_hue(void);
extern void fade_matrix_decrease_hue(void);
extern void fade_matrix_increase_sat(void);
extern void fade_matrix_decrease_sat(void);
extern void fade_matrix_increase_val(void);
extern void fade_matrix_decrease_val(void);
extern void fade_matrix_increase_speed(void);
extern void fade_matrix_decrease_speed(void);
extern void fade_matrix_toggle(void);
extern void fade_matrix_step(void);

extern void fade_matrix_load_preset(void);
extern void fade_matrix_load_preset_powersave(void);

extern void init_fade_matrix(const fast_timer_t now);
extern void activate_fade_matrix(const fast_timer_t now);
extern void update_fade_matrix(const fast_timer_t now);

extern void set_layer_color_hue_map(void);
extern void set_layer_color_sat_map(void);
extern void set_layer_color_val_map(void);
extern void set_layer_color_speed_map(void);
extern void set_layer_color_halt_map(void);

extern void set_layer_color_firmware_map(void);

extern void set_layer_color_mouse_map(void);
