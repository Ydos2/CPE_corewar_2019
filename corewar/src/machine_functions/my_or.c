/*
** EPITECH PROJECT, 2020
** my_or
** File description:
** my_or
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_or(arena_t *arena, process_t *process, int id, int pc_pos)
{
    int nbr;
    int ind;
    char arg;

    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 6, process->pos, 3) == -1)
    return (0);
    process->cycle += op_tab[6].nbr_cycles;
    nbr = take_what(arena->arena, process->pos, choose(pc_pos, 1, 1),
            process->reg);
    nbr |= take_what(arena->arena, process->pos, choose(pc_pos, 1, 2),
            process->reg);
    ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
    process->reg[ind - 1] = nbr;
    process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
    return (0);
}