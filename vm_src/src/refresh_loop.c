/*
** EPITECH PROJECT, 2020
** refresh_loop
** File description:
** refresh_loop
*/

#include <unistd.h>
#include "vm.h"

void pick_function(arena_t *arena, process_t *proc, int id)
{
    if (proc->cycle == 0) {
        if (arena && arena->arena[proc->pos] >= 1 &&
        arena->arena[proc->pos] <= 16)
            arena->func[arena->arena[proc->pos] - 1]
            (arena, proc, id, proc->pc_pos);
        else
            proc->pos = circle(proc->pos, 1);
    } else
        proc->cycle--;
}

void refresh_process(process_t *proc)
{
    process_t *tmp = proc;

    while (tmp != NULL) {
        proc->live = proc->living;
        proc->living = 0;
        if (tmp->child != NULL)
            refresh_process(tmp->child);
        tmp = tmp->next;
    }
}

void refresh_process_loop(arena_t *arena)
{
    int i = -1;

    while (++i < arena->champion->nbr_champion)
        refresh_process(arena->champion->process[i]);
    arena->nbr_live = 0;
}