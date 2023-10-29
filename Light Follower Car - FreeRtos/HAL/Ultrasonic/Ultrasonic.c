/******************************************************************************/
/*                                                                            */
/* !Layer           : Hardware Abstraction Layer (HAL)                        */
/*                                                                            */
/* !Module          : Ultra-sonic                                             */
/* !Description     : Ultra-sonic Module Implementation                       */
/*                                                                            */
/* !File            : Ultrasonic.c                                            */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car Project @EME - EUI                            */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Mazen TAMER                      !Date : SEP 09, 2023   */
/* !Coded by        : Mazen TAMER                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include <HAL/Ultrasonic/Ultrasonic.h>

/******************************************************************************/
/***************************** Global Variables *******************************/
/******************************************************************************/

uint8_t Glob_u8Flag = 0;                            /*Flag for knowing which variable to store value of timer into*/
uint8_t Glob_u8DistanceFlag = 0;

uint32_t initValue = 0;
uint32_t finalValue = 0;
uint32_t Difference;
float Period;

/******************************************************************************/
/**************************** Internal Functions ******************************/
/******************************************************************************/

void _delay_us(uint32_t n);                            /*Function to create delays in microseconds*/

void Delay_MicroSecond(int time);

void Ultrasonic_vidMeasureDistance(void);           /*The CallBack Function of The Timer Interrupt That Calculates The Distance*/

/******************************************************************************/
/************************* Function Implementations ***************************/
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize Ultra-sonic Module                              */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void Ultrasonic_vidInit(void)
{
    SYSCTL_RCGCWTIMER_R |= 0x01;        // Enable clock for Wide Timer 0
    SYSCTL_RCGCGPIO_R |= 0x04;          // Enable clock for GPIO Port A
    SYSCTL_RCGCGPIO_R |= 0x08;

    GPIO_PORTC_DIR_R &=~0x10;
    GPIO_PORTC_DIR_R |=0x20;
    GPIO_PORTC_AFSEL_R |= 0x10;         // Enable alternate function on PA6
    GPIO_PORTC_PCTL_R |= 0x00070000;    // Select WT0CCP0 function on PA6
    GPIO_PORTC_DEN_R |=0x30;


    WTIMER0_CTL_R &= ~TIMER_CTL_TAEN;   // Disable Wide Timer 0A during setup
    WTIMER0_CFG_R = 0x04;               // Configure Wide Timer 0 as 32-bit timer
    WTIMER0_TAMR_R = (TIMER_TAMR_TACMR | TIMER_TAMR_TAMR_CAP); // Configure capture mode

    // Configure the event to trigger the timer capture
    WTIMER0_CTL_R |= TIMER_CTL_TAEVENT_BOTH;  // Positive edge trigger event
    WTIMER0_CTL_R &= ~TIMER_CTL_TAPWML;      // Capture the full timer value

    WTIMER0_IMR_R |= TIMER_IMR_CAEIM;    // Enable capture event interrupt
    WTIMER0_TAV_R = 0;                   // Clear timer value register
    WTIMER0_CTL_R |= TIMER_CTL_TAEN;     // Enable Wide Timer 0A
}

/******************************************************************************/
/*! \Description : Get Ultra-sonic Distance Reading                      */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void Ultrasonic_vidGetDistance(float *Glob_u32Distance)
{


    WTIMER0_CTL_R |= TIMER_CTL_TAEN;
    GPIO_vidWritePin(GPIO_PORTC, PIN5, OUTPUT_LOW);
    Delay_MicroSecond(10);
    GPIO_vidWritePin(GPIO_PORTC, PIN5, OUTPUT_HIGH);
    Delay_MicroSecond(10);
    GPIO_vidWritePin(GPIO_PORTC, PIN5, OUTPUT_LOW);

    WTIMER0_TAV_R = 0;
    while(!GET_BIT(WTIMER0_RIS_R,2));
    SET_BIT(WTIMER0_ICR_R,2);               /*clear intereput flag of capture mode*/
    initValue = WTIMER0_TAR_R;
    while(!GET_BIT(WTIMER0_RIS_R,2));
    finalValue = WTIMER0_TAR_R;
    SET_BIT(WTIMER0_ICR_R,2);              /*clear intereput flag of capture mode*/
    Difference = initValue - finalValue;

    Period = Difference / 16000000.0;      /*divided by clcok to get time*/
    *Glob_u32Distance = (Period * 34000U) / 2.0;/*distance=time*speed but distance we get is whne go and return so divided it by 2*/
    WTIMER0_CTL_R &= ~TIMER_CTL_TAEN;

    //    initValue = 0;
    //    finalValue = 0;
}

void _delay_us(uint32_t n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        {}
}

void Delay_MicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
    TIMER1_CTL_R = 0;            /* disable Timer before initialization */
    TIMER1_CFG_R = 0x04;         /* 16-bit option */
    TIMER1_TAMR_R = 0x02;        /* periodic mode and down-counter */
    TIMER1_TAILR_R = 16 - 1;  /* TimerA interval load value reg */
    TIMER1_ICR_R = 0x1;          /* clear the TimerA timeout flag */
    TIMER1_CTL_R |= 0x01;        /* enable Timer A after initialization */

    for(i = 0; i < time; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER1_ICR_R = 0x1;      /* clear the TimerA timeout flag */
    }
}

void Timer0ACapture_init(void)
{
    SYSCTL_RCGCTIMER_R |= 1;     /* enable clock to Timer Block 0 */
    SYSCTL_RCGCGPIO_R |= 2;      /* enable clock to PORTB */

    GPIO_PORTB_DIR_R &= ~0x40;        /* make PB6 an input pin */
    GPIO_PORTB_DEN_R |= 0x40;         /* make PB6 as digital pin */
    GPIO_PORTB_AFSEL_R |= 0x40;       /* use PB6 alternate function */
    GPIO_PORTB_PCTL_R &= ~0x0F000000;  /* configure PB6 for T0CCP0 */
    GPIO_PORTB_PCTL_R |= 0x07000000;
    //
    //      /* PB2 as a digital output signal to provide trigger signal */
    //      SYSCTL_RCGCGPIO_R |= 1;      /* enable clock to PORTA */
    //      GPIO_PORTA_DIR_R |=(1<<4);         /* set PB2 as a digial output pin */
    //      GPIO_PORTA_DEN_R |=(1<<4);         /* make PB2 as digital pin */

    TIMER0_CTL_R &= ~1;          /* disable timer0A during setup */
    TIMER0_CFG_R = 4;            /* 16-bit timer mode */
    TIMER0_TAMR_R = 0x17;        /* up-count, edge-time, capture mode */
    TIMER0_CTL_R |=0x0C;        /* capture the rising edge */
    TIMER0_CTL_R |= (1<<0);           /* enable timer0A */
}
