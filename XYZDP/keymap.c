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
};



#define DUAL_FUNC_0 LT(15, KC_F15)
#define DUAL_FUNC_1 LT(11, KC_N)
#define DUAL_FUNC_2 LT(15, KC_F)
#define DUAL_FUNC_3 LT(1, KC_5)
#define DUAL_FUNC_4 LT(5, KC_Z)
#define DUAL_FUNC_5 LT(4, KC_D)
#define DUAL_FUNC_6 LT(2, KC_5)
#define DUAL_FUNC_7 LT(4, KC_F5)
#define DUAL_FUNC_8 LT(7, KC_8)
#define DUAL_FUNC_9 LT(11, KC_B)
#define DUAL_FUNC_10 LT(10, KC_F1)
#define DUAL_FUNC_11 LT(3, KC_F19)
#define DUAL_FUNC_12 LT(10, KC_E)
#define DUAL_FUNC_13 LT(9, KC_W)
#define DUAL_FUNC_14 LT(7, KC_U)
#define DUAL_FUNC_15 LT(11, KC_W)
#define DUAL_FUNC_16 LT(13, KC_F6)
#define DUAL_FUNC_17 LT(13, KC_4)
#define DUAL_FUNC_18 LT(12, KC_5)
#define DUAL_FUNC_19 LT(11, KC_F19)
#define DUAL_FUNC_20 LT(12, KC_V)
#define DUAL_FUNC_21 LT(12, KC_Y)

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
};

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#include "layer_num.h"
// enum for layer define sync oryx side
#define ORYX_LAYER_COUNT (sizeof(keymaps) / sizeof(keymaps[0]))
_Static_assert(C_LAYER_COUNT == ORYX_LAYER_COUNT, "C and ORYX layer count missmatch!!");

#include "engram_key_overrides.inc"

// access to voyager system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;

#include "fade_matrix.h"
#include "status_led.h"

// timer maximum delay
// #define timer_expired32(current, future) ((uint32_t)(current - future) < UINT32_MAX / 2)
// sub safety 14400000 ms (14400 sec = 240 min = 4 hour)
static const fast_timer_t maximum_delay = (UINT32_MAX / 2) - 14400000;

static void set_layer_color_overlay(void);
static void set_layer_color_firmware_map(void);

// ime state from LANG1/LANG2 key
static bool ime_on = false;
static bool ime_kk = false;  //KataKana

// Ime State Sync system
static bool iss_enable = true; 
static bool iss_sync = false;

static fast_timer_t iss_sync_trigger = 0;
static const fast_timer_t iss_sync_delay = 15013; //ms

static fast_timer_t iss_idle_trigger = 0;
static const fast_timer_t iss_idle_delay = 600011; //ms

// Ime State Display system

void keyboard_post_init_user(void) {
  keymap_config.nkro = true;

  fast_timer_t now = timer_read_fast();
  init_fade_matrix(now);
  status_led(now, 0b1111, led_pattern_off);
  
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

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (get_highest_layer(layer_state)) {
    case L_Firmware:
      set_layer_color_firmware_map();
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
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      else
        set_layer_color_overlay();
      break;
  }
  return true;
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
  state = update_tri_layer_state(state, L_Function, L_Cursor, L_Firmware); 

  // if speed layer active, MO guard, block base tap tap side
  state = update_tri_layer_state(state, L_Set_Speed, L_Set_Speed, L_MO_Guard); 
  
  // call color settng
  state = update_tri_layer_state(state, L_Function, L_Set_Speed, L_Set_Val); 
  state = update_tri_layer_state(state, L_Cursor, L_Set_Speed, L_Set_Sat); 

  // call Hue with Sat and Val
  state = update_tri_layer_state(state, L_Set_Val, L_Set_Sat, L_Set_Hue);
  
  //ANSI/JIS addiional enable
  state = update_tri_layer_state(state, L_Base_JIS, L_Number, L_Number_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_Cursor, L_Cursor_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_BothThumb, L_BothThumb_JIS);
  
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  fast_timer_t now = timer_read_fast();
  
  switch (layer) {
    case L_Base :
    case L_Base_JIS:
      status_led(now, 0b1111, led_pattern_off);
      break;
    case L_Function:
      status_led(now, 0b1100, led_pattern_off);
      status_led(now, 0b0011, led_pattern_on);
      break;
    case L_Number:
    case L_Number_JIS:
      //status_led(now, 0b1100, led_pattern_off);
      //status_led(now, 0b0001, led_pattern_on);
      //status_led(now, 0b0010, led_pattern_blink);
      break;
    case L_Cursor:
    case L_Cursor_JIS:
      //status_led(now, 0b1100, led_pattern_off);
      //status_led(now, 0b0010, led_pattern_on);
      //status_led(now, 0b0001, led_pattern_blink);
      break;
    case L_LeftPinky:
      //status_led(now, 0b0110, led_pattern_off);
      //status_led(now, 0b0001, led_pattern_on);
      //status_led(now, 0b1000, led_pattern_blink);
      break;
    case L_RightPinky:
      //status_led(now, 0b1001, led_pattern_off);
      //status_led(now, 0b0010, led_pattern_on);
      //status_led(now, 0b0100, led_pattern_blink);
      break;
    case L_LeftPinkyThumb:
      //status_led(now, 0b0100, led_pattern_off);
      //status_led(now, 0b0001, led_pattern_on);
      //status_led(now, 0b1010, led_pattern_blink);
      break;
    case L_RightPinkyThumb:
      //status_led(now, 0b1000, led_pattern_off);
      //status_led(now, 0b0010, led_pattern_on);
      //status_led(now, 0b0101, led_pattern_blink);
      break;
    case L_BothThumb:
    case L_BothThumb_JIS:
      //status_led(now, 0b1100, led_pattern_off);
      //status_led(now, 0b0011, led_pattern_blink);
      break;
    case L_BothPinky:
      //status_led(now, 0b0011, led_pattern_on);
      //status_led(now, 0b1100, led_pattern_blink);
      break;
    case L_BothPinkyThumb:
      //status_led(now, 0b1111, led_pattern_blink);
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

    default :
      status_led(now, 0b1111, led_pattern_off);
      break;
  }  
  return state;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (iss_enable) {
    if(iss_sync) {
      iss_sync = false;
      if (ime_on) {
        if (ime_kk) {
          tap_code16(LSFT(KC_LANGUAGE_1));
        } else {
          tap_code16(KC_LANGUAGE_1);
        }
      } else {
        tap_code16(KC_LANGUAGE_2);
      }
    }
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    fast_timer_t now = timer_read_fast();

    activate_fade_matrix(now);
    
    if (iss_enable) {
      iss_sync_trigger = now + iss_sync_delay;
      iss_idle_trigger = now + iss_idle_delay;
    }
  }
  
  return;
}

void housekeeping_task_user(void) {
  fast_timer_t now = timer_read_fast();

  update_fade_matrix(now);
  update_status_led(now);
  
  if (timer_expired_fast(now, iss_sync_trigger)) {
    iss_sync_trigger += maximum_delay;
    iss_sync = true;   
  }
  
  if (timer_expired_fast(now, iss_idle_trigger)) {
    iss_idle_trigger += maximum_delay;
    iss_sync = false;
    ime_on = false;
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
        iss_enable = true;
      }
      return false;
    case HSV_215_255_106:
      if (record->event.pressed) {
        layer_on(L_Base_JIS);
      }
      return false;
    case HSV_215_255_108:
      if (record->event.pressed) {
        iss_enable = false;
        iss_sync = false;
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

    //IME state display (update flag & re-calc status)
    case LT(L_Function, KC_LANGUAGE_1):
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          if (layer_state_is(L_LeftPinky) | layer_state_is(L_RightPinky) | layer_state_is(L_Function) |
            layer_state_is(L_Number) | layer_state_is(L_Cursor)) {
            // reverse side (upper layer)
            if ((get_mods() & MOD_MASK_CSAG) == 0) {
              ime_on = false;
            }
            tap_code16(KC_LANGUAGE_2);
            return false;
          } else {
            // normal side (base layer)
            if ((get_mods() & MOD_MASK_CAG) == 0) {
              ime_on = true;
              if (get_mods() & MOD_MASK_SHIFT) {
                ime_kk = true;
              } else {
                ime_kk = false;
              }
            }
          }
        }
      }
      return true;
    
    case KC_LANGUAGE_2:
      if (record->event.pressed) {
        if (layer_state_is(L_LeftPinky) | layer_state_is(L_RightPinky) | layer_state_is(L_Function) |
          layer_state_is(L_Number) | layer_state_is(L_Cursor)) {
          // reverse side (upper layer)
          if ((get_mods() & MOD_MASK_CAG) == 0) {
            ime_on = true;
            if (get_mods() & MOD_MASK_SHIFT) {
              ime_kk = true;
            } else {
              ime_kk = false;
            }
          }
          tap_code16(KC_LANGUAGE_1);
          return false;
        } else {
          // normal side (base layer)
          if ((get_mods() & MOD_MASK_CSAG) == 0) {
            ime_on = false;
          }
        }
      }
      return true;
  }
  return true;
}

// local functions
// basic static 
static void set_layer_color_overlay(void) {
  // use golden angle 255 * phi
  const uint8_t h_diff = 97;
  
  HSV hsv = rgb_matrix_get_hsv();
  hsv.h -= g_rgb_timer >> 4;
  hsv.s = 255;
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  uint8_t speed = rgb_matrix_get_speed(); 
  uint16_t time = scale16by8(g_rgb_timer, speed / 3);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

  // CAPS WORD inidication
  
  if (is_caps_word_on()) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
  }

  // mods display
  if (get_mods() & MOD_BIT_LCTRL) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LSHIFT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LALT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_LGUI) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(7, rgb.r, rgb.g, rgb.b);
  }
  
  if (get_mods() & MOD_BIT_RCTRL) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(27, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(42, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(43, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RSHIFT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(28, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(41, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RALT) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(35, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RGUI) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(36, rgb.r, rgb.g, rgb.b);
  }

  // IME state sync syntem state
  if (ime_on) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(44, rgb.r, rgb.g, rgb.b);
    
    if (ime_kk) {
      rgb_matrix_set_color(38, rgb.r, rgb.g, rgb.b);
    } else {
      rgb_matrix_set_color(38, 0, 0, 0);
    }
    
    if (iss_sync) {
      rgb_matrix_set_color(23, rgb.r, rgb.g, rgb.b);
    } else {
      rgb_matrix_set_color(23, 0, 0, 0);
    }
    rgb_matrix_set_color(5, 0, 0, 0);
    rgb_matrix_set_color(11, 0, 0, 0);
    rgb_matrix_set_color(17, 0, 0, 0);
    rgb_matrix_set_color(26, 0, 0, 0);
    rgb_matrix_set_color(32, 0, 0, 0);
  }
  
  // layer display with priority
  if (layer_state_is(L_BothPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_BothPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_BothThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_RightPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    
    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);

    return;
  }
  if (layer_state_is(L_LeftPinkyThumb)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);

    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_RightPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_LeftPinky)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_Cursor)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
    return;
  }
  if (layer_state_is(L_Number)) {
    hsv.h -= h_diff;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);
    return;
  }
}

void set_layer_color_firmware_map(void) {
  const uint8_t f = rgb_matrix_get_val();
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
  if (layer_state_is(L_Base_JIS)) {
    //JIS base enable
    rgb_matrix_set_color(0, o, 0, 0);
    rgb_matrix_set_color(6, 0, f, 0);
  } else {
    //ANSI base
    rgb_matrix_set_color(0, f, 0, 0);
    rgb_matrix_set_color(6, 0, o, 0);
  }

  //ISS
  if (iss_enable) {
    rgb_matrix_set_color(2, 0, f, 0);
    rgb_matrix_set_color(8, o, o, o);
  } else {
    //ANSI base
    rgb_matrix_set_color(2, o, o, o);
    rgb_matrix_set_color(8, f, f, f);
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

  //reset
  rgb_matrix_set_color(31, f, 0, 0);
  rgb_matrix_set_color(49, f, 0, 0);
}
