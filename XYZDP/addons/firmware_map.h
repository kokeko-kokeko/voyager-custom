#pragma once

bool firmware_map_main_keyrecord(const keyrecord_t * const record);

void set_layer_color_firmware_map(void);

//bool firmware_map_enter_color_palette_keyrecord(const keyrecord_t * const record);
//bool firmware_map_exit_all_keyrecord(const keyrecord_t * const record);

bool firmware_map_invoke_halt_keyrecord(const keyrecord_t * const record);

layer_state_t layer_state_set_firmware_map(const layer_state_t state);

void housekeeping_task_exec_halt(void);
void keyboard_post_init_addtional_power_setting(void);



