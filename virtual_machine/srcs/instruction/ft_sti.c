/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:26 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/08 10:30:15 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_second_line(t_process *process, uint32_t param[3][2])
{
	ft_printf("\n       | -> store to ", process->carry);
	if (param[1][1] == T_DIR)
		ft_printf("%hd + ", param[1][0]);
	else
		ft_printf("%d + ", param[1][0]);
	if (param[2][1] == T_DIR)
		ft_printf("%hd ", param[2][0]);
	else
		ft_printf("%d ", param[2][0]);
	ft_printf("= %d (with pc and mod %hd)\n", param[1][0] + param[2][0],
	(int)process->pc + (((int)param[1][0] + (int)param[2][0]) % IDX_MOD));
}

static void	ft_verbose(t_process *process, uint32_t param[3][2])
{
	int		i;

	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (i == 0 && param[i][1] == T_REG)
			ft_printf("r");
		if (param[i][1] == T_REG)
			ft_printf("%d", param[i][0]);
		else if (param[i][1] == T_DIR)
			ft_printf("%hd", param[i][0]);
		else if (param[i][1] == T_IND)
			ft_printf("%d", param[i][0]);
		if (i < g_tab_instruction[process->opcode].nb_param - 1)
			ft_printf(" ");
		i += 1;
	}
	ft_second_line(process, param);
}

int			ft_sti_param_recover_value(t_vm *vm, t_process *process,
										uint32_t tab[2])
{
	int		param;

	param = tab[0];
	if (tab[1] == T_DIR)
		param = (short)tab[0];
	else if (tab[1] == T_REG)
		param = process->registre[param - 1];
	else if (tab[1] == T_IND)
		param = ft_value_from_address(process->pc, param, vm);
	return (param);
}

void		ft_sti(t_process *process, t_vm *vm)
{
	long	param_1;
	long	param_2;
	long	param_3;
	long	pos;

	param_1 = vm->param[0][0];
	param_2 = ft_sti_param_recover_value(vm, process, vm->param[1]);
	param_3 = ft_sti_param_recover_value(vm, process, vm->param[2]);
	vm->param[1][0] = param_2;
	vm->param[2][0] = param_3;
	pos = (process->pc + ((param_2 + param_3) % IDX_MOD));
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param);
	ft_convert_to_char(vm,
	process->registre[vm->param[0][0] - 1], (pos + 3) % MEM_SIZE);
	ft_skip_instruction_sequency(process, vm);
}
