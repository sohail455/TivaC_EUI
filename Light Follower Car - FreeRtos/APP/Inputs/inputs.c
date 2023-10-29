#include "inputs.h"
void input_handling_task(void *pvParameters)
{
    TickType_t ip_handling_prev_running = xTaskGetTickCount();/*var for holding the previous running ticks count of this task */
    /*suspend the main tasks of our system till the user starts it*/
    vTaskSuspend(COLLISION_AVOIDANCE_TASK_HANDLE);
    vTaskSuspend(LIGHT_DETECTION_TASK_HANDLE);
    vTaskSuspend(MOTION_CONTROL_TASK_HANDLE);

    while (1)
    {
        if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High) /*check if the start button (switch 0) is pressed*/
        {
            while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High){};
            xTaskCreate(System_timer_task, "Timer", configMINIMAL_STACK_SIZE, NULL, 5, &SYSTME_TIMER_TASK_HANDLE);
            vTaskResume(COLLISION_AVOIDANCE_TASK_HANDLE);
            vTaskResume(LIGHT_DETECTION_TASK_HANDLE);
            vTaskResume(MOTION_CONTROL_TASK_HANDLE);
        }

        if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High)/*check if the stop button (switch 1) is pressed*/
        {
            while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High){};
            vTaskDelete(SYSTME_TIMER_TASK_HANDLE);
            vTaskSuspend(COLLISION_AVOIDANCE_TASK_HANDLE);
            vTaskSuspend(LIGHT_DETECTION_TASK_HANDLE);
            vTaskSuspend(MOTION_CONTROL_TASK_HANDLE);
            current_direction(STOP);
        }
        vTaskDelayUntil(&ip_handling_prev_running, pdMS_TO_TICKS(INPUT_HANDLING_TASK_PERIODICITY_MILLI_SEC));
    }

}
