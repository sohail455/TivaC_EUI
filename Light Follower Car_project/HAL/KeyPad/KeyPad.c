
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  KeyPad.c
 *        Layer:  HAL
 *      Version:  1.00
 *
 *  Description:  Keypad main file
 *
 *********************************************************************************************************************/


#include "../../LIB/Std_Types.h"
#include "../../LIB/Platform_Types.h"
#include "KeyPad_Interface.h"
#define  KEYPAD_PRG 1
#include "KeyPad_Cfg.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "../../LIB/UTILS.h"


/* Function: KEYPAD_Init
 * Description: Initializes the keypad by setting the rows to high voltage.
 * Input: None
 * Output: None
 */

void KEYPAD_Init(void)
{
    u8 r;
    for (r = 0; r < ROWS; r++)
    {
        GPIO_SetPinValue(GPIO_PORTB, (GPIO_Pin_t)(FIRST_OUTPUT + r), GPIO_PIN_HIGH);
    }
}


/* Function: KEYPAD_GetKey
 * Description: Retrieves a key press from the keypad and waits for key release.
 * Input: None
 * Output:
 *   - Returns the key pressed (char) or NO_KEY if no key is pressed.
 */

u8 KEYPAD_GetKey(void)
{

    u8 r, c, key = NO_KEY;
    GPIO_PinValue_t value = GPIO_PIN_HIGH;

    for (r = 0; r < ROWS; r++)
    {
        GPIO_SetPinValue(GPIO_PORTB, (GPIO_Pin_t)(FIRST_OUTPUT + r), GPIO_PIN_LOW);

        for (c = 0; c < COLS; c++)
        {
            GPIO_GetPinValue(GPIO_PORTB,(GPIO_Pin_t)(FIRST_INPUT + c), &value);

            if (value == GPIO_PIN_LOW)
            {
                key = KeysArr[r][c];
                while (1)
                {
                    GPIO_GetPinValue(GPIO_PORTB, (GPIO_Pin_t)(FIRST_INPUT + c),&value);
                    if(value == GPIO_PIN_HIGH){
                        break;
                    }
                }

            }
        }
        GPIO_SetPinValue(GPIO_PORTB, (GPIO_Pin_t)(FIRST_OUTPUT + r), GPIO_PIN_HIGH);
    }
    return key;
}

