/*
** EPITECH PROJECT, 2020
** my_aff
** File description:
** my_aff
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_aff(arena_t *arena, process_t *process, int id, int pc_pos)
{
    int reg;
    char arg;

    (void)pc_pos;
    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 15, process->pos, 1) == -1)
        return (0);
    process->cycle += op_tab[15].nbr_cycles;
    reg = process->reg[arena->arena[circle(process->pos, 1)] - 1];
    reg = reg % 256;
    my_putnbr(reg);
    process->pos = circle(process->pos, place_to_jump(arg, 1) + 1);
    return (0);
}