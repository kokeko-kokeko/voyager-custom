#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_112,
  HSV_10_255_112,
  HSV_32_255_112,
  HSV_43_255_112,
  HSV_53_255_112,
  HSV_75_255_112,
  HSV_16_255_112,
  HSV_36_255_112,
  HSV_59_255_112,
  HSV_79_255_112,
  HSV_3_255_112,
  HSV_21_255_112,
  HSV_39_255_112,
  HSV_46_255_112,
  HSV_64_255_112,
  HSV_82_255_112,
  HSV_6_255_112,
  HSV_26_255_112,
  HSV_42_255_112,
  HSV_49_255_112,
  HSV_69_255_112,
  HSV_85_255_112,
  HSV_0_0_112,
  HSV_0_255_255,
  HSV_86_255_112,
  HSV_118_255_112,
  HSV_139_255_112,
  HSV_172_255_112,
  HSV_204_255_112,
  HSV_225_255_112,
  HSV_89_255_112,
  HSV_125_255_112,
  HSV_150_255_112,
  HSV_175_255_112,
  HSV_211_255_112,
  HSV_236_255_112,
  HSV_96_255_112,
  HSV_129_255_112,
  HSV_161_255_112,
  HSV_182_255_112,
  HSV_215_255_112,
  HSV_247_255_112,
  HSV_107_255_112,
  HSV_132_255_112,
  HSV_168_255_112,
  HSV_193_255_112,
  HSV_218_255_112,
  HSV_254_255_112,
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
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  DANCE_19,
  DANCE_20,
  DANCE_21,
  DANCE_22,
  DANCE_23,
  DANCE_24,
  DANCE_25,
  DANCE_26,
  DANCE_27,
  DANCE_28,
  DANCE_29,
  DANCE_30,
  DANCE_31,
  DANCE_32,
  DANCE_33,
  DANCE_34,
  DANCE_35,
  DANCE_36,
  DANCE_37,
  DANCE_38,
  DANCE_39,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_AT,          KC_HASH,        KC_Y,           KC_O,           KC_U,           KC_QUOTE,                                       KC_DQUO,        KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    LT(10, KC_B),   MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),LT(2, KC_E),    MT(MOD_LCTL, KC_A),ALL_T(KC_COMMA),                                MEH_T(KC_DOT),  MT(MOD_RCTL, KC_H),LT(2, KC_T),    MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(12, KC_V),   
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           KC_MINUS,                                       KC_QUES,        KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(4, KC_SPACE),KC_LANGUAGE_2,                                  LT(6, KC_LANGUAGE_1),LT(8, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(6, KC_TAB),  TD(DANCE_0),                                    TD(DANCE_1),    KC_ENTER
  ),
  [1] = LAYOUT_voyager(
    JP_AT,          KC_HASH,        KC_Y,           KC_O,           KC_U,           KC_AMPR,                                        KC_AT,          KC_L,           KC_D,           KC_W,           KC_SLASH,       CW_TOGG,        
    LT(11, KC_B),   MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),LT(3, KC_E),    MT(MOD_LCTL, KC_A),ALL_T(KC_COMMA),                                MEH_T(KC_DOT),  MT(MOD_RCTL, KC_H),LT(3, KC_T),    MT(MOD_RALT, KC_S),MT(MOD_RGUI, KC_N),LT(13, KC_V),   
    MT(MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_G),KC_X,           KC_J,           KC_K,           KC_MINUS,                                       KC_QUES,        KC_R,           KC_M,           KC_F,           MT(MOD_RCTL, KC_P),MT(MOD_RCTL, KC_Q),
    KC_LEFT_SHIFT,  KC_LEFT,        KC_RIGHT,       KC_BSPC,        LT(5, KC_SPACE),KC_LANGUAGE_2,                                  LT(7, KC_LANGUAGE_1),LT(9, KC_SPACE),KC_DELETE,      KC_UP,          KC_DOWN,        KC_RIGHT_SHIFT, 
                                                    LT(7, KC_TAB),  TD(DANCE_2),                                    TD(DANCE_3),    KC_ENTER
  ),
  [2] = LAYOUT_voyager(
    KC_GRAVE,       KC_DLR,         LSFT(KC_Y),     LSFT(KC_O),     LSFT(KC_U),     KC_LPRN,                                        KC_RPRN,        LSFT(KC_L),     LSFT(KC_D),     LSFT(KC_W),     KC_BSLS,        KC_TRANSPARENT, 
    LSFT(KC_B),     TD(DANCE_4),    TD(DANCE_5),    LSFT(KC_E),     TD(DANCE_6),    KC_SCLN,                                        KC_COLN,        TD(DANCE_9),    LSFT(KC_T),     TD(DANCE_10),   TD(DANCE_11),   LSFT(KC_V),     
    TD(DANCE_7),    TD(DANCE_8),    LSFT(KC_X),     LSFT(KC_J),     LSFT(KC_K),     KC_UNDS,                                        KC_EXLM,        LSFT(KC_R),     LSFT(KC_M),     LSFT(KC_F),     TD(DANCE_12),   TD(DANCE_13),   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, LSFT(KC_SPACE), KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  LSFT(KC_SPACE), KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    LSFT(KC_TAB),   LSFT(KC_ESCAPE),                                LSFT(KC_BSPC),  LSFT(KC_ENTER)
  ),
  [3] = LAYOUT_voyager(
    KC_LCBR,        KC_DLR,         LSFT(KC_Y),     LSFT(KC_O),     LSFT(KC_U),     KC_ASTR,                                        KC_LPRN,        LSFT(KC_L),     LSFT(KC_D),     LSFT(KC_W),     KC_INTERNATIONAL_1,KC_TRANSPARENT, 
    LSFT(KC_B),     TD(DANCE_14),   TD(DANCE_15),   LSFT(KC_E),     TD(DANCE_16),   KC_SCLN,                                        KC_QUOTE,       TD(DANCE_19),   LSFT(KC_T),     TD(DANCE_20),   TD(DANCE_21),   LSFT(KC_V),     
    TD(DANCE_17),   TD(DANCE_18),   LSFT(KC_X),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_INTERNATIONAL_1),                                KC_EXLM,        LSFT(KC_R),     LSFT(KC_M),     LSFT(KC_F),     TD(DANCE_22),   TD(DANCE_23),   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, LSFT(KC_SPACE), KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  LSFT(KC_SPACE), KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    LSFT(KC_TAB),   LSFT(KC_ESCAPE),                                LSFT(KC_BSPC),  LSFT(KC_ENTER)
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_AT,          KC_GRAVE,       KC_HASH,        KC_DLR,         KC_TRANSPARENT, 
    KC_LBRC,        MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),KC_3,           MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),KC_8,           MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),KC_RBRC,        
    TD(DANCE_24),   TD(DANCE_25),   KC_EQUAL,       KC_TILD,        KC_PLUS,        KC_LABK,                                        KC_RABK,        KC_CIRC,        KC_AMPR,        KC_PERC,        TD(DANCE_26),   TD(DANCE_27),   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_6,           KC_RABK,                                        KC_5,           KC_LBRC,        KC_GRAVE,       KC_HASH,        KC_DLR,         KC_TRANSPARENT, 
    KC_RBRC,        MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),KC_3,           MT(MOD_LCTL, KC_4),KC_5,                                           KC_6,           MT(MOD_RCTL, KC_7),KC_8,           MT(MOD_RALT, KC_9),MT(MOD_RGUI, KC_0),KC_BSLS,        
    TD(DANCE_28),   TD(DANCE_29),   KC_UNDS,        KC_PLUS,        KC_COLN,        KC_LABK,                                        KC_RABK,        KC_EQUAL,       KC_CIRC,        KC_PERC,        TD(DANCE_30),   TD(DANCE_31),   
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F21,         KC_F22,         KC_F23,         KC_F24,         LCTL(KC_RBRC),                                  LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),KC_TRANSPARENT, 
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F21,         KC_F22,         KC_F23,         KC_F24,         LCTL(KC_RBRC),                                  LGUI(LSFT(KC_S)),LGUI(LSFT(KC_R)),LGUI(KC_PSCR),  LALT(KC_PSCR),  KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_F1),MT(MOD_LALT, KC_F2),MT(MOD_LSFT, KC_F3),MT(MOD_LCTL, KC_F4),KC_F5,                                          KC_F6,          MT(MOD_RCTL, KC_F7),MT(MOD_RSFT, KC_F8),MT(MOD_RALT, KC_F9),MT(MOD_RGUI, KC_F10),KC_TRANSPARENT, 
    KC_LEFT_CTRL,   MT(MOD_LCTL, KC_F11),KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         MT(MOD_RCTL, KC_F20),KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,                                     ST_MACRO_7,     KC_LBRC,        KC_LCBR,        KC_LABK,        KC_LPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_4,     ST_MACRO_5,     KC_AT,          KC_HASH,        KC_SLASH,                                       KC_BSLS,        ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    
    KC_LEFT_CTRL,   KC_EXLM,        KC_QUES,        KC_GRAVE,       KC_DLR,         ST_MACRO_6,                                     ST_MACRO_13,    KC_RBRC,        KC_RCBR,        KC_RABK,        KC_RPRN,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,                                    ST_MACRO_21,    KC_RBRC,        KC_RCBR,        KC_LABK,        KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_18,    ST_MACRO_19,    KC_LBRC,        KC_HASH,        KC_SLASH,                                       KC_INTERNATIONAL_1,ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,    
    KC_LEFT_CTRL,   KC_EXLM,        KC_QUES,        KC_LCBR,        KC_DLR,         ST_MACRO_20,                                    ST_MACRO_27,    KC_BSLS,        KC_PIPE,        KC_RABK,        KC_LPRN,        KC_RIGHT_CTRL,  
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT, 
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, TD(DANCE_32),   TD(DANCE_33),   KC_PAGE_UP,     KC_PGDN,        LGUI(LCTL(KC_V)),                                KC_TAB,         RCTL(KC_LEFT),  KC_UP,          RCTL(KC_RIGHT), KC_ESCAPE,      KC_APPLICATION, 
    KC_TRANSPARENT, TD(DANCE_34),   TD(DANCE_35),   LCTL(KC_C),     LCTL(KC_V),     LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_28,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [11] = LAYOUT_voyager(
    KC_TRANSPARENT, TD(DANCE_36),   TD(DANCE_37),   KC_PAGE_UP,     KC_PGDN,        LGUI(LCTL(KC_V)),                                KC_TAB,         RCTL(KC_LEFT),  KC_UP,          RCTL(KC_RIGHT), KC_ESCAPE,      KC_APPLICATION, 
    KC_TRANSPARENT, TD(DANCE_38),   TD(DANCE_39),   LCTL(KC_C),     LCTL(KC_V),     LGUI(KC_V),                                     KC_BSPC,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT, 
    LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_HOME,        KC_END,         LGUI(LSFT(KC_V)),                                LGUI(LCTL(KC_T)),LCTL(LSFT(KC_P)),LALT(LGUI(KC_SPACE)),LGUI(LSFT(KC_M)),LGUI(LSFT(KC_C)),ST_MACRO_29,    
    QK_LLCK,        RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [12] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [13] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_LLCK,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_SPACE,       KC_LANGUAGE_1,                                  KC_LANGUAGE_2,  KC_SPACE,       KC_TRANSPARENT, RGB_TOG,        RGB_MODE_FORWARD,QK_LLCK,        
                                                    KC_TAB,         KC_ESCAPE,                                      KC_BSPC,        KC_ENTER
  ),
  [14] = LAYOUT_voyager(
    HSV_0_255_112,  HSV_10_255_112, HSV_32_255_112, HSV_43_255_112, HSV_53_255_112, HSV_75_255_112,                                 HSV_86_255_112, HSV_118_255_112,HSV_139_255_112,HSV_172_255_112,HSV_204_255_112,HSV_225_255_112,
    HSV_0_255_112,  HSV_16_255_112, HSV_36_255_112, HSV_43_255_112, HSV_59_255_112, HSV_79_255_112,                                 HSV_89_255_112, HSV_125_255_112,HSV_150_255_112,HSV_175_255_112,HSV_211_255_112,HSV_236_255_112,
    HSV_3_255_112,  HSV_21_255_112, HSV_39_255_112, HSV_46_255_112, HSV_64_255_112, HSV_82_255_112,                                 HSV_96_255_112, HSV_129_255_112,HSV_161_255_112,HSV_182_255_112,HSV_215_255_112,HSV_247_255_112,
    HSV_6_255_112,  HSV_26_255_112, HSV_42_255_112, HSV_49_255_112, HSV_69_255_112, HSV_85_255_112,                                 HSV_107_255_112,HSV_132_255_112,HSV_168_255_112,HSV_193_255_112,HSV_218_255_112,HSV_254_255_112,
                                                    HSV_0_0_112,    HSV_0_255_255,                                  KC_NO,          KC_NO
  ),
  [15] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_NO,          KC_NO,          LED_LEVEL,      
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(1),          TO(0),                                          KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_NO,          KC_NO,          KC_NO,          TOGGLE_LAYER_COLOR,
    QK_BOOT,        EE_CLR,         KC_NO,          QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,                                KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_NO,          RGB_SPD,        RGB_SPI,        RGB_SLD,        
                                                    LGUI(LSFT(KC_SLASH)),KC_NO,                                          RALT(RCTL(KC_DELETE)),RGUI(KC_L)
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [14] = { {0,255,255}, {10,255,255}, {32,255,255}, {43,255,255}, {53,255,255}, {75,255,255}, {0,255,255}, {16,255,255}, {36,255,255}, {43,255,255}, {59,255,255}, {79,255,255}, {2,255,255}, {21,255,255}, {40,255,255}, {45,255,255}, {64,255,255}, {83,255,255}, {6,255,255}, {26,255,255}, {42,255,255}, {49,255,255}, {69,255,255}, {85,255,255}, {0,0,255}, {0,255,255}, {86,255,255}, {118,255,255}, {139,255,255}, {172,255,255}, {204,255,255}, {225,255,255}, {88,255,255}, {126,255,255}, {150,255,255}, {174,255,255}, {212,255,255}, {236,255,255}, {96,255,255}, {129,255,255}, {161,255,255}, {182,255,255}, {215,255,255}, {247,255,255}, {107,255,255}, {131,255,255}, {169,255,255}, {193,255,255}, {217,255,255}, {255,255,255}, {0,0,0}, {0,0,0} },

    [15] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {21,255,255}, {0,0,0}, {172,255,255}, {215,255,128}, {215,255,255}, {86,255,255}, {0,0,0}, {21,255,128}, {21,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {86,255,128}, {86,255,255}, {43,255,128}, {43,255,255}, {0,0,0}, {0,0,0}, {129,255,128}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {172,255,255}, {0,0,0}, {0,0,128}, {0,0,255}, {0,255,255}, {0,255,255}, {172,255,255} },

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
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_LEFT));
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
      SEND_STRING(SS_RSFT(SS_TAP(X_8))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_RSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_RSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_9))SS_DELAY(100)  SS_RSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
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
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_RSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_COMMA))SS_DELAY(100)  SS_RSFT(SS_TAP(X_DOT))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_8))SS_DELAY(100)  SS_RSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
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

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,112);
      }
      return false;
    case HSV_10_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(10,255,112);
      }
      return false;
    case HSV_32_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(32,255,112);
      }
      return false;
    case HSV_43_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,112);
      }
      return false;
    case HSV_53_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(53,255,112);
      }
      return false;
    case HSV_75_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(75,255,112);
      }
      return false;
    case HSV_16_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(16,255,112);
      }
      return false;
    case HSV_36_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(36,255,112);
      }
      return false;
    case HSV_59_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(59,255,112);
      }
      return false;
    case HSV_79_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(79,255,112);
      }
      return false;
    case HSV_3_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(3,255,112);
      }
      return false;
    case HSV_21_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(21,255,112);
      }
      return false;
    case HSV_39_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(39,255,112);
      }
      return false;
    case HSV_46_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(46,255,112);
      }
      return false;
    case HSV_64_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(64,255,112);
      }
      return false;
    case HSV_82_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(82,255,112);
      }
      return false;
    case HSV_6_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(6,255,112);
      }
      return false;
    case HSV_26_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(26,255,112);
      }
      return false;
    case HSV_42_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(42,255,112);
      }
      return false;
    case HSV_49_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(49,255,112);
      }
      return false;
    case HSV_69_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(69,255,112);
      }
      return false;
    case HSV_85_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(85,255,112);
      }
      return false;
    case HSV_0_0_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,112);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,112);
      }
      return false;
    case HSV_118_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(118,255,112);
      }
      return false;
    case HSV_139_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(139,255,112);
      }
      return false;
    case HSV_172_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,112);
      }
      return false;
    case HSV_204_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(204,255,112);
      }
      return false;
    case HSV_225_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(225,255,112);
      }
      return false;
    case HSV_89_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(89,255,112);
      }
      return false;
    case HSV_125_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(125,255,112);
      }
      return false;
    case HSV_150_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(150,255,112);
      }
      return false;
    case HSV_175_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(175,255,112);
      }
      return false;
    case HSV_211_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(211,255,112);
      }
      return false;
    case HSV_236_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(236,255,112);
      }
      return false;
    case HSV_96_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(96,255,112);
      }
      return false;
    case HSV_129_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,255,112);
      }
      return false;
    case HSV_161_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(161,255,112);
      }
      return false;
    case HSV_182_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(182,255,112);
      }
      return false;
    case HSV_215_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,112);
      }
      return false;
    case HSV_247_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(247,255,112);
      }
      return false;
    case HSV_107_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(107,255,112);
      }
      return false;
    case HSV_132_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(132,255,112);
      }
      return false;
    case HSV_168_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(168,255,112);
      }
      return false;
    case HSV_193_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(193,255,112);
      }
      return false;
    case HSV_218_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(218,255,112);
      }
      return false;
    case HSV_254_255_112:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(254,255,112);
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

static tap dance_state[40];

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
        case SINGLE_HOLD: layer_on(8); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: layer_on(15); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(8)) {
            layer_off(8);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(15)) {
                  layer_off(15);
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
        case SINGLE_HOLD: layer_on(9); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: layer_on(15); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(9)) {
            layer_off(9);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
              case DOUBLE_HOLD: 
                if(!is_layer_locked(15)) {
                  layer_off(15);
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
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_C));
        tap_code16(LSFT(KC_C));
        tap_code16(LSFT(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_C));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_C)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_C)); register_code16(LSFT(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_C)); register_code16(LSFT(KC_C));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_C)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_I));
        tap_code16(LSFT(KC_I));
        tap_code16(LSFT(KC_I));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_I));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_I)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_I)); register_code16(LSFT(KC_I)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_I)); register_code16(LSFT(KC_I));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_I)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_I)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_I)); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_A));
        tap_code16(LSFT(KC_A));
        tap_code16(LSFT(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_A));
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_A)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_A)); register_code16(LSFT(KC_A)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_A)); register_code16(LSFT(KC_A));
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_A)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_A)); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_Z));
        tap_code16(LSFT(KC_Z));
        tap_code16(LSFT(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_Z));
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_Z)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_Z)); register_code16(LSFT(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_Z)); register_code16(LSFT(KC_Z));
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_Z)); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_G));
        tap_code16(LSFT(KC_G));
        tap_code16(LSFT(KC_G));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_G));
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_G)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_G)); register_code16(LSFT(KC_G)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_G)); register_code16(LSFT(KC_G));
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_G)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_G)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_G)); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_H));
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_H)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_H)); register_code16(LSFT(KC_H)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_H)); register_code16(LSFT(KC_H));
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_H)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_S));
        tap_code16(LSFT(KC_S));
        tap_code16(LSFT(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_S));
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_S)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_S)); register_code16(LSFT(KC_S)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_S)); register_code16(LSFT(KC_S));
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_S)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_S)); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_N));
        tap_code16(LSFT(KC_N));
        tap_code16(LSFT(KC_N));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_N));
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_N)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_N)); register_code16(LSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_N)); register_code16(LSFT(KC_N));
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_N)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_N)); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_P));
        tap_code16(LSFT(KC_P));
        tap_code16(LSFT(KC_P));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_P));
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_P)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_P)); register_code16(LSFT(KC_P)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_P)); register_code16(LSFT(KC_P));
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_P)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_P)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_P)); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_Q));
        tap_code16(LSFT(KC_Q));
        tap_code16(LSFT(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_Q));
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_Q)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_Q)); register_code16(LSFT(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_Q)); register_code16(LSFT(KC_Q));
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_Q)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_Q)); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_C));
        tap_code16(LSFT(KC_C));
        tap_code16(LSFT(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_C));
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_C)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_C)); register_code16(LSFT(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_C)); register_code16(LSFT(KC_C));
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_C)); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_I));
        tap_code16(LSFT(KC_I));
        tap_code16(LSFT(KC_I));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_I));
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_I)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_I)); register_code16(LSFT(KC_I)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_I)); register_code16(LSFT(KC_I));
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_I)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_I)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_I)); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_A));
        tap_code16(LSFT(KC_A));
        tap_code16(LSFT(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_A));
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_A)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_A)); register_code16(LSFT(KC_A)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_A)); register_code16(LSFT(KC_A));
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_A)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_A)); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_Z));
        tap_code16(LSFT(KC_Z));
        tap_code16(LSFT(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_Z));
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_Z)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_Z)); register_code16(LSFT(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_Z)); register_code16(LSFT(KC_Z));
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_Z)); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_G));
        tap_code16(LSFT(KC_G));
        tap_code16(LSFT(KC_G));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_G));
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_G)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_G)); register_code16(LSFT(KC_G)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_G)); register_code16(LSFT(KC_G));
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_G)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_G)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_G)); break;
    }
    dance_state[18].step = 0;
}
void on_dance_19(tap_dance_state_t *state, void *user_data);
void dance_19_finished(tap_dance_state_t *state, void *user_data);
void dance_19_reset(tap_dance_state_t *state, void *user_data);

void on_dance_19(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_H));
    }
}

void dance_19_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_H)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_H)); register_code16(LSFT(KC_H)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_H)); register_code16(LSFT(KC_H));
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_H)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(tap_dance_state_t *state, void *user_data);
void dance_20_finished(tap_dance_state_t *state, void *user_data);
void dance_20_reset(tap_dance_state_t *state, void *user_data);

void on_dance_20(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_S));
        tap_code16(LSFT(KC_S));
        tap_code16(LSFT(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_S));
    }
}

void dance_20_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_S)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_S)); register_code16(LSFT(KC_S)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_S)); register_code16(LSFT(KC_S));
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_S)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_S)); break;
    }
    dance_state[20].step = 0;
}
void on_dance_21(tap_dance_state_t *state, void *user_data);
void dance_21_finished(tap_dance_state_t *state, void *user_data);
void dance_21_reset(tap_dance_state_t *state, void *user_data);

void on_dance_21(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_N));
        tap_code16(LSFT(KC_N));
        tap_code16(LSFT(KC_N));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_N));
    }
}

void dance_21_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_N)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_N)); register_code16(LSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_N)); register_code16(LSFT(KC_N));
    }
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_N)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_N)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_N)); break;
    }
    dance_state[21].step = 0;
}
void on_dance_22(tap_dance_state_t *state, void *user_data);
void dance_22_finished(tap_dance_state_t *state, void *user_data);
void dance_22_reset(tap_dance_state_t *state, void *user_data);

void on_dance_22(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_P));
        tap_code16(LSFT(KC_P));
        tap_code16(LSFT(KC_P));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_P));
    }
}

void dance_22_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_P)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_P)); register_code16(LSFT(KC_P)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_P)); register_code16(LSFT(KC_P));
    }
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_P)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_P)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_P)); break;
    }
    dance_state[22].step = 0;
}
void on_dance_23(tap_dance_state_t *state, void *user_data);
void dance_23_finished(tap_dance_state_t *state, void *user_data);
void dance_23_reset(tap_dance_state_t *state, void *user_data);

void on_dance_23(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_Q));
        tap_code16(LSFT(KC_Q));
        tap_code16(LSFT(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_Q));
    }
}

void dance_23_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_Q)); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_Q)); register_code16(LSFT(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_Q)); register_code16(LSFT(KC_Q));
    }
}

void dance_23_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_Q)); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_Q)); break;
    }
    dance_state[23].step = 0;
}
void on_dance_24(tap_dance_state_t *state, void *user_data);
void dance_24_finished(tap_dance_state_t *state, void *user_data);
void dance_24_reset(tap_dance_state_t *state, void *user_data);

void on_dance_24(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_24_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_24_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[24].step = 0;
}
void on_dance_25(tap_dance_state_t *state, void *user_data);
void dance_25_finished(tap_dance_state_t *state, void *user_data);
void dance_25_reset(tap_dance_state_t *state, void *user_data);

void on_dance_25(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if(state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

void dance_25_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_PIPE); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    }
}

void dance_25_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    }
    dance_state[25].step = 0;
}
void on_dance_26(tap_dance_state_t *state, void *user_data);
void dance_26_finished(tap_dance_state_t *state, void *user_data);
void dance_26_reset(tap_dance_state_t *state, void *user_data);

void on_dance_26(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
    }
    if(state->count > 3) {
        tap_code16(KC_ASTR);
    }
}

void dance_26_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(KC_ASTR); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_ASTR); register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ASTR); register_code16(KC_ASTR);
    }
}

void dance_26_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(KC_ASTR); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ASTR); break;
    }
    dance_state[26].step = 0;
}
void on_dance_27(tap_dance_state_t *state, void *user_data);
void dance_27_finished(tap_dance_state_t *state, void *user_data);
void dance_27_reset(tap_dance_state_t *state, void *user_data);

void on_dance_27(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

void dance_27_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_27_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state[27].step = 0;
}
void on_dance_28(tap_dance_state_t *state, void *user_data);
void dance_28_finished(tap_dance_state_t *state, void *user_data);
void dance_28_reset(tap_dance_state_t *state, void *user_data);

void on_dance_28(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

void dance_28_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_28_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state[28].step = 0;
}
void on_dance_29(tap_dance_state_t *state, void *user_data);
void dance_29_finished(tap_dance_state_t *state, void *user_data);
void dance_29_reset(tap_dance_state_t *state, void *user_data);

void on_dance_29(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_INTERNATIONAL_3));
        tap_code16(LSFT(KC_INTERNATIONAL_3));
        tap_code16(LSFT(KC_INTERNATIONAL_3));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_INTERNATIONAL_3));
    }
}

void dance_29_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_INTERNATIONAL_3)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_INTERNATIONAL_3)); register_code16(LSFT(KC_INTERNATIONAL_3)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_INTERNATIONAL_3)); register_code16(LSFT(KC_INTERNATIONAL_3));
    }
}

void dance_29_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_INTERNATIONAL_3)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_INTERNATIONAL_3)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_INTERNATIONAL_3)); break;
    }
    dance_state[29].step = 0;
}
void on_dance_30(tap_dance_state_t *state, void *user_data);
void dance_30_finished(tap_dance_state_t *state, void *user_data);
void dance_30_reset(tap_dance_state_t *state, void *user_data);

void on_dance_30(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void dance_30_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void dance_30_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[30].step = 0;
}
void on_dance_31(tap_dance_state_t *state, void *user_data);
void dance_31_finished(tap_dance_state_t *state, void *user_data);
void dance_31_reset(tap_dance_state_t *state, void *user_data);

void on_dance_31(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if(state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

void dance_31_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(KC_PIPE); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    }
}

void dance_31_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    }
    dance_state[31].step = 0;
}
void on_dance_32(tap_dance_state_t *state, void *user_data);
void dance_32_finished(tap_dance_state_t *state, void *user_data);
void dance_32_reset(tap_dance_state_t *state, void *user_data);

void on_dance_32(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Q));
        tap_code16(LCTL(KC_Q));
        tap_code16(LCTL(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Q));
    }
}

void dance_32_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Q)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Q)); register_code16(LCTL(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Q)); register_code16(LCTL(KC_Q));
    }
}

void dance_32_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Q)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Q)); break;
    }
    dance_state[32].step = 0;
}
void on_dance_33(tap_dance_state_t *state, void *user_data);
void dance_33_finished(tap_dance_state_t *state, void *user_data);
void dance_33_reset(tap_dance_state_t *state, void *user_data);

void on_dance_33(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_W));
        tap_code16(LCTL(KC_W));
        tap_code16(LCTL(KC_W));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_W));
    }
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_W)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_W)); register_code16(LCTL(KC_W)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_W)); register_code16(LCTL(KC_W));
    }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_W)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_W)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_W)); break;
    }
    dance_state[33].step = 0;
}
void on_dance_34(tap_dance_state_t *state, void *user_data);
void dance_34_finished(tap_dance_state_t *state, void *user_data);
void dance_34_reset(tap_dance_state_t *state, void *user_data);

void on_dance_34(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_A));
    }
}

void dance_34_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_A)); register_code16(LCTL(KC_A)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_A)); register_code16(LCTL(KC_A));
    }
}

void dance_34_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
    }
    dance_state[34].step = 0;
}
void on_dance_35(tap_dance_state_t *state, void *user_data);
void dance_35_finished(tap_dance_state_t *state, void *user_data);
void dance_35_reset(tap_dance_state_t *state, void *user_data);

void on_dance_35(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_S));
    }
}

void dance_35_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_S)); register_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_S)); register_code16(LCTL(KC_S));
    }
}

void dance_35_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
    }
    dance_state[35].step = 0;
}
void on_dance_36(tap_dance_state_t *state, void *user_data);
void dance_36_finished(tap_dance_state_t *state, void *user_data);
void dance_36_reset(tap_dance_state_t *state, void *user_data);

void on_dance_36(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Q));
        tap_code16(LCTL(KC_Q));
        tap_code16(LCTL(KC_Q));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Q));
    }
}

void dance_36_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Q)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Q)); register_code16(LCTL(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Q)); register_code16(LCTL(KC_Q));
    }
}

void dance_36_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Q)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Q)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Q)); break;
    }
    dance_state[36].step = 0;
}
void on_dance_37(tap_dance_state_t *state, void *user_data);
void dance_37_finished(tap_dance_state_t *state, void *user_data);
void dance_37_reset(tap_dance_state_t *state, void *user_data);

void on_dance_37(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_W));
        tap_code16(LCTL(KC_W));
        tap_code16(LCTL(KC_W));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_W));
    }
}

void dance_37_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_W)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_W)); register_code16(LCTL(KC_W)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_W)); register_code16(LCTL(KC_W));
    }
}

void dance_37_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_W)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_W)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_W)); break;
    }
    dance_state[37].step = 0;
}
void on_dance_38(tap_dance_state_t *state, void *user_data);
void dance_38_finished(tap_dance_state_t *state, void *user_data);
void dance_38_reset(tap_dance_state_t *state, void *user_data);

void on_dance_38(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_A));
    }
}

void dance_38_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_A)); register_code16(LCTL(KC_A)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_A)); register_code16(LCTL(KC_A));
    }
}

void dance_38_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
    }
    dance_state[38].step = 0;
}
void on_dance_39(tap_dance_state_t *state, void *user_data);
void dance_39_finished(tap_dance_state_t *state, void *user_data);
void dance_39_reset(tap_dance_state_t *state, void *user_data);

void on_dance_39(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_S));
    }
}

void dance_39_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[39].step = dance_step(state);
    switch (dance_state[39].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_S)); register_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_S)); register_code16(LCTL(KC_S));
    }
}

void dance_39_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[39].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
    }
    dance_state[39].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
        [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
        [DANCE_21] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
        [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
        [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
        [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
        [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
        [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
        [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
        [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
        [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
        [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
};




//
// additional
//
// LED control
// 1 -> Red Left
// 3 -> Red Right
// 2 -> Green Left
// 4 -> Green Right
// if define VOYAGER_USER_LEDS keyboard_config.led_level is not update
layer_state_t layer_state_set_user(layer_state_t state) {
  //if (!keyboard_config.led_level) return state;
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
    // Base
    case 0:
      STATUS_LED_1(0);
      STATUS_LED_3(1);
      STATUS_LED_2(0);
      STATUS_LED_4(0);
      break;
    case 1:
      STATUS_LED_1(1);
      STATUS_LED_3(0);
      STATUS_LED_2(0);
      STATUS_LED_4(0);
      break;
    // Shift
    case 2:
    case 3:
      STATUS_LED_1(1);
      STATUS_LED_3(1);
      STATUS_LED_2(0);
      STATUS_LED_4(0);
      break;
    // Num
    case 4:
    case 5:
      STATUS_LED_1(0);
      STATUS_LED_3(0);
      STATUS_LED_2(1);
      STATUS_LED_4(0);
      break;
    // Fn
    case 6:
    case 7:
      STATUS_LED_1(0);
      STATUS_LED_3(0);
      STATUS_LED_2(1);
      STATUS_LED_4(1);
      break;
    // Bkt
    case 8:
    case 9:
      STATUS_LED_1(0);
      STATUS_LED_3(0);
      STATUS_LED_2(0);
      STATUS_LED_4(1);
      break;
    // Lcur
    case 10:
    case 11:
      STATUS_LED_1(1);
      STATUS_LED_3(1);
      STATUS_LED_2(1);
      STATUS_LED_4(0);
      break;
    // Rcur
    case 12:
    case 13:
      STATUS_LED_1(1);
      STATUS_LED_3(1);
      STATUS_LED_2(0);
      STATUS_LED_4(1);
      break;
    default:
      STATUS_LED_1(1);
      STATUS_LED_3(1);
      STATUS_LED_2(1);
      STATUS_LED_4(1);
      break;
  }
  return state;
}

//
// Tap Flow Control
// Space disable -> layer mod
// semecolon dinable -> engram opt
//
bool is_flow_tap_key(uint16_t keycode) {
  if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
    return false; // Disable Flow Tap on hotkeys.
  }
  switch (get_tap_keycode(keycode)) {
    //case KC_SPC:
    case KC_A ... KC_Z:
    case KC_DOT:
    case KC_COMM:
    //case KC_SCLN:
    case KC_SLSH:
      return true;
  }
  return false;
}

