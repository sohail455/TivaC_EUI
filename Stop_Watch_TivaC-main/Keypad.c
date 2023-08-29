/*
 * Keypad.c
 *
 *  Created on: Aug 19, 2023
 *      Author: eme
 */
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "Keypad.h"
#include"Std_Types.h"
unsigned char KeyPad_GetValue(void)
{
    while(1)
    {
        unsigned char pin_value=0;
        int col=0;
        for( ;col<4; col++)
        {
            GPIO_Config_t KeypadPort_config[8]={
                                                {KEYPAD_PORT,COL_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,COL_PIN1,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,COL_PIN2,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,COL_PIN3,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,ROW_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,ROW_PIN1,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,ROW_PIN2,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                                {KEYPAD_PORT,ROW_PIN3,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}
            };
            GPIO_Init(KeypadPort_config,8);
            GPIO_Config_t current_col = {KEYPAD_PORT,COL_PIN0+col,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
            GPIO_Init(&current_col,1);
            GPIO_SetPinValue(KEYPAD_PORT, COL_PIN0+col, GPIO_PIN_LOW);
            int row=0;
            for( ;row<4; row++)
            {
                GPIO_GetPinValue(KEYPAD_PORT, ROW_PIN0+row, &pin_value);
                if(pin_value == KEYPAD_GET_PRESSED)
                {
                    return keypad_map(row * COLS_NUM + col +1);
                }
            }


        }
    }
}

unsigned char keypad_map(unsigned char value)
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
        value=4;
        break;

    }
    return value;
}
