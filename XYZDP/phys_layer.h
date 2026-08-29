#pragma once

// Oryx side physical layer 
enum phys_layer {
  PHYS_LAYER_Base = 0,
  PHYS_LAYER_Transition,
  
  PHYS_LAYER_Mouse_L,
  PHYS_LAYER_Mouse_R,

  PHYS_LAYER_L_thumb_1,
  PHYS_LAYER_L_thumb_2,
  PHYS_LAYER_L_thumb_3,
  PHYS_LAYER_L_thumb_4,

  PHYS_LAYER_R_thumb_1,
  PHYS_LAYER_R_thumb_2,
  PHYS_LAYER_R_thumb_3,
  PHYS_LAYER_R_thumb_4,

  PHYS_LAYER_L_pinky_1,
  PHYS_LAYER_L_pinky_2,

  PHYS_LAYER_R_pinky_1,
  PHYS_LAYER_R_pinky_2,

  PHYS_LAYER_Mouse_Upper_L,
  PHYS_LAYER_Mouse_Upper_R, 

  PHYS_LAYER_L_thumb_1_pinky_1,
  PHYS_LAYER_L_thumb_1_pinky_2,
  
  PHYS_LAYER_R_thumb_1_pinky_1,
  PHYS_LAYER_R_thumb_1_pinky_2,
 
  PHYS_LAYER_L_thumb_1_R_pinky_1,
  PHYS_LAYER_L_thumb_1_R_pinky_2,

  PHYS_LAYER_R_thumb_1_L_pinky_1,
  PHYS_LAYER_R_thumb_1_L_pinky_2,

  PHYS_LAYER_LR_thumb_1,
  PHYS_LAYER_LR_thumb_3,

  PHYS_LAYER_LR_pinky_1,
  PHYS_LAYER_LR_pinky_2,

  PHYS_LAYER_Firmware,
  PHYS_LAYER_Color_Palette,
  
  PHYS_LAYER_COUNT,
  
  PHYS_LAYER_UNALLOC
};

// layer alias
enum phys_layer_alias {
  PHYS_LAYER_Number = PHYS_LAYER_L_thumb_1,
  PHYS_LAYER_Cursor = PHYS_LAYER_R_thumb_1,

  PHYS_LAYER_Function = PHYS_LAYER_L_thumb_2
};
