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

#include "addons/sub_trackball.h"

// issue / read state machine
enum trackball_state {
  TB_S_I2C_CONF = 0,
  TB_S_SPI_CONF,
  TB_S_SET_CPI_ISSUE_MOTION,
  TB_S_READ_MOTION_ISSUE_X_L,
  TB_S_READ_X_L_ISSUE_Y_L,
  TB_S_READ_Y_L_ISSUE_X_H,
  TB_S_READ_X_H_ISSUE_Y_H,
  TB_S_READ_Y_H_SEND_REPORT
};

static uint8_t current_cpi = 0;
static uint8_t new_cpi = NAVIGATOR_TRACKBALL_CPI;

static uint8_t tb_state = TB_S_I2C_CONF;
static fast_timer_t tb_trigger = 0;

static uint8_t x_l = 0;
static uint8_t y_l = 0;
static uint8_t x_h = 0;
static uint8_t y_h = 0;

//static int16_t delta_x = 0;
//static int16_t delta_y = 0;

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
  tb_state = TB_S_I2C_CONF;
  tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
}

// POINTING_DEVICE_DRIVER = custom
void pointing_device_driver_init(void) {
  const fast_timer_t now = timer_read_fast();
  
  new_cpi = NAVIGATOR_TRACKBALL_CPI;

  reset_trackball_state(now);
}

// i2c tx/rx buffer with guard
uint8_t i2c_buf[8] = {0}; 

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
  
  // early exit
  if (timer_expired_fast(now, tb_trigger) == false) return mouse_report;

  if (tb_state == TB_S_I2C_CONF) {
    if (sci18is606_configure() != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }
    
    tb_state = TB_S_SPI_CONF;
    tb_trigger = now + 10;
  } else if (tb_state == TB_S_SPI_CONF) {
    paw3805ek_configure();

    tb_state = TB_S_SET_CPI_ISSUE_MOTION;
    tb_trigger = now + 10;
  } else if (tb_state == TB_S_SET_CPI_ISSUE_MOTION) {
    if (current_cpi != new_cpi) {
      current_cpi = new_cpi;
      paw3805ek_set_cpi();
    }
    
    i2c_buf[0] = 0x01;
    i2c_buf[1] = 0x02;
    if (sci18is606_spi_issue(i2c_buf, 3) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }

    tb_state = TB_S_READ_MOTION_ISSUE_X_L;
    tb_trigger = now + 1;
  } else if (tb_state == TB_S_READ_MOTION_ISSUE_X_L) {
    if (sci18is606_spi_read(i2c_buf, 2) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }
    
    if (i2c_buf[1] & 0x80) {
      i2c_buf[0] = 0x01;
      i2c_buf[1] = 0x03;
      if (sci18is606_spi_issue(i2c_buf, 3) != I2C_STATUS_SUCCESS) {
        reset_trackball_state(now);
        return mouse_report;
      }
      
      tb_state = TB_S_READ_X_L_ISSUE_Y_L;
      tb_trigger = now + 1;
    } else {
      tb_state = TB_S_SET_CPI_ISSUE_MOTION;
      tb_trigger = now + NAVIGATOR_TRACKBALL_READ;
    }
  } else if (tb_state == TB_S_READ_X_L_ISSUE_Y_L) {
    if (sci18is606_spi_read(i2c_buf, 2) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }

    x_l =  i2c_buf[1];

    i2c_buf[0] = 0x01;
    i2c_buf[1] = 0x04;
    if (sci18is606_spi_issue(i2c_buf, 3) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }
    
    tb_state = TB_S_READ_Y_L_ISSUE_X_H;
    tb_trigger = now + 1;    
  } else if (tb_state == TB_S_READ_Y_L_ISSUE_X_H) {
    if (sci18is606_spi_read(i2c_buf, 2) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }

    y_l =  i2c_buf[1];
    
    i2c_buf[0] = 0x01;
    i2c_buf[1] = 0x11;
    if (sci18is606_spi_issue(i2c_buf, 3) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }
    
    tb_state = TB_S_READ_X_H_ISSUE_Y_H;
    tb_trigger = now + 1;
  } else if (tb_state == TB_S_READ_X_H_ISSUE_Y_H) {
    if (sci18is606_spi_read(i2c_buf, 2) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }

    x_h =  i2c_buf[1];
    
    i2c_buf[0] = 0x01;
    i2c_buf[1] = 0x12;
    if (sci18is606_spi_issue(i2c_buf, 3) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }
    
    tb_state = TB_S_READ_Y_H_SEND_REPORT;
    tb_trigger = now + 1;
  } else if (tb_state == TB_S_READ_Y_H_SEND_REPORT) {
    if (sci18is606_spi_read(i2c_buf, 2) != I2C_STATUS_SUCCESS) {
      reset_trackball_state(now);
      return mouse_report;
    }

    y_h =  i2c_buf[1];
    
    mouse_report.x = (int16_t)(((int16_t)x_h << 8) | x_l);
    mouse_report.y = (int16_t)(((int16_t)y_h << 8) | y_l);

    tb_state = TB_S_SET_CPI_ISSUE_MOTION;
    tb_trigger = now + NAVIGATOR_TRACKBALL_READ;
  } 

  return mouse_report;
}

