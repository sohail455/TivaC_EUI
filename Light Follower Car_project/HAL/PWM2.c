/*
 * pwm.c
 *
 *  Created on: Aug 31, 2023
 *      Author: pc
 */


#include <HAL/PWM2.h>
/*******************************
* ->Prototype:
*           void pwm_init(void)
* ->Description:
*           initializes PWM0 Module
* ->Returns:
*           None
* ->Arguments:
*           duty1: speed of the left side motors
*           duty2: speed of the right side motors
********************************/
void pwm_init (void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);

    GPIOPinConfigure((uint32_t)GPIO_PB6_M0PWM0);
    GPIOPinConfigure((uint32_t)GPIO_PB7_M0PWM1);
    GPIOPinTypePWM((uint32_t)GPIO_PORTB_BASE, (uint8_t)GPIO_PIN_6|(uint8_t)GPIO_PIN_7);

    //
    // Enable the PWM0 peripheral
    //

    // Wait for the PWM0 module to be ready.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
    {
    }
    //
    // Configure the PWM generator for count down mode with immediate updates
    // to the parameters.
    //
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    //
    // Set the period. For a 50 KHz frequency, the period = 1/50,000, or 20
    // microseconds. For a 16 MHz clock, this translates to 320 clock ticks.
    // Use this value to set the period.
    //
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 320);
}

/*******************************
* ->Prototype:
*           void pwm_speed(int duty1,int duty2)
* ->Description:
*           changes the speed of motors using PWM
* ->Returns:
*           None
* ->Arguments:
*           duty1: speed of the left side motors
*           duty2: speed of the right side motors
********************************/

void pwm_speed(int32_t duty1,int32_t duty2)
{
    //disable pwm to reconfigure speed
    PWMGenDisable(PWM0_BASE, PWM_GEN_0);
    // Set the pulse width of PWM1 and PMW0  for the given duty cycle.
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, (310*duty1)/100);
    //

    //
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, (310*duty2)/100);
    //
    // Start the timers in generator 0.
    //
    //
    // Enable the outputs.
    //
    PWMOutputState(PWM0_BASE, (PWM_OUT_0_BIT | PWM_OUT_1_BIT), true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}
