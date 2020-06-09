EXE = corewar
CC = clang 
CFLAG = -Wall -Werror -Wextra -g3 -fsanitize=address,undefined
LIB = ../libft/libftprintf.a

SRC =	main.c
SRC +=	ft_place_player.c
SRC +=	ft_print_intro.c
SRC +=	ft_free.c
SRC +=	ft_option.c
SRC +=	ft_dump.c
SRC +=	ft_error.c
SRC +=	ft_execution.c
SRC +=	ft_loading.c
SRC +=	ft_parameter.c
SRC +=	ft_parameter_check.c
SRC +=	ft_processus_add.c
SRC +=	ft_processus_creation.c
SRC +=	ft_processus_delete.c
SRC +=	ft_processus_move.c
SRC +=	ft_processus_player_initialisation.c
SRC +=	ft_check.c
SRC +=	ft_tab_instruction.c
SRC +=	ft_parsing.c
SRC +=	ft_insertion_vm.c
SRC +=	ft_core_loop.c
SRC +=	ft_initialisation.c
SRC +=	ft_recover_value.c
SRC +=	ft_skip.c
SRC +=	ft_conversion.c
SRC +=	instruction/ft_add.c
SRC +=	instruction/ft_aff.c
SRC +=	instruction/ft_and.c
SRC +=	instruction/ft_fork.c
SRC +=	instruction/ft_ld.c
SRC +=	instruction/ft_ldi.c
SRC +=	instruction/ft_lfork.c
SRC +=	instruction/ft_live.c
SRC +=	instruction/ft_lld.c
SRC +=	instruction/ft_lldi.c
SRC +=	instruction/ft_or.c
SRC +=	instruction/ft_st.c
SRC +=	instruction/ft_sti.c
SRC +=	instruction/ft_sub.c
SRC +=	instruction/ft_xor.c
SRC +=	instruction/ft_zjmp.c
SRC +=	instruction/ft_utils.c

OBJ = $(SRC:.c=.o)
PATH_SRC = $(addprefix srcs/, $(SRC))
PATH_OBJ = $(addprefix obj/, $(OBJ))
PATH_HEADERS = $(addprefix includes/, $(HEADERS))

all: libft_comp $(EXE)

libft_comp:
	make -C ../libft

obj_dir:
	if ! [ -d "obj/" ]; then mkdir obj ; fi
	if ! [ -d "obj/instruction" ]; then mkdir obj/instruction ; fi

$(EXE) : libft_comp obj_dir $(PATH_OBJ)
	$(CC) $(CFLAG) -o $(EXE) $(PATH_OBJ) $(LIB)

$(addprefix obj/, %.o): $(addprefix srcs/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

lib_clean:
	make clean -C ../libft/

lib_fclean:
	make fclean -C ../libft/

clean: lib_clean
	rm -f $(PATH_OBJ) $(PATH_OBJ_OP)

fclean: clean lib_fclean
	rm -f $(EXE)

re: fclean all

.PHONY : libft clean fclean re comp lib_clean lib_fclean
