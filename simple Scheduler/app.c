/*
 * app.c
 *
 *  Created on: 10 Sep 2023
 *      Author: pvc
 */
#include "Platform_Types.h"
#include "GPIO_Interfaces.h"
#include"lcd.h"

u8 button_read=0;
typedef enum
{
    BUTTON_ON,
    BUTTON_OFF
}state;
state Button_State=BUTTON_OFF;
void System_init(void)
{
    LCD_init();
    LCD_displayString("Button is ");
    GPIO_Config_t config1={GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0};
    GPIO_Init(&config1, 1);


}

void Read_Button_t(void)
{
    GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN4, &button_read);
   if(button_read == 0)
   {
       Button_State=BUTTON_ON;
   }
   else
   {
       Button_State=BUTTON_OFF;
   }
}

void LCD_Refresh_t(void)
{
    LCD_moveCursor(0, 10);
    if(Button_State == BUTTON_ON)
    {
        LCD_displayString("ON ");
    }
    else
    {
        LCD_displayString("OFF");
    }

}

