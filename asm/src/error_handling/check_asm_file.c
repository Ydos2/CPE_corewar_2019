/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Checks if an asm file is correctly written.
*/

#include "asm.h"

static int set_prog_name(char *name, header_t *header)
{
    int len = 0;

    if (header->prog_name[0])
        return (84);
    for (; name[len]; len++);
    if (len > PROG_NAME_LENGTH)
        return (84);
    if (name[0] != '"' || name[len - 1] != '"')
        return (84);
    for (int i = 1; i < len - 1; i++)
        header->prog_name[i - 1] = name[i];
    return (0);
}

static int set_prog_comment(char *comment, header_t *header)
{
    int len = 0;

    if (header->comment[0])
        return (84);
    for (; comment[len]; len++);
    if (len > COMMENT_LENGTH)
        return (84);
    if (comment[0] != '"' || comment[len - 1] != '"')
        return (84);
    for (int i = 1; i < len - 1; i++)
        header->comment[i - 1] = comment[i];
    return (0);
}

static int is_valid_header(header_t *header, char ***asm_file, int *i)
{
    char **line = NULL;
    int return_val = 0;

    for (; !(header->prog_name[0]) || !(header->comment[0]); (*i)++) {
        line = asm_file[*i];
        if (!line)
            break;
        if (!(line[0]) || !(line[0][0]) || line[0][0] == COMMENT_CHAR)
            continue;
        if (my_strcmp(".name", line[0]) == 0)
            return_val = (line[2]) ? 84 : set_prog_name(line[1], header);
        else if (my_strcmp(".comment", line[0]) == 0)
            return_val = (line[2]) ? 84 : set_prog_comment(line[1], header);
        else
            return (0);
        if (return_val == 84)
            return (0);
    }
    return (header->prog_name[0] && header->comment[0]);
}

int is_valid_asm_file(char ***asm_file, header_t *header, int *i)
{
    int i_copy = 0;

    if (!is_valid_header(header, asm_file, i)) {
        write(2, "Error : invalid header.\n", 24);
        return (0);
    }
    i_copy = *i;
    for (; asm_file[i_copy]; i_copy++) {
        if (!is_valid_asm_line(asm_file[i_copy])) {
            write(2, "Error : invalid instruction on line ", 37);
            my_put_nbr(i_copy + 1, 2);
            write(2, ".\n", 2);
            return (0);
        }
    }
    return (1);
}