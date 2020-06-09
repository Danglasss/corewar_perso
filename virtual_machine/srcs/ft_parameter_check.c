/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:39:52 by paul              #+#    #+#             */
/*   Updated: 2020/06/05 14:39:32 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

/*
**	Fonction qui check que la valeur des parametres est valide
**	(i.e que le numero du registre soit bien entre 1 et 16)
*/

int			ft_check_value_param(t_process *process, t_vm *vm)
{
	int		nb_param;
	int		i;

	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		if (vm->param[i][1] == T_REG && (vm->param[i][0] <= 0
			|| vm->param[i][0] >= 17))
		{
			ft_skip_instruction_sequency(process, vm);
			return (false);
		}
		i += 1;
	}
	return (true);
}

int			ft_param_check_type(t_vm *vm, t_process *process)
{
	int		nb_param;
	int		i;

	nb_param = g_tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		if ((vm->param[i][1] &
		g_tab_instruction[process->opcode].param_type[i]) == 0)
			return (ft_skip_bad_ocp_parsing(vm, process, nb_param));
		i += 1;
	}
	return (true);
}
