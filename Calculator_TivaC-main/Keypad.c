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
#include"tm4c123gh6pm.h"

unsigned char g_keypad_value=0;
unsigned char Int_Flag ;
unsigned char  col=0;
unsigned char KeyPad_GetValue(void)
{
    while(Int_Flag == 1)
    {

        unsigned long pin_value=0;
        unsigned char  row=0;
        for(col=0 ;col<4; col++)
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
            GPIO_Config_t current_col = {KEYPAD_PORT,COL_PIN0-col,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
            GPIO_Init(&current_col,1);
            GPIO_SetPinValue(KEYPAD_PORT, COL_PIN0-col, GPIO_PIN_LOW);

        }
    }
    Int_Flag=1;
}


void KeyPad_Handler(void)
{
    unsigned char row;
    unsigned long pin_value=0;
    for(row=0;row<4; row++)
    {
        GPIO_GetPinValue(KEYPAD_PORT, ROW_PIN0-row, &pin_value);
        if(pin_value == KEYPAD_GET_PRESSED)
        {
            g_keypad_value= keypad_map( row * COLS_NUM + col +1);
        }

        Int_Flag=0;


    }
    GPIO_PORTB_ICR_R |= 0xF0 ;
    int i ;
    for( i=0 ; i<(762*500); i++)
    {}
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

void PortB_interrupt_init (void)
{
    SYSCTL_RCGCGPIO_R |= (1<<1) ;
    while (SYSCTL_RCGCGPIO_R == 0) {}

    GPIO_Config_t KeypadPort_config[4]={
                                        {KEYPAD_PORT,ROW_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                        {KEYPAD_PORT,ROW_PIN1,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                        {KEYPAD_PORT,ROW_PIN2,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                        {KEYPAD_PORT,ROW_PIN3,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}
    };
    GPIO_Init(KeypadPort_config,4);
    NVIC_EN0_R |= (1<<1)     ;

    GPIO_PORTB_IS_R  &= ~0xF0 ;
    GPIO_PORTB_IBE_R &= ~0xF0 ;
    GPIO_PORTB_IEV_R &= ~0xF0 ;
    GPIO_PORTB_IM_R  |= 0xF0  ;
    GPIO_PORTB_ICR_R |= 0xF0  ;

    GPIO_PORTB_RIS_R &= ~0xF0 ;



    __asm("   cpsie i\n") ;

}


