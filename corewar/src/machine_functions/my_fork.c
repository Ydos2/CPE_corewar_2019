/*
** EPITECH PROJECT, 2020
** my_fork
** File description:
** my_fork
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_fork(arena_t *arena, process_t *process, int id, int pc_pos)
{
    process_t *tmp;

    (void)id;
    process->pos = circle(process->pos, 1);
    process->cycle += op_tab[11].nbr_cycles;
    tmp = add_child(process);
    cpy_register(tmp, process);
    tmp->pos = circle(pc_pos, mod(take_param(
        arena->arena, process->pos, DIR_SIZE), IDX_MOD));
    tmp->pc_pos = tmp->pos;
    process->pos = circle(process->pos, DIR_SIZE);
    return (0);
}