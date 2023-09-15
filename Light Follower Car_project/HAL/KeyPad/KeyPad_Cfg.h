/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  KeyPad_Cfg.h
 *        Layer:  HAL
 *      Version:  1.00
 *
 *  Description:  This file contains configuration data for interfacing with a keypad.
 *
 *   - FIRST_OUTPUT and FIRST_INPUT are defined for the first output and input pins of the keypad.
 *   - NO_KEY is defined to represent no key press.
 *   - ROWS and COLS specify the number of rows and columns in the keypad matrix.
 *
 *   - The KEYPAD_PRG conditional block contains the configuration of the keypad key values in a 4x4 matrix.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  IMPORTANT NOTES:
 *   - Ensure that this code is used in conjunction with appropriate keypad driver functions.
 *   - Verify that the GPIO pins and keypad matrix configuration match the actual hardware connections.
 *********************************************************************************************************************/


#ifndef HAL_KEYPAD_CFG_H_
#define HAL_KEYPAD_CFG_H_

#define FIRST_OUTPUT GPIO_PIN0
#define FIRST_INPUT  GPIO_PIN4
#define NO_KEY  'T'

#define ROWS 4
#define COLS 4

#if KEYPAD_PRG
static u8 KeysArr[ROWS][COLS] = {
                                 {'1','2','3','-'},
                                 {'4','5','6','*'},
                                 {'7','8','9','/'},
                                 {'C','0','=','+'},};
#endif



#endif /* HAL_KEYPAD_CFG_H_ */
