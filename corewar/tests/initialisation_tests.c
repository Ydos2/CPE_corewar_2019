/*
** EPITECH PROJECT, 2020
** initialisation_tests
** File description:
** initialisation_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "vm.h"

Test(set_file_type, test_permission, .timeout = 1)
{
    int return_val = 0;

    return_val = is_a_champion_path("include.cor");
    cr_assert_eq(return_val, 1);
}