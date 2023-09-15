/*
 * Ultrasonic.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Hossam
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define PIN_4  0x10
#define PIN_5  0x20

#define GPIO_PIN_4  4
#define GPIO_PIN_5  5


void Ultrasonic_INIT(void);

u32 Get_Distance(void);




#endif /* ULTRASONIC_H_ */
