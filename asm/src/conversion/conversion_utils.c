/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Conversion utils.
*/

#include "asm.h"

int *current_size(void)
{
    static int current_size = 0;

    return (&current_size);
}

int is_exception(int op_index, int arg_index)
{
    if (op_index == 8 || (op_index == 9 && arg_index != 2) ||
       (op_index == 10 && arg_index != 0) || op_index == 11) {
        return (1);
    }
    return (0);
}