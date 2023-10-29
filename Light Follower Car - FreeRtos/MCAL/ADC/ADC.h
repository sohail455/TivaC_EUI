/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : ADC                                                     */
/* !Description     : Read analog values                                      */
/*                                                                            */
/* !File            : ADC.h                                                   */
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

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/******************************* Includes *************************************/
#include "../../GeneralFunctions/std_types.h"

/******************************************************************************/
/*************************** Custom Data Types ********************************/
/******************************************************************************/

/*Sequencers is an enum indicates specific sequencer*/
typedef enum
{
    SEQ_0,SEQ_1,SEQ_2,SEQ_3
}Sequencers;

/******************************************************************************/
/*! \Description : Initialize ADC Sequencer                                   */
/*! \return      None                                                         */
/*! \arguments   Copy_enuSeq to select sequencer                              */
/******************************************************************************/
void ADC_vidInit(Sequencers Copy_enuSeq);

/******************************************************************************/
/*! \Description : Read ADC value                                             */
/*! \return      Unsigned int -> 16 bit                                       */
/*! \arguments   Copy_enuSeq to select sequencer                              */
/******************************************************************************/
uint16_t ADC_u32ReadChannel(Sequencers Copy_enuSeq);



#endif /* MCAL_ADC_ADC_H_ */
