/*
** EPITECH PROJECT, 2020
** champion
** File description:
** champion
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

int is_a_champion_path(char *str)
{
    if (str[my_strlen(str) - 1] == 'r' &&
        str[my_strlen(str) - 2] == 'o' &&
        str[my_strlen(str) - 3] == 'c' &&
        str[my_strlen(str) - 4] == '.')
        return (1);
    return (0);
}

static int count_champ(int ac, char **av)
{
    int out = 0;

    for (int i = 0; i < ac; i++)
        if (is_a_champion_path(av[i]))
            out++;
    return (out);
}

champion_t *init_champion(champion_t *champion, int ac, char **av)
{
    int i = -1;

    champion = malloc(sizeof(champion_t));
    if ((champion->nbr_champion = count_champ(ac, av)) < 1) {
        write(2, "Not enought champion\n", 21);
        exit(84);
    }
    champion->live = my_xmalloc(sizeof(int) * (champion->nbr_champion));
    while (++i < champion->nbr_champion)
        champion->live[i] = 0;
    champion->id_champion = my_xmalloc(sizeof(int) * (champion->nbr_champion));
    champion->header = my_xmalloc(sizeof(header_t) * (champion->nbr_champion));
    champion->instruction = my_xmalloc(sizeof(char *)
        * (champion->nbr_champion));
    champion->process = my_xmalloc(sizeof(process_t *)
        * (champion->nbr_champion));
    if (load_process(champion, ac, av) == 84)
        exit(84);
    return (champion);
}