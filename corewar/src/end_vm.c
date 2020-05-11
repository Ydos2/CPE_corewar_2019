/*
** EPITECH PROJECT, 2020
** end_vm
** File description:
** end_vm
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static void end_prog(arena_t *arena)
{
    write(1, "\n", 1);
    print_arena_carac(arena);
    for (int i = 0; i < arena->champion->nbr_champion; i++) {
        free(arena->champion->instruction[i]);
        free_process(arena->champion->process[i]);
    }
    free(arena->champion->live);
    free(arena->champion->id_champion);
    free(arena->champion->header);
    free(arena->champion->instruction);
    free(arena->champion->process);
    free(arena->champion);
    free(arena->arena);
    free(arena->carac);
    free(arena);
}

void end_vm(arena_t *arena)
{
    write(1, "Player ", 7);
    my_putnbr(arena->champion->id_champion[arena->champion->last_live]);
    write(1, " called ", 8);
    my_putstr(arena->champion->header[arena->champion->last_live].prog_name);
    write(1, " won.", 5);
    end_prog(arena);
    write(1, "End war.\n", 9);
    exit(0);
}