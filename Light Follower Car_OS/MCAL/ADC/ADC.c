#include "ADC.h"

void ADC_Init(void)
{
    SYSCTL->RCGCADC |= 0x03;         /* Enable ADC0 and ADC1 clock */
    SYSCTL->RCGCGPIO |= 0x08;        /* Enable clock for Port D */
    GPIO_Config_t config[] = { { GPIO_PORTD, GPIO_PIN2, GPIO_PIN_INPUT,
                                 GPIO_PIN_ANALOG, GPIO_PIN_PUSHPULL,
                                 GPIO_PIN_FLOATING, GPIO_2MA_DRIVE },
                               { GPIO_PORTD, GPIO_PIN3, GPIO_PIN_INPUT,
                                 GPIO_PIN_ANALOG, GPIO_PIN_PUSHPULL,
                                 GPIO_PIN_FLOATING, GPIO_2MA_DRIVE } };
    GPIO_Init(config, 2);

    while ((SYSCTL->PRGPIO & 0x08) == 0)
    {
    } /* Wait for PD3 & PD2 to be ready*/

    while((SYSCTL-> PRADC & 0x03) == 0){

    }

    /*initialize ADC0*/
    ADC0->ACTSS &= ~(0x0008); /* Disable ADC0 sample sequencer 3 */
    ADC0->SSMUX3 &= ~(0x000F); /* Clear SS3 field */
    ADC0->SSMUX3 += 4; /* Set ADC0 SS3 to channel 4 (PD2) */
    ADC0->SSCTL3 = 0x0006; /* Enable interrupt and set the END bit */
    ADC0->ACTSS |= 0x0008; /* Enable ADC0 sample sequencer 3 */

    /*initialize ADC1*/
    ADC1->ACTSS &= ~(0x0008); /* Disable ADC1 sample sequencer 3 */
    ADC1->SSMUX3 &= ~(0x000F); /* Clear SS3 field */
    ADC1->SSMUX3 += 5; /* Set ADC0 SS3 to channel 5 (PD3) */
    ADC1->SSCTL3 = 0x0006; /* Enable interrupt and set the END bit */
    ADC1->ACTSS |= 0x0008; /* Enable ADC1 sample sequencer 3 */

}

uint16_t ADC_getValue(ADC_t adcNumber)
{
    uint16_t result;
    if (adcNumber == ADCNUM0)
    {
        ADC0->PSSI = 0x0008;                    /* Start conversion */
        while ((ADC0->RIS & 0x08) == 0)
        {
        }                                       /* Wait for conversion complete*/
        result = ADC0->SSFIFO3 & 0xFFF;         /* Get converted data from ADC0 SS3*/
        ADC0->ISC = 0x0008;                     /* Acknowledge completion*/
    }
    else if (adcNumber == ADCNUM1)
    {
        ADC1->PSSI = 0x0008;                    /* Start conversion*/
        while ((ADC1->RIS & 0x08) == 0)
        {
        }                                       /* Wait for conversion complete */
        result = ADC1->SSFIFO3 & 0xFFF;         /* Get converted data from ADC0 SS3*/
        ADC1->ISC = 0x0008;                     /* Acknowledge completion*/
    }

    return result;
}

