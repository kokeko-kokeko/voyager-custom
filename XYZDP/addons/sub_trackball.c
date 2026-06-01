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
  TB_S_READ_Y_H_ISSUE_MOTION_SEND_REPORT
};

static uint8_t current_cpi = 0;
static uint8_t new_cpi = NAVIGATOR_TRACKBALL_CPI;

static uint8_t tb_sensor_state = TB_S_I2C_CONF;
static fast_timer_t tb_sensor_trigger = 0;

static uint8_t x_l = 0;
static uint8_t y_l = 0;
static uint8_t x_h = 0;
static uint8_t y_h = 0;

// 32-bit accumulator
// on memory format 30bit total
// 10bit coeff _ 16bit int part int (with sign) _ 4 bit frac uint for guard
// 16bit raw int
// 10bit coeff int
//  4bit frac guard margin (final output shift out)
// int coeff 1024 * [0 - 1.0)

static int32_t accumulator_x = 0;
static int32_t accumulator_y = 0;
static int32_t accumulator_h = 0;
static int32_t accumulator_v = 0;

// temp
static const int32_t add_coeff = 16;  //raw move to int part 1_0000
static const int32_t reten_coeff = 512;
static const int32_t move_det_th = 320;

static bool scroll_flag = false;

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

#define TRACKBALL_AUTO_LAYER LAYER_Mouse_L

#define TRACKPAD_AUTO_LAYER LAYER_Mouse_R

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
  accumulator_h = 0;
  accumulator_v = 0;
}

// POINTING_DEVICE_DRIVER = custom
void pointing_device_driver_init(void) {
  const fast_timer_t now = timer_read_fast();
  
  new_cpi = NAVIGATOR_TRACKBALL_CPI;

  reset_trackball_state(now);
}

// i2c tx/rx buffer with guard
static uint8_t i2c_issue_buf[8] = {0x01, 0}; 
static uint8_t i2c_read_buf[8] = {0}; 

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
  
  // sensor pbobe
  if (timer_expired_fast(now, tb_sensor_trigger)){  
    if (tb_sensor_state == TB_S_I2C_CONF) {
      if (sci18is606_configure() != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
    
      tb_sensor_state = TB_S_SPI_CONF;
      tb_sensor_trigger = now + 10;
    } else if (tb_sensor_state == TB_S_SPI_CONF) {
      paw3805ek_configure();

      tb_sensor_state = TB_S_SET_CPI_ISSUE_MOTION;
      tb_sensor_trigger = now + 10;
    } else if (tb_sensor_state == TB_S_SET_CPI_ISSUE_MOTION) {
      if (current_cpi != new_cpi) {
        current_cpi = new_cpi;
        paw3805ek_set_cpi();
      }
    
      i2c_issue_buf[0] = 0x01;  // CS bit set once
      i2c_issue_buf[1] = 0x02;  // SPI address
      if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      tb_sensor_state = TB_S_READ_MOTION_ISSUE_X_L;
      //tb_sensor_trigger = now + 1;
    } else if (tb_sensor_state == TB_S_READ_MOTION_ISSUE_X_L) {
      if (sci18is606_spi_read(i2c_read_buf, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
    
      if (i2c_read_buf[1] & 0x80) {
        //i2c_issue_buf[0] = 0x01;
        i2c_issue_buf[1] = 0x03;  // SPI address
        if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
          reset_trackball_state(now);
          return mouse_report;
        }
      
        tb_sensor_state = TB_S_READ_X_L_ISSUE_Y_L;
        //tb_sensor_trigger = now + 1;
      } else {
        tb_sensor_state = TB_S_SET_CPI_ISSUE_MOTION;
        tb_sensor_trigger = now + NAVIGATOR_TRACKBALL_READ;
      }
    } else if (tb_sensor_state == TB_S_READ_X_L_ISSUE_Y_L) {
      if (sci18is606_spi_read(i2c_read_buf, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      x_l =  i2c_read_buf[1];

      //i2c_issue_buf[0] = 0x01;
      i2c_issue_buf[1] = 0x04;  // SPI address
      if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
    
      tb_sensor_state = TB_S_READ_Y_L_ISSUE_X_H;
      //tb_sensor_trigger = now + 1;    
    } else if (tb_sensor_state == TB_S_READ_Y_L_ISSUE_X_H) {
      if (sci18is606_spi_read(i2c_read_buf, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      y_l =  i2c_read_buf[1];
    
      //i2c_issue_buf[0] = 0x01;
      i2c_issue_buf[1] = 0x11;  // SPI address
      if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
    
      tb_sensor_state = TB_S_READ_X_H_ISSUE_Y_H;
      //tb_sensor_trigger = now + 1;
    } else if (tb_sensor_state == TB_S_READ_X_H_ISSUE_Y_H) {
      if (sci18is606_spi_read(i2c_read_buf, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      x_h =  i2c_read_buf[1];
    
      //i2c_issue_buf[0] = 0x01;
      i2c_issue_buf[1] = 0x12;  // SPI address
      if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
    
      tb_sensor_state = TB_S_READ_Y_H_ISSUE_MOTION_SEND_REPORT;
      //tb_sensor_trigger = now + 1;
    } else if (tb_sensor_state == TB_S_READ_Y_H_ISSUE_MOTION_SEND_REPORT) {
      if (sci18is606_spi_read(i2c_read_buf, 2) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      y_h =  i2c_read_buf[1];

      //i2c_issue_buf[0] = 0x01;
      i2c_issue_buf[1] = 0x02;  // SPI address
      if (sci18is606_spi_issue(i2c_issue_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }

      tb_sensor_state = TB_S_READ_MOTION_ISSUE_X_L;
      //tb_sensor_trigger = now + 1;

      int16_t delta_x = (int16_t)(((int16_t)x_h << 8) | x_l);
      int16_t delta_y = (int16_t)(((int16_t)y_h << 8) | y_l);

      if (scroll_flag) {
        accumulator_h = ((int32_t)delta_x) * add_coeff;
        accumulator_v = ((int32_t)delta_y) * add_coeff;
      } else {
        accumulator_x = ((int32_t)delta_x) * add_coeff;
        accumulator_y = ((int32_t )delta_y) * add_coeff;
      }
    }
  }
  
  // move detect, layer on
  // pseudo vector length
  // https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0/%E5%B9%B3%E6%96%B9%E6%A0%B9%E3%82%92%E4%BD%BF%E3%82%8F%E3%81%9A%E3%81%AB%E8%B7%9D%E9%9B%A2%E3%82%92%E6%B1%82%E3%82%81%E3%82%8B
  // https://qiita.com/Mya-Mya/items/68f6cafb4619c76956d6

  // output, digital filter
  // shift with bias
  // 16
  // 1024

  if ((accumulator_x != 0) || (accumulator_y != 0)) {
    int32_t abs_x = (accumulator_x >= 0) ? accumulator_x : -accumulator_x;
    int32_t abs_y = (accumulator_y >= 0) ? accumulator_y : -accumulator_y;

    int32_t max = (abs_x > abs_y) ? abs_x : abs_y;
    int32_t min = (abs_x < abs_y) ? abs_x : abs_y;
 
    int32_t pseudo_r = (983 * max) + (407 * min);  // 1024 base
    pseudo_r >>= 10;
    
    if (pseudo_r > move_det_th) {
      trackball_early_off_trigger = now + AUTO_MOUSE_TIME_TRACKBALL;
      layer_on(TRACKBALL_AUTO_LAYER);
    }

    mouse_report.x = (accumulator_x >= 0) ? (int16_t)(accumulator_x >> 4) : (int16_t)((accumulator_x + 15) >> 4);
    accumulator_x = accumulator_x * reten_coeff;
    accumulator_x = (accumulator_x >= 0) ? (int16_t)(accumulator_x >> 10) : (int16_t)((accumulator_x + 1023) >> 10);

    mouse_report.y = (accumulator_y >= 0) ? (int16_t)(accumulator_y >> 4) : (int16_t)((accumulator_y + 15) >> 4);
    accumulator_y = accumulator_y * reten_coeff;
    accumulator_y = (accumulator_y >= 0) ? (int16_t)(accumulator_y >> 10) : (int16_t)((accumulator_y + 1023) >> 10);
  }
  
  if (accumulator_h != 0) {
    mouse_report.h = (accumulator_h >= 0) ? (int16_t)(accumulator_h >> 4) : (int16_t)((accumulator_h + 15) >> 4);
    accumulator_h = accumulator_h * reten_coeff;
    accumulator_h = (accumulator_h >= 0) ? (int16_t)(accumulator_h >> 10) : (int16_t)((accumulator_h + 1023) >> 10);
  }

  if (accumulator_v != 0) {
    mouse_report.v = (accumulator_v >= 0) ? (int16_t)(accumulator_v >> 4) : (int16_t)((accumulator_v + 15) >> 4);
    accumulator_v = accumulator_v * reten_coeff;
    accumulator_v = (accumulator_v >= 0) ? (int16_t)(accumulator_v >> 10) : (int16_t)((accumulator_v + 1023) >> 10);
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

void post_process_record_sub_trackball(uint16_t keycode, keyrecord_t *record) {
  post_process_record_non_mouse(keycode, record);
  post_process_record_mouse_button(keycode, record);
  
  return;
}

layer_state_t layer_state_set_sub_trackball(layer_state_t state) {    
  scroll_flag = layer_state_cmp(state, TRACKPAD_AUTO_LAYER);
  scroll_flag = scroll_flag || layer_state_cmp(state, LAYER_Number);
  scroll_flag = scroll_flag || layer_state_cmp(state, LAYER_Cursor);
  scroll_flag = scroll_flag || layer_state_cmp(state, LAYER_Function);

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
