/****************************************************************************
 * Author: Sohail Talaat
 * Module: GPIO_Interface.h
 * File Name: GPIO_Interface
 * Layer: MCAL
 * Description: Headr file for GPIO module for Tiva C.
 ****************************************************************************/

#ifndef GPIO_INTERFACES_H_
#define GPIO_INTERFACES_H_
/************************************************************************
 *                            INCLUSION
 ************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"

/************************************************************************
 *                            DEFINITION
 ************************************************************************/

/************************************************************************
 *                         PORTS OF THE BOARD
 ************************************************************************/
typedef enum
{
    GPIO_PORTA=0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,
}GPIO_Port_t;

/************************************************************************
 *                         PINS OF THE EACH PORT
 ************************************************************************/
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

/************************************************************************
 *                         DIRECTION OF THE PINS
 ************************************************************************/
typedef enum
{
    GPIO_PIN_INPUT=0,
    GPIO_PIN_OUTPUT,
}GPIO_PinDirection_t;
/************************************************************************
 *                            MODE OF THE PINS
 ************************************************************************/
typedef enum
{
    GPIO_PIN_DIGITAL=0,
    GPIO_PIN_ALTFUNC,
    GPIO_PIN_ANALOG
}GPIO_PinMode_t;
/************************************************************************
 *                      TYPES OF THE PULL RESISTORS
 ************************************************************************/
typedef enum
{
    GPIO_PIN_PULLUP=0,
    GPIO_PIN_PULLDOWN,
    GPIO_PIN_FLOATING
}GPIO_PinPullUpDown_t;

/************************************************************************
 *                         STATE OF THE PINS
 ************************************************************************/
typedef enum
{
    GPIO_PIN_PUSHPULL=0,
    GPIO_PIN_OPENDRAIN
}GPIO_PinState_t;
/************************************************************************
 *                       VALUE OF THE OUTPUT PINS
 ************************************************************************/
typedef enum
{
    GPIO_PIN_LOW=0,
    GPIO_PIN_HIGH
}GPIO_PinValue_t;
/************************************************************************
 *                    ALTERNATED FUNCTIONS OF THE PINS
 ************************************************************************/
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
/************************************************************************
 *                     AMOUNT OF OUTPUT CURRENT
 ************************************************************************/
typedef enum
{
    GPIO_2MA_DRIVE=0,
    GPIO_4MA_DRIVE,
    GPIO_8MA_DRIVE
}GPIO_OutputCurrent_t;

typedef u8 Gpio_PortValue_t;
/************************************************************************
 *                       CONFIGURATION STRUCTURE
 ************************************************************************/
typedef struct
{
    GPIO_Port_t Port;
    GPIO_Pin_t Pin;
    GPIO_PinDirection_t Direction;
    GPIO_PinMode_t Mode;
    GPIO_PinState_t State;
    GPIO_PinPullUpDown_t Resistor;
    GPIO_OutputCurrent_t OutputCurrent;
    GPIO_AltFunc_t PinFunction;
}GPIO_Config_t;

/************************************************************************
 *                         FUNCTIONS DECLARATIONS
 ************************************************************************/
/***************************************************************************************************************************
* Syntax          : ErrorState_t GPIO_Init(const GPIO_Config_t* Copy_Config,u8 Copy_PinNum)
* Description     : Initialize GPIO Pins
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : GPIO_Config_t:   Array of configuration structure for GPIO.
*                   Copy_PinNum:     Number of Pins to be initialized.
* Parameters (out): None.
* Return value:   : ErrorState_t.
***************************************************************************************************************************/
ErrorState_t GPIO_Init(const GPIO_Config_t* Copy_Config,u8 Copy_PinNum);
/***************************************************************************************************************************
* Syntax          : ErrorState_t GPIO_SetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t Copy_PinValue)
* Description     : Set GPIO Pins Values
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : GPIO_Port_t:     The Number of GPIO Port that will be used as index in master array
*                   GPIO_Pin_t:      The number of the chosen pin.
*                   GPIO_PinValue_t: The desired output value
* Parameters (out): None.
* Return value:   : ErrorState_t.
***************************************************************************************************************************/
ErrorState_t GPIO_SetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t Copy_PinValue);
/***************************************************************************************************************************
* Syntax          : ErrorState_t GPIO_SetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t Copy_PortValue)
* Description     : Set GPIO Port Values
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : GPIO_Port_t:      The Number of GPIO Port that will be used as index in master array
*                   Gpio_PortValue_t: The desired output value
* Parameters (out): None.
* Return value:   : ErrorState_t.
***************************************************************************************************************************/
ErrorState_t GPIO_SetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t Copy_PortValue);
/***************************************************************************************************************************
* Syntax          : ErrorState_t GPIO_GetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t* Copy_PinValue)
* Description     : Get GPIO Pins Values
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : GPIO_Port_t:     The Number of GPIO Port that will be used as index in master array
*                   GPIO_Pin_t:      The desired pin
*                   GPIO_PinValue_t: read the value of the desired pin in this variable
* Parameters (out): None.
* Return value:   : ErrorState_t.
***************************************************************************************************************************/
ErrorState_t GPIO_GetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t* Copy_PinValue);
/***************************************************************************************************************************
* Syntax          : ErrorState_t GPIO_GetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t* Copy_PortValue)
* Description     : Get GPIO Ports Values
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : GPIO_Port_t:      The Number of GPIO Port that will be used as index in master array
*                   Gpio_PortValue_t: Read the port value in to this variable
* Parameters (out): None.
* Return value:   : ErrorState_t.
***************************************************************************************************************************/
ErrorState_t GPIO_GetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t* Copy_PortValue);




#endif /* GPIO_INTERFACES_H_ */
