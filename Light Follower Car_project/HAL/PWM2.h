/*
 * pwm.h
 *
 *  Created on: Aug 31, 2023
 *      Author: pc
 */

#ifndef HAL_PWM2_H_
#define HAL_PWM2_H_

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

void pwm_init(void);

void pwm_speed(int32_t duty1,int32_t duty2);
#endif /* HAL_PWM2_H_ */
