/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.c
 *
 * Description: Source file for the Systick driver
 *
 * Author: David & Sohail & Hossam
 *
 *******************************************************************************/
#include "Systick.h"
#include "tm4c123gh6pm.h"

/*
 * Description :
 *  function to make a delay:
 */
void Sys_delay(unsigned long delay)
{
    NVIC_ST_RELOAD_R = SYSTICK_MILI * delay;
    NVIC_ST_CTRL_R = 0x01;
    while(!(NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT));
    NVIC_ST_CTRL_R = 0x00;
}



