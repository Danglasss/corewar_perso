/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:13:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/05 18:46:06 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include "./op.h"
# include <stdlib.h>

typedef struct			s_player
{
	char				magic[MAGIC + 1];
	char				name[READ_NAME + 1];
	char				comment[READ_COM + 1];
	char				size[READ_EXEC + 1];
	int					index_player;
	uint32_t			nb_live;
}						t_player;

typedef struct			s_option
{
	int					visu;
	int					v[2];
	int					d[2];
	int					pad[2];
}						t_option;

typedef struct			s_args
{
	int					player_nb;
	int					option[4];
	char				**champ;
}						t_args;

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct			s_process
{
	struct s_process	*next;
	struct s_process	*prev;
	size_t				no;
	size_t				pc;
	size_t				tab_places;
	int					to_load;
	int					cycle_last_live;
	int					registre[16];
	char				carry;
	unsigned char		opcode;
	char				padding[6];
}						t_process;

typedef struct			s_vm
{
	unsigned char		vm[MEM_SIZE];
	t_process			*tab[CYCLE_WAIT_MAX];
	t_player			player_list[4];
	t_option			opt;
	t_process			**process_list;
	size_t				nb_process;
	size_t				nb_max_process;
	size_t				last_process;
	unsigned int		param[3][2];
	int					cycle;
	int					cycles_to_die;
	int					nb_live;
	int					no_decrease_check;
	int					nb_champs_left;
	int					period[2];
	int					nb_player;
	int					last_champ_alive;
}						t_vm;

typedef struct			s_instruction
{
	void				(*ft_instruction)(t_process *process, t_vm *vm);
	char				*name;
	size_t				cycle_to_exec;
	unsigned char		nb_param;
	unsigned char		ocp;
	unsigned char		dir_size;
	int					param_type[3];
	char				padding[6];
}						t_instruction;

#endif
