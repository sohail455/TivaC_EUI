/*
 * Buttons.h
 *
 *  Created on: 15 Sep 2023
 *      Author: pvc
 */

#ifndef HAL_BUTTONS_BUTTONS_H_
#define HAL_BUTTONS_BUTTONS_H_

#define BUTTON_PRESSED   0U


void Buttons_init(void);
u8 pushButton_startIsPressed();
u8 pushButton_stopIsPressed();

#endif /* HAL_BUTTONS_BUTTONS_H_ */
