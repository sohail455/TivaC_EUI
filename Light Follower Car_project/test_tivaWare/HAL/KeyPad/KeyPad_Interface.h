
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  [Your Name]
 *         File:  KeyPad_Interface.h
 *        Layer:  HAL
 *      Version:  [Version Number]
 *
 *  Description:  This file contains the interface for keypad initialization and key retrieval functions.
 *
 *   - KEYPAD_Init() is used to initialize the keypad.
 *   - KEYPAD_GetKey() is used to retrieve a key press from the keypad.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  IMPORTANT NOTES:
 *   - Ensure that this code is used in conjunction with appropriate keypad driver functions.
 *   - Verify that the interface functions are correctly implemented in the associated source file.
 *********************************************************************************************************************/


#ifndef HAL_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_INTERFACE_H_


void KEYPAD_Init(void);
u8 KEYPAD_GetKey(void);


#endif /* HAL_KEYPAD_INTERFACE_H_ */
