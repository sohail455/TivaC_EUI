/*
 * Schedular.c
 *
 *  Created on: Sep 10, 2023
 *      Author: eme
 */

#include "../Platform_Types.h"
#include "Scheduler.h"
#include "../tm4c123gh6pm.h"
#include "../Bit_Math.h"
#include "MCAL/SYSTICK/Gpt.h"
#include "../std_types.h"
#include "HAL/Buttons/Buttons.h"
#include"MCAL/GPIO/GPIO_Interfaces.h"
#include "HAL/MOTORS/motors.h"
#include "HAL/LCD/lcd.h"
u16 Priority =0;
u8 CountR=0;
u8 CountG=0;
u8 CountB=0;
u8 flagR=0;
u8 flagG=0;
u8 flagB=0;
u8 Off=0;
u8 off_flag=0;

u8 start_state=0;
u8 stop_state=0;

Task_TCB TASKS[NUM_OF_TASKS];

void sheduler_init(void)
{
    SysTick_Start(Ticks_Time);
}


void create_task (void (*TaskFunction)(), u32 periodicity ) {
    TASKS[Priority].Periodicity = periodicity;
    TASKS[Priority].TaskFunction = TaskFunction;
    Priority++;
}

void tasks_scheduler(void) {
    // Loop through tasks
    //uint32_t i;
    while (1)
    { /*if start button is pressed  it inilaize systick*/
        GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN0, &start_state);
        GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN4, &stop_state);
        if(start_state == BUTTON_PRESSED)
        {
            SysTick_Start(Ticks_Time);
            LCD_clearScreen();
        }
        /*if stop button is pressed  it disable systick*/
        else if(stop_state == BUTTON_PRESSED)
        {
            SysTick_Stop();
            LCD_clearScreen();
            LCD_moveCursor(0, 5);
            LCD_displayString("STOP!!");
            current_direction(STOP);
        }
        else
        {

        }

        if (flagR)
        {
            TASKS[0].TaskFunction();
            CountR=0;
            flagR=0;
        }
        if (flagG)
        {
            TASKS[1].TaskFunction();
            CountG=0;
            flagG=0;
        }
        if (flagB)
        {
            TASKS[2].TaskFunction();
            CountB=0;
            flagB=0;
        }
        if (off_flag)
        {
            SysTick_Stop();
            LCD_clearScreen();
            LCD_moveCursor(0, 5);
            LCD_displayString("STOP!!");
            current_direction(STOP);
        }


    }
}

void Systick_Handler (void)
{
    CountR++;
    CountG++;
    CountB++;
    Off++;
    if (CountR >=TASKS[0].Periodicity)
        flagR=1;
    if (CountG >=TASKS[1].Periodicity)
        flagG=1;
    if (CountB >=TASKS[2].Periodicity)
        flagB=1;
    /*if it become 1 min it make off flag that disable systick*/
    if(Off >= 6000)
    {
        off_flag = 1;
    }
}
