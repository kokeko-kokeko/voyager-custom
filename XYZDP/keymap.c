#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_43_255_100,
  HSV_43_255_102,
  HSV_43_255_106,
  HSV_43_255_108,
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
};



#define DUAL_FUNC_0 LT(12, KC_F5)
#define DUAL_FUNC_1 LT(2, KC_F24)
#define DUAL_FUNC_2 LT(2, KC_T)
#define DUAL_FUNC_3 LT(15, KC_R)
#define DUAL_FUNC_4 LT(4, KC_F23)
#define DUAL_FUNC_5 LT(4, KC_F24)
#define DUAL_FUNC_6 LT(12, KC_U)
#define DUAL_FUNC_7 LT(3, KC_X)
#define DUAL_FUNC_8 LT(15, KC_F14)
#define DUAL_FUNC_9 LT(6, KC_O)
#define DUAL_FUNC_10 LT(15, KC_L)
#define DUAL_FUNC_11 LT(9, KC_6)
#define DUAL_FUNC_12 LT(11, KC_F12)
#define DUAL_FUNC_13 LT(3, KC_1)
#define DUAL_FUNC_14 LT(1, KC_F)
#define DUAL_FUNC_15 LT(5, KC_6)
#define DUAL_FUNC_16 LT(10, KC_4)
#define DUAL_FUNC_17 LT(6, KC_F14)
#define DUAL_FUNC_18 LT(9, KC_F1)
#define DUAL_FUNC_19 LT(6, KC_G)
#define DUAL_FUNC_20 LT(1, KC_X)
#define DUAL_FUNC_21 LT(11, KC_7)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_1,           KC_2,           KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_3,           KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    LT(7, KC_B),    MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(8, KC_V),    
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),MT(MOD_LSFT, KC_X),KC_J,           KC_K,           KC_MINUS,                                       KC_4,           KC_R,           KC_M,           MT(MOD_RSFT, KC_F),MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(3, KC_SPACE),KC_LANGUAGE_2,                                  LT(2, KC_LANGUAGE_1),LT(5, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(2, KC_TAB),  LT(5, KC_ESCAPE),                                LT(3, KC_BSPC), KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_LBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,                                           KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(7, KC_F11),  MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),LT(8, KC_F12),  
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),MT(MOD_LSFT, KC_F12),KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         MT(MOD_RSFT, KC_F19),MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(7, KC_LBRC), MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),LT(8, KC_RBRC), 
    DUAL_FUNC_0,    DUAL_FUNC_1,    MT(MOD_LSFT, KC_EQUAL),KC_TILD,        KC_PLUS,        KC_LABK,                                        KC_RABK,        KC_CIRC,        KC_AMPR,        DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,    
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(7, KC_RBRC), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(8, KC_BSLS), 
    DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,    LSFT(KC_EQUAL), LSFT(KC_SCLN),  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       LSFT(KC_6),     KC_TRANSPARENT, DUAL_FUNC_8,    DUAL_FUNC_9,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    CW_TOGG,        KC_HOME,        KC_END,         KC_PAGE_UP,     KC_PGDN,        KC_LPRN,                                        KC_RPRN,        LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_APPLICATION, KC_BSPC,        
    KC_TRANSPARENT, DUAL_FUNC_10,   DUAL_FUNC_11,   DUAL_FUNC_12,   DUAL_FUNC_13,   KC_SCLN,                                        KC_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    KC_LEFT_CTRL,   DUAL_FUNC_14,   DUAL_FUNC_15,   KC_LCBR,        KC_LBRC,        KC_UNDS,                                        KC_EXLM,        KC_RBRC,        KC_RCBR,        DUAL_FUNC_16,   DUAL_FUNC_17,   KC_RIGHT_CTRL,  
    QK_LLCK,        KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_8),                                     LSFT(KC_9),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DUAL_FUNC_18,   KC_TRANSPARENT, LSFT(KC_RBRC),  KC_RBRC,        LSFT(KC_INTERNATIONAL_1),                                KC_TRANSPARENT, KC_BSLS,        LSFT(KC_BSLS),  KC_TRANSPARENT, DUAL_FUNC_19,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
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
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     LGUI(KC_V),                                     KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    
    KC_LEFT_CTRL,   DUAL_FUNC_20,   DUAL_FUNC_21,   ST_MACRO_7,     ST_MACRO_8,     LGUI(LSFT(KC_V)),                                KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [12] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_20,    ST_MACRO_21,    KC_TRANSPARENT, ST_MACRO_22,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [13] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [14] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [15] = LAYOUT_voyager(
    HSV_43_255_100, KC_NO,          HSV_43_255_102, KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    HSV_43_255_106, KC_NO,          HSV_43_255_108, KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(16),         KC_NO
  ),
  [16] = LAYOUT_voyager(
    HSV_0_255_100,  HSV_0_255_101,  HSV_0_255_102,  HSV_0_255_103,  HSV_0_255_104,  HSV_0_255_105,                                  HSV_0_255_126,  HSV_0_255_127,  HSV_0_255_128,  HSV_0_255_129,  HSV_0_255_130,  HSV_0_255_131,  
    HSV_0_255_106,  HSV_0_255_107,  HSV_0_255_108,  HSV_0_255_109,  HSV_0_255_110,  HSV_0_255_111,                                  HSV_0_255_132,  HSV_0_255_133,  HSV_0_255_134,  HSV_0_255_135,  HSV_0_255_136,  HSV_0_255_137,  
    HSV_0_255_112,  HSV_0_255_113,  HSV_0_255_114,  HSV_0_255_115,  HSV_0_255_116,  HSV_0_255_117,                                  HSV_0_255_138,  HSV_0_255_139,  HSV_0_255_140,  HSV_0_255_141,  HSV_0_255_142,  HSV_0_255_143,  
    HSV_0_255_118,  HSV_0_255_119,  HSV_0_255_120,  HSV_0_255_121,  HSV_0_255_122,  HSV_0_255_123,                                  HSV_0_255_144,  HSV_0_255_145,  HSV_0_255_146,  HSV_0_255_147,  HSV_0_255_148,  HSV_0_255_149,  
                                                    MO(17),         MO(18),                                         KC_TRANSPARENT, HSV_0_255_151
  ),
  [17] = LAYOUT_voyager(
    HSV_86_255_100, HSV_86_255_101, HSV_86_255_102, HSV_86_255_103, HSV_86_255_104, HSV_86_255_105,                                 HSV_86_255_126, HSV_86_255_127, HSV_86_255_128, HSV_86_255_129, HSV_86_255_130, HSV_86_255_131, 
    HSV_86_255_106, HSV_86_255_107, HSV_86_255_108, HSV_86_255_109, HSV_86_255_110, HSV_86_255_111,                                 HSV_86_255_132, HSV_86_255_133, HSV_86_255_134, HSV_86_255_135, HSV_86_255_136, HSV_86_255_137, 
    HSV_86_255_112, HSV_86_255_113, HSV_86_255_114, HSV_86_255_115, HSV_86_255_116, HSV_86_255_117,                                 HSV_86_255_138, HSV_86_255_139, HSV_86_255_140, HSV_86_255_141, HSV_86_255_142, HSV_86_255_143, 
    HSV_86_255_118, HSV_86_255_119, HSV_86_255_120, HSV_86_255_121, HSV_86_255_122, HSV_86_255_123,                                 HSV_86_255_144, HSV_86_255_145, HSV_86_255_146, HSV_86_255_147, HSV_86_255_148, HSV_86_255_149, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_86_255_151
  ),
  [18] = LAYOUT_voyager(
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

// enum for layer define sync oryx side
enum layer_num {
  L_Base = 0,
  L_Base_JIS,
  L_Function,
  L_Number,
  L_Number_JIS,
  L_Cursor,
  L_Cursor_JIS,
  L_LeftPinky,
  L_RightPinky,
  L_LeftPinkyThumb,
  L_RightPinkyThumb,
  L_BothThumb,
  L_BothThumb_JIS,
  L_BothPinky,
  L_BothPinkyThumb,
  L_Firmware,
  L_Set_Hue,
  L_Set_Sat,
  L_Set_Val,
  C_LAYER_COUNT 
};

#define ORYX_LAYER_COUNT (sizeof(keymaps) / sizeof(keymaps[0]))
_Static_assert(C_LAYER_COUNT == ORYX_LAYER_COUNT, "C and ORYX layer count missmatch!!");

// keymap ovverride (process Engram symbol and ANSI/JIS)
// base (x and xs pair is shifted symbol, xs only overwrite shift)
const key_override_t ko_ansi_base_1 = ko_make_with_layers_and_negmods(0, KC_1, KC_AT,   (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_2 = ko_make_with_layers_and_negmods(0, KC_2, KC_HASH, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_3 = ko_make_with_layers_and_negmods(0, KC_3, KC_DQUO, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_ansi_base_4 = ko_make_with_layers_and_negmods(0, KC_4, KC_QUES, (layer_state_t)1 << L_Base, (uint8_t) MOD_MASK_SHIFT);

const key_override_t ko_ansi_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_GRV,  (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, KC_DLR,  (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_3s = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, KC_RPRN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_4s = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, KC_EXLM, (layer_state_t)1 << L_Base);

const key_override_t ko_ansi_base_QUOTs = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_LPRN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_COMMs = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_MINSs = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_UNDS, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_SLSHs = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, (layer_state_t)1 << L_Base);
const key_override_t ko_ansi_base_DOTs  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_COLN, (layer_state_t)1 << L_Base);

// not work, disable, guess with mod-tap race condition
//const key_override_t ko_ansi_num_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_PIPE,  1 << 2);
//...
//const key_override_t ko_ansi_num_0s = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_ASTR,  1 << 2);

// base (x and xs pair is shifted symbol, xs only overwrite shift)
const key_override_t ko_jis_base_1 = ko_make_with_layers_and_negmods(0, JP_1, JP_QUOT, (layer_state_t)1 << L_Base_JIS, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ko_jis_base_2 = ko_make_with_layers_and_negmods(0, JP_2, JP_DQUO, (layer_state_t)1 << L_Base_JIS, (uint8_t) MOD_MASK_SHIFT);

const key_override_t ko_jis_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, JP_1, JP_LPRN, (layer_state_t)1 << L_Base_JIS);
const key_override_t ko_jis_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, JP_2, JP_RPRN, (layer_state_t)1 << L_Base_JIS);

const key_override_t ko_jis_base_ATs   = ko_make_with_layers(MOD_MASK_SHIFT, JP_AT,   JP_GRV,  (layer_state_t)1 << L_Base_JIS);
const key_override_t ko_jis_base_MINSs = ko_make_with_layers(MOD_MASK_SHIFT, JP_MINS, JP_UNDS, (layer_state_t)1 << L_Base_JIS);
const key_override_t ko_jis_base_SLSHs = ko_make_with_layers(MOD_MASK_SHIFT, JP_SLSH, JP_BSLS, (layer_state_t)1 << L_Base_JIS);
const key_override_t ko_jis_base_DOTs  = ko_make_with_layers(MOD_MASK_SHIFT, JP_DOT,  JP_COLN, (layer_state_t)1 << L_Base_JIS);

const key_override_t *key_overrides[] = {
  &ko_ansi_base_1,  &ko_ansi_base_2,  &ko_ansi_base_3,  &ko_ansi_base_4,
  &ko_ansi_base_1s, &ko_ansi_base_2s, &ko_ansi_base_3s, &ko_ansi_base_4s,
  &ko_ansi_base_QUOTs, &ko_ansi_base_COMMs, &ko_ansi_base_MINSs, &ko_ansi_base_SLSHs, &ko_ansi_base_DOTs,
  &ko_jis_base_1,  &ko_jis_base_2,
  &ko_jis_base_1s, &ko_jis_base_2s,
  &ko_jis_base_ATs, &ko_jis_base_MINSs, &ko_jis_base_SLSHs, &ko_jis_base_DOTs
};

static void rgb_matrix_set_hue(const uint8_t hue);
static void rgb_matrix_set_sat(const uint8_t sat);
static void rgb_matrix_set_val(const uint8_t val);
static void rgb_matrix_load_preset(void);

static void set_layer_color_overlay(void);
static void set_layer_color_firmware_map(void);
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
   49, 43, 37, 31,
   48, 42, 36, 30,
   47, 41, 35, 29,
   46, 40, 34, 28,
   45, 39, 33, 27,
   44, 38, 32, 26,
   
   23, 17, 11,  5,
   22, 16, 10,  4,
   21, 15,  9,  3,
   20, 14,  8,  2,
   19, 13,  7,  1,
   18, 12,  6,  0
};
static const uint8_t pos2idx_tbl[52] = {
   47, 43, 39, 35, 31, 27,
   46, 42, 38, 34, 30, 26,
   45, 41, 37, 33, 29, 25,
   44, 40, 36, 32, 28, 24,
    0,  0,
   23, 19, 15, 11,  7,  3,
   22, 18, 14, 10,  6,  2,
   21, 17, 13,  9,  5,  1,
   20, 16, 12,  8,  4,  0,
    0,  0
};

// status LED pattern list, no const limit, terminate symbol
// init value, scale, delay, delay, ...
// delay reduce data with shift by scale value
// 0: terminate, stop exec
// MAX: restart pattern 
static const uint8_t led_pattern_off[] = {0, 0, 0, UINT8_MAX, UINT8_MAX};
static const uint8_t led_pattern_on[] = {1, 0, 0, UINT8_MAX, UINT8_MAX};
static const uint8_t led_pattern_blink[] = {1, 2, 125, 62, UINT8_MAX, UINT8_MAX};
static const uint8_t led_pattern_single[] = {1, 2, 125, 0, UINT8_MAX, UINT8_MAX};
static const uint8_t led_pattern_oneshot[] = {1, 1, 160, 40, 160, 40, 160, 40, 160, 40, 160, 40, 160, 40, 160, 40, 160, 0, UINT8_MAX, UINT8_MAX};
//static const uint8_t * const led_pattern_heartbeat = (uint8_t[]){250, 125, UINT8_MAX, UINT8_MAX, UINT8_MAX};

static void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern);
static void update_status_led(const fast_timer_t now);

// housekeeping throttle, only exec every unit time
static fast_timer_t hk_fast_trigger = 0;
static const fast_timer_t hk_fast_delay = 33;  // typ 30fps

static fast_timer_t hk_mid_trigger = 0;
static const fast_timer_t hk_mid_delay = 333;

static fast_timer_t hk_slow_trigger = 0;
static const fast_timer_t hk_slow_delay = 3333;

// ime state from LANG1/LANG2 key
static bool ime_on = false;
static bool ime_kk = false;  //KataKana

// Ime State Sync system
static bool iss_enable = true; 
static bool iss_sync = false;

static bool iss_sync_to_run = false;
static fast_timer_t iss_sync_to_trigger = 0;
static const fast_timer_t iss_sync_to_delay = 15000; //ms

static bool iss_idle_to_run = false;
static fast_timer_t iss_idle_to_trigger = 0;
static const fast_timer_t iss_idle_to_delay = 600000; //ms

// Ime State Display system

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();
  rgb_matrix_load_preset();

  keymap_config.nkro = true;

  fast_timer_t now = timer_read_fast();
  hk_fast_trigger = now + hk_fast_delay;
  hk_mid_trigger = now + hk_mid_delay;
  hk_slow_trigger = now + hk_slow_delay;
  
  //ANSI
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
    case L_Set_Hue:
      set_layer_color_hue_map();
      break;
    case L_Set_Sat:
      set_layer_color_sat_map();
      break;
    case L_Set_Val:
      set_layer_color_val_map();
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
      status_led(now, 0b1100, led_pattern_off);
      status_led(now, 0b0001, led_pattern_on);
      status_led(now, 0b0010, led_pattern_blink);
      break;
    case L_Cursor:
    case L_Cursor_JIS:
      status_led(now, 0b1100, led_pattern_off);
      status_led(now, 0b0010, led_pattern_on);
      status_led(now, 0b0001, led_pattern_blink);
      break;
    case L_LeftPinky:
      status_led(now, 0b0110, led_pattern_off);
      status_led(now, 0b0001, led_pattern_on);
      status_led(now, 0b1000, led_pattern_blink);
      break;
    case L_RightPinky:
      status_led(now, 0b1001, led_pattern_off);
      status_led(now, 0b0010, led_pattern_on);
      status_led(now, 0b0100, led_pattern_blink);
      break;
    case L_LeftPinkyThumb:
      status_led(now, 0b0100, led_pattern_off);
      status_led(now, 0b0001, led_pattern_on);
      status_led(now, 0b1010, led_pattern_blink);
      break;
    case L_RightPinkyThumb:
      status_led(now, 0b1000, led_pattern_off);
      status_led(now, 0b0010, led_pattern_on);
      status_led(now, 0b0101, led_pattern_blink);
      break;
    case L_BothThumb:
    case L_BothThumb_JIS:
      status_led(now, 0b1100, led_pattern_off);
      status_led(now, 0b0011, led_pattern_blink);
      break;
    case L_BothPinky:
      status_led(now, 0b0011, led_pattern_on);
      status_led(now, 0b1100, led_pattern_blink);
      break;
    case L_BothPinkyThumb:
      status_led(now, 0b1111, led_pattern_blink);
      break;
    case L_Firmware:
      status_led(now, 0b1111, led_pattern_blink);
      break;
    case L_Set_Hue:
      status_led(now, 0b0011, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      break;
    case L_Set_Sat:
      status_led(now, 0b0001, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0010, led_pattern_blink);
      break;
    case L_Set_Val:
      status_led(now, 0b0010, led_pattern_off);
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0001, led_pattern_blink);
      break;

    default :
      status_led(now, 0b1111, led_pattern_off);
      break;
  }  
  return state;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
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
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (iss_enable) {
    if (record->event.pressed) {
      fast_timer_t now = timer_read_fast();
      
      iss_sync_to_run = true;
      iss_sync_to_trigger = now + iss_sync_to_delay;
      
      iss_idle_to_run = true;
      iss_idle_to_trigger = now + iss_idle_to_delay;
    }
  }
  return;
}

void housekeeping_task_user(void) {
  fast_timer_t now = timer_read_fast();
  
  // early return to throttle
  if (!(timer_expired_fast(now, hk_fast_trigger))) return;
  hk_fast_trigger += hk_fast_delay;

  update_status_led(now);

  if (!(timer_expired_fast(now, hk_mid_trigger))) return;
  hk_mid_trigger += hk_mid_delay;

  if (iss_sync_to_run) {
    if (timer_expired_fast(now, iss_sync_to_trigger)) {
      iss_sync_to_run = false;
      iss_sync = true;   
    }
  }

  if (!(timer_expired_fast(now, hk_slow_trigger))) return;
  hk_slow_trigger += hk_slow_delay;
  
  if (iss_idle_to_run) {
    if (timer_expired_fast(now, iss_idle_to_trigger)) {
      iss_idle_to_run = false;
      iss_sync = false;
      ime_on = false;
    }
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
        rgb_matrix_mode_noeeprom(1);
      }
      return false;
    
    case HSV_43_255_100:
      if (record->event.pressed) {
        //ANSI
        layer_off(L_Base_JIS);
      }
      return false;
    case HSV_43_255_102:
      if (record->event.pressed) {
        iss_enable = true;
      }
      return false;
    case HSV_43_255_106:
      if (record->event.pressed) {
        //JIS
        layer_on(L_Base_JIS);
      }
      return false;
    case HSV_43_255_108:
      if (record->event.pressed) {
        iss_enable = false;
        iss_sync = false;
        iss_sync_to_run = false;
        iss_idle_to_run = false;
      }
      return false;
    
    case HSV_0_255_100:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_0_255_101:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_0_255_102:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_0_255_103:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_0_255_104:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_0_255_105:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_0_255_106:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_0_255_107:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_0_255_108:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_0_255_109:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_0_255_110:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_0_255_111:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_0_255_112:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_0_255_113:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_0_255_114:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_0_255_115:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_0_255_116:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_0_255_117:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_0_255_118:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_0_255_119:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_0_255_120:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_0_255_121:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_0_255_122:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_0_255_123:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_0_255_126:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_0_255_127:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_0_255_128:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_0_255_129:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_0_255_130:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_0_255_131:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_0_255_132:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_0_255_133:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_0_255_134:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_0_255_135:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_0_255_136:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_0_255_137:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_0_255_138:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_0_255_139:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_0_255_140:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_0_255_141:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_0_255_142:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_0_255_143:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_0_255_144:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_0_255_145:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_0_255_146:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_0_255_147:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_0_255_148:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_0_255_149:
      if (record->event.pressed) {
        rgb_matrix_set_hue(hue_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_0_255_151:
      if (record->event.pressed) {
        rgb_matrix_load_preset();
      }
      return false;
    
    case HSV_86_255_100:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_86_255_101:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_86_255_102:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_86_255_103:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_86_255_104:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_86_255_105:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_86_255_106:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_86_255_107:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_86_255_108:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_86_255_109:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_86_255_110:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_86_255_111:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_86_255_112:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_86_255_113:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_86_255_114:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_86_255_115:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_86_255_116:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_86_255_117:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_86_255_118:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_86_255_119:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_86_255_120:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_86_255_121:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_86_255_122:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_86_255_123:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_86_255_126:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_86_255_127:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_86_255_129:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_86_255_130:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_86_255_131:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_86_255_132:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_86_255_133:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_86_255_134:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_86_255_135:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_86_255_136:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_86_255_137:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_86_255_138:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_86_255_139:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_86_255_140:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_86_255_141:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_86_255_142:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_86_255_143:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_86_255_144:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_86_255_145:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_86_255_146:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_86_255_147:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_86_255_148:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_86_255_149:
      if (record->event.pressed) {
        rgb_matrix_set_sat(sat_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_86_255_151:
      if (record->event.pressed) {
        
      }
      return false;
    
    case HSV_172_255_100:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[0]]);
      }
      return false;
    case HSV_172_255_101:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[1]]);
      }
      return false;
    case HSV_172_255_102:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[2]]);
      }
      return false;
    case HSV_172_255_103:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[3]]);
      }
      return false;
    case HSV_172_255_104:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[4]]);
      }
      return false;
    case HSV_172_255_105:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[5]]);
      }
      return false;
    case HSV_172_255_106:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[6]]);
      }
      return false;
    case HSV_172_255_107:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[7]]);
      }
      return false;
    case HSV_172_255_108:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[8]]);
      }
      return false;
    case HSV_172_255_109:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[9]]);
      }
      return false;
    case HSV_172_255_110:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[10]]);
      }
      return false;
    case HSV_172_255_111:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[11]]);
      }
      return false;
    case HSV_172_255_112:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[12]]);
      }
      return false;
    case HSV_172_255_113:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[13]]);
      }
      return false;
    case HSV_172_255_114:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[14]]);
      }
      return false;
    case HSV_172_255_115:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[15]]);
      }
      return false;
    case HSV_172_255_116:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[16]]);
      }
      return false;
    case HSV_172_255_117:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[17]]);
      }
      return false;
    case HSV_172_255_118:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[18]]);
      }
      return false;
    case HSV_172_255_119:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[19]]);
      }
      return false;
    case HSV_172_255_120:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[20]]);
      }
      return false;
    case HSV_172_255_121:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[21]]);
      }
      return false;
    case HSV_172_255_122:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[22]]);
      }
      return false;
    case HSV_172_255_123:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[23]]);
      }
      return false;
    case HSV_172_255_126:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[26]]);
      }
      return false;
    case HSV_172_255_127:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[27]]);
      }
      return false;
    case HSV_172_255_128:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[28]]);
      }
      return false;
    case HSV_172_255_129:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[29]]);
      }
      return false;
    case HSV_172_255_130:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[30]]);
      }
      return false;
    case HSV_172_255_131:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[31]]);
      }
      return false;
    case HSV_172_255_132:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[32]]);
      }
      return false;
    case HSV_172_255_133:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[33]]);
      }
      return false;
    case HSV_172_255_134:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[34]]);
      }
      return false;
    case HSV_172_255_135:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[35]]);
      }
      return false;
    case HSV_172_255_136:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[36]]);
      }
      return false;
    case HSV_172_255_137:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[37]]);
      }
      return false;
    case HSV_172_255_138:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[38]]);
      }
      return false;
    case HSV_172_255_139:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[39]]);
      }
      return false;
    case HSV_172_255_140:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[40]]);
      }
      return false;
    case HSV_172_255_141:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[41]]);
      }
      return false;
    case HSV_172_255_142:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[42]]);
      }
      return false;
    case HSV_172_255_143:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[43]]);
      }
      return false;
    case HSV_172_255_144:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[44]]);
      }
      return false;
    case HSV_172_255_145:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[45]]);
      }
      return false;
    case HSV_172_255_146:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[46]]);
      }
      return false;
    case HSV_172_255_147:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[47]]);
      }
      return false;
    case HSV_172_255_148:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[48]]);
      }
      return false;
    case HSV_172_255_149:
      if (record->event.pressed) {
        rgb_matrix_set_val(val_tbl[pos2idx_tbl[49]]);
      }
      return false;
    case HSV_172_255_151:
      if (record->event.pressed) {
        
      }
      return false;
    
    //RGB inc/dec no eeprom over write
    // always return false (sometime use upedge)
    case RGB_HUI:
      if (record->event.pressed) rgb_matrix_increase_hue_noeeprom();
      return false;
    case RGB_HUD:
      if (record->event.pressed) rgb_matrix_decrease_hue_noeeprom();
      return false;
    case RGB_SAI:
      if (record->event.pressed) rgb_matrix_increase_sat_noeeprom();
      return false;
    case RGB_SAD:
      if (record->event.pressed) rgb_matrix_decrease_sat_noeeprom();
      return false;
    case RGB_VAI:
      if (record->event.pressed) rgb_matrix_increase_val_noeeprom();
      return false;
    case RGB_VAD:
      if (record->event.pressed) rgb_matrix_decrease_val_noeeprom();
      return false;
    case RGB_SPI:
      if (record->event.pressed) rgb_matrix_increase_speed_noeeprom();
      return false;
    case RGB_SPD:
      if (record->event.pressed) rgb_matrix_decrease_speed_noeeprom();
      return false;
    case RGB_TOG:
      if (record->event.pressed) rgb_matrix_toggle_noeeprom();
      return false;
    case RGB_MODE_FORWARD:
      if (record->event.pressed) rgb_matrix_step_noeeprom();
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

static void status_led_task_1(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t delay = 0;
  static fast_timer_t trigger = 0;
  static const uint8_t * ptr_ori = NULL;
  static const uint8_t * ptr = NULL;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (delay == 0) return;
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_ori = pattern;
    
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_1(out_val);
  out_val = !out_val;
  
  delay = ((fast_timer_t)(*(ptr++))) << scale;
  trigger += delay;
  
  return;
}

static void status_led_task_2(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t delay = 0;
  static fast_timer_t trigger = 0;
  static const uint8_t * ptr_ori = NULL;
  static const uint8_t * ptr = NULL;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (delay == 0) return;
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_ori = pattern;
    
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_2(out_val);
  out_val = !out_val;
  
  delay = ((fast_timer_t)(*(ptr++))) << scale;
  trigger += delay;
  
  return;
}

static void status_led_task_3(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t delay = 0;
  static fast_timer_t trigger = 0;
  static const uint8_t * ptr_ori = NULL;
  static const uint8_t * ptr = NULL;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (delay == 0) return;
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_ori = pattern;
    
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_3(out_val);
  out_val = !out_val;
  
  delay = ((fast_timer_t)(*(ptr++))) << scale;
  trigger += delay;
  
  return;
}

static void status_led_task_4(const fast_timer_t now, const uint8_t * const pattern) {
  static fast_timer_t delay = 0;
  static fast_timer_t trigger = 0;
  static const uint8_t * ptr_ori = NULL;
  static const uint8_t * ptr = NULL;
  static bool out_val = false;
  static uint8_t scale = 0;

  if (pattern == NULL) {
    // normal operation
    if (delay == 0) return;
    if (!(timer_expired_fast(now, trigger))) return;
  } else {
    // update operation
    trigger = now;
    ptr_ori = pattern;
    
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  if (*ptr == UINT8_MAX) {
    ptr = ptr_ori;
    out_val = *(ptr++);
    scale = *(ptr++);
  }
  
  STATUS_LED_4(out_val);
  out_val = !out_val;
  
  delay = ((fast_timer_t)(*(ptr++))) << scale;
  trigger += delay;
  
  return;
}

// 1 -> Red Left
// 3 -> Red Right
// 2 -> Green Left
// 4 -> Green Right
// re-order bit position
static void status_led(const fast_timer_t now, const uint8_t mask, const uint8_t * const pattern) {  
  if (mask & 0b1000) {
    status_led_task_1(now, pattern);
  }
  if (mask & 0b0100) {
    status_led_task_3(now, pattern);
  }
  if (mask & 0b0010) {
    status_led_task_2(now, pattern);
  }
  if (mask & 0b0001) {
    status_led_task_4(now, pattern);
  }
  return;
}

static void update_status_led(const fast_timer_t now) {
  status_led_task_1(now, NULL);
  status_led_task_3(now, NULL);
  status_led_task_2(now, NULL);
  status_led_task_4(now, NULL);
  return;
}

// HSV independent update code
static void rgb_matrix_set_hue(const uint8_t hue) {
  HSV hsv = rgb_matrix_get_hsv();
  rgb_matrix_sethsv_noeeprom(hue, hsv.s, hsv.v);
}

static void rgb_matrix_set_sat(const uint8_t sat) {
  HSV hsv = rgb_matrix_get_hsv();
  rgb_matrix_sethsv_noeeprom(hsv.h, sat, hsv.v);
}

static void rgb_matrix_set_val(const uint8_t val) {
  HSV hsv = rgb_matrix_get_hsv();
  rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, val);
}

static void rgb_matrix_load_preset(void) {
  rgb_matrix_sethsv_noeeprom(250, 255, 109);
  rgb_matrix_set_speed_noeeprom(128);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
}

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

static void set_layer_color_overlay(void) {
  HSV hsv = rgb_matrix_get_hsv();
  
  // copy logic from breathing_anim.h 
  // use different speed divide
  uint8_t speed = rgb_matrix_get_speed(); 
  uint16_t time = scale16by8(g_rgb_timer, speed / 3);
  hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

  // CAPS WORD inidication
  hsv.h = 43;
  if (is_caps_word_on()) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
  }

  // mods display
  hsv.h = 0;
  if (get_mods() & MOD_BIT_LCTRL) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RCTRL) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(27, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(42, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(43, rgb.r, rgb.g, rgb.b);
  }
  
  hsv.h = 172;
  if (get_mods() & MOD_BIT_LSHIFT) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RSHIFT) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(28, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(41, rgb.r, rgb.g, rgb.b);
  }
  
  hsv.h = 46;
  if (get_mods() & MOD_BIT_LALT) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RALT) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(29, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(35, rgb.r, rgb.g, rgb.b);
  }
  
  hsv.h = 86;
  if (get_mods() & MOD_BIT_LGUI) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(7, rgb.r, rgb.g, rgb.b);
  }
  if (get_mods() & MOD_BIT_RGUI) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(36, rgb.r, rgb.g, rgb.b);
  }
  
  // layer display
  hsv.h = 0;
  if (layer_state_is(L_LeftPinky)) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b);
  }
  hsv.h  = 172;
  if (layer_state_is(L_Number)) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);
  }

  hsv.h = 43;
  if (layer_state_is(L_RightPinky)) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(26, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(37, rgb.r, rgb.g, rgb.b);
  }
  hsv.h = 86;
  if (layer_state_is(L_Cursor)) {
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(25, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);
  }
  
  // IME state sync syntem state
  if (ime_on) {
    if (ime_kk) {
      hsv.h = 172;
    } else {
      hsv.h = 86;
    }
    if (iss_sync == false) {
      hsv.v = rgb_matrix_get_val();
    }
    
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(23, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(44, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(17, 0, 0, 0);
    rgb_matrix_set_color(38, 0, 0, 0);
  }
}

static void set_layer_color_firmware_map(void) {
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
}

static void set_layer_color_hue_map(void) {
  HSV hsv = rgb_matrix_get_hsv();
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
  HSV hsv = rgb_matrix_get_hsv();
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
  HSV hsv = rgb_matrix_get_hsv();
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



