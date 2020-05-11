/*
** EPITECH PROJECT, 2020
** parameters
** File description:
** parameters
*/

#include <unistd.h>
#include "vm.h"

int take_param(char *arena, int pos, int bit)
{
    int	result = 0;

    bit = 8 * (bit - 1);
    while (bit >= 0) {
        result = result | (arena[pos] << bit);
        bit -= 8;
        pos = circle(pos, 1);
    }
    return (result);
}

void put_param(arena_t *arena, int pos, int id, int nbr)
{
    int bit = (DIR_SIZE - 1) * 8;

    for (int i = 0; i < DIR_SIZE; i++, bit -= 8) {
        arena->arena[pos] = nbr >> (bit);
        arena->carac[pos] = id;
        pos = circle(pos, 1);
    }
}

static int parameters(char *arena, int pos, int modu, int pc)
{
    int nbr;

    if (modu == 1)
        nbr = take_param(arena, circle(pc, mod(take_param
            (arena, pos, IND_SIZE), IDX_MOD)), DIR_SIZE);
    else
        nbr = take_param(arena, circle(pc, take_param
            (arena, pos, IND_SIZE)), DIR_SIZE);
    return (nbr);
}

int take_what(char *arena, int pos,
    choose_t choix, int *reg)
{
    char arg = this_octet(arena[pos], choix.place);
    int tmp = pos + 1;

    if (choix.place > 1)
        tmp = circle(tmp, place_to_jump(arena[pos], choix.place - 1));
    if (arg == T_REG)
        return (reg[arena[tmp] - 1]);
    if (arg == T_DIR)
        return (take_param(arena, tmp, DIR_SIZE));
    if (arg == T_IND - 1)
        return (parameters(arena, tmp, choix.modu, choix.pc));
    return (0);
}