/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:   David & Sohail & Hossam
 *	   	   File:  STD_TYPES.h
 *		  Layer:  LIB
 *       Module:  STD_TYPES
 *		Version:  1.00
 *	
 *  Description:  Standard types definitions      
 *  
 *********************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define NULL			0

#define ENABLE 1
#define DISABLE 0

#define SET 1
#define RESET 0

#define ON 1
#define OFF 0

#define HIGH 1
#define LOW 0

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	IDLE=0,
	BUSY
}Peripheral_State;

typedef enum
{
	SEND_CHAR=0,
	SEND_STRING,
	SEND_BUFFER,
	RECEIVE_CHAR,
	RECEIVE_BUFFER,
	SINGLE_CONVERSION=0,
	CHAIN_CONVERSION
}ISR_Src;

typedef enum
{
	FALSE=0,
	TRUE
}bool;

typedef enum
{
	E_OK=0,
	E_NOK,
	E_NULL_POINTER,
	E_WRONG_OPTION,
    E_BUSY,
	E_BUSY_FUNC,
	E_TIME_OUT,
	E_NO_RESPOSE,
	E_CONNECTION_FAILED,
}ErrorState_t;

typedef enum
{
	LOCKED=0,
	UNLOCKED
} Lock_t;

#endif /* STD_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: STD_TYPES.h
 *********************************************************************************************************************/
