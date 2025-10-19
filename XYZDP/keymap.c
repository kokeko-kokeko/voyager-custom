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
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};



#define DUAL_FUNC_0 LT(7, KC_F8)
#define DUAL_FUNC_1 LT(5, KC_S)
#define DUAL_FUNC_2 LT(12, KC_L)
#define DUAL_FUNC_3 LT(3, KC_D)
#define DUAL_FUNC_4 LT(15, KC_R)
#define DUAL_FUNC_5 LT(5, KC_W)
#define DUAL_FUNC_6 LT(10, KC_F2)
#define DUAL_FUNC_7 LT(15, KC_F21)
#define DUAL_FUNC_8 LT(1, KC_F8)
#define DUAL_FUNC_9 LT(11, KC_F23)
#define DUAL_FUNC_10 LT(5, KC_K)
#define DUAL_FUNC_11 LT(10, KC_F)
#define DUAL_FUNC_12 LT(14, KC_L)
#define DUAL_FUNC_13 LT(11, KC_F8)
#define DUAL_FUNC_14 LT(7, KC_F12)
#define DUAL_FUNC_15 LT(13, KC_I)
#define DUAL_FUNC_16 LT(2, KC_F1)
#define DUAL_FUNC_17 LT(1, KC_H)
#define DUAL_FUNC_18 LT(14, KC_F23)
#define DUAL_FUNC_19 LT(14, KC_5)
#define DUAL_FUNC_20 LT(1, KC_F14)
#define DUAL_FUNC_21 LT(14, KC_F21)

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
                                                    MO(3),          MO(6),                                          MO(4),          KC_TRANSPARENT
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
    MO(8),          DUAL_FUNC_10,   DUAL_FUNC_11,   DUAL_FUNC_12,   DUAL_FUNC_13,   KC_SCLN,                                        KC_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      MO(9),          
    KC_LEFT_CTRL,   DUAL_FUNC_14,   DUAL_FUNC_15,   KC_LCBR,        KC_LBRC,        KC_UNDS,                                        KC_EXLM,        KC_RBRC,        KC_RCBR,        DUAL_FUNC_16,   DUAL_FUNC_17,   KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN6,     KC_MS_BTN5,                                     KC_MS_BTN4,     KC_MS_BTN5,     KC_MS_BTN6,     KC_MS_BTN7,     KC_MS_BTN8,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LANGUAGE_6,  KC_MS_BTN7,     KC_MS_BTN4,                                     KC_MS_BTN3,     KC_MS_BTN2,     KC_LANGUAGE_6,  NAVIGATOR_AIM,  NAVIGATOR_TURBO,KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN8,     DRAG_SCROLL,                                    LGUI(KC_TAB),   KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LANGUAGE_6,  KC_MS_BTN3,                                     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_RIGHT_SHIFT, 
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [17] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_12,   DUAL_FUNC_13,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [18] = LAYOUT_voyager(
    HSV_215_255_100,KC_NO,          HSV_215_255_102,KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          HSV_215_255_131,
    HSV_215_255_106,KC_NO,          HSV_215_255_108,KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          HSV_215_255_149,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(19),         KC_NO
  ),
  [19] = LAYOUT_voyager(
    HSV_0_255_100,  HSV_0_255_101,  HSV_0_255_102,  HSV_0_255_103,  HSV_0_255_104,  HSV_0_255_105,                                  HSV_0_255_126,  HSV_0_255_127,  HSV_0_255_128,  HSV_0_255_129,  HSV_0_255_130,  HSV_0_255_131,  
    HSV_0_255_106,  HSV_0_255_107,  HSV_0_255_108,  HSV_0_255_109,  HSV_0_255_110,  HSV_0_255_111,                                  HSV_0_255_132,  HSV_0_255_133,  HSV_0_255_134,  HSV_0_255_135,  HSV_0_255_136,  HSV_0_255_137,  
    HSV_0_255_112,  HSV_0_255_113,  HSV_0_255_114,  HSV_0_255_115,  HSV_0_255_116,  HSV_0_255_117,                                  HSV_0_255_138,  HSV_0_255_139,  HSV_0_255_140,  HSV_0_255_141,  HSV_0_255_142,  HSV_0_255_143,  
    HSV_0_255_118,  HSV_0_255_119,  HSV_0_255_120,  HSV_0_255_121,  HSV_0_255_122,  HSV_0_255_123,                                  HSV_0_255_144,  HSV_0_255_145,  HSV_0_255_146,  HSV_0_255_147,  HSV_0_255_148,  HSV_0_255_149,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_0_255_151
  ),
  [20] = LAYOUT_voyager(
    HSV_43_255_100, HSV_43_255_101, HSV_43_255_102, HSV_43_255_103, HSV_43_255_104, HSV_43_255_105,                                 HSV_43_255_126, HSV_43_255_127, HSV_43_255_128, HSV_43_255_129, HSV_43_255_130, HSV_43_255_131, 
    HSV_43_255_106, HSV_43_255_107, HSV_43_255_108, HSV_43_255_109, HSV_43_255_110, HSV_43_255_111,                                 HSV_43_255_132, HSV_43_255_133, HSV_43_255_134, HSV_43_255_135, HSV_43_255_136, HSV_43_255_137, 
    HSV_43_255_112, HSV_43_255_113, HSV_43_255_114, HSV_43_255_115, HSV_43_255_116, HSV_43_255_117,                                 HSV_43_255_138, HSV_43_255_139, HSV_43_255_140, HSV_43_255_141, HSV_43_255_142, HSV_43_255_143, 
    HSV_43_255_118, HSV_43_255_119, HSV_43_255_120, HSV_43_255_121, HSV_43_255_122, HSV_43_255_123,                                 HSV_43_255_144, HSV_43_255_145, HSV_43_255_146, HSV_43_255_147, HSV_43_255_148, HSV_43_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
  ),
  [21] = LAYOUT_voyager(
    HSV_86_255_100, HSV_86_255_101, HSV_86_255_102, HSV_86_255_103, HSV_86_255_104, HSV_86_255_105,                                 HSV_86_255_126, HSV_86_255_127, HSV_86_255_128, HSV_86_255_129, HSV_86_255_130, HSV_86_255_131, 
    HSV_86_255_106, HSV_86_255_107, HSV_86_255_108, HSV_86_255_109, HSV_86_255_110, HSV_86_255_111,                                 HSV_86_255_132, HSV_86_255_133, HSV_86_255_134, HSV_86_255_135, HSV_86_255_136, HSV_86_255_137, 
    HSV_86_255_112, HSV_86_255_113, HSV_86_255_114, HSV_86_255_115, HSV_86_255_116, HSV_86_255_117,                                 HSV_86_255_138, HSV_86_255_139, HSV_86_255_140, HSV_86_255_141, HSV_86_255_142, HSV_86_255_143, 
    HSV_86_255_118, HSV_86_255_119, HSV_86_255_120, HSV_86_255_121, HSV_86_255_122, HSV_86_255_123,                                 HSV_86_255_144, HSV_86_255_145, HSV_86_255_146, HSV_86_255_147, HSV_86_255_148, HSV_86_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
  ),
  [22] = LAYOUT_voyager(
    HSV_129_255_100,HSV_129_255_101,HSV_129_255_102,HSV_129_255_103,HSV_129_255_104,HSV_129_255_105,                                HSV_129_255_126,HSV_129_255_127,HSV_129_255_128,HSV_129_255_129,HSV_129_255_130,HSV_129_255_131,
    HSV_129_255_106,HSV_129_255_107,HSV_129_255_108,HSV_129_255_109,HSV_129_255_110,HSV_129_255_111,                                HSV_129_255_132,HSV_129_255_133,HSV_129_255_134,HSV_129_255_135,HSV_129_255_136,HSV_129_255_137,
    HSV_129_255_112,HSV_129_255_113,HSV_129_255_114,HSV_129_255_115,HSV_129_255_116,HSV_129_255_117,                                HSV_129_255_138,HSV_129_255_139,HSV_129_255_140,HSV_129_255_141,HSV_129_255_142,HSV_129_255_143,
    HSV_129_255_118,HSV_129_255_119,HSV_129_255_120,HSV_129_255_121,HSV_129_255_122,HSV_129_255_123,                                HSV_129_255_144,HSV_129_255_145,HSV_129_255_146,HSV_129_255_147,HSV_129_255_148,HSV_129_255_149,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_129_255_151
  ),
};



// -----------------------------------------------------------------------------
//
//
// GitHub C additional
//
//
// -----------------------------------------------------------------------------

#define ORYX_LAYER_COUNT (sizeof(keymaps) / sizeof(keymaps[0]))

#include "layer_num.h"
// enum for layer define sync oryx side
_Static_assert(C_LAYER_COUNT == ORYX_LAYER_COUNT, "C and ORYX layer count missmatch!!");

// access to voyager system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;

// split impl
#include "fade_matrix.h"
#include "ime_state_sync.h"
#include "overlay_layer_mod.h"
#include "status_led.h"

#include "engram_key_overrides.inc"

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
  // self-hold 
  if (layer_state_is(L_Mouse_Cursor_Override)) {
    return true;
  }
  return false;
}

static bool lock_scrolling = false;
static fast_timer_t auto_mouse_early_trigger = 0;

// -----------------------------------------------------------------------------
//
//
// End of GitHub C additional
//
//
// -----------------------------------------------------------------------------


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
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
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
      {
        // local scope for keep press time value
        static uint16_t press_time = 0;

        if (record->event.pressed) {
          press_time = record->event.time;
          set_scrolling = true;
          fast_timer_t now = timer_read_fast();
          status_led(now, 0b0100, led_pattern_on);
        } else {
          uint16_t duration = record->event.time - press_time;
          if (duration < AUTO_MOUSE_DRAG_THRESHOLD) {
            // tap
            if (lock_scrolling) {
              // if locked release lock
              set_scrolling = false;
              fast_timer_t now = timer_read_fast();
              status_led(now, 0b0100, led_pattern_off);
              lock_scrolling = false;
            } else {
              // keep scroll
              //set_scrolling = true;
              //fast_timer_t now = timer_read_fast();
              //status_led(now, 0b0100, led_pattern_on);
              lock_scrolling = true;
            }
          } else {
            // drag, must disable scroll lock
            set_scrolling = false;
            fast_timer_t now = timer_read_fast();
            status_led(now, 0b0100, led_pattern_off);
            lock_scrolling = false;
          }
        }
      }
      return false;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      navigator_turbo = true;
      fast_timer_t now = timer_read_fast();
      status_led(now, 0b0001, led_pattern_on);
    } else {
      navigator_turbo = false;
      fast_timer_t now = timer_read_fast();
      status_led(now, 0b0001, led_pattern_off);
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      navigator_aim = true;
      fast_timer_t now = timer_read_fast();
      status_led(now, 0b0010, led_pattern_on);
    } else {
      navigator_aim = false;
      fast_timer_t now = timer_read_fast();
      status_led(now, 0b0010, led_pattern_off);
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
        fade_matrix_set_mode(RGB_MATRIX_SOLID_COLOR);
      }
      return false;
    
    case HSV_215_255_100:
      if (record->event.pressed) {
        layer_off(L_Base_JIS);
      }
      return false;
    case HSV_215_255_102:
      if (record->event.pressed) {
        ime_state_sync_enable();
      }
      return false;
    case HSV_215_255_106:
      if (record->event.pressed) {
        layer_on(L_Base_JIS);
      }
      return false;
    case HSV_215_255_108:
      if (record->event.pressed) {
        ime_state_sync_disable();
      }
      return false;
    case HSV_215_255_131:
      if (record->event.pressed) {
        reset_keyboard();
      }
      return false;
    case HSV_215_255_149:
      if (record->event.pressed) {
         soft_reset_keyboard();
      }
      return false;

    case HSV_0_255_100:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(0);
      }
      return false;
    case HSV_0_255_101:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(1);
      }
      return false;
    case HSV_0_255_102:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(2);
      }
      return false;
    case HSV_0_255_103:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(3);
      }
      return false;
    case HSV_0_255_104:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(4);
      }
      return false;
    case HSV_0_255_105:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(5);
      }
      return false;
    case HSV_0_255_106:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(6);
      }
      return false;
    case HSV_0_255_107:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(7);
      }
      return false;
    case HSV_0_255_108:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(8);
      }
      return false;
    case HSV_0_255_109:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(9);
      }
      return false;
    case HSV_0_255_110:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(10);
      }
      return false;
    case HSV_0_255_111:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(11);
      }
      return false;
    case HSV_0_255_112:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(12);
      }
      return false;
    case HSV_0_255_113:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(13);
      }
      return false;
    case HSV_0_255_114:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(14);
      }
      return false;
    case HSV_0_255_115:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(15);
      }
      return false;
    case HSV_0_255_116:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(16);
      }
      return false;
    case HSV_0_255_117:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(17);
      }
      return false;
    case HSV_0_255_118:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(18);
      }
      return false;
    case HSV_0_255_119:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(19);
      }
      return false;
    case HSV_0_255_120:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(20);
      }
      return false;
    case HSV_0_255_121:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(21);
      }
      return false;
    case HSV_0_255_122:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(22);
      }
      return false;
    case HSV_0_255_123:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(23);
      }
      return false;
    case HSV_0_255_126:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(26);
      }
      return false;
    case HSV_0_255_127:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(27);
      }
      return false;
    case HSV_0_255_128:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(28);
      }
      return false;
    case HSV_0_255_129:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(29);
      }
      return false;
    case HSV_0_255_130:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(30);
      }
      return false;
    case HSV_0_255_131:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(31);
      }
      return false;
    case HSV_0_255_132:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(32);
      }
      return false;
    case HSV_0_255_133:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(33);
      }
      return false;
    case HSV_0_255_134:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(34);
      }
      return false;
    case HSV_0_255_135:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(35);
      }
      return false;
    case HSV_0_255_136:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(36);
      }
      return false;
    case HSV_0_255_137:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(37);
      }
      return false;
    case HSV_0_255_138:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(38);
      }
      return false;
    case HSV_0_255_139:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(39);
      }
      return false;
    case HSV_0_255_140:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(40);
      }
      return false;
    case HSV_0_255_141:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(41);
      }
      return false;
    case HSV_0_255_142:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(42);
      }
      return false;
    case HSV_0_255_143:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(43);
      }
      return false;
    case HSV_0_255_144:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(44);
      }
      return false;
    case HSV_0_255_145:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(45);
      }
      return false;
    case HSV_0_255_146:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(46);
      }
      return false;
    case HSV_0_255_147:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(47);
      }
      return false;
    case HSV_0_255_148:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(48);
      }
      return false;
    case HSV_0_255_149:
      if (record->event.pressed) {
        fade_matrix_set_speed_pos(49);
      }
      return false;
    case HSV_0_255_151:
      if (record->event.pressed) {
        fade_matrix_load_preset_powersave();
        fast_timer_t now = timer_read_fast();
        status_led(now, 0b0101, led_pattern_oneshot);
      }
      return false;
    
    case HSV_43_255_100:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(0);
      }
      return false;
    case HSV_43_255_101:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(1);
      }
      return false;
    case HSV_43_255_102:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(2);
      }
      return false;
    case HSV_43_255_103:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(3);
      }
      return false;
    case HSV_43_255_104:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(4);
      }
      return false;
    case HSV_43_255_105:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(5);
      }
      return false;
    case HSV_43_255_106:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(6);
      }
      return false;
    case HSV_43_255_107:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(7);
      }
      return false;
    case HSV_43_255_108:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(8);
      }
      return false;
    case HSV_43_255_109:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(9);
      }
      return false;
    case HSV_43_255_110:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(10);
      }
      return false;
    case HSV_43_255_111:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(11);
      }
      return false;
    case HSV_43_255_112:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(12);
      }
      return false;
    case HSV_43_255_113:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(13);
      }
      return false;
    case HSV_43_255_114:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(14);
      }
      return false;
    case HSV_43_255_115:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(15);
      }
      return false;
    case HSV_43_255_116:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(16);
      }
      return false;
    case HSV_43_255_117:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(17);
      }
      return false;
    case HSV_43_255_118:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(18);
      }
      return false;
    case HSV_43_255_119:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(19);
      }
      return false;
    case HSV_43_255_120:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(20);
      }
      return false;
    case HSV_43_255_121:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(21);
      }
      return false;
    case HSV_43_255_122:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(22);
      }
      return false;
    case HSV_43_255_123:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(23);
      }
      return false;
    case HSV_43_255_126:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(26);
      }
      return false;
    case HSV_43_255_127:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(27);
      }
      return false;
    case HSV_43_255_128:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(28);
      }
      return false;
    case HSV_43_255_129:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(29);
      }
      return false;
    case HSV_43_255_130:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(39);
      }
      return false;
    case HSV_43_255_131:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(31);
      }
      return false;
    case HSV_43_255_132:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(32);
      }
      return false;
    case HSV_43_255_133:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(33);
      }
      return false;
    case HSV_43_255_134:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(34);
      }
      return false;
    case HSV_43_255_135:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(35);
      }
      return false;
    case HSV_43_255_136:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(36);
      }
      return false;
    case HSV_43_255_137:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(37);
      }
      return false;
    case HSV_43_255_138:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(38);
      }
      return false;
    case HSV_43_255_139:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(39);
      }
      return false;
    case HSV_43_255_140:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(40);
      }
      return false;
    case HSV_43_255_141:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(41);
      }
      return false;
    case HSV_43_255_142:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(42);
      }
      return false;
    case HSV_43_255_143:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(43);
      } 
      return false;
    case HSV_43_255_144:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(44);
      }
      return false;
    case HSV_43_255_145:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(45);
      }
      return false;
    case HSV_43_255_146:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(46);
      }
      return false;
    case HSV_43_255_147:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(47);
      }
      return false;
    case HSV_43_255_148:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(48);
      }
      return false;
    case HSV_43_255_149:
      if (record->event.pressed) {
        fade_matrix_set_val_pos(49);
      }
      return false;

    case HSV_86_255_100:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(0);
      }
      return false;
    case HSV_86_255_101:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(1);
      }
      return false;
    case HSV_86_255_102:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(2);
      }
      return false;
    case HSV_86_255_103:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(3);
      }
      return false;
    case HSV_86_255_104:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(4);
      }
      return false;
    case HSV_86_255_105:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(5);
      }
      return false;
    case HSV_86_255_106:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(6);
      }
      return false;
    case HSV_86_255_107:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(7);
      }
      return false;
    case HSV_86_255_108:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(8);
      }
      return false;
    case HSV_86_255_109:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(9);
      }
      return false;
    case HSV_86_255_110:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(10);
      }
      return false;
    case HSV_86_255_111:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(11);
      }
      return false;
    case HSV_86_255_112:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(12);
      }
      return false;
    case HSV_86_255_113:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(13);
      }
      return false;
    case HSV_86_255_114:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(14);
      }
      return false;
    case HSV_86_255_115:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(15);
      }
      return false;
    case HSV_86_255_116:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(16);
      }
      return false;
    case HSV_86_255_117:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(17);
      }
      return false;
    case HSV_86_255_118:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(18);
      }
      return false;
    case HSV_86_255_119:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(19);
      }
      return false;
    case HSV_86_255_120:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(20);
      }
      return false;
    case HSV_86_255_121:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(21);
      }
      return false;
    case HSV_86_255_122:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(22);
      }
      return false;
    case HSV_86_255_123:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(23);
      }
      return false;
    case HSV_86_255_126:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(26);
      }
      return false;
    case HSV_86_255_127:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(27);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(28);
      }
      return false;
    case HSV_86_255_129:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(29);
      }
      return false;
    case HSV_86_255_130:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(30);
      }
      return false;
    case HSV_86_255_131:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(31);
      }
      return false;
    case HSV_86_255_132:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(32);
      }
      return false;
    case HSV_86_255_133:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(33);
      }
      return false;
    case HSV_86_255_134:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(34);
      }
      return false;
    case HSV_86_255_135:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(35);
      }
      return false;
    case HSV_86_255_136:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(36);
      }
      return false;
    case HSV_86_255_137:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(37);
      }
      return false;
    case HSV_86_255_138:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(38);
      }
      return false;
    case HSV_86_255_139:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(39);
      }
      return false;
    case HSV_86_255_140:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(40);
      }
      return false;
    case HSV_86_255_141:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(41);
      }
      return false;
    case HSV_86_255_142:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(42);
      }
      return false;
    case HSV_86_255_143:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(43);
      }
      return false;
    case HSV_86_255_144:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(44);
      }
      return false;
    case HSV_86_255_145:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(45);
      }
      return false;
    case HSV_86_255_146:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(46);
      }
      return false;
    case HSV_86_255_147:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(47);
      }
      return false;
    case HSV_86_255_148:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(48);
      }
      return false;
    case HSV_86_255_149:
      if (record->event.pressed) {
        fade_matrix_set_sat_pos(49);
      }
      return false;
    
    case HSV_129_255_100:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(0);
      }
      return false;
    case HSV_129_255_101:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(1);
      }
      return false;
    case HSV_129_255_102:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(2);
      }
      return false;
    case HSV_129_255_103:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(3);
      }
      return false;
    case HSV_129_255_104:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(4);
      }
      return false;
    case HSV_129_255_105:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(5);
      }
      return false;
    case HSV_129_255_106:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(6);
      }
      return false;
    case HSV_129_255_107:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(7);
      }
      return false;
    case HSV_129_255_108:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(8);
      }
      return false;
    case HSV_129_255_109:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(9);
      }
      return false;
    case HSV_129_255_110:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(10);
      }
      return false;
    case HSV_129_255_111:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(11);
      }
      return false;
    case HSV_129_255_112:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(12);
      }
      return false;
    case HSV_129_255_113:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(13);
      }
      return false;
    case HSV_129_255_114:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(14);
      }
      return false;
    case HSV_129_255_115:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(15);
      }
      return false;
    case HSV_129_255_116:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(16);
      }
      return false;
    case HSV_129_255_117:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(17);
      }
      return false;
    case HSV_129_255_118:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(18);
      }
      return false;
    case HSV_129_255_119:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(19);
      }
      return false;
    case HSV_129_255_120:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(20);
      }
      return false;
    case HSV_129_255_121:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(21);
      }
      return false;
    case HSV_129_255_122:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(22);
      }
      return false;
    case HSV_129_255_123:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(23);
      }
      return false;
    case HSV_129_255_126:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(26);
      }
      return false;
    case HSV_129_255_127:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(27);
      }
      return false;
    case HSV_129_255_128:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(28);
      }
      return false;
    case HSV_129_255_129:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(29);
      }
      return false;
    case HSV_129_255_130:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(30);
      }
      return false;
    case HSV_129_255_131:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(31);
      }
      return false;
    case HSV_129_255_132:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(32);
      }
      return false;
    case HSV_129_255_133:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(33);
      }
      return false;
    case HSV_129_255_134:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(34);
      }
      return false;
    case HSV_129_255_135:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(35);
      }
      return false;
    case HSV_129_255_136:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(36);
      }
      return false;
    case HSV_129_255_137:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(37);
      }
      return false;
    case HSV_129_255_138:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(38);
      }
      return false;
    case HSV_129_255_139:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(39);
      }
      return false;
    case HSV_129_255_140:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(40);
      }
      return false;
    case HSV_129_255_141:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(41);
      }
      return false;
    case HSV_129_255_142:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(42);
      }
      return false;
    case HSV_129_255_143:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(43);
      }
      return false;
    case HSV_129_255_144:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(44);
      }
      return false;
    case HSV_129_255_145:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(45);
      }
      return false;
    case HSV_129_255_146:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(46);
      }
      return false;
    case HSV_129_255_147:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(47);
      }
      return false;
    case HSV_129_255_148:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(48);
      }
      return false;
    case HSV_129_255_149:
      if (record->event.pressed) {
        fade_matrix_set_hue_pos(49);
      }
      return false;
    case HSV_129_255_151:
      if (record->event.pressed) {
        fade_matrix_load_preset();
        fast_timer_t now = timer_read_fast();
        status_led(now, 0b1010, led_pattern_oneshot);
      }
      return false;

    //RGB inc/dec no eeprom over write
    // always return false (sometime use upedge)
    case RGB_HUI:
      if (record->event.pressed) {
        fade_matrix_increase_hue();
      }
      return false;
    case RGB_HUD:
      if (record->event.pressed) {
        fade_matrix_decrease_hue();
      }
      return false;
    case RGB_SAI:
      if (record->event.pressed) {
        fade_matrix_increase_sat();
      }
      return false;
    case RGB_SAD:
      if (record->event.pressed) {
        fade_matrix_decrease_sat();
      }
      return false;
    case RGB_VAI:
      if (record->event.pressed) {
        fade_matrix_increase_val();
      }
      return false;
    case RGB_VAD:
      if (record->event.pressed) {
        fade_matrix_decrease_val();
      }
      return false;
    case RGB_SPI:
      if (record->event.pressed) {
        fade_matrix_increase_speed();
      }
      return false;
    case RGB_SPD:
      if (record->event.pressed) {
        fade_matrix_decrease_speed();
      }
      return false;
    case RGB_TOG:
      if (record->event.pressed) {
        fade_matrix_toggle();
      }
      return false;
    case RGB_MODE_FORWARD:
      if (record->event.pressed) {
        fade_matrix_step();
      }
      return false;
    
    // auto mouse EXIT keys (dummy keycode)
    case KC_LANGUAGE_6:
      if (record->event.pressed) {
        auto_mouse_layer_off();
      }
      return false;
    
    // early auto mouse timeout
    case KC_MS_BTN1:
    case KC_MS_BTN2:
    case KC_MS_BTN3:
    case KC_MS_BTN4:
    case KC_MS_BTN5:
    case KC_MS_BTN6:
    case KC_MS_BTN7:
    case KC_MS_BTN8:
      {
        if (record->event.key.row < MATRIX_ROWS / 2) {
          // left side mouse button
          static uint16_t press_time[8];
          if (record->event.pressed) {
            press_time[keycode - KC_MS_BTN1] = record->event.time;
            // early trigger reset on auto_mouse_activation
          } else {
            uint16_t duration = record->event.time - press_time[keycode - KC_MS_BTN1];
            if (duration < AUTO_MOUSE_DRAG_THRESHOLD) {
              fast_timer_t now = timer_read_fast();
              auto_mouse_early_trigger = now + AUTO_MOUSE_TIME_LEFT_SIDE;
            }
          }
        } else {
          // right side mouse button
          static uint16_t press_time[8];
          if (record->event.pressed) {
            press_time[keycode - KC_MS_BTN1] = record->event.time;
            // early trigger reset on auto_mouse_activation
          } else {
            uint16_t duration = record->event.time - press_time[keycode - KC_MS_BTN1];
            if (duration < AUTO_MOUSE_DRAG_THRESHOLD) {
              fast_timer_t now = timer_read_fast();
              auto_mouse_early_trigger = now + AUTO_MOUSE_TIME_RIGHT_SIDE;
            }
          }
        }
      }
      // pass to main process
      return true; 
  }

  if (process_record_ime_state_sync(keycode, record) == false) {
    return false;
  }
  
  return true;
}


// -----------------------------------------------------------------------------
//
//
// GitHub C implementation additional
//
//
// -----------------------------------------------------------------------------

void keyboard_post_init_user(void) {
  keymap_config.nkro = true;

  fast_timer_t now = timer_read_fast();
  init_fade_matrix(now);
  status_led(now, 0b1111, led_pattern_off);

  auto_mouse_early_trigger = now + (UINT32_MAX / 2) - 1;
  
  //ANSI
  layer_move(L_Base);
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  fast_timer_t now = timer_read_fast();
  switch (detected_os) {
    case OS_MACOS:
      fade_matrix_load_preset();
      status_led(now, 0b1000, led_pattern_oneshot);
      break;
    case OS_IOS:
      fade_matrix_load_preset_powersave();
      status_led(now, 0b0100, led_pattern_oneshot);
      break;
    case OS_WINDOWS:
      fade_matrix_load_preset();
      status_led(now, 0b0010, led_pattern_oneshot);
      break;
    case OS_LINUX:
      fade_matrix_load_preset_powersave();
      status_led(now, 0b0001, led_pattern_oneshot);
      break;
    case OS_UNSURE:
      status_led(now, 0b1111, led_pattern_oneshot);
      status_led(now, 0b1111, led_pattern_oneshot);
      status_led(now, 0b1111, led_pattern_oneshot);
      break;
  }
    
  return true;
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
      case LT(L_Number, KC_SPACE):
      case LT(L_Cursor, KC_SPACE):
      case LT(L_LeftPinky, KC_B):
      case LT(L_LeftPinky, KC_F11):
      case LT(L_LeftPinky, KC_LBRC):
      case LT(L_LeftPinky, KC_RBRC):
      case LT(L_RightPinky, KC_V):
      case LT(L_RightPinky, KC_F12):
      case LT(L_RightPinky, KC_RBRC):
      case LT(L_RightPinky, KC_BSLS):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  return 0;  // Disable Flow Tap.
}

layer_state_t layer_state_set_user(layer_state_t state) {
  //both thumb
  state = update_tri_layer_state(state, L_Number, L_Cursor, L_BothThumb);
  
  //tumb and outer pin
  state = update_tri_layer_state(state, L_LeftPinky, L_Number, L_LeftPinkyThumb);
  state = update_tri_layer_state(state, L_RightPinky, L_Cursor, L_RightPinkyThumb);
  
  //both outer pin
  state = update_tri_layer_state(state, L_LeftPinky, L_RightPinky, L_BothPinky);

  // both thumb and pin
  state = update_tri_layer_state(state, L_LeftPinkyThumb, L_RightPinkyThumb, L_BothPinkyThumb);

  // call FwSys with Bkt and Fn
  state = update_tri_layer_state(state, L_Cursor, L_Function, L_Firmware); 

  // if speed layer active, MO guard, block base tap tap side
  state = update_tri_layer_state(state, L_Set_Speed, L_Set_Speed, L_MO_Guard); 
  
  // call color settng
  state = update_tri_layer_state(state, L_Function, L_Set_Speed, L_Set_Val); 
  state = update_tri_layer_state(state, L_Cursor, L_Set_Speed, L_Set_Sat); 
  
  // call Hue with Sat and Val
  state = update_tri_layer_state(state, L_Set_Val, L_Set_Sat, L_Set_Hue);
  
  // on mouse, cursor override
  state = update_tri_layer_state(state, L_Mouse, L_Cursor, L_Mouse_Cursor_Override);
  
  // ANSI/JIS addiional enable
  state = update_tri_layer_state(state, L_Base_JIS, L_Number, L_Number_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_Cursor, L_Cursor_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_BothThumb, L_BothThumb_JIS);
  
  // drag scroll lock release
  //if (layer_state_cmp(state, L_Mouse) == false) {
  //  lock_scrolling = false;
  //}
  
  // mouse scroll by layer
  if (layer_state_cmp(state, L_Number)) {
    set_scrolling = true;
    lock_scrolling = false;
  } else if (layer_state_cmp(state, L_Cursor)) {
    set_scrolling = true;
    lock_scrolling = false;
  } else {
    set_scrolling = lock_scrolling;
  }

  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  fast_timer_t now = timer_read_fast();
  
  switch (layer) {
    case L_Base :
    case L_Base_JIS:
    case L_MO_Guard:
      status_led(now, 0b1011, led_pattern_off);
      
      if (set_scrolling) {
        status_led(now, 0b0100, led_pattern_on);
      } else {
        status_led(now, 0b0100, led_pattern_off);
      }
      break;
    case L_Function:
      status_led(now, 0b1100, led_pattern_off);
      status_led(now, 0b0011, led_pattern_on);
      break; 
    case L_Number:
    case L_Number_JIS:
    case L_Cursor:
    case L_Cursor_JIS:
      status_led(now, 0b1011, led_pattern_off);
      status_led(now, 0b0100, led_pattern_on);
      break; 
    case L_LeftPinky:
    case L_RightPinky:
    case L_LeftPinkyThumb:
    case L_RightPinkyThumb:
    case L_BothThumb:
    case L_BothThumb_JIS:
    case L_BothPinky:
    case L_BothPinkyThumb:
      break;
    case L_Mouse:
    case L_Mouse_Cursor_Override:
      // mouse indication
      status_led(now, 0b0011, led_pattern_off);
      status_led(now, 0b1000, led_pattern_on);

      if (set_scrolling) {
        status_led(now, 0b0100, led_pattern_on);
      } else {
        status_led(now, 0b0100, led_pattern_off);
      }
      // DRAG_SCROLL add on key event

      // aim/turbo change without layer, direct write on process_record
      break;
    case L_Firmware:
      status_led(now, 0b0011, led_pattern_off);
      status_led(now, 0b1100, led_pattern_blink);
      break;
    case L_Set_Speed:
      status_led(now, 0b0011, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      break;    
    case L_Set_Val:
      status_led(now, 0b0001, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0010, led_pattern_blink);
      break;
    case L_Set_Sat:
      status_led(now, 0b0010, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0001, led_pattern_blink);
      break;
    case L_Set_Hue:
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0011, led_pattern_blink);
      break;

    default:
      status_led(now, 0b1111, led_pattern_off);
      break;
  }  
  return state;
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (get_highest_layer(layer_state)) {
    case L_Mouse:
    case L_Mouse_Cursor_Override:
      set_layer_color_mouse_map();
      break;    
    case L_Firmware:
      set_layer_color_firmware_map();
      set_layer_color_firmware_map_ime_state_sync();
      break;
    case L_Set_Speed:
      set_layer_color_speed_map();
      break;    
    case L_Set_Val:
      set_layer_color_val_map();
      break;
    case L_Set_Sat:
      set_layer_color_sat_map();
      break;
    case L_Set_Hue:
      set_layer_color_hue_map();
      break;
    
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      } else {
        set_layer_color_overlay_mod();
        set_layer_color_overlay_ime_state_sync();
        set_layer_color_overlay_layer();
      }
      break;
  }
  return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (pre_process_record_ime_state_sync(keycode, record) == false) {
    return false;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    fast_timer_t now = timer_read_fast();

    activate_fade_matrix(now);
    activate_ime_state_sync(now);
  }
  return;
}

// copy & custom from pointing_device_auto_mouse.c
bool auto_mouse_activation(report_mouse_t mouse_report) {
  static total_mouse_movement_t total_move_local = {
    .x = 0,
    .y = 0,
    .h = 0,
    .v = 0,
  };

  // both state check xy move
  total_move_local.x += mouse_report.x;
  total_move_local.y += mouse_report.y;

  bool activate = false;

  if (is_auto_mouse_active() == false) {
    // non active
    activate = activate || abs(total_move_local.x) > AUTO_MOUSE_THRESHOLD;
    activate = activate || abs(total_move_local.y) > AUTO_MOUSE_THRESHOLD;
  } else {
    // active
    activate = activate || abs(total_move_local.x) > AUTO_MOUSE_CONT_THRESHOLD;
    activate = activate || abs(total_move_local.y) > AUTO_MOUSE_CONT_THRESHOLD;  
    
    // active, additional check wheel and button
    total_move_local.h += mouse_report.h;
    total_move_local.v += mouse_report.v;
    
    activate = activate || abs(total_move_local.h) > AUTO_MOUSE_SCROLL_THRESHOLD;
    activate = activate || abs(total_move_local.v) > AUTO_MOUSE_SCROLL_THRESHOLD;
    activate = activate || mouse_report.buttons;
  }

  if (activate) {
    fast_timer_t now = timer_read_fast();
    auto_mouse_early_trigger = now + (UINT32_MAX / 2) - 1;
      
    // wakeup RGB
    activate_fade_matrix(now);
    
    total_move_local.x = 0;
    total_move_local.y = 0;
    total_move_local.h = 0;
    total_move_local.v = 0;
  }
  
  return activate;    
}

void housekeeping_task_user(void) {
  fast_timer_t now = timer_read_fast();
  
  if (timer_expired_fast(now, auto_mouse_early_trigger)) {
    auto_mouse_layer_off();
    auto_mouse_early_trigger = now + (UINT32_MAX / 2) - 1;
  }
  
  update_fade_matrix(now);
  update_ime_state_sync(now);
  update_status_led(now);
  
  return;
}
