/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:   David & Sohail & Hossam
 *         File:  Calc_manage.c
 *        Layer:  APP
 *       Module:  Calc_manage
 *      Version:  1.00
 *
 *  Description:  Source file of calculator
 *
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "lcd.h"
#include "Systick.h"
#include "Keypad.h"
#include "Calc_manage.h"

unsigned next_digit=0;
unsigned long ops_arr[arrsize]={0};
long double oper_arr[arrsize]={0};
unsigned char oper_count=0;
unsigned char sort_ops[4]={'*','%','+','-'};
unsigned char minus_flag=0;
unsigned char is_operand=0;
unsigned minus_counter=0;
unsigned char syntax_error_flag=0;
unsigned char math_error=0;

void get_number(void)
{
    long num=0;
    is_operand=0;
    /****************************************************************************
     *                         Handle input process                             *
     ***************************************************************************/
    while(1)
    {
        next_digit=KeyPad_GetValue  ();
        Sys_delay(280);
        if(!((next_digit >=0) && (next_digit <=9)))
        {
            break;
        }
        if(minus_flag==0)
        {
            num=num*10+next_digit;
        }
        else if(minus_flag==1)
        {
            num=num*(10)-(next_digit);
        }
        LCD_intgerToString(next_digit);
        is_operand=1;
    }
    LCD_displayCharacter(next_digit);
    /****************************************************************************
     *                         Handle Syntax Errors                             *
     ***************************************************************************/
    if(((next_digit == '%') || (next_digit == '*'))&&(is_operand==0))
    {
        syntax_error_flag=1;

    }
    if(next_digit == '=' && is_operand == 0)
    {
        syntax_error_flag=1;
    }
    /****************************************************************************
     *                    Handle the sign of the number                         *
     ***************************************************************************/
    if(is_operand == 1)/*prevent from negate the next number, suppose the next number is positive by default*/
    {
        minus_counter=0;
        minus_flag=0;
    }
    if(next_digit == '-')/*change the sign of the number every minus occurred*/
    {
        minus_flag=1;
        minus_counter++;
        if(minus_counter == 2)
        {
            minus_flag=0;
            minus_counter=0;
        }
    }
    /****************************************************************************
     *                Handle the operations and the operands                    *
     ***************************************************************************/
    if(is_operand == 1)/*only insert operands if there is one */
    {
        oper_arr[oper_count]=num;
    }
    if((next_digit != '=') && (is_operand==1))/*only insert operations if there is operand and don't insert equal*/
    {
        ops_arr[oper_count]=next_digit;
        oper_count++;
    }
    /****************************************************************************
     *                stop the input process and start to compute               *
     ***************************************************************************/
    if(next_digit == '=')
    {
        if(syntax_error_flag == 0)
        {
            result();
            if(math_error==1)
            {
                math_error=0;
                syntax_error_flag=0;
                LCD_clearScreen();
                LCD_moveCursor(0, 0);
                LCD_displayString("Math Error");
                Sys_delay(2000);
                LCD_clearScreen();
                LCD_moveCursor(0, 0);
                oper_count = 0;
                minus_counter=0;
                minus_flag=0;
            }
            else
            {
                LCD_moveCursor(1, 0);
                LCD_intgerToString(oper_arr[0]);
                Sys_delay(4000);
                oper_count = 0;
                LCD_clearScreen();
                LCD_moveCursor(0, 0);
                oper_arr[0]=0;
                minus_counter=0;
                minus_flag=0;
            }
        }
        else if(syntax_error_flag == 1)
        {
            syntax_error_flag=0;
            LCD_clearScreen();
            LCD_moveCursor(0, 0);
            LCD_displayString("Syntax Error");
            Sys_delay(2000);
            LCD_clearScreen();
            LCD_moveCursor(0, 0);
            oper_count = 0;
            minus_counter=0;
            minus_flag=0;
        }
    }
}

void custom_sort(long double *arr, int index)
{
    int i;
    for(i = index; i < arrsize-1; i++){
        long temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

void custom_sort_ops(unsigned long *arr, int index)
{
    int i;
    for(i = index; i < arrsize-1; i++){
        unsigned long temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

void result(void)
{
    int flag = 0;
    int i=0;
    for(i=0;i<oper_count;i++)/*first finish the multiplication and division operations*/
    {
        if(flag){
            i=0;
            flag = 0;
        }
        if(ops_arr[i] == sort_ops[0])
        {
            oper_arr[i+1] *= oper_arr[i];
            oper_arr[i]=0;
            ops_arr[i] = 0;
            custom_sort(oper_arr,i);
            custom_sort_ops(ops_arr, i);
            flag = 1;
        }
        if(ops_arr[i] == sort_ops[1])
        {
            if(oper_arr[i+1] == 0)
            {
                math_error=1;
            }
            oper_arr[i+1] = oper_arr[i]/oper_arr[i+1];
            oper_arr[i]=0;
            ops_arr[i] = 0;
            custom_sort(oper_arr,i);
            custom_sort_ops(ops_arr, i);
            flag = 1;
        }

    }

    for(i=0;i<oper_count;i++)/*second finish the addition and subtraction operations*/
    {
        if(flag){
            i=0;
            flag = 0;
        }
        if(ops_arr[i] == sort_ops[2])
        {
            oper_arr[i+1] = oper_arr[i]+oper_arr[i+1];
            oper_arr[i]=0;
            ops_arr[i] = 0;
            custom_sort(oper_arr,i);
            custom_sort_ops(ops_arr, i);
            flag = 1;
        }
        if(ops_arr[i] == sort_ops[3])
        {
            oper_arr[i+1] = oper_arr[i]+oper_arr[i+1];
            oper_arr[i]=0;
            ops_arr[i] = 0;
            custom_sort(oper_arr,i);
            custom_sort_ops(ops_arr, i);
            flag = 1;
        }
    }
}

void start_Calc()
{
    LCD_init();
    LCD_displayString("OUR  ");
    Sys_delay(1000);

    LCD_displayString("CALCULATOR");
    Sys_delay(2000);

    LCD_clearScreen();
    LCD_displayString("Sohail    ");

    LCD_displayString("David");
    Sys_delay(1000);

    LCD_moveCursor(1, 5);
    LCD_displayString("Hossam");
    Sys_delay(2000);
    LCD_clearScreen();

    while(1)
    {
        get_number();
    }
}
