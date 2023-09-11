/****************************************************************************
 * Author: Sohail Talaat
 * Module: GPIO_Private.h
 * File Name: GPIO_Private
 * Layer: MCAL
 * Description: Header file for Private Data for GPIO module for Tiva C.
 ****************************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_UNLOCK    0x4C4F434B
#define GPIO_COMMIT    0xFF
#define GPIO           reg_arr[GPIO_CONFIG.Port]
#define GPIO_CONFIG    Copy_Config[local_counter]



#endif /* GPIO_PRIVATE_H_ */
