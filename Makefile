##
## EPITECH PROJECT, 2020
## Corewar
## File description:
## Makefile
##

VM_NAME		=	corewar

ASM_NAME	=	asm

SRC_ASM		=	main.c	\
				asm.c	\
				op.c

SRC_VM		=	main.c	\
				op.c	\
				vm.c

OBJ_ASM_NAME	=	$(SRC_ASM:.c=.o)

OBJ_VM_NAME		=	$(SRC_VM:.c=.o)

SRC_ASM_PATH	=	src/asm/

SRC_VM_PATH		=	src/vm/

OBJ_PATH		=	obj/

SRC_ASM_LIB		=	$(addprefix $(SRC_ASM_PATH),$(SRC_ASM))

SRC_VM_LIB		=	$(addprefix $(SRC_VM_PATH),$(SRC_VM))

OBJ_ASM			=	$(addprefix $(OBJ_PATH),$(OBJ_ASM_NAME))

OBJ_VM			=	$(addprefix $(OBJ_PATH),$(OBJ_VM_NAME))

CC			=	gcc

CFLAGS		=	-Iinclude -Wextra -W -Wall -pedantic

goodbye:
	@echo -ne "\033[1;5;34m"
	@echo -e " ___   ___  ___  ___  ___       ___"
	@echo -e "/   | |   ||   ||   \|   / \ / |    "
	@echo -e "|   __|   ||   ||   ||---\  |  |--  "
	@echo -e "|___/ |___||___||___/|___/  |  |___"
	@echo -ne "\e[0m\n"

all:		$(VM_NAME) $(ASM_NAME) ## Build the project

$(ASM_NAME):		$(OBJ_ASM)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ_ASM) | tr ' ' '.'
	@printf "[\e[1;34m-Create Name-\e[0m] % 43s\n" $(ASM_NAME) | tr ' ' '.'
	@printf "\e[1;3;32m▀▄▀▄▀▄ Compilation done ▄▀▄▀▄▀\e[0m\n"

$(VM_NAME):			$(OBJ_VM)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ_VM) | tr ' ' '.'
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(OBJ_INSTR) | tr ' ' '.'
	@printf "[\e[1;34m-Create Name-\e[0m] % 43s\n" $(VM_NAME) | tr ' ' '.'
	@printf "\e[1;3;32m▀▄▀▄▀▄ Compilation done ▄▀▄▀▄▀\e[0m\n"

$(OBJ_PATH)%.o:		$(SRC_ASM_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH)%.o:		$(SRC_VM_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ_ASM) $(OBJ_VM)
	@rm -rfv $(OBJ_PATH) > /dev/null
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(OBJ_ASM) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(OBJ_VM) | tr ' ' '.'
	@printf "\e[1;3;32m▀▄▀▄▀▄ Finished RM Objects ▄▀▄▀▄▀\e[0m\n"

fclean:		clean goodbye
	@rm -fv $(ASM_NAME) $(VM_NAME)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(ASM_NAME) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(VM_NAME) | tr ' ' '.'
	@printf "\e[1;3;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"

re:		fclean all ## Clean then compile

valgrind:	CFLAGS += -g3
valgrind:	fclean	all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY: all, clean, fclean, re