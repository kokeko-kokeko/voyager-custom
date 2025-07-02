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



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

#define DUAL_FUNC_0 LT(4, KC_6)
#define DUAL_FUNC_1 LT(12, KC_F11)
#define DUAL_FUNC_2 LT(8, KC_H)
#define DUAL_FUNC_3 LT(6, KC_9)
#define DUAL_FUNC_4 LT(13, KC_F9)
#define DUAL_FUNC_5 LT(4, KC_F18)
#define DUAL_FUNC_6 LT(3, KC_T)
#define DUAL_FUNC_7 LT(12, KC_F3)
#define DUAL_FUNC_8 LT(1, KC_F24)
#define DUAL_FUNC_9 LT(1, KC_F13)
#define DUAL_FUNC_10 LT(12, KC_G)
#define DUAL_FUNC_11 LT(11, KC_A)
#define DUAL_FUNC_12 LT(13, KC_O)
#define DUAL_FUNC_13 LT(6, KC_F6)
#define DUAL_FUNC_14 LT(9, KC_F3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_1,           KC_2,           KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_7,           KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    KC_B,           MT(MOD_LALT, KC_C),LT(7, KC_I),    MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),KC_COMMA,                                       KC_DOT,         MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),LT(8, KC_S),    MT(MOD_RALT, KC_N),MT(MOD_RGUI, KC_V),
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           KC_MINUS,                                       KC_9,           KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(6, KC_LANGUAGE_1),LT(2, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(6, KC_TAB),  TD(DANCE_0),                                    TD(DANCE_1),    KC_ENTER
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
    MT(MOD_LGUI, KC_LBRC),MT(MOD_LALT, KC_1),LT(7, KC_2),    MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),LT(8, KC_9),    MT(MOD_RALT, KC_0),MT(MOD_RGUI, KC_RBRC),
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
    MT(MOD_LGUI, KC_F11),MT(MOD_LALT, KC_F1),LT(7, KC_F2),   MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),LT(8, KC_F9),   MT(MOD_RALT, KC_F10),MT(MOD_RGUI, KC_F12),
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    LCTL(KC_Q),     LCTL(KC_W),     CW_TOGG,        LCTL(KC_E),     LCTL(KC_R),     LGUI(LCTL(KC_V)),                                KC_ESCAPE,      KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_TAB,         KC_BSPC,        
    DUAL_FUNC_11,   DUAL_FUNC_12,   KC_TRANSPARENT, DUAL_FUNC_13,   DUAL_FUNC_14,   LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_APPLICATION, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_23,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    HSV_43_255_100, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    HSV_43_255_106, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_NO,          KC_NO
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
                                                    KC_TRANSPARENT, KC_NO,                                          KC_NO,          HSV_86_255_151
  ),
  [12] = LAYOUT_voyager(
    HSV_172_255_100,HSV_172_255_101,HSV_172_255_102,HSV_172_255_103,HSV_172_255_104,HSV_172_255_105,                                HSV_172_255_126,HSV_172_255_127,HSV_172_255_128,HSV_172_255_129,HSV_172_255_130,HSV_172_255_131,
    HSV_172_255_106,HSV_172_255_107,HSV_172_255_108,HSV_172_255_109,HSV_172_255_110,HSV_172_255_111,                                HSV_172_255_132,HSV_172_255_133,HSV_172_255_134,HSV_172_255_135,HSV_172_255_136,HSV_172_255_137,
    HSV_172_255_112,HSV_172_255_113,HSV_172_255_114,HSV_172_255_115,HSV_172_255_116,HSV_172_255_117,                                HSV_172_255_138,HSV_172_255_139,HSV_172_255_140,HSV_172_255_141,HSV_172_255_142,HSV_172_255_143,
    HSV_172_255_118,HSV_172_255_119,HSV_172_255_120,HSV_172_255_121,HSV_172_255_122,HSV_172_255_123,                                HSV_172_255_144,HSV_172_255_145,HSV_172_255_146,HSV_172_255_147,HSV_172_255_148,HSV_172_255_149,
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_NO,          HSV_172_255_151
  ),
};






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
        rgblight_mode(1);
      }
      return false;
    case HSV_43_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,100);
      }
      return false;
    case HSV_43_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,106);
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
    case HSV_86_255_151:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,151);
      }
      return false;
    case HSV_172_255_100:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,100);
      }
      return false;
    case HSV_172_255_101:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,101);
      }
      return false;
    case HSV_172_255_102:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,102);
      }
      return false;
    case HSV_172_255_103:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,103);
      }
      return false;
    case HSV_172_255_104:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,104);
      }
      return false;
    case HSV_172_255_105:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,105);
      }
      return false;
    case HSV_172_255_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,106);
      }
      return false;
    case HSV_172_255_107:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,107);
      }
      return false;
    case HSV_172_255_108:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,108);
      }
      return false;
    case HSV_172_255_109:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,109);
      }
      return false;
    case HSV_172_255_110:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,110);
      }
      return false;
    case HSV_172_255_111:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,111);
      }
      return false;
    case HSV_172_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,112);
      }
      return false;
    case HSV_172_255_113:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,113);
      }
      return false;
    case HSV_172_255_114:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,114);
      }
      return false;
    case HSV_172_255_115:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,115);
      }
      return false;
    case HSV_172_255_116:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,116);
      }
      return false;
    case HSV_172_255_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,117);
      }
      return false;
    case HSV_172_255_118:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,118);
      }
      return false;
    case HSV_172_255_119:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,119);
      }
      return false;
    case HSV_172_255_120:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,120);
      }
      return false;
    case HSV_172_255_121:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,121);
      }
      return false;
    case HSV_172_255_122:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,122);
      }
      return false;
    case HSV_172_255_123:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,123);
      }
      return false;
    case HSV_172_255_126:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,126);
      }
      return false;
    case HSV_172_255_127:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,127);
      }
      return false;
    case HSV_172_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,128);
      }
      return false;
    case HSV_172_255_129:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,129);
      }
      return false;
    case HSV_172_255_130:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,130);
      }
      return false;
    case HSV_172_255_131:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,131);
      }
      return false;
    case HSV_172_255_132:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,132);
      }
      return false;
    case HSV_172_255_133:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,133);
      }
      return false;
    case HSV_172_255_134:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,134);
      }
      return false;
    case HSV_172_255_135:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,135);
      }
      return false;
    case HSV_172_255_136:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,136);
      }
      return false;
    case HSV_172_255_137:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,137);
      }
      return false;
    case HSV_172_255_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,138);
      }
      return false;
    case HSV_172_255_139:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,139);
      }
      return false;
    case HSV_172_255_140:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,140);
      }
      return false;
    case HSV_172_255_141:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,141);
      }
      return false;
    case HSV_172_255_142:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,142);
      }
      return false;
    case HSV_172_255_143:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,143);
      }
      return false;
    case HSV_172_255_144:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,144);
      }
      return false;
    case HSV_172_255_145:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,145);
      }
      return false;
    case HSV_172_255_146:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,146);
      }
      return false;
    case HSV_172_255_147:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,147);
      }
      return false;
    case HSV_172_255_148:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,148);
      }
      return false;
    case HSV_172_255_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,149);
      }
      return false;
    case HSV_172_255_151:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,151);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: layer_on(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(2)) {
            layer_off(2);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(9)) {
                  layer_off(9);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: layer_on(4); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_HOLD: layer_on(10); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(4)) {
            layer_off(4);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(10)) {
                  layer_off(10);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
