// copy from zsa navigator.h

// Copyright 2025 ZSA Technology Labs, Inc <contact@zsa.io>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "pointing_device.h"

#ifndef NAVIGATOR_TRACKBALL_ADDRESS
#    define NAVIGATOR_TRACKBALL_ADDRESS 0x50
#endif

#ifndef NAVIGATOR_TRACKBALL_CPI
#    define NAVIGATOR_TRACKBALL_CPI 40
#endif

#ifndef NAVIGATOR_TRACKBALL_CPI_TICK
#    define NAVIGATOR_TRACKBALL_CPI_TICK 5
#endif

#define NAVIGATOR_TRACKBALL_CPI_MAX 125

#ifndef NAVIGATOR_TRACKBALL_TIMEOUT
#    define NAVIGATOR_TRACKBALL_TIMEOUT 100
#endif

#define NAVIGATOR_TRACKBALL_READ 25
#define NAVIGATOR_TRACKBALL_PROBE 1000

#define NCS_PIN 0x01
#define PAW3805EK_ID 0x31

#define SCI18IS606_CONF 0xDC //00001110b // MSB first, Mode 3, 155kHz

#define SCI18IS606_RW_SPI 0x00
#define SCI18IS606_CONF_SPI 0xF0
#define SCI18IS606_CLR_INT 0xF1
#define SCI18IS606_GET_ID 0xFE

#define WRITE_REG_BIT 0x80

typedef struct {
    uint8_t reg;
    uint8_t data;
} paw3805ek_reg_seq_t;

#ifndef MOUSE_EXTENDED_REPORT
#    define MOUSE_EXTENDED_REPORT
#endif

#ifndef WHEEL_EXTENDED_REPORT
#    define WHEEL_EXTENDED_REPORT
#endif

// mouse jiggler
#ifndef MOUSE_JIGGLER_INTERVAL_MS
#    define MOUSE_JIGGLER_INTERVAL_MS 1000
#endif

#ifndef MOUSE_JIGGLER_MOVEMENT
#    define MOUSE_JIGGLER_MOVEMENT 1
#endif

extern void mouse_jiggler_enable(void);
extern void mouse_jiggler_disable(void);
extern bool mouse_jiggler_is_enabled(void);

// auto layers
#define AUTO_MOUSE_TIME_MOUSEKEY_BUTTON 997
#define AUTO_MOUSE_TIME_TRACKBALL 7993

void keyboard_post_init_sub_trackball(void);
void post_process_record_sub_trackball(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_sub_trackball(layer_state_t state);
void housekeeping_task_sub_trackball(void);



