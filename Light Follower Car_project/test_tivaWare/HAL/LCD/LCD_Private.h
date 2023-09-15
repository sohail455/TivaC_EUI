/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  LCD_Private.h
 *        Layer:  HAL
 *      Version:  1.0
 *
 *  Description:  Private header file for LCD module.
 *
 *********************************************************************************************************************/


#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H


#define LINE0_ADD ((u8)0x80)
#define LINE1_ADD ((u8)0x80+(u8)0x40)
#define CGRAM_ADDRESS ((u8)0x40)


void LCD_WriteData(u8 data);
void LCD_WriteInstruction(u8 instruction);


#endif
