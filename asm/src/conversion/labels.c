/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Tools for labels.
*/

#include <stdlib.h>
#include "asm.h"

static int count_labels(char ***asm_file)
{
    int labels = 0;

    for (int i = 0; asm_file[i]; i++) {
        if (asm_file[i][0] &&
            asm_file[i][0][my_strlen(asm_file[i][0]) - 1] == LABEL_CHAR)
            labels++;
    }
    return (labels);
}

label_t *get_blank_labels(char ***asm_file)
{
    label_t *labels = NULL;
    int len = 0;

    len = count_labels(asm_file);
    labels = malloc(sizeof(label_t) * (len + 1));
    if (!labels)
        return (NULL);
    for (int i = 0; i <= len; i++) {
        labels[i].index = 0;
        labels[i].name = NULL;
    }
    return (labels);
}

void add_label(label_t **labels, int index, char *line)
{
    int end = 0;

    for (; (*labels)[end].name; end++);
    (*labels)[end].index = index;
    (*labels)[end].name = line;
}