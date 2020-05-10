/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "asm.h"

void destroy_file(char ***file)
{
    for (int i = 0; file[i]; i++) {
        for (int j = 0; file[i][j]; j++)
            free(file[i][j]);
        free(file[i]);
    }
    free(file);
}

void destroy_string_array(char **string_array)
{
    for (int i = 0; string_array[i]; i++)
        free(string_array[i]);
    free(string_array);
}

static char **store_line_in_array(char **last_stock, char *line, int line_size)
{
    char **new;
    int line_nb = 0;
    int j = 0;

    for (; last_stock != NULL && last_stock[line_nb] != NULL; line_nb++);
    new = malloc(sizeof(char *) * (line_nb + 2));
    for (int i = 0; last_stock != NULL && last_stock[i] != NULL; i++)
        new[i] = last_stock[i];
    free(last_stock);
    new[line_nb] = malloc(sizeof(char) * line_size + 2);
    for (; line[j] != 0 && line[j] != '\n'; j++)
        new[line_nb][j] = line[j];
    new[line_nb][j] = 0;
    new[line_nb + 1] = NULL;
    return (new);
}

static char **read_from_stream(FILE *stream)
{
    char *buffer = NULL;
    char **map = NULL;
    size_t size = 0;

    while (size != (size_t) - 1) {
        size = getline(&buffer, &size, stream);
        if (size == (size_t) - 1)
            break;
        map = store_line_in_array(map, buffer, size);
        free(buffer);
        buffer = NULL;
    }
    free(buffer);
    return (map);
}

char ***get_file(char *filename)
{
    char ***file = NULL;
    char **string_array = NULL;
    FILE *stream = NULL;

    stream = open_stream(filename);
    if (!stream)
        return (NULL);
    string_array = read_from_stream(stream);
    fclose(stream);
    if (!string_array)
        return (NULL);
    file = parse_string_array(string_array); // TODO
    destroy_string_array(string_array);
    return (file);
}
