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

// parsing_utils.c
int is_label_char(char c);
int is_separator(char c, char *separators);
void destroy_string_array(char **string_array);
void destroy_file(char ***file);
int strcmp_until(char *str1, char *str2, char end);

// open_stream.c
FILE *open_stream(char *filename);

// read_file.c
void destroy_string_array(char **string_array);
void destroy_file(char ***file);
char ***get_file(char *filename);

// parse_string_array.c
char ***parse_string_array(char **string_array);

/*           ERROR HANDLING        */

// check_asm_file.c
int is_valid_asm_file(char ***asm_file, header_t *header);

// check_asm_line.c
int get_op_index_by_name(char *name);
int is_valid_asm_line(char **line);

// check_argument.c
int is_valid_argument(int op_index, char *arg, int arg_index);

/*           CONVERSION            */

// translate_asm.c
int translate_asm_file(char ***asm_file, char *filename);

// translate_header.c
void init_header(header_t *header);
int translate_header(header_t *header, char ***asm_file, int fd);

// translate_asm_line.c
int translate_asm_line(char **line, int fd);

// write_int_as_x_bytes.c
int write_int_as_x_bytes(long data, size_t size, int fd);

#endif /* !ASM_H_ */
