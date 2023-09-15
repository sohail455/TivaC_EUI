/*
 * pwm.c
 *
 *  Created on: Aug 31, 2023
 *      Author: pc
 */


#include <HAL/PWM2.h>
/**************************
*! \prototype void pwm()
*! \Description function to initialize PWM module 0
*! \return      None
*! \arguments   None
**************************/
void pwm(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);

    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    GPIOPinConfigure(GPIO_PB7_M0PWM1);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6|GPIO_PIN_7);

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

/**************************
*! \prototype void pwm_speed(int duty1,int duty2)
*! \Description function to change PWM speed
*! \return      None
*! \arguments   duty1: speed of PWM0   duty2:speed of PWM1                                                         */

void pwm_speed(int duty1,int duty2)
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
