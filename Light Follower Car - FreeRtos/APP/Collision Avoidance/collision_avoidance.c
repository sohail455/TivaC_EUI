
#include "collision_avoidance.h"
void collisionAvoidance_task(void *pvParameters)
{
    TickType_t CA_prev_running = xTaskGetTickCount(); /*var for holding the previous running ticks count of this task */
    float Local_u32Distance = 0; /*var contains the distance between the car and detected object*/
    Sensor_msg_t distance_msg={0x00,DISTANCE_MESSAGE_ID}; /*message of ultrasonic reading*/
    while (1)
    {
        Ultrasonic_vidGetDistance(&Local_u32Distance);  /*update the distance using the ultrasonic module */
        distance_msg.reading=Local_u32Distance; /*update the distance message*/
        xQueueSend(Displaying_Q,( void * ) &distance_msg, 0); /*send the distance message to the displaying queue*/
        if (Local_u32Distance <= COLLISION_DISTANCE_CM) /*check if the detected object is closer than the allowable distance */
        {
            xEventGroupSetBits(events, COLLISION_EVENT_FLAG); /*set the collision event flag*/
            xEventGroupClearBits(events, NORMAL_EVENT_FLAG);
        }
        else
        {
            xEventGroupClearBits(events, COLLISION_EVENT_FLAG);/*clear the collision event flag in case no potential collision*/
        }
        vTaskDelayUntil(&CA_prev_running, pdMS_TO_TICKS(COLLISION_AVOIDANCE_TASK_PERIODICITY_MILLI_SEC));
    }

}


