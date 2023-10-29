/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : ADC                                                     */
/* !Description     : Read analog values                                      */
/*                                                                            */
/* !File            : ADC.c                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous car Project @EME - EUI                       */
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
/* !Designed by     : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/* !Coded by        : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include"../../GeneralFunctions/std_types.h"
#include"../../GeneralFunctions/Bit_Math.h"
#include"../../GeneralFunctions/hw_gpio.h"
#include"ADC.h"
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize ADC Sequencer                                   */
/*! \return      None                                                         */
/*! \arguments   Copy_enuSeq to select sequencer                              */
/******************************************************************************/
void ADC_vidInit(Sequencers Copy_enuSeq)
{
    SET_BIT(SYSCTL_RCGCADC_R,0);  /* Enable clock for ADC0 */
    SET_BIT(SYSCTL_RCGCGPIO_R,4); /*Enable clock for port E */

    /*switch to initiate the target sequencer*/
    switch(Copy_enuSeq)
    {
    case SEQ_0:

        /*Choose the ADC Pin*/
        /*
         *
         */
        CLR_BIT(ADC0_ACTSS_R , 0);    /* Disable Sequencer 1*/
        ADC0_EMUX_R |= 0;             /* Configure the trigger event for the sample sequencer 0 */
        /*Select your Target analog channel*/
        /*ADC0_SSMUX1_R = 0x2;*/          /* Select channel for input step*/
        SET_BIT(ADC0_SSCTL1_R , 0);   /* End of the Sequence for Sample Sequencer 0 step 0 */
        SET_BIT(ADC0_SSCTL1_R,  2);   /* Enabling Sample Interrupt for Sample Sequencer 0 step 0 */
        SET_BIT(ADC0_ACTSS_R , 0);    /* Enabling the Sample Sequencer 0 */
        break;

    case SEQ_1:

        CLR_BIT(GPIO_PORTE_AFSEL_R,1); /* Disable alternative for PE1 */
        CLR_BIT(GPIO_PORTE_DEN_R,1);   /* Configure the PE1 signals to be analog input */
        SET_BIT(GPIO_PORTE_AMSEL_R,1); /* The analog function of the PE1 is enabled */

        CLR_BIT(ADC0_ACTSS_R , 1);    /* Disable Sequencer 1*/
        ADC0_EMUX_R |= 0;             /* Configure the trigger event for the sample sequencer 1 */
        ADC0_SSMUX1_R = 0x2;          /* Select channel for input step*/
        SET_BIT(ADC0_SSCTL1_R , 1);   /* End of the Sequence for Sample Sequencer 1 step 0 */
        SET_BIT(ADC0_SSCTL1_R,  2);   /* Enabling Sample Interrupt for Sample Sequencer 1 step 0 */
        SET_BIT(ADC0_ACTSS_R , 1);    /* Enabling the Sample Sequencer 1 */
        break;

    case SEQ_2:

        SET_BIT(GPIO_PORTE_AFSEL_R, 2); /* Enable alternative for PE2 */
        CLR_BIT(GPIO_PORTE_DEN_R, 2);  /* Configure the PE2 signals to be analog input */
        SET_BIT(GPIO_PORTE_AMSEL_R, 2);/* The analog function of the PE2 is enabled */

        CLR_BIT(ADC0_ACTSS_R, 2);     /* Sample sequencer 2 is disabled */
        ADC0_EMUX_R &= ~(0xF000);      /* Set bits 15-12 to 0 to select software trigger */
        ADC0_SSMUX2_R = 1;             /* Set input channel to Ain1/PE2 */
        SET_BIT(ADC0_SSCTL2_R, 1);     /* Set bit 1 to mark the end of sequence */
        SET_BIT(ADC0_SSCTL2_R, 2);     /* Enable interrupt flag for the last sample */
        SET_BIT(ADC0_ACTSS_R, 2);      /* Sample sequencer 2 is enabled */
        break;

    case SEQ_3:

        SET_BIT(GPIO_PORTE_AFSEL_R,3); /* Enable alternative for PE3 */
        CLR_BIT(GPIO_PORTE_DEN_R,3);   /* Configure the PE3 signals to be analog input */
        SET_BIT(GPIO_PORTE_AMSEL_R,3); /* The analog function of the PE3 is enabled */

        CLR_BIT(ADC0_ACTSS_R,3);       /* Sample sequencer 3 is disabled */
        ADC0_EMUX_R = 0;
        ADC0_SSMUX3_R =0;
        SET_BIT(ADC0_SSCTL3_R,3);      /* The temperature sensor is read during the first sample of the sample sequence.*/
        SET_BIT(ADC0_SSCTL3_R,1);      /* This is the end of sequence.*/
        SET_BIT(ADC0_SSCTL3_R,2);
        SET_BIT(ADC0_ACTSS_R,3);       /* Sample sequencer 3 is enabled */
        break;

    default :
        /*Do Nothing*/
        break;
    }
}

/******************************************************************************/
/*! \Description : Read ADC value                                             */
/*! \return      Unsigned int -> 16 bit                                       */
/*! \arguments   Copy_enuSeq to select sequencer                              */
/******************************************************************************/
uint16_t ADC_u32ReadChannel(Sequencers Copy_enuSeq)
{
    uint16_t Loc_u32AdcRead ;

    /*switch to Read the target sequencer*/
    switch(Copy_enuSeq)
    {
    case SEQ_0:

        SET_BIT(ADC0_PSSI_R , 0);          /* Initiate the ADC conversion for Sample Sequencer 0 */
        while(!GET_BIT(ADC0_RIS_R , 0));   /* check for conversion completion */
        Loc_u32AdcRead = ADC0_SSFIFO0_R;   /* Read conversion result */
        SET_BIT(ADC0_ISC_R , 0);           /* Clear completion flag */
        break;

    case SEQ_1:
        SET_BIT(ADC0_PSSI_R , 1);          /* Initiate the ADC conversion for Sample Sequencer 1 */
        while(!GET_BIT(ADC0_RIS_R , 1));   /* check for conversion completion */
        Loc_u32AdcRead = ADC0_SSFIFO1_R;   /* Read conversion result */
        SET_BIT(ADC0_ISC_R , 1);           /* Clear completion flag */
        break;

    case SEQ_2:
        SET_BIT(ADC0_PSSI_R , 2);                  /* Initiate the ADC conversion for Sample Sequencer 2 */
        while(!GET_BIT(ADC0_RIS_R , 2));           /* check for conversion completion */
        Loc_u32AdcRead = ADC0_SSFIFO2_R;           /* Read conversion result */
        SET_BIT(ADC0_ISC_R , 2);                   /* Clear completion flag */
        break;

    case SEQ_3:
        SET_BIT(ADC0_PSSI_R , 3);                  /* Initiate the ADC conversion for Sample Sequencer 2 */
        while(!GET_BIT(ADC0_RIS_R , 3));           /* check for conversion completion */
        Loc_u32AdcRead = ADC0_SSFIFO3_R;           /* Read conversion result */
        SET_BIT(ADC0_ISC_R , 3);                   /* Clear completion flag */
        break;

    default:
        /*Do Nothing*/
        break;
    }

    return Loc_u32AdcRead;
}
