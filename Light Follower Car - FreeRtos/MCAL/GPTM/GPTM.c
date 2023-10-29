/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : GPTM                                                    */
/* !Description     : Timer Module Implementation                             */
/*                                                                            */
/* !File            : GPTM.c                                                  */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous car Project @EME - EUI                       */
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
/* !Designed by     : AHMED RAGAB                      !Date : SEP 11, 2023   */
/* !Coded by        : AHMED RAGAB                      !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/

#include <GeneralFunctions/Bit_Math.h>
#include <GeneralFunctions/hw_gpio.h>
#include <GeneralFunctions/std_types.h>
#include <MCAL/GPTM/GPTM.h>

/******************************************************************************/
/*************************** Global Variables *********************************/
/******************************************************************************/

static void (*Glob_ptrFunction)(void);              /*Pointer to the CallBack Function*/
volatile uint8_t Glob_u8_toogle_bit;


/******************************************************************************/
/*! \Description : Initialize GPTM Module                                     */
/*! \return        None                                                       */
/*! \arguments     timer         to choose which timer block                  */
/******************************************************************************/

void GPTM_vidInit(timerBlock timer,timerMode mode ,countDirection direction,subtimer block,uint32_t loadregister,edge edge_state){

    switch(timer){
    case Timer0:
        switch(mode){
        case oneShot:
            switch(block){
            case timerA:
                /*initialize the clock for the peripheral*/
                SET_BIT(SYSCTL_RCGCTIMER_R,0);

                //SET_BIT(NVIC_EN0_R,19);
                /*disable the timer*/
                CLR_BIT(TIMER0_CTL_R,0);
                /*select 16 bit timer configuration*/
                TIMER0_CFG_R = 0x04;
                /*choose one shot mode */
                SET_BIT(TIMER0_TAMR_R,0);
                CLR_BIT(TIMER0_TAMR_R,1);
                /*switch between count direction*/
                switch(direction){
                case up:
                    SET_BIT(TIMER0_TAMR_R,4);
                    break;
                case down:
                    CLR_BIT(TIMER0_TAMR_R,4);
                    break;
                }
                /*load the start value */
                TIMER0_TAILR_R =loadregister;

                //SET_BIT(TIMER0_IMR_R,0);

                SET_BIT(TIMER0_CTL_R,0);
                break;

                case timerB:
                    break;
                case concatenated:
                    /*initialize the clock for the peripheral*/
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);
                    SET_BIT(NVIC_EN0_R,19);
                    /*disable the timer*/
                    CLR_BIT(TIMER0_CTL_R,0);
                    /*select 16 bit timer configuration*/
                    TIMER0_CFG_R = 0x00;
                    /*choose one shot mode */
                    SET_BIT(TIMER0_TAMR_R,0);
                    CLR_BIT(TIMER0_TAMR_R,1);
                    /*switch between count direction*/
                    switch(direction){
                    case up:
                        SET_BIT(TIMER0_TAMR_R,4);
                        break;
                    case down:
                        CLR_BIT(TIMER0_TAMR_R,4);
                        break;
                    }
                    /*load the start value */
                    TIMER0_TAILR_R =loadregister;

                    SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;
            }
            case periodic:
                switch(block){
                case timerA:
                    /*initialize the clock for the peripheral*/
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);

                    //SET_BIT(NVIC_EN0_R,19);
                    /*disable the timer*/
                    CLR_BIT(TIMER0_CTL_R,0);
                    /*select 16 bit timer configuration*/
                    TIMER0_CFG_R = 0x04;
                    /*choose  periodic mode */
                    SET_BIT(TIMER0_TAMR_R,1);
                    CLR_BIT(TIMER0_TAMR_R,0);
                    /*switch between count direction*/
                    switch(direction){
                    case up:
                        SET_BIT(TIMER0_TAMR_R,4);
                        break;
                    case down:
                        CLR_BIT(TIMER0_TAMR_R,4);
                        break;
                    }
                    /*load the start value */
                    TIMER0_TAILR_R =loadregister;

                    //SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;

                    case timerB:
                        break;
                    case concatenated:
                        /*initialize the clock for the peripheral*/
                        SET_BIT(SYSCTL_RCGCTIMER_R,0);
                        SET_BIT(NVIC_EN0_R,19);
                        /*disable the timer*/
                        CLR_BIT(TIMER0_CTL_R,0);
                        /*select 16 bit timer configuration*/
                        TIMER0_CFG_R = 0x00;
                        /*choose  periodic mode */
                        SET_BIT(TIMER0_TAMR_R,1);
                        CLR_BIT(TIMER0_TAMR_R,0);
                        /*switch between count direction*/
                        switch(direction){
                        case up:
                            SET_BIT(TIMER0_TAMR_R,4);
                            break;
                        case down:
                            CLR_BIT(TIMER0_TAMR_R,4);
                            break;
                        }
                        /*load the start value */
                        TIMER0_TAILR_R =loadregister;

                        SET_BIT(TIMER0_IMR_R,0);

                        SET_BIT(TIMER0_CTL_R,0);
                        break;
                }
                break;
                case edgeTime:
                    switch(block){
                    case timerA:
                        /*Enable Timer Clock  */
                        SET_BIT(SYSCTL_RCGCTIMER_R,0);

                        /*Enable NVIC   */
                        SET_BIT(NVIC_EN0_R,19);

                        CLR_BIT(TIMER0_CTL_R,0);

                        TIMER0_CFG_R = 0x04;

                        INSERT_VALUE(TIMER0_TAMR_R,0,4,0x7);
                        switch(direction){
                        case up:
                            SET_BIT(TIMER0_TAMR_R,4);
                            break;
                        case down:
                            CLR_BIT(TIMER0_TAMR_R,4);
                            break;
                        }

                        /*Configure Edge Falling*/

                        INSERT_VALUE(TIMER0_CTL_R,2,2,edge_state);


                        TIMER0_TAILR_R =loadregister;

                        /*ALLOW Interrupt*/
                        SET_BIT(TIMER0_IMR_R,2);

                        SET_BIT(TIMER0_CTL_R,0);
                        break;
                        case timerB:
                            break;
                    }
                    break;
        }
        break;
        case wideTimer1:
            switch(mode){
            case periodic:
                switch(block){
                case timerA:
                    /*initialize the clock for the peripheral*/
                    SET_BIT(SYSCTL_RCGCWTIMER_R,1);

                    //  SET_BIT(NVIC_EN3_R,8);
                    /*disable the timer*/
                    CLR_BIT(WTIMER1_CTL_R,0);
                    /*select 16 bit timer configuration*/
                    WTIMER1_CFG_R = 0x04;
                    /*choose  periodic mode */
                    SET_BIT(WTIMER1_TAMR_R,1);
                    CLR_BIT(WTIMER1_TAMR_R,0);
                    /*switch between count direction*/
                    switch(direction){
                    case up:
                        SET_BIT(WTIMER1_TAMR_R,4);
                        break;
                    case down:
                        CLR_BIT(WTIMER1_TAMR_R,4);
                        break;
                    }
                    /*load the start value */
                    //WTIMER1_TAILR_R = load register;

                    // SET_BIT(WTIMER1_IMR_R,0);

                    SET_BIT(WTIMER1_CTL_R,0);
                    //while(GET_BIT(WTIMER1_RIS_R,0));

                    break;
                }
                break;
            }
            break;
            case wideTimer5:
                switch(mode){
                case oneShot:
                    switch(block){
                    case timerA:
                        /*initialize the clock for the peripheral*/
                        SET_BIT(SYSCTL_RCGCWTIMER_R,5);

                        //SET_BIT(NVIC_EN3_R,8);
                        /*disable the timer*/
                        CLR_BIT(WTIMER5_CTL_R,0);
                        /*select 32 bit timer configuration*/
                        WTIMER5_CFG_R = 0x04;
                        /*choose one shot mode */
                        SET_BIT(WTIMER5_TAMR_R,0);
                        CLR_BIT(WTIMER5_TAMR_R,1);
                        /*switch between count direction*/
                        switch(direction){
                        case up:
                            SET_BIT(WTIMER5_TAMR_R,4);
                            break;
                        case down:
                            CLR_BIT(WTIMER5_TAMR_R,4);
                            break;
                        }
                        /*load the start value */
                        WTIMER5_TAILR_R =loadregister;

                        SET_BIT(WTIMER5_IMR_R,0);

                        SET_BIT(WTIMER5_CTL_R,0);
                        break;

                        case timerB:
                            break;
                        case concatenated:
                            /*initialize the clock for the peripheral*/
                            SET_BIT(SYSCTL_RCGCTIMER_R,0);
                            SET_BIT(NVIC_EN3_R,8);
                            /*disable the timer*/
                            CLR_BIT(WTIMER5_CTL_R,0);
                            /*select 16 bit timer configuration*/
                            WTIMER5_CFG_R = 0x00;
                            /*choose one shot mode */
                            SET_BIT(WTIMER5_TAMR_R,0);
                            CLR_BIT(WTIMER5_TAMR_R,1);
                            /*switch between count direction*/
                            switch(direction){
                            case up:
                                SET_BIT(WTIMER5_TAMR_R,4);
                                break;
                            case down:
                                CLR_BIT(WTIMER5_TAMR_R,4);
                                break;
                            }
                            /*load the start value */
                            WTIMER5_TAILR_R =loadregister;

                            SET_BIT(WTIMER5_IMR_R,0);

                            SET_BIT(WTIMER5_CTL_R,0);
                            break;
                    }
                    case periodic:
                        switch(block){
                        case timerA:
                            /*initialize the clock for the peripheral*/
                            SET_BIT(SYSCTL_RCGCWTIMER_R,5);

                            //SET_BIT(NVIC_EN3_R,8);
                            /*disable the timer*/
                            CLR_BIT(WTIMER5_CTL_R,0);
                            /*select 16 bit timer configuration*/
                            WTIMER5_CFG_R = 0x04;
                            /*choose  periodic mode */
                            SET_BIT(WTIMER5_TAMR_R,1);
                            CLR_BIT(WTIMER5_TAMR_R,0);
                            /*switch between count direction*/
                            switch(direction){
                            case up:
                                SET_BIT(WTIMER5_TAMR_R,4);
                                break;
                            case down:
                                CLR_BIT(WTIMER5_TAMR_R,4);
                                break;
                            }
                            /*load the start value */
                            WTIMER5_TAILR_R =loadregister;

                            //SET_BIT(WTIMER5_IMR_R,0);

                            SET_BIT(WTIMER5_CTL_R,0);
                            break;

                            case timerB:
                                break;
                            case concatenated:
                                /*initialize the clock for the peripheral*/
                                SET_BIT(SYSCTL_RCGCTIMER_R,0);
                                SET_BIT(NVIC_EN3_R,8);
                                /*disable the timer*/
                                CLR_BIT(WTIMER5_CTL_R,0);
                                /*select 16 bit timer configuration*/
                                WTIMER5_CFG_R = 0x00;
                                /*choose  periodic mode */
                                SET_BIT(WTIMER5_TAMR_R,1);
                                CLR_BIT(WTIMER5_TAMR_R,0);
                                /*switch between count direction*/
                                switch(direction){
                                case up:
                                    SET_BIT(WTIMER5_TAMR_R,4);
                                    break;
                                case down:
                                    CLR_BIT(WTIMER5_TAMR_R,4);
                                    break;
                                }
                                /*load the start value */
                                WTIMER5_TAILR_R =loadregister;

                                SET_BIT(WTIMER5_IMR_R,0);

                                SET_BIT(WTIMER5_CTL_R,0);
                                break;
                        }
                        break;
                        case edgeTime:
                            switch(block){
                            case timerA:

                                GPIO_vidInitPort(GPIO_PORTD);
                                GPIO_vidInputPin(GPIO_PORTD, PIN6);
                                GPIO_vidSetAltFunc(GPIO_PORTD, PIN6, 7);


                                /*Enable Timer Clock  */
                                SET_BIT(SYSCTL_RCGCWTIMER_R,5);

                                /*Enable NVIC   */
                                //SET_BIT(NVIC_EN3_R,8);

                                CLR_BIT(WTIMER5_CTL_R,0);

                                WTIMER5_CFG_R = 0x04;

                                INSERT_VALUE(WTIMER5_TAMR_R,0,4,0x7);
                                switch(direction){
                                case up:
                                    SET_BIT(WTIMER5_TAMR_R,4);
                                    break;
                                case down:
                                    CLR_BIT(WTIMER5_TAMR_R,4);
                                    break;
                                }

                                /*Configure Edge*/

                                INSERT_VALUE(WTIMER5_CTL_R,2,2,edge_state);


                                /* WTIMER5_TAILR_R = load register;*/
                                SET_BIT(WTIMER5_ICR_R, 2);

                                /*ALLOW Interrupt*/
                                //SET_BIT(WTIMER5_IMR_R, 2);
                                /*enable timer*/

                                SET_BIT(WTIMER5_CTL_R, 0);
                                break;
                                case timerB:
                                    break;
                            }
                            break;
                }
                break;

    }
}

/******************************************************************************/
/*! \Description : Sets the pointer to the corresponding CallBack Function    */
/*! \return        None                                                       */
/*! \arguments     Copy_ptrFunction         Pointer to CallBack Function      */
/******************************************************************************/

void GPTM_vidSetCallbackFunction(void(*Copy_ptrFunction)(void))
{
    Glob_ptrFunction = Copy_ptrFunction;
}

/******************************************************************************/
/*! \Description : Returns the current timer value                            */
/*! \return        None                                                       */
/*! \arguments     Copy_enuTimer         Timer Choice                         */
/*                 Copy_enuBlock         Subtimer Choice                      */
/******************************************************************************/

uint32_t GPTM_u32GetCurrentValue(timerBlock Copy_enuTimer, subtimer Copy_enuBlock)
{
    uint32_t Local_u32TimerValue = 0;
    switch(Copy_enuTimer)
    {
    case wideTimer5:
        if (Copy_enuBlock == timerA)
        {
            Local_u32TimerValue = WTIMER5_TAR_R;
        }
        else if (Copy_enuBlock == timerB)
        {
            Local_u32TimerValue = WTIMER5_TBR_R;
        }
        break;
    }
    return Local_u32TimerValue;
}

void TimerA0_vid_Handler(void){
    (*Glob_ptrFunction)();
    SET_BIT(TIMER0_ICR_R, 0);
}

void WTimerA5_vid_Handler(void)
{
    (*Glob_ptrFunction)();
    SET_BIT(WTIMER5_ICR_R, 2);
}


