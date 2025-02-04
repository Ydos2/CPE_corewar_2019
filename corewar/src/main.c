/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Main function
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static int draw_help(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            write(1, "USAGE\n", 6);
            write(1, "\t./corewar [-dump nbr_cycle] [[-n prog_number]", 46);
            write(1, " [-a load_address] prog_name] ...\nDESCRIPTION\n", 46);
            write(1, "\t-dump nbr_cycledumps the memory after the", 42);
            write(1, " nbr_cycle execution (if the round isn’talready", 47);
            write(1, " over) with the following format: 32", 36);
            write(1, "bytes/linein hexadecimal (A0BCDEFE1DD3...)\n", 43);
            write(1, "\t-n prog_numbersets the next program’s ", 39);
            write(1, "number. By default, the first free numberin ", 44);
            write(1, "the parameter order\n", 20);
            write(1, "\t-a load_addresssets the next program’s ", 40);
            write(1, "loading address. When no address isspecified, ", 46);
            write(1, "optimize the addresses so that the processes", 44);
            write(1, " are as faraway from each other as possible.", 44);
            write(1, " The addresses areMEM_SIZEmodulo.\n", 34);
            return (1);
        }
    return (0);
}

static int verif_error(int ac, char **av, char **env)
{
    if (env == NULL) {
        write(2, "I can't read the env\n", 21);
        return (84);
    } else if (ac == 0)
        return (84);
    (void)av;
    return (0);
}

static int initialise_main(int ac, char **av)
{
    champion_t *champion = malloc(sizeof(champion_t));
    arena_t *arena = malloc(sizeof(arena_t));

    init_champion(champion, ac, av);
    init_arena(arena, champion);
    write(1, "Start war :\n", 12);
    print_arena_carac(arena);
    write(1, "War begin :\n", 12);
    vm_start(arena);
    end_vm(arena);
    free(champion);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (draw_help(ac, av) == 1)
        return (0);
    if (verif_error(ac, av, env) == 84)
        return (84);
    return (initialise_main(ac, av));
}