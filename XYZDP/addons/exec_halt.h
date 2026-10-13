#pragma once

bool exec_halt_invoke_halt_keyrecord(const keyrecord_t * const record);

bool rgb_matrix_indicators_exec_halt(void);

layer_state_t layer_state_set_exec_halt(const layer_state_t state);

void housekeeping_task_exec_halt(void);