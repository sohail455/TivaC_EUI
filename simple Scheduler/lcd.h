 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "Platform_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 GPIO_PORTA
#define LCD_RS_PIN_ID                  GPIO_PIN6

#define LCD_RW_PORT_ID                 GPIO_PORTA
#define LCD_RW_PIN_ID                  GPIO_PIN7

#define LCD_E_PORT_ID                  GPIO_PORTE
#define LCD_E_PIN_ID                   GPIO_PIN4

#define LCD_FIRST_DATA_PORT_ID         GPIO_PORTA
#define LCD_SECOND_DATA_PORT_ID        GPIO_PORTE

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(s8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const s8 *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const s8 *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(s32 data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
