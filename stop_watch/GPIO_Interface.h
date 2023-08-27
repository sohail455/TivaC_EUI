/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  David & Sohail & Hossam
 *	   	   File:  GPIO_Interface.h
 *		  Layer:  MCAL
 *       Module:  GPIO
 *		Version:  1.00
 *	
 *  Description:  Interfaces Needed by user       
 *  
 *********************************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include"Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_DONT_CARE   17

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned char unit8;
typedef enum
{
    GPIO_PORTA=0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF
}GPIO_Port_t;

typedef enum
{
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}GPIO_Pin_t;

typedef enum
{
    GPIO_PIN_INPUT=0,
    GPIO_PIN_OUTPUT,
}GPIO_PinDirection_t;

typedef enum
{
    GPIO_PIN_DIGITAL=0,
    GPIO_PIN_ALTFUNC,
    GPIO_PIN_ANALOG
}GPIO_PINMode_t;

typedef enum
{
    GPIO_PIN_PULLUP=0,
    GPIO_PIN_PULLDOWN,
    GPIO_PIN_FLOATING
}GPIO_PinPullUpDown_t;

typedef enum
{
    GPIO_PIN_PUSHPULL=0,
    GPIO_PIN_OPENDRAIN
}GPIO_PinState_t;

typedef enum
{
    GPIO_PIN_LOW=0,
    GPIO_PIN_HIGH
}GPIO_PinValue_t;

typedef u8 Gpio_PortValue_t;

typedef enum
{
    GPIO_ALTFUNC0=0,
    GPIO_ALTFUNC1,
    GPIO_ALTFUNC2,
    GPIO_ALTFUNC3,
    GPIO_ALTFUNC4,
    GPIO_ALTFUNC5,
    GPIO_ALTFUNC6,
    GPIO_ALTFUNC7,
    GPIO_ALTFUNC8,
    GPIO_ALTFUNC9,
    GPIO_ALTFUNC10,
    GPIO_ALTFUNC11,
    GPIO_ALTFUNC12,
    GPIO_ALTFUNC13,
    GPIO_ALTFUNC14,
    GPIO_ALTFUNC15
}GPIO_AltFunc_t;

typedef enum
{
    GPIO_2MA_DRIVE=0,
    GPIO_4MA_DRIVE,
    GPIO_8MA_DRIVE
}GPIO_OutputCurrent_t;

typedef struct
{
    GPIO_Port_t Port;
    GPIO_Pin_t Pin;
    GPIO_PinDirection_t Dir;
    GPIO_PINMode_t Mode;
    GPIO_PinState_t PinState;
    GPIO_PinPullUpDown_t PinPull;
    GPIO_OutputCurrent_t OutputCurrent;
    GPIO_AltFunc_t AltFuncNum;
}GPIO_Config_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/***************************************************************************************************************************
* \Syntax          : ErrorState_t GPIO_Init(const GPIO_Config_t* Copy_Config,u8 Copy_PinNum)
* \Description     : Initialize the GPIO Pins
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : GPIO_Config_t   Array of configuration structure for GPIO
*                    Copy_PinNum     Number of Pins to be initialized
* \Parameters (out): None
* \Return value:   : ErrorState_t
***************************************************************************************************************************/
ErrorState_t GPIO_Init(const GPIO_Config_t* Copy_Config,u8 Copy_PinNum);

/***************************************************************************************************************************
* \Syntax          : ErrorState_t GPIO_SetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t Copy_PinValue)
* \Description     : Set Value to Digital Pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Copy_Port       The port of pin to set its value
*                    Copy_Pin        The pin to set its Value
*                    Copy_PinValue   The Pin value
* \Parameters (out): None
* \Return value:   : ErrorState_t
***************************************************************************************************************************/
ErrorState_t GPIO_SetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t Copy_PinValue);

/***************************************************************************************************************************
* \Syntax          : ErrorState_t GPIO_SetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t Copy_PortValue)
* \Description     : Set Value to Digital Port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Copy_Port       The port to set its value
*                    Copy_PortValue  The Port value
* \Parameters (out): None
* \Return value:   : ErrorState_t
***************************************************************************************************************************/
ErrorState_t GPIO_SetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t Copy_PortValue);

/***************************************************************************************************************************
* \Syntax          : ErrorState_t GPIO_GetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t* Copy_PinValue)
* \Description     : Get the Value of Digital Pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Copy_Port       The port of pin to get its value
*                    Copy_Pin        The pin to get its Value
* \Parameters (out): Copy_PinValue   The Pin value
* \Return value:   : ErrorState_t
***************************************************************************************************************************/
ErrorState_t GPIO_GetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t* Copy_PinValue);

/***************************************************************************************************************************
* \Syntax          : ErrorState_t GPIO_GetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t* Copy_PortValue)
* \Description     : Get the value of Digital Port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Copy_Port       The port to get its value
* \Parameters (out): Copy_PortValue  The Port value
* \Return value:   : ErrorState_t
***************************************************************************************************************************/
ErrorState_t GPIO_GetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t* Copy_PortValue);

#endif      /* GPIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_interface.h
 *********************************************************************************************************************/
