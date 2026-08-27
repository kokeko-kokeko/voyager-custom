#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/layer_caps_word.h"

// enter layer, no key press, exit run caps word


bool pre_process_record_layer_caps_word(uint16_t keycode, keyrecord_t *record) {
    return true;
}

layer_state_t layer_state_set_layer_caps_word(layer_state_t state) {

    return state;
}
