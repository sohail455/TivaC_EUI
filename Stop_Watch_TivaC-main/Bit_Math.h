/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  -
 *	   	   File:  BIT_MATH.h
 *		  Layer:  LIB
 *       Module:  BIT_MATH
 *		Version:  1.00
 *	
 *  Description:  Bit manipulation Function Like Macros       
 *  
 *********************************************************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BitNo) 		(Var|=(1<<BitNo))
#define CLR_BIT(Var,BitNo) 		(Var&=(~(1<<BitNo)))
#define TOGGLE_BIT(Var,BitNo)	(Var^=(1<<BitNo))
#define GET_BIT(Var,BitNo) 		((Var>>BitNo)&1)
#define GET_VALUE(REG,Offset,count)         ((REG>>Offset)&((1<<count)-1))
#define INSERT_BIT(REG,BIT_NO,VALUE)        (REG =(REG&(~(1<<BIT_NO))|(VALUE<<BIT_NO)))
#define INSERT_VALUE(REG,Offset,count,VALUE)(REG =(REG&(~((1<<count)-1)<<Offset))|(VALUE<<Offset))

#endif
