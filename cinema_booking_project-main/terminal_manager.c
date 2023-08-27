#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal_color.h"
#include "terminal_manager.h"

inline void print_cinema_entery()
{
    printf(BLU "============================================================\n");
    printf("===     ===    ==  =======  ==        ==  =====  =====  ====\n");
    printf("==  ===  ===  ===   ======  ==  ========   ===   ====    ===\n");
    printf("=  =========  ===    =====  ==  ========  =   =  ===  ==  ==\n");
    printf("=  =========  ===  ==  ===  ==  ========  == ==  ==  ====  =\n");
    printf("=  =========  ===  ===  ==  ==      ====  =====  ==  ====  =\n");
    printf("=  =========  ===  ====  =  ==  ========  =====  ==        =\n");
    printf("=  =========  ===  =====    ==  ========  =====  ==  ====  =\n");
    printf("==  ===  ===  ===  ======   ==  ========  =====  ==  ====  =\n");
    printf("===     ===    ==  =======  ==        ==  =====  ==  ====  =\n");
    printf("============================================================\n");
    printf("\t   made with");
    printf(RED " ♥ " RESET);
    printf(BLU "by trojan and mechanicus\n\n" RESET);
}

void show_error(char *errorMessage)
{
    printf(RED "%s" RESET, errorMessage);
    play_errorBuzz();
}

void clrscr()
{
#ifdef __APPLE__
    system("clear");
#else
    system("@cls||clear");
#endif
}

void play_intro()
{
#ifdef __APPLE__
    system("afplay sounds/intro.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/intro.wav').PlaySync();");
#endif
}


void play_correct()
{

#ifdef __APPLE__
    system("afplay sounds/correct.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/correct.wav').PlaySync();");
#endif
}

void play_errorBuzz()
{
#ifdef __APPLE__
    system("afplay sounds/error_buzz.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/error_buzz.wav').PlaySync();");
#endif
}

void play_delete()
{
#ifdef __APPLE__
    system("afplay sounds/delete.wav");
#else
    system("powershell -c (New-Object Media.SoundPlayer 'sounds/delete.wav').PlaySync();");
#endif
}
