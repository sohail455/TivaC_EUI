
#include <stdbool.h>
#include <stdint.h>
#include "LIB/Std_Types.h"
#include "LIB/Platform_Types.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "inc/hw_gpio.h"
#include "driverlib/adc.h"
#include "APP/ToggleLedSys/ToggleLedSys.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "LIB/UTILS.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"

#include "HAL/car.h"

#define CONFIG_NUM 18

volatile u32 t1;
volatile u32 t2;

volatile u8 flag = 0;

void TIMER0_Handler(void);

void UltraSonic_init(void)
{
    GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PC4_WT0CCP0); // enable alternative function

    SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);

    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_WTIMER0))
    {
    }

    TimerConfigure(WTIMER0_BASE,
    TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP);

    TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_POS_EDGE);

    TimerIntRegister(WTIMER0_BASE, TIMER_A, TIMER0_Handler);

    TimerIntEnable(WTIMER0_BASE, TIMER_CAPA_EVENT);

    TimerEnable(WTIMER0_BASE, TIMER_A);
}

void UltraSonic_trigger(void)
{

    //    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, HIGH);
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_HIGH);
        SysCtlDelay(10 * 16);
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_LOW);
    //    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, LOW);
}

int main(void)
{

    const GPIO_Config_t Config[CONFIG_NUM] = {

            { GPIO_PORTA, GPIO_PIN4, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTA, GPIO_PIN5, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTA, GPIO_PIN6, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTA, GPIO_PIN7, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },

            { GPIO_PORTE, GPIO_PIN0, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTE, GPIO_PIN1, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTE, GPIO_PIN2, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTE, GPIO_PIN3, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },

            { GPIO_PORTD, GPIO_PIN6, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
            { GPIO_PORTD, GPIO_PIN7, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },

            { GPIO_PORTD, GPIO_PIN3, GPIO_PIN_INPUT, GPIO_PIN_ANALOG,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },

            // only to enable the port
            { GPIO_PORTC, GPIO_PIN5, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC7 },

            { GPIO_PORTB, GPIO_PIN3, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },


    };

    //    SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
    //    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_WTIMER0))
    //    {
    //    }
    //
    //
    //    TimerDisable(WTIMER0_BASE, TIMER_A);
    //
    //    TimerConfigure(WTIMER0_BASE,(TIMER_CFG_A_CAP_COUNT | TIMER_CFG_SPLIT_PAIR));
    //     TimerLoadSet(WTIMER0_BASE, TIMER_A, 40000);
    //
    //    TimerIntEnable(WTIMER0_BASE, TIMER_CAPA_EVENT);
    //
    //    TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_BOTH_EDGES);
    //    TimerEnable(WTIMER0_BASE, TIMER_BOTH);
    //
    //
    //    //        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    //    //       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))
    //    //       {
    //    //       }
    ////        TimerConfigure(TIMER0_BASE, TIMER_CFG_A_CAP_COUNT_UP|TIMER_CFG_SPLIT_PAIR);
    ////        TimerLoadSet(TIMER0_BASE, TIMER_A, 40000);
    ////        TimerIntEnable(TIMER0_BASE, TIMER_CAPA_EVENT);
    ////
    ////        TimerControlEvent(TIMER0_BASE, TIMER_A, TIMER_EVENT_POS_EDGE);
    ////        TimerEnable(TIMER0_BASE, TIMER_A);
    //
    ////    uint32_t ui32Value;



    GPIO_Init(Config, CONFIG_NUM);

    //    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE,GPIO_PIN_4 );
//    GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_4);
//    GPIOPinConfigure(GPIO_PC4_WT0CCP0); // enable alternative function

    //
    // Enable the Timer0 peripheral
    //
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
    //
    // Wait for the Timer0 module to be ready.
    //
//    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_WTIMER0))
//    {
//    }
    //
    // Configure TimerA as a half-width one-shot timer, and TimerB as a
    // half-width edge capture counter.
    //
//    TimerConfigure(WTIMER0_BASE,
//                   TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP);
    //
    // Set the count time for the the one-shot timer (TimerA).
    //
    //    TimerLoadSet(WTIMER0_BASE, TIMER_A, 3000);
    //
    // Configure the counter (TimerB) to count both edges.
    //
//    TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_NEG_EDGE);
//
//    TimerIntRegister(WTIMER0_BASE, TIMER_A, TIMER0_Handler);
//
//    TimerIntEnable(WTIMER0_BASE, TIMER_CAPA_EVENT);
//    //
    // Enable the timers.
//    TimerEnable(WTIMER0_BASE, TIMER_A);

    UltraSonic_init();
    LCD_Init();
    //
    // Trigger the sample sequence.
    //
    //    unsigned long first = 0;
    //    unsigned long second = 0;

    while (1)
    {

        UltraSonic_trigger();
        while (flag < 2) ;
        u32 time = t2 - t1;
        LCD_GoTo(0, 0);
        LCD_Clear();
        u32 d = time / 928;
        LCD_WriteNumber(d);
//        if(d < 6){
//            direction(stop);
//        }else if(d > 13){
//            direction(forward);
//        }
        flag = 0;
        TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_POS_EDGE);
        SysCtlDelay(70*16000);

        //
        //        while (!(TimerIntStatus(TIMER0_BASE, 0) & 0xFFFF))
        //            ;

    }
}

void TIMER0_Handler(void)
{
    if (flag == 0)
    {
        t1 = TimerValueGet(WTIMER0_BASE, TIMER_A);
        flag = 1;
        TimerControlEvent(WTIMER0_BASE, TIMER_A, TIMER_EVENT_NEG_EDGE);
    }
    else if (flag == 1)
    {
        t2 = TimerValueGet(WTIMER0_BASE, TIMER_A);
        flag = 2;

    }
    TimerIntClear(WTIMER0_BASE, TIMER_CAPA_EVENT);
}
//
//void adc_value()
//{
//
//    //
//    // Enable the ADC0 module.
//    //
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
//    //
//    // Wait for the ADC0 module to be ready.
//    //
//    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
//    {
//    }
//
//    //
//    // Enable the first sample sequencer to capture the value of channel 0 when
//    // the processor trigger occurs.
//    //
//    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
//    ADCSequenceStepConfigure(ADC0_BASE, 0, 0,
//    ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH4);
//
//    ADCSequenceEnable(ADC0_BASE, 0);
//
//    //        ADCProcessorTrigger(ADC0_BASE, 0);
//    //        //
//    //        // Wait until the sample sequence has completed.
//    //        //
//    //        while(!ADCIntStatus(ADC0_BASE, 0, false))
//    //        {
//    //        }
//    //        //
//    //        // Read the value from the ADC.
//    //        //
//    //
//    //        ADCSequenceDataGet(ADC0_BASE, 0, &ui32Value);
//    //        LCD_GoTo(0, 0);
//    //        LCD_Clear();
//    //
//    //        LCD_WriteNumber(ui32Value);
//    //
//    //        delay(1000);
//}

//    ToggleLedSysInit();

//   *( (uint32_t*)(GPIO_PORT_BASE+GPIO_O_LOCK)) = GPIO_LOCK_KEY;
//   *( (uint32_t*)(GPIO_PORTF_BASE+GPIO_O_CR)) = 0xFFFFFF;
//   GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

//    while(1){
//        if(!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0))
//        {
//            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0E);
//        }
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
//    };

