/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:38:04 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/28 15:14:09 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_verbose(t_process *process, uint32_t param)
{
	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	ft_printf("%hd", param);
}

/*
**	Refacto en mettant les ok/failed dans la focntion de verbose
*/

void		ft_zjmp(t_process *process, t_vm *vm)
{
	short	param;

	param = vm->param[0][0];
	if (vm->opt.v[1] & 4)
	{
		ft_verbose(process, vm->param[0][0]);
		if (process->carry == 1)
		{
			ft_printf(" OK\n");
			process->pc = (process->pc + (param % IDX_MOD)) % MEM_SIZE;
		}
		else
		{
			ft_printf(" FAILED\n");
			ft_skip_instruction_sequency(process, vm);
		}
	}
	else
	{
		if (process->carry == 1)
			process->pc = (process->pc + (param % IDX_MOD)) % MEM_SIZE;
		else
			ft_skip_instruction_sequency(process, vm);
	}
}
