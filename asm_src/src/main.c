/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Main function
*/

#include <unistd.h>
#include "op.h"
#include "asm.h"

static int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == 0 || s2 == 0)
        return (0);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return ((s1[i] > s2[i]) ? 1 : -1);
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s1[i] != '\0' && s2[i] == '\0')
        return (1);
    return (0);
}

static int draw_help(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            write(1, "USAGE\n", 6);
            write(1, "\t./asm file_name[.s]\n", 21);
            write(1, "DESCRIPTION\n", 12);
            write(1, "\tfile_namefile in assembly language to ", 39);
            write(1, "be converted intofile_name.cor, anexecutable ", 45);
            write(1, "in the Virtual Machine.\n", 24);
            return (1);
        }
    return (0);
}

int main(int ac, char **av)
{
    if (draw_help(ac, av) == 1)
        return (0);
    return (asm_start(av[1]));
}
