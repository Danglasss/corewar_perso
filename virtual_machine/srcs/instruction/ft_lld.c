/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/08 10:32:00 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void		ft_verbose(t_process *process, uint32_t param[3][2])
{
	int			i;

	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (param[i][1] == T_REG)
			ft_printf("r");
		if (param[i][1] == T_IND)
			ft_printf("%hd", process->registre[param[1][0] - 1]);
		else
			ft_printf("%d", param[i][0]);
		if (i < g_tab_instruction[process->opcode].nb_param - 1)
			ft_printf(" ");
		i += 1;
	}
	ft_printf("\n");
}

short			ft_convert2bytes_to_int(unsigned char tab[4])
{
	short		result;
	int			index;

	result = 0;
	index = 0;
	while (index < 2)
	{
		result |= tab[index];
		if (index < 1)
			result <<= 8;
		index++;
	}
	return (result);
}

void			ft_lld(t_process *process, t_vm *vm)
{
	int			param_1;
	int			param_2;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (T_DIR == vm->param[0][1])
		process->registre[param_2 - 1] = param_1;
	else if (T_IND == vm->param[0][1])
	{
		process->registre[param_2 - 1] = ft_convert2bytes_to_int(vm->vm +
										(process->pc + param_1) % MEM_SIZE);
		param_1 = process->registre[param_2 - 1];
	}
	process->carry = (param_1 == 0 ? 1 : 0);
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
