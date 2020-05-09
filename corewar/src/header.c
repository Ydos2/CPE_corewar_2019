/*
** EPITECH PROJECT, 2020
** header
** File description:
** header
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static int reverse_int(int number)
{
    number = (((number << 8) & 0xFF00FF00)
        | ((number >> 8) & 0xFF00FF));
    number = (number << 16)
        | ((number >> 16) & 0xFFFF);
    return (number);
}

header_t get_header(int fd)
{
    header_t header;

    if (read(fd, &header, sizeof(header_t)) < 0) {
        write(2, "Couldn't read one of the requested champion\n", 44);
        exit(84);
    }
    header.magic = reverse_int(header.magic);
    header.prog_size = reverse_int(header.prog_size);
    return (header);
}