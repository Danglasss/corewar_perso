# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 18:42:15 by aboitier          #+#    #+#              #
#    Updated: 2020/03/10 23:04:29 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
NAME 			= asm
CFLAG 			= -Wall -Wextra -Werror -fsanitize=address,undefined
LIB				= ../libft/libft.a

SRC				= op.c  					\
				  init.c					\
				  scan.c					\
				  main.c					\
				


OBJ 			= $(SRC:.c=.o)
PATH_SRC		= $(addprefix src/, $(SRC))
PATH_OBJ		= $(addprefix obj/, $(OBJ))
PATH_LIB		= ../libft/

all: $(NAME) libft_comp

libft_comp:
	@make -C $(PATH_LIB)

$(NAME)	: $(PATH_OBJ) libft_comp
	@$(CC) $(CFLAG) -o $(NAME) $(PATH_OBJ) $(LIB)
	@echo "asm has been created"

$(addprefix obj/, %.o): $(addprefix src/, %.c)
	@$(CC) $(CFLAG) -c $< -o $@

lib_clean:
	@make clean -C $(PATH_LIB)

lib_fclean:
	@make fclean -C $(PATH_LIB)

clean : #lib_clean
	@rm -f $(PATH_OBJ)
	@echo "asm OBJ have been deleted"

fclean : clean
	@rm -f $(EXE)

re: fclean all

run: re 
	@./$(NAME) tetet.s

.PHONY: clean fclean re 
