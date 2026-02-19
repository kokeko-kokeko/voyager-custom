#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "layer_num.h"

#include "addons/firmware_halt_map.h"

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
  
  POSITION_Halt = 26
};

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

  rgb_matrix_set_color_all(0, 0, 0);

  //layer indication
  rgb_matrix_set_color(24, f, f, 0);
  rgb_matrix_set_color(25, f, f, 0);
  //rgb_matrix_set_color(44, f, f, 0);
  //rgb_matrix_set_color(45, f, f, 0);
  rgb_matrix_set_color(50, q, q, 0);
  rgb_matrix_set_color(51, q, 0, 0);
  
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

bool firmware_map_enter_hue_keyrecord(const keyrecord_t * const record) {
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
  layer_on(LAYER_Set_Hue);

  // default false
  return false;
}

bool firmware_map_enter_halt_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;

  if (record->event.pressed) {
    // press
      
    return false;
  }
    
  const fast_timer_t now = timer_read_fast();

  // release
  static fast_timer_t release_time = 0;
  static uint8_t release_count = 0;
    
  if (TIMER_DIFF_FAST(now, release_time) >= 1000) {
    // single release (far from previous release)
    release_time = now;
    release_count = 1;
      
    return false;
  }

  // multi release
  release_time = now;
  if (release_count != 0) release_count++;

  if (3 <= release_count) {
    // both on Hue for exit key
    layer_state_t layer_mask = 
      ((layer_state_t)1 << LAYER_Set_Hue)   |
      ((layer_state_t)1 << LAYER_Halt_Mask);
    layer_or(layer_mask);
      
    return false;
  }

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
    ((layer_state_t)1 << LAYER_Firmware)  |
    ((layer_state_t)1 << LAYER_Set_Hue)   |
    ((layer_state_t)1 << LAYER_Set_Sat)   |
    ((layer_state_t)1 << LAYER_Set_Val)   |
    ((layer_state_t)1 << LAYER_Set_Speed) |
    ((layer_state_t)1 << LAYER_Halt_Mask);
  layer_mask = ~layer_mask;
  layer_and(layer_mask);

  status_led(0b1111, led_pattern_oneshot);

  // default false
  return false;
}

// safety flags
static volatile bool halt_request0 = false;
static volatile bool halt_request1 = false;
static volatile bool halt_request2 = false;
static fast_timer_t halt_map_trigger = (UINT32_MAX / 2) - 1;

bool halt_map_main_keyrecord(const keyrecord_t * const record) {
  if (record == NULL) return false;
  if (record->event.pressed == true) return false;

  uint8_t pos = get_pos_from_keyrecord(record);
  if (FADE_MATRIX_POSITION_COUNT <= pos) return false;
      
  if (pos == POSITION_Halt) {
    // release
    halt_request0 = true;
    halt_request1 = true;
    halt_request2 = true;
    halt_map_trigger =  timer_read_fast() + 997;
      
    clear_keyboard();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    rgb_matrix_disable_noeeprom();

    // halt status
    STATUS_LED_1(true);
    STATUS_LED_2(true);
    
    return false;
  }

  // default false
  return false;
}

void housekeeping_task_halt_map(void) {
  if ((halt_request0 && halt_request1 && halt_request2) == false) return;

  const fast_timer_t now = timer_read_fast();
  
  if (timer_expired_fast(now, halt_map_trigger) == false) return;

  // do halt
  STATUS_LED_1(false);
  STATUS_LED_2(true);
  
  usbDisconnectBus(&USB_DRIVER);
  usbStop(&USB_DRIVER);
  STATUS_LED_1(true);
  STATUS_LED_2(false);
  
  wait_ms(199);

  STATUS_LED_1(false);
  STATUS_LED_2(true);
  
  chSysLock();
  
  // core clock low down (ai gen)
  RCC->CR |= RCC_CR_HSION;                    // HSI enable
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);     // HSI wait
      
  RCC->CFGR &= ~RCC_CFGR_SW;                  // SYSCLK = HSI (SW=00)
  while ((RCC->CFGR & RCC_CFGR_SWS) != 0);    // wait fot change
      
  RCC->CR &= ~RCC_CR_PLLON;                   // PLL stop
  while (RCC->CR & RCC_CR_PLLRDY);            // wait for PLL stop
      
  // Flash Wait State to 0（8MHz must）
  FLASH->ACR &= ~FLASH_ACR_LATENCY;

  // AHB prescale /8 to 1MHz
  RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE) | RCC_CFGR_HPRE_DIV8;
      
  chSysUnlock();
      
  wait_ms(11);  

  STATUS_LED_1(false);
  STATUS_LED_2(false);
      
  chSysHalt("ready for disconnect");
      
  // hang-up
  while (true);
  
  return;
}

void set_layer_color_halt_map(void) {
  const uint8_t f = rgb_matrix_get_val();
  const uint8_t h = f >> 1;
  const uint8_t q = h >> 1;
  const uint8_t o = q >> 1;
  
  if (halt_request0 && halt_request1 && halt_request2) {
    rgb_matrix_set_color_all(0, 0, 0);
    return;
  }

  rgb_matrix_set_color_all(q, o, 0);

  rgb_matrix_set_color(POSITION_Halt, f, 0, 0);
  //rgb_matrix_set_color(49, hsv.v, hsv.v, 0);
  //rgb_matrix_set_color(24, 0, hsv.v, 0);
  //rgb_matrix_set_color(25, 0, hsv.v, 0);
  rgb_matrix_set_color(50, 0, f, 0);
  //rgb_matrix_set_color(51, 0, hsv.v, 0);
}
