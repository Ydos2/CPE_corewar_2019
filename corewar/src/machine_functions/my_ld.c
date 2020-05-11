/*
** EPITECH PROJECT, 2020
** my_ld
** File description:
** my_ld
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_ld(arena_t *arena, process_t *process, int id, int pc_pos)
{
    char arg;
    int nbr;
    int reg;

    (void)id;
    process->pos = circle(process->pos, 1);
    arg = arena->arena[process->pos];
    if (check_mult_args(arena->arena, 1, process->pos, 2) == -1)
        return (0);
    process->cycle += op_tab[1].nbr_cycles;
    process->carry = (process->carry == 1) ? 0 : 1;
    nbr = take_what(arena->arena, process->pos,
        choose(pc_pos, 1, 1), process->reg);
    reg = arena->arena[circle(process->pos, octet_to_read(arg, 1) + 1)];
    process->reg[reg - 1] = nbr;
    process->pos = circle(process->pos, place_to_jump(arg, 2) + 1);
    return (0);
}