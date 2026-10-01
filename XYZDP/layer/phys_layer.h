#pragma once

// Oryx conf side physical layer 
// base only direct value access
// mean 0 for UNALLOC
enum phys_layer_num {
  //PHYS_LAYER_Base = 0, 
  PHYS_LAYER_UNALLOC = 0, 
  
  PHYS_LAYER_Mouse_L = 1,
  PHYS_LAYER_Mouse_R,

  PHYS_LAYER_Number,
  PHYS_LAYER_Fucction,
  PHYS_LAYER_Cursor,
  
  PHYS_LAYER_QWERTY_Shortcut,

  PHYS_LAYER_Mouse_Upper_L,
  PHYS_LAYER_Mouse_Upper_R, 

  PHYS_LAYER_Print_Screen,
  PHYS_LAYER_Macro,
  
  PHYS_LAYER_Firmware,
  PHYS_LAYER_Color_Palette,
  
  PHYS_LAYER_COUNT
};

