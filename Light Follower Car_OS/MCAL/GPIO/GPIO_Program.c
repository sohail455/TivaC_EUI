/****************************************************************************
 * Author: Sohail Talaat
 * Module: GPIO.c
 * File Name: GPIO
 * Layer: MCAL
 * Description: Source file for GPIO module for Tiva C.
 ****************************************************************************/
/***************************************************************************
 *                             INCLUSION
 ***************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Register_Map.h"
#include "GPIO_Interfaces.h"
#include "Bit_Math.h"
#include "GPIO_Private.h"
/***************************************************************************
 *                             Master Array
 ***************************************************************************/
static GPIO_RegDef_t *reg_arr[6]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF};
/***************************************************************************
 *                             Global Function
 ***************************************************************************/
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
ErrorState_t GPIO_Init(const GPIO_Config_t* Copy_Config,u8 Copy_PinNum)
{
    ErrorState_t Local_Error_State=E_OK;/*Indicator of the process success*/
    u8 local_counter=0;
    if(Copy_Config == NULLPTR)/*Check if the input pointer is NULLPTR*/
    {
        Local_Error_State=E_NULL_POINTER;
    }
    else
    {
        /*Start looping over the array of configuration structure and apply configuration for each individual pin*/
        for(local_counter=0; local_counter<Copy_PinNum; local_counter++)
        {
            if(GPIO_CONFIG.Port > GPIO_PORTF || GPIO_CONFIG.Pin > GPIO_PIN7)/*Check the range of pin and port*/
            {
                Local_Error_State=E_WRONG_OPTION;
            }
            else
            {
                /*Enable Clock for the current port, if it is not enabled then enable it*/
                if(GET_BIT(SYSCTL->RCGCGPIO,GPIO_CONFIG.Port) == 0)
                {
                    SET_BIT(SYSCTL->RCGCGPIO,GPIO_CONFIG.Port);
                }
                /*Unlock the pin and commit, this not include PORTC anyway, if you want to unlock it do it yourself :D*/
                if(GPIO->LOCK == 1 && GPIO_CONFIG.Port != GPIO_PORTC)
                {
                    GPIO->LOCK=GPIO_UNLOCK;
                    GPIO->CR=GPIO_COMMIT;
                }
                /*make the pin input or output according to the configuration structure*/
                INSERT_BIT(GPIO->DIR,GPIO_CONFIG.Pin,GPIO_CONFIG.Direction);
                switch(GPIO_CONFIG.Resistor)/*make the input pin pulled up or down*/
                {
                case GPIO_PIN_PULLDOWN:
                    SET_BIT(GPIO->PDR,GPIO_CONFIG.Pin);
                    break;
                case GPIO_PIN_PULLUP:
                    SET_BIT(GPIO->PUR,GPIO_CONFIG.Pin);
                    break;
                case GPIO_PIN_FLOATING:/*if the pin is output there is no need to be pulled*/
                    break;
                }
                switch(GPIO_CONFIG.Mode)/*Check the mode of the pins*/
                {
                case GPIO_PIN_DIGITAL:/*Normal GPIO*/
                    SET_BIT(GPIO->DEN,GPIO_CONFIG.Pin);
                    break;
                case GPIO_PIN_ALTFUNC:/*Alternated functionality assigned to the pin*/
                    SET_BIT(GPIO->AFSEL,GPIO_CONFIG.Pin);/*indicate that there is alternated functionality*/
                    GPIO->PCTL&=(~(0b1111)<<(4*GPIO_CONFIG.Pin));
                    GPIO->PCTL|=(GPIO_CONFIG.PinFunction)<<(4*GPIO_CONFIG.Pin);/*choose the alternated functionality*/
                    SET_BIT(GPIO->DEN,GPIO_CONFIG.Pin);
                    break;
                case GPIO_PIN_ANALOG:
                    SET_BIT(GPIO->AMSEL,GPIO_CONFIG.Pin);
                    CLEAR_BIT(GPIO->DEN,GPIO_CONFIG.Pin);
                }
                if(GPIO_CONFIG.State == GPIO_PIN_OPENDRAIN)/*if pin used for I2C*/
                {
                    SET_BIT(GPIO->ODR,GPIO_CONFIG.Pin);
                }
                switch(GPIO_CONFIG.OutputCurrent)/*value of the output current*/
                {
                case GPIO_2MA_DRIVE:/*Usually used*/
                    SET_BIT(GPIO->DR2R,GPIO_CONFIG.Pin);
                    break;
                case GPIO_4MA_DRIVE:
                    SET_BIT(GPIO->DR4R,GPIO_CONFIG.Pin);
                    break;
                case GPIO_8MA_DRIVE:
                    SET_BIT(GPIO->DR8R,GPIO_CONFIG.Pin);
                    break;
                }
            }
        }
    }
    return Local_Error_State;
}
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
ErrorState_t GPIO_SetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t Copy_PinValue)
{
    ErrorState_t Local_ErrorState=E_OK;/*Indicator of the process success*/
    u8 Local_RegNum=1<<Copy_Pin;/*to use bit banding feature to exceed first two zeros of the address*/
    if((Copy_Port>GPIO_PORTF) || (Copy_Pin>GPIO_PIN7))/*Check the range*/
    {
        Local_ErrorState=E_WRONG_OPTION;
    }
    else
    {
        reg_arr[Copy_Port]->DATA[Local_RegNum]=Copy_PinValue<<Copy_Pin;/*Put the value at the location of the pin in bit banding register*/
    }
    return Local_ErrorState;
}
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
ErrorState_t GPIO_SetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t Copy_PortValue)
{
    ErrorState_t Local_ErrorState=E_OK;/*Indicator of the process success*/
    if((Copy_Port>GPIO_PORTF))/*Check the range*/
    {
        Local_ErrorState=E_WRONG_OPTION;
    }
    else
    {
        reg_arr[Copy_Port]->DATA[255]=Copy_PortValue;/*Put the value into the output register*/
    }
    return Local_ErrorState;
}
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
ErrorState_t GPIO_GetPinValue(GPIO_Port_t Copy_Port,GPIO_Pin_t Copy_Pin,GPIO_PinValue_t* Copy_PinValue)
{
    ErrorState_t Local_ErrorState=E_OK;/*Indicator of the process success*/
    u8 Local_RegNum=1<<Copy_Pin;/*to use bit banding feature to exceed first two zeros of the address*/
    if((Copy_Port>GPIO_PORTF) || (Copy_Pin>GPIO_PIN7))
    {
        Local_ErrorState=E_WRONG_OPTION;
    }
    else
    {
        *Copy_PinValue= (GPIO_PinValue_t) (reg_arr[Copy_Port]->DATA[Local_RegNum])>>Copy_Pin;/*Put the value of the desired pin in to this variable using bit banding feature*/
    }
    return Local_ErrorState;
}
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
ErrorState_t GPIO_GetPortValue(GPIO_Port_t Copy_Port,Gpio_PortValue_t* Copy_PortValue)
{
    ErrorState_t Local_ErrorState=E_OK;/*Indicator of the process success*/
    if((Copy_Port>GPIO_PORTF))
    {
        Local_ErrorState=E_WRONG_OPTION;
    }
    else
    {
        *Copy_PortValue=reg_arr[Copy_Port]->DATA[255];/*Put the value of the desired port in to this variable using bit banding feature*/
    }
    return Local_ErrorState;
}
