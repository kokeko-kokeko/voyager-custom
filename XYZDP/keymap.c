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
  HSV_86_255_255,
  HSV_172_255_210,
  HSV_0_255_211,
  HSV_172_255_211,
  HSV_0_255_212,
  HSV_172_255_212,
  HSV_0_255_213,
  HSV_172_255_213,
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



#define DUAL_FUNC_0 LT(14, KC_Z)
#define DUAL_FUNC_1 LT(5, KC_F7)
#define DUAL_FUNC_2 LT(8, KC_F2)
#define DUAL_FUNC_3 LT(7, KC_F6)
#define DUAL_FUNC_4 LT(2, KC_Q)
#define DUAL_FUNC_5 LT(15, KC_R)
#define DUAL_FUNC_6 LT(7, KC_F17)
#define DUAL_FUNC_7 LT(10, KC_C)
#define DUAL_FUNC_8 LT(10, KC_D)
#define DUAL_FUNC_9 LT(13, KC_D)
#define DUAL_FUNC_10 LT(4, KC_N)
#define DUAL_FUNC_11 LT(6, KC_S)
#define DUAL_FUNC_12 LT(13, KC_K)
#define DUAL_FUNC_13 LT(15, KC_W)
#define DUAL_FUNC_14 LT(7, KC_J)
#define DUAL_FUNC_15 LT(9, KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    JP_AT,          KC_1,           MT(MOD_LALT | MOD_LGUI | MOD_LSFT | MOD_LCTL, KC_Y),MT(MOD_LALT | MOD_LSFT, KC_O),MT(MOD_LALT | MOD_LCTL, KC_U),KC_2,                                           KC_3,           MT(MOD_RALT | MOD_RCTL, KC_D),MT(MOD_RALT | MOD_RSFT, KC_N),MT(MOD_RALT | MOD_RSFT | MOD_RCTL, KC_G),KC_SLASH,       CW_TOGG,        
    LT(10, KC_B),   MT(MOD_LSFT | MOD_LCTL, KC_H),MT(MOD_LGUI | MOD_LALT, KC_I),MT(MOD_LSFT, KC_A),MT(MOD_LCTL, KC_E),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_T),MT(MOD_RSFT, KC_R),MT(MOD_RGUI | MOD_RALT, KC_S),MT(MOD_RSFT | MOD_RCTL, KC_C),LT(11, KC_V),   
    MT(MOD_LCTL, KC_Q),MT(MOD_LGUI, KC_K),MT(MOD_LALT, KC_J),MT(MOD_LGUI | MOD_LSFT, KC_X),MT(MOD_LGUI | MOD_LCTL, KC_W),KC_MINUS,                                       KC_4,           MT(MOD_RGUI | MOD_RCTL, KC_M),MT(MOD_RGUI | MOD_RSFT, KC_L),MT(MOD_RALT, KC_F),MT(MOD_RGUI, KC_P),MT(MOD_RCTL, KC_Z),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(6, KC_SPACE),LT(4, KC_LANGUAGE_2),                                LT(5, KC_LANGUAGE_1),LT(8, KC_SPACE),LT(4, KC_DELETE),KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(5, KC_TAB),  LT(8, KC_ESCAPE),                                LT(6, KC_BSPC), KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_1,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,                                       KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    LGUI(KC_TAB),   KC_TRANSPARENT, KC_MS_BTN8,     KC_MS_BTN7,     KC_MS_BTN6,     KC_MS_BTN5,                                     KC_MS_BTN4,     KC_MS_BTN2,     KC_MS_BTN5,     KC_MS_BTN6,     KC_MS_BTN7,     KC_MS_BTN8,     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN4,                                     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                     KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(6),          KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(8),          KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_RIGHT_SHIFT, 
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         MT(MOD_LALT | MOD_LGUI | MOD_LSFT | MOD_LCTL, KC_F22),MT(MOD_LALT | MOD_LSFT, KC_F23),MT(MOD_LALT | MOD_LCTL, KC_F24),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(10, KC_F11), MT(MOD_LSFT | MOD_LCTL, KC_F1),MT(MOD_LGUI | MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RGUI | MOD_RALT, KC_F9),MT(MOD_RSFT | MOD_RCTL, KC_F10),LT(11, KC_F12), 
    KC_LEFT_CTRL,   MT(MOD_LGUI, KC_F11),MT(MOD_LALT, KC_F12),MT(MOD_LGUI | MOD_LSFT, KC_F13),MT(MOD_LGUI | MOD_LCTL, KC_F14),KC_F15,                                         KC_F16,         MT(MOD_RGUI | MOD_RCTL, KC_F17),MT(MOD_RGUI | MOD_RSFT, KC_F18),MT(MOD_RALT, KC_F19),MT(MOD_RGUI, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    DUAL_FUNC_0,    KC_1,           KC_2,           MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),KC_9,           KC_0,           DUAL_FUNC_4,    
    DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    JP_TILD,        JP_PLUS,        KC_LABK,                                        KC_RABK,        JP_CIRC,        JP_AMPR,        DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,    
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(10, KC_LBRC),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(11, KC_RBRC),
    DUAL_FUNC_8,    DUAL_FUNC_9,    MT(MOD_LALT, KC_EQUAL),KC_TILD,        KC_PLUS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_TRANSPARENT, DUAL_FUNC_10,   DUAL_FUNC_11,   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, JP_LPRN,                                        JP_RPRN,        LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_APPLICATION, KC_BSPC,        
    MO(10),         LCTL(KC_A),     LCTL(KC_S),     DUAL_FUNC_12,   DUAL_FUNC_13,   KC_SCLN,                                        JP_COLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      MO(11),         
    KC_LEFT_CTRL,   MT(MOD_LGUI, KC_HOME),MT(MOD_LALT, KC_END),KC_PAGE_UP,     KC_PGDN,        JP_UNDS,                                        KC_EXLM,        KC_1,           KC_2,           KC_3,           KC_4,           KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,                                        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,                                        KC_TRANSPARENT, KC_1,           KC_2,           KC_TRANSPARENT, KC_4,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_R)),LGUI(LSFT(KC_S)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_T)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [12] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [13] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [14] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     LGUI(KC_V),                                     KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    
    KC_LEFT_CTRL,   DUAL_FUNC_14,   DUAL_FUNC_15,   ST_MACRO_7,     ST_MACRO_8,     LGUI(LSFT(KC_V)),                                KC_BSPC,        JP_RBRC,        JP_RCBR,        KC_RABK,        JP_RPRN,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [15] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_20,    ST_MACRO_21,    KC_TRANSPARENT, ST_MACRO_22,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RBRC,        KC_RCBR,        KC_TRANSPARENT, KC_RPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [16] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [17] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [18] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_TRANSPARENT,                                 KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_1,           KC_2,           MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [19] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     DUAL_FUNC_12,   DUAL_FUNC_13,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [20] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [21] = LAYOUT_voyager(
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
    KC_LEFT_SHIFT,  KC_CAPS,        HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,                                  HSV_0_255_200,  KC_NUM,         KC_SCRL,        HSV_0_255_200,  HSV_0_255_200,  HSV_0_255_200,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 HSV_86_255_200, HSV_86_255_201
  ),
  [22] = LAYOUT_voyager(
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
    HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,                                  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  HSV_0_255_210,  
                                                    MO(23),         MO(24),                                         HSV_86_255_255, HSV_172_255_210
  ),
  [23] = LAYOUT_voyager(
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
    HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,                                  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  HSV_0_255_211,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_172_255_211
  ),
  [24] = LAYOUT_voyager(
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
    HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,                                  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  HSV_0_255_212,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_172_255_212
  ),
  [25] = LAYOUT_voyager(
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
    HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,                                  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  HSV_0_255_213,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_172_255_213
  ),
  [26] = LAYOUT_voyager(
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
    HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,                                  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  HSV_0_255_255,  
                                                    KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO
  ),
};






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
    return true;
  }
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
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
          layer_on(10);
        } else {
          layer_off(10);
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
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
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
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
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
          layer_on(11);
        } else {
          layer_off(11);
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
          register_code16(KC_RIGHT_ALT);
        } else {
          unregister_code16(KC_RIGHT_ALT);
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
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
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
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
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
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
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
          register_code16(KC_EXLM);
        } else {
          unregister_code16(KC_EXLM);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
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
    case HSV_0_255_200:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,200);
      }
      return false;
    case HSV_86_255_200:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,200);
      }
      return false;
    case HSV_86_255_201:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,201);
      }
      return false;
    case HSV_0_255_210:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,210);
      }
      return false;
    case HSV_86_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,255);
      }
      return false;
    case HSV_172_255_210:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,210);
      }
      return false;
    case HSV_0_255_211:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,211);
      }
      return false;
    case HSV_172_255_211:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,211);
      }
      return false;
    case HSV_0_255_212:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,212);
      }
      return false;
    case HSV_172_255_212:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,212);
      }
      return false;
    case HSV_0_255_213:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,213);
      }
      return false;
    case HSV_172_255_213:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,213);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}
