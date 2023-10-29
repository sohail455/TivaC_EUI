/*
 * Comm_Manger.h
 *
 *  Created on: Sep 3, 2023
 *      Author: Qaiaty store
 */

#ifndef COMM_MANGER_H_
#define COMM_MANGER_H_
#include <stdint.h>
#include <stdbool.h>
#define MAX_SIZE   200
extern uint8_t str0[MAX_SIZE];
extern uint8_t str1[MAX_SIZE];
extern uint8_t error_flag;
extern uint8_t send_flag1;
extern uint8_t send_flag0;
extern uint8_t counter0;
extern uint8_t counter1;
void comm_init(void);
void send_String(uint8_t* str,uint32_t uart_type);
void Read_UART1_string();
void Read_UART0_string();
//void Read_string();



#endif /* COMM_MANGER_H_ */
