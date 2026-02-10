#pragma once

bool firmware_map_set_keyrecord(const keyrecord_t * const record);

void set_layer_color_firmware_map(void);

bool firmware_map_enter_hue_keyrecord(const keyrecord_t * const record);
bool firmware_map_enter_halt_keyrecord(const keyrecord_t * const record);
bool firmware_map_exit_all_keyrecord(const keyrecord_t * const record);

bool halt_map_set_keyrecord(const keyrecord_t * const record);

void set_layer_color_halt_map(void);
