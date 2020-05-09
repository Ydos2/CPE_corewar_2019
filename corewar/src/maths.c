/*
** EPITECH PROJECT, 2020
** maths
** File description:
** maths
*/

#include <unistd.h>
#include "vm.h"

int mod(int nbr, int modulo)
{
    nbr = nbr % modulo;
    if (nbr < 0)
        nbr = modulo + nbr;
    return (nbr);
}

int circle(int pos, int incr)
{
    pos = pos + incr;
    pos = mod(pos, MEM_SIZE);
    return (pos);
}

/*t_choix make_choix(int pc, char modu, char place)
{
    t_choix	result;

    result.pc = pc;
    result.modu = modu;
    result.place = place;
    return (result);
}*/