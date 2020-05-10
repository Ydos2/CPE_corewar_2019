/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Main function
*/

#include <unistd.h>
#include <sys/stat.h>
       #include <fcntl.h>
#include "op.h"
#include "asm.h"

static int display_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
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
    char ***asm_file = NULL;
    int return_value = 0;

    if (display_help(ac, av))
        return (0);
    if (ac != 2)
        return (84);
    asm_file = get_file(av[1]); // TODO
    if (!asm_file)
        return (84);
    return_value = translate_asm_file(asm_file, av[1]); // TODO
    destroy_file(asm_file);
    return (return_value);
}
