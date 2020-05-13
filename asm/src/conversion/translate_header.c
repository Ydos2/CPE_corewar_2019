/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Converts the header into machine code and write it in the .cor file.
*/

#include "asm.h"

int translate_header(header_t header, int fd) // read(fd, &header, sizeof(header));
{
    if (write_int_as_x_bytes(COREWAR_EXEC_MAGIC, 4, fd) == 84)
        return (84);
    for (int i = 0; i < PROG_NAME_LENGTH; i++) {
        if (write_int_as_x_bytes(header.prog_name[i], 1, fd) == 84)
            return (84);
    }
    if (write_int_as_x_bytes(0, 4, fd) == 84) // why ?
        return (84);
    if (write_int_as_x_bytes(23, 4, fd) == 84) // why ?
        return (84);
    for (int i = 0; i < COMMENT_LENGTH; i++) {
        if (write_int_as_x_bytes(header.comment[i], 1, fd) == 84)
            return (84);
    }
    if (write_int_as_x_bytes(0, 4, fd) == 84) // why ?
        return (84);
    return (0);
}