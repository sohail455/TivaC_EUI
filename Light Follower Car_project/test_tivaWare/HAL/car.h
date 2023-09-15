/*
 * car.h
 *
 *  Created on: Sep 1, 2023
 *      Author: pc
 */

#ifndef HAL_CAR_H_
#define HAL_CAR_H_


#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"


enum{
    forward=0,backward=1,right=2,left=3,rotate_right=4,rotate_left=5,stop= 6
}; //enum to define directions

#define MOTOTR_PORT_BASE GPIO_PORTB_BASE //PORT BASE which is connected to the motor
#define MOTOR_PIN_1 GPIO_PIN_2           //motor direction pin1
#define MOTOR_PIN_2 GPIO_PIN_3           //motor direction pin2
#define MOTOR_PIN_3 GPIO_PIN_4           //motor direction pin3
#define MOTOR_PIN_4 GPIO_PIN_5           //motor direction pin4


void direction(int32_t action);


#endif /* HAL_CAR_H_ */
