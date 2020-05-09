/*
** EPITECH PROJECT, 2020
** id
** File description:
** id
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

int is_a_id_request(char *str)
{
    if (str[0] == '-' &&
        str[1] == 'n' &&
        str[2] == '\0')
        return (1);
    return (0);
}

int get_id(int *read_id_needed, int i, char **av)
{
    int out;

    if (*read_id_needed)
        out = my_getnbr(av[i - 1]);
    else
        out = -1;
    *read_id_needed = 0;
    return (out);
}

static int is_id_taken(int *id_tab, int id, int size)
{
    int i = -1;

    while (++i < size) {
        if (id_tab[i] == id)
            return (1);
    }
    return (0);
}

static int loop_taken(champion_t *champion, int i, int id)
{
    while (is_id_taken(champion->id_champion,
        ++id, champion->nbr_champion));
    champion->id_champion[i] = id;
    return (id);
}

void check_id(champion_t *champion)
{
    int i = -1;
    int id = -1;

    while (++i < champion->nbr_champion) {
        if (champion->id_champion[i] == -1)
            id = loop_taken(champion, i, id);
    }
    i = -1;
    while (++i < champion->nbr_champion)
        champion->process[i] = initialise_process(MEM_SIZE /
        champion->nbr_champion * i, champion->id_champion[i]);
}