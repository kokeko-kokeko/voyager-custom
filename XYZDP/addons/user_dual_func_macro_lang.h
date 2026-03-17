#pragma once

// use MT with 3,4 mod for dual func without Meh Hyper, more safe

#define MOD_UDFN1 (MOD_LCTL | MOD_LSFT | MOD_LGUI)
#define MOD_UDFN2 (MOD_RCTL | MOD_RSFT | MOD_RGUI)

#define MOD_UDFN3 (MOD_LCTL | MOD_LALT | MOD_LGUI)
#define MOD_UDFN4 (MOD_RCTL | MOD_RALT | MOD_RGUI)

#define MOD_UDFN5 (MOD_LSFT | MOD_LALT | MOD_LGUI)
#define MOD_UDFN6 (MOD_RSFT | MOD_RALT | MOD_RGUI)

// use 7 & 8 R Meh Hyper
// #define MOD_MEH (MOD_LCTL | MOD_LSFT | MOD_LALT)
// #define MOD_HYPR (MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI)

#define MOD_UDFN7 (MOD_RCTL | MOD_RSFT | MOD_RALT)
#define MOD_UDFN8 (MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI)

//#define MT(mod, kc) (QK_MOD_TAP | (((mod)&0x1F) << 8) | ((kc)&0xFF))
#define UDFN1(kc) MT(MOD_UDFN1, kc)
#define UDFN2(kc) MT(MOD_UDFN2, kc)
#define UDFN3(kc) MT(MOD_UDFN3, kc)
#define UDFN4(kc) MT(MOD_UDFN4, kc)
#define UDFN5(kc) MT(MOD_UDFN5, kc)
#define UDFN6(kc) MT(MOD_UDFN6, kc)
#define UDFN7(kc) MT(MOD_UDFN7, kc)
#define UDFN8(kc) MT(MOD_UDFN8, kc)

void jis_enable(void);
void jis_disable(void);
bool jis_is_enabled(void);

bool process_record_user_dual_func_macro_lang(uint16_t keycode, keyrecord_t *record);
