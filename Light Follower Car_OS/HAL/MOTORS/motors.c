/*
 * motors.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Mahmoud A. Monaim
 */

#include <stdint.h>
#include "motors.h"




/***************************************************************************************************************************
* Syntax          : void motor_initialisation(void)
* Description     : Initialize all the pins used to drive the motors ("b2,b3,b4,b5" for direction & "b6,b7" for speed)
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : NULL
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void motor_initialisation(void)
{
     //enabling pwm0 clock
     SET_BIT(SYSCTL_RCGCPWM_R,0);

     //enabling PORTB clock
     SET_BIT(SYSCTL_RCGCGPIO_R,1);

     //waiting for the clock to be set
     while((SYSCTL_RCGCGPIO_R&(1<<1))==0){};

     //unlocking PORTB
     GPIO_PORTB_LOCK_R=0x4C4F434B;
     GPIO_PORTB_CR_R |=0xFC;

     //setting pin direction --> (00111100)
     GPIO_PORTB_DIR_R |=0x3C;

     //Enabling pins "2->7" to digital uses
     SET_BIT(GPIO_PORTB_DEN_R,2);
     SET_BIT(GPIO_PORTB_DEN_R,3);
     SET_BIT(GPIO_PORTB_DEN_R,4);
     SET_BIT(GPIO_PORTB_DEN_R,5);
     SET_BIT(GPIO_PORTB_DEN_R,6);
     SET_BIT(GPIO_PORTB_DEN_R,7);

     //setting alternate function uses to pins "6&7"
     SET_BIT(GPIO_PORTB_AFSEL_R,6);
     SET_BIT(GPIO_PORTB_AFSEL_R,7);

     //setting pins "6&7" to PWM as their alternate functions
     GPIO_PORTB_PCTL_R=0x44000000;

     //enable PWM divisor  --> ((CLK "16 MHz"/64))
     SET_BIT(SYSCTL_RCC_R,20);


     /*
      * -> When the counter matches the value in the PWMnLOAD register:
      *     drive PWM_A to high
      *
      * -> When the counter matches comparator A while counting down:
      *     drive PWM_A to high
      */
     PWM0_0_GENA_R=0x0000008c;

     /*
      * -> When the counter matches the value in the PWMnLOAD register:
      *     drive PWM_B to high
      *
      * -> When the counter matches comparator B while counting down:
      *     drive PWM_B to high
      */
     PWM0_0_GENB_R=0x0000080c;


     //Cycle frequency = 100Hz
     PWM0_0_LOAD_R=2500-1;

     //Enable clock generation to PWM
     SET_BIT(PWM0_0_CTL_R,0);
}


/***************************************************************************************************************************
* Syntax          : void Speed (int speed_percentage_A , int speed_percentage_B)
* Description     : Converts the "speed percentage" to a PWM signal and sends it to the motors
*                   Speed Percentage is (0% "stop") --> (100% "full speed")
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : -> (int) speed_percentage_A:
*                       the speed of the left side motors of the car
*
*                  -> (int) speed_percentage_B:
*                       the speed of the right side motors of the car
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void Speed (int speed_percentage_A , int speed_percentage_B)
{
    int calculated_value_A =0;
    calculated_value_A = 2500-(2500*speed_percentage_A/100);
    int calculated_value_B =0;
    calculated_value_B = 2500-(2500*speed_percentage_B/100);

    PWM0_0_CMPA_R=calculated_value_A;
    PWM0_0_CMPB_R=calculated_value_B;

    SET_BIT(PWM0_ENABLE_R,0);//enable output
    SET_BIT(PWM0_ENABLE_R,1);//enable output
}



/***************************************************************************************************************************
* Syntax          : void current_direction(int direction)
* Description     : controls the car's direction of moving:
*                   ---------------------------------------
*                    1- Forward motion: both left side and right side motors are moving forward
*                    2- Backward motion: both left side and right side motors are moving backward
*                    3- Turning left : the "left side" motors are moving forward but with a higher speed than the "right side"
*                    4- Turning right : the "right side" motors are moving forward but with a higher speed than the "left side"
*                    5- Rotation : the "right side" and the "left side" are moving but in opposite directions
*
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) :  AN enum of the Direction {FORWARD , BACKWARD , TURN_LEFT, TURN_RIGH , ROTATE }
*                    Note: any other value = STOP
*
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void current_direction(int direction)
{
    switch (direction)
    {
    //1- Forward motion: both left side and right side motors are moving forward
    case STRAIGHT:
        SET_BIT(GPIO_PORTB_DATA_R,2);
        CLEAR_BIT(GPIO_PORTB_DATA_R,3);
        SET_BIT(GPIO_PORTB_DATA_R,4);
        CLEAR_BIT(GPIO_PORTB_DATA_R,5);

        Speed (50,50);
        break;

    //2- Backward motion: both left side and right side motors are moving backward
    case BACKWARD:
        CLEAR_BIT(GPIO_PORTB_DATA_R,2);
        SET_BIT(GPIO_PORTB_DATA_R,3);
        CLEAR_BIT(GPIO_PORTB_DATA_R,4);
        SET_BIT(GPIO_PORTB_DATA_R,5);

        Speed (50,50);
        break;

     //3- Turning left : the "left side" motors are moving forward but with a higher speed than the "right side"
    case TURN_LEFT:
        SET_BIT(GPIO_PORTB_DATA_R,2);
        CLEAR_BIT(GPIO_PORTB_DATA_R,3);
        SET_BIT(GPIO_PORTB_DATA_R,4);
        CLEAR_BIT(GPIO_PORTB_DATA_R,5);

        Speed (70,10);
        break;

     // 4- Turning right : the "right side" motors are moving forward but with a higher speed than the "left side"
    case TURN_RIGHT:
        SET_BIT(GPIO_PORTB_DATA_R,2);
        CLEAR_BIT(GPIO_PORTB_DATA_R,3);
        SET_BIT(GPIO_PORTB_DATA_R,4);
        CLEAR_BIT(GPIO_PORTB_DATA_R,5);

        Speed (10,70);
        break;

     //  5- Rotation : the "right side" and the "left side" are moving but in opposite directions
    case ROTATE:
        SET_BIT(GPIO_PORTB_DATA_R,2);
        CLEAR_BIT(GPIO_PORTB_DATA_R,3);
        CLEAR_BIT(GPIO_PORTB_DATA_R,4);
        SET_BIT(GPIO_PORTB_DATA_R,5);
        Speed (30,30);
        // A delay should be added to reach a 90 degree rotation
        break;

    // 6- stops the car
    case STOP:
        CLEAR_BIT(GPIO_PORTD_DATA_R,2);
        CLEAR_BIT(GPIO_PORTD_DATA_R,3);
        CLEAR_BIT(GPIO_PORTD_DATA_R,4);
        CLEAR_BIT(GPIO_PORTD_DATA_R,5);

        Speed (1,1);
        break;

    default :
        break;
    }

}

