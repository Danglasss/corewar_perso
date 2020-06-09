/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:31:49 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/28 15:12:22 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_verbose(t_process *process, uint32_t param[3][2])
{
	int		i;

	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param - 1)
	{
		if (param[i][1] == T_REG)
			ft_printf("r%d ", param[i][0]);
		else
			ft_printf("%d ", param[i][0]);
		i += 1;
	}
	ft_printf("r%d\n", param[2][0]);
}

void		ft_add(t_process *process, t_vm *vm)
{
	long	addition;
	long	param_1;
	long	param_2;
	long	param_3;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	param_3 = vm->param[2][0];
	addition = process->registre[param_1 - 1];
	addition += process->registre[param_2 - 1];
	process->registre[param_3 - 1] = addition;
	process->carry = (addition == 0 ? 1 : 0);
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
