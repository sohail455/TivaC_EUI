/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      CAN_tx.h
 * File Name:   CAN_tx
 * Layer:       MCAL
 * Description: header file for CAN transmitter for Tiva C.
 ****************************************************************************/
#ifndef CAN_TX_APP_CAN_TX_H_
#define CAN_TX_APP_CAN_TX_H_
/*include necessary files*/
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"

extern volatile uint32_t g_ui32MsgCount ;

/*CAN message object struct*/

typedef struct {
    uint32_t ui32MsgID;
    uint32_t ui32MsgIDMask;
    uint32_t ui32Flags;
    uint32_t ui32MsgLen;
    uint8_t* pui8MsgData;
} CANMsgObject;

void system_init(void);
void Can_Init();
void CANIntHandler(void);

#endif /* CAN_TX_APP_CAN_TX_H_ */
