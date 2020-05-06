/*
** EPITECH PROJECT, 2020
** arena
** File description:
** arena
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

static void init_function_machine(arena_t *arena)
{
    arena->func[0] = my_live;
    arena->func[1] = my_ld;
    arena->func[2] = my_st;
    arena->func[3] = my_add;
    arena->func[4] = my_sub;
    arena->func[5] = my_and;
    arena->func[6] = my_or;
    arena->func[7] = my_xor;
    arena->func[8] = my_zjump;
    arena->func[9] = my_ldi;
    arena->func[10] = my_sti;
    arena->func[11] = my_fork;
    arena->func[12] = my_lld;
    arena->func[13] = my_lldi;
    arena->func[14] = my_lfork;
    arena->func[15] = my_aff;
}

arena_t *init_arena(arena_t *arena, champion_t *champion)
{
    arena = malloc(sizeof(arena_t));
    arena->champion = champion;
    arena->cycle_to_die = CYCLE_TO_DIE;
    arena->total_cycle = 0;
    arena->total_live = 0;
    init_function_machine(arena);
    return (arena);
}

void print_arena_propertis(arena_t *arena)
{
    (void)arena;
}