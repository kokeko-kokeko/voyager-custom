#pragma once

// layer 
enum layer_num {
  LAYER_Base = 0,
  LAYER_Transition,
  
  LAYER_Mouse_L,
  LAYER_Mouse_R,

  LAYER_L_thumb_0,
  LAYER_R_thumb_0,

  LAYER_L_thumb_1,
  LAYER_R_thumb_1,

  LAYER_L_thumb_2,
  LAYER_R_thumb_2,

  LAYER_L_pinky_0,
  LAYER_R_pinky_0,

  LAYER_L_pinky_1,
  LAYER_R_pinky_1,

  LAYER_L_thumb_0_L_pinky_0,
  LAYER_L_thumb_0_L_pinky_1,

  LAYER_R_thumb_0_R_pinky_0,
  LAYER_R_thumb_0_R_pinky_1,
 
  LAYER_L_thumb_0_R_pinky_0,
  LAYER_L_thumb_0_R_pinky_1,

  LAYER_R_thumb_0_L_pinky_0,
  LAYER_R_thumb_0_L_pinky_1,

  LAYER_L_thumb_0_R_thumb_0,

  LAYER_L_pinky_0_R_pinky_0,
  LAYER_L_pinky_1_R_pinky_1,

  LAYER_Mouse_Upper_L,
  LAYER_Mouse_Upper_R,

  LAYER_Firmware,
  LAYER_Color_Palette,
  
  C_LAYER_COUNT 
};

// layer alias
enum layer_num_alias {
  LAYER_Number = LAYER_L_thumb_0,
  LAYER_Cursor = LAYER_R_thumb_0,

  LAYER_Function = LAYER_L_thumb_1
};
