/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}