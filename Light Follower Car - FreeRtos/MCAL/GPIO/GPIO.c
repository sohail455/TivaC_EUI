/******************************************************************************/
/*                                                                            */
/* !Layer           : Micro-controller Abstraction Layer (MCAL)               */
/*                                                                            */
/* !Module          : GPIO                                                    */
/* !Description     : to Drive GPIO Pins                                      */
/*                                                                            */
/* !File            : GPIO.c                                                  */
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
/* !Designed by     : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/* !Coded by        : AHMED ABDULAZEEM                 !Date : SEP 11, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 11, 2023     Initial release                                */
/******************************************************************************/

/******************************************************************************/
/******************************* Includes *************************************/
/******************************************************************************/
#include "GPIO.h"
/******************************************************************************/

/******************************************************************************/
/*! \Description : Initialize GPIO PORT                                       */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select Port Id                              */
/******************************************************************************/
void GPIO_vidInitPort(uint8_t Copy_u8PortId)
{
    if((GPIO_PORTA <= Copy_u8PortId) && (Copy_u8PortId<= GPIO_PORTF))
    {
        SET_BIT(SYSCTL_RCGCGPIO_R, Copy_u8PortId);
        while(GET_BIT(SYSCTL_PRGPIO_R,Copy_u8PortId) == 0){};

        /*If Port is -> C D F -> Unlock*/
        switch(Copy_u8PortId)
        {
        case GPIO_PORTC :
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            GPIO_PORTC_CR_R   = 0x1F;
            break;

        case GPIO_PORTD :
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            GPIO_PORTD_CR_R   = 0xFF;
            break;

        case GPIO_PORTF :
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R   = 0x1F;
            break;

        default:
            /*do Nothing*/
            break;
        }

    }
    else
    {
    }
}

/******************************************************************************/
/*! \Description : Set Specific Pin as an output                              */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidOutputPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum)
{
	/*Switch Port Id*/
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        SET_BIT(GPIO_PORTA_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTA_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTB :
        SET_BIT(GPIO_PORTB_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTB_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTC :
        SET_BIT(GPIO_PORTC_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTC_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTD :
        SET_BIT(GPIO_PORTD_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTD_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTE :
        SET_BIT(GPIO_PORTE_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTE_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTF :
        SET_BIT(GPIO_PORTF_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Output*/
        SET_BIT(GPIO_PORTF_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;


    default:
        /*Do Nothing*/
        break;
    }

}

/******************************************************************************/
/*! \Description : Set Pin Value                                              */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/*!              Copy_u8PinVal value to be set                                */
/******************************************************************************/
void GPIO_vidWritePin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum,uint8_t Copy_u8PinVal)
{
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        WRITE_BIT(GPIO_PORTA_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    case GPIO_PORTB :
        WRITE_BIT(GPIO_PORTB_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    case GPIO_PORTC :
        WRITE_BIT(GPIO_PORTC_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    case GPIO_PORTD :
        WRITE_BIT(GPIO_PORTD_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    case GPIO_PORTE :
        WRITE_BIT(GPIO_PORTE_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    case GPIO_PORTF :
        WRITE_BIT(GPIO_PORTF_DATA_R,Copy_u8PinNum,Copy_u8PinVal); /*Write Specified Pin value*/
        break;

    default:
        /*Do Nothing*/
        break;
    }

}

/******************************************************************************/
/*! \Description : Read Specific Pin Value                                    */
/*! \return      Pin value                                                    */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
uint8_t GPIO_u8ReadPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum)
{
    uint8_t Loc_u8Val =0;
	
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        Loc_u8Val = GET_BIT(GPIO_PORTA_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    case GPIO_PORTB :
        Loc_u8Val = GET_BIT(GPIO_PORTB_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    case GPIO_PORTC :
        Loc_u8Val = GET_BIT(GPIO_PORTC_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    case GPIO_PORTD :
        Loc_u8Val = GET_BIT(GPIO_PORTD_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    case GPIO_PORTE :
        Loc_u8Val = GET_BIT(GPIO_PORTE_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    case GPIO_PORTF :
        Loc_u8Val = GET_BIT(GPIO_PORTF_DATA_R,Copy_u8PinNum); /*Read Specified Pin value*/
        break;

    default:
        /*Do Nothing*/
        break;
    }

    return Loc_u8Val;
}

/******************************************************************************/
/*! \Description : Set pull up to a specified Pin                             */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidInputPinPullUp(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum)
{
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        SET_BIT(GPIO_PORTA_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/
        break;

    case GPIO_PORTB :
        SET_BIT(GPIO_PORTB_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/
        break;

    case GPIO_PORTC :
        SET_BIT(GPIO_PORTC_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/

        break;

    case GPIO_PORTD :
        SET_BIT(GPIO_PORTD_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/
        break;

    case GPIO_PORTE :
        SET_BIT(GPIO_PORTE_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/
        break;

    case GPIO_PORTF :
        SET_BIT(GPIO_PORTF_PUR_R,Copy_u8PinNum); /*Set Specified Pin as PullUp*/
        break;

    default:
        /*Do Nothing*/
        break;
    }

}

/******************************************************************************/
/*! \Description : Set a specific Pin as an input                             */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidInputPin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum)
{
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        CLR_BIT(GPIO_PORTA_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTA_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTB :
        CLR_BIT(GPIO_PORTB_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTB_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTC :
        CLR_BIT(GPIO_PORTC_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTC_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTD :
        CLR_BIT(GPIO_PORTD_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTD_PDR_R,Copy_u8PinNum);
        SET_BIT(GPIO_PORTD_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTE :
        CLR_BIT(GPIO_PORTE_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTE_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    case GPIO_PORTF :
        CLR_BIT(GPIO_PORTF_DIR_R,Copy_u8PinNum); /*Set Pin Direction as Input*/
        SET_BIT(GPIO_PORTF_DEN_R,Copy_u8PinNum); /*Set Pin as Digital*/
        break;

    default:
        /*Do Nothing*/
        break;
    }

}

/******************************************************************************/
/*! \Description : Toggle a specific Pin Value                                */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/******************************************************************************/
void GPIO_vidTogglePin(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum)
{
    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        TOGGLE_BIT(GPIO_PORTA_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    case GPIO_PORTB :
        TOGGLE_BIT(GPIO_PORTB_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    case GPIO_PORTC :
        TOGGLE_BIT(GPIO_PORTC_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    case GPIO_PORTD :
        TOGGLE_BIT(GPIO_PORTD_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    case GPIO_PORTE :
        TOGGLE_BIT(GPIO_PORTE_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    case GPIO_PORTF :
        TOGGLE_BIT(GPIO_PORTF_DATA_R,Copy_u8PinNum); /*Toggle specified Pin value*/
        break;

    default:
        /*Do Nothing*/
        break;
    }
}

/******************************************************************************/
/*! \Description : Set alternative function to a specific pin                 */
/*! \return      None                                                         */
/*! \arguments   Copy_u8PortId to select specific Port Id                     */
/*!              Copy_u8PinNum to select specific Pin Number                  */
/*!              Copy_u8AltFun alternative function to be set                 */
/******************************************************************************/
void GPIO_vidSetAltFunc(uint8_t Copy_u8PortId,uint8_t Copy_u8PinNum, uint8_t Copy_u8AltFun)
{
    switch(Copy_u8PortId)
        {
        case GPIO_PORTA :
            SET_BIT(GPIO_PORTA_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTA_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        case GPIO_PORTB :
            SET_BIT(GPIO_PORTB_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTB_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        case GPIO_PORTC :
            SET_BIT(GPIO_PORTC_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTC_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        case GPIO_PORTD :
            SET_BIT(GPIO_PORTD_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTD_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        case GPIO_PORTE :
            SET_BIT(GPIO_PORTE_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTE_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        case GPIO_PORTF :
            SET_BIT(GPIO_PORTF_AFSEL_R,Copy_u8PinNum);						    /*Set Pin to Alternative function*/
            INSERT_VALUE(GPIO_PORTF_PCTL_R,Copy_u8PinNum*4,4,Copy_u8AltFun);	/*Set Pin to a Specific Alternative function*/
            break;

        default:
            /*Do Nothing*/
            break;
        }
		
}

uint32_t GPIO_u8ReadPort(uint8_t Copy_u8PortId)
{
    uint32_t Loc_u8Val =0;

    switch(Copy_u8PortId)
    {
    case GPIO_PORTA :
        Loc_u8Val = GPIO_PORTA_DATA_R; /*Read Specified Pin value*/
        break;

    case GPIO_PORTB :
        Loc_u8Val = GPIO_PORTB_DATA_R; /*Read Specified Pin value*/
        break;

    case GPIO_PORTC :
        Loc_u8Val = GPIO_PORTC_DATA_R; /*Read Specified Pin value*/
        break;

    case GPIO_PORTD :
        Loc_u8Val = GPIO_PORTD_DATA_R; /*Read Specified Pin value*/
        break;

    case GPIO_PORTE :
        Loc_u8Val = GPIO_PORTE_DATA_R; /*Read Specified Pin value*/
        break;

    case GPIO_PORTF :
        Loc_u8Val = GPIO_PORTF_DATA_R; /*Read Specified Pin value*/
        break;

    default:
        /*Do Nothing*/
        break;
    }

    return Loc_u8Val;
}
