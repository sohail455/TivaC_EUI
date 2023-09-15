/*
 * car.c
 *
 *  Created on: Sep 1, 2023
 *      Author: pc
 */

#include "car.h"
#include "PWM2.h"



/**************************
*! \prototype void direction(int action )
*! \Description function to set the direction of the car
*! \return      None
*! \arguments   action: the action taken by the car {forward, backward, right, left}                                                         */


void direction(int32_t action)
{
    pwm_init();

    GPIOPinTypeGPIOOutput((uint32_t)MOTOTR_PORT_BASE, (uint8_t)MOTOR_PIN_1|(uint8_t)MOTOR_PIN_2|(uint8_t)MOTOR_PIN_3|(uint8_t)MOTOR_PIN_4);

    switch (action){
    case forward:
        pwm_speed(55, 55);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)PIN_2_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)PIN_4_ON);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)0x00);

        break;
    case backward:
        pwm_speed(55, 55);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)0x00);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)PIN_3_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)PIN_5_ON);
        break;
    case right:
        pwm_speed(85, 55);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)PIN_2_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)PIN_4_ON);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)0x00);

        break;
    case left:
        pwm_speed(55, 85);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)PIN_2_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)PIN_4_ON);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)0x00);
        break;
    case rotate_right:
        pwm_speed(70, 70);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)PIN_4_ON);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)PIN_3_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)0x00);
        break;
    case rotate_left:
        pwm_speed(70, 70);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)PIN_2_ON);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)0x00);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)PIN_5_ON);
        break;
    case stop:
        pwm_speed(0,0);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_2,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_4,(uint8_t)0x00);

        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_3,(uint8_t)0x00);
        GPIOPinWrite((uint32_t)MOTOTR_PORT_BASE, (uint8_t)GPIO_PIN_5,(uint8_t)0x00);


        break;

    default :
        break;


    }

}
