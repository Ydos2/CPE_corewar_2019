/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Converts an array of lines into an array of word arrays.
*/

#include <stdlib.h>
#include "asm.h"

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
    if (**str != COMMENT_CHAR)
        (*str)++;
    return (new_str);
}

static int get_nbr_of_parts(char *line, char *separ)
{
    int nbr_of_parts = 0;

    if (strcmp_until(line, ".name ", '"') == 0 ||
        strcmp_until(line, ".comment ", '"') == 0)
        return (2);
    for (int i = 0; line[i]; i++) {
        if (i != 0 && is_separator(line[i], separ) &&
            !is_separator(line[i - 1], separ))
            nbr_of_parts++;
        if (line[i] == COMMENT_CHAR) {
            nbr_of_parts = (i == 0) ? nbr_of_parts : nbr_of_parts + 1;
            break;
        }
    }
    nbr_of_parts++;
    return (nbr_of_parts);
}

static char **allocate_mem_for_parsed_line(char *line, int *len)
{
    char **parsed_line = NULL;

    *len = get_nbr_of_parts(line, " ,");
    if (*len <= 0)
        return (NULL);
    parsed_line = malloc(sizeof(char *) * (*len + 1));
    return (parsed_line);
}

static char **parse_line(char *line)
{
    char **parsed_line = NULL;
    int len = 0;
    char separators[4] = {' ', ',', COMMENT_CHAR, 0};

    parsed_line = allocate_mem_for_parsed_line(line, &len);
    if (!parsed_line)
        return (NULL);
    for (int i = 0; i < len - 1; i++) {
        parsed_line[i] = get_str_until(&line, separators);
        if (!(parsed_line[i])) {
            destroy_string_array(parsed_line);
            return (NULL);
        }
        parsed_line[i + 1] = NULL;
    }
    parsed_line[len - 1] = get_str_until(&line, &(separators[3]));
    parsed_line[len] = NULL;
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