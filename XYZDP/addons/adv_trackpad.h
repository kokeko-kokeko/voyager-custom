#pragma once

#define AUTO_MOUSE_TIME_TRACKPAD 751

void keyboard_post_init_adv_trackpad(void);
void post_process_record_adv_trackpad(uint16_t keycode, keyrecord_t *record);
//report_mouse_t pointing_device_task_adv_trackpad(report_mouse_t mouse_report);
layer_state_t layer_state_set_adv_trackpad(layer_state_t state);
void housekeeping_task_adv_trackpad(void);
