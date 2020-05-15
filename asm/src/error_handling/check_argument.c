/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Checks if an argument is valid.
*/

#include "asm.h"

static int is_valid_register(char *arg)
{
    int nbr = 0;

    if (!is_int_until(&(arg[1]), 0))
        return (0);
    nbr = get_nbr_until(&(arg[1]), 0);
    if (nbr < 1 || REG_NUMBER < nbr)
        return (0);
    return (1);
}

static int is_valid_label(char *arg)
{
    if (arg[0] != LABEL_CHAR)
        return (0);
    for (int i = 1; arg[i]; i++) {
        if (!is_label_char(arg[i]))
            return (0);
    }
    return (1);
}

static int check_arg_type(int op_index, args_type_t arg_type, int arg_index)
{
    args_type_t valid_types = 0;

    valid_types = op_tab[op_index].type[arg_index];
    if ((valid_types | arg_type) != valid_types)
        return (84);
    return (0);
}

int is_valid_argument(int op_index, char *arg, int arg_index)
{
    args_type_t arg_type = 0;

    if (*arg == 'r') {
        arg_type = T_REG;
        if (!is_valid_register(arg))
            return (0);
    } else {
        if (*arg == DIRECT_CHAR) {
            arg++;
            arg_type = T_DIR;
        } else
            arg_type = T_IND;
        if (!is_int_until(arg, 0) && !is_valid_label(arg))
            return (0);
    }
    if (check_arg_type(op_index, arg_type, arg_index) == 84)
        return (0);
    return (1);
}