#pragma once

// use MT with 1 or 2 mod, must mod override hold side
// HOOR : Hold Only OverRide, tap pass to normal process
// THORn : Tap Hold OverRide, both override, shift and land handle
// THORnS : Tap Hold OverRide, both override, fix shift
// MCFW : MaCro FirmWare

#define MOD_HOOR (MOD_LCTL)

#define MOD_THOR1 (MOD_RCTL)
#define MOD_THOR1S (MOD_RCTL | MOD_RSFT)

#define MOD_THOR2 (MOD_LALT)
#define MOD_THOR2S (MOD_LALT | MOD_LSFT)

#define MOD_MCFW (MOD_LCTL | MOD_LSFT)

//#define MT(mod, kc) (QK_MOD_TAP | (((mod)&0x1F) << 8) | ((kc)&0xFF))
#define HOOR(kc) MT(MOD_HOOR, kc)

#define THOR1(kc) MT(MOD_THOR1, kc)
#define THOR1S(kc) MT(MOD_THOR1S, kc)

#define THOR2(kc) MT(MOD_THOR2, kc)
#define THOR2S(kc) MT(MOD_THOR2S, kc)

#define MCFW(kc) MT(MOD_MCFW, kc)

void jis_enable(void);
void jis_disable(void);
bool jis_is_enabled(void);

bool process_record_orthogonality_mod_layer_lang(uint16_t keycode, keyrecord_t *record);
