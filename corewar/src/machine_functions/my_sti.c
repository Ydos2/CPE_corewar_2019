/*
** EPITECH PROJECT, 2020
** my_sti
** File description:
** my_sti
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_sti(arena_t *arena, process_t *process, int id, int pc_pos)
{
    int a;
    int b;
    int c;
    char arg;

    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 10, process->pos, 3) == -1)
        return (0);
    process->cycle += op_tab[10].nbr_cycles;
    a = process->reg[arena->arena[circle(process->pos, 1)] - 1];
    b = take_what(arena->arena, process->pos, choose(pc_pos, 0, 2),
        process->reg);
    c = take_what(arena->arena, process->pos, choose(pc_pos, 0, 3),
        process->reg);
    put_param(arena, circle(pc_pos, b + c),
        arena->champion->id_champion[id], a);
    process->pos = circle(process->pos, place_to_jump(arg, 3) + 1);
    return (0);
}