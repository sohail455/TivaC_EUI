/*
 * Keypad.h
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_PORT          1
#define COL_PIN0             0
#define COL_PIN1             1
#define COL_PIN2             2
#define COL_PIN3             3
#define ROW_PIN0             4
#define ROW_PIN1             5
#define ROW_PIN2             6
#define ROW_PIN3             7

#define COLS_NUM            4
#define KEYPAD_GET_PRESSED   0




unsigned char KeyPad_GetValue(void);



#endif /* KEYPAD_H_ */
