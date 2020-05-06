/*
** EPITECH PROJECT, 2020
** vm
** File description:
** vm
*/

#ifndef VM_H_
#define VM_H_

#define OBJECT_LIST 2

typedef struct process
{
    char live;
    char living;
    int pc_pos;
    int pos;
    int cycle;
    int carry;
    int *reg;
    struct process *next;
    struct process *child;
} process_t;

typedef struct champion
{
    char nbr_champ;
    int *live;
    int last_live;
    int *id_champ;
    char **instruction;
    process_t **process;
} champion_t;

typedef struct arena
{
    champion_t *champion;
    char *arena;
    int cycle;
    int cycle_to_die;
    int total_cycle;
    int total_live;
    int (*func[16])(struct arena *arena,
        process_t *process,
        int id, int pc_pos);
} arena_t;

// vm.c
int vm_start(arena_t *arena, champion_t *champion);

// util_function.c
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);

// arena.c
arena_t *init_arena(arena_t *arena, champion_t *champion);
void print_arena_propertis(arena_t *arena);

// champion.c
champion_t *init_champion(champion_t *champion, int ac, char **av);


#endif /* !VM_H_ */