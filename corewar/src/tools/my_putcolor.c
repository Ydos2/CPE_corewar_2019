/*
** EPITECH PROJECT, 2020
** my_putcolor
** File description:
** my_putcolor
*/

#include <unistd.h>
#include "vm.h"

void color(int i)
{
    int result;

    if (i < 0 || i > 7)
        result = 0;
    else
        result = 30 + i;
    my_putstr("\033[1;3;");
    my_putnbr(result);
    write(1, "m", 1);
}

int my_putcolor(char *str, int i)
{
    if (str[i] >= '0' && str[i] <= '7')
        color(str[i] - 48);
    else {
        color(-1);
        i--;
    }
    return (i);
}