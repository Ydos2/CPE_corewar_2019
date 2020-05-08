/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** my_memset
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

void my_memset(void *ptr, int size, char c)
{
    int i = -1;
    char *buf = ptr;

    while (++i < size)
        buf[i] = c;
}