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


#endif /* TIMER_H_ */
