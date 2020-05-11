/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Translates a .s file into a .cor file.
*/

#include "asm.h"

static int translate_asm_line(char **line, int cor_fd)
{
    // TODO
    return (0);
}

static void init_header(header_t *header)
{
    header->magic = 0;
    header->prog_size = 0;
    for (int i = 0; i <= PROG_NAME_LENGTH; i++)
        header->prog_name[i] = 0;
    for (int i = 0; i <= COMMENT_LENGTH; i++)
        header->comment[i] = 0;
}

int translate_asm_file(char ***asm_file, char *filename)
{
    header_t header;

    init_header(&header);
    if (!is_valid_asm_file(asm_file, &header))
        return (84);
    for (int i = 0; asm_file[i]; i++) {
        // translate_asm_line(asm_file[i], cor_fd);
    }
    return (0);
}