/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  LCD_Cfg.c
 *        Layer:  HAL
 *      Version:  1.00
 *
 *  Description:  This file contains configuration data for interfacing with an LCD module.
 *
 *   - RS_PIN and EN_PIN are configured for Register Select (RS) and Enable (EN) control, respectively.
 *   - D0_PIN through D7_PIN are configured for data lines D0 to D7.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  IMPORTANT NOTES:
 *   - Ensure that this code is used in conjunction with appropriate LCD driver functions.
 *   - Verify that the GPIO pins configured here match the actual hardware connections.
 *********************************************************************************************************************/



#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_

#define RS_PORT GPIO_PORTD
#define RS_PIN  GPIO_PIN6

#define EN_PORT GPIO_PORTD
#define EN_PIN  GPIO_PIN7


#define D0_PORT GPIO_PORTA
#define DO_PIN  GPIO_PIN4

#define D1_PORT GPIO_PORTA
#define D1_PIN  GPIO_PIN5

#define D2_PORT GPIO_PORTA
#define D2_PIN  GPIO_PIN6

#define D3_PORT GPIO_PORTA
#define D3_PIN  GPIO_PIN7

#define D4_PORT GPIO_PORTE
#define D4_PIN  GPIO_PIN0

#define D5_PORT GPIO_PORTE
#define D5_PIN  GPIO_PIN1

#define D6_PORT GPIO_PORTE
#define D6_PIN  GPIO_PIN2

#define D7_PORT GPIO_PORTE
#define D7_PIN  GPIO_PIN3



#endif /* HAL_LCD_CFG_H_ */
