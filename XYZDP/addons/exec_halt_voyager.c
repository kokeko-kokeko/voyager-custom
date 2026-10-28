#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// module safe-guard
#ifndef KEYBOARD_zsa_voyager
#    error "this file contains ZSA Voyager only magic number constants"
#endif

#include "layer/virt_layer.h"

#include "exec_halt.h"

#include "pos/get_pos_from_keyrecord.h"

#include "status/status_led.h"

#include "fade_matrix.h"

#include "ch.h"
#include "usb_main.h"

#include "mcp23018.h"
#include "i2c_master.h"

#include "user/split_txn_trackball.h"

#include "navigator_trackpad_common.h"

enum key_position {
  POSITION_Halt = 50,
  POSITION_Halt_Left = 23
};

// halt safety flags
static volatile bool halt_request0;
static volatile bool halt_request1;
static volatile bool halt_request2;

static uint8_t halt_invoke_count;
static fast_timer_t halt_invoke_reset_trigger;
static fast_timer_t exec_halt_trigger;

#define HALT_RESET_DELAY 503

void keyboard_post_init_exec_halt(void) {
  halt_request0 = false;
  halt_request1 = false;
  halt_request2 = false;
  
  halt_invoke_count = 0;
  halt_invoke_reset_trigger = (UINT32_MAX / 2) - 1;
  exec_halt_trigger = (UINT32_MAX / 2) - 1;
}

bool exec_halt_invoke_halt_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  
  const fast_timer_t now = timer_read_fast();

  // MT template
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      halt_invoke_count = record->tap.count;
      halt_invoke_reset_trigger = now + HALT_RESET_DELAY;
    } else {
      
    }
  } else {
    if (record->event.pressed) {
      
    } else {
      halt_invoke_count = 0;
    }  
  }
  
  // release
  //if (halt_invoke_count != UINT8_MAX) halt_invoke_count++;

  if (8 <= halt_invoke_count) {
    halt_request0 = true;
    halt_request1 = true;
    halt_request2 = true;
    exec_halt_trigger = now + 31;
    
    fade_matrix_disable();
    
    clear_keyboard();

    // halt status johnson counter
    STATUS_LED_1(false);
    
    return false;
  }

  if (7 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_2(false);
    
    return false;
  }

  if (6 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_3(false);
    
    return false;
  }

  if (5 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_4(false);
    
    return false;
  }

  if (4 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_1(true);
    
    return false;
  }

  if (3 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_2(true);
    
    return false;
  }
  
  if (2 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_3(true);
    
    return false;
  }

  if (1 <= halt_invoke_count) {
    // halt status johnson counter
    STATUS_LED_4(true);
    
    return false;
  }
  
  // default false
  return false;
}

bool rgb_matrix_indicators_exec_halt(void) {
  // if no active nothing to do, pass next
  if (virt_layer_state_is(VIRT_LAYER_Firmware) == false) return true;

  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;  
  
  // halt invoke == 0, clear and write blue pass next
  if (halt_invoke_count == 0) {
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, q);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, 0, q);

    return true; 
  }
  
  if (halt_request0 && halt_request1 && halt_request2) {
    rgb_matrix_set_color_all(0, 0, 0);
    // if run display terminate here
    return false;  
  }
  
  if (halt_invoke_count == 7) {
    rgb_matrix_set_color_all(q, 0, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, 0, 0);
    return false;
  } else if (halt_invoke_count == 6) {
    rgb_matrix_set_color_all(q, o, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, 0, 0);
    return false;
  } else if (halt_invoke_count == 5) {
    rgb_matrix_set_color_all(q, q, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, 0, 0);
    return false;
  } else if (halt_invoke_count == 4) {
    rgb_matrix_set_color_all(0, q, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, 0, 0);
    return false;
  } else if (halt_invoke_count >= 1)  {
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, q, 0);
    rgb_matrix_set_color(POSITION_Halt_Left, 0, q, 0);
    return false;
  }

  // if run display terminate here
  return false;
}

layer_state_t layer_state_set_exec_halt(const layer_state_t state) {
  // if enable nothig to do
  if (virt_layer_state_cmp(state, VIRT_LAYER_Firmware) == true) return state;

  halt_request0 = false;
  halt_request1 = false;
  halt_request2 = false;

  const fast_timer_t now = timer_read_fast();

  halt_invoke_count = 0;
  halt_invoke_reset_trigger = now + (UINT32_MAX / 2) - 1;
  exec_halt_trigger = now + (UINT32_MAX / 2) - 1;

  return state;
}

void housekeeping_task_exec_halt(void) {
  const fast_timer_t now = timer_read_fast();

  if (timer_expired_fast(now, halt_invoke_reset_trigger)) {
    halt_invoke_reset_trigger = now + (UINT32_MAX / 2) - 1;

    // reset invoke
    halt_invoke_count = 0;
  }
  
  if ((halt_request0 && halt_request1 && halt_request2) == false) return;
  
  if (timer_expired_fast(now, exec_halt_trigger) == false) return;
  exec_halt_trigger = now + (UINT32_MAX / 2) - 1;

  // do halt 
  STATUS_LED_1(true);
  STATUS_LED_2(true);

  // matrix gpio stop (from matrix.c)
  mcp23018_set_config(MCP23018_DEFAULT_ADDRESS, mcp23018_PORTA, ALL_INPUT);
  mcp23018_set_config(MCP23018_DEFAULT_ADDRESS, mcp23018_PORTB, ALL_INPUT);
  mcp23018_set_output_all(MCP23018_DEFAULT_ADDRESS, ALL_LOW, ALL_LOW);
  //mcp23018_set_output(MCP23018_DEFAULT_ADDRESS, mcp23018_PORTA, 0b00000000);
  //mcp23018_set_output(MCP23018_DEFAULT_ADDRESS, mcp23018_PORTB, 0b00000000);
  
  // to analog
  palSetPadMode(GPIOB, 10, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 11, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 12, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 13, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 14, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 15, PAL_MODE_INPUT_ANALOG);
  
  palSetPadMode(GPIOA, 0, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 1, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 2, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 3, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 6, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 0, PAL_MODE_INPUT_ANALOG);
  
  // rgb kill
  is31fl3731_select_page(1, IS31FL3731_COMMAND_FUNCTION);
  is31fl3731_write_register(1, IS31FL3731_FUNCTION_REG_SHUTDOWN, 0x00);

  is31fl3731_select_page(0, IS31FL3731_COMMAND_FUNCTION);
  is31fl3731_write_register(0, IS31FL3731_FUNCTION_REG_SHUTDOWN, 0x00);

  // trackball sensor reset powersave
  uint8_t disable_protect[3] = {0x01, 0x09 | WRITE_REG_BIT, 0x5A}; // Disable write protection
  uint8_t sw_reset[3] = {0x01, 0x06 | WRITE_REG_BIT, 0x80};        // Software reset
  uint8_t power_down[3] = {0x01, 0x06 | WRITE_REG_BIT, 0x08};      // power down
  
  i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, disable_protect, 3, NAVIGATOR_TRACKBALL_TIMEOUT);
  wait_ms(10);
  i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, sw_reset, 3, NAVIGATOR_TRACKBALL_TIMEOUT);
  wait_ms(10);
  i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, power_down, 3, NAVIGATOR_TRACKBALL_TIMEOUT);
  wait_ms(10);

  // trackball bridge disable (sci18is606 idle)
  uint8_t clr_int[1] = {SCI18IS606_CLR_INT};
  uint8_t idle_mode[1] = {0xF2};
  
  i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, clr_int, 1, NAVIGATOR_TRACKBALL_TIMEOUT);
  wait_ms(10);
  
  i2c_transmit(NAVIGATOR_TRACKBALL_ADDRESS, idle_mode, 1, NAVIGATOR_TRACKBALL_TIMEOUT);
  wait_ms(10);

  // trackpad force power-down
  cirque_gen6_write_reg(0x200A0408, 0x01);
  wait_ms(10);

  // i2c disable from voyager.c
  i2cStop(&I2CD1);
  wait_ms(10);
  
  //palSetLineMode(B6, PAL_MODE_INPUT);
  //palSetLineMode(B7, PAL_MODE_INPUT);
  palSetPadMode(GPIOB, 6, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 7, PAL_MODE_INPUT_ANALOG);
  wait_ms(10);
  
  STATUS_LED_1(false);
  STATUS_LED_2(true);
  
  usbDisconnectBus(&USB_DRIVER);
  usbStop(&USB_DRIVER);
  
  chSysLock();
  
  // usb unit disable
  USB->CNTR = USB_CNTR_FRES   | 
              USB_CNTR_PDWN   | 
              USB_CNTR_FSUSP  | 
              USB_CNTR_LPMODE;
  
  RCC->APB1RSTR |= RCC_APB1RSTR_USBRST;
  wait_ms(2);
  
  RCC->APB1ENR &= ~RCC_APB1ENR_USBEN;

  // DM DP to Analog
  palSetPadMode(GPIOA, 11, PAL_MODE_INPUT_ANALOG);  // DM
  palSetPadMode(GPIOA, 12, PAL_MODE_INPUT_ANALOG);  // DP

  // tie low, block re-detect (not work)
  //palSetPadMode(GPIOA, 12, PAL_MODE_OUTPUT_OPENDRAIN | PAL_STM32_OSPEED_LOW);
  //palWritePad(GPIOA, 12, 0);
  
  // core clock low down (ai gen)
  RCC->CR |= RCC_CR_HSION;                    // HSI enable
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);     // HSI wait
      
  RCC->CFGR &= ~RCC_CFGR_SW;                  // SYSCLK = HSI (SW=00)
  while ((RCC->CFGR & RCC_CFGR_SWS) != 0);    // wait fot change
      
  RCC->CR &= ~RCC_CR_PLLON;                   // PLL stop
  while (RCC->CR & RCC_CR_PLLRDY);            // wait for PLL stop

  RCC->CR &= ~RCC_CR_HSEON;                   // HSE stop
  while (RCC->CR & RCC_CR_HSERDY);            // wait
      
  // Flash Wait State to 0（8MHz）
  FLASH->ACR &= ~FLASH_ACR_LATENCY;
  
  // prepare standby
  PWR->CR |= PWR_CR_CWUF;          // Wakeup clear
  PWR->CR |= PWR_CR_PDDS;          // Standby mode（PDDS = 1）
  PWR->CR |= PWR_CR_LPDS;          // low power（LPDS = 1）
  
  // AHB prescale /512 to 15.625KHz
  RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE) | RCC_CFGR_HPRE_DIV512;

  // kill clock
  //RCC->AHBENR = 0;
  //RCC->APB1ENR = 0;
  //RCC->APB2ENR = 0;
      
  chSysUnlock();
  
  // 72 -> 0.015625 1000 000 -> 217
  wait_us(217);

  // stop status LED
  palSetPadMode(GPIOB, 5, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 4, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB, 3, PAL_MODE_INPUT_ANALOG);
  
  // chSysHalt is while (true) with debug system
  // use normal while true

  // from voyager.c
  // void mcu_reset(void)
  // set reset without bootloader
  // A8 -> level sense & charge
  // A9 -> discharge via R
  gpio_set_pin_output_push_pull(A9);
  gpio_set_pin_output_push_pull(A8);
  gpio_write_pin_low(A8);
  gpio_write_pin_low(A9);
  // ---- keep drive low ----
  
  // hang-up
  __disable_fault_irq();
  __disable_irq();

  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;   // Deep Sleep
  
  __DSB();
  __ISB();
  while (true) {
    __WFI();
    __WFI();
    __WFI();
    
    // test for non resrart
    // setup LED & disp
    gpio_set_pin_output(B5);
    gpio_set_pin_output(B4);
    
    STATUS_LED_1(true);
    STATUS_LED_2(true);

    // trap
    while (true);
    while (true);
    while (true);
  }
  
  return;
}

