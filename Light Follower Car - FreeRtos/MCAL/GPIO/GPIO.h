/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : GPIO                                                    */
/* !Description     : to Drive GPIO Pins                                      */
/*                                                                            */
/* !File            : GPIO.c                                                  */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous car Project @EME - EUI                       */
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
/* !Designed by     : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/* !Coded by        : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/******************************* Includes *************************************/
#include <GeneralFunctions/std_types.h>
#include "GeneralFunctions/Bit_Math.h"
#include "GeneralFunctions/hw_gpio.h"
/******************************************************************************/

/******************************************************************************/
/******************************* Defines **************************************/
/******************************************************************************/
#define OUTPUT_HIGH 1
#define OUTPUT_LOW  0

#define PULLUP      1
#define NO_PULLUP   0

/******************************* PORT NUMBER **********************************/
#define GPIO_PORTA                    0
#define GPIO_PORTB                    1
#define GPIO_PORTC                    2
#define GPIO_PORTD                    3
#define GPIO_PORTE                    4
#define GPIO_PORTF                    5
/******************************************************************************/

/******************************** PIN NUMBER **********************************/
#define PIN0                     0
#define PIN1                     1
#define PIN2                     2
#define PIN3                     3
#define PIN4                     4
#define PIN5                     5
#define PIN6                     6
#define PIN7                     7
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/*! \Description : Initialize GPIO PORT                                       */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select Port Id                              */
/******************************************************************************/
void GPIO_vidInitPort(uint8_t Copy_u8PortId);

/******************************************************************************/
/*! \Description : Set Specific Pin as an output                              */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidOutputPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum);

/******************************************************************************/
/*! \Description : Set Pin Value                                              */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/*!              Copy_u8PinVal value to be set                                */
/******************************************************************************/
void GPIO_vidWritePin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum,uint8_t Copy_u8PinVal);

/******************************************************************************/
/*! \Description : Read Specific Pin Value                                    */
/*! \return      Pin value                                                    */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
uint8_t GPIO_u8ReadPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum);

/******************************************************************************/
/*! \Description : Set a specific Pin as an input                             */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidInputPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum);

/******************************************************************************/
/*! \Description : Set pull up to a specified Pin                             */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidInputPinPullUp(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum);

/******************************************************************************/
/*! \Description : Toggle a specific Pin Value                                */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidTogglePin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum);

/******************************************************************************/
/*! \Description : Set alternative function to a specific pin                 */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/*!              Copy_u8AltFun alternative function to be set                 */
/******************************************************************************/
void GPIO_vidSetAltFunc(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum, uint8_t Copy_u8AltFun);
/******************************************************************************/
/*! \Description : Read Port Value                 */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/*!              Copy_u8AltFun alternative function to be set                 */
/******************************************************************************/
uint32_t GPIO_u8ReadPort(uint8_t Copy_u8PortId);

#endif /* GPIO_H_ */
