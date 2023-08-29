/*
 * Manager.c
 *
 *  Created on: Aug 28, 2023
 *      Author: eme
 */

#include "Manager.h"

volatile u32 seconds = 0;                 //Global variable for seconds that represented in LCD
volatile u32 minutes = 0;                //Global variable for minutes that represented in LCD
volatile u32 hours = 0;                 //Global variable for hours that represented in LCD
volatile u8 pause_flag=0x00;            // Variable for Pause state
volatile u32 systikc_value = 0;


u8 curr_row=0;                   // Variable for LCD rows
u8 curr_col=0;                   // Variable for LCD columns
u8 lap_count=0;                  // Variable to increase the number of laps



typedef enum                //enum for states
{
    COUNT,PAUS,reset,LABING
}StopWatch_states;

volatile StopWatch_states current_state=COUNT;     //Initialize the current state.

void Get_state (void)               //Function to determine the state using pushbutton and change LCD accordingly
{
    switch(current_state)
    {
    case COUNT:                                //Default state
        LCD_moveCursor(curr_row, curr_col);
        LCD_intgerToString(minutes/10);       //Display minutes
        LCD_intgerToString(minutes%10);
        LCD_displayCharacter(':');
        LCD_intgerToString(seconds/10);       //Display seconds
        LCD_intgerToString(seconds%10);
        break;
    case PAUS:                               // Pause state (stop counting)
        break;


    case reset:                           // Reset state and moving cursor to the starting point
        seconds=0;
        minutes=0;
        hours=0;
        LCD_clearScreen();
        curr_row = 0;
        curr_col = 0;
        lap_count=0;
        current_state=COUNT;
        break;
    case LABING:                        //Lap state handling
        switch (lap_count)              // Switch foe which lap I'll move to
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


void increment_seconds(void)      // Function to increment stop watch
{
    seconds++;
    if(seconds == 60)           // Reset seconds and increment minute every minute
    {
        seconds=0;
        minutes++;
    }
    if(minutes == 60)          // Reset minutes and increment hour every hour
    {
        minutes=0;
        hours++;
    }
}

void delay_ms(u32 m)                          // Software delay function
{
    u32 delay=0;
    for(delay=0; delay < m * 762; delay++);
}



void PORTF_HANDLER(void)               // PortF interrupt handler
{

    if (GPIO_PORTF_MIS_R& 0x01)       // Check if the PF0 is pressed
    {
        /* Logic to handle the cases as our design needs */
        if(current_state == PAUS)
        {
            current_state = reset;
        }
        else if(current_state == COUNT)
        {
            current_state=LABING;
        }
    }
    else if (GPIO_PORTF_MIS_R& 0x10)   // Check if PF4 is pressed
    {  /* Logic to handle the cases as our design needs */
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
    GPIO_PORTF_ICR_R |= 0x11;           // Clear interrupt flag for both PBs.
}


void Start_Calc()                   // Staring App function
{
    GPIO_Config_t config[2] = {{GPIO_PORTF,GPIO_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                               {GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}
    };                          // Configure two portF pin 0 and pin 4 as input, digital and pull-up
    GPIO_Init(config, 2);
    /* Register to configure portF pin0 and pin4 as negative edge interrupt */
    GPIO_PORTF_IS_R &= ~(0x11) ;
    GPIO_PORTF_IEV_R &= ~(0x11) ;
    GPIO_PORTF_IBE_R &= ~(0x11) ;
    GPIO_PORTF_IM_R |= 0x11 ;

    NVIC_EN0_R |=(1<<30);          //Allow processor to accept interrupt from portF
    Systick_SetCallBack(increment_seconds);        // Call back function for SysTick interrupt
    Sys_init(1000);
    LCD_init();

    __asm(" CPSIE I");                //Enabling global interrupt

    while(1)
    {
        Get_state() ;         // Super loop for application
    }
}



