/*
 * LDR.h
 *
 *  Created on: Sep 1, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef HAL_LDR_H_
#define HAL_LDR_H_
extern uint32_t reads1;
extern uint32_t reads0;
extern uint32_t diff;
void LDR_init(void);
void LDR_RUNNABLE(void);

#endif /* HAL_LDR_H_ */
