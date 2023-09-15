/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/
#include <stdint.h>

#include "Platform_Types.h"
#include "lcd.h"
#include "MCAL/GPIO/GPIO_Interfaces.h"
#include"MCAL/GPIO/GPIO_Private.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */

void delay(uint8_t d)
{
    uint32_t i=0;
    for(i=0; i<d * 762; i++);
}

void integer_to_string(s32 num,s8 *str)
{
    if(num < 0)/*if the number is negative*/
    {
        num *= -1;
        LCD_displayCharacter('-');
    }
    s32 rem=0;
    s32 i=0;
    s32 len =0;
    s32 size;
    if(num == 0)
    {
        str[0]= 0+'0';
        str[1]= '\0';
        return;
    }
    while(num!=0)
    {
        rem=num%10;
        str[i]=rem+'0';
        num/=10;
        i++;
    }
    str[i]='\0';
    size=i-1;
    u32 j=0;
    for(;j<i/2;j++)
    {
        s8 chr = str[size-j];
        str[size-j] = str[j];
        str[j] = chr;
        len--;
    }
}


void LCD_init(void)
{
    /* Configure the direction for RS, RW and E pins as output pins */
    GPIO_Config_t RS_config ={LCD_RS_PORT_ID,LCD_RS_PIN_ID,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
    GPIO_Config_t RW_config ={LCD_RW_PORT_ID,LCD_RW_PIN_ID,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
    GPIO_Config_t E_config ={LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};

    GPIO_Init(&RS_config,1);
    GPIO_Init(&RW_config,1);
    GPIO_Init(&E_config,1);

    /* Configure the data port as output port */

    GPIO_Config_t LcdPort_config[8]={
                                     {LCD_SECOND_DATA_PORT_ID,GPIO_PIN0,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                     {LCD_SECOND_DATA_PORT_ID,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                     {LCD_SECOND_DATA_PORT_ID,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                     {LCD_SECOND_DATA_PORT_ID,GPIO_PIN3,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}};


    GPIO_Init(LcdPort_config,4);
    LCD_sendCommand(LCD_GO_TO_HOME);
    LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
    LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
    LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(unsigned char command)
{
    Gpio_PortValue_t port_value=0;
    u32 value=0;
    GPIO_SetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,GPIO_PIN_LOW); /* Instruction Mode RS=0 */
    GPIO_SetPinValue(LCD_RW_PORT_ID,LCD_RW_PIN_ID,GPIO_PIN_LOW); /* write data to LCD so RW=0 */
    delay(1); /* delay for processing Tas = 50ns */
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_HIGH); /* Enable LCD E=1 */
    delay(1); /* delay for processing Tpw - Tdws = 190ns */

    GPIO_GetPortValue(LCD_SECOND_DATA_PORT_ID,&port_value);
    value = (port_value & 0xF0 )|((command & 0xF0)>>4);

    GPIO_SetPortValue(LCD_SECOND_DATA_PORT_ID,value);
    delay(1);
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_LOW);
    delay(1);
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_HIGH); /* Enable LCD E=1 */
    delay(1); /* delay for processing Tpw - Tdws = 190ns */
    GPIO_GetPortValue(LCD_SECOND_DATA_PORT_ID,&port_value);
    value= (port_value & 0xF0 )|((command & 0x0F));
    GPIO_SetPortValue(LCD_SECOND_DATA_PORT_ID,value); /* out the required command to the data bus D0 --> D7 */
    delay(1); /* delay for processing Tdsw = 100ns */
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_LOW); /* Disable LCD E=0 */
    delay(1); /* delay for processing Th = 13ns */
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(s8 data)
{
    Gpio_PortValue_t port_value=0;
    u32 value=0;
    GPIO_SetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,GPIO_PIN_HIGH); /* Instruction Mode RS=0 */
    GPIO_SetPinValue(LCD_RW_PORT_ID,LCD_RW_PIN_ID,GPIO_PIN_LOW); /* write data to LCD so RW=0 */
    delay(1);
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_HIGH); /* Enable LCD E=1 */
    delay(1); /* delay for processing Tpw - Tdws = 190ns */
    GPIO_GetPortValue(LCD_SECOND_DATA_PORT_ID,&port_value);
    value = (port_value & 0xF0 )|((data & 0xF0)>>4);
    GPIO_SetPortValue(LCD_SECOND_DATA_PORT_ID,value);
    delay(1);
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_LOW);
    delay(1);
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_HIGH); /* Enable LCD E=1 */
    delay(1); /* delay for processing Tpw - Tdws = 190ns */
    GPIO_GetPortValue(LCD_SECOND_DATA_PORT_ID,&port_value);
    value = (port_value & 0xF0 )|((data & 0x0F));
    GPIO_SetPortValue(LCD_SECOND_DATA_PORT_ID,value); /* out the required command to the data bus D0 --> D7 */
    delay(1); /* delay for processing Tdsw = 100ns */
    GPIO_SetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,GPIO_PIN_LOW); /* Disable LCD E=0 */
    delay(1);/* delay for processing Th = 13ns */
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const s8 *Str)
{
    unsigned char counter=0;
    unsigned char i = 0;
    while(Str[i] != '\0')
    {
        LCD_displayCharacter(Str[i]);
        i++;
        counter++;
        if(counter==16)
        {
            LCD_moveCursor(1, 0);
        }
    }
}


/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(unsigned char row,unsigned char col)
{
    unsigned char lcd_memory_address=0;

    /* Calculate the required address in the LCD DDRAM */
    switch(row)
    {
    case 0:
        lcd_memory_address=col;
        break;
    case 1:
        lcd_memory_address=col+0x40;
        break;
    case 2:
        lcd_memory_address=col+0x10;
        break;
    case 3:
        lcd_memory_address=col+0x50;
        break;
    }
    /* Move the LCD cursor to this specific address */
    LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const s8 *Str)
{
    LCD_moveCursor(row,col); /* go to to the required LCD position */
    LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */


void LCD_intgerToString(s32 data)
{
    s8 buff[16]; /* String to hold the ascii result */
    integer_to_string(data,buff); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
    LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
    LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
