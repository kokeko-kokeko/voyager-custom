#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_254,
  HSV_7_255_254,
  HSV_20_255_254,
  HSV_40_255_254,
  HSV_53_255_254,
  HSV_67_255_254,
  HSV_1_255_254,
  HSV_8_255_254,
  HSV_25_255_254,
  HSV_45_255_254,
  HSV_56_255_254,
  HSV_71_255_254,
  HSV_3_255_254,
  HSV_10_255_254,
  HSV_30_255_254,
  HSV_48_255_254,
  HSV_59_255_254,
  HSV_75_255_254,
  HSV_5_255_254,
  HSV_15_255_254,
  HSV_35_255_254,
  HSV_50_255_254,
  HSV_63_255_254,
  HSV_79_255_254,
  HSV_83_255_254,
  HSV_105_255_254,
  HSV_137_255_254,
  HSV_172_255_254,
  HSV_200_255_254,
  HSV_229_255_254,
  HSV_86_255_254,
  HSV_111_255_254,
  HSV_146_255_254,
  HSV_179_255_254,
  HSV_207_255_254,
  HSV_236_255_254,
  HSV_92_255_254,
  HSV_118_255_254,
  HSV_154_255_254,
  HSV_186_255_254,
  HSV_215_255_254,
  HSV_243_255_254,
  HSV_98_255_254,
  HSV_129_255_254,
  HSV_163_255_254,
  HSV_193_255_254,
  HSV_222_255_254,
  HSV_250_255_254,
  HSV_172_255_224,
  HSV_86_10_255,
  HSV_86_53_255,
  HSV_86_96_255,
  HSV_86_138_255,
  HSV_86_182_255,
  HSV_86_223_255,
  HSV_86_21_255,
  HSV_86_64_255,
  HSV_86_106_255,
  HSV_86_150_255,
  HSV_86_191_255,
  HSV_86_234_255,
  HSV_86_32_255,
  HSV_86_74_255,
  HSV_86_117_255,
  HSV_86_159_255,
  HSV_86_202_255,
  HSV_86_245_255,
  HSV_86_44_255,
  HSV_86_85_255,
  HSV_86_128_255,
  HSV_86_170_255,
  HSV_86_214_255,
  HSV_86_255_255,
  HSV_0_0_11,
  HSV_0_0_53,
  HSV_0_0_96,
  HSV_0_0_138,
  HSV_0_0_181,
  HSV_0_0_223,
  HSV_0_0_21,
  HSV_0_0_64,
  HSV_0_0_106,
  HSV_0_0_149,
  HSV_0_0_191,
  HSV_0_0_234,
  HSV_0_0_32,
  HSV_0_0_74,
  HSV_0_0_117,
  HSV_0_0_159,
  HSV_0_0_202,
  HSV_0_0_244,
  HSV_0_0_43,
  HSV_0_0_85,
  HSV_0_0_128,
  HSV_0_0_170,
  HSV_0_0_213,
  HSV_0_0_255,
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
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

#define DUAL_FUNC_0 LT(2, KC_F10)
#define DUAL_FUNC_1 LT(13, KC_F6)
#define DUAL_FUNC_2 LT(10, KC_F7)
#define DUAL_FUNC_3 LT(13, KC_F17)
#define DUAL_FUNC_4 LT(10, KC_L)
#define DUAL_FUNC_5 LT(6, KC_1)
#define DUAL_FUNC_6 LT(12, KC_8)
#define DUAL_FUNC_7 LT(6, KC_F4)
#define DUAL_FUNC_8 LT(3, KC_P)
#define DUAL_FUNC_9 LT(5, KC_F2)
#define DUAL_FUNC_10 LT(13, KC_1)
#define DUAL_FUNC_11 LT(9, KC_8)
#define DUAL_FUNC_12 LT(14, KC_F14)
#define DUAL_FUNC_13 LT(8, KC_8)
#define DUAL_FUNC_14 LT(1, KC_4)
#define DUAL_FUNC_15 LT(10, KC_F17)
#define DUAL_FUNC_16 LT(9, KC_N)
#define DUAL_FUNC_17 LT(9, KC_K)
#define DUAL_FUNC_18 LT(1, KC_8)
#define DUAL_FUNC_19 LT(13, KC_F16)
#define DUAL_FUNC_20 LT(6, KC_C)
#define DUAL_FUNC_21 LT(10, KC_1)
#define DUAL_FUNC_22 LT(14, KC_F10)
#define DUAL_FUNC_23 LT(4, KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_AT,          KC_HASH,        KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_DQUO,        KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    LT(10, KC_B),   MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),LT(2, KC_E),    MT(MOD_LCTL, KC_A),ALL_T(KC_COMMA),                                MEH_T(KC_DOT),  MT(MOD_RCTL, KC_H),LT(2, KC_T),    MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(12, KC_V),   
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           KC_MINUS,                                       KC_QUES,        KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(8, KC_LANGUAGE_1),LT(6, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(8, KC_TAB),  TD(DANCE_0),                                    TD(DANCE_1),    KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    JP_AT,          JP_HASH,        KC_Y,           KC_O,           KC_U,           JP_QUOT,                                        JP_DQT,         KC_L,           KC_D,           KC_W,           JP_SLSH,        CW_TOGG,        
    LT(11, KC_B),   MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),LT(3, KC_E),    MT(MOD_LCTL, KC_A),ALL_T(KC_COMMA),                                MEH_T(KC_DOT),  MT(MOD_RCTL, KC_H),LT(3, KC_T),    MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(13, KC_V),   
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           JP_MINS,                                        JP_QUES,        KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(5, KC_SPACE),KC_LANGUAGE_2,                                  LT(9, KC_LANGUAGE_1),LT(7, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(9, KC_TAB),  TD(DANCE_2),                                    TD(DANCE_3),    KC_ENTER
  ),
  [2] = LAYOUT_voyager(
    KC_GRAVE,       KC_DLR,         LSFT(KC_Y),     LSFT(KC_O),     LSFT(KC_U),     KC_LPRN,                                        KC_RPRN,        LSFT(KC_L),     LSFT(KC_D),     LSFT(KC_W),     KC_BSLS,        KC_TRANSPARENT, 
    LSFT(KC_B),     DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    KC_SCLN,                                        KC_COLN,        DUAL_FUNC_6,    DUAL_FUNC_7,    DUAL_FUNC_8,    DUAL_FUNC_9,    LSFT(KC_V),     
    DUAL_FUNC_4,    DUAL_FUNC_5,    LSFT(KC_X),     LSFT(KC_J),     LSFT(KC_K),     KC_UNDS,                                        KC_EXLM,        LSFT(KC_R),     LSFT(KC_M),     LSFT(KC_F),     DUAL_FUNC_10,   DUAL_FUNC_11,   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, LSFT(KC_SPACE), KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  LSFT(KC_SPACE), KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    LSFT(KC_TAB),   LSFT(KC_ESCAPE),                                LSFT(KC_BSPC),  LSFT(KC_ENTER)
  ),
  [3] = LAYOUT_voyager(
    JP_GRV,         JP_DLR,         LSFT(KC_Y),     LSFT(KC_O),     LSFT(KC_U),     JP_LPRN,                                        JP_RPRN,        LSFT(KC_L),     LSFT(KC_D),     LSFT(KC_W),     JP_BSLS,        KC_TRANSPARENT, 
    LSFT(KC_B),     DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    JP_SCLN,                                        JP_COLN,        DUAL_FUNC_6,    DUAL_FUNC_7,    DUAL_FUNC_8,    DUAL_FUNC_9,    LSFT(KC_V),     
    DUAL_FUNC_4,    DUAL_FUNC_5,    LSFT(KC_X),     LSFT(KC_J),     LSFT(KC_K),     JP_UNDS,                                        JP_EXLM,        LSFT(KC_R),     LSFT(KC_M),     LSFT(KC_F),     DUAL_FUNC_10,   DUAL_FUNC_11,   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, LSFT(KC_SPACE), KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  LSFT(KC_SPACE), KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    LSFT(KC_TAB),   LSFT(KC_ESCAPE),                                LSFT(KC_BSPC),  LSFT(KC_ENTER)
  ),
  [4] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_AT,          KC_GRAVE,       KC_HASH,        KC_DLR,         KC_TRANSPARENT, 
    KC_LBRC,        MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),KC_RBRC,        
    DUAL_FUNC_12,   DUAL_FUNC_13,   KC_EQUAL,       KC_TILD,        KC_PLUS,        KC_LABK,                                        KC_RABK,        KC_CIRC,        KC_AMPR,        KC_PERC,        DUAL_FUNC_14,   DUAL_FUNC_15,   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [5] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, JP_COMM,        JP_DOT,         KC_6,           JP_GT,                                          KC_5,           JP_AT,          JP_GRV,         JP_HASH,        JP_DLR,         KC_TRANSPARENT, 
    JP_LBRC,        MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),MT(MOD_RSFT, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),JP_RBRC,        
    DUAL_FUNC_16,   DUAL_FUNC_17,   JP_EQL,         JP_TILD,        JP_PLUS,        JP_LT,                                          JP_GT,          JP_CIRC,        JP_AMPR,        JP_PERC,        DUAL_FUNC_18,   DUAL_FUNC_19,   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [6] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,                                     ST_MACRO_7,     KC_LBRC,        KC_LCBR,        KC_LABK,        KC_LPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_4,     ST_MACRO_5,     KC_AT,          KC_HASH,        KC_SLASH,                                       KC_BSLS,        ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    
    KC_LEFT_CTRL,   KC_EXLM,        KC_QUES,        KC_GRAVE,       KC_DLR,         ST_MACRO_6,                                     ST_MACRO_13,    KC_RBRC,        KC_RCBR,        KC_RABK,        KC_RPRN,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [7] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,                                    ST_MACRO_21,    JP_LBRC,        JP_LCBR,        JP_LT,          JP_LPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_18,    ST_MACRO_19,    JP_AT,          JP_HASH,        JP_SLSH,                                        JP_BSLS,        ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,    
    KC_LEFT_CTRL,   JP_EXLM,        JP_QUES,        JP_GRV,         JP_DLR,         ST_MACRO_20,                                    ST_MACRO_27,    JP_RBRC,        JP_RCBR,        JP_GT,          JP_RPRN,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [8] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         KC_F22,         KC_F23,         KC_F24,         LCTL(KC_RBRC),                                  LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),KC_TRANSPARENT, 
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [9] = LAYOUT_voyager(
    CW_TOGG,        KC_F21,         KC_F22,         KC_F23,         KC_F24,         LCTL(JP_RBRC),                                  LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),KC_TRANSPARENT, 
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [10] = LAYOUT_voyager(
    CW_TOGG,        DUAL_FUNC_20,   DUAL_FUNC_21,   KC_PAGE_UP,     KC_PGDN,        LGUI(LCTL(KC_V)),                                KC_TAB,         LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), KC_ESCAPE,      KC_APPLICATION, 
    KC_TRANSPARENT, DUAL_FUNC_22,   DUAL_FUNC_23,   LCTL(KC_C),     LCTL(KC_V),     LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_28,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [11] = LAYOUT_voyager(
    CW_TOGG,        DUAL_FUNC_20,   DUAL_FUNC_21,   KC_PAGE_UP,     KC_PGDN,        LGUI(LCTL(KC_V)),                                KC_TAB,         LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), KC_ESCAPE,      KC_APPLICATION, 
    KC_TRANSPARENT, DUAL_FUNC_22,   DUAL_FUNC_23,   LCTL(KC_C),     LCTL(KC_V),     LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_29,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [12] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [13] = LAYOUT_voyager(
    CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_2,                                  KC_LANGUAGE_1,  KC_SPACE,       KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [14] = LAYOUT_voyager(
    HSV_0_255_254,  HSV_7_255_254,  HSV_20_255_254, HSV_40_255_254, HSV_53_255_254, HSV_67_255_254,                                 HSV_83_255_254, HSV_105_255_254,HSV_137_255_254,HSV_172_255_254,HSV_200_255_254,HSV_229_255_254,
    HSV_1_255_254,  HSV_8_255_254,  HSV_25_255_254, HSV_45_255_254, HSV_56_255_254, HSV_71_255_254,                                 HSV_86_255_254, HSV_111_255_254,HSV_146_255_254,HSV_179_255_254,HSV_207_255_254,HSV_236_255_254,
    HSV_3_255_254,  HSV_10_255_254, HSV_30_255_254, HSV_48_255_254, HSV_59_255_254, HSV_75_255_254,                                 HSV_92_255_254, HSV_118_255_254,HSV_154_255_254,HSV_186_255_254,HSV_215_255_254,HSV_243_255_254,
    HSV_5_255_254,  HSV_15_255_254, HSV_35_255_254, HSV_50_255_254, HSV_63_255_254, HSV_79_255_254,                                 HSV_98_255_254, HSV_129_255_254,HSV_163_255_254,HSV_193_255_254,HSV_222_255_254,HSV_250_255_254,
                                                    KC_NO,          MO(15),                                         KC_NO,          HSV_172_255_224
  ),
  [15] = LAYOUT_voyager(
    HSV_86_10_255,  HSV_86_53_255,  HSV_86_96_255,  HSV_86_138_255, HSV_86_182_255, HSV_86_223_255,                                 HSV_0_0_11,     HSV_0_0_53,     HSV_0_0_96,     HSV_0_0_138,    HSV_0_0_181,    HSV_0_0_223,    
    HSV_86_21_255,  HSV_86_64_255,  HSV_86_106_255, HSV_86_150_255, HSV_86_191_255, HSV_86_234_255,                                 HSV_0_0_21,     HSV_0_0_64,     HSV_0_0_106,    HSV_0_0_149,    HSV_0_0_191,    HSV_0_0_234,    
    HSV_86_32_255,  HSV_86_74_255,  HSV_86_117_255, HSV_86_159_255, HSV_86_202_255, HSV_86_245_255,                                 HSV_0_0_32,     HSV_0_0_74,     HSV_0_0_117,    HSV_0_0_159,    HSV_0_0_202,    HSV_0_0_244,    
    HSV_86_44_255,  HSV_86_85_255,  HSV_86_128_255, HSV_86_170_255, HSV_86_214_255, HSV_86_255_255,                                 HSV_0_0_43,     HSV_0_0_85,     HSV_0_0_128,    HSV_0_0_170,    HSV_0_0_213,    HSV_0_0_255,    
                                                    KC_NO,          KC_NO,                                          KC_NO,          HSV_172_255_224
  ),
  [16] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_NO,          KC_NO,          QK_BOOT,        
    TO(1),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_NO,          EE_CLR,         
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,                                KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_NO,          RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    LGUI(LSFT(KC_SLASH)),KC_NO,                                          LALT(LCTL(KC_DELETE)),LGUI(KC_L)
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [14] = { {0,255,255}, {7,255,255}, {20,255,255}, {40,255,255}, {53,255,255}, {67,255,255}, {1,255,255}, {8,255,255}, {25,255,255}, {45,255,255}, {56,255,255}, {71,255,255}, {3,255,255}, {10,255,255}, {30,255,255}, {48,255,255}, {59,255,255}, {75,255,255}, {5,255,255}, {15,255,255}, {35,255,255}, {50,255,255}, {63,255,255}, {79,255,255}, {0,0,0}, {0,0,255}, {83,255,255}, {105,255,255}, {137,255,255}, {172,255,255}, {200,255,255}, {229,255,255}, {86,255,255}, {111,255,255}, {146,255,255}, {179,255,255}, {207,255,255}, {236,255,255}, {92,255,255}, {118,255,255}, {154,255,255}, {186,255,255}, {215,255,255}, {243,255,255}, {98,255,255}, {129,255,255}, {163,255,255}, {193,255,255}, {222,255,255}, {250,255,255}, {0,0,0}, {172,255,255} },

    [15] = { {86,10,255}, {86,53,255}, {86,96,255}, {86,138,255}, {86,182,255}, {86,223,255}, {86,21,255}, {86,64,255}, {86,106,255}, {86,150,255}, {86,191,255}, {86,234,255}, {86,32,255}, {86,74,255}, {86,117,255}, {86,159,255}, {86,202,255}, {86,245,255}, {86,44,255}, {86,85,255}, {86,128,255}, {86,170,255}, {86,214,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,11}, {0,0,53}, {0,0,96}, {0,0,138}, {0,0,181}, {0,0,223}, {0,0,21}, {0,0,64}, {0,0,106}, {0,0,149}, {0,0,191}, {0,0,234}, {0,0,32}, {0,0,74}, {0,0,117}, {0,0,159}, {0,0,202}, {0,0,244}, {0,0,43}, {0,0,85}, {0,0,128}, {0,0,170}, {0,0,213}, {0,0,255}, {0,0,0}, {172,255,255} },

    [16] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {215,255,128}, {215,255,255}, {86,255,255}, {0,0,0}, {21,255,128}, {21,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {86,255,128}, {86,255,255}, {43,255,128}, {43,255,255}, {0,0,0}, {21,255,255}, {129,255,128}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {172,255,255}, {0,0,0}, {0,0,128}, {0,0,255}, {0,255,255}, {0,255,255}, {172,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 14:
      set_layer_color(14);
      break;
    case 15:
      set_layer_color(15);
      break;
    case 16:
      set_layer_color(16);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
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
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_LSFT(SS_TAP(X_8)));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_1))SS_DELAY(100)  SS_LSFT(SS_TAP(X_SLASH)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SLASH))SS_DELAY(100)  SS_LSFT(SS_TAP(X_1)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_LSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_BSLS));
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
      SEND_STRING(SS_LSFT(SS_TAP(X_1))SS_DELAY(100)  SS_LSFT(SS_TAP(X_SLASH)));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SLASH))SS_DELAY(100)  SS_LSFT(SS_TAP(X_1)));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_8))SS_DELAY(100)  SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(100)  SS_TAP(X_INTERNATIONAL_1));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_C));
        } else {
          unregister_code16(LSFT(KC_C));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_I));
        } else {
          unregister_code16(LSFT(KC_I));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_E));
        } else {
          unregister_code16(LSFT(KC_E));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_A));
        } else {
          unregister_code16(LSFT(KC_A));
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
          register_code16(LSFT(KC_Z));
        } else {
          unregister_code16(LSFT(KC_Z));
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
          register_code16(LSFT(KC_G));
        } else {
          unregister_code16(LSFT(KC_G));
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
          register_code16(LSFT(KC_H));
        } else {
          unregister_code16(LSFT(KC_H));
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
          register_code16(LSFT(KC_T));
        } else {
          unregister_code16(LSFT(KC_T));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_S));
        } else {
          unregister_code16(LSFT(KC_S));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_ALT);
        } else {
          unregister_code16(KC_RIGHT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_N));
        } else {
          unregister_code16(LSFT(KC_N));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_P));
        } else {
          unregister_code16(LSFT(KC_P));
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
          register_code16(LSFT(KC_Q));
        } else {
          unregister_code16(LSFT(KC_Q));
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
    case DUAL_FUNC_13:
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
    case DUAL_FUNC_14:
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
    case DUAL_FUNC_15:
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
    case DUAL_FUNC_16:
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
    case DUAL_FUNC_17:
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
    case DUAL_FUNC_18:
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
    case DUAL_FUNC_19:
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
    case DUAL_FUNC_20:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_Q));
        } else {
          unregister_code16(LCTL(KC_Q));
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
          register_code16(LCTL(KC_W));
        } else {
          unregister_code16(LCTL(KC_W));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_22:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_A));
        } else {
          unregister_code16(LCTL(KC_A));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_23:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_S));
        } else {
          unregister_code16(LCTL(KC_S));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,254);
      }
      return false;
    case HSV_7_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(7,255,254);
      }
      return false;
    case HSV_20_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(20,255,254);
      }
      return false;
    case HSV_40_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(40,255,254);
      }
      return false;
    case HSV_53_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(53,255,254);
      }
      return false;
    case HSV_67_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(67,255,254);
      }
      return false;
    case HSV_1_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(1,255,254);
      }
      return false;
    case HSV_8_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(8,255,254);
      }
      return false;
    case HSV_25_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(25,255,254);
      }
      return false;
    case HSV_45_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(45,255,254);
      }
      return false;
    case HSV_56_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(56,255,254);
      }
      return false;
    case HSV_71_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(71,255,254);
      }
      return false;
    case HSV_3_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(3,255,254);
      }
      return false;
    case HSV_10_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(10,255,254);
      }
      return false;
    case HSV_30_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(30,255,254);
      }
      return false;
    case HSV_48_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(48,255,254);
      }
      return false;
    case HSV_59_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(59,255,254);
      }
      return false;
    case HSV_75_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(75,255,254);
      }
      return false;
    case HSV_5_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(5,255,254);
      }
      return false;
    case HSV_15_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(15,255,254);
      }
      return false;
    case HSV_35_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(35,255,254);
      }
      return false;
    case HSV_50_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(50,255,254);
      }
      return false;
    case HSV_63_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(63,255,254);
      }
      return false;
    case HSV_79_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(79,255,254);
      }
      return false;
    case HSV_83_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(83,255,254);
      }
      return false;
    case HSV_105_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(105,255,254);
      }
      return false;
    case HSV_137_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(137,255,254);
      }
      return false;
    case HSV_172_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,254);
      }
      return false;
    case HSV_200_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(200,255,254);
      }
      return false;
    case HSV_229_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(229,255,254);
      }
      return false;
    case HSV_86_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,254);
      }
      return false;
    case HSV_111_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(111,255,254);
      }
      return false;
    case HSV_146_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(146,255,254);
      }
      return false;
    case HSV_179_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(179,255,254);
      }
      return false;
    case HSV_207_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(207,255,254);
      }
      return false;
    case HSV_236_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(236,255,254);
      }
      return false;
    case HSV_92_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(92,255,254);
      }
      return false;
    case HSV_118_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(118,255,254);
      }
      return false;
    case HSV_154_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(154,255,254);
      }
      return false;
    case HSV_186_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(186,255,254);
      }
      return false;
    case HSV_215_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,254);
      }
      return false;
    case HSV_243_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(243,255,254);
      }
      return false;
    case HSV_98_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(98,255,254);
      }
      return false;
    case HSV_129_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,254);
      }
      return false;
    case HSV_163_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(163,255,254);
      }
      return false;
    case HSV_193_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(193,255,254);
      }
      return false;
    case HSV_222_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(222,255,254);
      }
      return false;
    case HSV_250_255_254:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(250,255,254);
      }
      return false;
    case HSV_172_255_224:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,224);
      }
      return false;
    case HSV_86_10_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,10,255);
      }
      return false;
    case HSV_86_53_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,53,255);
      }
      return false;
    case HSV_86_96_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,96,255);
      }
      return false;
    case HSV_86_138_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,138,255);
      }
      return false;
    case HSV_86_182_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,182,255);
      }
      return false;
    case HSV_86_223_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,223,255);
      }
      return false;
    case HSV_86_21_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,21,255);
      }
      return false;
    case HSV_86_64_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,64,255);
      }
      return false;
    case HSV_86_106_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,106,255);
      }
      return false;
    case HSV_86_150_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,150,255);
      }
      return false;
    case HSV_86_191_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,191,255);
      }
      return false;
    case HSV_86_234_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,234,255);
      }
      return false;
    case HSV_86_32_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,32,255);
      }
      return false;
    case HSV_86_74_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,74,255);
      }
      return false;
    case HSV_86_117_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,117,255);
      }
      return false;
    case HSV_86_159_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,159,255);
      }
      return false;
    case HSV_86_202_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,202,255);
      }
      return false;
    case HSV_86_245_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,245,255);
      }
      return false;
    case HSV_86_44_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,44,255);
      }
      return false;
    case HSV_86_85_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,85,255);
      }
      return false;
    case HSV_86_128_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,128,255);
      }
      return false;
    case HSV_86_170_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,170,255);
      }
      return false;
    case HSV_86_214_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,214,255);
      }
      return false;
    case HSV_86_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,255);
      }
      return false;
    case HSV_0_0_11:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,11);
      }
      return false;
    case HSV_0_0_53:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,53);
      }
      return false;
    case HSV_0_0_96:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,96);
      }
      return false;
    case HSV_0_0_138:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,138);
      }
      return false;
    case HSV_0_0_181:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,181);
      }
      return false;
    case HSV_0_0_223:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,223);
      }
      return false;
    case HSV_0_0_21:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,21);
      }
      return false;
    case HSV_0_0_64:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,64);
      }
      return false;
    case HSV_0_0_106:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,106);
      }
      return false;
    case HSV_0_0_149:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,149);
      }
      return false;
    case HSV_0_0_191:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,191);
      }
      return false;
    case HSV_0_0_234:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,234);
      }
      return false;
    case HSV_0_0_32:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,32);
      }
      return false;
    case HSV_0_0_74:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,74);
      }
      return false;
    case HSV_0_0_117:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,117);
      }
      return false;
    case HSV_0_0_159:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,159);
      }
      return false;
    case HSV_0_0_202:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,202);
      }
      return false;
    case HSV_0_0_244:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,244);
      }
      return false;
    case HSV_0_0_43:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,43);
      }
      return false;
    case HSV_0_0_85:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,85);
      }
      return false;
    case HSV_0_0_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,128);
      }
      return false;
    case HSV_0_0_170:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,170);
      }
      return false;
    case HSV_0_0_213:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,213);
      }
      return false;
    case HSV_0_0_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,255);
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

static tap dance_state[4];

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
        case SINGLE_HOLD: layer_on(6); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: layer_on(16); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(6)) {
            layer_off(6);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(16)) {
                  layer_off(16);
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
        case DOUBLE_HOLD: layer_on(14); break;
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
                if(!is_layer_locked(14)) {
                  layer_off(14);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: layer_on(7); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: layer_on(16); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(7)) {
            layer_off(7);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(16)) {
                  layer_off(16);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_HOLD: layer_on(14); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(5)) {
            layer_off(5);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(14)) {
                  layer_off(14);
                }
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};




//
// additional function
//
// tap flow control
// bool is_flow_tap_key(uint16_t keycode) is default

// disable (return 0)
// thumb space LT 
// pinkey outer col
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (keycode) {
      case LT(4, KC_SPACE):
      case LT(5, KC_SPACE):      
      case LT(6, KC_SPACE):
      case LT(7, KC_SPACE):
        return 0;

      case LT(10, KC_B):
      case LT(11, KC_B):
      case LT(12, KC_V):
      case LT(13, KC_V):
        return 0;

      case MT(MOD_LCTL, KC_Z):
      case MT(MOD_RCTL, KC_Q):
        return 0;
        
      default:
        return FLOW_TAP_TERM;  // Longer timeout otherwise.
    }
  }
  return 0;  // Disable Flow Tap.
}

// LED pattern list, no const limit, terminate symbol
// off -> on -> off ... (off start for no glitch)
// reduce data x16 (4bit shift) 8bit
// 0: terminate, output this area value
// MAX: return to position 0 immediately, this cycle output position 0 value & wait
// other: output current position value & wait
// put reurn token for safety
// max 16x255=4080ms 4sec
// write NULL direct 
static const uint8_t * const led_pattern_on = (uint8_t[]){1, 0, UINT8_MAX, UINT8_MAX, UINT8_MAX};
static const uint8_t * const led_pattern_blink = (uint8_t[]){13, 50, UINT8_MAX, UINT8_MAX, UINT8_MAX};
static const uint8_t * const led_pattern_oneshot = (uint8_t[]){13, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 3, 20, 0, UINT8_MAX, UINT8_MAX, UINT8_MAX};
//static const uint8_t * const led_pattern_heartbeat = (uint8_t[]){250, 125, UINT8_MAX, UINT8_MAX, UINT8_MAX};

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
static bool status_led(uint8_t mask, const uint8_t * const pattern, uint16_t init_delay_ms) {
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

// access to system-side flag
extern keyboard_config_t keyboard_config;
extern bool is_launching;

// if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
layer_state_t layer_state_set_user(layer_state_t state) {
  if (is_launching || !keyboard_config.led_level) return state;

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
    // Base (ANSI)
    case 0:
    // Base (JIS)
    case 1:
      status_led(0b1111, NULL, 0);
      break;
    // Shift
    case 2:
    case 3:
      status_led(0b0011, NULL, 0);
      status_led(0b1100, led_pattern_on, 0);
      break;
    // Num
    case 4:
    case 5:
      status_led(0b1100, NULL, 0);
      status_led(0b0010, led_pattern_on, 0);
      status_led(0b0001, led_pattern_blink, 0);
      break;
    // Bkt
    case 6:
    case 7:
      status_led(0b1100, NULL, 0);
      status_led(0b0001, led_pattern_on, 0);
      status_led(0b0010, led_pattern_blink, 0);
      break;
    // Fn
    case 8:
    case 9:
      status_led(0b1100, NULL, 0);
      status_led(0b0011, led_pattern_on, 0);
      break;
    // Lcur
    case 10:
    case 11:
      status_led(0b0110, NULL, 0);
      status_led(0b1000, led_pattern_on, 0);
      status_led(0b0001, led_pattern_blink, 0);
      break;
    // Rcur
    case 12:
    case 13:
      status_led(0b1001, NULL, 0);
      status_led(0b0100, led_pattern_on, 0);
      status_led(0b0010, led_pattern_blink, 0);
      break;
    case 14:
      status_led(0b0100, led_pattern_on, 50);
      status_led(0b0001, led_pattern_on, 300);
      status_led(0b1000, led_pattern_on, 550);
      status_led(0b0010, led_pattern_on, 800);  
    case 15:
      status_led(0b1000, led_pattern_on, 50);
      status_led(0b0010, led_pattern_on, 300);
      status_led(0b0100, led_pattern_on, 550);
      status_led(0b0001, led_pattern_on, 800);
      break;    
    case 16:
      status_led(0b1111, NULL, 0);
      
      os_variant_t host = detected_host_os();
      if (host == OS_WINDOWS) {
        status_led(0b0001, led_pattern_on, 0);
      } else if (host == OS_IOS) {
        status_led(0b0100, led_pattern_on, 0);
        status_led(0b0001, led_pattern_blink, 0);
      } else if (host == OS_LINUX) {
        status_led(0b0001, led_pattern_on, 0);
        status_led(0b0100, led_pattern_blink, 0);
      } else if (host == OS_MACOS) {
        status_led(0b0100, led_pattern_on, 0);
      } else if (host == OS_UNSURE) {
        status_led(0b0101, NULL, 0);
      } else {
        status_led(0b0101, led_pattern_oneshot, 0);
      }
      
      if (layer_state_cmp(state, 1)) {
        //JIS base enable
        status_led(0b0010, led_pattern_on, 0);
      } else {
        //other
        status_led(0b1000, led_pattern_on, 0);
      }
      break;
    default :
      status_led(0b1111, NULL, 0);
      break;
  }
  return state;
}

// HSV independent update code
// impl...
// copy from qmk code
typedef union {
    uint64_t raw;
    struct {
        bool    enable : 1;
        bool    velocikey : 1;
        uint8_t mode : 6;
        uint8_t hue : 8;
        uint8_t sat : 8;
        uint8_t val : 8;
        uint8_t speed : 8;
    };
} rgblight_config_t;
void rgblight_sethsv_eeprom_helper(uint8_t hue, uint8_t sat, uint8_t val, bool write_to_eeprom);
extern rgblight_config_t rgblight_config;

void rgblight_sethsv_h_only(uint8_t hue, uint8_t sat, uint8_t val) {
  uint8_t sat_old = rgblight_config.sat;
  uint8_t val_old = rgblight_config.val;
  rgblight_sethsv_eeprom_helper(hue, sat_old, val_old, false);
}

void rgblight_sethsv_s_only(uint8_t hue, uint8_t sat, uint8_t val) {
  uint8_t hue_old = rgblight_config.hue;
  uint8_t val_old = rgblight_config.val;
  rgblight_sethsv_eeprom_helper(hue_old, sat, val_old, false);
}

void rgblight_sethsv_v_only(uint8_t hue, uint8_t sat, uint8_t val) {
  uint8_t hue_old = rgblight_config.hue;
  uint8_t sat_old = rgblight_config.sat;
  rgblight_sethsv_eeprom_helper(hue_old, sat_old, val, true);
}

