#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "ULTRASONIC.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

volatile uint32_t t1;
volatile uint32_t t2;
volatile uint8_t flag = 0;

void TIMER0_Handler(void);
void UltraSonic_trigger(void);

void ULTRASONIC_init(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
    {
    }

    GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PC4_WT0CCP0); // enable alternative function
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);

    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_WTIMER0))
    {
    }

    TimerConfigure(WTIMER0_BASE,
    TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP);

    TimerIntRegister(WTIMER0_BASE, TIMER_A, TIMER0_Handler);

    TimerIntEnable(WTIMER0_BASE, TIMER_CAPA_EVENT);

    TimerEnable(WTIMER0_BASE, TIMER_A);
}

uint16_t ULTRASONIC_GetDistance(void)
{
    uint32_t t;
    uint16_t d, c = 0;
    flag = 0;
    TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_POS_EDGE);
    UltraSonic_trigger();
    while ((flag < 2) )
    {
        c++;
        SysCtlDelay(1 * 6);
    }
    t = t2 - t1;
    d = t / 928;
    if (flag == 2)
    {
        t = t2 - t1;
        d = t / 928;
    }
    else
    {
        d = 400;
    }
    return d;
}

void TIMER0_Handler(void)
{
    if (flag == 0)
    {
        t1 = TimerValueGet(WTIMER0_BASE, TIMER_A);
        flag = 1;
        TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_NEG_EDGE);
    }
    else if (flag == 1)
    {
        t2 = TimerValueGet(WTIMER0_BASE, TIMER_A);
        flag = 2;

    }
    TimerIntClear(WTIMER0_BASE, TIMER_CAPA_EVENT);
}

void UltraSonic_trigger(void)
{
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
//    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_HIGH);
    SysCtlDelay(10 * 6);
//    GPIO_SetPinValue(GPIO_PORTB_BASE, GPIO_PIN3, 0);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
}
