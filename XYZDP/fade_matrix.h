#pragma once

extern void fade_matrix_load_preset(void);
extern void fade_matrix_load_preset_powersave(void);
extern void fade_matrix_set_hue_pos(unit8_t pos);
extern void fade_matrix_set_sat_pos(unit8_t pos);
extern void fade_matrix_set_val_pos(unit8_t pos);
extern void fade_matrix_set_speed_pos(unit8_t pos);

extern void init_fade_matrix(const fast_timer_t now);
extern void update_fade_matrix(const fast_timer_t now);

extern void set_layer_color_firmware_map(void);
extern void set_layer_color_hue_map(void);
extern void set_layer_color_sat_map(void);
extern void set_layer_color_val_map(void);
extern void set_layer_color_speed_map(void);
