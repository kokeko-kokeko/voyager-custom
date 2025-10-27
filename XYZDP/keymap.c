#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_10,
  HSV_86_255_1,
  HSV_86_255_2,
  HSV_0_255_20,
  HSV_86_255_3,
  HSV_86_255_4,
  HSV_86_255_255,
  HSV_172_255_1,
  HSV_0_255_21,
  HSV_86_255_5,
  HSV_0_255_22,
  HSV_86_255_6,
  HSV_0_255_23,
  HSV_172_255_2,
  HSV_0_0_0,
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



#define DUAL_FUNC_0 LT(11, KC_F8)
#define DUAL_FUNC_1 LT(5, KC_N)
#define DUAL_FUNC_2 LT(3, KC_G)
#define DUAL_FUNC_3 LT(2, KC_C)
#define DUAL_FUNC_4 LT(12, KC_V)
#define DUAL_FUNC_5 LT(6, KC_4)
#define DUAL_FUNC_6 LT(7, KC_T)
#define DUAL_FUNC_7 LT(3, KC_S)
#define DUAL_FUNC_8 LT(11, KC_D)
#define DUAL_FUNC_9 LT(6, KC_7)
#define DUAL_FUNC_10 LT(5, KC_T)
#define DUAL_FUNC_11 LT(13, KC_F20)
#define DUAL_FUNC_12 LT(5, KC_F13)
#define DUAL_FUNC_13 LT(13, KC_F24)
#define DUAL_FUNC_14 LT(1, KC_Q)
#define DUAL_FUNC_15 LT(8, KC_K)
#define DUAL_FUNC_16 LT(3, KC_4)
#define DUAL_FUNC_17 LT(10, KC_U)
#define DUAL_FUNC_18 LT(11, KC_F4)
#define DUAL_FUNC_19 LT(1, KC_H)
#define DUAL_FUNC_20 LT(5, KC_A)
#define DUAL_FUNC_21 LT(3, KC_U)

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
    MO(7),          DUAL_FUNC_10,   DUAL_FUNC_11,   DUAL_FUNC_12,   DUAL_FUNC_13,   KC_SCLN,                                        KC_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      MO(8),          
    KC_LEFT_CTRL,   DUAL_FUNC_14,   DUAL_FUNC_15,   KC_LCBR,        KC_LBRC,        KC_UNDS,                                        KC_EXLM,        KC_RBRC,        KC_RCBR,        DUAL_FUNC_16,   DUAL_FUNC_17,   KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_R)),LGUI(LSFT(KC_S)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN6,     KC_MS_BTN5,                                     KC_MS_BTN4,     KC_MS_BTN5,     KC_MS_BTN6,     KC_MS_BTN7,     KC_MS_BTN8,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LANGUAGE_6,  KC_MS_BTN7,     KC_MS_BTN4,                                     KC_MS_BTN3,     KC_MS_BTN2,     KC_LANGUAGE_7,  NAVIGATOR_AIM,  NAVIGATOR_TURBO,KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN8,     DRAG_SCROLL,                                    LGUI(KC_TAB),   KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_RIGHT_SHIFT, 
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [16] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_6,           KC_TRANSPARENT,                                 KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [17] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_12,   DUAL_FUNC_13,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [18] = LAYOUT_voyager(
    HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,                                   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   
    HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,                                   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   
    HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,                                   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   
    HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,                                   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   HSV_0_255_10,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 HSV_86_255_1,   HSV_86_255_2
  ),
  [19] = LAYOUT_voyager(
    HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,                                   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   
    HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,                                   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   
    HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,                                   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   
    HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,                                   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   HSV_0_255_20,   
                                                    HSV_86_255_3,   HSV_86_255_4,                                   HSV_86_255_255, HSV_172_255_1
  ),
  [20] = LAYOUT_voyager(
    HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,                                   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   
    HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,                                   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   
    HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,                                   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   
    HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,                                   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   HSV_0_255_21,   
                                                    HSV_86_255_5,   HSV_86_255_4,                                   HSV_86_255_255, KC_NO
  ),
  [21] = LAYOUT_voyager(
    HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,                                   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   
    HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,                                   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   
    HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,                                   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   
    HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,                                   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   HSV_0_255_22,   
                                                    HSV_86_255_3,   HSV_86_255_6,                                   HSV_86_255_255, KC_NO
  ),
  [22] = LAYOUT_voyager(
    HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,                                   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   
    HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,                                   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   
    HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,                                   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   
    HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,                                   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   HSV_0_255_23,   
                                                    HSV_86_255_5,   HSV_86_255_6,                                   HSV_86_255_255, HSV_172_255_2
  ),
  [23] = LAYOUT_voyager(
    HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,                                      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      
    HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,                                      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      
    HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,                                      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      
    HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,                                      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      HSV_0_0_0,      
                                                    KC_NO,          KC_NO,                                          HSV_86_255_255, KC_NO
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
static bool lock_turbo = false;
static bool lock_aim = false;

static fast_timer_t auto_mouse_early_trigger = 0;
static fast_timer_t auto_mouse_count_reset_trigger = 0;

static fast_timer_t drag_scroll_trigger = 0;
static fast_timer_t drag_turbo_trigger = 0;
static fast_timer_t drag_aim_trigger = 0;
static fast_timer_t drag_btn_left_trigger[8];
static fast_timer_t drag_btn_right_trigger[8];

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
  // timer read first
  fast_timer_t now = timer_read_fast();
  
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
      if (record->event.pressed) {
        drag_scroll_trigger = now + AUTO_MOUSE_DRAG_THRESHOLD;
        set_scrolling = true;
      } else {
        if (timer_expired_fast(now, drag_scroll_trigger)) {
          // drag, must release lock
          set_scrolling = false;
          lock_scrolling = false;
        } else {
          // tap
          if (lock_scrolling) {
            // if locked release lock
            set_scrolling = false;
            lock_scrolling = false;
          } else {
            // keep scroll, add lock
            lock_scrolling = true;
          }
        }
      }
      if (set_scrolling) {
        status_led(now, 0b0100, led_pattern_on);
      } else {
        status_led(now, 0b0100, led_pattern_off);
      }
      return false;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      drag_turbo_trigger = now + AUTO_MOUSE_DRAG_THRESHOLD;
      navigator_turbo = true;
      
      // release another side
      navigator_aim = false;
      lock_aim = false;
    } else {
      if (timer_expired_fast(now, drag_turbo_trigger)) {
        // drag, must release lock
        navigator_turbo = false;
        lock_turbo = false;
      } else {
        // tap
        if (lock_turbo) {
          // if locked release lock
          navigator_turbo = false;
          lock_turbo = false;
        } else {
          // keep turbo, add lock
          lock_turbo = true;
        }
      } 
    }
    if (navigator_turbo) {
      status_led(now, 0b0001, led_pattern_on);
    } else {
      status_led(now, 0b0001, led_pattern_off);
    }
    if (navigator_aim) {
      status_led(now, 0b0010, led_pattern_on);
    } else {
      status_led(now, 0b0010, led_pattern_off);
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      drag_aim_trigger = now + AUTO_MOUSE_DRAG_THRESHOLD;
      navigator_aim = true;
      
      // release another side
      navigator_turbo = false;
      lock_turbo = false;
    } else {
      if (timer_expired_fast(now, drag_aim_trigger)) {
        // drag, must release lock
        navigator_aim = false;
        lock_aim = false;
      } else {
        // tap
        if (lock_aim) {
          // if locked release lock
          navigator_aim = false;
          lock_aim = false;
        } else {
          // keep aim, add lock
          lock_aim = true;
        }
      }
    }      
    if (navigator_turbo) {
      status_led(now, 0b0001, led_pattern_on);
    } else {
      status_led(now, 0b0001, led_pattern_off);
    }
    if (navigator_aim) {
      status_led(now, 0b0010, led_pattern_on);
    } else {
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

    // Firmware
    case HSV_0_255_10:
      if (record->event.pressed) {
        uint8_t pos = get_pos_from_keyrecord(record);
        if (52 <= pos) return false;
        
        if (pos == 0) {
          layer_off(L_Base_JIS);
        } else if (pos == 6) {
          layer_on(L_Base_JIS);
        } else if (pos == 2) {
          ime_state_sync_enable();
        } else if (pos == 8) {
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
    case HSV_86_255_1:
      if (record->event.pressed) {
        layer_on(L_Set_Hue);
      }
      return false;
    case HSV_86_255_2:
      if (record->event.pressed) {
        set_auto_mouse_enable(false);
        clear_keyboard();
        layer_on(L_Halt_Mask);
      }
      return false;

    // Hue
    case HSV_0_255_20:
      if (record->event.pressed) {
        uint8_t pos = get_pos_from_keyrecord(record);
        if (52 <= pos) return false;
        
        fade_matrix_set_hue_pos(pos);
      }
      return false;
    case HSV_86_255_3:
      if (record->event.pressed) {
        layer_on(L_Set_Sat);
        update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
      }
      return false;
    case HSV_86_255_4:
      if (record->event.pressed) {
        layer_on(L_Set_Val);
        update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
      }
      return false;
    case HSV_86_255_255:
      if (record->event.pressed) {
        // off all setting layers
        layer_off(L_Halt_Mask);
        layer_off(L_Set_Speed);
        layer_off(L_Set_Val);
        layer_off(L_Set_Sat);
        layer_off(L_Set_Hue);
        layer_off(L_Firmware);

        set_auto_mouse_enable(true);
        
        status_led(now, 0b1111, led_pattern_oneshot);
      }
      return false;
    case HSV_172_255_1:
      if (record->event.pressed) {
        fade_matrix_load_preset();
        status_led(now, 0b0101, led_pattern_oneshot);
      }
      return false;
    
    // Sat
    case HSV_0_255_21:
      if (record->event.pressed) {
        uint8_t pos = get_pos_from_keyrecord(record);
        if (52 <= pos) return false;
        
        fade_matrix_set_sat_pos(pos);
      }
      return false;
    case HSV_86_255_5:
      if (record->event.pressed) {
        layer_off(L_Set_Sat);
        update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
      }
      return false;

    // Val
    case HSV_0_255_22:
      if (record->event.pressed) {
        uint8_t pos = get_pos_from_keyrecord(record);
        if (52 <= pos) return false;
        
        fade_matrix_set_val_pos(pos);
      }
      return false;
    case HSV_86_255_6:
      if (record->event.pressed) {
        layer_off(L_Set_Val);
        update_tri_layer(L_Set_Sat, L_Set_Val, L_Set_Speed);
      }
      return false;

    // Speed
    case HSV_0_255_23:
      if (record->event.pressed) {
        uint8_t pos = get_pos_from_keyrecord(record);
        if (52 <= pos) return false;
        
        fade_matrix_set_speed_pos(pos);
      }
      return false;
    case HSV_172_255_2:
      if (record->event.pressed) {
        fade_matrix_load_preset_powersave();
        status_led(now, 0b1010, led_pattern_oneshot);
      }
      return false;

    // Halt
    case HSV_0_0_0:
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
    
    // auto mouse EXIT key left (dummy keycode)
    case KC_LANGUAGE_6:
      if (record->event.pressed) {
        // Immediately
        auto_mouse_layer_off();
      }
      return false;

    // auto mouse EXIT key right (dummy keycode)
    case KC_LANGUAGE_7:
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
      if (record->event.key.row < MATRIX_ROWS / 2) {
        // left side mouse button
        if (record->event.pressed) {
          drag_btn_left_trigger[keycode - KC_MS_BTN1] = now + AUTO_MOUSE_DRAG_THRESHOLD;
          // early trigger reset on auto_mouse_activation
        } else {
          if (timer_expired_fast(now, drag_btn_left_trigger[keycode - KC_MS_BTN1])) {
            // drag, nothing to do
          } else {
            //tap
            auto_mouse_early_trigger = now + AUTO_MOUSE_TIME_LEFT_SIDE;
          }
        }
      } else {
        if (record->event.pressed) {
          drag_btn_right_trigger[keycode - KC_MS_BTN1] = now + AUTO_MOUSE_DRAG_THRESHOLD;
          // early trigger reset on auto_mouse_activation
        } else {
          if (timer_expired_fast(now, drag_btn_right_trigger[keycode - KC_MS_BTN1])) {
            // drag, nothing to do
          } else {
            //tap
            auto_mouse_early_trigger = now + AUTO_MOUSE_TIME_RIGHT_SIDE;
          }
        }
      }
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

  // call FwSys with Fn and Cursor
  state = update_tri_layer_state(state, L_Function, L_Cursor, L_Firmware); 
  
  // on mouse, number/cursor override
  state = update_tri_layer_state(state, L_Mouse, L_Number, L_Mouse_Number_Override);
  state = update_tri_layer_state(state, L_Mouse, L_Cursor, L_Mouse_Cursor_Override);
  
  // ANSI/JIS addiional enable
  state = update_tri_layer_state(state, L_Base_JIS, L_Number, L_Number_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_Cursor, L_Cursor_JIS);
  state = update_tri_layer_state(state, L_Base_JIS, L_BothThumb, L_BothThumb_JIS);
  
  // scroll lock release
  if (layer_state_cmp(state, L_Mouse) == false) {
    lock_scrolling = false;
    lock_turbo = false;
    lock_aim = false;

    navigator_turbo = false;
    navigator_aim = false;
  }
  
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
    case L_Mouse_Number_Override:
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
    case L_Set_Speed:
      status_led(now, 0b1100, led_pattern_on);
      status_led(now, 0b0011, led_pattern_blink);
      break;
    case L_Halt_Mask:
      status_led(now, 0b1111, led_pattern_off);
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
    case L_Mouse_Number_Override:
    case L_Mouse_Cursor_Override:
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
  total_move_local.h += mouse_report.h;
  total_move_local.v += mouse_report.v;
  
  bool activate = false;

  activate = activate || abs(total_move_local.x) > AUTO_MOUSE_THRESHOLD;
  activate = activate || abs(total_move_local.y) > AUTO_MOUSE_THRESHOLD;  
  activate = activate || abs(total_move_local.h) > AUTO_MOUSE_SCROLL_THRESHOLD;
  activate = activate || abs(total_move_local.v) > AUTO_MOUSE_SCROLL_THRESHOLD;
  activate = activate || mouse_report.buttons;
  
  fast_timer_t now = timer_read_fast();

  if (activate) {
    auto_mouse_early_trigger = now + (UINT32_MAX / 2) - 1;
    auto_mouse_count_reset_trigger = now + AUTO_MOUSE_COUNT_RESET_DELAY;

    // wakeup RGB
    activate_fade_matrix(now);
    
    total_move_local.x = 0;
    total_move_local.y = 0;
    total_move_local.h = 0;
    total_move_local.v = 0;
  } else if (timer_expired_fast(now, auto_mouse_count_reset_trigger)) {
    auto_mouse_count_reset_trigger = now + AUTO_MOUSE_COUNT_RESET_DELAY;

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
