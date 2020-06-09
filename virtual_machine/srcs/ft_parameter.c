/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:42:42 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/08 10:29:16 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

/*
**	Fonction qui va stocker la valeur des parametres.
*/

int			ft_param_get_value(t_process *process, t_vm *vm)
{
	int		i;
	int		j;
	int		nb_param;

	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = (process->pc + 1 + g_tab_instruction[process->opcode].ocp) % MEM_SIZE;
	j = 0;
	while (j < nb_param)
	{
		if (vm->param[j][1] == T_REG)
			ft_convert_ram_to_param(vm, i + 1, &i, j);
		else if (vm->param[j][1] == T_IND)
			ft_convert_ram_to_param(vm, i + 2, &i, j);
		else if (vm->param[j][1] == T_DIR)
		{
			ft_convert_ram_to_param(vm, i +
			g_tab_instruction[process->opcode].dir_size, &i, j);
		}
		j += 1;
	}
	return (ft_check_value_param(process, vm));
}

int			ft_param_get_type(uint8_t ocp, t_process *process,
							t_vm *vm, const int i)
{
	uint8_t	mask;

	mask = ocp & IND_BIT;
	if (mask == REG_BIT &&
	(g_tab_instruction[process->opcode].param_type[i] & T_REG) != 0)
		vm->param[i][1] = T_REG;
	else if (mask == IND_BIT &&
	(g_tab_instruction[process->opcode].param_type[i] & T_IND) != 0)
		vm->param[i][1] = T_IND;
	else if (mask == DIR_BIT &&
	(g_tab_instruction[process->opcode].param_type[i] & T_DIR) != 0)
		vm->param[i][1] = T_DIR;
	return (true);
}

int			ft_param_get_ocp(t_vm *vm, t_process *process)
{
	int		nb_param;
	int		i;
	uint8_t	ocp;

	ocp = vm->vm[(process->pc + 1) % MEM_SIZE];
	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		if (ft_param_get_type(ocp, process, vm, i++) == false)
			return (false);
		ocp <<= 2;
	}
	if (ft_param_check_type(vm, process) == false)
		return (false);
	return (true);
}

/*
**	Fonction qui va stocker les types des parametres.
*/

int			ft_param_set_struct(t_process *process, t_vm *vm)
{
	if (g_tab_instruction[process->opcode].ocp == true)
	{
		if (ft_param_get_ocp(vm, process) == false)
			return (false);
	}
	else
		vm->param[0][1] = T_DIR;
	return (ft_param_get_value(process, vm));
}
