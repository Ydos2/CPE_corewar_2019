/*
** EPITECH PROJECT, 2020
** my_st
** File description:
** my_st
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_st(arena_t *arena, process_t *process, int id, int pc_pos)
{
    int nbr;
    int ind;
    char arg;

    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 2, process->pos, 2) == -1)
        return (0);
    process->cycle += op_tab[2].nbr_cycles;
    nbr = process->reg[arena->arena[circle(process->pos, 1)] - 1];
    if (octet_to_read(arg, 2) == T_REG)
    process->reg[arena->arena[circle(process->pos, 2)] - 1] = nbr;
    else {
        ind = take_param(arena->arena, process->pos + 2, IND_SIZE);
        put_param(arena, circle(pc_pos, mod(ind, IDX_MOD)),
            arena->champion->id_champion[id], nbr);
    }
    process->pos = circle(process->pos, place_to_jump(arg, 2) + 1);
    return (0);
}