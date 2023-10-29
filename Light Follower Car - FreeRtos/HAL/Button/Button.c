/*
 * Button.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed
 */
#include <HAL/Button/Button.h>

#include "../../GeneralFunctions/Bit_Math.h"
#include "../../GeneralFunctions/std_types.h"
#include "../../MCAL/GPIO/GPIO.h"

void Button_vidInit(void)
{
    GPIO_vidInitPort(GPIO_PORTF);
    GPIO_vidInputPin(GPIO_PORTF, 0);
    GPIO_vidInputPin(GPIO_PORTF, 4);
    GPIO_vidInputPinPullUp(GPIO_PORTF, 0);
    GPIO_vidInputPinPullUp(GPIO_PORTF, 4);

    GPIO_vidOutputPin(GPIO_PORTF, 1);
    GPIO_vidOutputPin(GPIO_PORTF, 2);
    GPIO_vidOutputPin(GPIO_PORTF, 3);
}

Button_Val Button_vidGetButtonValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinNumber)
{
    Button_Val Local_enuButtonValue;
    uint8_t Local_u8ButtonPIN = ((GPIO_PORTF_DATA_R & (1 << Copy_u8PinNumber)) >> Copy_u8PinNumber);

    if (Local_u8ButtonPIN == 1)
    {
        Local_enuButtonValue = Button_Low;
    }
    else
    {
        Local_enuButtonValue = Button_High;
    }

    return Local_enuButtonValue;
}

