#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "overlay_layer_mod.h"

// use animation logic
// use abs path
#include "lib/lib8tion/lib8tion.h"

#include "layer_num.h"

// ime state from LANG1/LANG2 key
static bool ime_on = false;
static bool ime_kk = false;  //KataKana

// Ime State Sync system
static bool iss_enable = true; 
static bool iss_sync = false;

static fast_timer_t iss_trigger = 0;
static const fast_timer_t iss_sync_delay = 15013; //ms
static const fast_timer_t iss_idle_delay = 600011; //ms


