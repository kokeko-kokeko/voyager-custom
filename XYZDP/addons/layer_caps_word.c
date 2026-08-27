#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/layer_caps_word.h"

// enter layer, no key press, exit run caps word
static uint8_t caps_layers[] = {LAYER_L_thumb_3, LAYER_R_thumb_3};

#define CAPS_LAYER_COUNT (sizeof(caps_layers) / sizeof(caps_layers[0]))

static bool layer_active[CAPS_LAYER_COUNT] = {false};
static bool key_pressed[CAPS_LAYER_COUNT] = {false};

bool pre_process_record_layer_caps_word(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        for (int i = 0; i < CAPS_LAYER_COUNT; i++) {
            key_pressed[i] = true;    
        }
    }

    return true;
}

layer_state_t layer_state_set_layer_caps_word(layer_state_t state) {
    for (int i = 0; i < CAPS_LAYER_COUNT; i++) {
        if (layer_state_cmp(state, caps_layers[i]) == layer_active[i]) continue;
        layer_active[i] = !(layer_active[i]);

        if (layer_active[i]) {
            // enter layer
            key_pressed[i] = false; 
        } else {
            // leave layer
            if (key_pressed[i] == false) {
                // non key press, caps word
                caps_word_on();
            }
        }
    }

    return state;
}
