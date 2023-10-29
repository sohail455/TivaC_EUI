#include "motion_control.h"

void motion_control_task(void *pvParameters)
{
    EventBits_t events_flags; /*var for holding the current event */
    while(1)
    {
        events_flags = xEventGroupWaitBits(events, NORMAL_EVENT_FLAG|COLLISION_EVENT_FLAG|LIGHT_DETECTED_EVENT_FLAG, 1, 0, portMAX_DELAY);/*wait until triggering one event from the three main events in our car: NORMAL, LIGHT DETECTED and COLLISION DETECTED*/
        if ((events_flags & COLLISION_EVENT_FLAG) == COLLISION_EVENT_FLAG) /*check if the triggered event is the collision detection event*/
        {
            LED_turnOn(PURPLE_LED);
             current_direction(BACKWARD);
            vTaskDelay(pdMS_TO_TICKS(1000));
            current_direction(TURN_RIGHT);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else
        {
            if ((events_flags & LIGHT_DETECTED_EVENT_FLAG) == LIGHT_DETECTED_EVENT_FLAG)/*check if the triggered event is the light detection event*/
            {
                LED_turnOn(GREEN_LED);
            }
            else if ((events_flags & NORMAL_EVENT_FLAG ) == NORMAL_EVENT_FLAG )/*check if the triggered event is normal movement event */
            {
                LED_turnOn(RED_LED);
            }
            current_direction(motor_state);
        }
    }
}
