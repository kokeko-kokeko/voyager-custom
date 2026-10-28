#pragma once

void keyboard_post_init_layer_caps_word(void);
bool pre_process_record_layer_caps_word(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_layer_caps_word(layer_state_t state);
