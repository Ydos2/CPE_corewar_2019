/*
** EPITECH PROJECT, 2020
** arena
** File description:
** arena
*/

#include <stdlib.h>
#include <unistd.h>
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

static void battle(arena_t *arena, champion_t *champion)
{
    int nb_champion = -1;
    int i;

    while (nb_champion++ < champion->nbr_champion) {
        i = -1;
        while (++i < champion->header[nb_champion].prog_size) {
            arena->arena[i + champion->process[nb_champion]->pc_pos]
                = champion->instruction[nb_champion][i];
            arena->carac[i + champion->process[nb_champion]->pc_pos]
                = champion->id_champion[nb_champion];
        }
    }
}

arena_t *init_arena(arena_t *arena, champion_t *champion)
{
    arena = malloc(sizeof(arena_t));
    arena->champion = champion;
    arena->arena = my_xmalloc(sizeof(char) * MEM_SIZE);
    my_memset(arena->arena, MEM_SIZE, 0);
    arena->carac = my_xmalloc(sizeof(char) * MEM_SIZE);
    my_memset(arena->carac, MEM_SIZE, -1);
    battle(arena, champion);
    arena->cycle_to_die = CYCLE_TO_DIE;
    arena->total_cycle = 0;
    arena->total_live = 0;
    init_function_machine(arena);
    return (arena);
}