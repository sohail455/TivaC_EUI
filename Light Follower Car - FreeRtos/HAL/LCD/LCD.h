/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : LCD                                                     */
/* !Description     : LCD implementation                                      */
/*                                                                            */
/* !File            : LCD.h                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car Project @EME - EUI                            */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Sohail Talaat                     !Date : SEP 09, 2023   */
/* !Coded by        : Sohail talaat                     !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

#ifndef LCD_H_
#define LCD_H_
#include "../../GeneralFunctions/hw_gpio.h"
#include "../../MCAL/GPIO/GPIO.h"

/******************************************************************************/
/*********************** Data Pins Configuration Macros ***********************/
/******************************************************************************/
#define LCD_DATA_PORT_REG       GPIO_PORTB_DATA_R
#define LCD_DATA_PORT_ID        GPIO_PORTB
#define LCD_D0                  PIN0                    /*GPIO_B0*/
#define LCD_D1                  PIN1                    /*GPIO_B1*/
#define LCD_D2                  PIN2                    /*GPIO_B2*/
#define LCD_D3                  PIN3                    /*GPIO_B3*/

/******************************************************************************/
/********************* Control Pins Configuration Macros  *********************/
/******************************************************************************/
#define LCD_CONTROL_PORT_REG    GPIO_PORTA_DATA_R
#define LCD_CONTROL_PORT_ID     GPIO_PORTA
#define LCD_EN                  PIN6                    /*GPIO_B5*/
#define LCD_RS                  PIN5                    /*GPIO_B7*/


/******************************************************************************/
/*************************** Functions Declaration ****************************/
/******************************************************************************/


/******************************************************************************/
/*! \Description : Initialize the LCD Module and GPIO Pins used in LCD        */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void LCD_vidInit(void);

/******************************************************************************/
/*! \Description :  send nibble in the data mode                              */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/

void LCD_vidSendNibbleData(uint8_t Local_u8_Nibble_Copy);

/******************************************************************************/
/*! \Description :  send nibble in the command mode                           */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/
void LCD_vidSendNibbleCMD(uint8_t Local_u8_Nibble_Copy);


/******************************************************************************/
/*! \Description :  write a character in the LCD                              */
/*! \return         None                                                      */
/*! \arguments      uint8_t Copy_u8DataCopy                                   */
/******************************************************************************/
void LCD_vidWriteChar (uint8_t local_u8_DataCopy);

/******************************************************************************/
/*! \Description :  write string on the LCD                                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t* Copy_ptr_u8StringCopy                            */
/******************************************************************************/
void LCD_vidWriteString (uint8_t* Copy_ptr_u8StringCopy);

/******************************************************************************/
/*! \Description :  move the lcd cursor to certain position                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t Copy_u8column , uint8_t Copy_u8row                */
/******************************************************************************/
void LCD_moveCursor(uint8_t local_u8column,uint8_t local_u8row);

/******************************************************************************/
/*! \Description :  clear the lcd                                             */
/*! \return         None                                                      */
/*! \arguments      None                                                      */
/******************************************************************************/
void LCD_vidClearScreen(void);

/******************************************************************************/
/*! \Description :  write number on  the LCD                                  */
/*! \return         None                                                      */
/*! \arguments      uint16_t Copy_u16num                                      */
/******************************************************************************/
void LCD_vidWriteNumber (uint32_t local_u16num );

void LCD_sendCommand(unsigned char command);

void LCD_displayCharacter(unsigned char data);


#endif /* 2_HAL_LCD_LCD_H_ */
