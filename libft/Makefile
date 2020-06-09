NAME = libftprintf.a
CC= clang
CFLAG = -Wall -Werror -Wextra

SRCS_FT_PRINTF =			buffer.c
SRCS_FT_PRINTF +=		ft_error_parse.c
SRCS_FT_PRINTF +=		ft_printf.c
SRCS_FT_PRINTF +=		ft_option.c
SRCS_FT_PRINTF +=		ft_parser.c
SRCS_FT_PRINTF +=		ft_size.c
SRCS_FT_PRINTF +=		ft_lmc_precision.c
SRCS_FT_PRINTF +=		ft_argument.c
SRCS_FT_PRINTF +=		convert_to_base.c
SRCS_FT_PRINTF +=		ft_power.c
SRCS_FT_PRINTF +=		ft_formatting.c
SRCS_FT_PRINTF +=		ft_d_conversion.c
SRCS_FT_PRINTF +=		ft_o_conversion.c
SRCS_FT_PRINTF +=		ft_u_conversion.c
SRCS_FT_PRINTF +=		ft_x_conversion.c
SRCS_FT_PRINTF +=		ft_bigx_conversion.c
SRCS_FT_PRINTF +=		ft_p_conversion.c
SRCS_FT_PRINTF +=		ft_c_conversion.c
SRCS_FT_PRINTF +=		ft_s_conversion.c
SRCS_FT_PRINTF +=		ft_percent_conversion.c
SRCS_FT_PRINTF +=		ft_putchar.c
SRCS_FT_PRINTF +=		ft_putstr.c
SRCS_FT_PRINTF +=		ft_putendl.c
SRCS_FT_PRINTF +=		ft_putnbr.c
SRCS_FT_PRINTF +=		ft_putchar_fd.c
SRCS_FT_PRINTF +=		ft_putstr_fd.c
SRCS_FT_PRINTF +=		ft_putendl_fd.c
SRCS_FT_PRINTF +=		ft_putnbr_fd.c
SRCS_FT_PRINTF +=		ft_higher_value.c
SRCS_FT_PRINTF +=		ft_nb_digit.c
SRCS_FT_PRINTF +=		tab_global.c
SRCS_FT_PRINTF +=		comparaison.c

SRCS_MEMORY =			ft_memset.c
SRCS_MEMORY +=			ft_bzero.c
SRCS_MEMORY +=			ft_memcpy.c
SRCS_MEMORY +=			ft_memccpy.c
SRCS_MEMORY +=			ft_memmove.c
SRCS_MEMORY +=			ft_memchr.c
SRCS_MEMORY +=			ft_memcmp.c
SRCS_MEMORY +=			ft_memalloc.c
SRCS_MEMORY +=			ft_memdel.c

SRCS_STRING +=			ft_strlen.c
SRCS_STRING +=			ft_strdup.c
SRCS_STRING +=			ft_strcpy.c
SRCS_STRING +=			ft_strncpy.c
SRCS_STRING +=			ft_strcat.c
SRCS_STRING +=			ft_strncat.c
SRCS_STRING +=			ft_strlcat.c
SRCS_STRING +=			ft_strchr.c
SRCS_STRING +=			ft_strrchr.c
SRCS_STRING +=			ft_strstr.c
SRCS_STRING +=			ft_strnstr.c
SRCS_STRING +=			ft_strcmp.c
SRCS_STRING +=			ft_strncmp.c
SRCS_STRING +=			ft_strnew.c
SRCS_STRING +=			ft_strdel.c
SRCS_STRING +=			ft_strclr.c
SRCS_STRING +=			ft_striter.c
SRCS_STRING +=			ft_striteri.c
SRCS_STRING +=			ft_strmap.c
SRCS_STRING +=			ft_strmapi.c
SRCS_STRING +=			ft_strequ.c
SRCS_STRING +=			ft_strnequ.c
SRCS_STRING +=			ft_strsub.c
SRCS_STRING +=			ft_strjoin.c
SRCS_STRING +=			ft_strtrim.c
SRCS_STRING +=			ft_strsplit.c
SRCS_STRING +=			ft_strjoinf.c

SRCS_CONVERSION +=		ft_atoi.c
SRCS_CONVERSION +=		ft_itoa.c

SRCS_CHARACTER +=		ft_isalpha.c
SRCS_CHARACTER +=		ft_isdigit.c
SRCS_CHARACTER +=		ft_isalnum.c
SRCS_CHARACTER +=		ft_isascii.c
SRCS_CHARACTER +=		ft_isprint.c
SRCS_CHARACTER +=		ft_toupper.c
SRCS_CHARACTER +=		ft_tolower.c

SRCS_LIST +=				ft_lstnew.c
SRCS_LIST +=				ft_lstdelone.c
SRCS_LIST +=				ft_lstdel.c
SRCS_LIST +=				ft_lstadd.c
SRCS_LIST +=				ft_lstiter.c
SRCS_LIST +=				ft_lstmap.c
SRCS_LIST +=				ft_lst_push_back.c

OBJ_FT_PRINTF =			$(SRCS_FT_PRINTF:.c=.o)
OBJ_MEMORY =			$(SRCS_MEMORY:.c=.o)
OBJ_STRING =			$(SRCS_STRING:.c=.o)
OBJ_CONVERSION =		$(SRCS_CONVERSION:.c=.o)
OBJ_CHARACTER =			$(SRCS_CHARACTER:.c=.o)
OBJ_LIST =				$(SRCS_LIST:.c=.o)

PATH_SRCS_FT_PRINTF =	$(addprefix srcs/ft_printf/, $(SRC_FT_PRINTF))
PATH_SRCS_MEMORY =		$(addprefix srcs/memory/, $(SRC_MEMORY))
PATH_SRCS_STRING =		$(addprefix srcs/string/, $(SRC_STRING))
PATH_SRCS_CONVERSION =	$(addprefix srcs/conversion/, $(SRC_CONVERSION))
PATH_SRCS_CHARACTER =	$(addprefix srcs/character/, $(SRC_CHARACTER))
PATH_SRCS_LIST =			$(addprefix srcs/list/, $(SRC_LIST))

PATH_OBJ_FT_PRINTF =	$(addprefix obj/ft_printf/, $(OBJ_FT_PRINTF))
PATH_OBJ_MEMORY =		$(addprefix obj/memory/, $(OBJ_MEMORY))
PATH_OBJ_STRING =		$(addprefix obj/string/, $(OBJ_STRING))
PATH_OBJ_CONVERSION =	$(addprefix obj/conversion/, $(OBJ_CONVERSION))
PATH_OBJ_CHARACTER =	$(addprefix obj/character/, $(OBJ_CHARACTER))
PATH_OBJ_LIST =			$(addprefix obj/list/, $(OBJ_LIST))

all: obj $(NAME)

obj:
	if ! [ -d "obj" ]; then mkdir obj ; fi
	if ! [ -d "obj/ft_printf" ]; then mkdir obj/ft_printf ; fi
	if ! [ -d "obj/memory" ]; then mkdir obj/memory ; fi
	if ! [ -d "obj/string" ]; then mkdir obj/string ; fi
	if ! [ -d "obj/character" ]; then mkdir obj/character ; fi
	if ! [ -d "obj/conversion" ]; then mkdir obj/conversion ; fi
	if ! [ -d "obj/list" ]; then mkdir obj/list ; fi

$(NAME): $(PATH_OBJ_FT_PRINTF) $(PATH_OBJ_MEMORY) $(PATH_OBJ_STRING) $(PATH_OBJ_LIST) $(PATH_OBJ_CONVERSION) $(PATH_OBJ_CHARACTER)
	ar rc $@ $(PATH_OBJ_FT_PRINTF) $(PATH_OBJ_MEMORY) $(PATH_OBJ_STRING) $(PATH_OBJ_LIST) \
			$(PATH_OBJ_CONVERSION) $(PATH_OBJ_CHARACTER)
	ranlib $@

$(addprefix obj/ft_printf/, %.o): $(addprefix srcs/ft_printf/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

$(addprefix obj/memory/, %.o): $(addprefix srcs/memory/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

$(addprefix obj/string/, %.o): $(addprefix srcs/string/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

$(addprefix obj/conversion/, %.o): $(addprefix srcs/conversion/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

$(addprefix obj/character/, %.o): $(addprefix srcs/character/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

$(addprefix obj/list/, %.o): $(addprefix srcs/list/, %.c)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(PATH_OBJ_FT_PRINTF) $(PATH_OBJ_MEMORY) $(PATH_OBJ_STRING) $(PATH_OBJ_LIST) \
			$(PATH_OBJ_CONVERSION) $(PATH_OBJ_CHARACTER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : libft clean fclean re obj
