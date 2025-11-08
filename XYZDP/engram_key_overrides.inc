#pragma once

#include "keymap_japanese.h"

// keymap ovverride (process Engram symbol and ANSI/JIS)

// base (x and xs pair is shifted symbol, xs only overwrite shift)
static const key_override_t ko_jis_base_1 = ko_make_with_layers_and_negmods(0, KC_1, JP_HASH, (layer_state_t)1 << L_Base_2025, (uint8_t) MOD_MASK_SHIFT);
static const key_override_t ko_jis_base_2 = ko_make_with_layers_and_negmods(0, JP_2, JP_QUOT, (layer_state_t)1 << L_Base_2025, (uint8_t) MOD_MASK_SHIFT);
static const key_override_t ko_jis_base_3 = ko_make_with_layers_and_negmods(0, JP_3, JP_DQUO, (layer_state_t)1 << L_Base_2025, (uint8_t) MOD_MASK_SHIFT);
static const key_override_t ko_jis_base_4 = ko_make_with_layers_and_negmods(0, KC_4, JP_QUES, (layer_state_t)1 << L_Base_2025, (uint8_t) MOD_MASK_SHIFT);

static const key_override_t ko_jis_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, JP_1, JP_DLR,  (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, JP_2, JP_LPRN, (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_3s = ko_make_with_layers(MOD_MASK_SHIFT, JP_3, JP_RPRN, (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_4s = ko_make_with_layers(MOD_MASK_SHIFT, JP_4, JP_EXLM, (layer_state_t)1 << L_Base_2025);

static const key_override_t ko_jis_base_ATs   = ko_make_with_layers(MOD_MASK_SHIFT, JP_AT,   JP_GRV,  (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_MINSs = ko_make_with_layers(MOD_MASK_SHIFT, JP_MINS, JP_UNDS, (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_SLSHs = ko_make_with_layers(MOD_MASK_SHIFT, JP_SLSH, JP_BSLS, (layer_state_t)1 << L_Base_2025);
static const key_override_t ko_jis_base_DOTs  = ko_make_with_layers(MOD_MASK_SHIFT, JP_DOT,  JP_COLN, (layer_state_t)1 << L_Base_2025);


// base (x and xs pair is shifted symbol, xs only overwrite shift)
static const key_override_t ko_ansi_base_1 = ko_make_with_layers_and_negmods(0, KC_1, KC_AT,   (layer_state_t)1 << L_Base_ANSI, (uint8_t) MOD_MASK_SHIFT);
static const key_override_t ko_ansi_base_2 = ko_make_with_layers_and_negmods(0, KC_2, KC_DQUO, (layer_state_t)1 << L_Base_ANSI, (uint8_t) MOD_MASK_SHIFT);

static const key_override_t ko_ansi_base_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_GRV,  (layer_state_t)1 << L_Base_ANSI);
static const key_override_t ko_ansi_base_2s = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, KC_RPRN, (layer_state_t)1 << L_Base_ANSI);

static const key_override_t ko_ansi_base_QUOTs = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_LPRN, (layer_state_t)1 << L_Base_ANSI);
static const key_override_t ko_ansi_base_COMMs = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (layer_state_t)1 << L_Base_ANSI);
static const key_override_t ko_ansi_base_MINSs = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_UNDS, (layer_state_t)1 << L_Base_ANSI);
static const key_override_t ko_ansi_base_SLSHs = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, (layer_state_t)1 << L_Base_ANSI);
static const key_override_t ko_ansi_base_DOTs  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_COLN, (layer_state_t)1 << L_Base_ANSI);

// not work, disable, guess with mod-tap race condition
//static const key_override_t ko_ansi_num_1s = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_PIPE,  1 << 2);
//...
//static const key_override_t ko_ansi_num_0s = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_ASTR,  1 << 2);
const key_override_t *key_overrides[] = {
  &ko_jis_base_1,  &ko_jis_base_2,  ko_jis_base_3,  &ko_jis_base_4,
  &ko_jis_base_1s, &ko_jis_base_2s, ko_jis_base_3s, &ko_jis_base_4s,
  &ko_jis_base_ATs, &ko_jis_base_MINSs, &ko_jis_base_SLSHs, &ko_jis_base_DOTs,
  &ko_ansi_base_1,  &ko_ansi_base_2,
  &ko_ansi_base_1s, &ko_ansi_base_2s,
  &ko_ansi_base_QUOTs, &ko_ansi_base_COMMs, &ko_ansi_base_MINSs, &ko_ansi_base_SLSHs, &ko_ansi_base_DOTs
};


