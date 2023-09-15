/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      GPTM.c
 * File Name:   GPTM
 * Layer:       MCAL
 * Description: Source file for General purpose Timers module for Tiva C.
 ****************************************************************************/
/***************************************************************************
 *                             INCLUSION
 ***************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Register_Map.h"
#include "Timer.h"

void (*TimersHandler_ptr[24])(void);

/***************************************************************************
 *                             Master Array
 ***************************************************************************/
Timer_RegDef_t *Timers_Arr[] = { TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5,
                                 W_TIMER0, W_TIMER1, W_TIMER2, W_TIMER3,
                                 W_TIMER4, W_TIMER5 };
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
void TimerInit(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,
               TIMERS_Config_t config, TIMERS_Mode_t mode)
{
    NVIC->EN3 |= 1 << (2); /*set NVIC for WIDE TIMER2A*/

    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        if (block <= TIMER5_BLOCK)/*Enable The Corresponding Timer Block Clock*/
            SYSCTL->RCGCTIMER |= (1 << block);
        else
            SYSCTL->RCGCWTIMER |= (1 << (block - W_TIMER0_BLOCK));

        Timers_Arr[block]->CTL &= ~((1 << 0) | (1 << 8));/*Disable the Timer at the beginning*/
        Timers_Arr[block]->CFG = config;/*Select The Timer Configuration*/
        if ((sub_block == TIMER_A) || (config == TIMER_CONCATUNATED_CFG))/*Check if it is Timer A or Concatenated*/
        {
            if (mode == CAPTURE_EDGE_TIME_F)/*Check if it Capture mode with falling edge detection*/
            {
                Timers_Arr[block]->TAMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (1 << 2);
            }
            else if (mode == CAPTURE_EDGE_TIME_R)/*Check if it Capture mode with rising edge detection*/
            {
                Timers_Arr[block]->TAMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (0 << 2);
            }
            else if (mode == CAPTURE_EDGE_TIME_B)/*Check if it Capture mode with both edge detection*/
            {
                Timers_Arr[block]->TAMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (3 << 2);
            }
            else/*Check if it another mode*/
            {
                Timers_Arr[block]->TAMR = mode;
            }
        }
        else/*Check if it is Timer B*/
        {
            if (mode == CAPTURE_EDGE_TIME_F)/*Check if it Capture mode with falling edge detection*/
            {
                Timers_Arr[block]->TBMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (1 << 10);
            }
            else if (mode == CAPTURE_EDGE_TIME_R)/*Check if it Capture mode with rising edge detection*/
            {
                Timers_Arr[block]->TBMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (0 << 10);
            }
            else if (mode == CAPTURE_EDGE_TIME_B)/*Check if it Capture mode with both edge detection*/
            {
                Timers_Arr[block]->TBMR = CAPTURE_EDGE_TIME;
                Timers_Arr[block]->CTL |= (3 << 10);
            }
            else/*Check if it another mode*/
            {
                Timers_Arr[block]->TBMR = mode;
            }
        }
    }
}
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
void TimerSetValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,
                   u32 value)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                || (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            Timers_Arr[block]->TAILR = value;/*Set The Value in to Inerval Load Register*/
        }
        else/*Check if it is Timer B*/
        {
            Timers_Arr[block]->TBILR = value;/*Set The Value in to Inerval Load Register*/
        }
    }
}
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
void TimerEnable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                || (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            Timers_Arr[block]->CTL |= (1 << 0);/*Enable Timer A or Concatenated Timer*/
        }
        else/*Check if it is Timer B*/
        {
            Timers_Arr[block]->CTL |= (1 << 8);/*Enable Timer B*/
        }
    }
}
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
void TimerSetMatch(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,
                   u32 value)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                || (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            Timers_Arr[block]->TAMATCHR = value;/*Set Match Value for Timer A*/
        }
        else/*Check if it is Timer B*/
        {
            Timers_Arr[block]->TBMATCHR = value;/*Set Match Value for Timer B*/
        }
    }
}
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
u32 TimerReadValue(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
{
    u32 timer_value = 0;
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                || (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            timer_value = Timers_Arr[block]->TAR;/*Read the Value of Timer A Register*/
        }
        else/*Check if it is Timer B*/
        {
            timer_value = Timers_Arr[block]->TBR;/*Read the Value of Timer B Register*/
        }
    }
    return timer_value;
}
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
u8 TimerReadFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,
                 TIMERS_flag_t flag)
{
    u8 flag_read = 0;
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                || (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            if (flag == FLAG_CAPTURE_EDGE_TIME_A)/*Check The Desired Flag to be read*/
            {
                flag_read = ((Timers_Arr[block]->RIS) & flag) >> 2;
            }
            else if (flag == FLAG_TIME_OUT_A)
            {
                flag_read = ((Timers_Arr[block]->RIS) & flag);
            }
        }
        else/*Check if it is Timer B*/
        {
            if (flag == FLAG_CAPTURE_EDGE_TIME_B)/*Check The Desired Flag to be read*/
            {
                flag_read = ((Timers_Arr[block]->RIS) & flag) >> 10;
            }
            else if (flag == FLAG_TIME_OUT_B)
            {
                flag_read = ((Timers_Arr[block]->RIS) & flag) >> 8;
            }
        }
    }
    return flag_read;
}
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
void TimerClearFlag(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block,
                    TIMERS_flag_t flag)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A) || (Timers_Arr[block]->CFG == 0))
        {
            if (flag == FLAG_CAPTURE_EDGE_TIME_A)/*Check The Desired Flag to be Cleared*/
            {
                Timers_Arr[block]->ICR |= (1 << 2);
            }
            else if (flag == FLAG_TIME_OUT_A)
            {
                Timers_Arr[block]->ICR |= (1 << 0);
            }
            else
            {
                /*Do Nothing*/
            }
        }
        else/*Check if it is Timer B*/
        {
            if (flag == FLAG_CAPTURE_EDGE_TIME_B)/*Check The Desired Flag to be Cleared*/
            {
                Timers_Arr[block]->ICR |= (1 << 10);
            }
            else if (flag == FLAG_TIME_OUT_B)
            {

                Timers_Arr[block]->ICR |= 0x00000100;
            }
            else
            {
                /*Do Nothing*/
            }
        }
    }
}
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
void TimerSetEdgeDetectionType(TIMERS_Block_t block,
                               TIMERS_Sub_Block_t sub_block, TIMERS_edge_t edge)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        if ((sub_block == TIMER_A))/*Check if it is Timer A*/
        {
            Timers_Arr[block]->CTL = ((Timers_Arr[block]->CTL) & 0xFFFFFFF3)
                    | (edge << 2);
        }
        else if ((sub_block == TIMER_B))/*Check if it is Timer B*/
        {
            Timers_Arr[block]->CTL = ((Timers_Arr[block]->CTL) & 0xFFFFF3FF)
                    | (edge << 2);
        }
        else
        {
            /*Do Nothing*/
        }
    }
}
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
void TimerDisable(TIMERS_Block_t block, TIMERS_Sub_Block_t sub_block)
{
    if (block >= NUM_OF_TIMERS)/*Check the range*/
    {
        /*Do Nothing*/
    }
    else
    {
        /*Check if it is Timer A or Concatenated*/
        if ((sub_block == TIMER_A)
                | (Timers_Arr[block]->CFG == TIMER_CONCATUNATED_CFG))
        {
            Timers_Arr[block]->CTL &= ~(1 << 0);
        }
        else if ((sub_block == TIMER_B))/*Check if it is Timer B*/
        {
            Timers_Arr[block]->CTL &= ~(1 << 8);
        }
        else
        {
            /*Do Nothing*/
        }
    }
}

void TimerIntDisable(TIMERS_Block_t timerBlock, u32 IntFlags)
{
    Timers_Arr[timerBlock]->IMR &= ~IntFlags;
}

void TimerIntEnable(TIMERS_Block_t timerBlock, u32 IntFlags)
{
    Timers_Arr[timerBlock]->IMR |= IntFlags;
}

void TimerSetCallBack(TIMERS_Block_t timerBlock, TIMERS_Sub_Block_t subTimer,
                      void (*pfnHandler)(void))
{

    if (timerBlock <= W_TIMER5_BLOCK)
    {
        if (subTimer == TIMER_A || Timers_Arr[timerBlock]->CFG == 0)
        {
            TimersHandler_ptr[timerBlock] = pfnHandler;
        }
        else
        {
            TimersHandler_ptr[timerBlock + 12] = pfnHandler;
        }
    }
}

//*****************************************************************************
//
// Timers Interrupt Handler Functions
//
//*****************************************************************************

void Timer0A_Handler(void)
{
    if (TimersHandler_ptr[0] != NULLPTR)
    {
        TimersHandler_ptr[0]();
    }
}

void Timer1A_Handler(void)
{
    if (TimersHandler_ptr[1] != NULLPTR)
    {
        TimersHandler_ptr[1]();
    }
}

void Timer2A_Handler(void)
{
    if (TimersHandler_ptr[2] != NULLPTR)
    {
        TimersHandler_ptr[2]();
    }
}

void Timer3A_Handler(void)
{
    if (TimersHandler_ptr[3] != NULLPTR)
    {
        TimersHandler_ptr[3]();
    }
}

void Timer4A_Handler(void)
{
    if (TimersHandler_ptr[4] != NULLPTR)
    {
        TimersHandler_ptr[4]();
    }
}

void Timer5A_Handler(void)
{
    if (TimersHandler_ptr[5] != NULLPTR)
    {
        TimersHandler_ptr[5]();
    }
}

void Timer0AW_Handler(void)
{
    TimersHandler_ptr[6]();
}

void Timer1AW_Handler(void)
{
    TimersHandler_ptr[7]();
}

void Timer2AW_Handler(void)
{
    TimersHandler_ptr[8]();
}

void Timer3AW_Handler(void)
{
    TimersHandler_ptr[9]();
}

void Timer4AW_Handler(void)
{
    TimersHandler_ptr[10]();
}

void Timer5AW_Handler(void)
{
    TimersHandler_ptr[11]();
}

void Timer0B_Handler(void)
{
    TimersHandler_ptr[12]();
}

void Timer1B_Handler(void)
{
    TimersHandler_ptr[13]();
}

void Timer2B_Handler(void)
{
    TimersHandler_ptr[14]();
}

void Timer3B_Handler(void)
{
    TimersHandler_ptr[15]();
}

void Timer4B_Handler(void)
{
    TimersHandler_ptr[16]();
}

void Timer5B_Handler(void)
{
    TimersHandler_ptr[17]();
}

void Timer0BW_Handler(void)
{
    TimersHandler_ptr[18]();
}

void Timer1BW_Handler(void)
{
    TimersHandler_ptr[19]();
}

void Timer2BW_Handler(void)
{
    TimersHandler_ptr[20]();
}

void Timer3BW_Handler(void)
{
    TimersHandler_ptr[21]();
}

void Timer4BW_Handler(void)
{
    TimersHandler_ptr[22]();
}

void Timer5BW_Handler(void)
{
    TimersHandler_ptr[23]();
}
