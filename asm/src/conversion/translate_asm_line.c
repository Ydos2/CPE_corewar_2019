/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Converts an asm line into code machine and writes it in a .cor file.
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

static int get_args_types_as_byte(char **line)
{
    int byte[8] = {0};
    int nbr = 0;

    for (int i = 0; line[i]; i++) {
        byte[i * 2] = (line[i][0] != 'r');
        byte[i * 2 + 1] = (line[i][0] != DIRECT_CHAR);
    }
    for (int i = 0; i < 8; i++)
        nbr += byte[7 - i] << i;
    return (nbr);
}

static int write_command_argument(char *argument, int fd)
{
    size_t size = 0;
    int index = 0;

    if (argument[0] == 'r') {
        size = 1;
        argument++;
    } else if (argument[0] == DIRECT_CHAR) {
        size = DIR_SIZE;
        argument++;
    } else
        size = IND_SIZE;
    if (argument[0] != LABEL_CHAR)
        write_int_as_x_bytes(get_nbr_until(argument, 0), size, fd);
    else
        write_int_as_x_bytes(index, 2, fd); // get index value
    return (0);
}

int translate_asm_line(char **line, int fd)
{
    int op_index = 0;

    // TODO : store label if line[0] is a label ?
    line += (*line && **line && line[0][my_strlen(*line) - 1] == LABEL_CHAR);
    if (!(*line) || !(**line) || **line == COMMENT_CHAR)
        return (0);
    op_index = get_op_index_by_name(line[0]);
    if (op_index == -1)
        return (84);
    write_int_as_x_bytes(op_index + 1, 1, fd);
    line++;
    if (op_index != 0 && op_index != 8 && op_index != 11 && op_index != 14)
        write_int_as_x_bytes(get_args_types_as_byte(line), 1, fd);
    for (; line[0]; line++)
        write_command_argument(line[0], fd);
    return (0);
}