/*
** EPITECH PROJECT, 2020
** my_xmalloc
** File description:
** my_xmalloc
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

char *my_xrealloc(char *str, int size)
{
    char *output = my_xmalloc(size);
    int i = -1;

    while (str[i++])
        output[i] = str[i];
    output[i] = 0;
    return (output);
}

void *my_xmalloc(int size)
{
    void *ptr = NULL;

    if ((ptr = malloc(size))
        == NULL) {
        write(2, "Malloc error\n", 13);
        exit(84);
    }
    return (ptr);
}