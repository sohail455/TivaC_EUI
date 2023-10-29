/******************************************************************************/
/*                                                                            */
/* !Layer           : General Functions (Service Folder)                      */
/*                                                                            */
/* !Module          : Delay                                                   */
/* !Description     : Functions to delay in milli/microseconds                */
/*                                                                            */
/* !File            : Delay.h                                                 */
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
#ifndef DELAY_H_
#define DELAY_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "std_types.h"

/******************************************************************************/
/************************** Function Implementations **************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Creates millisecond delays                                 */
/*! \return        None                                                       */
/*! \arguments     Copy_u32DelayMS      Amount of delay in millisecond        */
/******************************************************************************/

void delay_ms(uint32_t Copy_u32DelayMS);

/******************************************************************************/
/*! \Description : Creates microsecond delays                                 */
/*! \return        None                                                       */
/*! \arguments     Copy_u32DelayUS      Amount of delay in microsecond        */
/******************************************************************************/

void delay_us(uint32_t Copy_u32DelayUS);

#endif /* 4_LIB_DELAY_H_ */
