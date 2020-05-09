/*
** EPITECH PROJECT, 2020
** machine_functions
** File description:
** machine_functions
*/

#ifndef MACHINE_FUNCTIONS_H_
#define MACHINE_FUNCTIONS_H_

int my_add(arena_t *arena, process_t *process, int id, int pc_pos);
int my_aff(arena_t *arena, process_t *process, int id, int pc_pos);
int my_and(arena_t *arena, process_t *process, int id, int pc_pos);
int my_fork(arena_t *arena, process_t *process, int id, int pc_pos);
int my_ld(arena_t *arena, process_t *process, int id, int pc_pos);
int my_ldi(arena_t *arena, process_t *process, int id, int pc_pos);
int my_lfork(arena_t *arena, process_t *process, int id, int pc_pos);
int my_live(arena_t *arena, process_t *process, int id, int pc_pos);
int my_lld(arena_t *arena, process_t *process, int id, int pc_pos);
int my_lldi(arena_t *arena, process_t *process, int id, int pc_pos);
int my_or(arena_t *arena, process_t *process, int id, int pc_pos);
int my_st(arena_t *arena, process_t *process, int id, int pc_pos);
int my_sti(arena_t *arena, process_t *process, int id, int pc_pos);
int my_sub(arena_t *arena, process_t *process, int id, int pc_pos);
int my_xor(arena_t *arena, process_t *process, int id, int pc_pos);
int my_zjump(arena_t *arena, process_t *process, int id, int pc_pos);

#endif /* !MACHINE_FUNCTIONS_H_ */