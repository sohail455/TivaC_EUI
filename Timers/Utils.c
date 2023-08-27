#include "Platform_Types.h"

void delay(u32 delay)
{
    u32 j=0;
    for(; j<delay * 762; j++);
}


