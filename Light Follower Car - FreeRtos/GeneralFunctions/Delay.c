/******************************************************************************/
/*                                                                            */
/* !Layer           : General Functions (Service Folder)                      */
/*                                                                            */
/* !Module          : Delay                                                   */
/* !Description     : Functions to delay in milli/microseconds                */
/*                                                                            */
/* !File            : Delay.c                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car Project @EME - EUI                            */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Ahmed ABDULAZEEM                 !Date : SEP 09, 2023   */
/* !Coded by        : Ahmed ABDULAZEEM                 !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "Delay.h"


/******************************************************************************/
/************************** Function Implementations **************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Creates millisecond delays                                 */
/*! \return        None                                                       */
/*! \arguments     Copy_u32DelayMS      Amount of delay in millisecond        */
/******************************************************************************/

void delay_ms(uint32_t Copy_u32DelayMS)
{
    volatile uint32_t Local_u32Ticks;
    Local_u32Ticks = 1600 * Copy_u32DelayMS;
    while (Local_u32Ticks)
    {
        Local_u32Ticks--;
    }
}

/******************************************************************************/
/*! \Description : Creates microsecond delays                                 */
/*! \return        None                                                       */
/*! \arguments     Copy_u32DelayUS      Amount of delay in microsecond        */
/******************************************************************************/

void delay_us(uint32_t Copy_u32DelayUS)
{
    uint32_t Local_u32OuterIterator;
    uint32_t Local_u32InnerIterator;
    for(Local_u32OuterIterator = 0; Local_u32OuterIterator < Copy_u32DelayUS; Local_u32OuterIterator++)
        for(Local_u32InnerIterator = 0; Local_u32InnerIterator < 3; Local_u32InnerIterator++)
        {};
}
