#pragma once

#define CONNECTION_STATUS_INIT_DELAY 7499
#define CONNECTION_STATUS_PROBE_DELAY 1249

layer_state_t layer_state_set_connection_status(layer_state_t state);
void housekeeping_task_connection_status(void);