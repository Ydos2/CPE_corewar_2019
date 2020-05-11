/*
** EPITECH PROJECT, 2020
** CPe_corewar_2019
** File description:
** Parsing utils.
*/

#include <stdlib.h>
#include "asm.h"

int is_label_char(char c)
{
    for (int i = 0; LABEL_CHARS[i]; i++) {
        if (c == LABEL_CHARS[i])
            return (1);
    }
    return (0);
}

int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i]; i++) {
        if (c == separators[i])
            return (1);
    }
    return (0);
}

void destroy_string_array(char **string_array)
{
    for (int i = 0; string_array[i]; i++)
        free(string_array[i]);
    free(string_array);
}

void destroy_file(char ***file)
{
    for (int i = 0; file[i]; i++)
        destroy_string_array(file[i]);
    free(file);
}

int strcmp_until(char *str1, char *str2, char end)
{
    int i = 0;

    for (; str1[i] && str2[i] && str1[i] != end && str2[i] != end; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    if (str1[i] == end || str2[i] == end)
        return (0);
    return (str1[i] - str2[i]);
}