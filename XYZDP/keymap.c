#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    MT(MOD_RCTL, KC_A),MT(MOD_RCTL, KC_B),MT(MOD_LCTL, KC_Y),MT(MOD_LCTL, KC_O),MT(MOD_LCTL, KC_U),MT(MOD_RCTL, KC_C),                                MT(MOD_RCTL, KC_G),MT(MOD_LCTL, KC_D),MT(MOD_LCTL, KC_N),MT(MOD_LCTL, KC_G),MT(MOD_RCTL, KC_F),CW_TOGG,        
    MT(MOD_LCTL, KC_B),MT(MOD_LCTL, KC_H),MT(MOD_LCTL, KC_I),MT(MOD_LCTL, KC_A),MT(MOD_LCTL, KC_E),MT(MOD_RCTL, KC_D),                                MT(MOD_RCTL, KC_H),MT(MOD_LCTL, KC_T),MT(MOD_LCTL, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LCTL, KC_C),MT(MOD_LCTL, KC_V),
    MT(MOD_LCTL, KC_Q),MT(MOD_LCTL, KC_K),MT(MOD_LCTL, KC_J),MT(MOD_LCTL, KC_X),MT(MOD_LCTL, KC_W),MT(MOD_RCTL, KC_E),                                MT(MOD_RCTL, KC_I),MT(MOD_LCTL, KC_M),MT(MOD_LCTL, KC_L),MT(MOD_LCTL, KC_F),MT(MOD_LCTL, KC_P),MT(MOD_LCTL, KC_Z),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        MT(MOD_LCTL, KC_SPACE),SH_T(KC_LNG2),                                          SH_T(KC_LNG1),          MT(MOD_LCTL, KC_SPACE),MT(MOD_LCTL, KC_DELETE),KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    MT(MOD_LCTL, KC_TAB),MT(MOD_LCTL, KC_ESCAPE),                                MT(MOD_LCTL, KC_BSPC),KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN4,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MO(9),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN4,                                     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(10),         
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                     KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_CTRL,  
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(3),          KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(4),          KC_TRANSPARENT, NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_RIGHT_SHIFT, 
                                                    KC_MS_BTN2,     KC_MS_BTN1,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, MT(MOD_RCTL, KC_COMMA),MT(MOD_RCTL, KC_DOT),MT(MOD_RCTL, KC_6),MT(MOD_RSFT | MOD_RCTL, KC_6),                                MT(MOD_RSFT | MOD_RCTL, KC_5),MT(MOD_RCTL, KC_5),MT(MOD_RCTL, KC_COMMA),MT(MOD_RCTL, KC_DOT),KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_RCTL, KC_L),MT(MOD_RCTL, KC_1),MT(MOD_RCTL, KC_2),MT(MOD_RCTL, KC_3),MT(MOD_RCTL, KC_4),MT(MOD_RCTL, KC_5),                                MT(MOD_RCTL, KC_6),MT(MOD_RCTL, KC_7),MT(MOD_RCTL, KC_8),MT(MOD_RCTL, KC_9),MT(MOD_RCTL, KC_0),MT(MOD_RCTL, KC_R),
    MT(MOD_RSFT | MOD_RCTL, KC_L),MT(MOD_RSFT | MOD_RCTL, KC_1),MT(MOD_RSFT | MOD_RCTL, KC_2),MT(MOD_RSFT | MOD_RCTL, KC_3),MT(MOD_RSFT | MOD_RCTL, KC_4),MT(MOD_RSFT | MOD_RCTL, KC_5),                                MT(MOD_RSFT | MOD_RCTL, KC_6),MT(MOD_RSFT | MOD_RCTL, KC_7),MT(MOD_RSFT | MOD_RCTL, KC_8),MT(MOD_RSFT | MOD_RCTL, KC_9),MT(MOD_RSFT | MOD_RCTL, KC_0),MT(MOD_RSFT | MOD_RCTL, KC_R),
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_RSFT | MOD_RCTL, KC_C),                                MT(MOD_RSFT | MOD_RCTL, KC_G),LCTL(KC_V),     KC_UP,          LCTL(KC_C),     KC_APPLICATION, KC_BSPC,        
    MO(9),          MT(MOD_LALT, KC_A),MT(MOD_LALT, KC_B),MT(MOD_LALT, KC_C),MT(MOD_LALT, KC_D),MT(MOD_RSFT | MOD_RCTL, KC_D),                                MT(MOD_RSFT | MOD_RCTL, KC_H),KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      MO(10),         
    KC_LEFT_CTRL,   MT(MOD_LALT, KC_E),MT(MOD_LALT, KC_F),MT(MOD_LALT, KC_G),MT(MOD_LALT, KC_H),MT(MOD_RSFT | MOD_RCTL, KC_E),                                MT(MOD_RSFT | MOD_RCTL, KC_I),MT(MOD_LALT, KC_I),MT(MOD_LALT, KC_J),MT(MOD_LALT, KC_K),MT(MOD_LALT, KC_L),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    CW_TOGG,        MT(MOD_LCTL, KC_F21),MT(MOD_LCTL, KC_F22),MT(MOD_LCTL, KC_F23),MT(MOD_LCTL, KC_F24),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_LCTL, KC_F11),MT(MOD_LCTL, KC_F1),MT(MOD_LCTL, KC_F2),MT(MOD_LCTL, KC_F3),MT(MOD_LCTL, KC_F4),MT(MOD_LCTL, KC_F5),                                MT(MOD_LCTL, KC_F6),MT(MOD_LCTL, KC_F7),MT(MOD_LCTL, KC_F8),MT(MOD_LCTL, KC_F9),MT(MOD_LCTL, KC_F10),MT(MOD_LCTL, KC_F12),
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),MT(MOD_LCTL, KC_F12),MT(MOD_LCTL, KC_F13),MT(MOD_LCTL, KC_F14),MT(MOD_LCTL, KC_F15),                                MT(MOD_LCTL, KC_F16),MT(MOD_LCTL, KC_F17),MT(MOD_LCTL, KC_F18),MT(MOD_LCTL, KC_F19),MT(MOD_LCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),                                     LCTL(KC_Y),     LCTL(KC_U),     LCTL(KC_I),     LCTL(KC_O),     LCTL(KC_P),     KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                     LCTL(KC_H),     LCTL(KC_J),     LCTL(KC_K),     LCTL(KC_L),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                                     LCTL(KC_N),     LCTL(KC_M),     LCTL(KC_COMMA), LCTL(KC_DOT),   KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(LSFT(KC_R)),KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(LSFT(KC_S)),LALT(KC_PSCR),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(LSFT(KC_T)),LGUI(KC_PSCR),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [16] = LAYOUT_voyager(
    CW_TOGG,        MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),LGUI(KC_V),                                     KC_TRANSPARENT, MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),
    KC_LEFT_CTRL,   MT(MOD_LALT, KC_M),MT(MOD_LALT, KC_N),MT(MOD_LSFT | MOD_LCTL, KC_M),MT(MOD_LSFT | MOD_LCTL, KC_M),LGUI(LSFT(KC_V)),                                KC_BSPC,        MT(MOD_LSFT | MOD_LALT, KC_I),MT(MOD_LSFT | MOD_LALT, KC_J),MT(MOD_LSFT | MOD_LALT, KC_K),MT(MOD_LSFT | MOD_LALT, KC_L),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [17] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN8,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN7,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_MS_BTN6,     KC_MS_BTN5,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [18] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN8,     KC_MS_BTN6,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN7,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN5,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [19] = LAYOUT_voyager(
    MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),                                MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),
    MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),                                MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),
    MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),                                MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),
    KC_LEFT_SHIFT,  KC_CAPS,        KC_NO,          MT(MOD_LSFT | MOD_LCTL, KC_F),KC_NO,          MT(MOD_LSFT | MOD_LCTL, KC_H),                                KC_NUM,         KC_SCRL,        KC_NO,          MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),MT(MOD_LSFT | MOD_LCTL, KC_F),
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MT(MOD_LSFT | MOD_LCTL, KC_1),MT(MOD_LSFT | MOD_LCTL, KC_H)
  ),
  [20] = LAYOUT_voyager(
    MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),                                MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),
    MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),                                MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),
    MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),                                MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),
    MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),                                MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),MT(MOD_LSFT | MOD_LCTL, KC_C),
                                                    MT(MOD_LSFT | MOD_LCTL, KC_6),MT(MOD_LSFT | MOD_LCTL, KC_7),                                MT(MOD_LSFT | MOD_LCTL, KC_2),MT(MOD_LSFT | MOD_LCTL, KC_P)
  ),
};

// -----------------------------------------------------------------------------
//
//
// GitHub C additional declaration
// declaration berofe process_record_user
//
//
// -----------------------------------------------------------------------------

// module impl
#include "addons/adv_mouse.h"
#include "addons/fade_matrix.h"
#include "addons/firmware_map.h"
#include "addons/ime_state_sync.h"
#include "addons/layer_mod_overlay.h"
#include "addons/orthogonality_mod_layer_lang.h"
#include "addons/status_led.h"

// -----------------------------------------------------------------------------
//
//
// End of GitHub C additional declaration
//
//
// -----------------------------------------------------------------------------




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

	case RGB_SLD:
      return fade_matrix_rgb_sld_keyrecord(record);
  }
  
  // -----------------------------------------------------------------------------
  // extra process_record, return false, break
  // -----------------------------------------------------------------------------

  if (process_record_fade_matrix(keycode, record) == false) return false;
  if (process_record_ime_state_sync(keycode, record) == false) return false;
  if (process_record_orthogonality_mod_layer_lang(keycode, record) == false) return false;
  
  return true;
}

// -----------------------------------------------------------------------------
//
//
// GitHub C additional definition
//
//
// -----------------------------------------------------------------------------

#include "layer_num.h"

// enum for layer define sync oryx side
#define ORYX_LAYER_COUNT (sizeof(keymaps) / sizeof(keymaps[0]))
_Static_assert(C_LAYER_COUNT == ORYX_LAYER_COUNT, "C and ORYX layer count missmatch!!");
#undef ORYX_LAYER_COUNT

_Static_assert(LAYER_Mouse == AUTOMOUSE_LAYER, "Auto Mouse layer missmatch!!");

// access to voyager system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;

// idle loop
#include "ch.h"
void chSysIdleHook(void) {
  __DSB();
  __WFI();
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

  keyboard_post_init_addtional_power_setting();
  keyboard_post_init_adv_mouse();
  keyboard_post_init_fade_matrix();
  keyboard_post_init_status_led();
  
  //JIS / no transition
  layer_move(LAYER_Base);
  layer_off(LAYER_Transition);
	
  jis_enable();
  mac_disable();
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  if (process_detected_host_os_fade_matrix(detected_os) == false) return false;

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
			case HOOR(KC_SPACE):
			
			case HOOR(KC_B):
			case HOOR(KC_V):
		
			case THOR1(KC_L): 
			case THOR1(KC_R):
		
			case HOOR(KC_F11):
			case HOOR(KC_F12):
        return 0;

      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  
  return 0;  // Disable Flow Tap.
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // same side thumb and pin
  state = update_tri_layer_state(state, LAYER_Number, LAYER_L_pinky, LAYER_L_thumb_L_pinky);
  state = update_tri_layer_state(state, LAYER_Cursor, LAYER_R_pinky, LAYER_R_thumb_R_pinky);
  
  // both outer pin
  state = update_tri_layer_state(state, LAYER_L_pinky, LAYER_R_pinky, LAYER_LR_pinky);
  
  // cross side thumb and pin
  state = update_tri_layer_state(state, LAYER_Number, LAYER_R_pinky, LAYER_L_thumb_R_pinky);
  state = update_tri_layer_state(state, LAYER_Cursor, LAYER_L_pinky, LAYER_R_thumb_L_pinky);

  // both thumb
  state = update_tri_layer_state(state, LAYER_Number, LAYER_Cursor, LAYER_LR_thumb);
    
  // call FwSys
  state = update_tri_layer_state(state, LAYER_Function, LAYER_L_thumb_2, LAYER_Firmware); 

  state = layer_state_set_adv_mouse(state);
  state = layer_state_set_fade_matrix(state);
  state = layer_state_set_firmware_map(state);
  
  // status LED, if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
  if (is_launching || !keyboard_config.led_level) return state;
  
  uint8_t layer = get_highest_layer(state);
  
  switch (layer) {
    case LAYER_Base:
    case LAYER_Transition:
      status_led(0b0011, led_pattern_off);

      if (is_swap_hands_on()) {
        status_led(0b1100, led_pattern_on);
      } else {
        status_led(0b1100, led_pattern_off);
      }
      break;
    case LAYER_Mouse:
      // mouse indication
      status_led(0b1000, led_pattern_on);
      // DRAG_SCROLL add on key event
      // aim/turbo change without layer, direct write on process_record
      break;
    case LAYER_Number:
    case LAYER_Cursor:
	  // mouse on keep top bit
      status_led(0b0011, led_pattern_off);
      status_led(0b0100, led_pattern_delayed_on);
      break;
    case LAYER_Function:
    case LAYER_R_thumb_1:
    case LAYER_L_thumb_2:
    case LAYER_R_thumb_2:
    case LAYER_L_pinky:
    case LAYER_R_pinky:  
      status_led(0b1111, led_pattern_off);
      break;
    case LAYER_L_thumb_L_pinky:
      status_led(0b1001, led_pattern_off);
      status_led(0b0110, led_pattern_on);
      break;
    case LAYER_R_thumb_R_pinky:
      status_led(0b1010, led_pattern_off);
      status_led(0b0101, led_pattern_on);
      break;
    case LAYER_LR_pinky:
      status_led(0b1100, led_pattern_off);
      status_led(0b0011, led_pattern_on);
      break;
    case LAYER_L_thumb_R_pinky:
    case LAYER_R_thumb_L_pinky:
    case LAYER_LR_thumb:
      status_led(0b1000, led_pattern_off);
      status_led(0b0111, led_pattern_on);
      break;
    case LAYER_Mouse_Upper_Left:
    case LAYER_Mouse_Upper_Right:
      // mouse indication
      status_led(0b1000, led_pattern_on);
      // DRAG_SCROLL add on key event
      // aim/turbo change without layer, direct write on process_record
      break;    
    case LAYER_Firmware:
      status_led(0b1111, led_pattern_off);
      break;
    case LAYER_Color_Palette:
      status_led(0b0011, led_pattern_off);
      status_led(0b1100, led_pattern_on);
      break;
    
    default:
      status_led(0b1111, led_pattern_off);
      break;
  }  
  return state;
}

bool rgb_matrix_indicators_user(void) {
  // disable rawhid
  //if (rawhid_state.rgb_control) {
  //    return false;
  //}
  if (keyboard_config.disable_layer_led) { return false; }
  switch (get_highest_layer(layer_state)) {
    case LAYER_Firmware:
      set_layer_color_firmware_map();
      break;
    case LAYER_Color_Palette:
      set_layer_color_palette_map();
      break;
    
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      } else {
        set_layer_color_overlay_mouse();
        set_layer_color_overlay_mod();
        set_layer_color_overlay_ime_state_sync();
        set_layer_color_overlay_layer();
      }
      break;
  }
  return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (pre_process_record_fade_matrix(keycode, record) == false) return false;
  if (pre_process_record_ime_state_sync(keycode, record) == false) return false;
  
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  post_process_record_adv_mouse(keycode, record);
  post_process_record_ime_state_sync(keycode, record);
  
  return;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report = pointing_device_task_adv_mouse(mouse_report);
  mouse_report = pointing_device_task_fade_matrix(mouse_report);
  
  return mouse_report;
}

void housekeeping_task_user(void) {
  housekeeping_task_adv_mouse();
  housekeeping_task_fade_matrix();
  housekeeping_task_ime_state_sync();
  housekeeping_task_status_led();

  // exec halt last
  housekeeping_task_exec_halt();

  return;
}
