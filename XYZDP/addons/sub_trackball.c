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
  TB_S_SET_CPI_QUEUE_MOTION,
  TB_S_READ_MOTION_QUEUE_X_L,
  TB_S_READ_X_L_QUEUE_Y_L,
  TB_S_READ_Y_L_QUEUE_X_H,
  TB_S_READ_X_H_QUEUE_Y_H,
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

// copy and mod zsa code

// The sequence of commands to configure and boot the paw3805ek sensor.
paw3805ek_reg_seq_t paw3805ek_configure_seq[] = {
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
i2c_status_t sci18is606_write(uint8_t *data, uint8_t length) {
    return i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, data, length, NAVIGATOR_TRACKBALL_TIMEOUT);
}

// A wrapper function for i2c_receive that adds the address of the bridge chip to the data.
i2c_status_t sci18is606_read(uint8_t *data, uint8_t length) {
    return i2c_receive(NAVIGATOR_TRACKBALL_ADDRESS, data, length, NAVIGATOR_TRACKBALL_TIMEOUT);
}

// A wrapper function that allows to write and optionally read from the bridge chip.
i2c_status_t sci18is606_spi_tx(uint8_t *data, uint8_t length, bool read) {
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
i2c_status_t sci18is606_spi_issue(uint8_t *data, uint8_t length) {
    return sci18is606_write(data, length);
}

i2c_status_t sci18is606_spi_read(uint8_t *data, uint8_t length) {
    return sci18is606_read(data, length);
}

// Configure the bridge chip to enable SPI mode.
i2c_status_t sci18is606_configure(void) {
    uint8_t      spi_conf[2] = {SCI18IS606_CONF_SPI, SCI18IS606_CONF};
    i2c_status_t status      = sci18is606_write(spi_conf, 2);
    wait_ms(10);
    //if (status != I2C_STATUS_SUCCESS) {
    //    trackball_init = 0;
    //}
    return status;
}

bool paw3805ek_set_cpi(void) {

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
bool paw3805ek_configure(void) {
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

void pointing_device_driver_init(void) {
  const fast_timer_t now = timer_read_fast();
  
  current_cpi = 0;
  new_cpi = NAVIGATOR_TRACKBALL_CPI;
  
  tb_state = TB_S_I2C_CONF;
  tb_trigger = now + 5000;
}

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
  const fast_timer_t now = timer_read_fast();

  // early exit
  if (timer_expired_fast(now, tb_trigger) == false) return mouse_report;

  if (tb_state == TB_S_I2C_CONF) {
    if (sci18is606_configure() != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }
    
    tb_state = TB_S_SPI_CONF;
    tb_trigger = now + 10;
  } else if (tb_state == TB_S_SPI_CONF) {
    paw3805ek_configure();

    tb_state = TB_S_SET_CPI;
    tb_trigger = now + 10;
  } else if (tb_state == TB_S_SET_CPI_QUEUE_MOTION) {
    if (current_cpi != new_cpi) {
      current_cpi = new_cpi;
      paw3805ek_set_cpi();
    }
    
    uint8_t motion[3] = {0x01, 0x02, 0x00};
    if (sci18is606_spi_issue(motion, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }

    tb_state = TB_S_READ_MOTION_QUEUE_X_L;
    tb_trigger = now + 3;
  } else if (tb_state == TB_S_READ_MOTION_QUEUE_X_L) {
    uint8_t motion[3] = {0x01, 0x02, 0x00};
    if (sci18is606_spi_read(motion, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }
    
    if (motion[1] & 0x80) {
      uint8_t delta_x_l[3] = {0x01, 0x03, 0x00};
      if (sci18is606_spi_issue(delta_x_l, 3) != I2C_STATUS_SUCCESS) {
        current_cpi = 0;
        tb_state = TB_S_I2C_CONF;
        tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
        return mouse_report;
      }
      
      tb_state = TB_S_ISSUE_X_L;
      tb_trigger = now + 3;
    } else {
      tb_state = TB_S_SET_CPI_QUEUE_MOTION;
      tb_trigger = now + 10;
    }
  } else if (tb_state == TB_S_READ_X_L_QUEUE_Y_L) {
    uint8_t delta_x_l[3] = {0x01, 0x03, 0x00};
    if (sci18is606_spi_read(delta_x_l, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }

    x_l =  delta_x_l[1];

    uint8_t delta_y_l[3] = {0x01, 0x04, 0x00};
    if (sci18is606_spi_issue(delta_y_l, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }
    
    tb_state = TB_S_READ_Y_L_QUEUE_X_H;
    tb_trigger = now + 3;    
  } else if (tb_state == TB_S_READ_Y_L_QUEUE_X_H) {
    uint8_t delta_y_l[3] = {0x01, 0x04, 0x00};
    if (sci18is606_spi_read(delta_y_l, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }

    y_l =  delta_y_l[1];
    
    uint8_t delta_x_h[3] = {0x01, 0x11, 0x00};
    if (sci18is606_spi_issue(delta_x_h, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }
    
    tb_state = TB_S_READ_X_H_QUEUE_Y_H;
    tb_trigger = now + 3;
  } else if (tb_state == TB_S_READ_X_H_QUEUE_Y_H) {
    uint8_t delta_x_h[3] = {0x01, 0x11, 0x00};
    if (sci18is606_spi_read(delta_x_h, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }

    x_h =  delta_x_h[1];

    tb_state = TB_S_ISSUE_Y_H;
    tb_trigger = now + 3;
  } else if (tb_state == TB_S_ISSUE_Y_H) {
    uint8_t delta_y_h[3] = {0x01, 0x12, 0x00};
    if (sci18is606_spi_issue(delta_y_h, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }
    
    tb_state = TB_S_READ_Y_H_SEND_REPORT;
    tb_trigger = now + 3;
  } else if (tb_state == TB_S_READ_Y_H_SEND_REPORT) {
    uint8_t delta_y_h[3] = {0x01, 0x12, 0x00};
    if (sci18is606_spi_read(delta_y_h, 3) != I2C_STATUS_SUCCESS) {
      current_cpi = 0;
      tb_state = TB_S_I2C_CONF;
      tb_trigger = now + NAVIGATOR_TRACKBALL_PROBE;
      return mouse_report;
    }

    y_h =  delta_y_h[1];
    
    mouse_report.x = (int16_t)(((int16_t)x_h << 8) | x_l);
    mouse_report.y = (int16_t)(((int16_t)y_h << 8) | y_l);

    tb_state = TB_S_SET_CPI_QUEUE_MOTION;
    tb_trigger = now + 3;
  } 

  return mouse_report;
}

