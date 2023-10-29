/*
 * Button.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

#include "../../GeneralFunctions/std_types.h"

#define BUTTON_PORT     GPIO_PORTF
#define BUTTON_0        0
#define BUTTON_1        4U

typedef enum
{
    Pullup,Pulldown,Float
}Button_State;

typedef enum
{
    Button_Low,
    Button_High
}Button_Val;

void Button_vidInit(void);
Button_Val Button_vidGetButtonValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinNumber);


#endif /* HAL_BUTTON_BUTTON_H_ */
