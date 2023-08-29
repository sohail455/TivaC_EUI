/*************************************************************************
 * Author:      Sohail.
 * FILE:        TM4C123XX_reg.h.
 * Module:      TM4C123XX_reg.
 * version:     1.00.
 * Description: Registers Definition.
 *************************************************************************/

#ifndef TM4C123XX_REG_H_
#define TM4C123XX_REG_H_
#include "Platform_Types.h"

#define SYSCTL_BASE_ADDRESS       0x400FE000UL

#define SYSTCL_RCGCGPIO           *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x608))


#define GPIO_PORTA_BASE_ADDRESS    0x40004000UL
#define GPIO_PORTB_BASE_ADDRESS    0x40005000UL
#define GPIO_PORTC_BASE_ADDRESS    0x40006000UL
#define GPIO_PORTD_BASE_ADDRESS    0x40007000UL
#define GPIO_PORTE_BASE_ADDRESS    0x40024000UL
#define GPIO_PORTF_BASE_ADDRESS    0x40025000UL

#define TIMER0_BASE_ADDRESS        0x40030000UL
#define TIMER1_BASE_ADDRESS        0x40031000UL
#define TIMER2_BASE_ADDRESS        0x40032000UL
#define TIMER3_BASE_ADDRESS        0x40033000UL
#define TIMER4_BASE_ADDRESS        0x40034000UL
#define TIMER5_BASE_ADDRESS        0x40035000UL
#define W_TIMER0_BASE_ADDRESS      0x40036000UL
#define W_TIMER1_BASE_ADDRESS      0x40037000UL
#define W_TIMER2_BASE_ADDRESS      0x4004C000UL
#define W_TIMER3_BASE_ADDRESS      0x4004D000UL
#define W_TIMER4_BASE_ADDRESS      0x4004E000UL
#define W_TIMER5_BASE_ADDRESS      0x4004F000UL

typedef struct
{
   u32 DATA[256];      /*GPIO DATA*/
   u32 DIR;            /*GPIO Direction Input/Output*/
   u32 IS;             /*GPIO interrupt sense level/edge*/
   u32 IBE;            /*GPIO enable interrupt on both edges*/
   u32 IEV;            /*GPIO interrupt event falling/rising edges or low/high level*/
   u32 IM;             /*GPIO interrupt mask*/
   u32 RIS;            /*GPIO raw Interrupt status*/
   u32 MIS;            /*GPIO masked interrupt status*/
   u32 ICR;            /*GPIO Interrupt clear register*/
   u32 AFSEL;          /*GPIO alternative function selection*/
   u32 reserved1[55];
   u32 R2R;            /*GPIO 2mA Drive select*/
   u32 R4R;            /*GPIO 4mA Drive select*/
   u32 R8R;            /*GPIO 8mA Drive select*/
   u32 OPD;            /*GPIO open drain select*/
   u32 PUR;            /*GPIO pull up select*/
   u32 PDR;            /*GPIO Pull Down select*/
   u32 SLR;            /*GPIO Slew Rate Control select*/
   u32 DEN;            /*GPIO Digital Enable select*/
   u32 LOCK;           /*GPIO Lock Register*/
   u32 CR;             /*GPIO Commit register*/
   u32 AMSEL;          /*GPIO Analog Mode select*/
   u32 PCTL;           /*GPIO Port control*/
   u32 ADCCTL;         /*GPIO ADC control register*/
   u32 DMACTL;         /*GPIO DMA Control Register*/
}GPIO_RegDef_t;

#define GPIOA    ((GPIO_RegDef_t *)GPIO_PORTA_BASE_ADDRESS)
#define GPIOB    ((GPIO_RegDef_t *)GPIO_PORTB_BASE_ADDRESS)
#define GPIOC    ((GPIO_RegDef_t *)GPIO_PORTC_BASE_ADDRESS)
#define GPIOD    ((GPIO_RegDef_t *)GPIO_PORTD_BASE_ADDRESS)
#define GPIOE    ((GPIO_RegDef_t *)GPIO_PORTE_BASE_ADDRESS)
#define GPIOF    ((GPIO_RegDef_t*)GPIO_PORTF_BASE_ADDRESS)

/*********************************SYSTEM CONTROL***********************************/
typedef struct
{ /*!< SYSCTL Structure                                                      */
    volatile u32 DID0; /*!< Device Identification 0                                               */
    volatile u32 DID1; /*!< Device Identification 1                                               */
    volatile u32 DC0; /*!< Device Capabilities 0                                                 */
    volatile u32 RESERVED0;
    volatile u32 DC1; /*!< Device Capabilities 1                                                 */
    volatile u32 DC2; /*!< Device Capabilities 2                                                 */
    volatile u32 DC3; /*!< Device Capabilities 3                                                 */
    volatile u32 DC4; /*!< Device Capabilities 4                                                 */
    volatile u32 DC5; /*!< Device Capabilities 5                                                 */
    volatile u32 DC6; /*!< Device Capabilities 6                                                 */
    volatile u32 DC7; /*!< Device Capabilities 7                                                 */
    volatile u32 DC8; /*!< Device Capabilities 8                                                 */
    volatile u32 PBORCTL; /*!< Brown-Out Reset Control                                               */
    volatile u32 RESERVED1[3];
    volatile u32 SRCR0; /*!< Software Reset Control 0                                              */
    volatile u32 SRCR1; /*!< Software Reset Control 1                                              */
    volatile u32 SRCR2; /*!< Software Reset Control 2                                              */
    volatile u32 RESERVED2;
    volatile u32 RIS; /*!< Raw Interrupt Status                                                  */
    volatile u32 IMC; /*!< Interrupt Mask Control                                                */
    volatile u32 MISC; /*!< Masked Interrupt Status and Clear                                     */
    volatile u32 RESC; /*!< Reset Cause                                                           */
    volatile u32 RCC; /*!< Run-Mode Clock Configuration                                          */
    volatile u32 RESERVED3[2];
    volatile u32 GPIOHBCTL; /*!< GPIO High-Performance Bus Control                                     */
    volatile u32 RCC2; /*!< Run-Mode Clock Configuration 2                                        */
    volatile u32 RESERVED4[2];
    volatile u32 MOSCCTL; /*!< Main Oscillator Control                                               */
    volatile u32 RESERVED5[32];
    volatile u32 RCGC0; /*!< Run Mode Clock Gating Control Register 0                              */
    volatile u32 RCGC1; /*!< Run Mode Clock Gating Control Register 1                              */
    volatile u32 RCGC2; /*!< Run Mode Clock Gating Control Register 2                              */
    volatile u32 RESERVED6;
    volatile u32 SCGC0; /*!< Sleep Mode Clock Gating Control Register 0                            */
    volatile u32 SCGC1; /*!< Sleep Mode Clock Gating Control Register 1                            */
    volatile u32 SCGC2; /*!< Sleep Mode Clock Gating Control Register 2                            */
    volatile u32 RESERVED7;
    volatile u32 DCGC0; /*!< Deep Sleep Mode Clock Gating Control Register 0                       */
    volatile u32 DCGC1; /*!< Deep-Sleep Mode Clock Gating Control Register 1                       */
    volatile u32 DCGC2; /*!< Deep Sleep Mode Clock Gating Control Register 2                       */
    volatile u32 RESERVED8[6];
    volatile u32 DSLPCLKCFG; /*!< Deep Sleep Clock Configuration                                        */
    volatile u32 RESERVED9;
    volatile u32 SYSPROP; /*!< System Properties                                                     */
    volatile u32 PIOSCCAL; /*!< Precision Internal Oscillator Calibration                             */
    volatile u32 PIOSCSTAT; /*!< Precision Internal Oscillator Statistics                              */
    volatile u32 RESERVED10[2];
    volatile u32 PLLFREQ0; /*!< PLL Frequency 0                                                       */
    volatile u32 PLLFREQ1; /*!< PLL Frequency 1                                                       */
    volatile u32 PLLSTAT; /*!< PLL Status                                                            */
    volatile u32 RESERVED11[7];
    volatile u32 SLPPWRCFG; /*!< Sleep Power Configuration                                             */
    volatile u32 DSLPPWRCFG; /*!< Deep-Sleep Power Configuration                                        */
    volatile u32 DC9; /*!< Device Capabilities 9                                                 */
    volatile u32 RESERVED12[3];
    volatile u32 NVMSTAT; /*!< Non-Volatile Memory Information                                       */
    volatile u32 RESERVED13[4];
    volatile u32 LDOSPCTL; /*!< LDO Sleep Power Control                                               */
    volatile u32 RESERVED14;
    volatile u32 LDODPCTL; /*!< LDO Deep-Sleep Power Control                                          */
    volatile u32 RESERVED15[80];
    volatile u32 PPWD; /*!< Watchdog Timer Peripheral Present                                     */
    volatile u32 PPTIMER; /*!< 16/32-Bit General-Purpose Timer Peripheral Present                    */
    volatile u32 PPGPIO; /*!< General-Purpose Input/Output Peripheral Present                       */
    volatile u32 PPDMA; /*!< Micro Direct Memory Access Peripheral Present                         */
    volatile u32 RESERVED16;
    volatile u32 PPHIB; /*!< Hibernation Peripheral Present                                        */
    volatile u32 PPUART; /*!< Universal Asynchronous Receiver/Transmitter Peripheral Present        */
    volatile u32 PPSSI; /*!< Synchronous Serial Interface Peripheral Present                       */
    volatile u32 PPI2C; /*!< Inter-Integrated Circuit Peripheral Present                           */
    volatile u32 RESERVED17;
    volatile u32 PPUSB; /*!< Universal Serial Bus Peripheral Present                               */
    volatile u32 RESERVED18[2];
    volatile u32 PPCAN; /*!< Controller Area Network Peripheral Present                            */
    volatile u32 PPADC; /*!< Analog-to-Digital Converter Peripheral Present                        */
    volatile u32 PPACMP; /*!< Analog Comparator Peripheral Present                                  */
    volatile u32 PPPWM; /*!< Pulse Width Modulator Peripheral Present                              */
    volatile u32 PPQEI; /*!< Quadrature Encoder Interface Peripheral Present                       */
    volatile u32 RESERVED19[4];
    volatile u32 PPEEPROM; /*!< EEPROM Peripheral Present                                             */
    volatile u32 PPWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Present               */
    volatile u32 RESERVED20[104];
    volatile u32 SRWD; /*!< Watchdog Timer Software Reset                                         */
    volatile u32 SRTIMER; /*!< 16/32-Bit General-Purpose Timer Software Reset                        */
    volatile u32 SRGPIO; /*!< General-Purpose Input/Output Software Reset                           */
    volatile u32 SRDMA; /*!< Micro Direct Memory Access Software Reset                             */
    volatile u32 RESERVED21;
    volatile u32 SRHIB; /*!< Hibernation Software Reset                                            */
    volatile u32 SRUART; /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
    volatile u32 SRSSI; /*!< Synchronous Serial Interface Software Reset                           */
    volatile u32 SRI2C; /*!< Inter-Integrated Circuit Software Reset                               */
    volatile u32 RESERVED22;
    volatile u32 SRUSB; /*!< Universal Serial Bus Software Reset                                   */
    volatile u32 RESERVED23[2];
    volatile u32 SRCAN; /*!< Controller Area Network Software Reset                                */
    volatile u32 SRADC; /*!< Analog-to-Digital Converter Software Reset                            */
    volatile u32 SRACMP; /*!< Analog Comparator Software Reset                                      */
    volatile u32 SRPWM; /*!< Pulse Width Modulator Software Reset                                  */
    volatile u32 SRQEI; /*!< Quadrature Encoder Interface Software Reset                           */
    volatile u32 RESERVED24[4];
    volatile u32 SREEPROM; /*!< EEPROM Software Reset                                                 */
    volatile u32 SRWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Software Reset                   */
    volatile u32 RESERVED25[40];
    volatile u32 RCGCWD; /*!< Watchdog Timer Run Mode Clock Gating Control                          */
    volatile u32 RCGCTIMER; /*!< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
    volatile u32 RCGCGPIO; /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
    volatile u32 RCGCDMA; /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
    volatile u32 RESERVED26;
    volatile u32 RCGCHIB; /*!< Hibernation Run Mode Clock Gating Control                             */
    volatile u32 RCGCUART; /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
     Control                                                               */
    volatile u32 RCGCSSI; /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
    volatile u32 RCGCI2C; /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
    volatile u32 RESERVED27;
    volatile u32 RCGCUSB; /*!< Universal Serial Bus Run Mode Clock Gating Control                    */
    volatile u32 RESERVED28[2];
    volatile u32 RCGCCAN; /*!< Controller Area Network Run Mode Clock Gating Control                 */
    volatile u32 RCGCADC; /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
    volatile u32 RCGCACMP; /*!< Analog Comparator Run Mode Clock Gating Control                       */
    volatile u32 RCGCPWM; /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
    volatile u32 RCGCQEI; /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
    volatile u32 RESERVED29[4];
    volatile u32 RCGCEEPROM; /*!< EEPROM Run Mode Clock Gating Control                                  */
    volatile u32 RCGCWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
    volatile u32 RESERVED30[40];
    volatile u32 SCGCWD; /*!< Watchdog Timer Sleep Mode Clock Gating Control                        */
    volatile u32 SCGCTIMER; /*!< 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
    volatile u32 SCGCGPIO; /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
    volatile u32 SCGCDMA; /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
    volatile u32 RESERVED31;
    volatile u32 SCGCHIB; /*!< Hibernation Sleep Mode Clock Gating Control                           */
    volatile u32 SCGCUART; /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
     Gating Control                                                        */
    volatile u32 SCGCSSI; /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
    volatile u32 SCGCI2C; /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
    volatile u32 RESERVED32;
    volatile u32 SCGCUSB; /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
    volatile u32 RESERVED33[2];
    volatile u32 SCGCCAN; /*!< Controller Area Network Sleep Mode Clock Gating Control               */
    volatile u32 SCGCADC; /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
    volatile u32 SCGCACMP; /*!< Analog Comparator Sleep Mode Clock Gating Control                     */
    volatile u32 SCGCPWM; /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
    volatile u32 SCGCQEI; /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
    volatile u32 RESERVED34[4];
    volatile u32 SCGCEEPROM; /*!< EEPROM Sleep Mode Clock Gating Control                                */
    volatile u32 SCGCWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
     Control                                                               */
    volatile u32 RESERVED35[40];
    volatile u32 DCGCWD; /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
    volatile u32 DCGCTIMER; /*!< 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
     Control                                                               */
    volatile u32 DCGCGPIO; /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
    volatile u32 DCGCDMA; /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
    volatile u32 RESERVED36;
    volatile u32 DCGCHIB; /*!< Hibernation Deep-Sleep Mode Clock Gating Control                      */
    volatile u32 DCGCUART; /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
     Clock Gating Control                                                  */
    volatile u32 DCGCSSI; /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
    volatile u32 DCGCI2C; /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
    volatile u32 RESERVED37;
    volatile u32 DCGCUSB; /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
    volatile u32 RESERVED38[2];
    volatile u32 DCGCCAN; /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
    volatile u32 DCGCADC; /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
    volatile u32 DCGCACMP; /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
    volatile u32 DCGCPWM; /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
    volatile u32 DCGCQEI; /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
    volatile u32 RESERVED39[4];
    volatile u32 DCGCEEPROM; /*!< EEPROM Deep-Sleep Mode Clock Gating Control                           */
    volatile u32 DCGCWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
     Control                                                               */
    volatile u32 RESERVED40[104];
    volatile u32 PRWD; /*!< Watchdog Timer Peripheral Ready                                       */
    volatile u32 PRTIMER; /*!< 16/32-Bit General-Purpose Timer Peripheral Ready                      */
    volatile u32 PRGPIO; /*!< General-Purpose Input/Output Peripheral Ready                         */
    volatile u32 PRDMA; /*!< Micro Direct Memory Access Peripheral Ready                           */
    volatile u32 RESERVED41;
    volatile u32 PRHIB; /*!< Hibernation Peripheral Ready                                          */
    volatile u32 PRUART; /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
    volatile u32 PRSSI; /*!< Synchronous Serial Interface Peripheral Ready                         */
    volatile u32 PRI2C; /*!< Inter-Integrated Circuit Peripheral Ready                             */
    volatile u32 RESERVED42;
    volatile u32 PRUSB; /*!< Universal Serial Bus Peripheral Ready                                 */
    volatile u32 RESERVED43[2];
    volatile u32 PRCAN; /*!< Controller Area Network Peripheral Ready                              */
    volatile u32 PRADC; /*!< Analog-to-Digital Converter Peripheral Ready                          */
    volatile u32 PRACMP; /*!< Analog Comparator Peripheral Ready                                    */
    volatile u32 PRPWM; /*!< Pulse Width Modulator Peripheral Ready                                */
    volatile u32 PRQEI; /*!< Quadrature Encoder Interface Peripheral Ready                         */
    volatile u32 RESERVED44[4];
    volatile u32 PREEPROM; /*!< EEPROM Peripheral Ready                                               */
    volatile u32 PRWTIMER; /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Ready                 */
} SYSCRL_RegDef_t;

#define SYSCTL                          ((SYSCRL_RegDef_t*) SYSCTL_BASE_ADDRESS)

/********************************GP TIMERS REGS************************************/

typedef struct
{
    u32 CFG;
    u32 TAMR;
    u32 TBMR;
    u32 CTL;
    u32 SYNC;
    u32 RESERVED;
    u32 IMR;
    u32 RIS;
    u32 MIS;
    u32 ICR;
    u32 TAILR;
    u32 TBILR;
    u32 TAMATCHR;
    u32 TBMATCHR;
    u32 TAPR;
    u32 TBPR;
    u32 TAPMR;
    u32 TBPMR;
    u32 TAR;
    u32 TBR;
    u32 TAV;
    u32 TBV;
    u32 RTCPD;
    u32 TAPS;
    u32 TBPS;
    u32 TAPV;
    u32 TBPV;
    u32 reserved[981];
    u32 PP;
}GPTM_RegDef_t;

#define TIMER0      ((GPTM_RegDef_t *)TIMER0_BASE_ADDRESS)
#define TIMER1      ((GPTM_RegDef_t *)TIMER1_BASE_ADDRESS)
#define TIMER2      ((GPTM_RegDef_t *)TIMER2_BASE_ADDRESS)
#define TIMER3      ((GPTM_RegDef_t *)TIMER3_BASE_ADDRESS)
#define TIMER4      ((GPTM_RegDef_t *)TIMER4_BASE_ADDRESS)
#define TIMER5      ((GPTM_RegDef_t *)TIMER5_BASE_ADDRESS)
#define W_TIMER0    ((GPTM_RegDef_t *)W_TIMER0_BASE_ADDRESS)
#define W_TIMER1    ((GPTM_RegDef_t *)W_TIMER1_BASE_ADDRESS)
#define W_TIMER2    ((GPTM_RegDef_t *)W_TIMER2_BASE_ADDRESS)
#define W_TIMER3    ((GPTM_RegDef_t *)W_TIMER3_BASE_ADDRESS)
#define W_TIMER4    ((GPTM_RegDef_t *)W_TIMER4_BASE_ADDRESS)
#define W_TIMER5    ((GPTM_RegDef_t *)W_TIMER5_BASE_ADDRESS)

#endif /* TM4C123XX_REG_H_ */
