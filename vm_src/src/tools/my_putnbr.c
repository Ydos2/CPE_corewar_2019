/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "vm.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483647)
        return (84);
    if (nb > 9)
        my_putnbr(nb / 10);
    if (nb < 0 && nb > -10) {
        write(1, "-", 1);
    } else if (nb < 0) {
        write(1, "-", 1);
        my_putnbr(nb / -10);
    }
    if (nb >= 0)
        my_putchar(nb % 10 + '0');
    if (nb < 0)
        my_putchar(- nb % 10 + '0');
    return (0);
}