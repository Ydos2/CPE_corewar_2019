##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=	gcc

SRC     =	src/op.c								\
			src/vm.c								\
			src/tools/util_function.c 				\
			src/arena.c								\
			src/champion.c							\
			src/tools/my_xmalloc.c					\
			src/tools/my_memset.c					\
			src/machine_functions/my_add.c			\
			src/machine_functions/my_aff.c			\
			src/machine_functions/my_and.c			\
			src/machine_functions/my_fork.c			\
			src/machine_functions/my_ld.c			\
			src/machine_functions/my_ldi.c			\
			src/machine_functions/my_lfork.c		\
			src/machine_functions/my_live.c			\
			src/machine_functions/my_lld.c			\
			src/machine_functions/my_lldi.c			\
			src/machine_functions/my_or.c			\
			src/machine_functions/my_st.c			\
			src/machine_functions/my_sti.c			\
			src/machine_functions/my_sub.c			\
			src/machine_functions/my_xor.c			\
			src/machine_functions/my_zjump.c		\
			src/print_arena_carac.c					\
			src/tools/my_putnbr.c					\
			src/tools/my_getnbr.c					\
			src/tools/my_xopen.c					\
			src/tools/my_putstr.c					\
			src/process.c							\
			src/id.c								\
			src/header.c							\
			src/refresh_loop.c						\
			src/maths.c								\
			src/instruction.c						\
			src/tools/my_putcolor.c					\
			src/end_vm.c							\
			src/check.c								\
			src/parameters.c						\
			src/octet.c								\
			src/register.c

OBJ     =	$(SRC:.c=.o) 			\

MAIN_SRC    =    src/main.c			\

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)	\

CFLAGS    =    -I./include -Wextra -W -Wall -pedantic

TARGET    =		corewar		\

TEST_TARGET	=	unit_tests

TEST_LFLAGS	=	-lcriterion

SRC_TESTS	=	tests/initialisation_tests.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)			\
				$(SRC:.c=.gcda)				\
				$(MAIN_SRC:.c=.gcda)		\
				$(SRC_TESTS:.c=.gcda)		\
				$(SRC:.c=.gcno)				\
				$(MAIN_SRC:.c=.gcno)		\
				$(SRC_TESTS:.c=.gcno)

all: $(TARGET) ## Build the project

$(TARGET): build

build: $(OBJ) $(MAIN_OBJ) ## Compile the project
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET)
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Link all object ▄▀▄▀▄▀\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34m-Compiled-\e[0m] % 41s\n" $@ | tr ' ' '.'

clean: ## Clean the useless file
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(OBJ_TESTS)

fclean: clean ## Clean the project
	@rm -f $(TARGET) $(TEST_TARGET)
	@rm -f *.gcno
	@rm -f *.gcda
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(TEST_TARGET) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:    fclean all ## Clean then compile

valgrind:	CFLAGS += -g3
valgrind: fclean all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: fclean $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TEST_TARGET) $(TEST_LFLAGS)
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Tests the code ▄▀▄▀▄▀\e[0m\n"
	@./$(TEST_TARGET) -n 1 ../corewar_binaries/corewar/assets/champions/42.cor -n 3 ../corewar_binaries/corewar/assets/champions/abel.cor ../corewar_binaries/corewar/assets/champions/bill.cor
	@gcovr --exclude tests/
	@gcovr -b

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help