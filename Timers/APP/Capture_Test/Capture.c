#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "Utils.h"

u32 first_edge=0;
u32 last_edge=0;
u32 period=0;

void Capture_TEST_Init(void)
{

    SYSCTL->RCGCGPIO |= 0x00000008;
    SYSCTL->RCGCGPIO |= 0x00000020;
    GPIOD->DIR &= ~0x01;
    GPIOF->DIR |= 0x0E;
    GPIOD->PxR[0] |=0x00000001;
    GPIOD->AFSEL |= 0x00000001;
    GPIOD->PCTL &= ~0x000000F;
    GPIOD->PCTL |= 0x00000007;
    GPIOD->DEN |= 0x01;
    GPIOF->DEN |= 0x0E;
    TimerInit(TIMERBLOCK2_W, TIMERA, TIMER_CFG_16BITMODE, TIMER_MODE_EDGE_TIME_F);
    TimerEnable(TIMERBLOCK2_W, TIMERA);
}
void Capture_TEST_Runnable(void)
{
    TIMER2_W->ICR = 4;
    while((TIMER2_W->RIS & 4) == 0);
    first_edge=TIMER2_W->TAR;
    TIMER2_W->ICR = 4;
    while((TIMER2_W->RIS & 4) == 0);
    last_edge=TIMER2_W->TAR;
    if((last_edge - first_edge) <= 0)
    {
        period=((last_edge - first_edge )+4294967296)/16000000;
    }
    else
    {
        period=(last_edge - first_edge )/16000000;
    }
    if(period < 2)
    {
        GPIOF->DATA[255] &=0x00;
        GPIOF->DATA[255] = (1<<1);
    }
    else if(period > 2 && period <= 5)
    {
        GPIOF->DATA[255] &=0x00;
        GPIOF->DATA[255] = (1<<2);
    }
    else if(period > 5)
    {
        GPIOF->DATA[255] &=0x00;
        GPIOF->DATA[255] = (1<<3);
    }
}
