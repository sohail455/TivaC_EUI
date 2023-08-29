/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  TM4C123xx.h
 *		  Layer:  LIB
 *       Module:  TM4C123xx
 *		Version:  1.00
 *	
 *  Description:  Register Defination       
 *  
 *********************************************************************************************************************/
 #ifndef TM4C123XX_H
 #define TM4C123XX_H
 
/******************************************** SC Peripheral Definition  **********************************************/

#define SYSCTL_BASE_ADDRESS                         0x400FE000UL

#define SYSCTL_GPIOHBCTL                            *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x06c))

#define SYSCTL_RCGCGPIO                             *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x608))

#define SYSCTL_RCGCWD                               *((volatile u32*)(SYSCTL_BASE_ADDRESS+0x600))

/******************************************** SYSCTL Registers Definition    *********************************************/
typedef struct
{
    volatile u32 DID0;
    volatile u32 DID1;
    u32 Reserved[11];
    volatile u32 PBORCTL;
    u32 Reserved2[8];
    volatile u32 RIS;
    volatile u32 IMC;
    volatile u32 MISC;
    volatile u32 RESC;
    volatile u32 RCC;
    u32 Reserved3[3];
    volatile u32 GPIOHBCTL;
    volatile u32 RCC2;
    u32 Reserved4[3];
    volatile u32 MOSCCTL;
    u32 Reserved5[50];
    volatile u32 DSLPCLKCFG;
    u32 Reserved6[2];
    volatile u32 SYSPROP;
    volatile u32 PIOSCCAL;
    volatile u32 PIOSCSTAT;
    u32 Reserved7[3];
    volatile u32 PLLFREQ0;
    volatile u32 PLLFREQ1;
    volatile u32 PLLSTAT;
    u32 Reserved8[8];
    volatile u32 SLPPWRCFG;
    volatile u32 NDSLPPWRCFG;
}SYSCRL_RegDef_t;
/******************************************** GPIO Peripheral Definition *********************************************/

#define GPIOA_BASE_ADDRESS					0x40004000UL
#define GPIOB_BASE_ADDRESS					0x40005000UL
#define GPIOC_BASE_ADDRESS					0x40006000UL
#define GPIOD_BASE_ADDRESS					0x40007000UL
#define GPIOE_BASE_ADDRESS					0x40024000UL
#define GPIOF_BASE_ADDRESS					0x40025000UL


/******************************************** GPIO Registers Definition **********************************************/

typedef struct
{
	volatile u32 DATA[256];           /*GPIO Data*/
	volatile u32 DIR;                 /*GPIO Direction*/
	volatile u32 IS;                  /*GPIO Interrupt Sense*/
	volatile u32 IBE;                 /*GPIO Interrupt Both Edges*/
	volatile u32 IEV;                 /*GPIO Interrupt Event*/
	volatile u32 IM;                  /*GPIO Interrupt Mask*/
	volatile u32 RIS;                 /*GPIO Raw Interrupt Status*/
	volatile u32 MIS;                 /*GPIO Masked Interrupt Status*/
	volatile u32 ICR;                 /*GPIO GPIO Interrupt Clear*/
	volatile u32 AFSEL;               /*GPIO Alternate Function Select*/
	u32 Reserved[55];
	volatile u32 DRxR[3];                /*GPIO x-mA Drive Select*/
	volatile u32 ODR;                 /*GPIO Open Drain Select*/
	volatile u32 PxR[2];                 /*GPIO Pull-Up-Down Select*/
	volatile u32 SLR;                 /*GPIO Slew Rate Control Select*/
	volatile u32 DEN;                 /*GPIO Digital Enable*/
	volatile u32 LOCK;                /*GPIO Lock*/
	volatile u32 CR;                  /*GPIO Commit*/
	volatile u32 AMSEL;               /*GPIO Analog Mode Select*/
	volatile u32 PCTL;                /*GPIO Port Control*/
	volatile u32 ADCCTL;              /*GPIO ADC Control*/
	volatile u32 DMACTL;              /*GPIO DMA Control*/
}GPIO_RegDef_t;

#define GPIOA							((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)

/******************************************** STK Peripheral Definition *********************************************/

#define STK_BASE_ADDRESS					0xE000E010UL

/******************************************** STK Registers Definition **********************************************/

typedef struct
{
	volatile u32 CTRL;				/*SysTick Control and Status Register*/
	volatile u32 LOAD;              /*SysTick Reload Value Register*/
	volatile u32 CURRENT;           /*SysTick Current Value Register*/
}STK_RegDef_t;

#define STK                             ((STK_RegDef_t*) STK_BASE_ADDRESS)

#endif	/*TM4C123XX_H*/
/**********************************************************************************************************************
 *  END OF FILE: TM4c123xx.h
 *********************************************************************************************************************/
