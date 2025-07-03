#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_43_255_100,
  HSV_43_255_106,
  HSV_0_255_100,
  HSV_0_255_101,
  HSV_0_255_102,
  HSV_0_255_103,
  HSV_0_255_104,
  HSV_0_255_105,
  HSV_0_255_106,
  HSV_0_255_107,
  HSV_0_255_108,
  HSV_0_255_109,
  HSV_0_255_110,
  HSV_0_255_111,
  HSV_0_255_112,
  HSV_0_255_113,
  HSV_0_255_114,
  HSV_0_255_115,
  HSV_0_255_116,
  HSV_0_255_117,
  HSV_0_255_118,
  HSV_0_255_119,
  HSV_0_255_120,
  HSV_0_255_121,
  HSV_0_255_122,
  HSV_0_255_123,
  HSV_0_255_126,
  HSV_0_255_127,
  HSV_0_255_128,
  HSV_0_255_129,
  HSV_0_255_130,
  HSV_0_255_131,
  HSV_0_255_132,
  HSV_0_255_133,
  HSV_0_255_134,
  HSV_0_255_135,
  HSV_0_255_136,
  HSV_0_255_137,
  HSV_0_255_138,
  HSV_0_255_139,
  HSV_0_255_140,
  HSV_0_255_141,
  HSV_0_255_142,
  HSV_0_255_143,
  HSV_0_255_144,
  HSV_0_255_145,
  HSV_0_255_146,
  HSV_0_255_147,
  HSV_0_255_148,
  HSV_0_255_149,
  HSV_0_255_151,
  HSV_86_255_100,
  HSV_86_255_101,
  HSV_86_255_102,
  HSV_86_255_103,
  HSV_86_255_104,
  HSV_86_255_105,
  HSV_86_255_106,
  HSV_86_255_107,
  HSV_86_255_108,
  HSV_86_255_109,
  HSV_86_255_110,
  HSV_86_255_111,
  HSV_86_255_112,
  HSV_86_255_113,
  HSV_86_255_114,
  HSV_86_255_115,
  HSV_86_255_116,
  HSV_86_255_117,
  HSV_86_255_118,
  HSV_86_255_119,
  HSV_86_255_120,
  HSV_86_255_121,
  HSV_86_255_122,
  HSV_86_255_123,
  HSV_86_255_126,
  HSV_86_255_127,
  HSV_86_255_128,
  HSV_86_255_129,
  HSV_86_255_130,
  HSV_86_255_131,
  HSV_86_255_132,
  HSV_86_255_133,
  HSV_86_255_134,
  HSV_86_255_135,
  HSV_86_255_136,
  HSV_86_255_137,
  HSV_86_255_138,
  HSV_86_255_139,
  HSV_86_255_140,
  HSV_86_255_141,
  HSV_86_255_142,
  HSV_86_255_143,
  HSV_86_255_144,
  HSV_86_255_145,
  HSV_86_255_146,
  HSV_86_255_147,
  HSV_86_255_148,
  HSV_86_255_149,
  HSV_86_255_151,
  HSV_172_255_100,
  HSV_172_255_101,
  HSV_172_255_102,
  HSV_172_255_103,
  HSV_172_255_104,
  HSV_172_255_105,
  HSV_172_255_106,
  HSV_172_255_107,
  HSV_172_255_108,
  HSV_172_255_109,
  HSV_172_255_110,
  HSV_172_255_111,
  HSV_172_255_112,
  HSV_172_255_113,
  HSV_172_255_114,
  HSV_172_255_115,
  HSV_172_255_116,
  HSV_172_255_117,
  HSV_172_255_118,
  HSV_172_255_119,
  HSV_172_255_120,
  HSV_172_255_121,
  HSV_172_255_122,
  HSV_172_255_123,
  HSV_172_255_126,
  HSV_172_255_127,
  HSV_172_255_128,
  HSV_172_255_129,
  HSV_172_255_130,
  HSV_172_255_131,
  HSV_172_255_132,
  HSV_172_255_133,
  HSV_172_255_134,
  HSV_172_255_135,
  HSV_172_255_136,
  HSV_172_255_137,
  HSV_172_255_138,
  HSV_172_255_139,
  HSV_172_255_140,
  HSV_172_255_141,
  HSV_172_255_142,
  HSV_172_255_143,
  HSV_172_255_144,
  HSV_172_255_145,
  HSV_172_255_146,
  HSV_172_255_147,
  HSV_172_255_148,
  HSV_172_255_149,
  HSV_172_255_151,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
};



#define DUAL_FUNC_0 LT(12, KC_K)
#define DUAL_FUNC_1 LT(9, KC_P)
#define DUAL_FUNC_2 LT(7, KC_Z)
#define DUAL_FUNC_3 LT(5, KC_F5)
#define DUAL_FUNC_4 LT(11, KC_W)
#define DUAL_FUNC_5 LT(5, KC_B)
#define DUAL_FUNC_6 LT(15, KC_F20)
#define DUAL_FUNC_7 LT(5, KC_V)
#define DUAL_FUNC_8 LT(2, KC_S)
#define DUAL_FUNC_9 LT(10, KC_F5)
#define DUAL_FUNC_10 LT(6, KC_3)
#define DUAL_FUNC_11 LT(3, KC_F2)
#define DUAL_FUNC_12 LT(14, KC_G)
#define DUAL_FUNC_13 LT(9, KC_F2)
#define DUAL_FUNC_14 LT(15, KC_F18)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_1,           KC_2,           KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_7,           KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    KC_B,           MT(MOD_LALT, KC_C),LT(8, KC_I),    MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),LT(7, KC_S),    MT(MOD_RALT, KC_N),MT(MOD_RGUI, KC_V),
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           KC_MINUS,                                       KC_9,           KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(6, KC_LANGUAGE_1),LT(2, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(6, KC_TAB),  LT(2, KC_ESCAPE),                                LT(4, KC_BSPC), KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_LBRC,        KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_3,                                           KC_7,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,                                       KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,                                       KC_9,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     KC_LPRN,                                        KC_RPRN,        KC_LBRC,        KC_LCBR,        KC_LABK,        KC_LPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     KC_SCLN,                                        KC_COLN,        ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    
    KC_LEFT_CTRL,   DUAL_FUNC_0,    KC_QUES,        ST_MACRO_7,     ST_MACRO_8,     KC_UNDS,                                        KC_EXLM,        KC_RBRC,        KC_RCBR,        KC_RABK,        DUAL_FUNC_1,    KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_LANGUAGE_1,                                  LT(6, KC_LANGUAGE_2),KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    LSFT(KC_8),                                     LSFT(KC_9),     KC_RBRC,        LSFT(KC_RBRC),  KC_TRANSPARENT, LSFT(KC_8),     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT,                                 KC_QUOTE,       ST_MACRO_20,    ST_MACRO_21,    KC_TRANSPARENT, ST_MACRO_22,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19,    LSFT(KC_INTERNATIONAL_1),                                KC_TRANSPARENT, KC_BSLS,        LSFT(KC_BSLS),  KC_TRANSPARENT, DUAL_FUNC_2,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_LGUI, KC_LBRC),MT(MOD_LALT, KC_1),LT(8, KC_2),    MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),LT(7, KC_9),    MT(MOD_RALT, KC_0),MT(MOD_RGUI, KC_RBRC),
    DUAL_FUNC_3,    DUAL_FUNC_4,    KC_EQUAL,       KC_TILD,        KC_PLUS,        KC_LABK,                                        KC_RABK,        KC_CIRC,        KC_AMPR,        KC_PERC,        DUAL_FUNC_5,    DUAL_FUNC_6,    
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_LANGUAGE_1,                                  LT(6, KC_LANGUAGE_2),KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_LGUI, KC_RBRC),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_RGUI, KC_BSLS),
    DUAL_FUNC_7,    DUAL_FUNC_8,    LSFT(KC_MINUS), LSFT(KC_EQUAL), LSFT(KC_SCLN),  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       LSFT(KC_6),     KC_TRANSPARENT, DUAL_FUNC_9,    DUAL_FUNC_10,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT,                                 LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    MT(MOD_LGUI, KC_F11),MT(MOD_LALT, KC_F1),LT(8, KC_F2),   MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),LT(7, KC_F9),   MT(MOD_RALT, KC_F10),MT(MOD_RGUI, KC_F12),
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    LCTL(KC_Q),     LCTL(KC_W),     CW_TOGG,        LCTL(KC_E),     LCTL(KC_R),     LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_TAB,         KC_BSPC,        
    DUAL_FUNC_11,   DUAL_FUNC_12,   KC_TRANSPARENT, DUAL_FUNC_13,   DUAL_FUNC_14,   LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_APPLICATION, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_23,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    HSV_43_255_100, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    HSV_43_255_106, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(10),         KC_NO
  ),
  [10] = LAYOUT_voyager(
    HSV_0_255_100,  HSV_0_255_101,  HSV_0_255_102,  HSV_0_255_103,  HSV_0_255_104,  HSV_0_255_105,                                  HSV_0_255_126,  HSV_0_255_127,  HSV_0_255_128,  HSV_0_255_129,  HSV_0_255_130,  HSV_0_255_131,  
    HSV_0_255_106,  HSV_0_255_107,  HSV_0_255_108,  HSV_0_255_109,  HSV_0_255_110,  HSV_0_255_111,                                  HSV_0_255_132,  HSV_0_255_133,  HSV_0_255_134,  HSV_0_255_135,  HSV_0_255_136,  HSV_0_255_137,  
    HSV_0_255_112,  HSV_0_255_113,  HSV_0_255_114,  HSV_0_255_115,  HSV_0_255_116,  HSV_0_255_117,                                  HSV_0_255_138,  HSV_0_255_139,  HSV_0_255_140,  HSV_0_255_141,  HSV_0_255_142,  HSV_0_255_143,  
    HSV_0_255_118,  HSV_0_255_119,  HSV_0_255_120,  HSV_0_255_121,  HSV_0_255_122,  HSV_0_255_123,                                  HSV_0_255_144,  HSV_0_255_145,  HSV_0_255_146,  HSV_0_255_147,  HSV_0_255_148,  HSV_0_255_149,  
                                                    MO(11),         MO(12),                                         KC_TRANSPARENT, HSV_0_255_151
  ),
  [11] = LAYOUT_voyager(
    HSV_86_255_100, HSV_86_255_101, HSV_86_255_102, HSV_86_255_103, HSV_86_255_104, HSV_86_255_105,                                 HSV_86_255_126, HSV_86_255_127, HSV_86_255_128, HSV_86_255_129, HSV_86_255_130, HSV_86_255_131, 
    HSV_86_255_106, HSV_86_255_107, HSV_86_255_108, HSV_86_255_109, HSV_86_255_110, HSV_86_255_111,                                 HSV_86_255_132, HSV_86_255_133, HSV_86_255_134, HSV_86_255_135, HSV_86_255_136, HSV_86_255_137, 
    HSV_86_255_112, HSV_86_255_113, HSV_86_255_114, HSV_86_255_115, HSV_86_255_116, HSV_86_255_117,                                 HSV_86_255_138, HSV_86_255_139, HSV_86_255_140, HSV_86_255_141, HSV_86_255_142, HSV_86_255_143, 
    HSV_86_255_118, HSV_86_255_119, HSV_86_255_120, HSV_86_255_121, HSV_86_255_122, HSV_86_255_123,                                 HSV_86_255_144, HSV_86_255_145, HSV_86_255_146, HSV_86_255_147, HSV_86_255_148, HSV_86_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_86_255_151
  ),
  [12] = LAYOUT_voyager(
    HSV_172_255_100,HSV_172_255_101,HSV_172_255_102,HSV_172_255_103,HSV_172_255_104,HSV_172_255_105,                                HSV_172_255_126,HSV_172_255_127,HSV_172_255_128,HSV_172_255_129,HSV_172_255_130,HSV_172_255_131,
    HSV_172_255_106,HSV_172_255_107,HSV_172_255_108,HSV_172_255_109,HSV_172_255_110,HSV_172_255_111,                                HSV_172_255_132,HSV_172_255_133,HSV_172_255_134,HSV_172_255_135,HSV_172_255_136,HSV_172_255_137,
    HSV_172_255_112,HSV_172_255_113,HSV_172_255_114,HSV_172_255_115,HSV_172_255_116,HSV_172_255_117,                                HSV_172_255_138,HSV_172_255_139,HSV_172_255_140,HSV_172_255_141,HSV_172_255_142,HSV_172_255_143,
    HSV_172_255_118,HSV_172_255_119,HSV_172_255_120,HSV_172_255_121,HSV_172_255_122,HSV_172_255_123,                                HSV_172_255_144,HSV_172_255_145,HSV_172_255_146,HSV_172_255_147,HSV_172_255_148,HSV_172_255_149,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_172_255_151
  ),
};


#include "keymap_japanese.h"

// access to voyager system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;
extern rgb_config_t rgb_matrix_config;

// enum for layer define sync oryx side
enum layer_number {
  L_Base = 0,
  L_BaseJIS,
  L_BktEx,
  L_BktExJIS,
  L_Num,
  L_NumJIS,
  L_Fn,
  L_Rcur,
  L_Lcur,
  L_FwSys,
  L_SetHue,
  L_SetSat,
  L_SetVal
};

// keymap ovverride (process Engram symbol and ANSI/JIS)
// base (x and xs pair is shifted symbol, xs only overwrite shift)
const key_override_t ko_ansi_base_1 = ko_make_with_layers_and_negmods(0, KC_1, KC_AT,   (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_2 = ko_make_with_layers_and_negmods(0, KC_2, KC_HASH, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_7 = ko_make_with_layers_and_negmods(0, KC_7, KC_DQUO, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_9 = ko_make_with_layers_and_negmods(0, KC_9, KC_QUES, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);

const key_override_t ko_ansi_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1,    KC_GRV,  (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, KC_2,    KC_DLR,  (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_3s = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_LPRN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_4s = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_5s = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_UNDS, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_6s = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_7s = ko_make_with_layers(MOD_MASK_SHIFT, KC_7,    KC_RPRN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_8s = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT , KC_COLN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_9s = ko_make_with_layers(MOD_MASK_SHIFT, KC_9,    KC_EXLM, (layer_state_t)1 << L_Base);

// not work, disable, guess with mod-tap race condition
//const key_override_t ko_ansi_num_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_PIPE,  1 << 2);
//...
//const key_override_t ko_ansi_num_0s = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_ASTR,  1 << 2);

// base (x and xs pair is shifted symbol, xs only overwrite shift)
const key_override_t ko_jis_base_2 = ko_make_with_layers_and_negmods(0, JP_2, JP_HASH, (layer_state_t)1 << L_BaseJIS, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_jis_base_3 = ko_make_with_layers_and_negmods(0, JP_3, JP_QUOT, (layer_state_t)1 << L_BaseJIS, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_jis_base_7 = ko_make_with_layers_and_negmods(0, JP_7, JP_DQUO, (layer_state_t)1 << L_BaseJIS, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_jis_base_9 = ko_make_with_layers_and_negmods(0, JP_9, JP_QUES, (layer_state_t)1 << L_BaseJIS, (uint8_t) MOD_MASK_SHIFT);

const key_override_t ko_jis_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, JP_AT,   JP_GRV,  (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, JP_2,    JP_DLR,  (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_3s = ko_make_with_layers(MOD_MASK_SHIFT, JP_3,    JP_LPRN, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_4s = ko_make_with_layers(MOD_MASK_SHIFT, JP_COMM, JP_SCLN, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_5s = ko_make_with_layers(MOD_MASK_SHIFT, JP_MINS, JP_UNDS, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_6s = ko_make_with_layers(MOD_MASK_SHIFT, JP_SLSH, JP_BSLS, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_7s = ko_make_with_layers(MOD_MASK_SHIFT, JP_7,    JP_RPRN, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_8s = ko_make_with_layers(MOD_MASK_SHIFT, JP_DOT,  JP_COLN, (layer_state_t)1 << L_BaseJIS);
const key_override_t ko_jis_base_9s = ko_make_with_layers(MOD_MASK_SHIFT, JP_9,    JP_EXLM, (layer_state_t)1 << L_BaseJIS);

const key_override_t *key_overrides[] = {
  &ko_ansi_base_1,  &ko_ansi_base_2, &ko_ansi_base_7,  &ko_ansi_base_9,
  &ko_ansi_base_1s, &ko_ansi_base_2s, &ko_ansi_base_3s, &ko_ansi_base_4s, &ko_ansi_base_5s,
  &ko_ansi_base_6s, &ko_ansi_base_7s, &ko_ansi_base_8s, &ko_ansi_base_9s,
  &ko_jis_base_2,  &ko_jis_base_3, &ko_jis_base_7,  &ko_jis_base_9, 
  &ko_jis_base_1s, &ko_jis_base_2s, &ko_jis_base_3s, &ko_jis_base_4s, &ko_jis_base_5s,
  &ko_jis_base_6s, &ko_jis_base_7s, &ko_jis_base_8s, &ko_jis_base_9s
};

static void rgblight_set_hue(const uint8_t hue);
static void rgblight_set_sat(const uint8_t sat);
static void rgblight_set_val(const uint8_t val);
static void rgblight_save_eeprom(void);
static void rgblight_load_preset(void);

static void set_layer_color_fwsys_map(void);
static void set_layer_color_hue_map(void);
static void set_layer_color_sat_map(void);
static void set_layer_color_val_map(void);

// reverse sort order
// hue value 6 * 8 like NCS
static const uint8_t hue_tbl[48] = {
  250, 243, 236, 229, 222, 215,
  207, 200, 193, 186, 179, 172,
  163, 154, 146, 137, 129, 118,
  111, 105,  98,  92,  86,  83,
   79,  75,  71,  67,  63,  58,
   55,  52,  49,  46,  43,  40,
   35,  30,  25,  20,  15,  10,
    9,   7,   5,   3,   1,   0
};
static const uint8_t sat_tbl[48] = {
  255, 252, 249, 246, 243, 240, 237, 234,
  231, 228, 225, 222, 219, 216, 213, 210,
  207, 204, 201, 198, 195, 192, 189, 186,
  183, 180, 177, 174, 171, 168, 164, 160,
  150, 140, 130, 120, 110, 100,  90,  80,
   70,  60,  50,  40,  30,  20,  10,   0
};
// val value max limit 175
static const uint8_t val_tbl[48] = {
  175, 165, 155, 145, 135, 128, 121, 119,
  117, 115, 113, 111, 109, 107, 105, 103,
  101,  99,  97,  95,  93,  91,  89,  87,
   85,  83,  81,  79,  77,  75,  73,  71,
   69,  67,  65,  63,  61,  59,  57,  55,
   53,  51,  46,  41,  31,  21,  11,   1
};
static const uint8_t idx2pos_tbl[48] = {
   49,  43,  37,  31,
   48,  42,  36,  30,
   47,  41,  35,  29,
   46,  40,  34,  28,
   45,  39,  33,  27,
   44,  38,  32,  26,
   
   23,  17,  11,   5,
   22,  16,  10,   4,
   21,  15,   9,   3,
   20,  14,   8,   2,
   19,  13,   7,   1,
   18,  12,   6,   0
};
static const uint8_t pos2idx_tbl[52] = {
   47,  43,  39,  35,  31,  27,
   46,  42,  38,  34,  30,  26,
   45,  41,  37,  33,  29,  25,
   44,  40,  36,  32,  28,  24,
    0,   0,
   23,  19,  15,   11,  7,   3,
   22,  18,  14,   10,  6,   2,
   21,  17,  13,    9,  5,   1,
   20,  16,  12,    8,  4,   0,
    0,   0
};

static bool status_led(const uint8_t mask, const uint8_t * const pattern, const uint16_t init_delay_ms);

static const uint8_t * const led_pattern_on = (uint8_t[]){1, 0, UINT8_MAX, UINT8_MAX, UINT8_MAX};
static const uint8_t * const led_pattern_blink = (uint8_t[]){13, 50, UINT8_MAX, UINT8_MAX, UINT8_MAX};
static const uint8_t * const led_pattern_single = (uint8_t[]){1, 25, 0, UINT8_MAX, UINT8_MAX, UINT8_MAX};
static const uint8_t * const led_pattern_oneshot = (uint8_t[]){13, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 0, UINT8_MAX, UINT8_MAX, UINT8_MAX};
//static const uint8_t * const led_pattern_heartbeat = (uint8_t[]){250, 125, UINT8_MAX, UINT8_MAX, UINT8_MAX};

// IME status indicator
static bool ime_on = false;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  //ANSI, IME off
  ime_on = false;
  layer_move(L_Base);
}

// tap flow control
// bool is_flow_tap_key(uint16_t keycode) is default
// disable (return 0)
// thumb space LT 
// cursor LT
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (keycode) {
      case LT(L_Num, KC_SPACE):
      case LT(L_BktEx, KC_SPACE):
        return 0;
      
      // flow tap only enable to letter
      case LT(L_Lcur, KC_I):
      case LT(L_Rcur, KC_S):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  return 0;  // Disable Flow Tap.
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case L_FwSys:
      set_layer_color_fwsys_map();
      break;
    case L_SetHue:
      set_layer_color_hue_map();
      break;
    case L_SetSat:
      set_layer_color_sat_map();
      break;
    case L_SetVal:
      set_layer_color_val_map();
      break;
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  //ANSI/JIS addiional enable
  state = update_tri_layer_state(state, L_BaseJIS, L_Num, L_NumJIS);
  state = update_tri_layer_state(state, L_BaseJIS, L_BktEx, L_BktExJIS);

  // call FwSys with Bkt and Fn
  state = update_tri_layer_state(state, L_Fn, L_BktEx, L_FwSys);
  
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
    case L_Base :
    case L_BaseJIS:
      status_led(0b1111, NULL, 0);
      if (ime_on) {
        status_led(0b1000, led_pattern_on, 0);
      }
      if (is_caps_word_on()) {
        status_led(0b0100, led_pattern_on, 0);
      }
      break;
    case L_Num:
    case L_NumJIS:
      status_led(0b1100, NULL, 0);
      status_led(0b0010, led_pattern_on, 0);
      status_led(0b0001, led_pattern_blink, 0);
      break;
    case L_BktEx:
    case L_BktExJIS:
      status_led(0b1100, NULL, 0);
      status_led(0b0001, led_pattern_on, 0);
      status_led(0b0010, led_pattern_blink, 0);
      break;
    case L_Fn:
      status_led(0b1100, NULL, 0);
      status_led(0b0011, led_pattern_on, 0);
      break;
    case L_Lcur:
      status_led(0b0110, NULL, 0);
      status_led(0b1000, led_pattern_on, 0);
      status_led(0b0001, led_pattern_blink, 0);
      break;
    case L_Rcur:
      status_led(0b1001, NULL, 0);
      status_led(0b0100, led_pattern_on, 0);
      status_led(0b0010, led_pattern_blink, 0);
      break;
    case L_FwSys:
      status_led(0b1111, led_pattern_on, 0);
      break;
    case L_SetHue:
      status_led(0b0011, NULL, 0);
      status_led(0b1100, led_pattern_on, 0);
      break;
    case L_SetSat:
      status_led(0b0001, NULL, 0);
      status_led(0b1110, led_pattern_on, 0);
      break;
    case L_SetVal:
      status_led(0b0010, NULL, 0);
      status_led(0b1101, led_pattern_on, 0);
      break;

    default :
      status_led(0b1111, NULL, 0);
      break;
  }  
  return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //IME state display (update flag & re-calc status)
    case KC_LANGUAGE_1:
      if (record->event.pressed) {
        if (!ime_on) {
          ime_on = true;
          layer_on(L_Base);
        }
      }
      return;
    case LT(L_Fn, KC_LANGUAGE_1):
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          if (!ime_on) {
            ime_on = true;
            layer_on(L_Base);
          }
        }
      }
      return;
    case KC_LANGUAGE_2:
      if (record->event.pressed) {
        if (ime_on) {
          ime_on = false;
          layer_on(L_Base);
        }
      }
      return;
    case LT(L_Fn, KC_LANGUAGE_2):
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          if (ime_on) {
            ime_on = false;
            layer_on(L_Base);
          }
        }
      }
      return;
  }
  return;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_1))SS_DELAY(100)  SS_LSFT(SS_TAP(X_SLASH)));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SLASH))SS_DELAY(100)  SS_LSFT(SS_TAP(X_1)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_8)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_BSLS));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_LSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(100)  SS_TAP(X_INTERNATIONAL_1));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_EXLM);
        } else {
          unregister_code16(KC_EXLM);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RPRN);
        } else {
          unregister_code16(KC_RPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_9));
        } else {
          unregister_code16(LSFT(KC_9));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LCBR);
        } else {
          unregister_code16(KC_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PIPE);
        } else {
          unregister_code16(KC_PIPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ASTR);
        } else {
          unregister_code16(KC_ASTR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RCBR);
        } else {
          unregister_code16(KC_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_RBRC));
        } else {
          unregister_code16(LSFT(KC_RBRC));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_INTERNATIONAL_3));
        } else {
          unregister_code16(LSFT(KC_INTERNATIONAL_3));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_QUOTE));
        } else {
          unregister_code16(LSFT(KC_QUOTE));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_BSLS));
        } else {
          unregister_code16(LSFT(KC_BSLS));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_A));
        } else {
          unregister_code16(LCTL(KC_A));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_12:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_S));
        } else {
          unregister_code16(LCTL(KC_S));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_C));
        } else {
          unregister_code16(LCTL(KC_C));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_V));
        } else {
          unregister_code16(LCTL(KC_V));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode_noeeprom(1);
      }
      return false;
    
    case HSV_43_255_100:
      if (record->event.pressed) {
        //ANSI
        layer_off(L_BaseJIS);
        layer_on(L_Base);
      }
      return false;
    case HSV_43_255_106:
      if (record->event.pressed) {
        //JIS
        layer_on(L_BaseJIS);
        layer_on(L_Base);
      }
      return false;
    
    case HSV_0_255_100:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_0_255_101:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_0_255_102:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_0_255_103:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_0_255_104:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_0_255_105:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_0_255_106:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_0_255_107:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_0_255_108:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_0_255_109:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_0_255_110:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_0_255_111:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_0_255_112:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_0_255_113:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_0_255_114:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_0_255_115:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_0_255_116:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_0_255_117:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_0_255_118:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_0_255_119:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_0_255_120:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_0_255_121:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_0_255_122:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_0_255_123:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_0_255_126:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_0_255_127:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_0_255_128:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_0_255_129:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_0_255_130:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_0_255_131:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_0_255_132:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_0_255_133:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_0_255_134:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_0_255_135:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_0_255_136:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_0_255_137:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_0_255_138:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_0_255_139:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_0_255_140:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_0_255_141:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_0_255_142:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_0_255_143:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_0_255_144:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_0_255_145:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_0_255_146:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_0_255_147:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_0_255_148:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_0_255_149:
      if (record->event.pressed) {
        rgblight_set_hue(hue_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_0_255_151:
      if (record->event.pressed) {
        rgblight_load_preset();
      }
      return false;
    
    case HSV_86_255_100:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_86_255_101:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_86_255_102:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_86_255_103:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_86_255_104:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_86_255_105:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_86_255_106:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_86_255_107:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_86_255_108:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_86_255_109:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_86_255_110:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_86_255_111:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_86_255_112:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_86_255_113:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_86_255_114:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_86_255_115:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_86_255_116:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_86_255_117:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_86_255_118:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_86_255_119:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_86_255_120:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_86_255_121:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_86_255_122:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_86_255_123:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_86_255_126:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_86_255_127:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_86_255_129:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_86_255_130:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_86_255_131:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_86_255_132:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_86_255_133:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_86_255_134:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_86_255_135:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_86_255_136:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_86_255_137:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_86_255_138:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_86_255_139:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_86_255_140:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_86_255_141:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_86_255_142:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_86_255_143:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_86_255_144:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_86_255_145:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_86_255_146:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_86_255_147:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_86_255_148:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_86_255_149:
      if (record->event.pressed) {
        rgblight_set_sat(sat_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_86_255_151:
      if (record->event.pressed) {
        rgblight_save_eeprom();
      }
      return false;
    
    case HSV_172_255_100:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_172_255_101:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_172_255_102:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_172_255_103:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_172_255_104:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_172_255_105:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_172_255_106:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_172_255_107:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_172_255_108:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_172_255_109:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_172_255_110:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_172_255_111:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_172_255_112:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_172_255_113:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_172_255_114:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_172_255_115:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_172_255_116:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_172_255_117:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_172_255_118:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_172_255_119:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_172_255_120:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_172_255_121:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_172_255_122:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_172_255_123:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_172_255_126:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_172_255_127:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_172_255_128:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_172_255_129:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_172_255_130:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_172_255_131:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_172_255_132:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_172_255_133:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_172_255_134:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_172_255_135:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_172_255_136:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_172_255_137:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_172_255_138:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_172_255_139:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_172_255_140:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_172_255_141:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_172_255_142:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_172_255_143:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_172_255_144:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_172_255_145:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_172_255_146:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_172_255_147:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_172_255_148:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_172_255_149:
      if (record->event.pressed) {
        rgblight_set_val(val_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_172_255_151:
      if (record->event.pressed) {
        rgblight_save_eeprom();
      }
      return false;
    
    //RGB inc/dec no eeprom over write
    // always return false (sometime use upedge)
    case RGB_HUI:
      if (record->event.pressed) rgblight_increase_hue_noeeprom();
      return false;
    case RGB_HUD:
      if (record->event.pressed) rgblight_decrease_hue_noeeprom();
      return false;
    case RGB_SAI:
      if (record->event.pressed) rgblight_increase_sat_noeeprom();
      return false;
    case RGB_SAD:
      if (record->event.pressed) rgblight_decrease_sat_noeeprom();
      return false;
    case RGB_VAI:
      if (record->event.pressed) rgblight_increase_val_noeeprom();
      return false;
    case RGB_VAD:
      if (record->event.pressed) rgblight_decrease_val_noeeprom();
      return false;
    case RGB_SPI:
      if (record->event.pressed) rgblight_increase_speed_noeeprom();
      return false;
    case RGB_SPD:
      if (record->event.pressed) rgblight_decrease_speed_noeeprom();
      return false;
    case RGB_TOG:
      if (record->event.pressed) rgblight_toggle_noeeprom();
      return false;
    case RGB_MODE_FORWARD:
      if (record->event.pressed) rgblight_step_noeeprom();
      return false;    
  }
  return true;
}


// local function

// LED pattern list, no const limit, terminate symbol
// off -> on -> off ... (off start for no glitch)
// reduce data x16 (4bit shift) 8bit
// 0: terminate, output this area value
// MAX: return to position 0 immediately, this cycle output position 0 value & wait
// other: output current position value & wait
// put reurn token for safety
// max 16x255=4080ms 4sec
// write NULL direct 
static uint32_t status_led_task_1(uint32_t trigger_time, void *cb_arg) {
  static uint8_t count = 0;
  if (cb_arg == NULL) {
    count = 0;
    STATUS_LED_1(0);
    return 0;
  }
  const uint8_t * const pattern = cb_arg;
  if (pattern[count] == UINT8_MAX) {
    count = 0;
  }
  STATUS_LED_1(count & 0b00000001);
  return (((uint32_t)pattern[count++]) << 4);
}

static uint32_t status_led_task_2(uint32_t trigger_time, void *cb_arg) {
  static uint8_t count = 0;
  if (cb_arg == NULL) {
    count = 0;
    STATUS_LED_2(0);
    return 0;
  }
  const uint8_t * const pattern = cb_arg;
  if (pattern[count] == UINT8_MAX) {
    count = 0;
  }
  STATUS_LED_2(count & 0b00000001);
  return (((uint32_t)pattern[count++]) << 4);
}

static uint32_t status_led_task_3(uint32_t trigger_time, void *cb_arg) {
  static uint8_t count = 0;
  if (cb_arg == NULL) {
    count = 0;
    STATUS_LED_3(0);
    return 0;
  }
  const uint8_t * const pattern = cb_arg;
  if (pattern[count] == UINT8_MAX) {
    count = 0;
  }
  STATUS_LED_3(count & 0b00000001);
  return (((uint32_t)pattern[count++]) << 4);
}

static uint32_t status_led_task_4(uint32_t trigger_time, void *cb_arg) {
  static uint8_t count = 0;
  if (cb_arg == NULL) {
    count = 0;
    STATUS_LED_4(0);
    return 0;
  }
  const uint8_t * const pattern = cb_arg;
  if (pattern[count] == UINT8_MAX) {
    count = 0;
  }
  STATUS_LED_4(count & 0b00000001);
  return (((uint32_t)pattern[count++]) << 4);
}

// 1 -> Red Left
// 3 -> Red Right
// 2 -> Green Left
// 4 -> Green Right
// re-order bit position
static bool status_led(const uint8_t mask, const uint8_t * const pattern, const uint16_t init_delay_ms) {
  static deferred_token token_1 = INVALID_DEFERRED_TOKEN;
  static deferred_token token_3 = INVALID_DEFERRED_TOKEN;
  static deferred_token token_2 = INVALID_DEFERRED_TOKEN;
  static deferred_token token_4 = INVALID_DEFERRED_TOKEN;
  
  if (mask & 0b1000) {
    if (token_1 != INVALID_DEFERRED_TOKEN) {
      cancel_deferred_exec(token_1);
      token_1 = INVALID_DEFERRED_TOKEN;
      status_led_task_1(0, NULL);
    }
  }
  if (mask & 0b0100) {
    if (token_3 != INVALID_DEFERRED_TOKEN) {
      cancel_deferred_exec(token_3);
      token_3 = INVALID_DEFERRED_TOKEN;
      status_led_task_3(0, NULL);
    }
  }  
  if (mask & 0b0010) {
    if (token_2 != INVALID_DEFERRED_TOKEN) {
      cancel_deferred_exec(token_2);
      token_2 = INVALID_DEFERRED_TOKEN;
      status_led_task_2(0, NULL);
    }
  }
  if (mask & 0b0001) {
    if (token_4 != INVALID_DEFERRED_TOKEN) {
      cancel_deferred_exec(token_4);
      token_4 = INVALID_DEFERRED_TOKEN;
      status_led_task_4(0, NULL);
    }
  }

  // skip task exec
  if (pattern == NULL) return true;

  // add pseudo rondom delay 
  if (mask & 0b1000) {
    token_1 = defer_exec((uint32_t)(init_delay_ms + 1), status_led_task_1, (void *)pattern);
  }
  if (mask & 0b0100) {
    token_3 = defer_exec((uint32_t)(init_delay_ms + 3), status_led_task_3, (void *)pattern);
  }
  if (mask & 0b0010) {
    token_2 = defer_exec((uint32_t)(init_delay_ms + 5), status_led_task_2, (void *)pattern);
  }
  if (mask & 0b0001) {
    token_4 = defer_exec((uint32_t)(init_delay_ms + 7), status_led_task_4, (void *)pattern);
  }
  
  return true;
}

// HSV independent update code
static void rgblight_set_hue(const uint8_t hue) {
  HSV hsv = rgblight_get_hsv();
  rgblight_sethsv_noeeprom(hue, hsv.s, hsv.v);
}

static void rgblight_set_sat(const uint8_t sat) {
  HSV hsv = rgblight_get_hsv();
  rgblight_sethsv_noeeprom(hsv.h, sat, hsv.v);
}

static void rgblight_set_val(const uint8_t val) {
  HSV hsv = rgblight_get_hsv();
  rgblight_sethsv_noeeprom(hsv.h, hsv.s, val);
}

static void rgblight_save_eeprom(void) {
  HSV hsv = rgblight_get_hsv();
  rgblight_sethsv(hsv.h, hsv.s, hsv.v);
  //eeprom write once (write all value raw to eeprom)
  
  status_led(0b1111, led_pattern_single, 0);
}

static void rgblight_load_preset(void) {
  rgblight_sethsv_noeeprom(250, 255, 109);
  
  status_led(0b1111, led_pattern_single, 0);
}

static void set_layer_color_fwsys_map(void) {
  const uint8_t f = rgblight_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;

  rgb_matrix_set_color_all(0, 0, 0);

  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  rgb_matrix_set_color(44, f, f, 0);
  rgb_matrix_set_color(45, f, f, 0);
  rgb_matrix_set_color(50, o, o, o);

  //ANSI/JIS
  if (layer_state_is(L_BaseJIS)) {
    //JIS base enable
    rgb_matrix_set_color(0, o, 0, 0);
    rgb_matrix_set_color(6, 0, f, 0);
  } else {
    //ANSI base
    rgb_matrix_set_color(0, f, 0, 0);
    rgb_matrix_set_color(6, 0, o, 0);
  }

  //OS detect
  RGB rgb_os = {0, 0, 0};
  switch (detected_host_os()) {
    case OS_WINDOWS:
      rgb_os.b = f;
      break;
    case OS_LINUX:
      rgb_os.g = f;
      break;
    case OS_MACOS:
      rgb_os.r = f;
      break;
    case OS_IOS:
      rgb_os.r = f;
      rgb_os.g = h;
      break;    
    case OS_UNSURE:
      rgb_os.r = f;
      rgb_os.g = f;
      break;
    default:
      rgb_os.r = f;
      rgb_os.g = f;
      rgb_os.b = f;
      break;
  }
  rgb_matrix_set_color(22, rgb_os.r, rgb_os.g, rgb_os.b);
  rgb_matrix_set_color(23, rgb_os.r, rgb_os.g, rgb_os.b);

  //tapping
  rgb_matrix_set_color(18, 0, 0, f);
  rgb_matrix_set_color(19, o, 0, o);
  rgb_matrix_set_color(20, f, 0, f);

  //LED
  rgb_matrix_set_color(47, o, o, o);
  rgb_matrix_set_color(48, h, h, h);
  rgb_matrix_set_color(49, f, 0, 0);

  //reset
  rgb_matrix_set_color(31, f, 0, 0);
}

static void set_layer_color_hue_map(void) {
  HSV hsv = rgblight_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(50, hsv.v, hsv.v, hsv.v);
  rgb_matrix_set_color(51, hsv.v, 0, 0 );
  uint8_t key = hsv.h;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.h <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.h = hue_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_sat_map(void) {
  HSV hsv = rgblight_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(24, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(50, hsv.v, hsv.v, hsv.v);
  rgb_matrix_set_color(51, 0, hsv.v, 0);
  uint8_t key = hsv.s;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.s <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.s = sat_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}

static void set_layer_color_val_map(void) {
  HSV hsv = rgblight_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);

  rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
  rgb_matrix_set_color(50, hsv.v, hsv.v, hsv.v);
  rgb_matrix_set_color(51, 0, 0, hsv.v);
  uint8_t key = hsv.v;
  uint8_t i = 0;
  for (i = 0; i < 48; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    if (hsv.v <= key) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      break;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
  for (i++; i < 48; i++) {
    hsv.v = val_tbl[i];
    if (hsv.v == 0) {
      rgb_matrix_set_color(idx2pos_tbl[i], 0, 0, 0);
      continue;
    }
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(idx2pos_tbl[i], rgb.r, rgb.g, rgb.b);
  }
}



