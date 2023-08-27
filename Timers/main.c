#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "APP/PWM_Test/PWM_test.h"




int main(void)
{
//            PWM_TEST_Init();
//
//            while(1){
//                PWM_TEST_Runnable();
//            }
        unsigned long first_edge=0;
        unsigned long last_edge=0;
        unsigned long period=0;
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
        while(1)
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
//    SYSCTL->RCGCGPIO |= 0x00000020;
//    GPIOF->DIR |= 0x0E;
//    GPIOF->DEN |= 0x0E;
//    TimerInit(TIMERBLOCK0, TIMERA, TIMER_CFG_32BITMODE, TIMER_MODE_PERIODIC);
//    TimerLoadSet(TIMERBLOCK0, TIMERA, 800000);
//    TimerEnable(TIMERBLOCK0, TIMERA);
//    while(1)
//    {
//        while((TIMER0->RIS & 0x01) == 0);
//        TIMER0->ICR=0x01;
//        GPIOF->DATA[255]|=(7<<1);
//        while((TIMER0->RIS & 0x01) == 0);
//        TIMER0->ICR=0x01;
//        GPIOF->DATA[255]&=~(7<<1);
//    }
}


































//
//
//void pin_int(void)
//{
//
//}
//
//
//
//void TIMER0_delay(unsigned long delay)
//{
//    SYSCTL_RCGCTIMER_R = 0x00000001;
//    while(SYSCTL_RCGCTIMER_R ==0);
//    TIMER0_CTL_R = 0x00;
//    TIMER0_CFG_R = 0x00;
//    TIMER0_TAMR_R = 0x01;
//    TIMER0_TAILR_R = 16000 - 1;
//    TIMER0_CTL_R = 0x01;
//    TIMER0_ICR_R = 0x01;
//
//    int i=0;
//    for(i; i<delay; i++)
//    {TIMER0_CTL_R = 0x01;
//    while((TIMER0_RIS_R & 0x01) == 0);
//    TIMER0_ICR_R = 0x01;
//
//    }
//}
//
//
//
//void Input_edge(void)
//{
//    //    SYSCTL_RCGCGPIO |= 0x00000020;
//    SYSCTL->RCGCGPIO |= 0x00000020;
//    //    SYSCTL_RCGCTIMER_R = 0x00000001;
//    GPIOF->DIR &=~0x01;
//    GPIOF->AFSEL|=0x00000001;
//    GPIOF->PCTL &= ~0x0000000F;
//    GPIOF->PCTL |= 0x00000007;
//    GPIOF->PxR[1] |=(1<<0);
//    while(SYSCTL_RCGCTIMER_R ==0);
//    WTIMER0_CTL_R = 0x00;
//    WTIMER0_CFG_R = 0x04;
//    WTIMER0_TAMR_R = 0x17;
//    WTIMER0_CTL_R |= (1<<10);
//    WTIMER0_TAILR_R = 0xFFFF;
//    WTIMER0_CTL_R = 0x01;
//
//}
//
//
