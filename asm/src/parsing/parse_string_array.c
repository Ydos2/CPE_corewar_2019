/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Converts an array of lines into an array of word arrays.
*/

#include <stdlib.h>
#include "asm.h"

static int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i]; i++) {
        if (c == separators[i])
            return (1);
    }
    return (0);
}

static char *get_str_until(char **str, char *separators)
{
    char *new_str = NULL;
    int len = 0;

    for (; (*str)[len] && !is_separator((*str)[len], separators); len++);
    new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (NULL);
    for (int i = 0; i < len; i++, (*str)++)
        new_str[i] = **str;
    new_str[len] = 0;
    for (; is_separator(**str, separators); (*str)++);
    return (new_str);
}

static int get_nbr_of_parts(char *line, char *separ)
{
    int nbr_of_parts = 0;

    for (int i = 1; line[i]; i++) {
        if (is_separator(line[i], separ) && !is_separator(line[i - 1], separ))
            nbr_of_parts++;
    }
    nbr_of_parts++;
    return (nbr_of_parts);
}

static char **parse_line(char *line)
{
    char **parsed_line = NULL;
    int len = 0;

    len = get_nbr_of_parts(line, " ,");
    if (len <= 0)
        return (NULL);
    parsed_line = malloc(sizeof(char *) * (len + 1));
    if (!parsed_line)
        return (NULL);
    for (int i = 0; i < len; i++) {
        parsed_line[i] = get_str_until(&line, " ,");
        if (!(parsed_line[i])) {
            destroy_string_array(parsed_line);
            return (NULL);
        }
        parsed_line[i + 1] = NULL;
    }
    return (parsed_line);
}

char ***parse_string_array(char **string_array)
{
    char ***file = NULL;
    int len = 0;

    for (; string_array[len]; len++);
    file = malloc(sizeof(char **) * (len + 1));
    if (!file)
        return (NULL);
    for (int i = 0; i < len; i++) {
        file[i] = parse_line(string_array[i]);
        if (!(file[i])) {
            destroy_file(file);
            return (NULL);
        }
        file[i + 1] = NULL;
    }
    return (file);
}