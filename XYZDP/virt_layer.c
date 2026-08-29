#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "phys_layer.h"
#include "virt_layer.h"

// virt to phys translate table
static const uint8_t v_to_p_tbl[VIRT_LAYER_COUNT] = {
    [VIRT_LAYER_Transition] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_FB_JIS] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_FB_Mac] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_FB_error] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_ISS_Enable] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_navigator_base_scroll] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_navigator_base_aim] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_navigator_base_turbo] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_Flag_END] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_Mouse_L] = PHYS_LAYER_Mouse_L,
    [VIRT_LAYER_Mouse_R] = PHYS_LAYER_Mouse_R,

    [VIRT_LAYER_L_thumb_1] = PHYS_LAYER_Number,
    [VIRT_LAYER_L_thumb_2] = PHYS_LAYER_Fucction,
    [VIRT_LAYER_L_thumb_3] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_L_thumb_4] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_R_thumb_1] = PHYS_LAYER_Cursor,
    [VIRT_LAYER_R_thumb_3] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_2] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_4] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_L_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_L_pinky_2] = PHYS_LAYER_QWERTY_Shortcut,

    [VIRT_LAYER_R_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_pinky_2] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_Mouse_Upper_L] = PHYS_LAYER_Mouse_Upper_L,
    [VIRT_LAYER_Mouse_Upper_R] = PHYS_LAYER_Mouse_Upper_R, 

    [VIRT_LAYER_L_thumb_1_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_L_thumb_1_pinky_2] = PHYS_LAYER_UNALLOC,
  
    [VIRT_LAYER_R_thumb_1_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_1_pinky_2] = PHYS_LAYER_Print_Screen,
 
    [VIRT_LAYER_L_thumb_1_R_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_L_thumb_1_R_pinky_2] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_R_thumb_1_L_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_1_L_pinky_2] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_LR_thumb_1] = PHYS_LAYER_Macro,
    [VIRT_LAYER_LR_thumb_2] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_LR_thumb_3] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_LR_thumb_4] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_LR_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_LR_pinky_2] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_Firmware] = PHYS_LAYER_Firmware,
    [VIRT_LAYER_Color_Palette] = PHYS_LAYER_Color_Palette 
};

// tri layer combination table, all entry virt layer number
// 0 and 1 both on -> 2 on
// multi entry result is or
static const uint8_t tri_layer_tbl_v_v_v[][3] = {
    // mouse upper
    {VIRT_LAYER_Mouse_L, VIRT_LAYER_L_pinky_1, VIRT_LAYER_Mouse_Upper_L},
    {VIRT_LAYER_Mouse_L, VIRT_LAYER_L_pinky_2, VIRT_LAYER_Mouse_Upper_L},
    {VIRT_LAYER_Mouse_R, VIRT_LAYER_L_pinky_1, VIRT_LAYER_Mouse_Upper_L},
    {VIRT_LAYER_Mouse_R, VIRT_LAYER_L_pinky_2, VIRT_LAYER_Mouse_Upper_L},

    {VIRT_LAYER_Mouse_L, VIRT_LAYER_R_pinky_1, VIRT_LAYER_Mouse_Upper_R},
    {VIRT_LAYER_Mouse_L, VIRT_LAYER_R_pinky_2, VIRT_LAYER_Mouse_Upper_R},
    {VIRT_LAYER_Mouse_R, VIRT_LAYER_R_pinky_1, VIRT_LAYER_Mouse_Upper_R},
    {VIRT_LAYER_Mouse_R, VIRT_LAYER_R_pinky_2, VIRT_LAYER_Mouse_Upper_R},

    // same side thumb and pin
    {VIRT_LAYER_L_thumb_1, VIRT_LAYER_L_pinky_1, VIRT_LAYER_L_thumb_1_pinky_1},
    {VIRT_LAYER_L_thumb_1, VIRT_LAYER_L_pinky_2, VIRT_LAYER_L_thumb_1_pinky_2},

    {VIRT_LAYER_R_thumb_1, VIRT_LAYER_R_pinky_1, VIRT_LAYER_R_thumb_1_pinky_1},
    {VIRT_LAYER_R_thumb_1, VIRT_LAYER_R_pinky_2, VIRT_LAYER_R_thumb_1_pinky_2},

    // cross side thumb and pin
    {VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_pinky_1, VIRT_LAYER_L_thumb_1_R_pinky_1},
    {VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_pinky_2, VIRT_LAYER_L_thumb_1_R_pinky_2},

    {VIRT_LAYER_R_thumb_1, VIRT_LAYER_L_pinky_1, VIRT_LAYER_R_thumb_1_L_pinky_1},
    {VIRT_LAYER_R_thumb_1, VIRT_LAYER_L_pinky_2, VIRT_LAYER_R_thumb_1_L_pinky_2},

    // both thumb
    {VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_thumb_1, VIRT_LAYER_LR_thumb_1},
    {VIRT_LAYER_L_thumb_2, VIRT_LAYER_R_thumb_2, VIRT_LAYER_LR_thumb_2},
    {VIRT_LAYER_L_thumb_3, VIRT_LAYER_R_thumb_3, VIRT_LAYER_LR_thumb_3},
    {VIRT_LAYER_L_thumb_4, VIRT_LAYER_R_thumb_4, VIRT_LAYER_LR_thumb_4},

    // both pinky
    {VIRT_LAYER_L_pinky_1, VIRT_LAYER_R_pinky_1, VIRT_LAYER_LR_pinky_1},
    {VIRT_LAYER_L_pinky_2, VIRT_LAYER_R_pinky_2, VIRT_LAYER_LR_pinky_2},

    // fwsys
    {VIRT_LAYER_L_thumb_2, VIRT_LAYER_L_thumb_3, VIRT_LAYER_Firmware}
};

#define TRI_STATE_COUNT (sizeof(tri_layer_tbl_v_v_v) / sizeof(tri_layer_tbl_v_v_v[0]))

// virt layer number state cache, update on layer_state_set_
static bool state_cache_v[VIRT_LAYER_COUNT] = {0};

bool virt_layer_state_is(const uint8_t virt_layer) {
    // layer_state_set_ outside use cache value
    return state_cache_v[virt_layer];
}

bool virt_layer_state_cmp(layer_state_t state, const uint8_t virt_layer) {
    const uint8_t phys_layer = v_to_p_tbl[virt_layer];

    if (phys_layer == PHYS_LAYER_UNALLOC) {
        return state_cache_v[virt_layer];
    } 
    
    // layer_state_set_ inside update cache value from phys state
    state_cache_v[virt_layer] = layer_state_cmp(state, phys_layer);
    return state_cache_v[virt_layer];
}

uint8_t get_highest_virt_layer(const layer_state_t state) {
    for (int i = VIRT_LAYER_COUNT - 1; i >= 0; i--) {
        if (virt_layer_state_cmp(state, i)) return (uint8_t)i;
    }
    return 0;
}

void virt_layer_on(const uint8_t virt_layer) {
    const uint8_t phys_layer = v_to_p_tbl[virt_layer];
    state_cache_v[virt_layer] = true;

    if (phys_layer == PHYS_LAYER_UNALLOC) {
        // re-calc layer_state_set_*
        // or 0 -> no change
        layer_or(0);
    } else {
        layer_on(phys_layer);
    }
}

void virt_layer_off(const uint8_t virt_layer) {
    const uint8_t phys_layer = v_to_p_tbl[virt_layer];
    state_cache_v[virt_layer] = false;

    if (phys_layer == PHYS_LAYER_UNALLOC) {
        // re-calc layer_state_set_*
        // or 0 -> no change
        layer_or(0);
    } else {
        layer_off(phys_layer);
    }
}

layer_state_t layer_state_set_virt_layer(layer_state_t state) {
    // tri state update flag memory
    bool t_state[VIRT_LAYER_COUNT] = {0};
    bool t_update[VIRT_LAYER_COUNT] = {0};
    
    // scan combination
    for (int i = 0; i < TRI_STATE_COUNT; i++) {
        t_state[tri_layer_tbl_v_v_v[i][2]] = t_state[tri_layer_tbl_v_v_v[i][2]] ||
        (
            virt_layer_state_cmp(state, tri_layer_tbl_v_v_v[i][0]) &&
            virt_layer_state_cmp(state, tri_layer_tbl_v_v_v[i][1]) 
        );
        
        t_update[tri_layer_tbl_v_v_v[i][2]] = true; 
    }

    // apply update
    for (int i = 0; i < VIRT_LAYER_COUNT; i++) {
        if (t_update[i] == false) {
            // update cache from phys, dummy read
            virt_layer_state_cmp(state, i);
            continue;
        }

        const uint8_t phys_layer = v_to_p_tbl[i];
        state_cache_v[i] = t_state[i];
        
        if (phys_layer == PHYS_LAYER_UNALLOC) continue;

        if (t_state[i]) {
            state |= ((layer_state_t)1 << phys_layer);
        } else {
            state &= ~((layer_state_t)1 << phys_layer);
        }
    }

    // safe guard, LSB layer on here
    state |= (layer_state_t)0x01;
    
    return state;
}