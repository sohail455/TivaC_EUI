/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      GPTM.h
 * File Name:   GPTM
 * Layer:       MCAL
 * Description: Header file for General purpose Timers module for Tiva C.
 ****************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_
/************************************************************************
 *                            DEFINITION
 ************************************************************************/
#define NUM_OF_TIMERS   12UL
/************************************************************************
 *                            TIMERS BLOCKS
 ************************************************************************/
typedef enum
{
    TIMER0_BLOCK,
    TIMER1_BLOCK,
    TIMER2_BLOCK,
    TIMER3_BLOCK,
    TIMER4_BLOCK,
    TIMER5_BLOCK,
    W_TIMER0_BLOCK,
    W_TIMER1_BLOCK,
    W_TIMER2_BLOCK,
    W_TIMER3_BLOCK,
    W_TIMER4_BLOCK,
    W_TIMER5_BLOCK
}TIMERS_Block_t;
/************************************************************************
 *                         INDIVIDUAL TIMERS
 ************************************************************************/
typedef enum
{
    TIMER_A=0UL,
    TIMER_B
}TIMERS_Sub_Block_t;
/************************************************************************
 *                         TIMERS CONFIGURATIONS
 ************************************************************************/
typedef enum
{
    TIMER_CONCATUNATED_CFG=0UL,
    TIMER_INDVIDUAL_CFG=4UL
}TIMERS_Config_t;
/************************************************************************
 *                             TIMERS MODES
 ************************************************************************/
typedef enum
{
    ONE_SHOT_MODED=0x01UL,
    PERIODIC_MODE=0x02UL,
    ONE_SHOT_MODED_UP=0x11UL,
    PERIODIC_MODE_UP=0x12UL,
    CAPTURE_EDGE_TIME=0x17UL,
    CAPTURE_EDGE_TIME_F=0x18UL,
    CAPTURE_EDGE_TIME_R=0x19UL,
    CAPTURE_EDGE_TIME_B=0x20UL,
    PWM_MODE=0x0A
}TIMERS_Mode_t;
/************************************************************************
 *                         TIMERS FLAGS TYPES
 ************************************************************************/
typedef enum
{
    FLAG_TIME_OUT_A =0x00000001,
    FLAG_TIME_OUT_B =0x00000100,
    FLAG_CAPTURE_EDGE_TIME_B =0x00000400,
    FLAG_CAPTURE_EDGE_TIME_A =0x00000004

}TIMERS_flag_t;
/************************************************************************
 *                          EDGE SIGANLS TYPES
 ************************************************************************/
typedef enum
{
    RISING_EDGE=0x00UL,
    FALLING_EDGE=0x01UL,
    BOTH_EDGE=0x03UL
}TIMERS_edge_t;



//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable


//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_DMA          0x00002000 // TimerB DMA Complete Interrupt.
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_DMA          0x00000020 // TimerA DMA Complete Interrupt.
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

/************************************************************************
 *                         FUNCTIONS DECLARATIONS
 ************************************************************************/
/***************************************************************************************************************************
* Syntax          : void TimerInit(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_Config_t config, TIMERS_Mode_t mode)
* Description     : Initialize Timers
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B.
*                   TIMERS_Config_t:    Select whether Individual or Concatenated Timer.
*                   TIMERS_Mode_t:      Select Timer's Mode.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerInit(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_Config_t config, TIMERS_Mode_t mode);
/***************************************************************************************************************************
* Syntax          : void TimerSetValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,u32 value)
* Description     : Set value for Timers
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B.
*                   u32:                Desired Value to be set.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerSetValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,u32 value);
/***************************************************************************************************************************
* Syntax          : void TimerEnable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
* Description     : Enable Timers
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerEnable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block);
/***************************************************************************************************************************
* Syntax          : void TimerSetMatch(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,u32 value)
* Description     : Set match value for Timers.
* Sync\Async      : Synchronous.
* Reentrancy      : Non Reentrant.
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B
*                   u32:                Desired Value to be set.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerSetMatch(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,u32 value);
/***************************************************************************************************************************
* Syntax          : u32 TimerReadValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
* Description     : Read Timers Value
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B
* Parameters (out): None.
* Return value:   : u32.
***************************************************************************************************************************/
u32 TimerReadValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block);
/***************************************************************************************************************************
* Syntax          : u8 TimerReadFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_flag_t flag)
* Description     : Read Timer's Specific Flag.
* Sync\Async      : Synchronous.
* Reentrancy      : Non Reentrant.
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B
*                   TIMERS_flag_t:      Desired Flag to be read.
* Parameters (out): None.
* Return value:   : u8.
***************************************************************************************************************************/
u8 TimerReadFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_flag_t flag);
/***************************************************************************************************************************
* Syntax          : void TimerClearFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,TIMERS_flag_t flag )
* Description     : Clear Timer's Specific Flag.
* Sync\Async      : Synchronous.
* Reentrancy      : Non Reentrant.
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B
*                   TIMERS_flag_t:      Desired Flag to be Cleared.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerClearFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,TIMERS_flag_t flag );
/***************************************************************************************************************************
* Syntax          : void TimerSetEdgeDetectionType(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_edge_t edge)
* Description     : Select The Next Edge Type To be Detected in In Edge Time Mode.
* Sync\Async      : Synchronous.
* Reentrancy      : Non Reentrant.
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B
*                   TIMERS_edge_t:      Desired Edge to be Detected.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerSetEdgeDetectionType(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block, TIMERS_edge_t edge);
/***************************************************************************************************************************
* Syntax          : void TimerDisable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
* Description     : Disable Timers
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : TIMERS_Block_t:     Select Timer Block.
*                   TIMERS_Sub_Block_t: Select Timer Sub Block A or B.
* Parameters (out): None.
* Return value:   : void.
***************************************************************************************************************************/
void TimerDisable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block);


void TimerIntDisable (TIMERS_Block_t timerBlock, u32 IntFlags);

void TimerIntEnable (TIMERS_Block_t timerBlock, u32 IntFlags);

void TimerSetCallBack (TIMERS_Block_t timerBlock, TIMERS_Sub_Block_t subTimer, void (*pfnHandler)(void));

#endif /* TIMER_H_ */
