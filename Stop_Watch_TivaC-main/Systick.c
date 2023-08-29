/*
 * Systick.c
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */
#include "Systick.h"
#include "tm4c123gh6pm.h"
#include "Std_Types.h"

volatile void (* g_ptr)(void) = NULL;

/* Systick initializations */
void Sys_init(u32 delay)
{
    NVIC_ST_CTRL_R = 0x00;
    NVIC_ST_RELOAD_R = SYSTICK_MILI * delay;
    NVIC_ST_CTRL_R = 0x03;
}

void Systick_Handller(void)
{
    if(g_ptr != NULL)
    {
        (* g_ptr)();
    }
}

void Systick_SetCallBack(void (* copy_ptr)(void))
{
    g_ptr=copy_ptr;
}


