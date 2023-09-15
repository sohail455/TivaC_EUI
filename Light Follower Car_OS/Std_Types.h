/*************************************************************************
 * Author: Sohail.
 * FILE:   Std_Types.h.
 * Module: Std_Types.
 * version: 1.00.
 * Description: Standard Types File.
 *************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

//#define NULL (void*)0
#define NULLPTR         (void*)0


#define ON     1
#define OFF    0

#define HIGH    1
#define LOW     0


#define SET     1
#define RESET   0

typedef enum
{
    E_OK=0,
    E_NOK,
    E_NULL_POINTER,
    E_WRONG_OPTION
}ErrorState_t;




#endif /* STD_TYPES_H_ */
