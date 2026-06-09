#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "i2c_master.h"
#include <stdint.h>
#include <stdio.h>
#include "quantum.h"

#include "layer_num.h"

#include "addons/sub_trackball.h"

// issue / read state machine
enum trackball_sensor_state {
  TB_S_I2C_CONF = 0,
  TB_S_SPI_CONF,
  TB_S_SET_CPI_ISSUE_MOTION,
  TB_S_READ_MOTION_ISSUE_X_L,
  TB_S_READ_X_L_ISSUE_Y_L,
  TB_S_READ_Y_L_ISSUE_X_H,
  TB_S_READ_X_H_ISSUE_Y_H,
  TB_S_READ_Y_H_ISSUE_MOTION_ADD_ACC
};

static uint8_t current_cpi = 0;
static uint8_t new_cpi = NAVIGATOR_TRACKBALL_CPI;

static uint8_t tb_sensor_state = TB_S_I2C_CONF;
static fast_timer_t tb_sensor_trigger = 0;

// simple int 32-bit accumulator (w/o coeff)
static int32_t accumulator_x = 0;
static int32_t accumulator_y = 0;

static bool move_xy_flag = false;

static bool mouse_jiggler_enabled = false;
static fast_timer_t mouse_jiggler_trigger = 0;
static int8_t jiggle_direction = 1;

bool mouse_jiggler_is_enabled(void) {
    return mouse_jiggler_enabled;
}

void mouse_jiggler_enable(void) {
    mouse_jiggler_enabled = true;
    mouse_jiggler_trigger = timer_read_fast() + MOUSE_JIGGLER_INTERVAL_MS;
}

void mouse_jiggler_disable(void) {
    mouse_jiggler_enabled = false;
}

static fast_timer_t trackball_early_off_trigger = 0;

#define TRACKBALL_AUTO_LAYER LAYER_Mouse_R

#define TRACKPAD_AUTO_LAYER LAYER_Mouse_L

// copy and mod zsa code

// The sequence of commands to configure and boot the paw3805ek sensor.
static paw3805ek_reg_seq_t paw3805ek_configure_seq[] = {
    {0x06, 0x80},                 // Software reset
    {0x00, 0x00},                 // Request the sensor ID
    {0x09 | WRITE_REG_BIT, 0x5A}, // Disable the write protection
#ifdef MOUSE_EXTENDED_REPORT
    {0x19 | WRITE_REG_BIT, 0x30}, // Set the sensor orientation, set motion data length to 16 bits
#else
    {0x19 | WRITE_REG_BIT, 0x34}, // Set the sensor orientation, set motion data length to 8 bits
#endif
    //{0x26 | WRITE_REG_BIT, 0x10}, // Enable burst mode
    {0x09 | WRITE_REG_BIT, 0x00}, // Enable the write protection
};

// A wrapper function for i2c_transmit that adds the address of the bridge chip to the data.
static i2c_status_t sci18is606_write(uint8_t *data, uint8_t length) {
    return i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, data, length, NAVIGATOR_TRACKBALL_TIMEOUT);
}

// A wrapper function for i2c_receive that adds the address of the bridge chip to the data.
static i2c_status_t sci18is606_read(uint8_t *data, uint8_t length) {
    return i2c_receive(NAVIGATOR_TRACKBALL_ADDRESS, data, length, NAVIGATOR_TRACKBALL_TIMEOUT);
}

// A wrapper function that allows to write and optionally read from the bridge chip.
static i2c_status_t sci18is606_spi_tx(uint8_t *data, uint8_t length, bool read) {
    i2c_status_t status = sci18is606_write(data, length);
    wait_us(length * 15);
    // Read the SPI response if the command expects it
    if (read) {
        status = sci18is606_read(data, length);
    }
    //if (status != I2C_STATUS_SUCCESS) {
    //    trackball_init = 0;
    //}
    return status;
}

// split queue 
static i2c_status_t sci18is606_spi_issue(uint8_t *data, uint8_t length) {
    return sci18is606_write(data, length);
}

static i2c_status_t sci18is606_spi_read(uint8_t *data, uint8_t length) {
    return sci18is606_read(data, length);
}

// Configure the bridge chip to enable SPI mode.
static i2c_status_t sci18is606_configure(void) {
    uint8_t      spi_conf[2] = {SCI18IS606_CONF_SPI, SCI18IS606_CONF};
    i2c_status_t status      = sci18is606_write(spi_conf, 2);
    wait_ms(10);
    //if (status != I2C_STATUS_SUCCESS) {
    //    trackball_init = 0;
    //}
    return status;
}

static bool paw3805ek_set_cpi(void) {

    paw3805ek_reg_seq_t cpi_reg_seq[] = {
        {0x09 | WRITE_REG_BIT, 0x5A}, // Disable write protection
        {0x0D | WRITE_REG_BIT, current_cpi},
        {0x0E | WRITE_REG_BIT, current_cpi},
        {0x09 | WRITE_REG_BIT, 0x00}, // Enable the write protection
    };

    // Run the spi sequence to configure the cpi.
    for (uint8_t i = 0; i < sizeof(cpi_reg_seq) / sizeof(paw3805ek_reg_seq_t); i++) {
        uint8_t buf[3];
        buf[0] = NCS_PIN;
        buf[1] = cpi_reg_seq[i].reg;
        buf[2] = cpi_reg_seq[i].data;
        if (sci18is606_spi_tx(buf, 3, true) != I2C_STATUS_SUCCESS) {
            return false;
        }
    }

    return true;
}

// Run the paw3805ek configuration sequence.
static bool paw3805ek_configure(void) {
    for (uint8_t i = 0; i < sizeof(paw3805ek_configure_seq) / sizeof(paw3805ek_reg_seq_t); i++) {
        uint8_t buf[3];
        buf[0] = NCS_PIN;
        buf[1] = paw3805ek_configure_seq[i].reg;
        buf[2] = paw3805ek_configure_seq[i].data;
        if (sci18is606_spi_tx(buf, 3, true) != I2C_STATUS_SUCCESS) {
            return false;
        }
        // Wait for the sensor to restart after the software reset cmd
        wait_ms(1);

        // Check the sensor ID to validate the spi link after the reset
        if (i == 1 && buf[1] != PAW3805EK_ID) {
            return false;
        }
    }

    return true;
}

static void reset_trackball_state(const fast_timer_t now) {
  current_cpi = 0;
  tb_sensor_state = TB_S_I2C_CONF;
  tb_sensor_trigger = now + NAVIGATOR_TRACKBALL_PROBE;

  accumulator_x = 0;
  accumulator_y = 0;
}

// POINTING_DEVICE_DRIVER = custom
void pointing_device_driver_init(void) {
  const fast_timer_t now = timer_read_fast();
  
  new_cpi = NAVIGATOR_TRACKBALL_CPI;

  reset_trackball_state(now);
}

// POINTING_DEVICE_DRIVER = custom
report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
  const fast_timer_t now = timer_read_fast();

  if (mouse_jiggler_enabled) {
    if (timer_expired_fast(now, mouse_jiggler_trigger)) {
      mouse_jiggler_trigger += MOUSE_JIGGLER_INTERVAL_MS;

      mouse_report.x = MOUSE_JIGGLER_MOVEMENT * jiggle_direction;

      jiggle_direction = -jiggle_direction;
    }
  }
  
  if ((accumulator_x != 0) || (accumulator_y != 0)) {
    if (move_xy_flag) {
      mouse_report.x = (int16_t) accumulator_x;
      mouse_report.y = (int16_t) accumulator_y;
    } else {
      mouse_report.h = (int16_t) accumulator_x;
      mouse_report.v = (int16_t) accumulator_y;
    }

    accumulator_x = 0;
    accumulator_y = 0;
  }
  
  return mouse_report;
}

static void post_process_record_non_mouse(uint16_t keycode, keyrecord_t *record) {
  // mouse non-active skip
  if (layer_state_is(TRACKBALL_AUTO_LAYER) == false) return;

  // keep on mouse number and cursor
  if (layer_state_is(LAYER_Mouse_Upper_L) == true) return;
  if (layer_state_is(LAYER_Mouse_Upper_R) == true) return;
  if (layer_state_is(LAYER_Number) == true) return;
  if (layer_state_is(LAYER_Cursor) == true) return;

  // keycode check
  if (IS_MOUSEKEY(keycode) == true) return;
  if (IS_QK_MOMENTARY(keycode) == true) return;
  //if (IS_QK_LAYER_TAP(keycode) == true) return;
  if (keycode ==  LGUI(KC_TAB)) return;
  
  if (record->event.pressed) {
    // non-mouse key press 
    trackball_early_off_trigger = timer_read_fast() + (UINT32_MAX / 2) - 1;
  } else {
    // non-mouse key release, exit 
    trackball_early_off_trigger = timer_read_fast() + 1;
  } 

  return;
}

static void post_process_record_mouse_button(uint16_t keycode, keyrecord_t *record) {
  // only mouse button
  if (IS_MOUSEKEY_BUTTON(keycode) == false) return;
  
  if (record->event.pressed) {
    // non-mouse key press 
    trackball_early_off_trigger = timer_read_fast() + (UINT32_MAX / 2) - 1;
  } else {
    // non-mouse key release, exit 
    trackball_early_off_trigger = timer_read_fast() + AUTO_MOUSE_TIME_MOUSEKEY_BUTTON;
  }
  
  return;
}

void keyboard_post_init_sub_trackball(void) {
  const fast_timer_t now = timer_read_fast();

  trackball_early_off_trigger = now + (UINT32_MAX / 2) - 1;

  return;
}

void matrix_scan_sub_trackball(void) {
  // sensor probe
  const fast_timer_t now = timer_read_fast();

  // i2c tx/rx buffer with guard
  // motion, x_l, y_l, x_h, y_h
  // use common buffer issue, read, guard
  // pre-load commands
  static uint8_t i2c_buf[24] = {0x01, 0x02, 0x01, 0x03, 0x01, 0x04, 0x01, 0x11, 0x01, 0x12, 0x00, 0x00}; 
  
  // write 3 byte but last 1 byte is dummy (owerwrite from sensor)
  static uint8_t * const issue_motion = &i2c_buf[0];
  static uint8_t * const issue_x_l = &i2c_buf[2];
  static uint8_t * const issue_y_l = &i2c_buf[4];
  static uint8_t * const issue_x_h = &i2c_buf[6];
  static uint8_t * const issue_y_h = &i2c_buf[8];
  
  // read 2 byte first 1 byte is dummy
  static uint8_t * const read_motion = &i2c_buf[10];
  static uint8_t * const read_x_l = &i2c_buf[12];
  static uint8_t * const read_y_l = &i2c_buf[14];
  static uint8_t * const read_x_h = &i2c_buf[16];
  static uint8_t * const read_y_h = &i2c_buf[18];

  // value on second byte
  static uint8_t * const value_motion = &i2c_buf[11];
  static uint8_t * const value_x_l = &i2c_buf[13];
  static uint8_t * const value_y_l = &i2c_buf[15];
  static uint8_t * const value_x_h = &i2c_buf[17];
  static uint8_t * const value_y_h = &i2c_buf[19];

  // sensor pbobe function
  // early return to trigger
  if (timer_expired_fast(now, tb_sensor_trigger) == false) return;
  
  switch (tb_sensor_state) {
    case TB_S_I2C_CONF: {
      if (sci18is606_configure() != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return;
      }
    
      tb_sensor_state = TB_S_SPI_CONF;
      tb_sensor_trigger = now + NAVIGATOR_TRACKBALL_READ;
      return;
    }
    
    case TB_S_SPI_CONF: {
      paw3805ek_configure();

      tb_sensor_state = TB_S_SET_CPI_ISSUE_MOTION;
      tb_sensor_trigger = now + NAVIGATOR_TRACKBALL_READ;
      return;
    } 
    
    case TB_S_SET_CPI_ISSUE_MOTION: {
      if (current_cpi != new_cpi) {
        current_cpi = new_cpi;
        paw3805ek_set_cpi();
      }
    
      if (sci18is606_spi_issue(issue_motion, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return;
      }

      tb_sensor_state = TB_S_READ_MOTION_ISSUE_X_L;
      return;
    } 
    
    case TB_S_READ_MOTION_ISSUE_X_L: {
      if (sci18is606_spi_read(read_motion, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return;
      }

      if (*value_motion & 0x80) {
        if (sci18is606_spi_issue(issue_x_l, 3) != I2C_STATUS_SUCCESS) {
          reset_trackball_state(now);
          return;
        }

        tb_sensor_state = TB_S_READ_X_L_ISSUE_Y_L;
        return;
      } 
        
      tb_sensor_state = TB_S_SET_CPI_ISSUE_MOTION;
      tb_sensor_trigger = now + NAVIGATOR_TRACKBALL_READ;
      return;
    } 
    
    case TB_S_READ_X_L_ISSUE_Y_L: {
      if (
        (sci18is606_spi_read(read_x_l, 2) != I2C_STATUS_SUCCESS) ||
        (sci18is606_spi_issue(issue_y_l, 3) != I2C_STATUS_SUCCESS)
      ) {
        reset_trackball_state(now);
        return;
      }

      tb_sensor_state = TB_S_READ_Y_L_ISSUE_X_H;
      return;
    } 
    
    case TB_S_READ_Y_L_ISSUE_X_H: {
      if (
        (sci18is606_spi_read(read_y_l, 2) != I2C_STATUS_SUCCESS) ||
        (sci18is606_spi_issue(issue_x_h, 3) != I2C_STATUS_SUCCESS)
      ) {
        reset_trackball_state(now);
        return;
      }

      tb_sensor_state = TB_S_READ_X_H_ISSUE_Y_H;
      return;
    } 
    
    case TB_S_READ_X_H_ISSUE_Y_H: {
      if (
        (sci18is606_spi_read(read_x_h, 2) != I2C_STATUS_SUCCESS) || 
        (sci18is606_spi_issue(issue_y_h, 3) != I2C_STATUS_SUCCESS) 
      ) {
        reset_trackball_state(now);
        return;
      }

      tb_sensor_state = TB_S_READ_Y_H_ISSUE_MOTION_ADD_ACC;
      return;
    } 
    
    case TB_S_READ_Y_H_ISSUE_MOTION_ADD_ACC: {
      if (
        (sci18is606_spi_read(read_y_h, 2) != I2C_STATUS_SUCCESS) || 
        (sci18is606_spi_issue(issue_motion, 3) != I2C_STATUS_SUCCESS)
      ) {
        reset_trackball_state(now);
        return;
      }

      int16_t delta_x = (int16_t)(((int16_t)*value_x_h << 8) | *value_x_l);
      int16_t delta_y = (int16_t)(((int16_t)*value_y_h << 8) | *value_y_l);

      accumulator_x += (int32_t)delta_x;
      accumulator_y += (int32_t)delta_y;

      tb_sensor_state = TB_S_READ_MOTION_ISSUE_X_L;
      return;
    }
  }

  return;
}

void post_process_record_sub_trackball(uint16_t keycode, keyrecord_t *record) {
  post_process_record_non_mouse(keycode, record);
  post_process_record_mouse_button(keycode, record);
  
  return;
}

layer_state_t layer_state_set_sub_trackball(layer_state_t state) {    
  //move_xy_flag = layer_state_cmp(state, TRACKPAD_AUTO_LAYER);
  move_xy_flag = false;
  
  move_xy_flag = move_xy_flag || layer_state_cmp(state, LAYER_Number);
  move_xy_flag = move_xy_flag || layer_state_cmp(state, LAYER_Cursor);
  move_xy_flag = move_xy_flag || layer_state_cmp(state, LAYER_Function);

  return state;
}

void housekeeping_task_sub_trackball(void) {
  const fast_timer_t now = timer_read_fast();

  if (timer_expired_fast(now, trackball_early_off_trigger)) {
    trackball_early_off_trigger = now + (UINT32_MAX / 2) - 1;
    //auto_mouse_layer_off();
    //automouse_disable();
    layer_off(TRACKBALL_AUTO_LAYER);
    //automouse_enable();
  }
  
  return;
}
