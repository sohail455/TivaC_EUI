/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.h
 *
 * Description: header file for the Systick driver
 *
 * Author: David & Sohail & Hossam
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYSTICK_MILI    4000


void Sys_init(unsigned long delay);

void Systick_SetCallBack(void (* copy_ptr)(void));


#endif /* SYSTICK_H_ */
