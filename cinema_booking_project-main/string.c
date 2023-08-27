#include <stdio.h>

void string_scan(char *str, int max_size)
{
    int i = 0;
    fflush(stdin);
    scanf("%c", &str[i]);
    for (; str[i] != '\n' && i < max_size - 1;)
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = 0;
}