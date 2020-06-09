/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/02 08:55:05 by paul             ###   ########.fr       */
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
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (param[i][1] == T_REG)
			ft_printf("r");
		ft_printf("%d", param[i][0]);
		if (i < g_tab_instruction[process->opcode].nb_param - 1)
			ft_printf(" ");
		i += 1;
	}
	ft_printf("\n");
}

void		ft_ld(t_process *process, t_vm *vm)
{
	int		pos;
	int		param_1;
	int		param_2;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (T_DIR == vm->param[0][1])
	{
		process->registre[param_2 - 1] = param_1;
	}
	else if (T_IND == vm->param[0][1])
	{
		param_1 = (short)param_1;
		pos = (process->pc + (param_1 % IDX_MOD)) % MEM_SIZE;
		process->registre[param_2 - 1] =
		ft_convert_to_int(vm->vm + pos);
	}
	vm->param[0][0] = process->registre[param_2 - 1];
	param_1 = process->registre[param_2 - 1];
	process->carry = (param_1 == 0 ? 1 : 0);
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
