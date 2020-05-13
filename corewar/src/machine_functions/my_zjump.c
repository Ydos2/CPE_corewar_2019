/*
** EPITECH PROJECT, 2020
** my_zjump
** File description:
** my_zjump
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_zjump(arena_t *arena, process_t *process, int id, int pc_pos)
{
    (void)id;
    process->pos = circle(process->pos, 1);
    process->cycle += op_tab[8].nbr_cycles;
    if (process->carry == 1)
        process->pc_pos = circle(pc_pos,
        mod(take_param(arena->arena, process->pos, IND_SIZE), IDX_MOD));
    else
        process->pos = circle(process->pos, octet_to_r(3) + 1);
    return (0);
}