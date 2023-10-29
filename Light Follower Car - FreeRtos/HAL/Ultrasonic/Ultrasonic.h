/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : Ultra-sonic                                             */
/* !Description     : Ultra-sonic Module Implementation                       */
/*                                                                            */
/* !File            : Ultrasonic.h                                            */
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
/* !Designed by     : Mazen TAMER                      !Date : SEP 09, 2023   */
/* !Coded by        : Mazen TAMER                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/
#ifndef HAL_HC_SR04_H_
#define HAL_HC_SR04_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include <GeneralFunctions/hw_gpio.h>
#include <GeneralFunctions/Bit_Math.h>

#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPTM/GPTM.h"

/******************************************************************************/
/****************************** Macro Defines *********************************/
/******************************************************************************/

#define     ULTRASONIC_PORT     GPIO_PORTD
#define     TRIG_PIN            PIN7

#define     US_ECHO     0U
#define     US_TRIG     1U

//#define     MAX_DISTANCE_CM    10U

/******************************************************************************/
/*************************** Function Declarations ****************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize Ultra-sonic Module                              */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void Ultrasonic_vidInit(void);

/******************************************************************************/
/*! \Description : Get Ultra-sonic Distance Reading                      */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void Ultrasonic_vidGetDistance(float *Glob_u32Distance);


#endif /* HAL_HC_SR04_H_ */
