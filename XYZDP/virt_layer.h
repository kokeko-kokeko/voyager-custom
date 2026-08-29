#pragma once

#include <stdint.h>
#include "keyboard.h"
#include "action.h"
#include "bitwise.h"

// C program side virtual layer 
enum virt_layer {
  VIRT_LAYER_Transition = 0,

  VIRT_LAYER_FB_JIS,
  VIRT_LAYER_FB_Mac,
  VIRT_LAYER_FB_error,
  
  VIRT_LAYER_ISS_Enable,

  VIRT_LAYER_Flag_END,

  VIRT_LAYER_Mouse_L,
  VIRT_LAYER_Mouse_R,

  VIRT_LAYER_L_thumb_1,
  VIRT_LAYER_L_thumb_2,
  VIRT_LAYER_L_thumb_3,
  VIRT_LAYER_L_thumb_4,

  VIRT_LAYER_R_thumb_1,
  VIRT_LAYER_R_thumb_2,
  VIRT_LAYER_R_thumb_3,
  VIRT_LAYER_R_thumb_4,

  VIRT_LAYER_L_pinky_1,
  VIRT_LAYER_L_pinky_2,

  VIRT_LAYER_R_pinky_1,
  VIRT_LAYER_R_pinky_2,

  VIRT_LAYER_Mouse_Upper_L,
  VIRT_LAYER_Mouse_Upper_R, 

  VIRT_LAYER_L_thumb_1_pinky_1,
  VIRT_LAYER_L_thumb_1_pinky_2,
  
  VIRT_LAYER_R_thumb_1_pinky_1,
  VIRT_LAYER_R_thumb_1_pinky_2,
 
  VIRT_LAYER_L_thumb_1_R_pinky_1,
  VIRT_LAYER_L_thumb_1_R_pinky_2,

  VIRT_LAYER_R_thumb_1_L_pinky_1,
  VIRT_LAYER_R_thumb_1_L_pinky_2,

  VIRT_LAYER_LR_thumb_1,
  VIRT_LAYER_LR_thumb_2,
  VIRT_LAYER_LR_thumb_3,
  VIRT_LAYER_LR_thumb_4,

  VIRT_LAYER_LR_pinky_1,
  VIRT_LAYER_LR_pinky_2,

  VIRT_LAYER_Firmware,
  VIRT_LAYER_Color_Palette,
  
  VIRT_LAYER_COUNT  
};

// minimal virt version subset for action_layer.h
bool virt_layer_state_is(const uint8_t virt_layer);
bool virt_layer_state_cmp(layer_state_t state, const uint8_t virt_layer);

uint8_t get_highest_virt_layer(layer_state_t state);

void virt_layer_on(const uint8_t virt_layer);
void virt_layer_off(const uint8_t virt_layer);

layer_state_t layer_state_set_virt_layer(layer_state_t state);
