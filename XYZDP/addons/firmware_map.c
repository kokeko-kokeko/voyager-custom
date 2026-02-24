#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/firmware_map.h"

#include "addons/fade_matrix.h"
#include "addons/ime_state_sync.h"
#include "addons/status_led.h"

#include "ch.h"
#include "usb_main.h"

enum key_position {
  POSITION_JIS = 0,
  POSITION_ANSI = 6,
  POSITION_Tran_off = 1,
  POSITION_Tran_on = 7,
  POSITION_ISS_on = 3,
  POSITION_ISS_off = 9,
  POSITION_MJ_on = 5,
  POSITION_MJ_off = 11,

  POSITION_RST = 31,
  POSITION_SW_RST = 37,
  POSITION_CLEAR = 49,
  
  POSITION_Caps_Lock = 19,
  POSITION_Num_Lock = 44,
  POSITION_Scroll_Lock = 45,
  POSITION_Compose = 46,
  POSITION_Kana = 20,

  POSITION_OS1 = 22,
  POSITION_OS2 = 23,

  POSITION_Color_Palette = 50,
  POSITION_Halt = 51
};

// halt safety flags
static volatile bool halt_request0 = false;
static volatile bool halt_request1 = false;
static volatile bool halt_request2 = false;
static fast_timer_t exec_halt_trigger = (UINT32_MAX / 2) - 1;
static uint8_t halt_invoke_count = 0;
static fast_timer_t abort_halt_trigger = (UINT32_MAX / 2) - 1;

// call mouse jiggler
void mouse_jiggler_enable(void);
void mouse_jiggler_disable(void);
bool mouse_jiggler_is_enabled(void);

bool firmware_map_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == false) return false;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (FADE_MATRIX_POSITION_COUNT <= pos) return false;

  if (pos == POSITION_JIS) {
    layer_on(LAYER_Base);
    layer_off(LAYER_Base_ANSI);
        
    return false;
  }
      
  if (pos == POSITION_ANSI) {
    layer_on(LAYER_Base);
    layer_on(LAYER_Base_ANSI);
        
    return false;
  }
      
  if (pos == POSITION_Tran_off) {
    layer_on(LAYER_Base);
    layer_off(LAYER_Transition);
        
    return false;
  }
      
  if (pos == POSITION_Tran_on) {
    layer_on(LAYER_Base);
    layer_on(LAYER_Transition);
        
    return false;
  }
      
  if (pos == POSITION_ISS_on) {
    ime_state_sync_enable();
        
    return false;
  }
      
  if (pos == POSITION_ISS_off) {
    ime_state_sync_disable();
        
    return false;
  }

  if (pos == POSITION_MJ_on) {
    mouse_jiggler_enable();
        
    return false;
  }
      
  if (pos == POSITION_MJ_off) {
    mouse_jiggler_disable();
        
    return false;
  }
      
  if (pos == POSITION_RST) {
    reset_keyboard();
        
    return false;
  }
      
  if (pos == POSITION_SW_RST) {
    soft_reset_keyboard();
        
    return false;
  }
      
  if (pos == POSITION_CLEAR) {
    clear_keyboard();
    
    status_led(0b1111, led_pattern_oneshot);
        
    return false;
  }

  // default false
  return false;
}

void set_layer_color_firmware_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;
  
  if (halt_request0 && halt_request1 && halt_request2) {
    rgb_matrix_set_color_all(0, 0, 0);
    return;
  }
  
  if (halt_invoke_count == 7) {
    rgb_matrix_set_color_all(f, 0, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    return;
  } else if (halt_invoke_count == 6) {
    rgb_matrix_set_color_all(f, h, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    return;
  } else if (halt_invoke_count == 5) {
    rgb_matrix_set_color_all(f, f, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    return;
  } else if (halt_invoke_count == 4) {
    rgb_matrix_set_color_all(0, f, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, 0, 0);
    return;
  } else if (halt_invoke_count >= 1)  {
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_color(POSITION_Halt, 0, f, 0);
    return;
  }

  rgb_matrix_set_color_all(0, 0, 0);
  rgb_matrix_set_color(POSITION_Halt, 0, 0, f);

  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  //rgb_matrix_set_color(44, f, f, 0);
  //rgb_matrix_set_color(45, f, f, 0);
  
  rgb_matrix_set_color(POSITION_Color_Palette, q, q, 0);
  
  //ANSI/JIS
  if (layer_state_is(LAYER_Base_ANSI)) {
    //ANSI base enable
    rgb_matrix_set_color(POSITION_JIS, q, q, q);
    rgb_matrix_set_color(POSITION_ANSI, f, 0, 0);
  } else {
    //JIS base
    rgb_matrix_set_color(POSITION_JIS, 0, f, 0);
    rgb_matrix_set_color(POSITION_ANSI, q, q, q);
  }

  // Transition
  if (layer_state_is(LAYER_Transition)) {
    // on
    rgb_matrix_set_color(POSITION_Tran_off, q, q, q);
    rgb_matrix_set_color(POSITION_Tran_on, f, f, 0);
  } else {
    // off
    rgb_matrix_set_color(POSITION_Tran_off, 0, 0, f);
    rgb_matrix_set_color(POSITION_Tran_on, q, q, q);
  }

  // ISS system
  if (ime_state_sync_is_enabled()) {
    rgb_matrix_set_color(POSITION_ISS_on, 0, f, 0);
    rgb_matrix_set_color(POSITION_ISS_off, o, o, o);
  } else {
    //ANSI base
    rgb_matrix_set_color(POSITION_ISS_on, o, o, o);
    rgb_matrix_set_color(POSITION_ISS_off, f, f, 0);
  }

  // mouse jiggler
  if (mouse_jiggler_is_enabled()) {
    // on
    rgb_matrix_set_color(POSITION_MJ_on, 0, 0, f);
    rgb_matrix_set_color(POSITION_MJ_off, q, q, q);
  } else {
    // off
    rgb_matrix_set_color(POSITION_MJ_on, q, q, q);
    rgb_matrix_set_color(POSITION_MJ_off, f, 0, 0);
  }

  //OS detect
  RGB rgb_os = {0, 0, 0};
  switch (detected_host_os()) {
    case OS_WINDOWS:
      rgb_os.b = f;
      break;
    case OS_LINUX:
      rgb_os.g = f;
      break;
    case OS_MACOS:
      rgb_os.r = f;
      break;
    case OS_IOS:
      rgb_os.r = f;
      rgb_os.g = h;
      break;    
    case OS_UNSURE:
      rgb_os.r = f;
      rgb_os.g = f;
      break;
    default:
      rgb_os.r = f;
      rgb_os.g = f;
      rgb_os.b = f;
      break;
  }
  rgb_matrix_set_color(POSITION_OS1, rgb_os.r, rgb_os.g, rgb_os.b);
  rgb_matrix_set_color(POSITION_OS2, rgb_os.r, rgb_os.g, rgb_os.b);
  
  //reset clear
  rgb_matrix_set_color(POSITION_RST, f, 0, 0);
  rgb_matrix_set_color(POSITION_SW_RST, f, h, 0);
  rgb_matrix_set_color(POSITION_CLEAR, f, f, 0);

  //color test
  //rgb_matrix_set_color(26, f, 0, 0);
  //rgb_matrix_set_color(32, f, o, 0);
  //rgb_matrix_set_color(38, f, q, 0);
  //rgb_matrix_set_color(44, f, h, 0);

  //rgb_matrix_set_color(27, f, f, 0);
  //rgb_matrix_set_color(33, h, f, 0);
  //rgb_matrix_set_color(39, q, f, 0);
  //rgb_matrix_set_color(45, o, f, 0);
  
  //rgb_matrix_set_color(28, 0, f, 0);
  //rgb_matrix_set_color(34, 0, f, q);
  //rgb_matrix_set_color(40, 0, f, f);
  //rgb_matrix_set_color(46, 0, q, f);
  
  //rgb_matrix_set_color(29, 0, 0, f);
  //rgb_matrix_set_color(35, q, 0, f);
  //rgb_matrix_set_color(41, f, 0, f);
  //rgb_matrix_set_color(47, f, 0, q);

  led_t status = host_keyboard_led_state();

  if (status.caps_lock) {
    rgb_matrix_set_color(POSITION_Caps_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(POSITION_Caps_Lock, q, q, q);
  }

  if (status.num_lock) {
    rgb_matrix_set_color(POSITION_Num_Lock, h, 0, 0);
  } else {
    rgb_matrix_set_color(POSITION_Num_Lock, q, q, q);
  }

  if (status.scroll_lock) {
    rgb_matrix_set_color(POSITION_Scroll_Lock, 0, h, 0);
  } else {
    rgb_matrix_set_color(POSITION_Scroll_Lock, q, q, q);
  }

  if (status.compose) {
    rgb_matrix_set_color(POSITION_Compose, 0, 0, h);
  } else {
    rgb_matrix_set_color(POSITION_Compose, q, q, q);
  }

  if (status.kana) {
    rgb_matrix_set_color(POSITION_Kana, h, 0, h);
  } else {
    rgb_matrix_set_color(POSITION_Kana, q, q, q);
  }
}

bool firmware_map_enter_color_palette_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  static uint16_t press_time = 0;
    
  if (record->event.pressed) {
    // press
    press_time = record->event.time;
      
    return false;
  }

  if (TIMER_DIFF_16(record->event.time, press_time) < TAPPING_TERM) {
    // tap release
      
    return false;
  }
  
  // hold release
  layer_on(LAYER_Color_Palette);

  // default false
  return false;
}

bool firmware_map_exit_all_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  static uint16_t press_time = 0;
    
  if (record->event.pressed) {
    // press
    press_time = record->event.time;
      
    return false;
  }

  if (TIMER_DIFF_16(record->event.time, press_time) < TAPPING_TERM) {
    // tap release
      
    return false;
  }
    
  // hold release
  // off all setting layers
  layer_state_t layer_mask = 
    ((layer_state_t)1 << LAYER_Firmware)      |
    ((layer_state_t)1 << LAYER_Color_Palette);
  layer_mask = ~layer_mask;
  layer_and(layer_mask);

  status_led(0b1111, led_pattern_oneshot);

  // default false
  return false;
}

bool firmware_map_invoke_halt_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == false) return false;
  
  const fast_timer_t now = timer_read_fast();

  // release
  if (halt_invoke_count != UINT8_MAX) halt_invoke_count++;
  abort_halt_trigger = now + 1999;

  if (8 <= halt_invoke_count) {
    halt_request0 = true;
    halt_request1 = true;
    halt_request2 = true;
    exec_halt_trigger = now + 11;
    
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    rgb_matrix_disable_noeeprom();
    
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

void housekeeping_task_exec_halt(void) {
  const fast_timer_t now = timer_read_fast();
  
  if (timer_expired_fast(now, abort_halt_trigger) == true) {
    halt_invoke_count = 0;
    abort_halt_trigger = (UINT32_MAX / 2) - 1;

    // clear flag
    halt_request0 = false;
    halt_request1 = false;
    halt_request2 = false;

    // halt status
    STATUS_LED_1(false);
    STATUS_LED_2(false);
    STATUS_LED_3(false);
    STATUS_LED_4(false);
  }
  
  if ((halt_request0 && halt_request1 && halt_request2) == false) return;
  
  if (timer_expired_fast(now, exec_halt_trigger) == false) return;

  // do halt
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
  //palSetPadMode(GPIOA, 12, PAL_MODE_INPUT_ANALOG);  // DP

  // tie low, block re-detect
  palSetPadMode(GPIOA, 12, PAL_MODE_OUTPUT_OPENDRAIN | PAL_STM32_OSPEED_LOW);
  palWritePad(GPIOA, 12, 0);
  
  // core clock low down (ai gen)
  RCC->CR |= RCC_CR_HSION;                    // HSI enable
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);     // HSI wait
      
  RCC->CFGR &= ~RCC_CFGR_SW;                  // SYSCLK = HSI (SW=00)
  while ((RCC->CFGR & RCC_CFGR_SWS) != 0);    // wait fot change
      
  RCC->CR &= ~RCC_CR_PLLON;                   // PLL stop
  while (RCC->CR & RCC_CR_PLLRDY);            // wait for PLL stop
      
  // Flash Wait State to 0（8MHz）
  FLASH->ACR &= ~FLASH_ACR_LATENCY;
  
  // prepare standby
  PWR->CR |= PWR_CR_CWUF;          // Wakeup clear
  PWR->CR |= PWR_CR_PDDS;          // Standby mode（PDDS = 1）
  PWR->CR |= PWR_CR_LPDS;          // low power（LPDS = 1）

  PWR->CR &= ~PWR_CR_PLS;          // PLS clear
  PWR->CR |= PWR_CR_PLS_LEV7;      // max level
  PWR->CR |= PWR_CR_PVDE;          // enable
  
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;   // Deep Sleep
  
  // AHB prescale /512 to 15.625KHz
  RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE) | RCC_CFGR_HPRE_DIV512;
      
  chSysUnlock();
  
  // 72 -> 0.015625 1000 000 -> 217
  wait_us(217);

  STATUS_LED_1(false);
  STATUS_LED_2(false);
  
  // chSysHalt is while (true) with debug system
  // use normal while true
  
  // hang-up
  __disable_fault_irq();
  __disable_irq();
  __DSB();
  while (true) {
    __WFI();

    // test for non resrart
    STATUS_LED_1(true);
    STATUS_LED_2(true);
  }
  
  return;
}

