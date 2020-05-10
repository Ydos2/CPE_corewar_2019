/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Translates a .s file into a .cor file.
*/

#include "asm.h"

static int translate_asm_line(char **line, int cor_fd)
{
    // TODO
    return (0);
}

int translate_asm_file(char ***asm_file, char *filename)
{
    for (int i = 0; asm_file[i]; i++) {
        if (!is_valid_asm_line(asm_file[i])) {
            write(2, "Error : invalid instruction on line ", 37);
            my_put_nbr(i + 1, 2);
            write(2, ".\n", 2);
            return (84);
        } //else
            //translate_asm_line(asm_file[i], cor_fd);
    }
    return (0);
}