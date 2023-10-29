/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : LDR                                                     */
/* !Description     : Read light intensity                                    */
/*                                                                            */
/* !File            : LDR.c                                                   */
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

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "LDR.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../GeneralFunctions/std_types.h"
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/*! \Description : Initialize the LDR Sensor with specified Pin and ADC       */
/*! \return        None                                                       */
/*! \arguments     None                                                       */
/******************************************************************************/
void LDR_vidInit(void)
{
    ADC_vidInit(SEQ_1);  /*Initialize ADC Sequencer 1 to Left LDR Sensor */
    ADC_vidInit(SEQ_2);  /*Initialize ADC Sequencer 1 to Right LDR Sensor*/
}

/******************************************************************************/
/*! \Description : Get left LDR Sensor Value                                  */
/*! \return        None                                                       */
/*! \arguments     Loc_u16Read is a pointer to store LDR read in it           */
/******************************************************************************/
void LDR_vidGetLeftBright(uint16_t *Loc_u16Read)
{
    *Loc_u16Read = ADC_u32ReadChannel(SEQ_1); /*Read LDR Left Sensor Value*/
}

/******************************************************************************/
/*! \Description : Get left LDR Sensor Value                                  */
/*! \return        None                                                       */
/*! \arguments     Loc_u16Read is a pointer to store LDR read in it           */
/******************************************************************************/
void LDR_vidGetRightBright(uint16_t *Loc_u16Read)
{
    *Loc_u16Read = ADC_u32ReadChannel(SEQ_2); /*Read LDR right Sensor Value*/
}
