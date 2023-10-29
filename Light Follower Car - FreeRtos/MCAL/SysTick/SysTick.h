/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-Controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : SYSTICK Core Peripheral                                 */
/* !Description     : SYSTICK Peripheral Header File Implementation           */
/*                                                                            */
/* !File            : STK.h                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : MEGA Project @EME - EUI                                 */
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
/* !Designed by     : Mazen Tamer                      !Date : SEP 09, 2023   */
/* !Coded by        : Mazen Tamer                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 09, 2023     Initial release                                */
/******************************************************************************/

#ifndef MCAL_STK_H_
#define MCAL_STK_H_

/******************************************************************************/
/*********************************** INCLUDES *********************************/
/******************************************************************************/

#include <GeneralFunctions/Std_types.h>

/******************************************************************************/
/**************************** Configuration Macros ****************************/
/******************************************************************************/

#define F_CPU           16000000UL
#define MILLISECOND     1000U
#define MICROSECOND     1000000UL

#define COUNT           16U
#define CLK_SRC         2U
#define INTEN           1U
#define ENABLE          0

#define ON              1U
#define OFF             0

#define INTERRUPT       ON

/******************************************************************************/
/*************************** Function Declarations ****************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Microseconds  */
/*! \return      None                                                         */
/*! \arguments   Copy_u32Microseconds       Delay in microseconds             */
/******************************************************************************/

void STK_vidStartUS(uint32_t Copy_u32Microseconds);

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Milliseconds  */
/*! \return      None                                                         */
/*! \arguments   Copy_u32Milliseconds       Delay in milliseconds             */
/******************************************************************************/

void STK_vidStartMS(uint32_t Copy_u32Milliseconds);

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Seconds       */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void STK_vidStartSEC(void);

/******************************************************************************/
/*! \Description : Sets the SYSTICK Interrupt Callback Function               */
/*! \return      None                                                         */
/*! \arguments   Copy_ptrFunction            Pointer to the CB Function       */
/******************************************************************************/

void STK_vidSetInterruptCallback(void(*Copy_ptrFunction)(void));

/******************************************************************************/
/*! \Description : Stops the SYSTICK Timer                                    */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void STK_vidStopCounter(void);

#endif /* MCAL_STK_H_ */
