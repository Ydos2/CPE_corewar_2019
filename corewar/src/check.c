/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include <unistd.h>
#include "vm.h"

int check_arg(int funct, int pos, char arg)
{
    char def = op_tab[funct].type[pos];

    if (T_LAB == arg && def / T_LAB == 1)
        return (1);
    def %= T_LAB;
    if (T_IND - 1 == arg && def / (T_IND) == 1)
        return (1);
    def %= T_IND;
    if (T_DIR == arg && def / T_DIR == 1)
        return (1);
    def %= T_DIR;
    if (T_REG == arg && def / T_REG == 1)
        return (1);
    return (-1);
}

static int verif_octet(char param, int funct, int size)
{
    char cur = 0;

    for (int pos = 7, result; cur < size; cur++, pos--) {
        result = 2 * ((param >> pos) & 1);
        pos--;
        result = result + ((param >> pos) & 1);
        if (check_arg(funct, cur, result) == -1)
            return (-1);
    }
    return (1);
}

static int check_reg(int reg)
{
    if (reg < 1 || reg > REG_NUMBER)
        return (-1);
    return (reg);
}

int check_mult_args(char *arena, int fun, int pos, int size)
{
    char arg = arena[pos];
    char tmp;

    if (verif_octet(arg, fun, size) == -1)
        return (-1);
    pos = circle(pos, 1);
    for (int turn = 1; turn <= size; turn++) {
        tmp = this_octet(arg, turn);
        if (tmp == T_REG) {
            if (check_reg(arena[pos]) == -1)
                return (-1);
        }
        pos = circle(pos, octet_to_r(tmp));
    }
    return (0);
}