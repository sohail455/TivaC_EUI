

#ifndef HAL_LDR_LDR_H_
#define HAL_LDR_LDR_H_
#include "Platform_Types.h"
#include "MCAL/ADC/ADC.h"

typedef enum {
    LDR0,
    LDR1
}LDR_t;
void LDR_Init();
u16 Ldr_getValue(LDR_t ldrNumber);

#endif /* HAL_LDR_LDR_H_ */
