#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

uint32_t reads1=0;
uint32_t reads0=0;
uint32_t diff=0;
uint32_t arr1[10] = {0};
uint32_t arr2[10] = {0};

void LDR_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
    {
    }
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC1))
    {
    }
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
    {
    }
    GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_2 | GPIO_PIN_3);
    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH5 | ADC_CTL_IE |ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 0);
    ADCSequenceConfigure(ADC1_BASE, 1, ADC_TRIGGER_PROCESSOR, 1);
    ADCSequenceStepConfigure(ADC1_BASE, 1, 0, ADC_CTL_CH4 | ADC_CTL_IE |ADC_CTL_END);
    ADCSequenceEnable(ADC1_BASE, 1);


}

void LDR_RUNNABLE(void)
{
    ADCProcessorTrigger(ADC0_BASE, 0);
    ADCSequenceDataGet(ADC0_BASE, 0, &reads1);

    ADCProcessorTrigger(ADC1_BASE, 1);
    ADCSequenceDataGet(ADC1_BASE, 1, &reads0);



    if(reads0<reads1)
        diff = reads1-reads0;
    else
        diff = reads0-reads1;
}
