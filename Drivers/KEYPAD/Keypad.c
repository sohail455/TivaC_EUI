/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: source file for the Keypad driver
 *
 * Author: David & Sohail & Hossam
 *
 *******************************************************************************/
#include "Platform_Types.h"
#include "GPIO_Interfaces.h"
#include "GPIO_Private.h"
#include "Keypad.h"
#include "Std_Types.h"

/*
 * Description :
 *  function to get numbers from keypad:
 */
unsigned char KeyPad_GetValue(void)
{
    while(1)
    {
        GPIO_PinValue_t pin_value=GPIO_PIN_LOW;
        u8  row=0;
        u8  col=0;
        for(col=0 ;col<4; col++)
        {
            GPIO_Config_t KeypadPort_config[8]={
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)COL_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)COL_PIN1,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)COL_PIN2,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)COL_PIN3,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)ROW_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)ROW_PIN1,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)ROW_PIN2,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)ROW_PIN3,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}
            };
            GPIO_Init(KeypadPort_config,8);
            GPIO_Config_t current_col = {(GPIO_Port_t)KEYPAD_PORT,(GPIO_Pin_t)(COL_PIN0-col),GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
            GPIO_Init(&current_col,1);
            GPIO_SetPinValue((GPIO_Port_t)KEYPAD_PORT, (GPIO_Pin_t)(COL_PIN0-col), GPIO_PIN_LOW);

            for(row=0;row<4; row++)
            {
                GPIO_GetPinValue((GPIO_Port_t)KEYPAD_PORT, (GPIO_Pin_t)(ROW_PIN0-row), &pin_value);
                if(pin_value == KEYPAD_GET_PRESSED)
                {
                    return keypad_map( row * COLS_NUM + col +1);
                }
            }

        }
    }
}

/*
 * Description :
 *  function to map pressed key to numbers:
 */
u8 keypad_map(u8 value)
{
    switch(value)
    {
    case 1:
        value=1;
        break;
    case 2:
        value=2;
        break;
    case 3:
        value=3;
        break;
    case 4:
        value='+';
        break;
    case 5:
        value=4;
        break;
    case 6:
        value=5;
        break;
    case 7:
        value=6;
        break;
    case 8:
        value='-';
        break;
    case 9:
        value=7;
        break;
    case 10:
        value=8;
        break;
    case 11:
        value=9;
        break;
    case 12:
        value='%';
        break;
    case 13:
        value='*';
        break;
    case 14:
        value=0;
        break;
    case 15:
        value='#';
        break;
    case 16:
        value='=';
        break;

    }
    return value;
}
