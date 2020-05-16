/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Writes an int as a needed number of bytes in a file.
*/

#include "asm.h"

static int bin_write_byte(int fd, unsigned char *data)
{
    ssize_t write_size = 0;

    write_size = write(fd, data, 1);
    if (write_size == -1)
        return (0);
    return (1);
}

static long x_to_the_power_of_y(int x, int y)
{
    if (y == 0)
        return (1);
    return (x * x_to_the_power_of_y(x, y - 1));
}

int write_int_as_x_bytes(long nbr, size_t size, int fd)
{
    long byte_as_long = 0;
    unsigned char byte = 0;

    for (size_t i = 0; i < size; i++) {
        byte_as_long = nbr % x_to_the_power_of_y(16, (size - i) * 2);
        byte_as_long /= x_to_the_power_of_y(16, (size - i - 1) * 2);
        byte = (unsigned char)byte_as_long;
        if (!bin_write_byte(fd, &byte))
            return (84);
    }
    return (0);
}