/*
** EPITECH PROJECT, 2020
** champion
** File description:
** champion
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "vm.h"

static int is_a_champ_path(char *str)
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
        if (is_a_champ_path(av[i]))
            out++;
    return (out);
}

champion_t *init_champion(champion_t *champion, int ac, char **av)
{
    champion = malloc(sizeof(champion_t));
    if ((champion->nbr_champ = count_champ(ac, av)) < 1) {
        write(2, "Not enought champion\n", 21);
        exit(84);
    }
    champion->live = malloc(sizeof(int) * (champion->nbr_champ));
    return (champion);
}