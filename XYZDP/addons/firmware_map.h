#pragma once

void firmware_map_set_keyrecord(const keyrecord_t * const record);
void firmware_map_enter_hue_keyrecord(const keyrecord_t * const record);
void firmware_map_enter_halt_keyrecord(const keyrecord_t * const record);
void firmware_map_exit_all_keyrecord(const keyrecord_t * const record);

void set_layer_color_firmware_map(void);

void halt_map_set_keyrecord(const keyrecord_t * const record);

void set_layer_color_halt_map(void);
