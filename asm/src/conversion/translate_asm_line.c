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

    for (int i = 0; line[i] && line[i][0] != COMMENT_CHAR; i++) {
        byte[i * 2] = (line[i][0] != 'r');
        byte[i * 2 + 1] = (line[i][0] != DIRECT_CHAR);
    }
    for (int i = 0; i < 8; i++)
        nbr += byte[7 - i] << i;
    return (nbr);
}

static int write_index(char *arg, label_t *labels, int fd)
{
    int index_label = -1;
    int index = 0;

    arg += (arg[0] == DIRECT_CHAR);
    if (arg[0] == LABEL_CHAR)
        index_label = get_label_index_by_name(&(arg[1]), labels);
    else
        index_label = get_nbr_until(arg, 0);
    if (index_label == -1)
        return (84);
    index = index_label - (*current_size_line());
    if (index < 0)
        index = 65535 - (-index - 1);
    write_int_as_x_bytes(index, 2, fd);
    (*current_size()) += 2;
    return (0);
}

static size_t get_size_of_arg(char **arg)
{
    size_t size = 0;

    if ((*arg)[0] == 'r') {
        size = 1;
        (*arg)++;
    } else if ((*arg)[0] == DIRECT_CHAR) {
        size = DIR_SIZE;
        (*arg)++;
    } else
        size = IND_SIZE;
    return (size);
}

static int write_command_arg(char *arg, label_t *labels, int exception, int fd)
{
    size_t size = 0;

    if (exception && arg[0] != 'r') {
        if (write_index(arg, labels, fd) == 84)
            return (84);
        return (0);
    }
    size = get_size_of_arg(&arg);
    if (arg[0] != LABEL_CHAR) {
        write_int_as_x_bytes(get_nbr_until(arg, 0), size, fd);
        (*current_size()) += size;
    } else {
        if (write_index(arg, labels, fd) == 84)
            return (84);
    }
    return (0);
}

int translate_asm_line(char **line, label_t *labels, int fd)
{
    int op_i = 0;

    line += (*line && **line && line[0][my_strlen(*line) - 1] == LABEL_CHAR);
    if (!(*line) || !(**line) || **line == COMMENT_CHAR)
        return (0);
    op_i = get_op_index_by_name(line[0]);
    if (op_i == -1)
        return (84);
    write_int_as_x_bytes(op_i + 1, 1, fd);
    (*current_size())++;
    line++;
    if (op_i != 0 && op_i != 8 && op_i != 11 && op_i != 14) {
        write_int_as_x_bytes(get_args_types_as_byte(line), 1, fd);
        (*current_size())++;
    }
    for (int i = 0; line[i] && line[i][0] != COMMENT_CHAR; i++) {
        if (write_command_arg(line[i], labels, is_exception(op_i, i), fd) == 84)
            return (84);
    }
    return (0);
}