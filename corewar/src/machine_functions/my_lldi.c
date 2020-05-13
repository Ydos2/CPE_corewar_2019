/*
** EPITECH PROJECT, 2020
** my_lldi
** File description:
** my_lldi
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_lldi(arena_t *arena, process_t *process, int id, int pc_pos)
{
    int s;
    int ind;
    char arg;

    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 13, process->pos, 3) == -1)
        return (0);
    process->cycle += op_tab[13].nbr_cycles;
    process->carry = (process->carry == 1) ? 0 : 1;
    s = take_what(arena->arena, process->pos,
        choose(pc_pos, 0, 1), process->reg);
    s += take_what(arena->arena, process->pos,
        choose(pc_pos, 0, 2), process->reg);
    ind = arena->arena[circle(process->pos, place_to_jump(arg, 2) + 1)];
    s = take_param(arena->arena, circle(pc_pos, s), DIR_SIZE);
    process->reg[ind - 1] = s;
    process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
    return (0);
}