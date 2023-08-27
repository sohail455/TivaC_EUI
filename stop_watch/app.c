/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:   David & Sohail & Hossam
 *         File:  app.c
 *        Layer:  APP
 *       Module:  app
 *      Version:  1.00
 *
 *  Description:  Source file of StopWatch
 *
 *********************************************************************************************************************/
#include "lcd.h"
#include "Keypad.h"
#include "Systick.h"
#include "EXTI_Interface.h"
#include "GPIO_Interface.h"
#include "tm4c123gh6pm.h"

volatile u32 seconds = 0;
volatile u32 minutes = 0;
volatile u32 hours = 0;
volatile u8 pause_flag=0x00;
volatile u32 systikc_value = 0;
u8 curr_row=0;
u8 curr_col=0;
u8 lap_count=0;

typedef enum
{
    COUNT,PAUS,reset,LABING
}StopWatch_states;

volatile StopWatch_states current_state=COUNT;

void increment_seconds(void)
{
    seconds++;
    if(seconds == 60)
    {
        seconds=0;
        minutes++;
    }
    if(minutes == 60)
    {
        minutes=0;
        hours++;
    }
}

void delay_ms(u32 m)
{
    u32 delay=0;
    for(delay=0; delay < m * 762; delay++);
}

void start_app(void)
{
    GPIO_Config_t config[2] = {{GPIO_PORTF,GPIO_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                               {GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}
    };
    GPIO_Init(config, 2);
    GPIO_PORTF_IS_R &= ~(0x11) ;
    GPIO_PORTF_IEV_R &= ~(0x11) ;
    GPIO_PORTF_IBE_R &= ~(0x11) ;
    GPIO_PORTF_IM_R |= 0x11 ;
    NVIC_EN0_R |=(1<<30);
    Systick_SetCallBack(increment_seconds);
    Sys_init(1000);
    LCD_init();
    __asm(" CPSIE I");
    while(1)
    {
        switch(current_state)
        {
        case COUNT:
            LCD_moveCursor(curr_row, curr_col);
            LCD_intgerToString(minutes/10);
            LCD_intgerToString(minutes%10);
            LCD_displayCharacter(':');
            LCD_intgerToString(seconds/10);
            LCD_intgerToString(seconds%10);
            break;
        case PAUS:
            break;
        case reset:
            seconds=0;
            minutes=0;
            hours=0;
            LCD_clearScreen();
            curr_row = 0;
            curr_col = 0;
            lap_count=0;
            current_state=COUNT;
            break;
        case LABING:
            switch (lap_count)
            {
            case 0:
                curr_row = 0;
                curr_col = 6;
                lap_count++;
                current_state=COUNT;
                break;

            case 1:
                curr_row = 1;
                curr_col = 0;
                lap_count++;
                current_state=COUNT;
                break;

            case 2:
                curr_row = 1;
                curr_col = 6;
                lap_count++;
                current_state=COUNT;
                break;

            case 3:
                curr_row = 0;
                curr_col = 0;
                lap_count=0;
                current_state=COUNT;
                break;
            }
        }
    }
}





void PORTF_HANDLER(void)
{

    if (GPIO_PORTF_MIS_R& 0x01)
    {
        if(current_state == PAUS)
        {
            current_state = reset;
        }
        else if(current_state == COUNT)
        {
            current_state=LABING;
        }
    }
    else if (GPIO_PORTF_MIS_R& 0x10)
    {
        pause_flag++;
        if(pause_flag == 1)
        {
            NVIC_ST_CTRL_R &=~(1<<0);
            current_state = PAUS;
        }
        else if(pause_flag == 2)
        {
            current_state = COUNT;
            pause_flag=0;
            NVIC_ST_CTRL_R |=(1<<0);
        }
    }
    GPIO_PORTF_ICR_R |= 0x11;
}
