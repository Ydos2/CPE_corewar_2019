/*
** EPITECH PROJECT, 2020
** octet
** File description:
** octet
*/

#include <unistd.h>
#include "vm.h"

char this_octet(char param, int to_read)
{
    int pos = 7 - ((to_read - 1) * 2);
    char result = 2 * ((param >> pos) & 1);

    pos--;
    result = result + ((param >> pos) & 1);
    return (result);
}

int octet_to_read(char param, int to_read)
{
    char arg = this_octet(param, to_read);

    if (arg == T_REG)
        return (1);
    else if (arg == T_DIR)
        return (4);
    else if (arg == T_IND - 1)
        return (2);
    return (-1);
}

int octet_to_r(char arg)
{
    if (arg == T_REG)
        return (1);
    else if (arg == T_DIR)
        return (4);
    else if (arg == T_IND - 1)
        return (2);
    return (-1);
}

int place_to_jump(char arg, char place)
{
    int tmp = 0;

    for (char i = 1; i <= place; i++)
        tmp = tmp + octet_to_read(arg, i);
    return (tmp);
}