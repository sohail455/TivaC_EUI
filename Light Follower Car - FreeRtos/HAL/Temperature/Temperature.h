/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : Temperature                                             */
/* !Description     : Temperature Header File                                 */
/*                                                                            */
/* !File            : Temperature.h                                           */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous car Project @EME - EUI                       */
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
/* !Designed by     : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/* !Coded by        : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

#ifndef HAL_TemperatureERATURE_Temperature_H_
#define HAL_TemperatureERATURE_Temperature_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "../../GeneralFunctions/std_types.h"

/******************************************************************************/
/************************* Temperature Functions ******************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize the internal temperature sensor                 */
/*! \return        None                                                       */
/*! \arguments     None                                                       */
/******************************************************************************/

void Temperature_vidInit(void);

/******************************************************************************/
/*! \Description : Retrieves temperature from internal sensor                 */
/*! \return        Loc_u16Read  Pointer to a variable holds sensor reading    */
/*! \arguments     None                                                       */
/******************************************************************************/

void Temperature_vidGetTemperature(uint16_t *Loc_u16Read);

#endif /* HAL_TemperatureERATURE_Temperature_H_ */
