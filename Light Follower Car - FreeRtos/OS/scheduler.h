/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Module          : scheduler                                               */
/* !Description     : scheduler Module Header file                            */
/*                                                                            */
/* !File            : scheduler.h                                             */
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

#ifndef OS_SCHEDULER_H_
#define OS_SCHEDULER_H_

#include "../GeneralFunctions/std_types.h"

#define NUM_OF_TASKS        10

typedef struct
{
    void (*TaskHandler)(void);
    uint16_t Period;
}Task;

static Task Glob_OsTasks[NUM_OF_TASKS] = {NULL_PTR};

void OS_Start(void);
void tasks_scheduler(void);
void create_task(void (*Task)(void) , uint16_t period  );


#endif /* OS_SCHEDULER_H_ */
