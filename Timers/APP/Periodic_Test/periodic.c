#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "Utils.h"


void Periodic_TEST_Init(void)
{
    SYSCTL->RCGCGPIO |= 0x00000020;
    GPIOF->DIR |= 0x0E;
    GPIOF->DEN |= 0x0E;
    TimerInit(TIMERBLOCK0, TIMERA, TIMER_CFG_32BITMODE, TIMER_MODE_PERIODIC);
    TimerLoadSet(TIMERBLOCK0, TIMERA, 800000);
    TimerEnable(TIMERBLOCK0, TIMERA);
}
void Periodic_TEST_Runnable(void)
{

    while((TIMER0->RIS & 0x01) == 0);
    TIMER0->ICR=0x01;
    GPIOF->DATA[255]|=(7<<1);
    while((TIMER0->RIS & 0x01) == 0);
    TIMER0->ICR=0x01;
    GPIOF->DATA[255]&=~(7<<1);
}
