/*
 * tasks.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mazen
 */

#ifndef APP_TASKS_H_
#define APP_TASKS_H_

#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/semphr.h"
#include "include/event_groups.h"

#include "HAL/RCC/RCC.h"
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "HAL/Motors/Motors.h"
#include "HAL/LDR/LDR.h"
#include "HAL/Temperature/Temperature.h"
#include "HAL/LCD/LCD.h"
#include "HAL/Button/Button.h"
#include "HAL/LEDs/leds.h"


extern TaskHandle_t ultrasonic_h;
extern TaskHandle_t ldr_h;
extern TaskHandle_t lcd_h;
extern TaskHandle_t motors_h;
extern TaskHandle_t sys_h;


void tasks_modulesInit(void);
void button_scan(void);
void ldr_swing_car(void);
void lcd_display(void);
void avoid_obstacles(void);


#endif /* APP_TASKS_H_ */
