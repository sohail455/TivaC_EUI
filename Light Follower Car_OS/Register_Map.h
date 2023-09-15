#ifndef UTILS_REGISTER_MAP_H_
#define UTILS_REGISTER_MAP_H_


/******************************************** System Control Base Definition *****************************************/

#define SYSCTL_BASE_ADDRESS             0x400FE000UL

/******************************************** System Control Registers Definition ************************************/

typedef struct
{
    volatile u32 DID0; /* Device Identification 0 */
    volatile u32 DID1; /* Device Identification 1 */
    volatile u32 Reserved[10]; /* Reserved 1 */
    volatile u32 PBORCTL; /* Brown-Out Reset Control */
    volatile u32 Reserved2[7]; /* Reserved 2 */
    volatile u32 RIS; /* Raw Interrupt Status */
    volatile u32 IMC; /* Interrupt Mask Control  */
    volatile u32 MISC; /* Masked Interrupt Status and Clear */
    volatile u32 RESC; /* Reset Cause */
    volatile u32 RCC; /* Run-Mode Clock Configuration */
    volatile u32 Reserved3[2]; /* Reserved 3 */
    volatile u32 GPIOHCTL; /* GPIO High-Performance Bus Control */
    volatile u32 RCC2; /* Run-Mode Clock Configuration  */
    volatile u32 Reserved4[2]; /* Reserved 4 */
    volatile u32 MOSCCTL; /* Main Oscillator Control */
    volatile u32 Reserved5[49]; /* Reserved 5 */
    volatile u32 DSLPCLKCFG; /* Deep Sleep Clock Configuration */
    volatile u32 Reserved6; /* Reserved 6 */
    volatile u32 SYSPROP; /* System Properties */
    volatile u32 PIOSCCAL; /* Precision Internal Oscillator Calibration */
    volatile u32 PIOSCSTAT; /* Precision Internal Oscillator Statistics */
    volatile u32 Reserved7[2]; /* Reserved 7 */
    volatile u32 PLLFREQ0; /* PLL Frequency 0 */
    volatile u32 PLLFREQ1; /* PLL Frequency 1 */
    volatile u32 PLLSTAT; /* PLL Status */
    volatile u32 Reserved8[7]; /* Reserved 8 */
    volatile u32 SLPPWRCFG; /* Sleep Power Configuration */
    volatile u32 DSLPPWRCFG; /* Deep-Sleep Power Configuration */
    volatile u32 Reserved9[9]; /* Reserved 9 */
    volatile u32 LDOSPCTL; /* LDO Sleep Power Control */
    volatile u32 LDOSPCAL; /* LDO Sleep Power Calibration */
    volatile u32 LDODPCTL; /* LDO Deep-Sleep Power Control */
    volatile u32 LDODPCAL; /* LDO Deep-Sleep Power Calibration */
    volatile u32 Reserved10[2]; /* Reserved 10 */
    volatile u32 SDPMST; /* Sleep / Deep-Sleep Power Mode Status */
    volatile u32 Reserved11[76]; /* Reserved 11 */
    volatile u32 PPWD; /* Watchdog Timer Peripheral Present */
    volatile u32 PPTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Present */
    volatile u32 PPGPIO; /* General-Purpose Input/Output Peripheral Present */
    volatile u32 PPDMA; /* Micro Direct Memory Access Peripheral Present */
    volatile u32 Reserved12; /* Reserved 12 */
    volatile u32 PPHIB; /* Hibernation Peripheral Present */
    volatile u32 PPUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Present */
    volatile u32 PPSSI; /* Synchronous Serial Interface Peripheral Present */
    volatile u32 PPI2C; /* Inter-Integrated Circuit Peripheral Present */
    volatile u32 Reserved13; /* Reserved 13 */
    volatile u32 PPUSB; /* Universal Serial Bus Peripheral Present */
    volatile u32 Reserved14[2]; /* Reserved 14 */
    volatile u32 PPCAN; /* Controller Area Network Peripheral Present */
    volatile u32 PPADC; /* Analog-to-Digital Converter Peripheral Present */
    volatile u32 PPACMP; /* Analog Comparator Peripheral Present */
    volatile u32 PPPWM; /* Pulse Width Modulator Peripheral Present */
    volatile u32 PPQEI; /* Quadrature Encoder Interface Peripheral Present */
    volatile u32 Reserved15[4]; /* Reserved 15 */
    volatile u32 PPEEPROM; /* EEPROM Peripheral Present */
    volatile u32 PPWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Present */
    volatile u32 Reserved16[104]; /* Reserved 16 */
    volatile u32 SRWD; /* Watchdog Timer Software Reset */
    volatile u32 SRTIMER; /* 16/32-Bit General-Purpose Timer Software Reset */
    volatile u32 SRGPIO; /* General-Purpose Input/Output Software Reset */
    volatile u32 SRDMA; /* Micro Direct Memory Access Software Reset */
    volatile u32 Reserved17; /* Reserved 17 */
    volatile u32 SRHIB; /* Hibernation Software Reset */
    volatile u32 SRUART; /* Universal Asynchronous Receiver/Transmitter Software Reset */
    volatile u32 SRSSI; /* Synchronous Serial Interface Software Reset */
    volatile u32 SRI2C; /* Inter-Integrated Circuit Software Reset */
    volatile u32 Reserved18; /* Reserved 18 */
    volatile u32 SRUSB; /* Universal Serial Bus Software Reset */
    volatile u32 Reserved19[2]; /* Reserved 19 */
    volatile u32 SRCAN; /* Controller Area Network Software Reset */
    volatile u32 SRADC; /* Analog-to-Digital Converter Software Reset */
    volatile u32 SRACMP; /* Analog Comparator Software Reset */
    volatile u32 SRPWM; /* Pulse Width Modulator Software Reset */
    volatile u32 SRQEI; /* Quadrature Encoder Interface Software Reset */
    volatile u32 Reserved20[4]; /* Reserved 20 */
    volatile u32 SREEPROM; /* EEPROM Software Reset */
    volatile u32 SRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Software Reset */
    volatile u32 Reserved21[40]; /* Reserved 21 */
    volatile u32 RCGCWD; /* Watchdog Timer Run Mode Clock Gating Control */
    volatile u32 RCGCTIMER; /* 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control */
    volatile u32 RCGCGPIO; /* General-Purpose Input/Output Run Mode Clock Gating Control */
    volatile u32 RCGCDMA; /* Micro Direct Memory Access Run Mode Clock Gating Control */
    volatile u32 Reserved22; /* Reserved 22 */
    volatile u32 RCGCHIB; /* Hibernation Run Mode Clock Gating Control */
    volatile u32 RCGCUART; /* Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control */
    volatile u32 RCGCSSI; /* Synchronous Serial Interface Run Mode Clock Gating Control */
    volatile u32 RCGCI2C; /* Inter-Integrated Circuit Run Mode Clock Gating Control */
    volatile u32 Reserved23; /* Reserved 23 */
    volatile u32 RCGCUSB; /* Universal Serial Bus Run Mode Clock Gating Control */
    volatile u32 Reserved24[2]; /* Reserved 24 */
    volatile u32 RCGCCAN; /* Controller Area Network Run Mode Clock Gating Control */
    volatile u32 RCGCADC; /* Analog-to-Digital Converter Run Mode Clock Gating Control */
    volatile u32 RCGCACMP; /* Analog Comparator Run Mode Clock Gating Control */
    volatile u32 RCGCPWM; /* Pulse Width Modulator Run Mode Clock Gating Control */
    volatile u32 RCGCQEI; /* Quadrature Encoder Interface Run Mode Clock Gating Control */
    volatile u32 Reserved25[4]; /* Reserved 25 */
    volatile u32 RCGCEEPROM; /* EEPROM Run Mode Clock Gating Control */
    volatile u32 RCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control */
    volatile u32 Reserved26[40]; /* Reserved 26 */
    volatile u32 SCGCWD; /* Watchdog Timer Sleep Mode Clock Gating Control */
    volatile u32 SCGCTIMER; /* 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile u32 SCGCGPIO; /* General-Purpose Input/Output Sleep Mode Clock Gating Control */
    volatile u32 SCGCDMA; /* Micro Direct Memory Access Sleep Mode Clock Gating Control */
    volatile u32 Reserved27; /* Reserved 27 */
    volatile u32 SCGCHIB; /* Hibernation Sleep Mode Clock Gating Control */
    volatile u32 SCGCUART; /* Universal Asynchronous Receiver/Transmitter Sleep Mode Clock Gating Control */
    volatile u32 SCGCSSI; /* Synchronous Serial Interface Sleep Mode Clock Gating Control */
    volatile u32 SCGCI2C; /* Inter-Integrated Circuit Sleep Mode Clock Gating Control */
    volatile u32 Reserved28; /* Reserved 28 */
    volatile u32 SCGCUSB; /* Universal Serial Bus Sleep Mode Clock Gating Control */
    volatile u32 Reserved29[2]; /* Reserved 29 */
    volatile u32 SCGCCAN; /* Controller Area Network Sleep Mode Clock Gating Control */
    volatile u32 SCGCADC; /* Analog-to-Digital Converter Sleep Mode Clock Gating Control */
    volatile u32 SCGCACMP; /* Analog Comparator Sleep Mode Clock Gating Control */
    volatile u32 SCGCPWM; /* Pulse Width Modulator Sleep Mode Clock Gating Control */
    volatile u32 SCGCQEI; /* Quadrature Encoder Interface Sleep Mode Clock Gating Control */
    volatile u32 Reserved30[4]; /* Reserved 30 */
    volatile u32 SCGCEEPROM; /* EEPROM Sleep Mode Clock Gating Control */
    volatile u32 SCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile u32 Reserved31[40]; /* Reserved 31 */
    volatile u32 DCGCWD; /* Watchdog Timer Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCTIMER; /* 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCGPIO; /* General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCDMA; /* Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved32; /* Reserved 32 */
    volatile u32 DCGCHIB; /* Hibernation Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCUART; /* Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCSSI; /* Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCI2C; /* Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved33; /* Reserved 33 */
    volatile u32 DCGCUSB; /* Universal Serial Bus Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved34[2]; /* Reserved 34 */
    volatile u32 DCGCCAN; /* Controller Area Network Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCADC; /* Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCACMP; /* Analog Comparator Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCPWM; /* Pulse Width Modulator Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCQEI; /* Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved35[4]; /* Reserved 35 */
    volatile u32 DCGCEEPROM; /* EEPROM Deep-Sleep Mode Clock Gating Control */
    volatile u32 DCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile u32 Reserved36[104]; /* Reserved 36 */
    volatile u32 PRWD; /* Watchdog Timer Peripheral Ready */
    volatile u32 PRTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Ready */
    volatile u32 PRGPIO; /* General-Purpose Input/Output Peripheral Ready */
    volatile u32 PRDMA; /* Micro Direct Memory Access Peripheral Ready */
    volatile u32 Reserved37; /* Reserved 37 */
    volatile u32 PRHIB; /* Hibernation Peripheral Ready */
    volatile u32 PRUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Ready */
    volatile u32 PRSSI; /* Synchronous Serial Interface Peripheral Ready */
    volatile u32 PRI2C; /* Inter-Integrated Circuit Peripheral Ready */
    volatile u32 Reserved38; /* Reserved 38 */
    volatile u32 PRUSB; /* Universal Serial Bus Peripheral Ready */
    volatile u32 Reserved39[2]; /* Reserved 39 */
    volatile u32 PRCAN; /* Controller Area Network Peripheral Ready */
    volatile u32 PRADC; /* Analog-to-Digital Converter Peripheral Ready */
    volatile u32 PRACMP; /* Analog Comparator Peripheral Ready */
    volatile u32 PRPWM; /* Pulse Width Modulator Peripheral Ready */
    volatile u32 PRQEI; /* Quadrature Encoder Interface Peripheral Ready */
    volatile u32 Reserved40[4]; /* Reserved 40 */
    volatile u32 PREEPROM; /* EEPROM Peripheral Ready */
    volatile u32 PRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Ready */
} SysCTRL_RegDef_t;

#define SYSCTL                          ((SysCTRL_RegDef_t*) SYSCTL_BASE_ADDRESS)


/************************ SYSCTRL RCC MASKS ************************/
#define SYSCTL_RCC2_USERCC2_MASK     0x80000000  /* USERCC2 Bit MASK */
#define SYSCTL_RCC2_BYPASS2_MASK     0x00000800  /* PLL BYPASS2 Bit MASK */
#define SYSCTL_RCC_XTAL_MASK         0x000007C0  /* XTAL Bits MASK */
#define SYSCTL_RCC_XTAL_8MHZ         0x00000380  /* 8 MHz Crystal Value */
#define SYSCTL_RCC_XTAL_16MHZ        0x00000540  /* 16 MHz Crystal Value */
#define SYSCTL_RCC2_OSCSRC2_MASK     0x00000070  /* OSCSRC2 Bits MASK */
#define SYSCTL_RCC2_OSCSRC2_MOSC     0x00000000  /* MOSC(Main Oscillator) value */
#define SYSCTL_RCC2_PWRDN2_MASK      0x00002000  /* PWRDN2 Bit MASK */
#define SYSCTL_RCC2_DIV400_MASK      0x40000000  /* DIV400 Bit MASK to Divide PLL as 400 MHz vs. 200 */
#define SYSCTL_RCC2_SYSDIV2_MASK     0x1FC00000  /* SYSDIV2 Bits MASK */
#define SYSCTL_RIS_PLLLRIS_MASK      0x00000040  /* PLLLRIS Bit MASK */
#define SYSCTL_RCC2_SYSDIV2_BIT_POS     22       /* SYSDIV2 Bits Postion start from bit number 22 */
#define SYSDIV2_VALUE 24


/******************************************** GPIO Base Definition ***************************************************/

#define GPIOA_BASE_ADDRESS              0x40004000UL
#define GPIOB_BASE_ADDRESS              0x40005000UL
#define GPIOC_BASE_ADDRESS              0x40006000UL
#define GPIOD_BASE_ADDRESS              0x40007000UL
#define GPIOE_BASE_ADDRESS              0x40024000UL
#define GPIOF_BASE_ADDRESS              0x40025000UL

/******************************************** GPIO Registers Definition **********************************************/

typedef struct
{
    volatile u32 DATA[256]; /* GPIO Data */
    volatile u32 DIR; /* GPIO Direction */
    volatile u32 IS; /* GPIO Interrupt Sense */
    volatile u32 IBE; /* GPIO Interrupt Both Edges */
    volatile u32 IEV; /* GPIO Interrupt Even */
    volatile u32 IM; /* GPIO Interrupt Mask */
    volatile u32 RIS; /* GPIO Raw Interrupt Status */
    volatile u32 MIS; /* GPIO Masked Interrupt Status */
    volatile u32 ICR; /* GPIO Interrupt Clear */
    volatile u32 AFSEL; /* GPIO Alternate Function Select */
    volatile u32 Reserved[55]; /* Reserved 1 */
    volatile u32 DR2R; /* GPIO 2-mA Drive Select */
    volatile u32 DR4R; /* GPIO 2-mA Drive Select */
    volatile u32 DR8R; /* GPIO 8-mA Drive Select */
    volatile u32 ODR; /* GPIO Open Drain Select */
    volatile u32 PUR; /* GPIO Pull-Up Select */
    volatile u32 PDR; /* GPIO Pull-Down Select */
    volatile u32 SLR; /* GPIO Slew Rate Control Select */
    volatile u32 DEN; /* GPIO Digital Enable */
    volatile u32 LOCK; /* GPIO Lock */
    volatile u32 CR; /* GPIO Commit */
    volatile u32 AMSEL; /* GPIO Analog Mode Select */
    volatile u32 PCTL; /* GPIO Port Control */
    volatile u32 ADCCTL; /* GPIO ADC Control */
    volatile u32 DMACTL; /* GPIO DMA Control */
    volatile u32 PeriphlD4; /* GPIO Peripheral Identification 4 */
    volatile u32 PeriphlD5; /* GPIO Peripheral Identification 5 */
    volatile u32 PeriphlD6; /* GPIO Peripheral Identification 6 */
    volatile u32 PeriphlD7; /* GPIO Peripheral Identification 6 */
    volatile u32 PeriphlD0; /* GPIO Peripheral Identification 0 */
    volatile u32 PeriphlD1; /* GPIO Peripheral Identification 1 */
    volatile u32 PeriphlD2; /* GPIO Peripheral Identification 2 */
    volatile u32 PeriphlD3; /* GPIO Peripheral Identification 3 */
    volatile u32 PCelllD0; /* GPIO PrimeCell Identification 0 */
    volatile u32 PCelllD1; /* GPIO PrimeCell Identification 1 */
    volatile u32 PCelllD2; /* GPIO PrimeCell Identification 2 */
    volatile u32 PCelllD3; /* GPIO PrimeCell Identification 3 */
} GPIO_RegDef_t;

#define GPIOA                           ((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)

/******************************************** Timer Base Definition **************************************************/

#define TIMER0_BASE_ADDRESS             0x40030000UL
#define TIMER1_BASE_ADDRESS             0x40031000UL
#define TIMER2_BASE_ADDRESS             0x40032000UL
#define TIMER3_BASE_ADDRESS             0x40033000UL
#define TIMER4_BASE_ADDRESS             0x40034000UL
#define TIMER5_BASE_ADDRESS             0x40035000UL
#define WTIMER0_BASE_ADDRESS            0x40036000UL
#define WTIMER1_BASE_ADDRESS            0x40037000UL
#define WTIMER2_BASE_ADDRESS            0x4004C000UL
#define WTIMER3_BASE_ADDRESS            0x4004D000UL
#define WTIMER4_BASE_ADDRESS            0x4004E000UL
#define WTIMER5_BASE_ADDRESS            0x4004F000UL

/******************************************** Timer Register Definition **********************************************/

typedef struct
{
    volatile u32 CFG; /* GPTM Configuration */
    volatile u32 TAMR; /* GPTM Timer A Mode */
    volatile u32 TBMR; /* GPTM Timer B Mode */
    volatile u32 CTL; /* GPTM Control */
    volatile u32 SYNC; /* GPTM Synchronize */
    volatile u32 Reserved; /* Reserved 1 */
    volatile u32 IMR; /* GPTM Interrupt Mask */
    volatile u32 RIS; /* GPTM Raw Interrupt Status */
    volatile u32 MIS; /* GPTM Masked Interrupt Status */
    volatile u32 ICR; /* GPTM Interrupt Clear */
    volatile u32 TAILR; /* GPTM Timer A Interval Load */
    volatile u32 TBILR; /* GPTM Timer B Interval Load */
    volatile u32 TAMATCHR; /* GPTM Timer A Match */
    volatile u32 TBMATCHR; /* GPTM Timer B Match */
    volatile u32 TAPR; /* GPTM Timer A Prescale */
    volatile u32 TBPR; /* GPTM Timer B Prescale */
    volatile u32 TAPMR; /* GPTM TimerA Prescale Match */
    volatile u32 TBPMR; /* GPTM TimerB Prescale Match */
    volatile u32 TAR; /* GPTM Timer A */
    volatile u32 TBR; /* GPTM Timer B */
    volatile u32 TAV; /* GPTM Timer A Value */
    volatile u32 TBV; /* GPTM Timer B Value */
    volatile u32 RTCPD; /* GPTM RTC Predivide */
    volatile u32 TAPS; /* GPTM Timer A Prescale Snapshot */
    volatile u32 TBPS; /* GPTM Timer B Prescale Snapshot */
    volatile u32 TAPV; /* GPTM Timer A Prescale Value */
    volatile u32 TBPV; /* GPTM Timer B Prescale Value */
    volatile u32 Reserved2[981]; /* Reserved 2 */
    volatile u32 PP; /* GPTM Peripheral Properties */
} Timer_RegDef_t;

#define TIMER0                          ((Timer_RegDef_t*) TIMER0_BASE_ADDRESS)
#define TIMER1                          ((Timer_RegDef_t*) TIMER1_BASE_ADDRESS)
#define TIMER2                          ((Timer_RegDef_t*) TIMER2_BASE_ADDRESS)
#define TIMER3                          ((Timer_RegDef_t*) TIMER3_BASE_ADDRESS)
#define TIMER4                          ((Timer_RegDef_t*) TIMER4_BASE_ADDRESS)
#define TIMER5                          ((Timer_RegDef_t*) TIMER5_BASE_ADDRESS)
#define W_TIMER0                         ((Timer_RegDef_t*) WTIMER0_BASE_ADDRESS)
#define W_TIMER1                         ((Timer_RegDef_t*) WTIMER1_BASE_ADDRESS)
#define W_TIMER2                         ((Timer_RegDef_t*) WTIMER2_BASE_ADDRESS)
#define W_TIMER3                         ((Timer_RegDef_t*) WTIMER3_BASE_ADDRESS)
#define W_TIMER4                         ((Timer_RegDef_t*) WTIMER4_BASE_ADDRESS)
#define W_TIMER5                         ((Timer_RegDef_t*) WTIMER5_BASE_ADDRESS)

/******************************************** ADC Base Definition ****************************************************/

#define ADC0_BASE_ADDRESS               0x40038000UL
#define ADC1_BASE_ADDRESS               0x40039000UL

/******************************************** ADC Base Register ******************************************************/

typedef struct
{
    volatile u32 ACTSS; /* ADC Active Sample Sequencer */
    volatile u32 RIS; /* ADC Raw Interrupt Status  */
    volatile u32 IM; /* ADC Interrupt Mask */
    volatile u32 ISC; /* ADC Interrupt Status and Clear */
    volatile u32 OSTAT; /* ADC Overflow Status */
    volatile u32 EMUX; /* ADC Event Multiplexer Select */
    volatile u32 USTAT; /* ADC Underflow Status */
    volatile u32 TSSEL; /* ADC Trigger Source Select */
    volatile u32 SSPRI; /* ADC Sample Sequencer Priority */
    volatile u32 SPC; /* ADC Sample Phase Control  */
    volatile u32 PSSI; /* ADC Processor Sample Sequence Initiate */
    volatile u32 Reserved; /* Reserved 1 */
    volatile u32 SAC; /* ADC Sample Averaging Control */
    volatile u32 DCISC; /* ADC Digital Comparator Interrupt Status and Clear */
    volatile u32 CTL; /* ADC Control */
    volatile u32 Reserved2; /* Reserved 2 */
    volatile u32 SSMUX0; /* ADC Sample Sequence Input Multiplexer Select 0  */
    volatile u32 SSCTL0; /* ADC Sample Sequence Control  */
    volatile u32 SSFIFO0; /* ADC Sample Sequence Result FIFO 0  */
    volatile u32 SSFSTAT0; /* ADC Sample Sequence FIFO 0 Status */
    volatile u32 SSOP0; /* ADC Sample Sequence 0 Operation */
    volatile u32 SSDC0; /* ADC Sample Sequence 0 Digital Comparator Select */
    volatile u32 Reserved3[2]; /* Reserved 3 */
    volatile u32 SSMUX1; /* ADC Sample Sequence Input Multiplexer Select 1 */
    volatile u32 SSCTL1; /* ADC Sample Sequence Control 1 */
    volatile u32 SSFIFO1; /* ADC Sample Sequence Result FIFO 1 */
    volatile u32 SSFSTAT1; /* ADC Sample Sequence FIFO 1 Status */
    volatile u32 SSOP1; /* ADC Sample Sequence 1 Operation */
    volatile u32 SSDC1; /* ADC Sample Sequence 1 Digital Comparator Select */
    volatile u32 Reserved4[2]; /* Reserved 4 */
    volatile u32 SSMUX2; /* ADC Sample Sequence Input Multiplexer Select 2 */
    volatile u32 SSCTL2; /* ADC Sample Sequence Control 2  */
    volatile u32 SSFIFO2; /* ADC Sample Sequence Result FIFO 2 */
    volatile u32 SSFSTAT2; /* ADC Sample Sequence FIFO 2 Status */
    volatile u32 SSOP2; /* ADC Sample Sequence 2 Operation */
    volatile u32 SSDC2; /* ADC Sample Sequence 2 Digital Comparator Select */
    volatile u32 Reserved5[2]; /* Reserved 5 */
    volatile u32 SSMUX3; /* ADC Sample Sequence Input Multiplexer Select 3 */
    volatile u32 SSCTL3; /* ADC Sample Sequence Control 3 */
    volatile u32 SSFIFO3; /* ADC Sample Sequence Result FIFO 3 */
    volatile u32 SSFSTAT3; /* ADC Sample Sequence FIFO 3 Status */
    volatile u32 SSOP3; /* ADC Sample Sequence 3 Operation  */
    volatile u32 SSDC3; /* ADC Sample Sequence 3 Digital Comparator Select */
    volatile u32 Reserved6[787]; /* Reserved 6 */
    volatile u32 DCRIC; /* ADC Digital Comparator Reset Initial Conditions */
    volatile u32 Reserved7[63]; /* Reserved 7 */
    volatile u32 DCCTL0; /* ADC Digital Comparator Control 0 */
    volatile u32 DCCTL1; /* ADC Digital Comparator Control 1 */
    volatile u32 DCCTL2; /* ADC Digital Comparator Control 2 */
    volatile u32 DCCTL3; /* ADC Digital Comparator Control 3 */
    volatile u32 DCCTL4; /* ADC Digital Comparator Control 4 */
    volatile u32 DCCTL5; /* ADC Digital Comparator Control 5 */
    volatile u32 DCCTL6; /* ADC Digital Comparator Control 6 */
    volatile u32 DCCTL7; /* ADC Digital Comparator Control 7 */
    volatile u32 Reserved8[8]; /* Reserved 8 */
    volatile u32 DCCMP0; /* ADC Digital Comparator Range 0 */
    volatile u32 DCCMP1; /* ADC Digital Comparator Range 1 */
    volatile u32 DCCMP2; /* ADC Digital Comparator Range 2 */
    volatile u32 DCCMP3; /* ADC Digital Comparator Range 3 */
    volatile u32 DCCMP4; /* ADC Digital Comparator Range 4 */
    volatile u32 DCCMP5; /* ADC Digital Comparator Range 5 */
    volatile u32 DCCMP6; /* ADC Digital Comparator Range 6 */
    volatile u32 DCCMP7; /* ADC Digital Comparator Range 7 */
    volatile u32 Reserved9[88]; /* Reserved 9 */
    volatile u32 PP; /* ADC Peripheral Properties */
    volatile u32 PC; /* ADC Peripheral Configuration */
    volatile u32 CC; /* ADC Clock Configuration */
} ADC_RegDef_t;

#define ADC0                            ((ADC_RegDef_t*) ADC0_BASE_ADDRESS)
#define ADC1                            ((ADC_RegDef_t*) ADC1_BASE_ADDRESS)

/******************************************** UART Base Definition ***************************************************/

#define UART0_BASE_ADDRESS              0x4000C000UL
#define UART1_BASE_ADDRESS              0x4000D000UL
#define UART2_BASE_ADDRESS              0x4000E000UL
#define UART3_BASE_ADDRESS              0x4000F000UL
#define UART4_BASE_ADDRESS              0x40010000UL
#define UART5_BASE_ADDRESS              0x40011000UL
#define UART6_BASE_ADDRESS              0x40012000UL
#define UART7_BASE_ADDRESS              0x40013000UL

/******************************************** UART Register Definition ***********************************************/

typedef struct
{
    volatile u32 DR; /* UART Data */
    volatile u32 RSRECR; /* UART Receive Status/Error Clear */
    volatile u32 RESERVED[4]; /* Reserved 1 */
    volatile u32 FR; /* UART Flag */
    volatile u32 RESERVED2; /* Reserved 2 */
    volatile u32 ILPR; /* UART IrDA Low-Power Register */
    volatile u32 IBRD; /* UART Integer Baud-Rate Divisor */
    volatile u32 FBRD; /* UART Fractional Baud-Rate Divisor */
    volatile u32 LCRH; /* UART Line Control */
    volatile u32 CTL; /* UART Control */
    volatile u32 IFLS; /* UART Interrupt FIFO Level Select */
    volatile u32 IM; /* UART Interrupt Mask */
    volatile u32 RIS; /* UART Raw Interrupt Status */
    volatile u32 MIS; /* UART Masked Interrupt Status */
    volatile u32 ICR; /* UART Interrupt Clear */
    volatile u32 DMACTL; /* UART DMA Control */
    volatile u32 RESERVED3[22]; /* Reserved 3 */
    volatile u32 _9BITADDR; /* UART 9-Bit Self Address */
    volatile u32 _9BITAMASK; /* UART 9-Bit Self Address Mask */
    volatile u32 RESERVED4[965]; /* Reserved 4 */
    volatile u32 PP; /* UART Peripheral Properties */
    volatile u32 RESERVED5; /* Reserved 5 */
    volatile u32 CC; /* UART Clock Configuration */
    volatile u32 RESERVED6; /* Reserved 6 */
    volatile u32 PeriphlD4; /* UART Peripheral Identification 4 */
    volatile u32 PeriphID5; /* UART Peripheral Identification 5 */
    volatile u32 PeriphID6; /* UART Peripheral Identification 6 */
    volatile u32 PeriphID7; /* UART Peripheral Identification 7 */
    volatile u32 PeriphID0; /* UART Peripheral Identification 0 */
    volatile u32 PeriphID1; /* UART Peripheral Identification 1 */
    volatile u32 PeriphID2; /* UART Peripheral Identification 2 */
    volatile u32 PeriphID3; /* UART Peripheral Identification 3 */
    volatile u32 PCelllD0; /* UART PrimeCell Identification 0 */
    volatile u32 PCelllD1; /* UART PrimeCell Identification 1 */
    volatile u32 PCelllD2; /* UART PrimeCell Identification 2 */
    volatile u32 PCelllD3; /* UART PrimeCell Identification 3 */
} UART_RegDef_t;

#define UART0                           ((UART_RegDef_t*) UART0_BASE_ADDRESS)
#define UART1                           ((UART_RegDef_t*) UART1_BASE_ADDRESS)
#define UART2                           ((UART_RegDef_t*) UART2_BASE_ADDRESS)
#define UART3                           ((UART_RegDef_t*) UART3_BASE_ADDRESS)
#define UART4                           ((UART_RegDef_t*) UART4_BASE_ADDRESS)
#define UART5                           ((UART_RegDef_t*) UART5_BASE_ADDRESS)
#define UART6                           ((UART_RegDef_t*) UART6_BASE_ADDRESS)
#define UART7                           ((UART_RegDef_t*) UART7_BASE_ADDRESS)

/******************************************** SSI Base Definition ****************************************************/

#define SSI0_BASE_ADDRESS               0x40008000UL
#define SSI1_BASE_ADDRESS               0x40009000UL
#define SSI2_BASE_ADDRESS               0x4000A000UL
#define SSI3_BASE_ADDRESS               0x4000B000UL

/******************************************** SSI Register Definition ************************************************/

typedef struct
{
    volatile u32 CR0; /* SSI Control 0 */
    volatile u32 CR1; /* SSI Control 1 */
    volatile u32 DR; /* SSI Data */
    volatile u32 SR; /* SSI Status */
    volatile u32 CPSR; /* SSI Clock Prescale */
    volatile u32 IM; /* SSI Interrupt Mask */
    volatile u32 RIS; /* SSI Raw Interrupt Status */
    volatile u32 MIS; /* SSI Masked Interrupt Status */
    volatile u32 ICR; /* SSI Interrupt Clear */
    volatile u32 DMACTL; /* SSI DMA Control */
    volatile u32 RESERVED[1000]; /* Reserved 1 */
    volatile u32 CC; /* SSI Clock Configuration */
    volatile u32 RESERVED2; /* Reserved 2 */
    volatile u32 PeriphlD4; /* SSI Peripheral Identification 4 */
    volatile u32 PeriphID5; /* SSI Peripheral Identification 5 */
    volatile u32 PeriphID6; /* SSI Peripheral Identification 6 */
    volatile u32 PeriphID7; /* SSI Peripheral Identification 7 */
    volatile u32 PeriphID0; /* SSI Peripheral Identification 0 */
    volatile u32 PeriphID1; /* SSI Peripheral Identification 1 */
    volatile u32 PeriphID2; /* SSI Peripheral Identification 2 */
    volatile u32 PeriphID3; /* SSI Peripheral Identification 3 */
    volatile u32 PCelllD0; /* SSI PrimeCell Identification 0 */
    volatile u32 PCelllD1; /* SSI PrimeCell Identification 1 */
    volatile u32 PCelllD2; /* SSI PrimeCell Identification 2 */
    volatile u32 PCelllD3; /* SSI PrimeCell Identification 3 */
} SSI_RegDef_t;

#define SSI0                            ((SSI_RegDef_t*) SSI0_BASE_ADDRESS)
#define SSI1                            ((SSI_RegDef_t*) SSI1_BASE_ADDRESS)
#define SSI2                            ((SSI_RegDef_t*) SSI2_BASE_ADDRESS)
#define SSI3                            ((SSI_RegDef_t*) SSI3_BASE_ADDRESS)

/******************************************** I2C Base Definition ****************************************************/

#define I2C0_BASE_ADDRESS               0x40020000UL
#define I2C1_BASE_ADDRESS               0x40021000UL
#define I2C2_BASE_ADDRESS               0x40022000UL
#define I2C3_BASE_ADDRESS               0x40023000UL

/******************************************** I2C Register Definition ************************************************/

typedef struct
{
    /* I2C Master Registers */
    volatile u32 MSA; /* I2C Master Slave Address */
    volatile u32 MCS; /* I2C Master Control/Status */
    volatile u32 MDR; /* I2C Master Data */
    volatile u32 MTPR; /* I2C Master Timer Period */
    volatile u32 MIMR; /* I2C Master Interrupt Mask */
    volatile u32 MRIS; /* I2C Master Raw Interrupt Status */
    volatile u32 MMIS; /* I2C Master Masked Interrupt Status */
    volatile u32 MICR; /* I2C Master Interrupt Clear */
    volatile u32 MCR; /* I2C Master Configuration */
    volatile u32 MCLKOCNT; /* I2C Master Clock Low Timeout Count */
    volatile u32 MBMON; /* I2C Master Bus Monitor */
    volatile u32 RESERVED[2]; /* Reserved 1 */
    volatile u32 MCR2; /* I2C Master Configuration2 */
    volatile u32 RESERVED2[497]; /* Reserved 2 */
    /* I2C Slave Registers */
    volatile u32 SOAR; /* I2C Slave Own Address */
    volatile u32 SCSR; /* I2C Slave Control/Status */
    volatile u32 SDR; /* I2C Slave Data */
    volatile u32 SIMR; /* I2C Slave Interrupt Mask */
    volatile u32 SRIS; /* I2C Slave Raw Interrupt Status */
    volatile u32 SMIS; /* I2C Slave Masked Interrupt Status */
    volatile u32 SICR; /* I2C Slave Interrupt Clear */
    volatile u32 SOAR2; /* I2C Slave Own Address 2 */
    volatile u32 SACKCTL; /* I2C Slave ACK Control  */
    volatile u32 RESERVED3[487]; /* Reserved 3 */
    /* I2C Status and Control Registers */
    volatile u32 PP; /* I2C Peripheral Properties */
    volatile u32 CC; /* I2C Peripheral Configuration */
} I2C_RegDef_t;

#define I2C0                            ((I2C_RegDef_t*) I2C0_BASE_ADDRESS)
#define I2C1                            ((I2C_RegDef_t*) I2C1_BASE_ADDRESS)
#define I2C2                            ((I2C_RegDef_t*) I2C2_BASE_ADDRESS)
#define I2C3                            ((I2C_RegDef_t*) I2C3_BASE_ADDRESS)

/******************************************** PWM Base Definition ****************************************************/

#define PWM0_BASE_ADDRESS               0x40028000UL
#define PWM1_BASE_ADDRESS               0x40029000UL

/******************************************** PWM Register Definition ************************************************/

typedef struct
{
    volatile u32 CTL; /* PWM Master Control */
    volatile u32 SYNC; /* PWM Time Base Sync */
    volatile u32 ENABLE; /* PWM Output Enable */
    volatile u32 INVERT; /* PWM Output Inversion */
    volatile u32 FAULT; /* PWM Output Fault */
    volatile u32 INTEN; /* PWM Interrupt Enable */
    volatile u32 RIS; /* PWM Raw Interrupt Status */
    volatile u32 ISC; /* PWM Interrupt Status and Clear */
    volatile u32 STATUS; /* PWM Status */
    volatile u32 FAULTVAL; /* PWM Fault Condition Value */
    volatile u32 ENUPD; /* PWM Enable Update */
    volatile u32 RESERVED[5]; /* Reserved 1 */
    volatile u32 _0_CTL; /* PWM0 Control */
    volatile u32 _0_INTEN; /* PWM0 Interrupt and Trigger Enable */
    volatile u32 _0_RIS; /* PWM0 Raw Interrupt Status */
    volatile u32 _0_ISC; /* PWM0 Interrupt Status and Clear */
    volatile u32 _0_LOAD; /* PWM0 Load */
    volatile u32 _0_COUNT; /* PWM0 Counter */
    volatile u32 _0_CMPA; /* PWM0 Compare A */
    volatile u32 _0_CMPB; /* PWM0 Compare B */
    volatile u32 _0_GENA; /* PWM0 Generator A Control */
    volatile u32 _0_GENB; /* PWM0 Generator B Control */
    volatile u32 _0_DBCTL; /* PWM0 Dead-Band Control */
    volatile u32 _0_DBRISE; /* PWM0 Dead-Band Rising-Edge Delay */
    volatile u32 _0_DBFALL; /* PWM0 Dead-Band Falling-Edge-Delay */
    volatile u32 _0_FLTSRC0; /* PWM0 Fault Source 0 */
    volatile u32 _0_FLTSRC1; /* PWM0 Fault Source 1 */
    volatile u32 _0_MINFLTPER; /* PWM0 Minimum Fault Period */
    volatile u32 _1_CTL; /* PWM1 Control */
    volatile u32 _1_INTEN; /* PWM1 Interrupt and Trigger Enable */
    volatile u32 _1_RIS; /* PWM1 Raw Interrupt Status */
    volatile u32 _1_ISC; /* PWM1 Interrupt Status and Clear */
    volatile u32 _1_LOAD; /* PWM1 Load */
    volatile u32 _1_COUNT; /* PWM1 Counter */
    volatile u32 _1_CMPA; /* PWM1 Compare A */
    volatile u32 _1_CMPB; /* PWM1 Compare B */
    volatile u32 _1_GENA; /* PWM1 Generator A Control */
    volatile u32 _1_GENB; /* PWM1 Generator B Control */
    volatile u32 _1_DBCTL; /* PWM1 Dead-Band Control */
    volatile u32 _1_DBRISE; /* PWM1 Dead-Band Rising-Edge Delay */
    volatile u32 _1_DBFALL; /* PWM1 Dead-Band Falling-Edge-Delay */
    volatile u32 _1_FLTSRC0; /* PWM1 Fault Source 0 */
    volatile u32 _1_FLTSRC1; /* PWM1 Fault Source 1 */
    volatile u32 _1_MINFLTPER; /* PWM1 Minimum Fault Period */
    volatile u32 _2_CTL; /* PWM2 Control */
    volatile u32 _2_INTEN; /* PWM2 Interrupt and Trigger Enable */
    volatile u32 _2_RIS; /* PWM2 Raw Interrupt Status */
    volatile u32 _2_ISC; /* PWM2 Interrupt Status and Clear */
    volatile u32 _2_LOAD; /* PWM2 Load */
    volatile u32 _2_COUNT; /* PWM2 Counter */
    volatile u32 _2_CMPA; /* PWM2 Compare A */
    volatile u32 _2_CMPB; /* PWM2 Compare B */
    volatile u32 _2_GENA; /* PWM2 Generator A Control */
    volatile u32 _2_GENB; /* PWM2 Generator B Control */
    volatile u32 _2_DBCTL; /* PWM2 Dead-Band Control */
    volatile u32 _2_DBRISE; /* PWM2 Dead-Band Rising-Edge Delay */
    volatile u32 _2_DBFALL; /* PWM2 Dead-Band Falling-Edge-Delay */
    volatile u32 _2_FLTSRC0; /* PWM2 Fault Source 0 */
    volatile u32 _2_FLTSRC1; /* PWM2 Fault Source 1 */
    volatile u32 _2_MINFLTPER; /* PWM2 Minimum Fault Period */
    volatile u32 _3_CTL; /* PWM3 Control */
    volatile u32 _3_INTEN; /* PWM3 Interrupt and Trigger Enable */
    volatile u32 _3_RIS; /* PWM3 Raw Interrupt Status */
    volatile u32 _3_ISC; /* PWM3 Interrupt Status and Clear */
    volatile u32 _3_LOAD; /* PWM3 Load */
    volatile u32 _3_COUNT; /* PWM3 Counter */
    volatile u32 _3_CMPA; /* PWM3 Compare A */
    volatile u32 _3_CMPB; /* PWM3 Compare B */
    volatile u32 _3_GENA; /* PWM3 Generator A Control */
    volatile u32 _3_GENB; /* PWM3 Generator B Control */
    volatile u32 _3_DBCTL; /* PWM3 Dead-Band Control */
    volatile u32 _3_DBRISE; /* PWM3 Dead-Band Rising-Edge Delay */
    volatile u32 _3_DBFALL; /* PWM3 Dead-Band Falling-Edge-Delay */
    volatile u32 _3_FLTSRC0; /* PWM3 Fault Source 0 */
    volatile u32 _3_FLTSRC1; /* PWM3 Fault Source 1 */
    volatile u32 _3_MINFLTPER; /* PWM3 Minimum Fault Period */
    volatile u32 RESERVED2[432]; /* Reserved 2 */
    volatile u32 _0_FLTSEN; /* PWM0 Fault Pin Logic Sense */
    volatile u32 _0_FLTSTAT0; /* PWM0 Fault Status 0 */
    volatile u32 _0_FLTSTAT1; /* PWM0 Fault Status 1 */
    volatile u32 RESERVED3[29]; /* Reserved 3 */
    volatile u32 _1_FLTSEN; /* PWM1 Fault Pin Logic Sense */
    volatile u32 _1_FLTSTAT0; /* PWM1 Fault Status 0 */
    volatile u32 _1_FLTSTAT1; /* PWM1 Fault Status 1 */
    volatile u32 RESERVED4[30]; /* Reserved 4 */
    volatile u32 _2_FLTSTAT0; /* PWM2 Fault Status 0 */
    volatile u32 _2_FLTSTAT1; /* PWM2 Fault Status 1 */
    volatile u32 RESERVED5[30];
    volatile u32 _3_FLTSTAT0; /* PWM3 Fault Status 0 */
    volatile u32 _3_FLTSTAT1; /* PWM3 Fault Status 1 */
    volatile u32 RESERVED6[397]; /* Reserved 6 */
    volatile u32 PP; /* PWM Peripheral Properties */
} PWM_RegDef_t;

#define PWM0                            ((PWM_RegDef_t*) PWM0_BASE_ADDRESS)
#define PWM1                            ((PWM_RegDef_t*) PWM1_BASE_ADDRESS)

/******************************************** NVIC Base Definition ***************************************************/

#define NVIC_BASE_ADDRESS               0xE000E000UL

/******************************************** NVIC Register Definition ***********************************************/

typedef struct
{
    volatile u32 Reserved[2]; /* Reserved 1 */
    volatile u32 ACTLR; /* Auxiliary Control  */
    volatile u32 Reserved2; /* Reserved 2 */
    /* SysTick Registers */
    volatile u32 STCTRL; /* SysTick Control and Status Register */
    volatile u32 STRELEAD; /* SysTick Reload Value Register */
    volatile u32 STCURRENT; /* SysTick Current Value Register */
    volatile u32 Reserved3[57]; /* Reserved 3 */
    /* NVIC Registers */
    volatile u32 EN0; /* Interrupt 0-31 Set Enable */
    volatile u32 EN1; /* Interrupt 32-63 Set Enable */
    volatile u32 EN2; /* Interrupt 64-95 Set Enable */
    volatile u32 EN3; /* Interrupt 96-127 Set Enable */
    volatile u32 EN4; /* Interrupt 128-138 Set Enable */
    volatile u32 Reserved4[27]; /* Reserved 4 */
    volatile u32 DIS0; /* Interrupt 0-31 Clear Enable */
    volatile u32 DIS1; /* Interrupt 32-63 Clear Enable */
    volatile u32 DIS2; /* Interrupt 64-95 Clear Enable */
    volatile u32 DIS3; /* Interrupt 96-127 Clear Enable */
    volatile u32 DIS4; /* Interrupt 128-138 Clear Enable */
    volatile u32 Reserved5[27]; /* Reserved 5 */
    volatile u32 PEND0; /* Interrupt 0-31 Set Pending */
    volatile u32 PEND1; /* Interrupt 32-63 Set Pending */
    volatile u32 PEND2; /* Interrupt 64-95 Set Pending */
    volatile u32 PEND3; /* Interrupt 96-127 Set Pending */
    volatile u32 PEND4; /* Interrupt 128-138 Set Pending */
    volatile u32 Reserved6[27]; /* Reserved 6 */
    volatile u32 UNPEND0; /* Interrupt 0-31 Clear Pending */
    volatile u32 UNPEND1; /* Interrupt 32-63 Clear Pending */
    volatile u32 UNPEND2; /* Interrupt 64-95 Clear Pending */
    volatile u32 UNPEND3; /* Interrupt 96-127 Clear Pending */
    volatile u32 UNPEND4; /* Interrupt 128-138 Clear Pending */
    volatile u32 Reserved7[27]; /* Reserved 7 */
    volatile u32 ACTIVE0; /* Interrupt 0-31 Active Bit */
    volatile u32 ACTIVE1; /* Interrupt 32-63 Active Bit */
    volatile u32 ACTIVE2; /* Interrupt 64-95 Active Bit */
    volatile u32 ACTIVE4; /* Interrupt 128-138 Active Bit */
    volatile u32 Reserved8[59]; /* Reserved 8 */
    volatile u32 PRI0; /* Interrupt 0-3 Priority */
    volatile u32 PRI1; /* Interrupt 4-7 Priority */
    volatile u32 PRI2; /* Interrupt 8-11 Priority */
    volatile u32 PRI3; /* Interrupt 12-15 Priority */
    volatile u32 PRI4; /* Interrupt 16-19 Priority */
    volatile u32 PRI5; /* Interrupt 20-23 Priority */
    volatile u32 PRI6; /* Interrupt 24-27 Priority */
    volatile u32 PRI7; /* Interrupt 28-31 Priority */
    volatile u32 PRI8; /* Interrupt 32-35 Priority */
    volatile u32 PRI9; /* Interrupt 36-39 Priority */
    volatile u32 PRI10; /* Interrupt 40-43 Priority */
    volatile u32 PRI11; /* Interrupt 44-47 Priority */
    volatile u32 PRI12; /* Interrupt 48-51 Priority */
    volatile u32 PRI13; /* Interrupt 52-55 Priority */
    volatile u32 PRI14; /* Interrupt 56-59 Priority */
    volatile u32 PRI15; /* Interrupt 60-63 Priority */
    volatile u32 PRI16; /* Interrupt 64-67 Priority */
    volatile u32 PRI17; /* Interrupt 68-71 Priority */
    volatile u32 PRI18; /* Interrupt 72-75 Priority */
    volatile u32 PRI19; /* Interrupt 76-79 Priority */
    volatile u32 PRI20; /* Interrupt 80-83 Priority */
    volatile u32 PRI21; /* Interrupt 84-87 Priority */
    volatile u32 PRI22; /* Interrupt 88-91 Priority */
    volatile u32 PRI23; /* Interrupt 92-95 Priority */
    volatile u32 PRI24; /* Interrupt 96-99 Priority */
    volatile u32 PRI25; /* Interrupt 100-103 Priority */
    volatile u32 PRI26; /* Interrupt 104-107 Priority */
    volatile u32 PRI27; /* Interrupt 108-111 Priority */
    volatile u32 PRI28; /* Interrupt 112-115 Priority */
    volatile u32 PRI29; /* Interrupt 116-119 Priority */
    volatile u32 PRI30; /* Interrupt 120-123 Priority */
    volatile u32 PRI31; /* Interrupt 124-127 Priority */
    volatile u32 PRI32; /* Interrupt 128-131 Priority */
    volatile u32 PRI33; /* Interrupt 132-135 Priority */
    volatile u32 PRI34; /* Interrupt 136-138 Priority */
    volatile u32 Reserved9[541]; /* Reserved 9 */
    volatile u32 CPUID; /* CPU ID Base */
    volatile u32 INTCTRL; /* Interrupt Control and State */
    volatile u32 VTABLE; /* Vector Table Offset */
    volatile u32 APINT; /* Application Interrupt and Reset Control */
    volatile u32 SYSCTRL; /* System Control */
    volatile u32 CFGCTRL; /* Configuration and Control */
    volatile u32 SYSPRI1; /* System Handler Priority 1 */
    volatile u32 SYSPRI2; /* System Handler Priority 2 */
    volatile u32 SYSPRI3; /* System Handler Priority 3 */
    volatile u32 SYSHNDCTRL; /* System Handler Control and State */
    volatile u32 FAULTSTAT; /* Configurable Fault Status  */
    volatile u32 HFAULTSTAT; /* Hard Fault Status  */
    volatile u32 Reserved10; /* Reserved 10 */
    volatile u32 MMADDR; /* Memory Management Fault Address */
    volatile u32 FAULTADDR; /* Bus Fault Address */
    volatile u32 Reserved11[19]; /* Reserved 11 */
    volatile u32 CPAC; /* Coprocessor Access Control */
    volatile u32 Reserved12; /* Reserved 12 */
    volatile u32 MPUTYPE; /* MPU Type */
    volatile u32 MPUCTRL; /* MPU Control */
    volatile u32 MPUNUMBER; /* MPU Region Number */
    volatile u32 MPUBASE; /* MPU Region Base Address */
    volatile u32 MPUATTR; /* MPU Region Attribute and Size */
    volatile u32 MPUBASE1; /* MPU Region Base Address Alias 1 */
    volatile u32 MPUATTR1; /* MPU Region Attribute and Size Alias 1 */
    volatile u32 MPUBASE2; /* MPU Region Base Address Alias 2 */
    volatile u32 MPUATTR2; /* MPU Region Attribute and Size Alias 2 */
    volatile u32 MPUBASE3; /* MPU Region Base Address Alias 3 */
    volatile u32 MPUATTR3; /* MPU Region Attribute and Size Alias 3 */
    volatile u32 Reserved13[81]; /* Reserved 13 */
    volatile u32 SWTRIG; /* Software Trigger Interrupt */
    volatile u32 Reserved14[12]; /* Reserved 14 */
    volatile u32 FPCC; /* Floating-Point Context Control */
    volatile u32 FPCA; /* Floating-Point Context Address */
    volatile u32 FPDSC; /* Floating-Point Default Status Control */
} NVIC_RegDef_t;

#define NVIC                            ((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)

#endif /* UTILS_REGISTER_MAP_H_ */
