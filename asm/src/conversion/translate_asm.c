/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Translates a .s file into a .cor file.
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

static char *get_new_filename(char *filename)
{
    char *new_filename = NULL;
    char *extension = ".cor";
    int len = 0;
    int new_len = 0;

    len = my_strlen(filename);
    new_len = len + 2;
    if (filename[len - 2] != '.' || filename[len - 1] != 's')
        new_len += 2;
    new_filename = malloc(sizeof(char) * (new_len + 1));
    if (!new_filename)
        return (NULL);
    for (int i = 0; i < new_len - 4; i++)
        new_filename[i] = filename[i];
    if (new_len != len) {
        for (int i = 0; i < 4; i++)
            new_filename[i + new_len - 4] = extension[i];
    }
    new_filename[new_len] = 0;
    return (new_filename);
}

static int bin_open_stream(char *filename)
{
    char *new_filename = NULL;
    int fd = 0;

    new_filename = get_new_filename(filename);
    if (!new_filename)
        return (84);
    fd = open(new_filename, O_WRONLY | O_TRUNC | O_CREAT);
    free(new_filename);
    return (fd);
}

static int get_index_1st_line_of_code(char ***file)
{
    int index = 10;

    // TODO

    return (index);
}

int translate_asm_file(char ***asm_file, char *filename)
{
    header_t header;
    int fd = 0;
    int return_value = 0;
    int i = 0;

    init_header(&header);
    if (!is_valid_asm_file(asm_file, &header))
        return (84);
    fd = bin_open_stream(filename);
    if (fd == -1)
        return (84);
    i = get_index_1st_line_of_code(asm_file);
    if (translate_header(&header, &(asm_file[i]), fd) == 84) {
        close(fd);
        return (84);
    }
    for (; asm_file[i] && return_value != 84; i++)
        return_value = translate_asm_line(asm_file[i], fd);
    close(fd);
    return (return_value);
}