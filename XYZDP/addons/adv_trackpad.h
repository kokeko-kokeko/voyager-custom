#pragma once

#define AUTO_MOUSE_TIME_TRACKPAD 751

void keyboard_post_init_adv_trackpad(void);
void post_process_record_adv_trackpad(uint16_t keycode, keyrecord_t *record);
void housekeeping_task_adv_trackpad(void);
