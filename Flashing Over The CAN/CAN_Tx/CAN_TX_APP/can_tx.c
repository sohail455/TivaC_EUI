/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      CAN_tx.c
 * File Name:   CAN_tx
 * Layer:       MCAL
 * Description: Source file for CAN transmitter for Tiva C.
 ****************************************************************************/
#include "can_tx.h"
/*****************************************************************************
 * A counter that keeps track of the number of times the TX interrupt has
 * occurred, which should match the number of TX messages that were sent.
*****************************************************************************/
volatile uint32_t g_ui32MsgCount = 0;
/*****************************************************************************
 * A flag to indicate that some transmission error occurred.
*****************************************************************************/
volatile bool g_bErrFlag = 0;

void system_init(void)
{
    /* Set the system clock to use a 16MHz */
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    /* Enable the GPIO port that is used for the on-board LED. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    /* Check if the peripheral access is enabled. */
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    /* Set GPIO_PORTF_BASE, GPIO_PIN_1 high */
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);

    /* Enable the interrupts.*/
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);

    /* enable interrupt to portf */
    IntEnable(INT_GPIOF);

    /* Initialize CAN Communication */
    Can_Init();
}

void Can_Init()
{
    /* Enable the GPIO (General-Purpose Input/Output) peripheral for Port B. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    /* Configure pins PB4 and PB5 to be used for CAN0 receiver (RX) and transmitter (TX). */
    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    /* Set the pins PB4 and PB5 as CAN pins for Port B. */
    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    /* Enable the CAN0 peripheral. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    /* Initialize the CAN0 controller. */
    CANInit(CAN0_BASE);

    /* Set the CAN bit rate to 500,000 bits per second using the current system clock frequency. */
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);

    /* Enable CAN interrupts for the CAN0 controller, including master, error, and status interrupts. */
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    /* Register the CAN interrupt handler function (CANIntHandler) for CAN controller 0 (CAN0_BASE). */
    CANIntRegister(CAN0_BASE, CANIntHandler);

    /* Enable the CAN0 interrupt in the NVIC (Nested Vectored Interrupt Controller). */
    IntEnable(INT_CAN0);

    /* Enable the CAN0 controller. */
    CANEnable(CAN0_BASE);
}

void CANIntHandler(void)
{
    uint32_t ui32Status;  /* Declare a variable to store interrupt status. */

    /* Read the CAN interrupt status to find the cause of the interrupt. */
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    /* If the cause is a controller status interrupt, then get the status. */
    if (ui32Status == CAN_INT_INTID_STATUS) {
        /* Read the controller status. This will return a field of status
         * error bits that can indicate various errors. Error processing
         * is not done in this example for simplicity. Refer to the
         * API documentation for details about the error status bits.
         * The act of reading this status will clear the interrupt. If the
         * CAN peripheral is not connected to a CAN bus with other CAN devices
         * present, then errors will occur and will be indicated in the
         * controller status.
         */
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

        /* Set a flag to indicate some errors may have occurred. */
        g_bErrFlag = 1;
    }

    /* Check if the cause is message object 1, which is what we are using for
     * sending messages.
     */
    else if (ui32Status == 1) {
        /* Getting to this point means that the TX interrupt occurred on
         * message object 1, and the message TX is complete. Clear the
         * message object interrupt.
         */
        CANIntClear(CAN0_BASE, 1);

        /* Increment a counter to keep track of how many messages have been
         * sent. In a real application, this could be used to set flags to
         * indicate when a message is sent.
         */
        g_ui32MsgCount++;

        /* Since the message was sent, clear any error flags. */
        g_bErrFlag = 0;
    }

    /* Otherwise, something unexpected caused the interrupt. This should
     * never happen.
     */
    else {
        /* Spurious interrupt handling can go here.
         * This part is executed when an unexpected interrupt occurs,
         * which should not normally happen.
         */
    }
}

