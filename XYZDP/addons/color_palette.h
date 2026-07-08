#pragma once

bool color_palette_main_keyrecord(const keyrecord_t * const record);
bool color_palette_select_keyrecord(const keyrecord_t * const record);

layer_state_t layer_state_set_color_palette(layer_state_t state);

bool rgb_matrix_indicators_color_palette(void);
