/*
 * Tasks.c
 *
 *  Created on: 15 Sep 2023
 *      Author: pvc
 */
#include "Tasks.h"
#include "MCAL/GPIO/GPIO_Interfaces.h"
#include "HAL/MOTORS/motors.h"
#include "APP/LDR_APP/LDR_APP.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LDR/LDR.h"
#include "HAL/UltraSonic/Ultrasonic.h"
#define POSITIVE_THRESH 150
#define NEGATIVE_THRESH -150

static uint16_t left_value, right_value;
static s16 difference;
static u32 direction;
u32 distance;
static u32 obs_distance;

void delay2(u32 d)
{
    u32 i=0;
    for(i=0; i< 762*d; i++)
    {

    }
}

void ldr_swing_car_init(void)
{
    LDR_Init();
}

void ldr_swing_car(void)
{

    left_value = Ldr_getValue(LDR0);
    right_value = Ldr_getValue(LDR1);
    difference = left_value - right_value;
    if (difference > POSITIVE_THRESH)
    {
        current_direction(TURN_LEFT);
        direction = TURN_LEFT;
    }
    else if (difference < NEGATIVE_THRESH)
    {
        current_direction(TURN_RIGHT);
        direction = TURN_RIGHT;
    }
    else
    {
        current_direction(STRAIGHT);
        direction = STRAIGHT;
    }
}

s16 getDifferenceValue(void)
{
    return difference;
}

/********************************* avoid obstacles task **************************/




/******************************************************************************************/

//
void LCD_Show_T(void)
{
    LCD_moveCursor(0, 0);
    LCD_displayString("     ");
    LCD_moveCursor(0, 0);
    LCD_intgerToString(difference);

    LCD_moveCursor(0, 13);
    LCD_displayString("     ");
    LCD_moveCursor(0, 13);
    LCD_intgerToString(distance);
}

void LCD_Show_Dir(void)
{

    if (direction == STRAIGHT)
    {
        LCD_moveCursor(0, 12);
        LCD_displayCharacter('F');
    }
    else if (direction == TURN_LEFT)
    {
        LCD_moveCursor(0, 12);
        LCD_displayCharacter('L');
    }
    else if (direction == TURN_RIGHT)
    {
        LCD_moveCursor(0, 12);
        LCD_displayCharacter('R');
    }
    else
    {
        LCD_moveCursor(0, 12);
        LCD_displayCharacter('S');
    }
}

void UltraSonic_t(void)
{
    distance=Get_Distance();
    if(distance > 99)
    {
        distance = 99;
    }
    else if( distance < 1)
    {
        distance = 1;
    }
    else
    {

    }
    if(distance < 10)
    {
        LCD_clearScreen();
        LCD_moveCursor(0, 3);
        LCD_displayString("Obstacle!!");
        current_direction(STOP);
        delay2(2000);
        current_direction(BACKWARD);
        delay2(4000);
        current_direction(TURN_RIGHT);
        delay2(5000);
        LCD_clearScreen();
        LCD_moveCursor(0, 0);
    }
    else
    {

    }
}


