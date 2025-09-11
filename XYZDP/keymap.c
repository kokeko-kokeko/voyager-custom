#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_215_255_100,
  HSV_215_255_102,
  HSV_215_255_106,
  HSV_215_255_108,
  HSV_215_255_131,
  HSV_215_255_149,
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
  HSV_43_255_100,
  HSV_43_255_101,
  HSV_43_255_102,
  HSV_43_255_103,
  HSV_43_255_104,
  HSV_43_255_105,
  HSV_43_255_106,
  HSV_43_255_107,
  HSV_43_255_108,
  HSV_43_255_109,
  HSV_43_255_110,
  HSV_43_255_111,
  HSV_43_255_112,
  HSV_43_255_113,
  HSV_43_255_114,
  HSV_43_255_115,
  HSV_43_255_116,
  HSV_43_255_117,
  HSV_43_255_118,
  HSV_43_255_119,
  HSV_43_255_120,
  HSV_43_255_121,
  HSV_43_255_122,
  HSV_43_255_123,
  HSV_43_255_126,
  HSV_43_255_127,
  HSV_43_255_128,
  HSV_43_255_129,
  HSV_43_255_130,
  HSV_43_255_131,
  HSV_43_255_132,
  HSV_43_255_133,
  HSV_43_255_134,
  HSV_43_255_135,
  HSV_43_255_136,
  HSV_43_255_137,
  HSV_43_255_138,
  HSV_43_255_139,
  HSV_43_255_140,
  HSV_43_255_141,
  HSV_43_255_142,
  HSV_43_255_143,
  HSV_43_255_144,
  HSV_43_255_145,
  HSV_43_255_146,
  HSV_43_255_147,
  HSV_43_255_148,
  HSV_43_255_149,
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
  HSV_129_255_100,
  HSV_129_255_101,
  HSV_129_255_102,
  HSV_129_255_103,
  HSV_129_255_104,
  HSV_129_255_105,
  HSV_129_255_106,
  HSV_129_255_107,
  HSV_129_255_108,
  HSV_129_255_109,
  HSV_129_255_110,
  HSV_129_255_111,
  HSV_129_255_112,
  HSV_129_255_113,
  HSV_129_255_114,
  HSV_129_255_115,
  HSV_129_255_116,
  HSV_129_255_117,
  HSV_129_255_118,
  HSV_129_255_119,
  HSV_129_255_120,
  HSV_129_255_121,
  HSV_129_255_122,
  HSV_129_255_123,
  HSV_129_255_126,
  HSV_129_255_127,
  HSV_129_255_128,
  HSV_129_255_129,
  HSV_129_255_130,
  HSV_129_255_131,
  HSV_129_255_132,
  HSV_129_255_133,
  HSV_129_255_134,
  HSV_129_255_135,
  HSV_129_255_136,
  HSV_129_255_137,
  HSV_129_255_138,
  HSV_129_255_139,
  HSV_129_255_140,
  HSV_129_255_141,
  HSV_129_255_142,
  HSV_129_255_143,
  HSV_129_255_144,
  HSV_129_255_145,
  HSV_129_255_146,
  HSV_129_255_147,
  HSV_129_255_148,
  HSV_129_255_149,
  HSV_129_255_151,
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
  DRAG_SCROLL,
  TOGGLE_SCROLL,
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};



#define DUAL_FUNC_0 LT(2, KC_N)
#define DUAL_FUNC_1 LT(5, KC_8)
#define DUAL_FUNC_2 LT(13, KC_F22)
#define DUAL_FUNC_3 LT(10, KC_S)
#define DUAL_FUNC_4 LT(2, KC_A)
#define DUAL_FUNC_5 LT(9, KC_F14)
#define DUAL_FUNC_6 LT(2, KC_3)
#define DUAL_FUNC_7 LT(8, KC_F17)
#define DUAL_FUNC_8 LT(3, KC_B)
#define DUAL_FUNC_9 LT(1, KC_4)
#define DUAL_FUNC_10 LT(15, KC_S)
#define DUAL_FUNC_11 LT(10, KC_D)
#define DUAL_FUNC_12 LT(2, KC_F10)
#define DUAL_FUNC_13 LT(15, KC_F8)
#define DUAL_FUNC_14 LT(10, KC_4)
#define DUAL_FUNC_15 LT(13, KC_0)
#define DUAL_FUNC_16 LT(1, KC_Z)
#define DUAL_FUNC_17 LT(14, KC_W)
#define DUAL_FUNC_18 LT(2, KC_W)
#define DUAL_FUNC_19 LT(1, KC_P)
#define DUAL_FUNC_20 LT(10, KC_F2)
#define DUAL_FUNC_21 LT(6, KC_F2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_1,           KC_2,           KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_3,           KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    LT(8, KC_B),    MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(9, KC_V),    
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),MT(MOD_LSFT, KC_X),KC_J,           KC_K,           KC_MINUS,                                       KC_4,           KC_R,           KC_M,           MT(MOD_RSFT, KC_F),MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(3, KC_LANGUAGE_1),LT(6, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(3, KC_TAB),  LT(6, KC_ESCAPE),                                LT(4, KC_BSPC), KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_LBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,                                           KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MO(8),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(9),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(4),          KC_TRANSPARENT,                                 MO(3),          MO(6),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    MO(3),          MO(6),                                          MO(4),          KC_NO
  ),
  [3] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(8, KC_F11),  MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),LT(9, KC_F12),  
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),MT(MOD_LSFT, KC_F12),KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         MT(MOD_RSFT, KC_F19),MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(8, KC_LBRC), MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),LT(9, KC_RBRC), 
    DUAL_FUNC_0,    DUAL_FUNC_1,    MT(MOD_LSFT, KC_EQUAL),KC_TILD,        KC_PLUS,        KC_LABK,                                        KC_RABK,        KC_CIRC,        KC_AMPR,        DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,    
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(8, KC_RBRC), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(9, KC_BSLS), 
    DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,    LSFT(KC_EQUAL), LSFT(KC_SCLN),  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       LSFT(KC_6),     KC_TRANSPARENT, DUAL_FUNC_8,    DUAL_FUNC_9,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    CW_TOGG,        KC_HOME,        KC_END,         KC_PAGE_UP,     KC_PGDN,        KC_LPRN,                                        KC_RPRN,        LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_APPLICATION, KC_BSPC,        
    KC_TRANSPARENT, DUAL_FUNC_10,   DUAL_FUNC_11,   DUAL_FUNC_12,   DUAL_FUNC_13,   KC_SCLN,                                        KC_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    KC_LEFT_CTRL,   DUAL_FUNC_14,   DUAL_FUNC_15,   KC_LCBR,        KC_LBRC,        KC_UNDS,                                        KC_EXLM,        KC_RBRC,        KC_RCBR,        DUAL_FUNC_16,   DUAL_FUNC_17,   KC_RIGHT_CTRL,  
    QK_LLCK,        KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_8),                                     LSFT(KC_9),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DUAL_FUNC_18,   KC_TRANSPARENT, LSFT(KC_RBRC),  KC_RBRC,        LSFT(KC_INTERNATIONAL_1),                                KC_TRANSPARENT, KC_BSLS,        LSFT(KC_BSLS),  KC_TRANSPARENT, DUAL_FUNC_19,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_R)),LGUI(LSFT(KC_S)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [12] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     LGUI(KC_V),                                     KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    
    KC_LEFT_CTRL,   DUAL_FUNC_20,   DUAL_FUNC_21,   ST_MACRO_7,     ST_MACRO_8,     LGUI(LSFT(KC_V)),                                KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [13] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_20,    ST_MACRO_21,    KC_TRANSPARENT, ST_MACRO_22,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [14] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [15] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [16] = LAYOUT_voyager(
    HSV_215_255_100,KC_NO,          HSV_215_255_102,KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          HSV_215_255_131,
    HSV_215_255_106,KC_NO,          HSV_215_255_108,KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          HSV_215_255_149,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(17),         KC_NO
  ),
  [17] = LAYOUT_voyager(
    HSV_0_255_100,  HSV_0_255_101,  HSV_0_255_102,  HSV_0_255_103,  HSV_0_255_104,  HSV_0_255_105,                                  HSV_0_255_126,  HSV_0_255_127,  HSV_0_255_128,  HSV_0_255_129,  HSV_0_255_130,  HSV_0_255_131,  
    HSV_0_255_106,  HSV_0_255_107,  HSV_0_255_108,  HSV_0_255_109,  HSV_0_255_110,  HSV_0_255_111,                                  HSV_0_255_132,  HSV_0_255_133,  HSV_0_255_134,  HSV_0_255_135,  HSV_0_255_136,  HSV_0_255_137,  
    HSV_0_255_112,  HSV_0_255_113,  HSV_0_255_114,  HSV_0_255_115,  HSV_0_255_116,  HSV_0_255_117,                                  HSV_0_255_138,  HSV_0_255_139,  HSV_0_255_140,  HSV_0_255_141,  HSV_0_255_142,  HSV_0_255_143,  
    HSV_0_255_118,  HSV_0_255_119,  HSV_0_255_120,  HSV_0_255_121,  HSV_0_255_122,  HSV_0_255_123,                                  HSV_0_255_144,  HSV_0_255_145,  HSV_0_255_146,  HSV_0_255_147,  HSV_0_255_148,  HSV_0_255_149,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_0_255_151
  ),
  [18] = LAYOUT_voyager(
    HSV_43_255_100, HSV_43_255_101, HSV_43_255_102, HSV_43_255_103, HSV_43_255_104, HSV_43_255_105,                                 HSV_43_255_126, HSV_43_255_127, HSV_43_255_128, HSV_43_255_129, HSV_43_255_130, HSV_43_255_131, 
    HSV_43_255_106, HSV_43_255_107, HSV_43_255_108, HSV_43_255_109, HSV_43_255_110, HSV_43_255_111,                                 HSV_43_255_132, HSV_43_255_133, HSV_43_255_134, HSV_43_255_135, HSV_43_255_136, HSV_43_255_137, 
    HSV_43_255_112, HSV_43_255_113, HSV_43_255_114, HSV_43_255_115, HSV_43_255_116, HSV_43_255_117,                                 HSV_43_255_138, HSV_43_255_139, HSV_43_255_140, HSV_43_255_141, HSV_43_255_142, HSV_43_255_143, 
    HSV_43_255_118, HSV_43_255_119, HSV_43_255_120, HSV_43_255_121, HSV_43_255_122, HSV_43_255_123,                                 HSV_43_255_144, HSV_43_255_145, HSV_43_255_146, HSV_43_255_147, HSV_43_255_148, HSV_43_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
  ),
  [19] = LAYOUT_voyager(
    HSV_86_255_100, HSV_86_255_101, HSV_86_255_102, HSV_86_255_103, HSV_86_255_104, HSV_86_255_105,                                 HSV_86_255_126, HSV_86_255_127, HSV_86_255_128, HSV_86_255_129, HSV_86_255_130, HSV_86_255_131, 
    HSV_86_255_106, HSV_86_255_107, HSV_86_255_108, HSV_86_255_109, HSV_86_255_110, HSV_86_255_111,                                 HSV_86_255_132, HSV_86_255_133, HSV_86_255_134, HSV_86_255_135, HSV_86_255_136, HSV_86_255_137, 
    HSV_86_255_112, HSV_86_255_113, HSV_86_255_114, HSV_86_255_115, HSV_86_255_116, HSV_86_255_117,                                 HSV_86_255_138, HSV_86_255_139, HSV_86_255_140, HSV_86_255_141, HSV_86_255_142, HSV_86_255_143, 
    HSV_86_255_118, HSV_86_255_119, HSV_86_255_120, HSV_86_255_121, HSV_86_255_122, HSV_86_255_123,                                 HSV_86_255_144, HSV_86_255_145, HSV_86_255_146, HSV_86_255_147, HSV_86_255_148, HSV_86_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
  ),
  [20] = LAYOUT_voyager(
    HSV_129_255_100,HSV_129_255_101,HSV_129_255_102,HSV_129_255_103,HSV_129_255_104,HSV_129_255_105,                                HSV_129_255_126,HSV_129_255_127,HSV_129_255_128,HSV_129_255_129,HSV_129_255_130,HSV_129_255_131,
    HSV_129_255_106,HSV_129_255_107,HSV_129_255_108,HSV_129_255_109,HSV_129_255_110,HSV_129_255_111,                                HSV_129_255_132,HSV_129_255_133,HSV_129_255_134,HSV_129_255_135,HSV_129_255_136,HSV_129_255_137,
    HSV_129_255_112,HSV_129_255_113,HSV_129_255_114,HSV_129_255_115,HSV_129_255_116,HSV_129_255_117,                                HSV_129_255_138,HSV_129_255_139,HSV_129_255_140,HSV_129_255_141,HSV_129_255_142,HSV_129_255_143,
    HSV_129_255_118,HSV_129_255_119,HSV_129_255_120,HSV_129_255_121,HSV_129_255_122,HSV_129_255_123,                                HSV_129_255_144,HSV_129_255_145,HSV_129_255_146,HSV_129_255_147,HSV_129_255_148,HSV_129_255_149,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_129_255_151
  ),
  [21] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TOGGLE_SCROLL,  KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 DRAG_SCROLL,    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,QK_LLCK,        
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
};






extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NAVIGATOR_INC_CPI ... NAVIGATOR_AIM:
    case DRAG_SCROLL:
    case TOGGLE_SCROLL:
      return true;
  }
  return is_mouse_record_user(keycode, record);
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(1);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
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

    case DUAL_FUNC_0:
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
    case DUAL_FUNC_1:
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
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PERC);
        } else {
          unregister_code16(KC_PERC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
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
    case DUAL_FUNC_4:
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
    case DUAL_FUNC_5:
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
    case DUAL_FUNC_6:
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
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_MINUS));
        } else {
          unregister_code16(LSFT(KC_MINUS));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
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
    case DUAL_FUNC_9:
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
    case DUAL_FUNC_10:
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
    case DUAL_FUNC_11:
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
    case DUAL_FUNC_12:
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
    case DUAL_FUNC_13:
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
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LPRN);
        } else {
          unregister_code16(KC_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_17:
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
    case DUAL_FUNC_18:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_8));
        } else {
          unregister_code16(LSFT(KC_8));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_19:
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
    case DUAL_FUNC_20:
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
    case DUAL_FUNC_21:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;
    case TOGGLE_SCROLL:
      if (record->event.pressed) {
        set_scrolling = !set_scrolling;
      }
      return false;
    break;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      navigator_turbo = true;
    } else {
      navigator_turbo = false;
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      navigator_aim = true;
    } else {
      navigator_aim = false;
    }
    return false;
  case NAVIGATOR_INC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(1);
    }
    return false;
  case NAVIGATOR_DEC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(0);
    }
    return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_215_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,100);
      }
      return false;
    case HSV_215_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,102);
      }
      return false;
    case HSV_215_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,106);
      }
      return false;
    case HSV_215_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,108);
      }
      return false;
    case HSV_215_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,131);
      }
      return false;
    case HSV_215_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,149);
      }
      return false;
    case HSV_0_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,100);
      }
      return false;
    case HSV_0_255_101:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,101);
      }
      return false;
    case HSV_0_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,102);
      }
      return false;
    case HSV_0_255_103:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,103);
      }
      return false;
    case HSV_0_255_104:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,104);
      }
      return false;
    case HSV_0_255_105:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,105);
      }
      return false;
    case HSV_0_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,106);
      }
      return false;
    case HSV_0_255_107:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,107);
      }
      return false;
    case HSV_0_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,108);
      }
      return false;
    case HSV_0_255_109:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,109);
      }
      return false;
    case HSV_0_255_110:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,110);
      }
      return false;
    case HSV_0_255_111:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,111);
      }
      return false;
    case HSV_0_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,112);
      }
      return false;
    case HSV_0_255_113:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,113);
      }
      return false;
    case HSV_0_255_114:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,114);
      }
      return false;
    case HSV_0_255_115:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,115);
      }
      return false;
    case HSV_0_255_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,116);
      }
      return false;
    case HSV_0_255_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,117);
      }
      return false;
    case HSV_0_255_118:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,118);
      }
      return false;
    case HSV_0_255_119:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,119);
      }
      return false;
    case HSV_0_255_120:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,120);
      }
      return false;
    case HSV_0_255_121:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,121);
      }
      return false;
    case HSV_0_255_122:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,122);
      }
      return false;
    case HSV_0_255_123:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,123);
      }
      return false;
    case HSV_0_255_126:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,126);
      }
      return false;
    case HSV_0_255_127:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,127);
      }
      return false;
    case HSV_0_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,128);
      }
      return false;
    case HSV_0_255_129:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,129);
      }
      return false;
    case HSV_0_255_130:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,130);
      }
      return false;
    case HSV_0_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,131);
      }
      return false;
    case HSV_0_255_132:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,132);
      }
      return false;
    case HSV_0_255_133:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,133);
      }
      return false;
    case HSV_0_255_134:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,134);
      }
      return false;
    case HSV_0_255_135:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,135);
      }
      return false;
    case HSV_0_255_136:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,136);
      }
      return false;
    case HSV_0_255_137:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,137);
      }
      return false;
    case HSV_0_255_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,138);
      }
      return false;
    case HSV_0_255_139:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,139);
      }
      return false;
    case HSV_0_255_140:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,140);
      }
      return false;
    case HSV_0_255_141:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,141);
      }
      return false;
    case HSV_0_255_142:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,142);
      }
      return false;
    case HSV_0_255_143:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,143);
      }
      return false;
    case HSV_0_255_144:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,144);
      }
      return false;
    case HSV_0_255_145:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,145);
      }
      return false;
    case HSV_0_255_146:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,146);
      }
      return false;
    case HSV_0_255_147:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,147);
      }
      return false;
    case HSV_0_255_148:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,148);
      }
      return false;
    case HSV_0_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,149);
      }
      return false;
    case HSV_0_255_151:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,151);
      }
      return false;
    case HSV_43_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,100);
      }
      return false;
    case HSV_43_255_101:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,101);
      }
      return false;
    case HSV_43_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,102);
      }
      return false;
    case HSV_43_255_103:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,103);
      }
      return false;
    case HSV_43_255_104:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,104);
      }
      return false;
    case HSV_43_255_105:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,105);
      }
      return false;
    case HSV_43_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,106);
      }
      return false;
    case HSV_43_255_107:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,107);
      }
      return false;
    case HSV_43_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,108);
      }
      return false;
    case HSV_43_255_109:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,109);
      }
      return false;
    case HSV_43_255_110:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,110);
      }
      return false;
    case HSV_43_255_111:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,111);
      }
      return false;
    case HSV_43_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,112);
      }
      return false;
    case HSV_43_255_113:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,113);
      }
      return false;
    case HSV_43_255_114:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,114);
      }
      return false;
    case HSV_43_255_115:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,115);
      }
      return false;
    case HSV_43_255_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,116);
      }
      return false;
    case HSV_43_255_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,117);
      }
      return false;
    case HSV_43_255_118:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,118);
      }
      return false;
    case HSV_43_255_119:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,119);
      }
      return false;
    case HSV_43_255_120:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,120);
      }
      return false;
    case HSV_43_255_121:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,121);
      }
      return false;
    case HSV_43_255_122:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,122);
      }
      return false;
    case HSV_43_255_123:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,123);
      }
      return false;
    case HSV_43_255_126:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,126);
      }
      return false;
    case HSV_43_255_127:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,127);
      }
      return false;
    case HSV_43_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,128);
      }
      return false;
    case HSV_43_255_129:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,129);
      }
      return false;
    case HSV_43_255_130:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,130);
      }
      return false;
    case HSV_43_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,131);
      }
      return false;
    case HSV_43_255_132:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,132);
      }
      return false;
    case HSV_43_255_133:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,133);
      }
      return false;
    case HSV_43_255_134:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,134);
      }
      return false;
    case HSV_43_255_135:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,135);
      }
      return false;
    case HSV_43_255_136:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,136);
      }
      return false;
    case HSV_43_255_137:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,137);
      }
      return false;
    case HSV_43_255_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,138);
      }
      return false;
    case HSV_43_255_139:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,139);
      }
      return false;
    case HSV_43_255_140:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,140);
      }
      return false;
    case HSV_43_255_141:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,141);
      }
      return false;
    case HSV_43_255_142:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,142);
      }
      return false;
    case HSV_43_255_143:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,143);
      }
      return false;
    case HSV_43_255_144:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,144);
      }
      return false;
    case HSV_43_255_145:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,145);
      }
      return false;
    case HSV_43_255_146:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,146);
      }
      return false;
    case HSV_43_255_147:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,147);
      }
      return false;
    case HSV_43_255_148:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,148);
      }
      return false;
    case HSV_43_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,149);
      }
      return false;
    case HSV_86_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,100);
      }
      return false;
    case HSV_86_255_101:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,101);
      }
      return false;
    case HSV_86_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,102);
      }
      return false;
    case HSV_86_255_103:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,103);
      }
      return false;
    case HSV_86_255_104:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,104);
      }
      return false;
    case HSV_86_255_105:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,105);
      }
      return false;
    case HSV_86_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,106);
      }
      return false;
    case HSV_86_255_107:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,107);
      }
      return false;
    case HSV_86_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,108);
      }
      return false;
    case HSV_86_255_109:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,109);
      }
      return false;
    case HSV_86_255_110:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,110);
      }
      return false;
    case HSV_86_255_111:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,111);
      }
      return false;
    case HSV_86_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,112);
      }
      return false;
    case HSV_86_255_113:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,113);
      }
      return false;
    case HSV_86_255_114:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,114);
      }
      return false;
    case HSV_86_255_115:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,115);
      }
      return false;
    case HSV_86_255_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,116);
      }
      return false;
    case HSV_86_255_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,117);
      }
      return false;
    case HSV_86_255_118:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,118);
      }
      return false;
    case HSV_86_255_119:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,119);
      }
      return false;
    case HSV_86_255_120:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,120);
      }
      return false;
    case HSV_86_255_121:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,121);
      }
      return false;
    case HSV_86_255_122:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,122);
      }
      return false;
    case HSV_86_255_123:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,123);
      }
      return false;
    case HSV_86_255_126:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,126);
      }
      return false;
    case HSV_86_255_127:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,127);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_86_255_129:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,129);
      }
      return false;
    case HSV_86_255_130:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,130);
      }
      return false;
    case HSV_86_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,131);
      }
      return false;
    case HSV_86_255_132:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,132);
      }
      return false;
    case HSV_86_255_133:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,133);
      }
      return false;
    case HSV_86_255_134:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,134);
      }
      return false;
    case HSV_86_255_135:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,135);
      }
      return false;
    case HSV_86_255_136:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,136);
      }
      return false;
    case HSV_86_255_137:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,137);
      }
      return false;
    case HSV_86_255_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,138);
      }
      return false;
    case HSV_86_255_139:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,139);
      }
      return false;
    case HSV_86_255_140:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,140);
      }
      return false;
    case HSV_86_255_141:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,141);
      }
      return false;
    case HSV_86_255_142:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,142);
      }
      return false;
    case HSV_86_255_143:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,143);
      }
      return false;
    case HSV_86_255_144:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,144);
      }
      return false;
    case HSV_86_255_145:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,145);
      }
      return false;
    case HSV_86_255_146:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,146);
      }
      return false;
    case HSV_86_255_147:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,147);
      }
      return false;
    case HSV_86_255_148:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,148);
      }
      return false;
    case HSV_86_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,149);
      }
      return false;
    case HSV_129_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,100);
      }
      return false;
    case HSV_129_255_101:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,101);
      }
      return false;
    case HSV_129_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,102);
      }
      return false;
    case HSV_129_255_103:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,103);
      }
      return false;
    case HSV_129_255_104:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,104);
      }
      return false;
    case HSV_129_255_105:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,105);
      }
      return false;
    case HSV_129_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,106);
      }
      return false;
    case HSV_129_255_107:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,107);
      }
      return false;
    case HSV_129_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,108);
      }
      return false;
    case HSV_129_255_109:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,109);
      }
      return false;
    case HSV_129_255_110:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,110);
      }
      return false;
    case HSV_129_255_111:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,111);
      }
      return false;
    case HSV_129_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,112);
      }
      return false;
    case HSV_129_255_113:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,113);
      }
      return false;
    case HSV_129_255_114:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,114);
      }
      return false;
    case HSV_129_255_115:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,115);
      }
      return false;
    case HSV_129_255_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,116);
      }
      return false;
    case HSV_129_255_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,117);
      }
      return false;
    case HSV_129_255_118:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,118);
      }
      return false;
    case HSV_129_255_119:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,119);
      }
      return false;
    case HSV_129_255_120:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,120);
      }
      return false;
    case HSV_129_255_121:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,121);
      }
      return false;
    case HSV_129_255_122:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,122);
      }
      return false;
    case HSV_129_255_123:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,123);
      }
      return false;
    case HSV_129_255_126:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,126);
      }
      return false;
    case HSV_129_255_127:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,127);
      }
      return false;
    case HSV_129_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,128);
      }
      return false;
    case HSV_129_255_129:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,129);
      }
      return false;
    case HSV_129_255_130:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,130);
      }
      return false;
    case HSV_129_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,131);
      }
      return false;
    case HSV_129_255_132:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,132);
      }
      return false;
    case HSV_129_255_133:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,133);
      }
      return false;
    case HSV_129_255_134:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,134);
      }
      return false;
    case HSV_129_255_135:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,135);
      }
      return false;
    case HSV_129_255_136:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,136);
      }
      return false;
    case HSV_129_255_137:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,137);
      }
      return false;
    case HSV_129_255_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,138);
      }
      return false;
    case HSV_129_255_139:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,139);
      }
      return false;
    case HSV_129_255_140:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,140);
      }
      return false;
    case HSV_129_255_141:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,141);
      }
      return false;
    case HSV_129_255_142:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,142);
      }
      return false;
    case HSV_129_255_143:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,143);
      }
      return false;
    case HSV_129_255_144:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,144);
      }
      return false;
    case HSV_129_255_145:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,145);
      }
      return false;
    case HSV_129_255_146:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,146);
      }
      return false;
    case HSV_129_255_147:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,147);
      }
      return false;
    case HSV_129_255_148:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,148);
      }
      return false;
    case HSV_129_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,149);
      }
      return false;
    case HSV_129_255_151:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,151);
      }
      return false;
  }
  return true;
}
