#include "system_timer.h"

void System_timer_task(void *pvParameters)
{
    uint8_t time_count = 0; /*current seconds' count */
    TickType_t timer_prev_running;  /*var for holding the previous running ticks count of this task */
    Sensor_msg_t current_seconds_msg={0x00,SECONDS_MESSAGE_ID}; /*msg holds the current seconds to be send at displaying queue*/
    timer_prev_running = xTaskGetTickCount();/*get the tick counts at the first exec of this task*/
    while (1)
    {
        time_count++; /*increment the current seconds*/
        current_seconds_msg.reading=time_count; /*update the current seconds reading*/
        xQueueSend(Displaying_Q,( void * ) &current_seconds_msg, 0);/*send the message to the displaying queue*/
        if (time_count == TOTAL_SYS_RUNNING_TIME_IN_SEC) /*check if the time reaches the predefined total execution time */
        {

            time_count = 0; /*redundant?*/
            /*suspend all systems' tasks*/
            vTaskSuspend(COLLISION_AVOIDANCE_TASK_HANDLE);
            vTaskSuspend(LIGHT_DETECTION_TASK_HANDLE);
            vTaskSuspend(MOTION_CONTROL_TASK_HANDLE);

            current_direction(STOP);/*stop the motors*/
            vTaskDelete(NULL);/*delete the system timer task */
        }
        vTaskDelayUntil(&timer_prev_running, pdMS_TO_TICKS(SYSTEM_TIMER_TASK_PERIODICITY_MILLI_SEC));
    }
}
