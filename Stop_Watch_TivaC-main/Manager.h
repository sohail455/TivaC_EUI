/*
 * Manager.h
 *
 *  Created on: Aug 28, 2023
 *      Author: eme
 */

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "Keypad.h"
#include"Std_Types.h"
#include"tm4c123gh6pm.h"


#ifndef MANAGER_H_
#define MANAGER_H_


/* Prototypes for the functions used in Manager.c */
void Start_Calc(void) ;
void Get_state (void) ;
void increment_seconds(void) ;
void delay_ms(u32 m) ;
void PORTF_HANDLER(void) ;

#endif /* MANAGER_H_ */
