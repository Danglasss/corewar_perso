/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:39:28 by paul              #+#    #+#             */
/*   Updated: 2020/06/04 16:02:10 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/tab.h"
#include <stdbool.h>

void		ft_print_skip(t_vm *vm, t_process *process, int to_skip)
{
	int		i;

	ft_printf("ADV %d (%#.4x -> %#.4x) ", to_skip + 1, process->pc,
	process->pc + to_skip + 1);
	i = 0;
	while (i <= to_skip)
		ft_printf("%.2x ", vm->vm[(process->pc + i++) % MEM_SIZE]);
	ft_printf("\n");
}

int			ft_skip_one_parameter_field(t_vm *vm, int to_skip, const int j,
								const uint8_t opcode)
{
	if (vm->param[j][1] == T_REG)
		to_skip += 1;
	else if (vm->param[j][1] == T_IND)
		to_skip += 2;
	else if (vm->param[j][1] == T_DIR)
		to_skip += g_tab_instruction[opcode].dir_size;
	return (to_skip);
}

/*
**	Fonction qui va deplacer le PC lorsque l'instruction a été executer.
*/

void		ft_skip_instruction_sequency(t_process *process, t_vm *vm)
{
	int		to_skip;
	int		nb_param;
	int		i;

	to_skip = 0;
	if (g_tab_instruction[process->opcode].ocp == true)
		to_skip = 1;
	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		to_skip = ft_skip_one_parameter_field(vm, to_skip,
		i++, process->opcode);
	}
	if (vm->opt.v[1] & 16)
		ft_print_skip(vm, process, to_skip);
	ft_move_pc(process, to_skip + 1);
}

uint8_t		ft_convert_ocp(uint8_t ocp)
{
	if (ocp == IND_BIT)
		return (T_IND);
	else if (ocp == DIR_BIT)
		return (T_DIR);
	else if (ocp == REG_BIT)
		return (T_REG);
	else
		return (0);
}

/*
**	Fonction qui va deplacer le pc dans le cas d'un OCP incorrect.
*/

int			ft_skip_bad_ocp_parsing(t_vm *vm, t_process *process, int nb_param)
{
	int		j;
	int		i;
	uint8_t	mask;
	uint8_t	ocp;

	ocp = vm->vm[(process->pc + 1) % MEM_SIZE];
	j = 0;
	i = 0;
	while (j < nb_param)
	{
		mask = ft_convert_ocp(ocp & IND_BIT);
		if (mask == T_DIR)
			i += g_tab_instruction[process->opcode].dir_size;
		else if (mask != 0)
			i += mask;
		ocp <<= 2;
		j += 1;
	}
	if (vm->opt.v[1] & 16)
		ft_print_skip(vm, process, i + 1);
	process->pc += i + 2;
	return (false);
}
