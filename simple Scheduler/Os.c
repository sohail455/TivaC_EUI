/******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Sohail Talaat
 ******************************************************************************/

#include "Os.h"
#include "Gpt.h"
#include "app.h"

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm(" CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm(" CPSID I")

/* Global variable store the Os Time */
static u32 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static u8 g_New_Time_Tick_Flag = 0;

/*********************************************************************************************/
void Os_start(void)
{
    /* Global Interrupts Enable */
    Enable_Interrupts();

    /* 
     * Set the Call Back function to call Os_NewTimerTick
     * this function will be called every SysTick Interrupt (20ms)
     */
    SysTick_SetCallBack(Os_NewTimerTick);

    /* Start SysTickTimer to generate interrupt every 20ms */
    SysTick_Start(OS_BASE_TIME);

    System_init();
    /* Start the Os Scheduler */
    Os_Scheduler();
}

/*********************************************************************************************/
void Os_NewTimerTick(void)
{
    /* Increment the Os time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*********************************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {
        /* Code is only executed in case there is a new timer tick */
        if(g_New_Time_Tick_Flag == 1)
        {
            switch(g_Time_Tick_Count)
            {
            case 20:
            case 10:
                Read_Button_t();
                g_New_Time_Tick_Flag = 0;
                break;

            case 30:
                Read_Button_t();
                LCD_Refresh_t();
                g_New_Time_Tick_Flag = 0;
                g_Time_Tick_Count=0;
                break;
            }
        }
    }

}
/*********************************************************************************************/
