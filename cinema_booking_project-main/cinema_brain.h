 /******************************************************************************
 
 * File Name: Cinema_brain.h
 *
 * Description: the main functionality of the system
 *
 * Author: Trojan and Mechanicus
 *
 *******************************************************************************/

#include "MyP_Types.h"

#ifndef CINMEA_BRAIN_H_
#define CINMEA_BRAIN_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NO_OF_SEATS 100
#define NO_OF_MOVIES 3


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef struct {
    Int8_t  phone_number[12];
    Int32_t isReserved;
    Int32_t price;
}Seat_t;


typedef enum{
    ADMIN,
    USER
}USER_type;


typedef enum{
    INITIAL,
    USER_SELECTION,
    ADMIN_SELECTION,
    RESERVE_TICKET,
    CANCEL_TICKET,
    DISPLAY_SEAT,
    SHOW_RESERVED_TICKET,
    CHANGE_PRICE
}STATE;


typedef enum{
    OK,
    NOT_OK,
    NOT_FOUND
}ERROR_type;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void view_reservedTicket(Int32_t movie_index);
void change_price(Int32_t new_price);
void set_credential(USER_type type_of_user);
void get_pass (Int8_t  *pass);
USER_type get_user_type();
Int32_t seats(Int32_t index);
ERROR_type reserve_seat(Int32_t movie_index, Int32_t seat_number,char* phone_number);
ERROR_type cancel_seat(Int32_t movie_index,Int32_t seat_number);
ERROR_type canceling_by_phone (Int32_t movie_index , Int8_t  *phone_number);


#endif
