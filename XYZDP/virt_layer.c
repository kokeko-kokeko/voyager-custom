#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "phys_layer.h"
#include "virt_layer.h"

// virt to phys translate table
// virt only one key, phys can multi
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
    [VIRT_LAYER_R_thumb_2] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_3] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_thumb_4] = PHYS_LAYER_UNALLOC,

    [VIRT_LAYER_L_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_L_pinky_2] = PHYS_LAYER_QWERTY_Shortcut,

    [VIRT_LAYER_R_pinky_1] = PHYS_LAYER_UNALLOC,
    [VIRT_LAYER_R_pinky_2] = PHYS_LAYER_QWERTY_Shortcut,

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
// 1 and 2 both on -> 0 on
// multi entry result is or
static const uint8_t tri_layer_tbl_v_v_v[][3] = {
    // mouse upper
    {VIRT_LAYER_Mouse_Upper_L, VIRT_LAYER_Mouse_L, VIRT_LAYER_L_pinky_1},
    {VIRT_LAYER_Mouse_Upper_L, VIRT_LAYER_Mouse_L, VIRT_LAYER_L_pinky_2},
    {VIRT_LAYER_Mouse_Upper_L, VIRT_LAYER_Mouse_R, VIRT_LAYER_L_pinky_1},
    {VIRT_LAYER_Mouse_Upper_L, VIRT_LAYER_Mouse_R, VIRT_LAYER_L_pinky_2},
    
    {VIRT_LAYER_Mouse_Upper_R, VIRT_LAYER_Mouse_L, VIRT_LAYER_R_pinky_1},
    {VIRT_LAYER_Mouse_Upper_R, VIRT_LAYER_Mouse_L, VIRT_LAYER_R_pinky_2},
    {VIRT_LAYER_Mouse_Upper_R, VIRT_LAYER_Mouse_R, VIRT_LAYER_R_pinky_1},
    {VIRT_LAYER_Mouse_Upper_R, VIRT_LAYER_Mouse_R, VIRT_LAYER_R_pinky_2},

    // same side thumb and pin
    {VIRT_LAYER_L_thumb_1_pinky_1, VIRT_LAYER_L_thumb_1, VIRT_LAYER_L_pinky_1},
    {VIRT_LAYER_L_thumb_1_pinky_2, VIRT_LAYER_L_thumb_1, VIRT_LAYER_L_pinky_2},

    {VIRT_LAYER_R_thumb_1_pinky_1, VIRT_LAYER_R_thumb_1, VIRT_LAYER_R_pinky_1},
    {VIRT_LAYER_R_thumb_1_pinky_2, VIRT_LAYER_R_thumb_1, VIRT_LAYER_R_pinky_2},

    // cross side thumb and pin
    {VIRT_LAYER_L_thumb_1_R_pinky_1, VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_pinky_1},
    {VIRT_LAYER_L_thumb_1_R_pinky_2, VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_pinky_2},

    {VIRT_LAYER_R_thumb_1_L_pinky_1, VIRT_LAYER_R_thumb_1, VIRT_LAYER_L_pinky_1},
    {VIRT_LAYER_R_thumb_1_L_pinky_2, VIRT_LAYER_R_thumb_1, VIRT_LAYER_L_pinky_2},

    // both thumb
    {VIRT_LAYER_LR_thumb_1, VIRT_LAYER_L_thumb_1, VIRT_LAYER_R_thumb_1},
    {VIRT_LAYER_LR_thumb_2, VIRT_LAYER_L_thumb_2, VIRT_LAYER_R_thumb_2},
    {VIRT_LAYER_LR_thumb_3, VIRT_LAYER_L_thumb_3, VIRT_LAYER_R_thumb_3},
    {VIRT_LAYER_LR_thumb_4, VIRT_LAYER_L_thumb_4, VIRT_LAYER_R_thumb_4},

    // both pinky
    {VIRT_LAYER_LR_pinky_1, VIRT_LAYER_L_pinky_1, VIRT_LAYER_R_pinky_1},
    {VIRT_LAYER_LR_pinky_2, VIRT_LAYER_L_pinky_2, VIRT_LAYER_R_pinky_2},

    // fwsys
    {VIRT_LAYER_Firmware, VIRT_LAYER_L_thumb_2, VIRT_LAYER_L_thumb_3}
};

#define TRI_LAYER_COUNT (sizeof(tri_layer_tbl_v_v_v) / sizeof(tri_layer_tbl_v_v_v[0]))

// virt layer number state cache, update on layer_state_set_
static bool state_cache_v[VIRT_LAYER_COUNT] = {0};

// phy layer has other source, check on layer
// ex, automouse on/off
// if true, check and update from phys, disable ref count system
static const bool p_has_other_source[PHYS_LAYER_COUNT] = {
    [PHYS_LAYER_Mouse_L] = true,
    [PHYS_LAYER_Mouse_R] = true,

    [PHYS_LAYER_Color_Palette] = true
};

// phys ref count
// base layer set fix 1
static uint8_t p_ref_count[PHYS_LAYER_COUNT] = {
    [0] = 1
};

bool virt_layer_state_is(const uint8_t virt_layer) {
    // layer_state_set_ outside use cached value
    return state_cache_v[virt_layer];
}

bool virt_layer_state_cmp(layer_state_t state, const uint8_t virt_layer) {
    const uint8_t phys_layer = v_to_p_tbl[virt_layer];

    if (phys_layer == PHYS_LAYER_UNALLOC) {
        return state_cache_v[virt_layer];
    }

    // if no other source, always use cache
    if (p_has_other_source[phys_layer] == false) return state_cache_v[virt_layer];
    
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

    if (phys_layer != PHYS_LAYER_UNALLOC) {    
        p_ref_count[phys_layer]++;
        if(p_ref_count[phys_layer] == 0) p_ref_count[phys_layer] = UINT8_MAX; 
    }

    // re-calc layer_state_set_*
    // or 0 -> no change
    layer_or(0);
}

void virt_layer_off(const uint8_t virt_layer) {
    const uint8_t phys_layer = v_to_p_tbl[virt_layer];
    state_cache_v[virt_layer] = false;
    
    if (phys_layer != PHYS_LAYER_UNALLOC) {
        p_ref_count[phys_layer]--;
        if(p_ref_count[phys_layer] == UINT8_MAX) p_ref_count[phys_layer] = 0; 
    }

    // re-calc layer_state_set_*
    // or 0 -> no change
    layer_or(0);

}

// disable for ref_count
//void virt_layer_invert(const uint8_t virt_layer) {
//    const uint8_t phys_layer = v_to_p_tbl[virt_layer];
//    state_cache_v[virt_layer] = !(state_cache_v[virt_layer]);
//    
//    if (phys_layer == PHYS_LAYER_UNALLOC) {
//        // re-calc layer_state_set_*
//        // or 0 -> no change
//        layer_or(0);
//    } else {
//        layer_invert(phys_layer);
//    }
//}

layer_state_t layer_state_set_virt_layer(layer_state_t state) {
    // tri layer update flag memory
    bool tmp_state_v[VIRT_LAYER_COUNT] = {0};
    bool tmp_update_v[VIRT_LAYER_COUNT] = {0};
    
    // scan tri layer combination
    for (int i = 0; i < TRI_LAYER_COUNT; i++) {
        tmp_state_v[tri_layer_tbl_v_v_v[i][0]] = tmp_state_v[tri_layer_tbl_v_v_v[i][0]] ||
        (
            virt_layer_state_cmp(state, tri_layer_tbl_v_v_v[i][1]) &&
            virt_layer_state_cmp(state, tri_layer_tbl_v_v_v[i][2])
        );
        
        tmp_update_v[tri_layer_tbl_v_v_v[i][0]] = true; 
    }

    // apply update to virt cache and phys ref count
    for (int v = 0; v < VIRT_LAYER_COUNT; v++) {
        if (tmp_update_v[v] == false) {
            // update cache from phys, dummy read
            virt_layer_state_cmp(state, v);
            continue;
        }

        const uint8_t phys_layer = v_to_p_tbl[v];
        state_cache_v[v] = tmp_state_v[v];
        
        if (phys_layer == PHYS_LAYER_UNALLOC) continue;

        if (tmp_state_v[v]) {
            p_ref_count[phys_layer] = 1;
        } else {
            p_ref_count[phys_layer] = 0;
        }
    }

    // phys ref count to qmk side bitmask
    for (int p = 0; p < PHYS_LAYER_COUNT; p++) {
        // other source, skip not use ref count
        if (p_has_other_source[p] == true) continue;
        
        if (p_ref_count[p] > 0) {
            state |= ((layer_state_t)1 << p);
        } else {
            state &= ~((layer_state_t)1 << p);
        }
    }

    // safe guard, LSB layer on here
    state |= (layer_state_t)0x01;
    
    return state;
}