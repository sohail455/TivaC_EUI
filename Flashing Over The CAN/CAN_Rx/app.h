/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      app.h
 * File Name:   app
 * Layer:       app
 * Description: application to receive an image through CAN bus.
 ****************************************************************************/
#ifndef APP_H_
#define APP_H_
#include <stdbool.h>
#include <stdint.h>
#define IMAGE1_SIZE         2360
#define IMAGE2_SIZE         2440
#define FLASH_BLOCK1_ADDR   0x00010000
#define FLASH_BLOCK2_ADDR   0x00014000
#define NUMBER_OF_SECTORS   3
#define FLASH_REQ1          0xAA
#define FLASH_REQ2          0x55
#define FLASH_BLOCK         0x400
#define HALF_SEC            800000
#define EEPROM_ADDRESS      0x400

void start_receive(void);
void install_image(uint32_t* firmwareData, uint32_t addr, uint32_t firmwareData_Size);
void Switch_app(uint32_t addr);
void CAN_receiveFirmware1(void);
void CAN_receiveFirmware2(void);

#endif /* APP_H_ */
