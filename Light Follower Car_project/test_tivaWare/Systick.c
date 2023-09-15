/*
 * Systick.c
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */
#include "Systick.h"
#include "tm4c123gh6pm.h"
#define NULL (void *)0


volatile void (*g_ptr)(void)= NULL ;

void Sys_delay(unsigned long delay)
{
    NVIC_ST_CTRL_R = 0x00;
    NVIC_ST_RELOAD_R = SYSTICK_MILI * delay;

    NVIC_ST_CTRL_R = 0x03;
}

void Systick_Handler(void){


}


void Systick_SetCallBack(void (*g_ptr)(void));

