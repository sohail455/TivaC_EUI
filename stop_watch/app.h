/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:   David & Sohail & Hossam
 *         File:  app.h
 *        Layer:  APP
 *       Module:  app
 *      Version:  1.00
 *
 *  Description:  header file of StopWatch
 *
 *********************************************************************************************************************/

#ifndef APP_H_
#define APP_H_
#include"Platform_Types.h"

void increment_seconds(void);
void delay_ms(u32 m);
void start_app(void);
void PORTF_HANDLER(void);

#endif /* APP_H_ */
