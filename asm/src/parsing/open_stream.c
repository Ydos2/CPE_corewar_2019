/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Opens a .s file.
*/

#include <stdlib.h>
#include "asm.h"

static char *get_filepath(char *filename)
{
    char *filepath = NULL;
    int filename_len = 0;
    int filepath_len = 0;

    filename_len = my_strlen(filename);
    filepath_len = filename_len;
    if (filename[filename_len - 2] != '.' || filename[filename_len - 1] != 's')
        filepath_len += 2;
    filepath = malloc(sizeof(char) * (filepath_len + 1));
    if (!filepath)
        return (NULL);
    for (int i = 0; i < filename_len; i++)
        filepath[i] = filename[i];
    if (filepath_len != filename_len) {
        filepath[filepath_len - 2] = '.';
        filepath[filepath_len - 1] = 's';
    }
    filepath[filepath_len] = 0;
    return (filepath);
}

FILE *open_stream(char *filename)
{
    FILE *stream = NULL;
    char *filepath = NULL;

    filepath = get_filepath(filename);
    if (!filepath)
        return (NULL);
    stream = fopen(filepath, "r");
    free(filepath);
    if (!stream)
        write(2, "Error : .s file could not be opened.\n", 37);
    return (stream);
}