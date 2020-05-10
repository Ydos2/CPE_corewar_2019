/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm : header.
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdio.h>
#include <unistd.h>
#include "op.h"

// asm_utils.c
int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
int is_int_until(char *str, char end);
int get_nbr_until(char *str, char end);
void my_put_nbr(int nbr, int file_descr);

/*           PARSING               */

// open_stream.c
FILE *open_stream(char *filename);

// read_file.c
void destroy_file(char ***file);
char ***get_file(char *filename);

/*           ERROR HANDLING        */

// check_asm_line.c
int is_label_char(char c);
int is_valid_asm_line(char **line);

// check_argument.c
int is_valid_argument(int op_index, char *arg, int arg_index);

/*           CONVERSION            */

// translate_asm.c
int translate_asm_file(char ***asm_file, char *filename);

#endif /* !ASM_H_ */
