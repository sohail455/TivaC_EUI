/*************************************************************************
 * Author: Sohail.
 * FILE: Bit_Math.h.
 * Module: Bit Math.
 * version: 1.00.
 * Description: bit manipulation function like macros.
 *************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)              (REG|=(1<<BIT))

#define CLEAR_BIT(REG,BIT)            (REG&=~(1<<BIT))

#define TOGGLE_BIT(REG,BIT)           (REG^=(1<<BIT))

#define GET_BIT(REG,BIT)              ((REG & (1<<BIT))>>BIT)

#define GET_VALUE(REG,OFFSET,COUNT)   ((REG & (((1<<COUNT) - 1)<<OFFSET))>>OFFSET)

#define INSERT_BIT(REG,BIT_NO,VALUE)  (REG=((REG & ~(1<<BIT_NO)) | (VALUE<<BIT_NO)))

#define INSERT_VALUE(REG,OFFSET,COUNT,VALUE) (REG=(REG & ~(((1<<COUNT)-1)<<OFFSET)) | (VALUE<<OFFSET))


#endif /* BIT_MATH_H_ */
