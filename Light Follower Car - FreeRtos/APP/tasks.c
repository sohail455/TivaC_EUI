/*
 * tasks.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Mazen
 */

#include "tasks.h"

extern uint16_t Glob_TimeCount;
extern uint8_t Glob_u8DistanceFlag;

uint8_t Glob_u8ObstacleState;
uint8_t Glob_u8ObstacleCounter;
uint8_t Glob_u8ObstacleTaskFlag;

uint16_t Glob_u16Difference = 0;

uint8_t Glob_u8Sw1 = 0;
uint8_t Glob_u8Sw2 = 0;

TaskHandle_t ultrasonic_h;
TaskHandle_t ldr_h;
TaskHandle_t lcd_h;
TaskHandle_t motors_h;
TaskHandle_t sys_h;

void tasks_modulesInit(void)
{
    PLL_Init();
    LDR_vidInit();
    LCD_vidInit();
    Button_vidInit();
    LEDs_init();
//    Temperature_vidInit();
    Ultrasonic_vidInit();
    motor_initialisation();
}

void button_scan(void)
{
    if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High)
    {
        while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_0) == Button_High){};
        Glob_u8Sw1 = 1;
        Glob_TimeCount = 0;
    }

    if(Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High)
    {
        while (Button_vidGetButtonValue(BUTTON_PORT, BUTTON_1) == Button_High){};
        Glob_u8Sw1 = 0;
    }

    if (Glob_TimeCount % 60 == 0 && Glob_TimeCount > 0)
    {
        Glob_u8Sw1 = 0;
    }
}
