/*
** EPITECH PROJECT, 2020
** vm
** File description:
** vm
*/

#include <unistd.h>
#include "vm.h"

static int how_much_alive(champion_t *champion)
{
    int i = -1;
    int count = 0;

    while (++i < champion->nbr_champion) {
        if (champion->live[i] == 1)
            count++;
        champion->live[i] = 0;
    }
    return (count);
}

void launch_process(process_t *process, arena_t *arena, int id)
{
    process_t *tmp = process;

    while (tmp != NULL) {
        if (arena->nbr_live >= NBR_LIVE) {
            refresh_process_loop(arena);
            if (how_much_alive(arena->champion) < 2)
                vm_start(arena);
            arena->cycle = 0;
            arena->cycle_to_die -= CYCLE_DELTA;
        }
        pick_function(arena, process, id);
        if (tmp->child != NULL && tmp->child->live == 1)
            launch_process(tmp->child, arena, id);
        tmp = tmp->next;
    }
}

static void loop_champ(arena_t *arena)
{
    int i = -1;

    while (++i < arena->champion->nbr_champion) {
        if (arena->champion->process[i]->live == 1)
            launch_process(arena->champion->process[i], arena, i);
    }
}

int vm_start(arena_t *arena)
{
    arena->cycle_to_die = CYCLE_TO_DIE;
    while (arena->cycle_to_die > 0) {
        arena->cycle = 0;
        while (arena->cycle < arena->cycle_to_die) {
            loop_champ(arena);
            arena->total_cycle++;
            arena->cycle++;
        }
        refresh_process_loop(arena);
        if (how_much_alive(arena->champion) < 2)
            end_vm(arena);
        arena->cycle_to_die -= CYCLE_DELTA;
    }
    end_vm(arena);
    return (0);
}