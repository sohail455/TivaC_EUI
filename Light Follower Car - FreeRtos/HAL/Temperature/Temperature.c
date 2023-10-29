/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : Temperature                                             */
/* !Description     : Temperature implementation                              */
/*                                                                            */
/* !File            : Temperature.c                                           */
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
/* !Designed by     : Ahmed RAGAB                      !Date : SEP 09, 2023   */
/* !Coded by        : Ahmed RAGAB                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "Temperature.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../GeneralFunctions/std_types.h"

/******************************************************************************/
/************************* Temperature Functions ******************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize the internal temperature sensor                 */
/*! \return        None                                                       */
/*! \arguments     None                                                       */
/******************************************************************************/

void Temperature_vidInit(void)
{
    ADC_vidInit(SEQ_3);
}

/******************************************************************************/
/*! \Description : Retrieves temperature from internal sensor                 */
/*! \return        Loc_u16Read  Pointer to a variable holds sensor reading    */
/*! \arguments     None                                                       */
/******************************************************************************/

void Temperature_vidGetTemperature(uint16_t *Loc_u16Read)
{
    *Loc_u16Read = ADC_u32ReadChannel(SEQ_3);
}

