/*
** EPITECH PROJECT, 2020
** register
** File description:
** register
*/

#include <unistd.h>
#include "vm.h"

static process_t *create_list(void)
{
    process_t *process;

    process = my_xmalloc(sizeof(process_t));
    process->child = NULL;
    process->next = NULL;
    return (process);
}

static void init_child(process_t *father, process_t *child)
{
    child->carry = father->carry;
    child->live = father->live;
    child->living = father->living;
    child->cycle = father->cycle;
}

process_t *add_child(process_t *father)
{
    process_t *tmp;
    process_t *child = create_list();

    init_child(father, child);
    if (father->child == NULL)
        father->child = child;
    else {
        tmp = father->child;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = child;
    }
    return (child);
}

void cpy_register(process_t *child, process_t *parent)
{
    int pos = -1;

    child->reg = my_xmalloc(sizeof(int) * REG_NUMBER);
    while (++pos < REG_NUMBER)
        child->reg[pos] = parent->reg[pos];
}