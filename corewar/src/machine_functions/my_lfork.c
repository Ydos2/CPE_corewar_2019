/*
** EPITECH PROJECT, 2020
** my_lfork
** File description:
** my_lfork
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

int my_lfork(arena_t *arena, process_t *process, int id, int pc_pos)
{
    process_t *tmp;

    (void)id;
    process->pos = circle(process->pos, 1);
    process->carry = (process->carry == 1) ? 0 : 1;
    process->cycle += op_tab[14].nbr_cycles;
    tmp = add_child(process);
    cpy_register(tmp, process);
    tmp->pos = circle(pc_pos, take_param(
        arena->arena, process->pos, DIR_SIZE));
    tmp->pc_pos = tmp->pos;
    process->pos = circle(process->pos, DIR_SIZE);
    return (0);
}