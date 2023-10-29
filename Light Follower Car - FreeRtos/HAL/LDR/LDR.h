/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : LDR                                                     */
/* !Description     : Read light intensity                                    */
/*                                                                            */
/* !File            : LDR.h                                                   */
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
/* !Designed by     : Sohail talaat                 !Date : SEP 11, 2023   */
/* !Coded by        : Sohail talaat                 !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "../../GeneralFunctions/std_types.h"
/******************************************************************************/


/******************************************************************************/
/*! \Description : Initialize the LDR Sensor with specificed Pin and ADC      */
/*! \return        None                                                       */
/*! \arguments     None                                                       */
/******************************************************************************/
void LDR_vidInit(void);

/******************************************************************************/
/*! \Description : Get left LDR Sensor Value                                  */
/*! \return        None                                                       */
/*! \arguments     Loc_u16Read is a pointer to store LDR read in it           */
/******************************************************************************/
void LDR_vidGetLeftBright(uint16_t *Loc_u16Read);

/******************************************************************************/
/*! \Description : Get left LDR Sensor Value                                  */
/*! \return        None                                                       */
/*! \arguments     Loc_u16Read is a pointer to store LDR read in it           */
/******************************************************************************/
void LDR_vidGetRightBright(uint16_t *Loc_u16Read);

#endif
