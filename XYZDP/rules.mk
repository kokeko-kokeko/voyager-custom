CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = navigator_trackball


BOOTMAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
RGBLIGHT_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no

DEBOUNCE_TYPE = asym_eager_defer_pk
EEPROM_DRIVER = transient

KEY_OVERRIDE_ENABLE = yes
NKRO_ENABLE = yes
OS_DETECTION_ENABLE = yes
RGB_MATRIX_ENABLE = yes

SRC += addons/adv_mouse.c
SRC += addons/fade_matrix.c
SRC += addons/firmware_map.c
SRC += addons/ime_state_sync.c
SRC += addons/overlay_layer_mod.c
SRC += ../addons/status_led.c

LTO_ENABLE = yes
EXTRAFLAGS += -flto -O3
EXTRAFLAGS += -Werror
EXTRAFLAGS += -march=armv7e-m
EXTRAFLAGS += -mcpu=cortex-m4
EXTRAFLAGS += -mfloat-abi=hard
EXTRAFLAGS += -mfpu=fpv4-sp-d16
EXTRAFLAGS += -mthumb 
EXTRAFLAGS += -fsingle-precision-constant 

