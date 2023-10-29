/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Module          : scheduler                                               */
/* !Description     : scheduler Module implementation                         */
/*                                                                            */
/* !File            : scheduler.c                                             */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous Car @EME-EUI  (CLASS 1)                      */
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
/* !Designed by     : Mahmoud Emara                    !Date : SEP 11, 2023   */
/* !Coded by        : Mahmoud Emara                    !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/*! Include the module header file                                            */
#include <OS/scheduler.h>
#include "../MCAL/SysTick/SysTick.h"

volatile uint16_t Glob_TaskCounts= 0;
volatile uint16_t Glob_TickCounts = 0;
volatile uint16_t Glob_TimeCount = 0;

volatile uint8_t Glob_u8TickFlag = 0;

void scheduler_start(void);

void OS_Start(void)
{
    STK_vidSetInterruptCallback(scheduler_start);
    STK_vidStartMS(10);
}
void create_task(void (*Task)(void) , uint16_t ms_periodicity  )
{
    if(Glob_TaskCounts < NUM_OF_TASKS )
    {
        Glob_OsTasks[Glob_TaskCounts].Period = ms_periodicity ;
        Glob_OsTasks[Glob_TaskCounts].TaskHandler = Task ;
        Glob_TaskCounts++;
    }
    else
    {
        /*  Do nothing */
    }
}

void tasks_scheduler(void)
{
    uint16_t local_TaskIndex = 0;

    while (1)
    {
        while (Glob_u8TickFlag)
        {
            for(local_TaskIndex = 0 ; local_TaskIndex < Glob_TaskCounts ; local_TaskIndex++)
            {
                if(( Glob_TickCounts % Glob_OsTasks[local_TaskIndex].Period ) == 0 )
                {
                    Glob_OsTasks[local_TaskIndex].TaskHandler();
                }
                else
                {
                    /*      */
                }
            }
            Glob_u8TickFlag = 0;
            }
        }
    }

    void scheduler_start(void)
    {
        Glob_u8TickFlag = 1;
        Glob_TickCounts++;
        if (Glob_TickCounts % 100 == 0)
        {
            Glob_TimeCount++;
        }
    }




