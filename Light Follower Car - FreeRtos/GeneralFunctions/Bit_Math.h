/******************************************************************************/
/*                                                                            */
/* !Layer           : General Functions (Service Folder)                      */
/*                                                                            */
/* !Module          : Bit_Math                                                */
/* !Description     : Macros for needed operations                            */
/*                                                                            */
/* !File            : Bit_Math.h                                              */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Robot Car Project @EME - EUI                            */
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
/* !Designed by     : Mazen TAMER                      !Date : SEP 09, 2023   */
/* !Coded by        : Mazen TAMER                      !Date : SEP 09, 2023   */
/*                                                                            */
/* Ver 1.0    SEP 13, 2023     Initial release                                */
/******************************************************************************/

#ifndef GENERALFUNCTIONS_BIT_MATH_H_
#define GENERALFUNCTIONS_BIT_MATH_H_

/******************************************************************************/
/******************************** Macros **************************************/
/******************************************************************************/

#define SET_BIT(Var,BitNo)                      ((Var)|=(1<<(BitNo)))
#define CLR_BIT(Var,BitNo)                      ((Var)&=(~(1<<(BitNo))))
#define TOGGLE_BIT(Var,BitNo)                   ((Var)^=(1<<BitNo))
#define GET_BIT(Var,BitNo)                      (((Var)>>(BitNo))&1)
#define INSERT_BIT(REG,BIT_NO,VALUE)            ((REG) =((REG)&(~(1<<(BIT_NO)))|((VALUE)<<(BIT_NO))))
#define INSERT_VALUE(REG,Offset,count,VALUE)    ((REG) =(((REG)&(~(((1<<(count))-1)<<(Offset)))))|((VALUE)<<(Offset)))
#define WRITE_BIT(num,BitNo,Val)                (num)=(((num)&~(1<<(BitNo))) | ((Val)<<(BitNo)))

#endif /* GENERALFUNCTIONS_BIT_MATH_H_ */
