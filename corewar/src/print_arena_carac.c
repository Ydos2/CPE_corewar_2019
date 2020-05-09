/*
** EPITECH PROJECT, 2020
** print_arena_carac
** File description:
** print_arena_carac
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "op.h"
#include "vm.h"
#include "machine_functions.h"

static void print_start(void)
{
    int i = -1;

    write(1, "|", 1);
    while (++i < 128)
        write(1, "-", 1);
    write(1, "|\n|", 3);
}

static void print_end(void)
{
    int i = -1;

    while (++i < 128)
        write(1, "-", 1);
    write(1, "|\n", 2);
}

static void print_arena(arena_t *arena, int i)
{
    switch (arena->carac[i - 1]) {
        case -1:
            write(1, " ", 1);
            break;
        case 0:
            write(1, "#1", 2);
            my_putnbr(arena->carac[i - 1]);
            break;
        case 1:
            write(1, "#2", 2);
            my_putnbr(arena->carac[i - 1]);
            break;
        case 2:
            write(1, "#3", 2);
            my_putnbr(arena->carac[i - 1]);
            break;
        case 3:
            write(1, "#4", 2);
            my_putnbr(arena->carac[i - 1]);
    }
}

void print_arena_carac(arena_t *arena)
{
    print_start();
    for (int i = 0, j = 1; i++ <= MEM_SIZE;) {
        print_arena(arena, i);
        if (i % (128 * j) == 0) {
            j++;
            write(1, "|\n|", 3);
        }
    }
    print_end();
}