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

choose_t choose(int pc, char modu, char place)
{
    choose_t nbr;

    nbr.pc = pc;
    nbr.modu = modu;
    nbr.place = place;
    return (nbr);
}