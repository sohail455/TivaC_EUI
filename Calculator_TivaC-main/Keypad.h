/*
 * Keypad.h
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_PORT          1
#define COL_PIN0             3
#define COL_PIN1             2
#define COL_PIN2             1
#define COL_PIN3             0
#define ROW_PIN0             7
#define ROW_PIN1             6
#define ROW_PIN2             5
#define ROW_PIN3             4

#define COLS_NUM             4
#define KEYPAD_GET_PRESSED   0
extern unsigned char g_keypad_value;
extern unsigned char Int_Flag ;


unsigned char KeyPad_GetValue(void);
void PortB_interrupt_init (void)   ;



#endif /* KEYPAD_H_ */
