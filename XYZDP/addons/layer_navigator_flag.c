#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "virt_layer.h"
 
#include "addons/layer_navigator_flag.h"

#include "navigator.h"

static uint8_t scroll_layers[] = {VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_thumb_1, VIRT_LAYER_L_thumb_2, VIRT_LAYER_Mouse_L};
static uint8_t aim_layers[] = {VIRT_LAYER_L_thumb_2, VIRT_LAYER_R_thumb_1};
static uint8_t turbo_layers[] = {VIRT_LAYER_L_pinky_1, VIRT_LAYER_R_pinky_2, VIRT_LAYER_L_thumb_2};

#define SCROLL_LAYER_COUNT (sizeof(scroll_layers) / sizeof(scroll_layers[0]))
#define AHM_LAYER_COUNT (sizeof(aim_layers) / sizeof(aim_layers[0]))
#define TURBO_LAYER_COUNT (sizeof(turbo_layers) / sizeof(turbo_layers[0]))

void keyboard_post_init_layer_navigator_flag(void) {
    virt_layer_on(VIRT_LAYER_navigator_base_scroll);
    virt_layer_off(VIRT_LAYER_navigator_base_aim);
    virt_layer_off(VIRT_LAYER_navigator_base_turbo);
}

layer_state_t layer_state_set_layer_navigator_flag(layer_state_t state) {
    if (get_highest_virt_layer(state) < VIRT_LAYER_Flag_END) {
        set_scrolling = virt_layer_state_cmp(state, VIRT_LAYER_navigator_base_scroll);
        scroll_vertical_only = false;
        navigator_aim = virt_layer_state_cmp(state, VIRT_LAYER_navigator_base_aim);;
        navigator_turbo = virt_layer_state_cmp(state, VIRT_LAYER_navigator_base_turbo);;

        return state;
    }

    bool t_scrolling = false;
    bool t_aim = false;
    bool t_turbo = false;

    for (int i = 0; i < SCROLL_LAYER_COUNT; i++) {
        t_scrolling = t_scrolling || virt_layer_state_cmp(state, scroll_layers[i]);
    }

    for (int i = 0; i < AHM_LAYER_COUNT; i++) {
        t_aim = t_aim || virt_layer_state_cmp(state, aim_layers[i]);
    }

    for (int i = 0; i < TURBO_LAYER_COUNT; i++) {
        t_turbo = t_turbo || virt_layer_state_cmp(state, turbo_layers[i]);
    }

    set_scrolling = t_scrolling;
    navigator_aim = t_aim;
    navigator_turbo = t_turbo;

    return state;
}