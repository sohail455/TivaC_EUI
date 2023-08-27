#ifndef TERMINAL_MANAGER_H_
#define TERMINAL_MANAGER_H_

#define GOTOXY(x, y) printf("\033[%d;%dH", (y), (x))

#define PRINT_MAIN_MENU           \
  printf(YEL "Commands\n" RESET); \
  printf(GRN "1- USER\n" RESET);  \
  printf(GRN "2- ADMIN\n" RESET);

#define PRINT_USER_INSTRUCTIONS            \
  printf(YEL "Commands\n" RESET);          \
  printf(GRN "1- RESERVE TICKET\n" RESET); \
  printf(GRN "2- CANCEL TICKET\n" RESET);  \
  printf(GRN "3- SHOW RESERVED\n" RESET);  \
  printf(GRN "4- RETURN TO MAIN MENU\n" RESET);

#define PRINT_ADMIN_INSTRUCTIONS                \
  printf(YEL "Commands\n" RESET);               \
  printf(GRN "1- SHOW RESERVED SEATS\n" RESET); \
  printf(GRN "2- CHANGE PRICE\n" RESET);        \
  printf(GRN "3- RETUEN TO USER MENU\n" RESET);

#define PRINT_MOVIES                           \
  printf(YEL "movies options\n" RESET);        \
  printf(GRN "1- OPPENHIEMER\n" RESET);        \
  printf(GRN "2- BARBIE\n" RESET);             \
  printf(GRN "3- MISSION IMPOSSIBLE\n" RESET); \
  printf(GRN "4- RETUEN TO USER MENU\n" RESET);

#define PRINT_CANCEL_OPTIONS                    \
  printf(YEL "Commands\n" RESET);               \
  printf(GRN "1- CANCEL BY SEAT NUMBER\n" RESET); \
  printf(GRN "2- CANCEL BY PHONENUMBER\n" RESET);        \
  printf(GRN "3- RETUEN TO USER MENU\n" RESET);

void play_intro();
void play_win();
void play_correct();
void play_fail();
void play_delete();
void play_gameOver();
void play_errorBuzz();
void clrscr();
void print_cinema_entery();
void show_error(char *errorMessage);

#endif
