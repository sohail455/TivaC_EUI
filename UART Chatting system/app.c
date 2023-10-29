#include "app.h"
uint8_t state_counter=0;
void start_chat()
{
    state_counter = ONLINE;
    comm_init();
    send_flag0=0;
    send_flag1=0;
    UARTCharsAvail(UART1_BASE);
    UARTCharsAvail(UART0_BASE);
    while (1)
    {
        switch(state_counter)
        {
        case ONLINE:
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,  0x00);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);
            if(UARTCharsAvail(UART1_BASE)==1)
            {
                Read_UART1_string();
            }
            if(send_flag1 == 1)
            {
                send_flag1=0;
                send_String(str1,UART0_BASE);
            }
            if(UARTCharsAvail(UART0_BASE)==1)
            {
                Read_UART0_string();
            }
            if(send_flag0 == 1)
            {
                send_flag0=0;
                send_String(str0,UART1_BASE);
            }
            if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0)
            {
                state_counter=1;
            }while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0);
            break;

        case OFFLINE:
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,  0x00);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
            if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0)
            {
                UARTEnable(UART0_BASE);
                state_counter=ONLINE;
            }while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0);
            break;

        case READ_ONLY:
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,  0x00);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
            if(UARTCharsAvail(UART1_BASE)==1)
            {
                Read_UART1_string();
            }
            if(send_flag1 == 1)
            {
                send_flag1=0;
                send_String(str1,UART0_BASE);
            }

            if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0)
            {
                UARTDisable(UART0_BASE);
                state_counter=2;
            }while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0);
            break;
        }

    }
}
