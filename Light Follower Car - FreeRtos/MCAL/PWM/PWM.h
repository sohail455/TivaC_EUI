/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-Controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : PWM                                                     */
/* !Description     : PWM Module Header file                                  */
/*                                                                            */
/* !File            : Motor.h                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous Car @EME-EUI  (CLASS 1)                      */
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
/* !Designed by     : Mahmoud Emara                    !Date : SEP 11, 2023   */
/* !Coded by        : Mahmoud Emara                    !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

#ifndef MCAL_PWM_H_
#define MCAL_PWM_H_

#include "../../GeneralFunctions/std_types.h"

/******************************************************************************/
/****************************** Local Types ***********************************/
/******************************************************************************/
typedef enum
{
    PWM0,PWM1
}PWM_ID;

typedef enum
{
    Channel0,Channel1,Channel2
}Channel_ID;


/******************************************************************************/
/*************************** Functions Declaration ****************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description Initialise the PWM Prehpiral  and AF pins used               */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void PWM_vidInit(void);


/******************************************************************************/
/*! \Description Set the duty cycle of a given channel                        */
/*! \return      None                                                         */
/*! \arguments   arg 1                                                        */
/*                      Name : Copy_Channel_ID                                */
/*                      type : Channel_ID (enum)                              */
/*                      Description : channel NO. (channel0 - channel1)       */
/*               arg 2                                                        */
/*                      Name : Copy_u8DutyValue                               */
/*                      type : uint8_t                                        */
/*                      Description : Duty Cycle Value (0 - 100)              */
/*                                                                            */
/******************************************************************************/
void PWM_vidSetDutyCycle(Channel_ID Copy_Channel_ID , uint8_t Copy_u8DutyValue);

#endif /* MCAL_PWM_H_ */
