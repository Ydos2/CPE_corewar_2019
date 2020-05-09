/*
** EPITECH PROJECT, 2020
** process
** File description:
** process
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

static void create_registre(process_t *process, int id)
{
    int pos = 0;

    process->reg = my_xmalloc(sizeof(int) * REG_NUMBER);
    process->reg[0] = id;
    while (pos++ < REG_NUMBER)
        process->reg[pos] = 0;
}

process_t *initialise_process(int pos, int id)
{
    process_t *proc;

    proc = my_xmalloc(sizeof(process_t));
    proc->live = 1;
    proc->living = 0;
    proc->pos = pos;
    proc->pc_pos = pos;
    proc->cycle = 0;
    proc->carry = 0;
    create_registre(proc, id);
    proc->next = NULL;
    proc->child = NULL;
    return (proc);
}

void free_process(process_t *process)
{
    process_t *tmp;

    while (process != NULL) {
        free(process->reg);
        if (process->child != NULL)
            free_process(process->child);
        tmp = process;
        process = process->next;
        free(tmp);
    }
}

static int process_loop(champion_t *champion, int j)
{
    if (champion->header[j].prog_size > MEM_SIZE / 4) {
        write(2, "Error, size of the program is too big\n", 38);
        return (84);
    }
    return (0);
}

int load_process(champion_t *champion, int ac, char **av)
{
    int i = -1;
    int j = (i = -1) * 0;

    for (int read_id_needed = 0, fd = 0, rnt = 0; ++i < ac;) {
        i += (read_id_needed = is_a_id_request(av[i])) * 2;
        if (is_a_champion_path(av[i])) {
            fd = my_xopen(av[i]);
            champion->id_champion[j] = get_id(&read_id_needed, i, av);
            champion->header[j] = get_header(fd);
            rnt = process_loop(champion, j);
            champion->instruction[j] = get_instruction
                (fd, champion->header[j].prog_size);
            close(fd);
            j++;
        }
        if (rnt == 84)
            return (84);
    }
    check_id(champion);
}