#pragma once

void keyboard_post_init_adv_mouse(void);
void post_process_record_adv_mouse(uint16_t keycode, keyrecord_t *record);
report_mouse_t pointing_device_task_adv_mouse(report_mouse_t mouse_report);
layer_state_t layer_state_set_adv_mouse(const layer_state_t state);
void housekeeping_task_adv_mouse(void);
