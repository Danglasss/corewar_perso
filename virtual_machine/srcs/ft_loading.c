/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:20 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/28 15:15:07 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

void	ft_loading_processus(t_vm *vm, t_process *process, size_t cycle)
{
	int	cycle_to_add;

	process->opcode = vm->vm[process->pc % MEM_SIZE] - 1;
	cycle_to_add = g_tab_instruction[process->opcode].cycle_to_exec;
	ft_process_move(process, vm, cycle % 1024,
	(cycle + cycle_to_add - 1) % 1024);
}

void	ft_loading_try_processus(t_vm *vm, t_process *process, size_t cycle)
{
	if (vm->vm[process->pc % MEM_SIZE] == 0 ||
	vm->vm[process->pc % MEM_SIZE] > 16)
	{
		ft_move_pc(process, 1);
		process->opcode = 100;
		ft_process_move(process, vm, cycle % 1024, (cycle + 1) % 1024);
	}
	else
	{
		process->to_load = FALSE;
		ft_loading_processus(vm, process, cycle);
	}
}
