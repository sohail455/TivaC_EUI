 /******************************************************************************
 
 * File Name: Cinema_manager.c
 *
 * Description: the flow control of the the whole system
 *
 * Author: Trojan and Mechanicus
 *
 *******************************************************************************/


#include <stdio.h>
#include "terminal_manager.h"
#include "terminal_color.h"
#include "cinema_brain.h"
#include "cinema_manager.h"
#include "verification.h"
#include "MyP_Types.h"


static STATE current_state = INITIAL;

/*
 * Description :
 * the fuction is responsible for starting the application
 */

void start_app()
{
    clrscr();
    print_cinema_entery();
    play_intro();
    clrscr(); // clear terminal
    print_cinema_entery();
    clrscr(); // clear terminal

    while (1)
    {

        switch (current_state)
        {
        case INITIAL:
            select_user();
            break;
        case USER_SELECTION:
            manage_user_selection();
            break;
        case ADMIN_SELECTION:
            manage_admin_selection();
            break;
        case SHOW_RESERVED_TICKET:
            manage_showing_ticket();
            break;
        case RESERVE_TICKET:
            manage_ticket_reserve();
            break;
        case CANCEL_TICKET:
            manage_ticket_cancel();
            break;
        case CHANGE_PRICE:
            manage_change_price();
            break;
        default:
            break;
        }
    }
}

/*
 * Description :
 * the fuction is responsible for slecting the mode (user/admin)
 */

void select_user()
{
    Int32_t selected_value;
    Int8_t pass[6] = {0};
    PRINT_MAIN_MENU;
    printf(BLU "TO MANAGE SYSTEM AS USER PRESS 1 AS ADMIN PRESS 2: " RESET);

    scanf("%d", &selected_value);

    if (selected_value == 1)
    {
        get_pass(pass);
        if (1 == verify_user_pass(pass))
        {
            set_credential(USER);
            current_state = USER_SELECTION;
        }
        else
        {
            show_error("WRONG PASSWORD\n");
        }
    }
    else if (selected_value == 2)
    {
        get_pass(pass);
        if (1 == verify_admin_pass(pass))
        {
            set_credential(ADMIN);
            current_state = ADMIN_SELECTION;
        }
        else
        {
            show_error("WRONG PASSWORD\n");
        }
    }
    else
    {
        printf(RED "WRONG ENTERY\n" RESET);
        play_errorBuzz();
    }
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for managing user selection. based on user's input the state of the 
 * program will change.
 */

void manage_user_selection()
{
    PRINT_USER_INSTRUCTIONS;
    Int32_t selection;
    printf("please enter your selection: ");
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        current_state = RESERVE_TICKET;
        break;
    case 2:
        current_state = CANCEL_TICKET;
        break;
    case 3:
        current_state = SHOW_RESERVED_TICKET;
        break;
    case 4:
        current_state = INITIAL;
        break;

    default:
        show_error("WRONG ENTERY\n");
        break;
    }
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for handling seat booking by asking the user to select 
 * the movie then ask user to enter phone number. the function will not complete the
 * booking process if the seat is already reserved or the phone number is incorrect.
 */

void manage_ticket_reserve()
{

    PRINT_MOVIES;
    Int8_t phone_number[12];
    Int32_t selection;
    Int32_t seat_number;
    ERROR_type status;

    printf("please enter your selection: ");
    scanf("%d", &selection);
    if (selection < 4 && selection > 0)
    {
        printf("please enter seat number: ");
        scanf("%d", &seat_number);
        printf("please enter your phone number: ");
        fflush(stdin);
        scanf("%s", phone_number);
        if (phone_check(phone_number) == OK)
        {
            if (seat_number > 0 && seat_number <= 100)
            {
                status = reserve_seat(selection, seat_number, phone_number);
                if (status == NOT_OK)
                {
                    show_error("SEAT IS ALREADY RESERVED\n");
                }
                else
                {
                    play_correct();
                }
            }
            else
            {
                show_error("INCORRECT SEAT NUMBER\n");
            }
        }
        else
        {
            show_error("INCORRECT PHONENUMBER\n");
        }
    }
    else if (selection == 4)
    {
        current_state = USER_SELECTION;
    }
    else
    {
        show_error("WRONG ENTERY");
    }
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for showing  seats in each movie
 */

void manage_showing_ticket()
{
    Int32_t movie_number;
    PRINT_MOVIES;
    printf("please enter movie number: ");
    scanf("%d", &movie_number);
    if (movie_number > 0 && movie_number < 4)
    {
        clrscr();
        view_reservedTicket(movie_number - 1);
        current_state = SHOW_RESERVED_TICKET;
    }
    else if (movie_number == 4)
    {
        current_state = USER_SELECTION;
        clrscr();
    }
    else
    {
        current_state = SHOW_RESERVED_TICKET;
        show_error("WRONG ENTERY\n");
        clrscr();
    }
}

/*
 * Description :
 * the fuction is responsible for canceling  seats in each movie
 */

void manage_ticket_cancel()
{
    Int32_t selected_movie, selection;

    PRINT_MOVIES;
    printf("please enter your selection: ");
    scanf("%d", &selection);
    if (selection == 4)
    {
        current_state = USER_SELECTION;
    }
    else if (selection > 0 && selection < 4)
    {
        clrscr();
        selected_movie = selection;
        PRINT_CANCEL_OPTIONS;
        printf("please enter your selection: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            manage_cancelBySeat(selected_movie);
            break;
        case 2:
            manage_cancelByPhoneNumber(selected_movie);
            break;
        case 3:
            current_state = CANCEL_TICKET;
            break;
        default:
            show_error("WRONG ENTERY\n");
            break;
        }
    }
    else
    {
        show_error("WRONG ENTERY\n");
    }
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for managing admin selection. based on admin's input the state of the 
 * program will change.
 */

void manage_admin_selection()
{
    PRINT_ADMIN_INSTRUCTIONS;
    Int32_t selection;
    printf("please enter your selection: ");
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        current_state = SHOW_RESERVED_TICKET;
        break;
    case 2:
        current_state = CHANGE_PRICE;
        break;
    case 3:
        current_state = INITIAL;
        break;

    default:
        show_error("WRONG ENTERY");
        break;
    }
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for changing the price of the ticket
 */

void manage_change_price()
{
    Int32_t new_price;
    printf("please enter the new price: ");
    scanf("%d", &new_price);
    change_price(new_price);
    current_state = ADMIN_SELECTION;
    clrscr();
}

/*
 * Description :
 * the fuction is responsible for recieve the password from user 
 */

void get_pass(Int8_t *pass)
{
    printf(YEL "Enter password: " RESET);
    scanf("%s", pass);
    pass[5] = '\0';
}


/*
 * Description :
 * the fuction is responsible for canceling seat booking by asking the user to enter the seat number
 */

void manage_cancelBySeat(Int32_t selected_movie)
{
    ERROR_type status;

    Int32_t selected_seat;
    printf("please enter seat number: ");
    scanf("%d", &selected_seat);
    status = cancel_seat(selected_movie, selected_seat);
    if (status == NOT_OK)
    {
        show_error("SEAT IS ALREADY NOT RESERVED\n");
    }
    else
    {
        play_delete();
    }
}


/*
 * Description :
 * the fuction is responsible for canceling seat booking by asking the user to enter the
 * phone number
 */

void manage_cancelByPhoneNumber(Int32_t selected_movie)
{

    ERROR_type status;
    Int8_t phone_number[12];
    printf("please enter your phoneNumber: ");
    fflush(stdin);
    scanf("%s", phone_number);
    if (phone_check(phone_number) == OK)
    {
        status = canceling_by_phone(selected_movie, phone_number);
        if (status == NOT_OK)
        {
            show_error("SEAT IS ALREADY NOT RESERVED\n");
        }
        else if (status == NOT_FOUND)
        {
            show_error("NO SEAT RESERVED USING THIS PHONENUMBER\n");
        }
        else
        {
            play_delete();
        }
    }
    else
    {
        show_error("INCORRECT PHONENUMBER\n");
    }
}
