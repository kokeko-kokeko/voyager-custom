#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_200,
  HSV_86_255_200,
  HSV_86_255_201,
  HSV_0_255_210,
  HSV_86_255_202,
  HSV_86_255_203,
  HSV_86_255_255,
  HSV_172_255_200,
  HSV_0_255_211,
  HSV_86_255_204,
  HSV_0_255_212,
  HSV_86_255_205,
  HSV_0_255_213,
  HSV_172_255_201,
  HSV_0_255_255,
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
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};



#define DUAL_FUNC_0 LT(15, KC_L)
#define DUAL_FUNC_1 LT(13, KC_F8)
#define DUAL_FUNC_2 LT(11, KC_K)
#define DUAL_FUNC_3 LT(6, KC_F24)
#define DUAL_FUNC_4 LT(7, KC_F9)
#define DUAL_FUNC_5 LT(13, KC_F7)
#define DUAL_FUNC_6 LT(11, KC_M)
#define DUAL_FUNC_7 LT(10, KC_L)
#define DUAL_FUNC_8 LT(4, KC_E)
#define DUAL_FUNC_9 LT(13, KC_M)
#define DUAL_FUNC_10 LT(7, KC_W)
#define DUAL_FUNC_11 LT(5, KC_0)
#define DUAL_FUNC_12 LT(2, KC_B)
#define DUAL_FUNC_13 LT(6, KC_F23)
#define DUAL_FUNC_14 LT(3, KC_4)
#define DUAL_FUNC_15 LT(7, KC_F8)
#define DUAL_FUNC_16 LT(6, KC_F22)
#define DUAL_FUNC_17 LT(5, KC_J)
#define DUAL_FUNC_18 LT(7, KC_F14)
#define DUAL_FUNC_19 LT(2, KC_F8)
#define DUAL_FUNC_20 LT(7, KC_T)
#define DUAL_FUNC_21 LT(13, KC_8)
#define DUAL_FUNC_22 LT(13, KC_U)
#define DUAL_FUNC_23 LT(7, KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    JP_AT,          KC_1,           KC_Y,           KC_O,           KC_U,           KC_2,                                           KC_3,           KC_D,           KC_N,           KC_G,           KC_SLASH,       CW_TOGG,        
    LT(8, KC_B),    MT(MOD_LGUI, KC_H),MT(MOD_LALT, KC_I),MT(MOD_LSFT, KC_A),MT(MOD_LCTL, KC_E),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_T),MT(MOD_RSFT, KC_R),MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_C),LT(9, KC_V),    
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_K),MT(MOD_LSFT, KC_J),KC_X,           KC_W,           KC_MINUS,                                       KC_4,           KC_M,           KC_L,           MT(MOD_RSFT, KC_F),MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(3, KC_LANGUAGE_1),LT(6, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(3, KC_TAB),  LT(6, KC_ESCAPE),                                LT(4, KC_BSPC), KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_L,           KC_D,           KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_C),KC_TRANSPARENT, MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),KC_TRANSPARENT, MT(MOD_RGUI, KC_N),KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_G),MT(MOD_LSFT, KC_X),KC_J,           KC_K,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_R,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_1,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,                                       KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
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
    DUAL_FUNC_0,    MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),DUAL_FUNC_4,    
    DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    JP_TILD,        JP_PLUS,        KC_LABK,                                        KC_RABK,        JP_CIRC,        JP_AMPR,        DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,    
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(8, KC_LBRC), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(9, KC_RBRC), 
    DUAL_FUNC_8,    DUAL_FUNC_9,    MT(MOD_LSFT, KC_EQUAL),KC_TILD,        KC_PLUS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_TRANSPARENT, DUAL_FUNC_10,   DUAL_FUNC_11,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    CW_TOGG,        KC_HOME,        KC_END,         KC_PAGE_UP,     KC_PGDN,        JP_LPRN,                                        JP_RPRN,        LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_APPLICATION, KC_BSPC,        
    MO(8),          DUAL_FUNC_12,   DUAL_FUNC_13,   DUAL_FUNC_14,   DUAL_FUNC_15,   KC_SCLN,                                        JP_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      MO(9),          
    KC_LEFT_CTRL,   DUAL_FUNC_16,   DUAL_FUNC_17,   JP_LCBR,        JP_LBRC,        JP_UNDS,                                        KC_EXLM,        JP_RBRC,        JP_RCBR,        DUAL_FUNC_18,   DUAL_FUNC_19,   KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,                                        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DUAL_FUNC_20,   KC_TRANSPARENT, KC_LCBR,        KC_LBRC,        KC_UNDS,                                        KC_TRANSPARENT, KC_RBRC,        KC_RCBR,        KC_TRANSPARENT, DUAL_FUNC_21,   KC_TRANSPARENT, 
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
    KC_LEFT_CTRL,   DUAL_FUNC_22,   DUAL_FUNC_23,   ST_MACRO_7,     ST_MACRO_8,     LGUI(LSFT(KC_V)),                                KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  KC_RIGHT_CTRL,  
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN8,     KC_MS_BTN7,     KC_MS_BTN6,     KC_MS_BTN5,                                     KC_MS_BTN4,     KC_MS_BTN5,     KC_MS_BTN6,     KC_MS_BTN7,     KC_MS_BTN8,     LGUI(KC_TAB),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN4,                                     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                     KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(17),         KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(18),         KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_RIGHT_SHIFT, 
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     MO(17),         KC_TRANSPARENT
  ),
  [17] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_6,           KC_TRANSPARENT,                                 KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [18] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_14,   DUAL_FUNC_15,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [19] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [20] = LAYOUT_voyager(
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    KC_LEFT_SHIFT,  KC_CAPS,        HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  KC_NUM,         KC_SCRL,        HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 HSV_86_255_200, HSV_86_255_201
  ),
  [21] = LAYOUT_voyager(
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
                                                    HSV_86_255_202, HSV_86_255_203,                                 HSV_86_255_255, HSV_172_255_200
  ),
  [22] = LAYOUT_voyager(
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
                                                    HSV_86_255_204, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
  ),
  [23] = LAYOUT_voyager(
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
                                                    KC_TRANSPARENT, HSV_86_255_205,                                 KC_TRANSPARENT, KC_NO
  ),
  [24] = LAYOUT_voyager(
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_172_255_201
  ),
  [25] = LAYOUT_voyager(
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
                                                    KC_NO,          KC_NO,                                          HSV_86_255_255, KC_NO
  ),
};

// -----------------------------------------------------------------------------
//
//
// GitHub C additional declaration
//
//
// -----------------------------------------------------------------------------

#define ORYX_LAYER_COUNT (sizeof(keymaps) / sizeof(keymaps[0]))
#include "layer_num.h"
// enum for layer define sync oryx side
_Static_assert(C_LAYER_COUNT == ORYX_LAYER_COUNT, "C and ORYX layer count missmatch!!");
#undef ORYX_LAYER_COUNT

// access to voyager system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;

// split impl header
#include "fade_matrix.h"
#include "ime_state_sync.h"
#include "overlay_layer_mod.h"
#include "status_led.h"

// split process_record, return false, break
// declaration berofe process_record
static bool process_record_rgb_inc_dec(uint16_t keycode, keyrecord_t *record);
static bool process_record_hsv_0_255_n_setting_map(uint16_t keycode, keyrecord_t *record);
static bool process_record_hsv_86_255_n_layer_to(uint16_t keycode, keyrecord_t *record);
static bool process_record_hsv_172_255_n_function(uint16_t keycode, keyrecord_t *record);
static bool process_record_mouse(uint16_t keycode, keyrecord_t *record);

// -----------------------------------------------------------------------------
//
//
// End of GitHub C additional declaration
//
//
// -----------------------------------------------------------------------------

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;
void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
  // Treat all keys as mouse keys when in the automouse layer so that any key set resets the timeout without leaving the layer.
  if (!layer_state_is(AUTO_MOUSE_TARGET_LAYER)){
    // When depressing a mouse key with a LT key at the same time, the mouse key tracker is not decremented.
    // This is a workaround to fix that
    if (IS_MOUSE_KEYCODE(keycode) && !record->event.pressed) {
      return true;
    }
    return false;
  }
  else {
    return false;
  }
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
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_LSFT(SS_TAP(X_7))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_TAP(X_LEFT));
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
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(100)  SS_TAP(X_INTERNATIONAL_1));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_8)));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_BSLS));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_LSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    
    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_LBRC);
        } else {
          unregister_code16(JP_LBRC);
        }
      } else {
        if (record->event.pressed) {
          layer_on(8);
        } else {
          layer_off(8);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_LCBR);
        } else {
          unregister_code16(JP_LCBR);
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
          register_code16(JP_PIPE);
        } else {
          unregister_code16(JP_PIPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_EQL);
        } else {
          unregister_code16(JP_EQL);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_RBRC);
        } else {
          unregister_code16(JP_RBRC);
        }
      } else {
        if (record->event.pressed) {
          layer_on(9);
        } else {
          layer_off(9);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
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
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_ASTR);
        } else {
          unregister_code16(JP_ASTR);
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
          register_code16(JP_RCBR);
        } else {
          unregister_code16(JP_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
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
    case DUAL_FUNC_9:
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
    case DUAL_FUNC_10:
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
    case DUAL_FUNC_11:
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
    case DUAL_FUNC_12:
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
    case DUAL_FUNC_13:
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
    case DUAL_FUNC_14:
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
    case DUAL_FUNC_15:
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
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_LPRN);
        } else {
          unregister_code16(JP_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_17:
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
    case DUAL_FUNC_18:
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
    case DUAL_FUNC_19:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(JP_RPRN);
        } else {
          unregister_code16(JP_RPRN);
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
    case DUAL_FUNC_21:
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
    case DUAL_FUNC_22:
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
    case DUAL_FUNC_23:
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
  }

  // split process_record, return false, break
  if (process_record_rgb_inc_dec(keycode, record) == false) return false;
  if (process_record_hsv_0_255_n_setting_map(keycode, record) == false) return false;
  if (process_record_hsv_86_255_n_layer_to(keycode, record) == false) return false;
  if (process_record_hsv_172_255_n_function(keycode, record) == false) return false;
  if (process_record_mouse(keycode, record) == false) return false;
  if (process_record_ime_state_sync(keycode, record) == false) return false;
  
  return true;
}

// -----------------------------------------------------------------------------
//
//
// GitHub C additional definition
//
//
// -----------------------------------------------------------------------------

#include "i18n_undef.inc"

#include "engram_key_overrides.inc"

// cached now value, update on housekeeping
static fast_timer_t now_buffer = 0;

static bool lock_scrolling = false;

// auto_mouse_layer_off() only on housekeeping, other set timer
static fast_timer_t auto_mouse_early_off_trigger = 0;
static fast_timer_t auto_mouse_count_reset_trigger = 0;

// 0 to 7 = left, 8 to 15 = right, button 8 count
static const fast_timer_t btn_early_off_delay[16] = {
  AUTO_MOUSE_TIME_LONG,  AUTO_MOUSE_TIME_LONG,  AUTO_MOUSE_TIME_MID,   AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_MID,   AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT,
  AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT, AUTO_MOUSE_TIME_SHORT
};

// reset from housekeeping
static total_mouse_movement_t auto_mouse_total_move = {
  .x = 0,
  .y = 0,
  .h = 0,
  .v = 0,
};

// mouse status delayed display
static bool set_scrolling_delayed = false;
static bool navigator_turbo_delayed = false;
static bool navigator_aim_delayed = false;

static fast_timer_t mouse_flag_update_trigger = 0;

bool get_mouse_flag_scrolling(void) {
  return set_scrolling_delayed;
}

bool get_mouse_flag_turbo(void) {
  return navigator_turbo_delayed;
}

bool get_mouse_flag_aim(void) {
  return navigator_aim_delayed;
}

static void activate_mouse_flag(const fast_timer_t now, const bool pressed) {
  if (pressed) {
    mouse_flag_update_trigger = now + TAPPING_TERM;
  } else {
    mouse_flag_update_trigger = now + 1;
  }
  return;
}

static void update_mouse_flag(const fast_timer_t now) {
  if (timer_expired_fast(now, mouse_flag_update_trigger) == false) return;
  mouse_flag_update_trigger = now + (UINT32_MAX / 2) - 1;
  
  // update
  set_scrolling_delayed = set_scrolling;
  navigator_turbo_delayed = navigator_turbo;
  navigator_aim_delayed = navigator_aim;
  
  if (get_mouse_flag_scrolling()) {
    status_led(now, 0b0100, led_pattern_on);
  } else {
    status_led(now, 0b0100, led_pattern_off);
  }
    
  if (get_mouse_flag_turbo()) {
    status_led(now, 0b0001, led_pattern_on);
  } else {
    status_led(now, 0b0001, led_pattern_off);
  }
    
  if (get_mouse_flag_aim()) {
    status_led(now, 0b0010, led_pattern_on);
  } else {
    status_led(now, 0b0010, led_pattern_off);
  }
  return;
}

// -----------------------------------------------------------------------------
//
//
// Split keymap process_record impl
//
//
// -----------------------------------------------------------------------------

static bool process_record_rgb_inc_dec(uint16_t keycode, keyrecord_t *record) {
  //RGB inc/dec no eeprom override
  // always return false (sometime use upedge)
  if (keycode == RGB_SLD) {
    if (record->event.pressed) {
      fade_matrix_set_mode(now_buffer, RGB_MATRIX_SOLID_COLOR);
    }
    return false;
  }
  
  if (keycode == RGB_HUI) {
    if (record->event.pressed) {
      fade_matrix_increase_hue(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_HUD) {
    if (record->event.pressed) {
      fade_matrix_decrease_hue(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_SAI) {
    if (record->event.pressed) {
      fade_matrix_increase_sat(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_SAD) {
    if (record->event.pressed) {
      fade_matrix_decrease_sat(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_VAI) {
    if (record->event.pressed) {
      fade_matrix_increase_val(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_VAD) {
    if (record->event.pressed) {
      fade_matrix_decrease_val(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_SPI) {
    if (record->event.pressed) {
      fade_matrix_increase_speed(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_SPD) {
    if (record->event.pressed) {
      fade_matrix_decrease_speed(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_TOG) {
    if (record->event.pressed) {
      fade_matrix_toggle(now_buffer);
    }
    return false;
  }
  
  if (keycode == RGB_MODE_FORWARD) {
    if (record->event.pressed) {
      fade_matrix_step(now_buffer);
    }
    return false;
  }
  
  return true;
}

static bool process_record_hsv_0_255_n_setting_map(uint16_t keycode, keyrecord_t *record) {
  // Firmware  
  if (keycode == HSV_0_255_200) {
    if (record->event.pressed) {
      uint8_t pos = get_pos_from_keyrecord(record);
      if (52 <= pos) return false;
      
      if (pos == 0) {
        layer_off(L_Base_ANSI);
      } else if (pos == 6) {
        layer_on(L_Base_ANSI);
      } else if (pos == 1) {
        layer_on(L_Base_2025);
        layer_off(L_Base_2021);
      } else if (pos == 7) {
        layer_on(L_Base_2025);
        layer_on(L_Base_2021);
      } else if (pos == 3) {
        ime_state_sync_enable();
      } else if (pos == 9) {
        ime_state_sync_disable();
      } else if (pos == 29) {
        soft_reset_keyboard();
      } else if (pos == 31) {
        reset_keyboard();
      } else if (pos == 49) {
        clear_keyboard();
      }
    }
    return false;
  }

  if (keycode == HSV_0_255_210) {
    if (record->event.pressed) {
      fade_matrix_set_hue_keyrecord(now_buffer, record);
    }
    return false;
  }

  if (keycode == HSV_0_255_211) {
    if (record->event.pressed) {
      fade_matrix_set_sat_keyrecord(now_buffer, record);
    }
    return false;
  }

  if (keycode == HSV_0_255_212) {
    if (record->event.pressed) {
      fade_matrix_set_val_keyrecord(now_buffer, record);
    }
    return false;
  }

  if (keycode == HSV_0_255_213) {
    if (record->event.pressed) {
      fade_matrix_set_speed_keyrecord(now_buffer, record);
    }
    return false;
  }
  
  if (keycode == HSV_0_255_255) {
    if (record->event.pressed) {
      uint8_t pos = get_pos_from_keyrecord(record);
      if (52 <= pos) return false;
      
      if (pos == 31) {
        // hang-up
        while (1);
      } else if (pos == 49) {
        clear_keyboard();
      }
    }
    return false;
  }
  
  return true;
}

static bool process_record_hsv_86_255_n_layer_to(uint16_t keycode, keyrecord_t *record) {  
  if (keycode == HSV_86_255_200) {
    if (record->event.pressed) {
      layer_on(L_Set_Hue);
    }
    return false;
  }
  
  if (keycode == HSV_86_255_201) {
    if (record->event.pressed) {
      clear_keyboard();
      set_auto_mouse_enable(false);
      layer_on(L_Halt_Mask);
    }
    return false;
  }
  
  if (keycode == HSV_86_255_202) {
    if (record->event.pressed) {
      layer_on(L_Set_Sat);
      update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
    }
    return false;
  }
  
  if (keycode == HSV_86_255_203) {
    if (record->event.pressed) {
      layer_on(L_Set_Val);
      update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);

    }
    return false;
  }

  if (keycode == HSV_86_255_204) {
    if (record->event.pressed) {
      layer_off(L_Set_Sat);
      update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
    }
    return false;
  }
  
  if (keycode == HSV_86_255_205) {
    if (record->event.pressed) {
      layer_off(L_Set_Val);
      update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
    }
    return false;
  }
  
  if (keycode == HSV_86_255_255) {
    if (record->event.pressed) {
      // off all setting layers
      layer_off(L_Halt_Mask);
      layer_off(L_Set_Speed);
      layer_off(L_Set_Val);
      layer_off(L_Set_Sat);
      layer_off(L_Set_Hue);
      layer_off(L_Firmware);
      
      set_auto_mouse_enable(true);
      
      status_led(now_buffer, 0b1111, led_pattern_oneshot);
    }
    return false;
  }
  
  return true;
}

static bool process_record_hsv_172_255_n_function(uint16_t keycode, keyrecord_t *record) {    
  if (keycode == HSV_172_255_200) {
    if (record->event.pressed) {
      fade_matrix_load_preset(now_buffer);
      status_led(now_buffer, 0b0101, led_pattern_oneshot);
    }
    return false;  
  }
  
  if (keycode == HSV_172_255_201) {
    if (record->event.pressed) {
      fade_matrix_load_preset_powersave(now_buffer);
      status_led(now_buffer, 0b1010, led_pattern_oneshot);
    }
    return false;
  }
  
  return true;
}

static bool process_record_mouse(uint16_t keycode, keyrecord_t *record) {
  if (keycode == NAVIGATOR_TURBO) {
    // empty
    return false;
  }
  
  if (keycode == NAVIGATOR_AIM) {
    // empty
    return false;
  }
  
  if (keycode == NAVIGATOR_INC_CPI) {  
    if (record->event.pressed) {
      pointing_device_set_cpi(1);
    }
    return false;
  }
  
  if (keycode == NAVIGATOR_DEC_CPI) {
    if (record->event.pressed) {
      pointing_device_set_cpi(0);
    }
    return false;
  }
  
  return true;
}

// -----------------------------------------------------------------------------
//
//
// Split keymap post_process_record impl & declaration, not break, overwrite after function
//
//
// -----------------------------------------------------------------------------

static void post_process_record_non_mouse(uint16_t keycode, keyrecord_t *record) {
  if (IS_MOUSEKEY(keycode) == true) return;
  
  if (record->event.pressed == false) {
    // non-mouse key release, exit 
    auto_mouse_early_off_trigger = now_buffer + 1;
  } 

  return;
}

static void post_process_record_mouse_button(uint16_t keycode, keyrecord_t *record) {
  // 0 to 7 = left, 8 to 15 = right, button 8 count
  static uint16_t btn_press_time[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
  };
  static fast_timer_t btn_last_tap_time[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
  };
    
  // only mouse button
  if (IS_MOUSEKEY_BUTTON(keycode) == false) return;
  
  uint8_t index = keycode - KC_MS_BTN1;
  if (record->event.key.row < MATRIX_ROWS / 2) {
    // left
    index += 0;
  } else {
    // right
    index += 8;
  }
  
  if (record->event.pressed) {
    btn_press_time[index] = record->event.time;
    // early trigger reset on auto_mouse_activation
  } else {
    if (TIMER_DIFF_16(record->event.time, btn_press_time[index]) < AUTO_MOUSE_DRAG_THRESHOLD) {
      //tap
      if (TIMER_DIFF_FAST(now_buffer, btn_last_tap_time[index]) < AUTO_MOUSE_MULTI_TAP_THRESHOLD) {
        //double tap, short time
        auto_mouse_early_off_trigger = now_buffer + AUTO_MOUSE_TIME_SHORT;
      } else {
        //single tap
        btn_last_tap_time[index] = now_buffer;
        
        auto_mouse_early_off_trigger = now_buffer + btn_early_off_delay[index];
      }
    } else {
      // drag, reset
      btn_last_tap_time[index] = now_buffer + (UINT32_MAX / 2) - 1;
      
      auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    }
  }
  
  return;
}

// -----------------------------------------------------------------------------
//
//
// Split set layer impl
//
//
// -----------------------------------------------------------------------------

static layer_state_t layer_state_set_mouse_halt_mask(layer_state_t state) {
  if (layer_state_cmp(state, L_Halt_Mask)) {
    state = remove_auto_mouse_layer(state, true);
    set_auto_mouse_enable(false);
  }
  return state;
}

static layer_state_t layer_state_set_mouse_number(layer_state_t state) {
  return state;
}

static layer_state_t layer_state_set_mouse_cursor(layer_state_t state) {
  return state;
}

static layer_state_t layer_state_set_mouse_scrolling(layer_state_t state) {
  bool scrolling_flag = false;
  scrolling_flag = scrolling_flag || layer_state_cmp(state, L_Function);
  scrolling_flag = scrolling_flag || layer_state_cmp(state, L_Number);
  scrolling_flag = scrolling_flag || layer_state_cmp(state, L_Cursor);
  scrolling_flag = scrolling_flag || layer_state_cmp(state, L_Mouse_Number);
  scrolling_flag = scrolling_flag || layer_state_cmp(state, L_Mouse_Cursor);
  
  if (scrolling_flag) {
    set_scrolling = true;
    if (is_auto_mouse_active() == false) {
      set_auto_mouse_enable(false);
    }
    activate_mouse_flag(now_buffer, true);
  } else {
    set_scrolling = false;
    set_auto_mouse_enable(true);
    activate_mouse_flag(now_buffer, false);
  }
  
  return state;
}

static layer_state_t layer_state_set_mouse_reset(layer_state_t state) {
  return state;
}

// -----------------------------------------------------------------------------
//
//
// GitHub C QMK callback definition
//
//
// -----------------------------------------------------------------------------

void keyboard_post_init_user(void) {
  // config.h
  //keymap_config.nkro = true;

  now_buffer = timer_read_fast();
  init_fade_matrix(now_buffer);
  status_led(now_buffer, 0b1111, led_pattern_off);

  auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
  
  //JIS / 2021
  layer_move(L_Base_2025);
  layer_on(L_Base_2021);
  layer_off(L_Base_ANSI);
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
      fade_matrix_load_preset(now_buffer);
      status_led(now_buffer, 0b1000, led_pattern_oneshot);
      break;
    case OS_IOS:
      fade_matrix_load_preset_powersave(now_buffer);
      status_led(now_buffer, 0b0100, led_pattern_oneshot);
      break;
    case OS_WINDOWS:
      fade_matrix_load_preset(now_buffer);
      status_led(now_buffer, 0b0010, led_pattern_oneshot);
      break;
    case OS_LINUX:
      fade_matrix_load_preset_powersave(now_buffer);
      status_led(now_buffer, 0b0001, led_pattern_oneshot);
      break;
    case OS_UNSURE:
      status_led(now_buffer, 0b1111, led_pattern_oneshot);
      status_led(now_buffer, 0b1111, led_pattern_oneshot);
      status_led(now_buffer, 0b1111, led_pattern_oneshot);
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

  // call FwSys with Fn and Cursor
  state = update_tri_layer_state(state, L_Function, L_Cursor, L_Firmware); 
  
  // on mouse, both thumb
  state = update_tri_layer_state(state, L_Mouse_Number, L_Mouse_Cursor, L_Mouse_BothThumb);
  
  // ANSI/JIS addiional enable
  state = update_tri_layer_state(state, L_Base_ANSI, L_Number, L_Number_ANSI);
  state = update_tri_layer_state(state, L_Base_ANSI, L_Cursor, L_Cursor_ANSI);
  state = update_tri_layer_state(state, L_Base_ANSI, L_BothThumb, L_BothThumb_ANSI);
  
  // mouse layers
  state = layer_state_set_mouse_halt_mask(state);
  state = layer_state_set_mouse_number(state);
  state = layer_state_set_mouse_cursor(state);
  state = layer_state_set_mouse_scrolling(state);
  state = layer_state_set_mouse_reset(state);
  
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  
  switch (layer) {
    case L_Base_2025:
    case L_Base_2021:
    case L_Base_ANSI:
      status_led(now_buffer, 0b1011, led_pattern_off);
      break;
    case L_Function:
      status_led(now_buffer, 0b1100, led_pattern_off);
      status_led(now_buffer, 0b0011, led_pattern_on);
      break; 
    case L_Number:
    case L_Number_ANSI:
    case L_Cursor:
    case L_Cursor_ANSI:
    case L_LeftPinky:
    case L_RightPinky:
    case L_LeftPinkyThumb:
    case L_RightPinkyThumb:
    case L_BothThumb:
    case L_BothThumb_ANSI:
    case L_BothPinky:
    case L_BothPinkyThumb:
      break;
    case L_Mouse:
    case L_Mouse_Number:
    case L_Mouse_Cursor:
    case L_Mouse_BothThumb:
      // mouse indication
      status_led(now_buffer, 0b0011, led_pattern_off);
      status_led(now_buffer, 0b1000, led_pattern_on);
      // DRAG_SCROLL add on key event
      // aim/turbo change without layer, direct write on process_record
      break;
    case L_Firmware:
      status_led(now_buffer, 0b0011, led_pattern_off);
      status_led(now_buffer, 0b1100, led_pattern_blink);
      break;
    case L_Set_Hue:
      status_led(now_buffer, 0b0011, led_pattern_off);
      status_led(now_buffer, 0b1100, led_pattern_on);
      break;
    case L_Set_Sat:
      status_led(now_buffer, 0b0001, led_pattern_off);
      status_led(now_buffer, 0b1100, led_pattern_on);
      status_led(now_buffer, 0b0010, led_pattern_blink);
      break;
    case L_Set_Val:
      status_led(now_buffer, 0b0010, led_pattern_off);
      status_led(now_buffer, 0b1100, led_pattern_on);
      status_led(now_buffer, 0b0001, led_pattern_blink);
      break;    
    case L_Set_Speed:
      status_led(now_buffer, 0b1100, led_pattern_on);
      status_led(now_buffer, 0b0011, led_pattern_blink);
      break;
    case L_Halt_Mask:
      status_led(now_buffer, 0b1111, led_pattern_off);
      break;

    default:
      status_led(now_buffer, 0b1111, led_pattern_off);
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
    case L_Mouse_Number:
    case L_Mouse_Cursor:
    case L_Mouse_BothThumb:
      set_layer_color_mouse_map();
      break;    
    case L_Firmware:
      set_layer_color_firmware_map();
      set_layer_color_firmware_map_ime_state_sync();
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
    case L_Set_Speed:
      set_layer_color_speed_map();
      break;
    case L_Halt_Mask:
      set_layer_color_halt_map();
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
    activate_fade_matrix(now_buffer);
    activate_ime_state_sync(now_buffer);
  }
  
  // split post_process_record not break, overwrite after function
  post_process_record_non_mouse(keycode, record);
  post_process_record_mouse_button(keycode, record);
  
  return;
}

// copy & custom from pointing_device_auto_mouse.c
bool auto_mouse_activation(report_mouse_t mouse_report) {
  // both state check xy move
  auto_mouse_total_move.x += mouse_report.x;
  auto_mouse_total_move.y += mouse_report.y;
  auto_mouse_total_move.h += mouse_report.h;
  auto_mouse_total_move.v += mouse_report.v;
  
  bool activate = false;

  activate = activate || abs(auto_mouse_total_move.x) > AUTO_MOUSE_THRESHOLD;
  activate = activate || abs(auto_mouse_total_move.y) > AUTO_MOUSE_THRESHOLD;  
  activate = activate || abs(auto_mouse_total_move.h) > AUTO_MOUSE_SCROLL_THRESHOLD;
  activate = activate || abs(auto_mouse_total_move.v) > AUTO_MOUSE_SCROLL_THRESHOLD;
  activate = activate || mouse_report.buttons;
  
  if (activate) {
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    auto_mouse_count_reset_trigger = now_buffer + AUTO_MOUSE_COUNT_RESET_DELAY;

    // wakeup RGB
    activate_fade_matrix(now_buffer);
    
    auto_mouse_total_move.x = 0;
    auto_mouse_total_move.y = 0;
    auto_mouse_total_move.h = 0;
    auto_mouse_total_move.v = 0;
  } else if (timer_expired_fast(now_buffer, auto_mouse_count_reset_trigger)) {
    auto_mouse_count_reset_trigger += AUTO_MOUSE_COUNT_RESET_DELAY;

    auto_mouse_total_move.x = 0;
    auto_mouse_total_move.y = 0;
    auto_mouse_total_move.h = 0;
    auto_mouse_total_move.v = 0;
  }
  
  return activate;    
}

void housekeeping_task_user(void) {
  // update to next now
  now_buffer = timer_read_fast();
  
  update_fade_matrix(now_buffer);
  update_ime_state_sync(now_buffer);
  update_status_led(now_buffer);

  update_mouse_flag(now_buffer); 

  if (timer_expired_fast(now_buffer, auto_mouse_early_off_trigger)) {
    auto_mouse_early_off_trigger = now_buffer + (UINT32_MAX / 2) - 1;
    
    // reset state
    auto_mouse_total_move.x = 0;
    auto_mouse_total_move.y = 0;
    auto_mouse_total_move.h = 0;
    auto_mouse_total_move.v = 0;

    set_scrolling = false;
    lock_scrolling = false;

    navigator_turbo = false;
    navigator_aim = false;

    status_led(now_buffer, 0b0111, led_pattern_off);
    
    auto_mouse_layer_off();

    mouse_flag_update_trigger = now_buffer + 1;
  }
  
  return;
}
