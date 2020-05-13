/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Converts the header into machine code and write it in the .cor file.
*/

#include "asm.h"

void init_header(header_t *header)
{
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    for (int i = 0; i <= PROG_NAME_LENGTH; i++)
        header->prog_name[i] = 0;
    for (int i = 0; i <= COMMENT_LENGTH; i++)
        header->comment[i] = 0;
}

static int get_arg_size(char *argument)
{
    int size = 0;

    if (argument[0] == 'r')
        return (1);
    if (argument[0] == DIRECT_CHAR) {
        size = DIR_SIZE;
        argument++;
    } else
        size = IND_SIZE;
    if (argument[0] != LABEL_CHAR)
        return (size);
    //else
        // TODO : handle label
    return (0);
}

static int get_line_size(char **line)
{
    int op_index = 0;
    int line_size = 0;

    line += (*line && **line && line[0][my_strlen(*line) - 1] == LABEL_CHAR);
    if (!(*line) || !(**line) || **line == COMMENT_CHAR)
        return (0);
    op_index = get_op_index_by_name(line[0]);
    line_size++;
    line++;
    if (op_index != 0 && op_index != 8 && op_index != 11 && op_index != 14)
        line_size++;
    for (; line[0]; line++)
        line_size += get_arg_size(line[0]);
    return (line_size);
}

static int get_prog_size(char ***asm_file)
{
    int prog_size = 0;

    // TODO : store labels ?
    for (int i = 0; asm_file[i]; i++)
        prog_size += get_line_size(asm_file[i]);
    return (prog_size);
}

int translate_header(header_t *header, char ***asm_file, int fd)
{
    header->prog_size = get_prog_size(asm_file);

    if (write_int_as_x_bytes(COREWAR_EXEC_MAGIC, 4, fd) == 84)
        return (84);
    if (write(fd, header->prog_name, PROG_NAME_LENGTH) < 0)
        return (84);
    if (write_int_as_x_bytes(0, 4, fd) == 84)
        return (84);
    if (write_int_as_x_bytes(header->prog_size, 4, fd) == 84)
        return (84);
    if (write(fd, header->comment, COMMENT_LENGTH) < 0)
        return (84);
    if (write_int_as_x_bytes(0, 4, fd) == 84)
        return (84);
    return (0);
}