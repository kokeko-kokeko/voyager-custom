CONSOLE_ENABLE = no
COMMAND_ENABLE = no


SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
PRECISION_TRACKPAD_ENABLE = yes
PRECISION_TRACKPAD_DRIVER = navigator_trackpad

OS_DETECTION_ENABLE = yes

SRC += qmk_additional_callbacks.c

SRC += addons/color_palette_voyager.c
SRC += addons/connection_layer_os_swap_status.c
SRC += addons/fade_matrix.c
SRC += addons/firmware_map_voyager.c
SRC += addons/flexible_behavior_os_locale_voyager.c
SRC += addons/flexible_behavior_os_locale.c
SRC += addons/get_pos_from_keyrecord_voyager.c
SRC += addons/ime_state_sync_voyager.c
SRC += addons/ime_state_sync.c
SRC += addons/layer_mod_overlay_voyager.c
SRC += addons/mouse_button_indicator_voyager.c
SRC += addons/pos_tap_hold_overlay_voyager.c
SRC += addons/status_led_voyager.c

EXTRAFLAGS += -flto=auto -O3
EXTRAFLAGS += -Werror
EXTRAFLAGS += -march=armv7e-m+fp
EXTRAFLAGS += -mtune=cortex-m4
EXTRAFLAGS += -mcpu=cortex-m4
EXTRAFLAGS += -mfloat-abi=hard
EXTRAFLAGS += -mfpu=fpv4-sp-d16
EXTRAFLAGS += -mthumb 
EXTRAFLAGS += -fsingle-precision-constant 
EXTRAFLAGS += -fstack-protector-strong
EXTRAFLAGS += -fstack-clash-protection

