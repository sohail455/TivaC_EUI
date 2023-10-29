/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : LCD                                                     */
/* !Description     : LCD implementation                                      */
/*                                                                            */
/* !File            : LCD.c                                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car @EME - EUI                                    */
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
/* !Designed by     : Sohail talaat                  !Date : SEP 9, 2023      */
/* !Coded by        : Sohail talaat                  !Date : SEP 9, 2023      */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include "../../GeneralFunctions/Bit_Math.h"
#include "../../GeneralFunctions/std_types.h"
#include "../../GeneralFunctions/hw_gpio.h"
#include "../../GeneralFunctions/Delay.h"
#include "../../MCAL/GPIO/GPIO.h"

/*! Include the module header file                                            */
#include "LCD.h"

/******************************************************************************/
/******************************** GLOBAL VARIABLES ****************************/
/******************************************************************************/
uint8_t counter;

/******************************************************************************/
/*! \Description : Initialize the LCD Module and GPIO Pins used in LCD        */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void LCD_vidInit(void)
{
    /*SET THE CONFIGRATION FOR THE GPIO PINS THAN WILL BE CONNECTED TO THE LCD*/
    GPIO_vidInitPort(LCD_DATA_PORT_ID);
    GPIO_vidInitPort(LCD_CONTROL_PORT_ID);

    GPIO_vidOutputPin(LCD_DATA_PORT_ID , LCD_D0);
    GPIO_vidOutputPin(LCD_DATA_PORT_ID , LCD_D1);
    GPIO_vidOutputPin(LCD_DATA_PORT_ID , LCD_D2);
    GPIO_vidOutputPin(LCD_DATA_PORT_ID , LCD_D3);

    GPIO_vidOutputPin(LCD_CONTROL_PORT_ID , LCD_EN);
    GPIO_vidOutputPin(LCD_CONTROL_PORT_ID , LCD_RS);


    GPIO_vidWritePin(LCD_DATA_PORT_ID, LCD_D0, 0);
    GPIO_vidWritePin(LCD_DATA_PORT_ID, LCD_D1, 0);
    GPIO_vidWritePin(LCD_DATA_PORT_ID, LCD_D2, 0);
    GPIO_vidWritePin(LCD_DATA_PORT_ID, LCD_D3, 0);

    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 0);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_RS, 0);


    LCD_sendCommand(0x02);
    LCD_sendCommand(0x28);
    LCD_sendCommand(0x0C);
    LCD_sendCommand(0x06);
    LCD_sendCommand(0x01);
}

/******************************************************************************/
/*! \Description :  send nibble in the command mode                           */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/

void LCD_sendCommand(unsigned char command)
{
    uint32_t port_value=0;
    uint32_t value=0;
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_RS, 0);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 1);
    /* Enable LCD E=1 */
    delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

    port_value= GPIO_u8ReadPort(LCD_DATA_PORT_ID);
    value = (port_value & 0xF0 )|((command & 0xF0)>>4);

    INSERT_VALUE(LCD_DATA_PORT_REG,LCD_D0,4,value);
    delay_ms(1);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 0);
    delay_ms(1);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 1); /* Enable LCD E=1 */
    delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
    port_value= GPIO_u8ReadPort(LCD_DATA_PORT_ID);
    value= (port_value & 0xF0 )|((command & 0x0F));
    INSERT_VALUE(LCD_DATA_PORT_REG,LCD_D0,4,value); /* out the required command to the data bus D0 --> D7 */
    delay_ms(1); /* delay for processing Tdsw = 100ns */
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 0); /* Disable LCD E=0 */
    delay_ms(1); /* delay for processing Th = 13ns */
}

/******************************************************************************/
/*! \Description :  send nibble in the data mode                              */
/*! \return      None                                                         */
/*! \arguments   uint8_t Copy_u8NibbleCopy                                    */
/******************************************************************************/
void LCD_displayCharacter(unsigned char data)
{
    uint32_t port_value=0;
    uint32_t value=0;
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_RS, 1);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 1);
    /* Enable LCD E=1 */
    delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

    port_value= GPIO_u8ReadPort(LCD_DATA_PORT_ID);
    value = (port_value & 0xF0 )|((data & 0xF0)>>4);

    INSERT_VALUE(LCD_DATA_PORT_REG,LCD_D0,4,value);
    delay_ms(1);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 0);
    delay_ms(1);
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 1); /* Enable LCD E=1 */
    delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
    port_value= GPIO_u8ReadPort(LCD_DATA_PORT_ID);
    value= (port_value & 0xF0 )|((data & 0x0F));
    INSERT_VALUE(LCD_DATA_PORT_REG,LCD_D0,4,value); /* out the required command to the data bus D0 --> D7 */
    delay_ms(1); /* delay for processing Tdsw = 100ns */
    GPIO_vidWritePin(LCD_CONTROL_PORT_ID, LCD_EN, 0); /* Disable LCD E=0 */
    delay_ms(1); /* delay for processing Th = 13ns */
}




/******************************************************************************/
/*! \Description :  write string on the LCD                                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t* Copy_ptr_u8StringCopy                            */
/******************************************************************************/

void LCD_vidWriteString (uint8_t* Copy_ptr_u8StringCopy)
{
    uint8_t i;
    /*loop into string till reach null*/
    for(i=0; Copy_ptr_u8StringCopy[i] != '\0'; i++)
    {
        /*print the each single character individually*/
        LCD_displayCharacter(Copy_ptr_u8StringCopy[i]);
    }
}

/******************************************************************************/
/*! \Description :  move the lcd cursor to certain position                   */
/*! \return         None                                                      */
/*! \arguments      uint8_t Copy_u8column , uint8_t Copy_u8row                */
/******************************************************************************/
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
    LCD_sendCommand(lcd_memory_address | 0x80);
}

/******************************************************************************/
/*! \Description :  clear the lcd                                             */
/*! \return         None                                                      */
/*! \arguments      None                                                      */
/******************************************************************************/
void LCD_vidClearScreen(void){
    LCD_sendCommand(0x01);
    counter=0;
}

/******************************************************************************/
/*! \Description :  write number on  the LCD                                  */
/*! \return         None                                                      */
/*! \arguments      uint16_t Copy_u16num                                      */
/******************************************************************************/
void integer_to_string(uint32_t num,uint8_t *str)
{
    uint32_t rem=0;
    uint32_t i=0;
    uint32_t len =0;
    uint32_t size;
    if(num == 0)
    {
        str[0]=0+'0';
        str[1]='\0';
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
    uint32_t j=0;
    for(;j<i/2;j++)
    {
        char chr = str[size-j];
        str[size-j] = str[j];
        str[j] = chr;
        len--;
    }
}
void LCD_vidWriteNumber (uint32_t Copy_u16num ){

    uint8_t buff[16]; /* String to hold the ascii result */
    integer_to_string(Copy_u16num,buff); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
    LCD_vidWriteString(buff); /* Display the string */

}
