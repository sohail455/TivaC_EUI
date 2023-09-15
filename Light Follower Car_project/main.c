#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "HAL/LDR.h"
#include "HAL/ULTRASONIC/ULTRASONIC.h"
/**
 * main.c
 */
#include <HAL/PWM2.h>
#include "HAL/car.h"

void delay(unsigned long d)
{
    unsigned long i;
    for (i = 0; i < 762 * d; i++)
        ;
}

int32_t main(void)
{
    pwm_init();
    uint16_t distance;
    //    //    direction(rotate_rotate_right);

    CAR_State current_state = forward;
    LDR_init();
    ULTRASONIC_init();
    while (1)
    {
        LDR_RUNNABLE();
        distance = ULTRASONIC_GetDistance();

        if (distance < 30 && distance != 0)
        {
            direction(stop);
        }
        else if (distance > 60)
        {
            if (reads0 < 400)
            {
                current_state = left;
            }
            else if (reads1 < 800)
            {
                current_state = right;
            }
            else
            {
                current_state = forward;
            }

            switch (current_state)
            {
            case left:
                direction(left);
                break;
            case right:
                direction(right);
                break;
            case forward:
                direction(forward);
                break;
            default:
                break;
            }

        }

    }
}
//while (1)
//{
//    int i=0;
////    direction(forward);
////
////    for(i=0;i<762*3000;i++){}
////
////    direction(backward);
////
////    for(i=0;i<762*3000;i++){}
//
//    direction(right);
//
//    for(i=0;i<762*6000;i++){}
//}
/*
 direction(stop);

 for(i=0;i<762*3000;i++){}
 direction(rotate_right);

 for(i=0;i<762*3000;i++){}
 direction(stop);

 for(i=0;i<762*3000;i++){}
 direction(rotate_left);

 for(i=0;i<762*3000;i++){}
 direction(stop);
 */
//}
//    {
//
//void isr()
//{
//    if(counter<2)
//    {
//        counter++;
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x0E);
//    }
//    else
//    {
//        counter=0;
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
//
//    }
//}
//
//direction(forward);
//
//
//           switch (current_state)
//           {
//           case forward:
//               direction(forward);
//               LDR_RUNNABLE();
//               if (diff < 550)
//               {
//                   current_state = forward;
//               }
//               else if (diff > 550)
//               {
//                   if (reads0 > reads1)
//                   {
//                       current_state = right;
//                   }
//                   else if (reads0 < reads1)
//                   {
//                       current_state = left;
//                   }
//               }
//               break;
//           case left:
//               direction(left);
//               //            delay(4);
//               LDR_RUNNABLE();
//               //            delay(4);
//               if (diff < 550)
//               {
//                   current_state = forward;
//               }
//               else if (diff < 150)
//               {
//                   if (reads0 > reads1)
//                   {
//                       current_state = right;
//                   }
//                   else if (reads0 < reads1)
//                   {
//                       current_state = left;
//                   }
//               }
//               break;
//           case right:
//               direction(right);
//               //            delay(4);
//               LDR_RUNNABLE();
//               //            delay(4);
//               //            delay(4);
//
//               if (diff < 550)
//               {
//                   current_state = forward;
//               }
//               else if (diff > 420)
//               {
//                   if (reads0 > reads1)
//                   {
//                       current_state = right;
//                   }
//                   else if (reads0 < reads1)
//                   {
//                       current_state = left;
//                   }
//               }
//               break;
//           }
