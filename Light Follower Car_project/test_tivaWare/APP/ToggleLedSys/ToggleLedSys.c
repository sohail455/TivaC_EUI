/*
 * ToggleLedSys.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Qaiaty store
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "inc/hw_gpio.h"



void systick_callBack(void)
{

    static uint8_t flag = 0;
    if (flag == 0)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0E);
        flag = 1;
    }
    else
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x00);
        flag = 0;
    }
}

void systickIntialize(void){

    SysTickPeriodSet(16000000);
    SysTickIntRegister(systick_callBack);
    SysTickIntEnable();
    SysTickEnable();
}



void ToggleLedSysInit(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    systickIntialize();
}

void ToggleLedSysRunnable(void)
{

}

