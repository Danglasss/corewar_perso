/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/08 10:28:41 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tab.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

/*
**	Fonction qui execute l'instruction correspondante
**	a l'opcode contenu dans process.
*/

void		ft_exec_instruction(t_process *process, t_vm *vm)
{
	uint8_t	to_exec;

	if (process->opcode == 100)
		return ;
	to_exec = ft_param_set_struct(process, vm);
	if (to_exec == true)
		g_tab_instruction[process->opcode].ft_instruction(process, vm);
	ft_bzero(vm->param, sizeof(vm->param));
}

/*
**	Fonction qui va executer les processus qui
**	doivent etre execute a ce cycle.
*/

void		ft_exec_processus(t_process *tab[1024], size_t cycle, t_vm *vm)
{
	while (tab[cycle % 1024] != NULL)
	{
		if (tab[cycle % 1024]->to_load == FALSE)
		{
			ft_exec_instruction(tab[cycle % 1024], vm);
			tab[cycle % 1024]->to_load = TRUE;
			ft_process_move(tab[cycle % 1024], vm,
			cycle % 1024, (cycle + 1) % 1024);
		}
		else
			ft_loading_try_processus(vm, tab[cycle % 1024], cycle);
	}
}

/*
**	Fonction qui gere le déroulement d'un cycle.
*/

void		ft_exec_cycle(t_vm *vm, t_process *tab[1024], size_t cycle)
{
	if (tab[cycle % 1024] != NULL)
		ft_exec_processus(tab, cycle, vm);
}
