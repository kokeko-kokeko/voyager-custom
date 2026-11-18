CONSOLE_ENABLE = no
COMMAND_ENABLE = no


SPACE_CADET_ENABLE = no


POINTING_DEVICE_DRIVER = custom

#PRECISION_TRACKPAD_ENABLE = yes
#PRECISION_TRACKPAD_DRIVER = navigator_trackpad

OS_DETECTION_ENABLE = yes

SRC += addons/exec_halt_voyager.c
SRC += addons/firmware_map_voyager.c
SRC += addons/flexible_behavior_os_locale_voyager.c
SRC += addons/flexible_behavior_os_locale.c
SRC += addons/ime_state_sync_voyager.c
SRC += addons/ime_state_sync.c

SRC += layer/layer_caps_word.c
SRC += layer/virt_layer.c

SRC += pos/get_pos_from_keyrecord_voyager.c

SRC += rgb_matrix_extra/color_palette_voyager.c
SRC += rgb_matrix_extra/fade_matrix.c
SRC += rgb_matrix_extra/layer_mod_overlay_voyager.c
SRC += rgb_matrix_extra/mouse_button_indicator_voyager.c
SRC += rgb_matrix_extra/pos_press_overlay_voyager.c

SRC += status_led/connection_layer_os_swap_status.c
SRC += status_led/status_led_voyager.c

SRC += user_extra/custom_debounce_voyager.c
SRC += user_extra/split_txn_trackball.c
SRC += user_extra/tap_hold_settings.c
SRC += user_extra/user_hooks.c

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

# reduce size
EXTRAFLAGS += -ffunction-sections -fdata-sections
EXTRALDFLAGS += -Wl,--gc-sections,-Map=$(BUILD_DIR)/$(TARGET).map,--cref

