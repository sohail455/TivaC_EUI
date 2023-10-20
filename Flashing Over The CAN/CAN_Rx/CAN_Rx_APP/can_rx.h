/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      CAN_rx.h
 * File Name:   CAN_rx
 * Layer:       CAN_rx
 * Description: application to receive an image through CAN bus.
 ****************************************************************************/

#ifndef CAN_RX_APP_CAN_RX_H_
#define CAN_RX_APP_CAN_RX_H_

/*Include standard C libraries*/
#include <stdbool.h>
#include <stdint.h>
/* Include TivaWare library header files */
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/can.h"
#include "inc/hw_can.h"
#include "inc/hw_nvic.h"
#include "inc/hw_sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/flash.h"

extern volatile uint32_t g_ui32MsgCount ;
extern volatile bool g_bRXFlag;
extern uint32_t pui32Data;
extern uint32_t pui32Read;

typedef struct {
    uint32_t ui32MsgID;
    uint32_t ui32MsgIDMask;
    uint32_t ui32Flags;
    uint32_t ui32MsgLen;
    uint8_t* pui8MsgData;
} CANMsgObject;

void system_init(void);
void Can_Init(void);
void CANIntHandler(void);
void sw_init(void);

#endif /* CAN_RX_APP_CAN_RX_H_ */
