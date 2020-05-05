##
## EPITECH PROJECT, 2020
## Corewar
## File description:
## Makefile
##

VM_NAME		=	vvm_src

ASM_NAME	=	aasm_src

CC			=	gcc

all:		$(VM_NAME) $(ASM_NAME) ## Build the project

goodbye:
	@echo -ne "\033[1;5;34m"
	@echo -e " ___   ___  ___  ___  ___       ___"
	@echo -e "/   | |   ||   ||   \|   / \ / |    "
	@echo -e "|   __|   ||   ||   ||---\  |  |--  "
	@echo -e "|___/ |___||___||___/|___/  |  |___"
	@echo -ne "\e[0m\n"

$(ASM_NAME):
	@make re -C asm_src/
	@cp ./asm_src/asm ./ -rf

$(VM_NAME):
	@make re -C vm_src/
	@cp ./vm_src/corewar ./ -rf

clean:
	@make clean -C asm_src
	@make clean -C vm_src

fclean:			goodbye
	@make fclean -C asm_src
	@make fclean -C vm_src
	@rm -rf asm
	@rm -rf corewar

re:		fclean all ## Clean then compile

valgrind:	fclean	all ## Launch valgrind
	@make valgrind -C asm_src
	@make valgrind -C vm_src

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY: all, clean, fclean, valgrind, re