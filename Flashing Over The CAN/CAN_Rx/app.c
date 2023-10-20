/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      app.c
 * File Name:   app
 * Layer:       app
 * Description: application to receive an image through CAN bus.
 ****************************************************************************/
/*Include standard C libraries*/
#include <stdbool.h>
#include <stdint.h>

/* Include TivaWare library header files */
#include "CAN_Rx_APP/can_rx.h"
#include "driverlib/flash.h"
#include "driverlib/eeprom.h"
#include "app.h"

uint32_t ptr=0;
typedef void (*p_fun)(void);
p_fun jump;

tCANMsgObject sCANMessage;
uint8_t pui8MsgData[8];
uint8_t APP1_image[IMAGE1_SIZE];
uint8_t APP2_image[IMAGE2_SIZE];

void delay(uint64_t d)
{
    uint64_t i=0;
    for(i=0; i<762; i++);
}

void start_receive(void)
{
    /*initiate the system*/
    system_init();
    sw_init();
    /*configuration for CAN receive*/
    sCANMessage.ui32MsgID = 0;
    sCANMessage.ui32MsgIDMask = 0;
    sCANMessage.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sCANMessage.ui32MsgLen = 8;

    /* Set the message object for receiving */
    CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_RX);
    sCANMessage.pui8MsgData = pui8MsgData;
    while(1)
    {
        /*LED on purple led*/
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_1|GPIO_PIN_2);
        if(g_bRXFlag)
        {
            CANMessageGet(CAN0_BASE, 1, &sCANMessage, 0);
            g_bRXFlag =0;

            /*If the first byte is FLASH_REQ1 then we receive a first firmware*/
            if(*sCANMessage.pui8MsgData == FLASH_REQ1)
            {
                CAN_receiveFirmware1();
            }
            /*If the first byte is FLASH_REQ1 then we receive a first firmware*/
            else if(*sCANMessage.pui8MsgData == FLASH_REQ2)
            {
                CAN_receiveFirmware2();
            }
        }
        if(! GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0))
        {
            /*Check if there is image in this location by checking stack pointer value*/
            if(*(uint32_t *)(FLASH_BLOCK1_ADDR) == 0x20000200)
            {
                /* Clear GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 */
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
                /* Call a simple delay function */
                delay(1000);
                /* Jump to the bootloader using the provided new_APP_Addr */
                Switch_app(FLASH_BLOCK1_ADDR);
            }

        }
        if(! GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4))
        {
            /*Check if there is image in this location by checking stack pointer value*/
            if(*(uint32_t *)(FLASH_BLOCK2_ADDR) == 0x20000200)
            {
                /* Clear GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 */
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
                /* Call a simple delay function */
                delay(1000);
                /* Jump to the bootloader using the provided new_APP_Addr */
                Switch_app(FLASH_BLOCK2_ADDR);
            }
        }
    }
}



void install_image(uint32_t* firmwareData, uint32_t addr, uint32_t firmwareData_Size)
{
    uint8_t sector_counter=0;
    for(sector_counter=0; sector_counter < NUMBER_OF_SECTORS; sector_counter++)
    {
        FlashErase(addr+sector_counter*(FLASH_BLOCK));
    }
    // Flash the data
    FlashProgram((uint32_t *)firmwareData, addr, firmwareData_Size);
    /*turn off all leds*/
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
    /*jump on new image*/
    Switch_app(addr);
}

void Switch_app(uint32_t addr)
{
    /*disable systick interrupt and systick itself*/
    SysTickIntDisable();
    SysTickDisable();
    /* Disable all processor interrupts */
    HWREG(NVIC_DIS0) = 0xffffffff;
    HWREG(NVIC_DIS1) = 0xffffffff;
    /* Disable global interrupt */
    IntMasterDisable();
    /* Set the vector table address to the provided address */
    HWREG(NVIC_VTABLE) = addr;
    /* enable global interrupt */
    IntMasterEnable();
    ptr = *( uint32_t *)(addr + 4);
    jump = (p_fun)ptr;
    /*reset stack pointer*/
    __set_MSP(*(( uint32_t *)addr));
    /*jump on the new image*/
    jump();
}

void CAN_receiveFirmware1(void)
{
    g_ui32MsgCount = 0;
    /* Clear GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 */
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
    /* Set GPIO_PORTF_BASE, GPIO_PIN_1 high */
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
    for (;;)
    {
        if (g_bRXFlag)
        {
            /* Calculate the message data pointer for the current message */
            sCANMessage.pui8MsgData = APP1_image + ((g_ui32MsgCount - 1) * 8);

            /* Get a CAN message from CAN0_BASE with object 1 */
            CANMessageGet(CAN0_BASE, 1, &sCANMessage, 0);
            g_bRXFlag = 0;
        }
        if (g_ui32MsgCount - 1 == IMAGE1_SIZE / 8)
        {
            break;
        }
    }
    uint32_t *pFirmware = (uint32_t *)APP1_image;
    install_image(pFirmware,FLASH_BLOCK1_ADDR,IMAGE1_SIZE);
}

void CAN_receiveFirmware2(void)
{
    g_ui32MsgCount = 0;
    /* Clear GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 */
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
    /* Set GPIO_PORTF_BASE, GPIO_PIN_1 high */
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    for (;;)
    {
        if (g_bRXFlag)
        {
            /* Calculate the message data pointer for the current message */
            sCANMessage.pui8MsgData = APP2_image + ((g_ui32MsgCount - 1) * 8);

            /* Get a CAN message from CAN0_BASE with object 1 */
            CANMessageGet(CAN0_BASE, 1, &sCANMessage, 0);
            g_bRXFlag = 0;
        }
        if (g_ui32MsgCount - 1 == IMAGE2_SIZE / 8)
        {
            break;
        }
    }
    uint32_t *pFirmware = (uint32_t *)APP2_image;
    install_image(pFirmware,FLASH_BLOCK2_ADDR,IMAGE2_SIZE);
}

