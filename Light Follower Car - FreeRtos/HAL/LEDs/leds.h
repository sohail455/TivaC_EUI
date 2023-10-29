/*
 * leds.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Mariam
 */

#ifndef HAL_LEDS_LEDS_H_
#define HAL_LEDS_LEDS_H_



#include "MCAL/GPIO/GPIO.h"


#define RED_LED     1
#define BLUE_LED    2
#define GREEN_LED   3
#define PURPLE_LED  4
#define WHITE_LED   5


void LEDs_init(void);
void LED_turnOn(uint8_t color);




#endif /* HAL_LEDS_LEDS_H_ */
