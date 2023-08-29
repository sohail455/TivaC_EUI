/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.h
 *
 * Description: Headr file for the Keypad driver
 *
 * Author: David & Sohail & Hossam
 *
 *******************************************************************************/
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


/*
 * Description :
 *  function to get numbers from keypad:
 */

unsigned char KeyPad_GetValue(void);

u8 keypad_map(u8 value);

#endif /* KEYPAD_H_ */
