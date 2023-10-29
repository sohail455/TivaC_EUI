/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : GPTM                                                    */
/* !Description     : Timer Module Implementation                             */
/*                                                                            */
/* !File            : GPTM.h                                                  */
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
/* !Designed by     : AHMED RAGAB                      !Date : SEP 11, 2023   */
/* !Coded by        : AHMED RAGAB                      !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

#ifndef  MCAL_TIMER0_TIMER0_H_
#define  MCAL_TIMER0_TIMER0_H_

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include <GeneralFunctions/std_types.h>
#include "../GPIO/GPIO.h"

/******************************************************************************/
/****************************** Custom Types **********************************/
/******************************************************************************/

/**
 * Mode of the timer.
 */
typedef enum
{
    oneShot, periodic, edgeCount, edgeTime, PWM
}timerMode;

/**
 * Which timer block to use.
 */
typedef enum
{
    Timer0, Timer1, Timer2, Timer3, Timer4, Timer5,
    wideTimer0, wideTimer1, wideTimer2, wideTimer3, wideTimer4, wideTimer5
}timerBlock;

/**
 * Count direction of the timer.
 */
typedef enum
{
    up, down
}countDirection;

/**
 * Which subtimer to use or both in concatenated mode.
 */
typedef enum
{
    timerA, timerB, concatenated
}subtimer;
/**
 * Which edge to use negative or positive or none.
 */
typedef enum
{
    positive, nigative, none, both
} edge;

/******************************************************************************/
/*! \Description : Initialize GPTM Module                                     */
/*! \return        None                                                       */
/*! \arguments     timer         to choose which timer block                  */
/******************************************************************************/

void GPTM_vidInit(timerBlock timer,timerMode mode ,countDirection direction,subtimer block,uint32_t loadregister,edge edge_state);

/******************************************************************************/
/*! \Description : Sets the pointer to the corresponding CallBack Function    */
/*! \return        None                                                       */
/*! \arguments     Copy_ptrFunction         Pointer to CallBack Function      */
/******************************************************************************/

void GPTM_vidSetCallbackFunction(void(*Copy_ptrFunction)(void));

/******************************************************************************/
/*! \Description : Returns the current timer value                            */
/*! \return        None                                                       */
/*! \arguments     Copy_enuTimer         Timer Choice                         */
/*                 Copy_enuBlock         Subtimer Choice                      */
/******************************************************************************/

uint32_t GPTM_u32GetCurrentValue(timerBlock Copy_enuTimer, subtimer Copy_enuBlock);

#endif /* 1_MCAL_TIMER0_TIMER0_H_ */
