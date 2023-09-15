/*
 * Scheduler.h
 *
 *  Created on: Sep 10, 2023
 *      Author: eme
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "std_types.h"

#define Ticks_Time 4

#define NUM_OF_TASKS 3

void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);
void create_task (void (*TaskFunction)(), u32 ms_periodicity );
void tasks_scheduler(void);
void Systick_Handler (void);
void sheduler_init(void);

typedef struct {
    u32 Periodicity;
    void (*TaskFunction)(void);
}Task_TCB;




#endif /* SCHEDULER_H_ */
