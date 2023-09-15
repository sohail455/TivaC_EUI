
#include "Platform_Types.h"
#include "Register_Map.h"
#include "RCC.h"
/* configure the system to get its clock from the PLL with Frquency 16Mhz */
void PLL_Init(void)
{
    /* 1) Configure the system to use RCC2 for advanced features
     such as 400 MHz PLL and non-integer System Clock Divisor */
    SYSCTL->RCC2 |= SYSCTL_RCC2_USERCC2_MASK;

    /* 2) Bypass PLL while initializing, Don’t use PLL while init. Precision internal oscillator is used as OSCSRC2 = 0x01 */
    SYSCTL->RCC2 |= SYSCTL_RCC2_BYPASS2_MASK;

    /* 3) Select the crystal value and oscillator source */
    SYSCTL->RCC &= ~SYSCTL_RCC_XTAL_MASK; /* clear XTAL field */
    SYSCTL->RCC |= SYSCTL_RCC_XTAL_16MHZ; /* Set the XTAL bits for 16 MHz crystal */

    SYSCTL->RCC2 &= ~SYSCTL_RCC2_OSCSRC2_MASK; /* clear oscillator source field (OSCSRC2 bits) */
    SYSCTL->RCC2 |= SYSCTL_RCC2_OSCSRC2_MOSC; /* configure for main oscillator source */

    /* 4) Activate PLL by clearing PWRDN2 */
    SYSCTL->RCC2 &= ~SYSCTL_RCC2_PWRDN2_MASK;

    /* 5) Set the desired system divider and the system divider least significant bit */
    SYSCTL->RCC2 |= SYSCTL_RCC2_DIV400_MASK; /* use 400 MHz PLL */

    SYSCTL->RCC2 = (SYSCTL->RCC2 & ~SYSCTL_RCC2_SYSDIV2_MASK) /* clear system clock divider field */
    | (SYSDIV2_VALUE << SYSCTL_RCC2_SYSDIV2_BIT_POS); /* configure for 16MHz clock */

    /* 6) Wait for the PLL to lock by polling PLLLRIS bit */
    while (!(SYSCTL->RIS & SYSCTL_RIS_PLLLRIS_MASK))
        ;

    /* 7) Enable use of PLL by clearing BYPASS2 */
    SYSCTL->RCC2 &= ~SYSCTL_RCC2_BYPASS2_MASK;
}




