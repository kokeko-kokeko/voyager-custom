#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "phys_layer.h"
#include "virt_layer.h"

bool virt_layer_state_is(uint8_t virt_layer) {
    return false;
}
bool virt_layer_state_cmp(layer_state_t phys_state, uint8_t virt_layer) {
    return false;
}

uint8_t get_highest_virt_layer(layer_state_t phys_state) {
    return 0;
}

void virt_layer_on(uint8_t virt_layer) {

}
void virt_layer_off(uint8_t virt_layer) {
    
}

layer_state_t layer_state_set_virt_layer(layer_state_t state) {


    return state;
}