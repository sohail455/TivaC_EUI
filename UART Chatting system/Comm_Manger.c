#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "Comm_Manger.h"

uint8_t str0[MAX_SIZE];
uint8_t str1[MAX_SIZE];
uint8_t counter0=0;
uint8_t counter1=0;
uint8_t flag=0;
uint8_t error_flag=0;
uint8_t send_flag1=0;
uint8_t send_flag0=0;


/**************************************************
 *                                                *
 *                                                *
 *               UART INTILIZATION                *
 *                                                *
 *                                                *
 **************************************************/
void comm_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)))
        ;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_UART1)))
        ;
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
//    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)))
//        ;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)))
        ;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while (!(SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)))
        ;
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PB0_U1RX);
    GPIOPinConfigure(GPIO_PB1_U1TX);
    GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
                          GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));
    UARTClockSourceSet(UART1_BASE, UART_CLOCK_PIOSC);
    UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 9600,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));
    UARTEnable(UART1_BASE);
    UARTEnable(UART0_BASE);
}

void send_String(uint8_t* str,uint32_t uart_type)
{
    if(error_flag == 1)
    {
        error_flag=0;
    }
    else
    {
        UARTCharPut(uart_type, '>');
        while(*str!=0x0D)
        {
            UARTCharPut(uart_type, *str);
            str++;
        }
        UARTCharPut(uart_type, 0x0D);
    }
}

void Read_UART1_string()
{

    str1[counter1]=UARTCharGetNonBlocking(UART1_BASE);
    counter1++;
    if(str1[counter1-1] == 0x7F)
    {
        counter1-=2;

    }
    if(counter1 == MAX_SIZE)
    {
        flag=1;
    }

    if(flag == 0 && str1[counter1-1]==0x0D)
    {

        send_flag1=1;
        str1[counter1-1]='\n';
        str1[counter1]=0x0D;
        counter1=0;
    }
    if(flag == 1)
    {
        flag=0;
        send_String("ERROR!!",UART0_BASE);
        error_flag=1;

    }


}

void Read_UART0_string()
{

    str0[counter0]=UARTCharGetNonBlocking(UART0_BASE);
    UARTCharPut(UART0_BASE, str0[counter0]);
    counter0++;
    if(str0[counter0-1] == 0x7F)
    {
        counter0-=2;
    }

    if(counter0 == MAX_SIZE)
    {
        flag=1;
    }

    if(flag == 0 && str0[counter0-1]==0x0D)
    {
        UARTCharPut(UART0_BASE,'\n');
        str0[counter0-1]=0x0D;
        send_flag0=1;
        counter0=0;
    }
    if(flag == 1)
    {
        flag=0;
        send_String("ERROR!!",UART0_BASE);
        error_flag=1;

    }


}

//void Read_string()
//{
//    while(str[counter-1]!=0x0D)
//    {
//        str[counter]=UARTCharGet(UART1_BASE);
//        UARTCharPut(UART1_BASE, str[counter]);
//        counter++;
//        if(counter == 200)
//        {
//            flag=1;
//            break;
//        }
//    }
//    if(flag == 0)
//    {
//        str[counter-1]='\0';
//    }
//    if(flag == 1)
//    {
//        flag=0;
//        send_String("ERROR!!");
//        send_flag1=1;
//
//    }
//    counter=0;
//
//}
