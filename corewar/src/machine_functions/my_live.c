/*
** EPITECH PROJECT, 2020
** my_live
** File description:
** my_live
*/

#include <unistd.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

static int check_proprio(char *proprio, int pos, char size, int *id)
{
    int said = proprio[pos];
    int i = 0;

    if (said == -1)
        return (-1);
    while (i < size) {
        if (said == id[i])
            return (i);
        i++;
    }
    return (-1);
}

static void champion_is_here(int who_said, arena_t *arena,
    champion_t *champion, process_t *process)
{
    if (who_said != -1) {
        my_putstr("Player ");
        my_putnbr(champion->id_champion[who_said]);
        my_putstr(" called ");
        my_putstr(champion->header[who_said].prog_name);
        my_putstr(" is alive !\n");
        champion->last_live = who_said;
        champion->live[who_said] = 1;
        process->living = 1;
        arena->total_live++;
        arena->nbr_live++;
    }
}

int my_live(arena_t *arena, process_t *process, int id, int pc_pos)
{
    champion_t *champion;
    int who_said;
    int tmp;

    (void)id;
    champion = arena->champion;
    process->pos = circle(process->pos, 1);
    process->cycle += op_tab[0].nbr_cycles;
    tmp = take_param(arena->arena, process->pos, DIR_SIZE);
    tmp = circle(pc_pos, tmp);
    who_said = check_proprio(arena->carac, tmp,
        champion->nbr_champion, champion->id_champion);
    champion_is_here(who_said, arena, champion, process);
    return (0);
}