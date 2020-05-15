/*
** EPITECH PROJECT, 2020
** initialisation_tests
** File description:
** initialisation_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "vm.h"

Test(vm_start, test_vm, .timeout = 1)
{
    champion_t *champion = malloc(sizeof(champion_t));
    arena_t *arena = malloc(sizeof(arena_t));
    int rtn = 0;
    char *array_result[] = {
        "./corewar",
        "../bonus/42.cor",
        "../bonus/abel.cor",
        "../bonus/bill.cor",
    };

    init_champion(champion, 4, array_result);
    init_arena(arena, champion);
    print_arena_carac(arena);
    rtn = vm_start(arena);
    cr_assert_eq(rtn, 0);
}

Test(display, test_print, .timeout = 1)
{
    champion_t *champion = malloc(sizeof(champion_t));
    arena_t *arena = malloc(sizeof(arena_t));
    int rtn = 0;
    char *array_result[] = {
        "./corewar",
        "../bonus/42.cor",
        "../bonus/abel.cor",
        "../bonus/bill.cor",
    };

    init_champion(champion, 4, array_result);
    init_arena(arena, champion);
    rtn = print_arena_carac(arena);
    cr_assert_eq(rtn, 0);
}

Test(initialise_arena, test_structure_2, .timeout = 1)
{
    champion_t *champion = malloc(sizeof(champion_t));
    arena_t *arena = malloc(sizeof(arena_t));
    char *array_result[] = {
        "./corewar",
        "../bonus/42.cor",
        "../bonus/abel.cor",
        "../bonus/bill.cor",
    };

    init_champion(champion, 4, array_result);
    init_arena(arena, champion);
    cr_assert_eq(arena->total_cycle, 0);
}

Test(initialise_champion, test_structure_1, .timeout = 1)
{
    champion_t *champion = malloc(sizeof(champion_t));
    char *array_result[] = {
        "./corewar",
        "../bonus/42.cor",
        "../bonus/abel.cor",
        "../bonus/bill.cor",
    };

    init_champion(champion, 4, array_result);
    cr_assert_eq(champion->live, 0);
}

Test(set_file_type, test_permission, .timeout = 1)
{
    int return_val = 0;

    return_val = is_a_champion_path("include.cor");
    cr_assert_eq(return_val, 1);
}