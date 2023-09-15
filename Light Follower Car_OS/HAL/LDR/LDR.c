#include "HAL/LDR/LDR.h"

void LDR_Init(void)
{
    ADC_Init();
}
u16 Ldr_getValue(LDR_t ldrNumber)
{
    u16 result;

    if (ldrNumber == LDR0)
    {
        result = ADC_getValue(ADCNUM0);
    }
    else
    {
        result = ADC_getValue(ADCNUM1);

    }
    return result;

}
