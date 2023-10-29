/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-Controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : SYSTICK Core Peripheral                                 */
/* !Description     : SYSTICK Peripheral Source File Implementation           */
/*                                                                            */
/* !File            : STK.c                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : MEGA Project @EME - EUI                                 */
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
/* !Designed by     : Mazen Tamer                      !Date : SEP 09, 2023   */
/* !Coded by        : Mazen Tamer                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 09, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/*********************************** INCLUDES *********************************/
/******************************************************************************/

#include <GeneralFunctions/Bit_Math.h>
#include <GeneralFunctions/hw_gpio.h>
#include <GeneralFunctions/std_types.h>
#include <MCAL/SysTick/SysTick.h>

/******************************************************************************/
/******************************* GLOBAL VARIABLES *****************************/
/******************************************************************************/

static void (*Glob_ptrFunction)(void);
void STK_vidHandler(void);

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Microseconds  */
/*! \return      None                                                         */
/*! \arguments   Copy_u32Microseconds       Delay in microseconds             */
/******************************************************************************/

void STK_vidStartUS(uint32_t Copy_u32Microseconds)
{
    NVIC_ST_RELOAD_R = ((F_CPU / MICROSECOND) * Copy_u32Microseconds) - 1U;
    NVIC_ST_CURRENT_R = 0x01;
    SET_BIT(NVIC_ST_CTRL_R, CLK_SRC);

#if INTERRUPT == ON

    SET_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);

#elif INTERRUPT == OFF

    CLR_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);
    while (GET_BIT(NVIC_ST_CTRL_R, COUNT) == 0){};

#endif
}

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Milliseconds  */
/*! \return      None                                                         */
/*! \arguments   Copy_u32Milliseconds       Delay in milliseconds             */
/******************************************************************************/

void STK_vidStartMS(uint32_t Copy_u32Milliseconds)
{
    NVIC_ST_RELOAD_R = ((F_CPU / MILLISECOND) * Copy_u32Milliseconds) - 1;
    NVIC_ST_CURRENT_R = 0x01;
    SET_BIT(NVIC_ST_CTRL_R, CLK_SRC);

#if INTERRUPT == ON

    SET_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);

#elif INTERRUPT == OFF

    CLR_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);
    while (GET_BIT(NVIC_ST_CTRL_R, COUNT) == 0){};

#endif
}

/******************************************************************************/
/*! \Description : Set-up the SYSTICK Timer To Create Delays in Seconds       */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void STK_vidStartSEC(void)
{
    NVIC_ST_RELOAD_R = F_CPU - 1;
    NVIC_ST_CURRENT_R = 0x01;
    SET_BIT(NVIC_ST_CTRL_R, CLK_SRC);

#if INTERRUPT == ON

    SET_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);

#elif INTERRUPT == OFF

    CLR_BIT(NVIC_ST_CTRL_R, INTEN);
    SET_BIT(NVIC_ST_CTRL_R, ENABLE);
    while (GET_BIT(NVIC_ST_CTRL_R, COUNT) == 0){};

#endif
}

/******************************************************************************/
/*! \Description : Stops the SYSTICK Timer                                    */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void STK_vidStopCounter(void)
{
    NVIC_ST_CURRENT_R = 0x01;
    CLR_BIT(NVIC_ST_CTRL_R, ENABLE);
}

/******************************************************************************/
/*! \Description : Sets the SYSTICK Interrupt Callback Function               */
/*! \return      None                                                         */
/*! \arguments   Copy_ptrFunction            Pointer to the CB Function       */
/******************************************************************************/

void STK_vidSetInterruptCallback(void(*Copy_ptrFunction)(void))
{
    Glob_ptrFunction = Copy_ptrFunction;
}

/******************************************************************************/
/*! \Description : SYSTICK Interrupt Handler                                  */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void STK_vidHandler(void)
{
    (*Glob_ptrFunction)();
}
