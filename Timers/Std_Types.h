/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  -
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
#define NULLPTR         (void*)0

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


typedef enum {
    POSITIVE,
    NEGATIVE
}Sign_type;


typedef enum{
    STACK_FULL,
    STACK_EMPTY,
    STACK_DONE,
}stackStatus_t;

#define MAX_U8  ((u8)255)
#define MIN_U8  ((u8)0)
#define MAX_S8  ((s8)127)
#define MIN_S8  ((s8)-128)
#define ZERO_S8 ((s8)0)
#define MAX_S16 ((s16)32767)
#define MIN_S16 ((s16)-32768)
#define ZERO_S16 ((s16)0)
#define MAX_S32 ((s32)2147483647)
#define MIN_S32 ((s32)-2147483648)
#define ZERO_S32 ((s32)0)

#endif /* STD_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: STD_TYPES.h
 *********************************************************************************************************************/
