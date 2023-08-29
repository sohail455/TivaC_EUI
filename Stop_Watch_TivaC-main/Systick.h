/*
 * Systick.h
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYSTICK_MILI    4000


void Sys_init(unsigned long delay);

void Systick_SetCallBack(void (* copy_ptr)(void));


#endif /* SYSTICK_H_ */
