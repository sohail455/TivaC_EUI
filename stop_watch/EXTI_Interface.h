/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  David & Sohail & Hossam
 *	   	   File:  EXTI_interface.h
 *		  Layer:  MCAL
 *       Module:  EXTI
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    EXTI_PORTA=0,
    EXTI_PORTB,
    EXTI_PORTC,
    EXTI_PORTD,
    EXTI_PORTE,
    EXTI_PORTF
}EXTI_Port_t;

typedef enum
{
    EXTI_PIN0=0,
    EXTI_PIN1,
    EXTI_PIN2,
    EXTI_PIN3,
    EXTI_PIN4,
    EXTI_PIN5,
    EXTI_PIN6,
    EXTI_PIN7
}EXTI_Pin_t;

typedef enum
{
    EXTI_EDGE=0,
    EXTI_LEVEL
}EXTI_Detect_t;

typedef enum
{
    EXTI_FALLING_EDGE=0,
    EXTI_RAISING_EDGE,
    EXTI_ONCHANGE,
    EXTI_BOTH_LEVELS
}EXTI_TriggerDetect_t;

typedef struct
{
    EXTI_Port_t Port;
    EXTI_Pin_t Pin;
    EXTI_Detect_t Sence;
    EXTI_TriggerDetect_t TrigTye;
}EXTI_Config_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************************************************
 * \Syntax          : ErrorState_t EXTI_Init(EXTI_Config_t* Copy_config,u8 Copy_PinsNum)
 * \Description     : set the required configuration to number of pins
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_config     Configuration structure
 *                    Copy_PinsNum    Number of Pins to be configured
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *******************************************************************************************************************/
ErrorState_t EXTI_Init(EXTI_Config_t* Copy_config,u8 Copy_PinsNum);

/*******************************************************************************************************************************
 * \Syntax          : ErrorState_t EXTI_SetCallBack(EXTI_Port_t Copy_Port, EXTI_Pin_t Copy_Pin,void (*Copy_CallBackFunc)(void))
 * \Description     : Set the callback function to specific pin
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Copy_Port                         Port of pin to set the callback to
 *                    Copy_Pin                          Pin to set the callback to
 *                    void (*Copy_CallBackFunc)(void)   pointer to The callback function to be set
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 ********************************************************************************************************************************/
ErrorState_t EXTI_SetCallBack(EXTI_Port_t Copy_Port, EXTI_Pin_t Copy_Pin,void (*Copy_CallBackFunc)(void));

#endif  /* EXTI_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: EXTI_interface.h
 *********************************************************************************************************************/
