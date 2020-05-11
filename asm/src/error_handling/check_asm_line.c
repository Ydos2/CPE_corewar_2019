/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Checks if a .s file's line is correctly written.
*/

#include "asm.h"

static int is_valid_label(char *arg)
{
    for (int i = 0; arg[i + 1]; i++) {
        if (!is_label_char(arg[i]))
            return (0);
    }
    if (arg[my_strlen(arg) - 1] != LABEL_CHAR)
        return (0);
    return (1);
}

static int get_op_index_by_name(char *name)
{
    if (!name)
        return (-1);
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(name, op_tab[i].mnemonique) == 0)
            return (i);
    }
    return (-1);
}

static int check_nbr_of_args(int op_index, char **line)
{
    int nbr_args = 0;

    for (int i = 1; line[i] && line[i][0] != COMMENT_CHAR; i++, nbr_args++);
    if (op_tab[op_index].nbr_args != nbr_args)
        return (84);
    return (0);
}

int is_valid_asm_line(char **line)
{
    int op_index = 0;

    if (line[0][0] == COMMENT_CHAR)
        return (1);
    if (is_valid_label(line[0])) {
        if (!line[1] || line[1][0] == COMMENT_CHAR)
            return (1);
        line++;
    }
    op_index = get_op_index_by_name(line[0]);
    if (op_index == -1)
        return (0);
    if (check_nbr_of_args(op_index, line) == 84)
        return (0);
    for (int i = 1; line[i] && line[i][0] != COMMENT_CHAR; i++) {
        if (!is_valid_argument(op_index, line[i], i - 1))
            return (0);
    }
    return (1);
}