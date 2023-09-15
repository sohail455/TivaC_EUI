/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  LCD.c
 *        Layer:  HAL
 *      Version:  1.0
 *
 *  Description:  LCD Main file
 *
 *********************************************************************************************************************/

#include "../../LIB/Platform_Types.h"
#include "../../LIB/Std_Types.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "../../LIB/UTILS.h"
#include "LCD_Cfg.h"
#include "../../LIB/Bit_Math.h"


/*
 * Function: LCD_Init
 * Description: Initializes the LCD.
 * Input: None
 * Output: None
 */

void LCD_Init(void)
{
    delay(100);
    LCD_WriteInstruction(0x38);
    LCD_WriteInstruction(0x0C);
    LCD_WriteInstruction(0x01);
    delay(80);
    LCD_WriteInstruction(0x06);
}


/*
 * Function: LCD_WriteString
 * Description: Writes a null-terminated string to the LCD.
 * Input: str - Pointer to the string to be written.
 * Output: None
 */

void LCD_WriteString(u8 *str)
{
    u8 i;
    for (i = 0; str[i] != 0; i++)
    {
        LCD_WriteChar(str[i]);
    }

}

/*
 * Function: LCD_WriteChar
 * Description: Writes a single character to the LCD.
 * Input: character - The character to be written.
 * Output: None
 */

void LCD_WriteChar(u8 character)
{
    LCD_WriteData(character);
}


/*
 * Function: LCD_WriteNumber
 * Description: Writes a signed 32-bit integer as a string to the LCD.
 * Input: num - The number to be written.
 * Output: None
 */

void LCD_WriteNumber(s32 num)
{
    u8 str[33];
    s32 rem;
    u8 index = (u8) 0;
    Sign_type sign = POSITIVE;
    if (num == 0)
    {
        LCD_WriteChar('0');
        return;
    }

    if (num < 0)
    {
        num = -num;
        sign = NEGATIVE;
    }

    while (num)
    {
        rem = num % 10;
        num /= 10;
        str[index] = (u8)(rem +'0');
        index++;
    }
    if (sign)
    {
        str[index] = '-';
        index++;
    }
    for (; index > (u8)0; index--)
    {
        LCD_WriteChar(str[index - (u8)1]);
    }

}


/*
 * Function: LCD_Clear
 * Description: Clears the LCD screen.
 * Input: None
 * Output: None
 */

void LCD_Clear(void){
    LCD_WriteInstruction((u8)0x01);
    delay((u32)1);
}

/*
 * Function: LCD_WriteData
 * Description: Writes a byte of data to the LCD.
 * Input: data - The data byte to be written.
 * Output: None
 */

void LCD_WriteData(u8 data)
{
    /* Set RS pin to indicate data mode */


    GPIO_SetPinValue(RS_PORT, RS_PIN, GPIO_PIN_HIGH);

    /* Set value for each pin on different ports according to LCD configuration */
    GPIO_SetPinValue(D0_PORT, DO_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)0));
    GPIO_SetPinValue(D1_PORT, D1_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)1));
    GPIO_SetPinValue(D2_PORT, D2_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)2));
    GPIO_SetPinValue(D3_PORT, D3_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)3));
    GPIO_SetPinValue(D4_PORT, D4_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)4));
    GPIO_SetPinValue(D5_PORT, D5_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)5));
    GPIO_SetPinValue(D6_PORT, D6_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)6));
    GPIO_SetPinValue(D7_PORT, D7_PIN, (GPIO_PinValue_t)GET_BIT(data, (u8)7));

    /* Trigger the enable pin */
    GPIO_SetPinValue(EN_PORT, EN_PIN, GPIO_PIN_HIGH);
    delay((u32)2);
    GPIO_SetPinValue(EN_PORT, EN_PIN, GPIO_PIN_LOW);
    delay((u32)2);

}


/*
 * Function: LCD_GoTo
 * Description: Sets the cursor position on the LCD.
 * Input: line - The line number (0 or 1), cell - The cell (column) number.
 * Output: None
 */

void LCD_GoTo(u8 line, u8 cell)
{

    if (line == (u8)0)
    {
        LCD_WriteInstruction(LINE0_ADD + cell);
    }
    else if (line == (u8)1)
    {
        LCD_WriteInstruction(LINE1_ADD + cell);
    }else{

    }
}

/*
 * Function: LCD_WriteInstruction
 * Description: Writes an instruction to the LCD.
 * Input: instruction - The instruction to be written.
 * Output: None
 */

void LCD_WriteInstruction(u8 instruction)
{

    /* Set RS pin to indicate instruction mode */

    GPIO_SetPinValue(RS_PORT, RS_PIN, GPIO_PIN_LOW);

    /* Set value for each pin on different ports according to LCD configuration */
    GPIO_SetPinValue(D0_PORT, DO_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)0));
    GPIO_SetPinValue(D1_PORT, D1_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)1));
    GPIO_SetPinValue(D2_PORT, D2_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)2));
    GPIO_SetPinValue(D3_PORT, D3_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)3));
    GPIO_SetPinValue(D4_PORT, D4_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)4));
    GPIO_SetPinValue(D5_PORT, D5_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)5));
    GPIO_SetPinValue(D6_PORT, D6_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)6));
    GPIO_SetPinValue(D7_PORT, D7_PIN, (GPIO_PinValue_t)GET_BIT(instruction, (u8)7));

    /* Trigger the enable pin */

    GPIO_SetPinValue(EN_PORT, EN_PIN, GPIO_PIN_HIGH);
    delay((u32)2);
    GPIO_SetPinValue(EN_PORT, EN_PIN, GPIO_PIN_LOW);
    delay((u32)2);

}
