#include "Platform_Types.h"
#include "Std_Types.h"
#include "MEM_MAP.h"
#include "Timer.h"

static TIMER_RegDef_t *timersArr[] = { TIMER0, TIMER1, TIMER2,TIMER3, TIMER4, TIMER5,TIMER0_W, TIMER1_W, TIMER2_W, TIMER3_W,TIMER4_W,TIMER5_W };

void (*TimersHandler_ptr[24])(void);

/*this function choose configuration and timer mode */
void TimerInit(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, TIMER_CONFIG_t config, TIMER_MODES_t mode)
{
    if (timerBlock <= TIMERBLOCK5_W)
    {

        if(timerBlock <= TIMERBLOCK5)
            SYSCTL->RCGCTIMER |= (1 << timerBlock); //enable timer1
        else if(timerBlock > TIMERBLOCK5 && timerBlock <= TIMERBLOCK5_W)
            SYSCTL->RCGCWTIMER |= (1 << (timerBlock-6));
        //        SYSCTL->RCGCWTIMER,
        timersArr[timerBlock]->CTL &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);
        timersArr[timerBlock]->CFG = config;

        if (subTimer == TIMERA || config == 0)
        {
            if(mode == TIMER_MODE_EDGE_TIME_F)
            {
                timersArr[timerBlock]->TAMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(1<<2);
            }
            else if(mode == TIMER_MODE_EDGE_TIME_R)
            {
                timersArr[timerBlock]->TAMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(0<<2);
            }
            else if(mode == TIMER_MODE_EDGE_TIME_B)
            {
                timersArr[timerBlock]->TAMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(3<<2);
            }
            else
            {
                timersArr[timerBlock]->TAMR = mode;
            }


        }
        else
        {
            if(mode == TIMER_MODE_EDGE_TIME_F)
            {
                timersArr[timerBlock]->TBMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(1<<10);
            }
            else if(mode == TIMER_MODE_EDGE_TIME_R)
            {
                timersArr[timerBlock]->TBMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(0<<10);
            }
            else if(mode == TIMER_MODE_EDGE_TIME_B)
            {
                timersArr[timerBlock]->TBMR=TIMER_MODE_EDGE_TIME;
                timersArr[timerBlock]->CTL |=(3<<10);
            }
            else
            {
                timersArr[timerBlock]->TAMR = mode;
            }
        }

    }
}

void TimerLoadSet(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, u32 value)
{
    if (timerBlock <= TIMERBLOCK5_W)
    {
        if (subTimer == TIMERA || timersArr[timerBlock]->CFG == 0)
        {
            timersArr[timerBlock]->TAILR = value;
        }
        else
        {
            timersArr[timerBlock]->TBILR = value;
        }
    }
}

void TimerMatchSet(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer, u32 value)
{
    if (timerBlock <= TIMERBLOCK5_W)
    {
        if (subTimer == TIMERA || timersArr[timerBlock]->CFG == 0)
        {
            timersArr[timerBlock]->TAMATCHR = value;
        }
        else
        {
            timersArr[timerBlock]->TBMATCHR = value;
        }
    }
}

void TimerIntClear(TIMER_BLOCK_t timerBlock, u32 ui32IntFlags)
{
    if (timerBlock <= TIMERBLOCK5_W)
    {

        timersArr[timerBlock]->ICR = TIMER_TIMA_TIMEOUT;
    }
}

void TimerEnable(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer)
{

    if (timerBlock <= TIMERBLOCK5_W || timersArr[timerBlock]->CFG == 0)
    {
        if (subTimer == TIMERA)
        {
            timersArr[timerBlock]->CTL |= TIMER_CTL_TAEN;
        }
        else
        {
            timersArr[timerBlock]->CTL |= TIMER_CTL_TBEN;

        }
    }
}

void TimerDisable(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer)
{
    if (timerBlock <= TIMERBLOCK5_W)
    {
        if (subTimer == TIMERA || timersArr[timerBlock]->CFG == 0)
        {
            timersArr[timerBlock]->CTL &= ~TIMER_CTL_TAEN;
        }
        else
        {
            timersArr[timerBlock]->CTL &= ~TIMER_CTL_TBEN;
        }
    }
}

void TimerIntDisable(TIMER_BLOCK_t timerBlock, u32 IntFlags)
{
    timersArr[timerBlock]->IMR &= ~IntFlags;
}

void TimerIntEnable(TIMER_BLOCK_t timerBlock, u32 IntFlags)
{
    timersArr[timerBlock]->IMR |= IntFlags;
}

void TimerSetCallBack(TIMER_BLOCK_t timerBlock, SUBTIMER_t subTimer,
                      void (*pfnHandler)(void))
{

    if (timerBlock <= TIMERBLOCK5_W)
    {
        if (subTimer == TIMERA || timersArr[timerBlock]->CFG == 0)
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
