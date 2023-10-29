/*
 * leds.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mariam
 */
#include "leds.h"
void LEDs_init(void)
{
    GPIO_vidInitPort(GPIO_PORTF);
    GPIO_vidOutputPin(GPIO_PORTF, 1);
    GPIO_vidOutputPin(GPIO_PORTF, 2);
    GPIO_vidOutputPin(GPIO_PORTF, 3);
}
void LED_turnOn(uint8_t color)
{
    switch(color)
    {
    case RED_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);
        break;
    case BLUE_LED:
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);
        break;
    case GREEN_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_LOW);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_HIGH);
        break;
    case PURPLE_LED:
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_LOW);

        break;
    case WHITE_LED :
        GPIO_vidWritePin(GPIO_PORTF, PIN1, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN2, OUTPUT_HIGH);
        GPIO_vidWritePin(GPIO_PORTF, PIN3, OUTPUT_HIGH);
        break;

    }

}


