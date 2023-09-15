/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  LCD_Interface.h
 *        Layer:  HAL
 *      Version:  1.0
 *
 *  Description:  Interface header file for LCD module.
 *
 *********************************************************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_Init(void);
void LCD_WriteString(u8* str);
void LCD_WriteChar(u8 character);
void LCD_WriteNumber(s32 num);
void LCD_GoTo(u8 line,u8 cell);
void LCD_Clear(void);

#endif

