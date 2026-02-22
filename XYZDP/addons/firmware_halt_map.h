#pragma once

bool firmware_map_main_keyrecord(const keyrecord_t * const record);

void set_layer_color_firmware_map(void);

bool firmware_map_enter_color_palette_keyrecord(const keyrecord_t * const record);
bool firmware_map_exit_all_keyrecord(const keyrecord_t * const record);

bool firmware_map_invoke_halt_keyrecord(const keyrecord_t * const record);

void housekeeping_task_exec_halt(void);
