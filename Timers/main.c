#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "APP/Capture_Test/Capture.h"
#include "APP/PWM_Test/PWM_test.h"
#include "APP/Periodic_Test/Periodic.h"

typedef enum
{
    PERIODIC,
    PWM,
    CAPTURE
}APP_Slect_t;

APP_Slect_t mode=PWM;

int main(void)
{
    if(mode == PERIODIC)
    {
        Periodic_TEST_Init();
        while(1)
        {
            Periodic_TEST_Runnable();
        }
    }
    else if( mode == PWM)
    {
        PWM_TEST_Init();
        while(1)
        {
            PWM_TEST_Runnable();
        }
    }
    else if( mode == CAPTURE)
    {
        Capture_TEST_Init();
        while(1)
        {
            Capture_TEST_Runnable();
        }
    }

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
