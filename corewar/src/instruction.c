/*
** EPITECH PROJECT, 2020
** instruction
** File description:
** instruction
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

char *get_instruction(int fd, int size)
{
    char *instruction = my_xmalloc(size + 10);

    if ((read(fd, instruction, size + 10)) < 0) {
        write(2, "I don't read requested champion\n", 32);
        exit(84);
    }
    return (instruction);
}