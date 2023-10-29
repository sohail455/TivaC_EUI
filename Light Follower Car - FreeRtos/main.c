/**
 * main.c
 */

#include "APP/Light Detection/light_detection.h"
#include "APP/Collision Avoidance/collision_avoidance.h"
#include "APP/Motion Control/motion_control.h"
#include "APP/System Timer/system_timer.h"
#include "APP/Inputs/inputs.h"
#include "APP/Display/display.h"


QueueHandle_t Displaying_Q;
uint8_t motor_state = STRAIGHT;


int main(void)
{

    tasks_modulesInit();
    Display_init();
    xTaskCreate(collisionAvoidance_task, "Ultrasonic", configMINIMAL_STACK_SIZE, NULL, 2, &ultrasonic_h);
    xTaskCreate(light_detection_task, "LDR", configMINIMAL_STACK_SIZE, NULL, 2, &ldr_h);
    xTaskCreate(input_handling_task, "Button", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(motion_control_task, "Motors", configMINIMAL_STACK_SIZE, NULL, 4, &motors_h);
    xTaskCreate(Display_task, "LCD", configMINIMAL_STACK_SIZE, NULL, 1, &lcd_h);
    events = xEventGroupCreate();
    Displaying_Q = xQueueCreate(2,sizeof(Sensor_msg_t));
    vTaskStartScheduler();

    while (1)
    {
    }
}


