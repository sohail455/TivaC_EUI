/*
 * Buttons.c
 *
 *  Created on: 15 Sep 2023
 *      Author: pvc
 */
#include"MCAL/GPIO/GPIO_Interfaces.h"



void Buttons_init(void)
{
    GPIO_Config_t config[] = { { GPIO_PORTF, GPIO_PIN0, GPIO_PIN_INPUT,
                                 GPIO_PIN_DIGITAL, GPIO_PIN_PUSHPULL,
                                 GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,GPIO_ALTFUNC0 },
                               { GPIO_PORTF, GPIO_PIN4, GPIO_PIN_INPUT,
                                 GPIO_PIN_DIGITAL, GPIO_PIN_PUSHPULL,
                                 GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,GPIO_ALTFUNC0 }};
    GPIO_Init(config, 2);
}

