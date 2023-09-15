/*
 * UTILS.c
 *
 *  Created on: Aug 18, 2023
 *      Author: mo2a
 */


#include "Std_Types.h"
#include "Platform_Types.h"
#include "UTILS.h"


void delay(u32 ms)
{
    unsigned long volatile t;
    t = 762*ms;
    while(t){
        t--;
    }
}

