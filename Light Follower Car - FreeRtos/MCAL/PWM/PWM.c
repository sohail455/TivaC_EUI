/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-Controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : PWM                                                     */
/* !Description     : PWM Module implementation                               */
/*                                                                            */
/* !File            : Motor.c                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous Car @EME-EUI  (CLASS 1)                      */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Mahmoud Emara                    !Date : SEP 11, 2023   */
/* !Coded by        : Mahmoud Emara                    !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/


/*! Include the module header file                                            */
#include "PWM.h"

/*! Includes                                                                  */
#include "../../GeneralFunctions/std_types.h"
#include "../../GeneralFunctions/Bit_Math.h"
#include "../../GeneralFunctions/hw_gpio.h"
#include "../GPIO/GPIO.h"



/******************************************************************************/
/*! \Description Initialise the PWM Prehpiral  and AF pins used               */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void PWM_vidInit(void)
{
    SET_BIT(SYSCTL_RCGCPWM_R,0);

    SET_BIT(SYSCTL_RCGCGPIO_R,1);

    SET_BIT(GPIO_PORTB_AFSEL_R,6);
    SET_BIT(GPIO_PORTB_AFSEL_R,4);

    GPIO_PORTB_LOCK_R = 0X4C4F434B;
    GPIO_PORTB_CR_R  = 0X1F;

    GPIO_PORTB_PCTL_R &= ~0xFF000000; /*                         */
    INSERT_VALUE(GPIO_PORTB_PCTL_R,24,4,4);
    INSERT_VALUE(GPIO_PORTB_PCTL_R,16,4,4);

    SET_BIT(GPIO_PORTB_DEN_R,6);
    SET_BIT(GPIO_PORTB_DEN_R,4);

    CLR_BIT(SYSCTL_RCC_R,20);
    INSERT_VALUE(SYSCTL_RCC_R,17,3,0);


    /* PWM0 channel 0 setting */
    PWM0_0_CTL_R &= ~(1<<0);    /* Disable Generator 0 counter */
    PWM0_0_CTL_R &= ~(1<<1);    /* select down count mode of counter 0*/
    PWM0_0_GENA_R = 0x0000008C; /* Set PWM output when counter reloaded and CLR when matches PWMCMPA */
    PWM0_0_LOAD_R = 16000;      /* set load value for 1kHz (16MHz/16000) */
//    PWM0_0_CTL_R = 1;           /* Enable Generator 0 counter */

    /* PWM0 channel 2 setting */
    PWM0_1_CTL_R &= ~(1<<0);    /* Disable Generator 1 counter */
    PWM0_1_CTL_R &= ~(1<<1);    /* select down count mode of counter 1*/
    PWM0_1_GENA_R = 0x0000008C; /* Set PWM output when counter reloaded and CLR when matches PWMCMPA */
    PWM0_1_LOAD_R = 16000;      /* set load value for 1kHz (16MHz/16000) */
//    PWM0_1_CTL_R = 1;           /* Enable Generator 1 counter */

    PWM0_ENABLE_R = 0x05;       /* Enable PWM0 channel 0 , 2 output */
}

/******************************************************************************/
/*! \Description Set the duty cycle of a given channel                        */
/*! \return      None                                                         */
/*! \arguments   arg 1                                                        */
/*                      Name : Copy_Channel_ID                                */
/*                      type : Channel_ID (enum)                              */
/*                      Description : channel NO. (channel0 - channel1)       */
/*               arg 2                                                        */
/*                      Name : Copy_u8DutyValue                               */
/*                      type : uint8_t                                        */
/*                      Description : Duty Cycle Value (0 - 100)              */
/*                                                                            */
/******************************************************************************/
void PWM_vidSetDutyCycle(Channel_ID Copy_Channel_ID , uint8_t Copy_u8DutyValue)
{
    uint32_t local_u32CMPvalue = (16000 - ((16000*Copy_u8DutyValue)/100)) - 1 ;
    switch(Copy_Channel_ID)
    {
    case Channel0:
        PWM0_0_CMPA_R = local_u32CMPvalue ;
        PWM0_0_CTL_R = 1; /* Enable Generator 1 counter */
        break;
    case Channel2:
        PWM0_1_CMPA_R = local_u32CMPvalue ;
        PWM0_1_CTL_R = 1; /* Enable Generator 1 counter */
        break;
    }

}



