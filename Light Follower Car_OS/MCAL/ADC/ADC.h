/*
 * ADC.h
 *
 *  Created on: Sep 10, 2023
 *      Author: eme
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include <stdint.h>
#include <stdbool.h>
#include "Platform_Types.h"
#include "Register_Map.h"
#include "MCAL/GPIO/GPIO_Interfaces.h"
typedef enum
{
    ADCNUM0, ADCNUM1
} ADC_t;


void ADC_Init(void);
uint16_t ADC_getValue(ADC_t adcNumber);





#endif /* MCAL_ADC_ADC_H_ */
