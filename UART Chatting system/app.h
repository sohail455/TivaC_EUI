/*
 * app.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Qaiaty store
 */

#ifndef APP_H_
#define APP_H_
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "Comm_Manger.h"

typedef enum
{
    ONLINE=0,
    READ_ONLY,
    OFFLINE

}States;

void start_chat();


#endif /* APP_H_ */
