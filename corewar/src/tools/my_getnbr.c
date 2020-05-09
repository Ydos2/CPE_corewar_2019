/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static int true_nbr(int number, char add, int less)
{
    if (number <= 214748364) {
        if (number == 214748364) {
            if ((less < 0 && add <= 56) || (less > 0 && add <= 55)) {
                number = number * 10;
                number = number + add - 48;
                return (number);
            }
        } else {
            number = number * 10;
            number = number + add - 48;
            return (number);
        }
    }
    return (-1);
}

int my_getnbr(const char *str)
{
    int	number = 0;
    int	less = 1;
    int	i = 0;

    while (str[i] == ' ' || str[i] == '\n')
        i++;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            less = -1 * less;
        i++;
    }
    while (str[i] > 47 && str[i] < 58) {
        number = true_nbr(number, str[i], less);
        if (number == -1)
            return (0);
        i++;
    }
    return (number * less);
}