/*
 * Ultrasonoc.c
 *
 *  Created on: Sep 9, 2023
 *      Author: HOSSAM
 */
#include <stdint.h>
#include"tm4c123gh6pm.h"
#include"Platform_Types.h"
#include"Bit_Math.h"
#include"MCAL/GPIO/GPIO_Interfaces.h"
#include"MCAL/GPTM/Timer.h"
#include "Ultrasonic.h"
#include <math.h>
#include"MCAL/SYSTICK/Gpt.h"

void _delay_ms(u32 n)
{
    u32 i,j;
    for(i=0; i<n ; i++)
        for(j=0;j<3180;j++)
        {}
}

void _delay_us(u32 n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        {}
}

volatile f32 Rise, Fall,Difference;                  /*to get rising and falling,Difference between them*/

f32 Distance,Period = 0U;

/*private function for triger the ultra sonic used in Ultasoic.c only*/
void Triger(void);


/* *************************************************
 *             Function Definition
 * ************************************************/


/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*ULTRASONIC initialization function*/
/*INPUTS: NONE*/
/*OUTPUTS: NONE*/
/*Description: Initializes the GPIO PIN C5 for trigeer  C4 For timerInput cptaure*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
void Ultrasonic_INIT(void)
{
    SYSCTL_RCGCWTIMER_R |= 0x01;        // Enable clock for Wide Timer 0
    SYSCTL_RCGCGPIO_R |= 0x04;          // Enable clock for GPIO Port A

    GPIO_PORTC_DIR_R &=~0x10;
    GPIO_PORTC_DIR_R |=0x20;
    GPIO_PORTC_AFSEL_R |= 0x10;         // Enable alternate function on PA6
    GPIO_PORTC_PCTL_R |= 0x00070000;    // Select WT0CCP0 function on PA6
    GPIO_PORTC_DEN_R |=0x30;


    WTIMER0_CTL_R &= ~TIMER_CTL_TAEN;   // Disable Wide Timer 0A during setup
    WTIMER0_CFG_R = 0x04;               // Configure Wide Timer 0 as 32-bit timer
    WTIMER0_TAMR_R = (TIMER_TAMR_TACMR | TIMER_TAMR_TAMR_CAP); // Configure capture mode

    // Configure the event to trigger the timer capture
    WTIMER0_CTL_R |= TIMER_CTL_TAEVENT_BOTH;  // Positive edge trigger event
    WTIMER0_CTL_R &= ~TIMER_CTL_TAPWML;      // Capture the full timer value

    WTIMER0_IMR_R |= TIMER_IMR_CAEIM;    // Enable capture event interrupt
    WTIMER0_TAV_R = 0;                   // Clear timer value register
    WTIMER0_CTL_R |= TIMER_CTL_TAEN;     // Enable Wide Timer 0A
}


/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*TRIGER  function*/
/*INPUTS: NONE*/
/*OUTPUTS: NONE*/
/*Description: fUNCTION THAT GIVE PLUSE FOR 10US THEN MAKE IT LOW TO TRIGEER ULRASONIC*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
void Triger(void)
{ /* Make the pulse for triggering the sound wave */
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN5, GPIO_PIN_LOW);
    _delay_us(2);
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN5, GPIO_PIN_HIGH);
    _delay_us(10);
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN5, GPIO_PIN_LOW);
}


/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*GETDISTANCE  function*/
/*INPUTS: NONE*/
/*OUTPUTS: UINT32 DISTANCE*/
/*Description: fUNCTION RETURN DISTANCE MEASURE BY ULTRASONIC USING PULLING METHOD*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
u32 Get_Distance(void)
{
    SysTick_Stop();
    Triger();
    WTIMER0_TAV_R = 0;
    while(!GET_BIT(WTIMER0_RIS_R,2));
    SET_BIT(WTIMER0_ICR_R,2);               /*clear intereput flag of capture mode*/
    Rise = WTIMER0_TAR_R;
    while(!GET_BIT(WTIMER0_RIS_R,2));
    Fall = WTIMER0_TAR_R;
    SET_BIT(WTIMER0_ICR_R,2);              /*clear intereput flag of capture mode*/
    Difference = Fall - Rise;
    Period = Difference / 16000000.0;      /*divided by clcok to get time*/
    Distance = (Period * 34000U) / 2U;/*distance=time*speed but distance we get is whne go and return so divided it by 2*/
    SysTick_Start(10);
    return Distance;
}

