

#ifndef APP_SYSTEM_TIMER_SYSTEM_TIMER_H_
#define APP_SYSTEM_TIMER_SYSTEM_TIMER_H_


#include "../utilities/APP_types.h"

#define TOTAL_SYS_RUNNING_TIME_IN_SEC     60
#define SYSTEM_TIMER_TASK_PERIODICITY_MILLI_SEC    1000

#include "HAL/Motors/Motors.h"

void System_timer_task(void *pvParameters);

#endif /* APP_SYSTEM_TIMER_SYSTEM_TIMER_H_ */
