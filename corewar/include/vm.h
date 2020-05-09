/*
** EPITECH PROJECT, 2020
** vm
** File description:
** vm
*/

#ifndef VM_H_
#define VM_H_

#include "op.h"

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
    char nbr_champion;
    int *live;
    int last_live;
    int *id_champion;
    char **instruction;
    header_t *header;
    process_t **process;
} champion_t;

typedef struct arena
{
    champion_t *champion;
    char *arena;
    char *carac;
    int cycle;
    int cycle_to_die;
    int total_cycle;
    int total_live;
    int nbr_live;
    int (*func[16])(struct arena *arena,
        process_t *process,
        int id, int pc_pos);
} arena_t;

// vm.c
void launch_process(process_t *process, arena_t *arena, int id);
int vm_start(arena_t *arena);

// util_function.c
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);

// arena.c
arena_t *init_arena(arena_t *arena, champion_t *champion);

// print_arena_carac.c
void print_arena_carac(arena_t *arena);

// champion.c
int is_a_champion_path(char *str);
champion_t *init_champion(champion_t *champion, int ac, char **av);

// my_xmalloc.c
char *my_xrealloc(char *str, int size);
void *my_xmalloc(int size);

// my_xopen.c
int my_xopen(char *path);

// my_memset.c
void my_memset(void *ptr, int size, char c);

// my_putnbr.c
int my_putnbr(int nb);

// my_getnbr.c
int my_getnbr(const char *str);

// my_putstr.c
int my_putstr(char const *str);

// process.c
process_t *initialise_process(int pos, int id);
void free_process(process_t *process);
int load_process(champion_t *champion, int ac, char **av);

// header.c
header_t get_header(int fd);

// id.c
void check_id(champion_t *champion);
int get_id(int *read_id_needed, int i, char **av);
int is_a_id_request(char *str);

// instruction.c
char *get_instruction(int fd, int size);

// end_vm.c
void end_vm(arena_t *arena);

// refresh_loop.c
void pick_function(arena_t *arena, process_t *proc, int id);
void refresh_process(process_t *proc);
void refresh_process_loop(arena_t *arena);

// maths.c
//t_choix make_choix(int pc, char modu, char place);
int circle(int pos, int incr);
int mod(int nbr, int modulo);

#endif /* !VM_H_ */