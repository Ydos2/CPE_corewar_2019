/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Useful functions for parsing, error handling and conversion to machine code.
*/

#include "asm.h"

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    for (; str1[i] != 0 && str2[i] != 0; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (str1[i] - str2[i]);
}

int is_int_until(char *str, char end)
{
    int i = 0;

    if (!str || !(*str))
        return (0);
    for (; str[i] && str[i] != end; i++) {
        if (str[i] < '0' || '9' < str[i])
            return (0);
    }
    return (1);
}

int get_nbr_until(char *str, char end)
{
    int nbr = 0;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+' || str[i] == '0'; i++);
    for (; str[i] != end && str[i] != 0; i++)
        nbr = nbr * 10 + (str[i] - 48);
    if (str[0] == '-')
        nbr = nbr * (-1);
    return (nbr);
}

void my_put_nbr(int nbr, int file_descr)
{
    char character = 0;

    if (nbr < 0) {
        write(file_descr, "-", 1);
        nbr = nbr * -1;
    }
    if (nbr >= 10)
        my_put_nbr(nbr / 10, file_descr);
    character = nbr % 10 + 48;
    write(file_descr, &character, 1);
}