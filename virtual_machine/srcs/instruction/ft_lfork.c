/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/28 15:13:02 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"

static void		ft_verbose(t_process *process, uint32_t param)
{
	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	ft_printf("%hd (%hd)\n", param, ((short)param + (int)process->pc));
}

static void		ft_good_read(t_process *new_process, t_vm *vm)
{
	new_process->opcode = vm->vm[new_process->pc] - 1;
	ft_processus_tab_add(new_process, vm, (vm->cycle +
	g_tab_instruction[new_process->opcode].cycle_to_exec) % 1024);
}

static void		ft_bad_read(t_process *new_process, t_vm *vm)
{
	new_process->opcode = 100;
	ft_processus_tab_add(new_process, vm, (vm->cycle + 1) % 1024);
	new_process->pc += 1;
}

void			ft_lfork(t_process *process, t_vm *vm)
{
	t_process	*new_process;
	short		param;
	size_t		no;
	size_t		pc;

	param = vm->param[0][0];
	no = vm->last_process + 1;
	vm->last_process += 1;
	pc = (process->pc + param) % MEM_SIZE;
	if (!(new_process = ft_processus_cpy(process, pc, no)))
		exit(0);
	if (vm->opt.v[1] & 4)
		ft_verbose(process, vm->param[0][0]);
	if (vm->vm[new_process->pc % MEM_SIZE] == 0 ||
		vm->vm[new_process->pc % MEM_SIZE] > 16)
		ft_bad_read(new_process, vm);
	else
		ft_good_read(new_process, vm);
	new_process->cycle_last_live = process->cycle_last_live;
	ft_processus_list_add(vm, new_process);
	ft_skip_instruction_sequency(process, vm);
}
