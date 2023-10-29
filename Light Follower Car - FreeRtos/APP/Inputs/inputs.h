#ifndef APP_INPUTS_INPUTS_H_
#define APP_INPUTS_INPUTS_H_

#include "../utilities/APP_types.h"
#include "APP/System Timer/system_timer.h"

void input_handling_task(void *pvParameters);

#define INPUT_HANDLING_TASK_PERIODICITY_MILLI_SEC    300

#endif /* APP_INPUTS_INPUTS_H_ */
