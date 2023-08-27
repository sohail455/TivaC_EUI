
#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "Utils.h"

static unsigned long i = 0;

void PWM_TEST_Init(void)
{
    SYSCTL->RCGCGPIO |= 0x00000020;
    GPIOF->DIR |= 0x04;
    GPIOF->AFSEL |= 0x00000004;
    GPIOF->PCTL &= ~0x00000F00;
    GPIOF->PCTL |= 0x00000700;
    GPIOF->DEN |= 0x04;
    TimerInit(TIMERBLOCK1, TIMERA, TIMER_CFG_16BITMODE, TIMER_MODE_PWM);
    TimerLoadSet(TIMERBLOCK1, TIMERA, 10000);
    TimerMatchSet(TIMERBLOCK1, TIMERA, 1);
    TimerEnable(TIMERBLOCK1, TIMERA);
    i = 10000;
}
void PWM_TEST_Runnable(void)
{
    static u8 flag = 0;

    if (flag == 0)
    {
        i--;
        TimerMatchSet(TIMERBLOCK1, TIMERA, i);
        if (i == 0)
        {
            flag = 1;
        }
    }
    else if (flag == 1)
    {
        TimerMatchSet(TIMERBLOCK1, TIMERA, i);
        i++;
        if (i == 9999)
        {
            flag = 0;
        }
    }
    delay(1);
}

//
//while(1)
//{
//    unsigned long i=0;
//    for(i=0; i < 10000; i++)
//    {
//        TimerMatchSet(TIMERBLOCK1, TIMERA, i);
//        delay(1);
//
//    }
//    delay(2000);
//    i--;
//    for(; i>0; i--)
//    {
//        TimerMatchSet(TIMERBLOCK1, TIMERA, i);
//
//        delay(1);
//    }
//}
