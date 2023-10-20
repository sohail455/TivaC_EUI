/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      app.c
 * File Name:   app
 * Layer:       app
 * Description: Application to start transfer over CAN bus.
 ****************************************************************************/

#include <CAN_TX_APP/new_image1.h>
#include <CAN_TX_APP/new_image2.h>
#include "CAN_TX_APP/can_tx.h"
#include "app.h"

volatile uint8_t request_flag = 0;
volatile uint8_t pui8MsgData1[8];

void start_transmit(void)
{
    system_init();
    tCANMsgObject sCANMessage;
    /*CAN transmit configuration*/
    sCANMessage.ui32MsgID = 1;
    sCANMessage.ui32MsgIDMask = 0;
    sCANMessage.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage.ui32MsgLen = 8;
    while(1)
    {
        if(request_flag != 0)
        {
            /*Clear all leds pins*/
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
            sCANMessage.pui8MsgData = pui8MsgData1;
            CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
            uint32_t chunk=0,i=0;
            if(request_flag == 1)
            {
                /*turn on red led*/
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
                /*Loop over the first image and start to transfer 8 bytes each iteration*/
                for(chunk=0; chunk <= IMAGE1_SIZE/8; chunk++)
                {
                    for(i=0; i<500; i++);/*simple delay between each frame*/
                    sCANMessage.pui8MsgData = new_image1 + (chunk * 8);
                    CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
                }
            }
            else if(request_flag == 2)
            {
                /*turn on blue led*/
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
                /*Loop over the second image and start to transfer 8 bytes each iteration*/
                for(chunk=0; chunk <= IMAGE2_SIZE/8; chunk++)
                {
                    for(i=0; i<500; i++);/*simple delay between each frame*/
                    sCANMessage.pui8MsgData = new_image2 + (chunk * 8);
                    CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
                }
            }
            else
            {
                /*do nothing*/
            }
            request_flag=0;
            /*turn off all leds*/
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x0);
            /*turn on white led*/
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
        }
    }
}

void GPIOFIntHandler(void)
{
    /*check if interrupt is by SW1*/
    if (GPIOIntStatus(GPIO_PORTF_BASE,0) & GPIO_PIN_4)
    {
        /* Clear the interrupt for PF4*/
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);
        /* Set flag to send the firmware for first application*/
        pui8MsgData1[0] = FLASH_REQ1;
        request_flag = 1;
    }
    /* check if interrupt causes by PF0/SW2 */
    else if (GPIOIntStatus(GPIO_PORTF_BASE,0) & GPIO_PIN_0)
    {
        /* Clear the interrupt for GPIO_PIN_1 */
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_0);
        /* Set flag to send the firmware for second application*/
        pui8MsgData1[0] = FLASH_REQ2;
        request_flag = 2;
    }
    else
    {
        /*do nothing*/
    }
}
