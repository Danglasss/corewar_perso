/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:02:38 by paul              #+#    #+#             */
/*   Updated: 2020/06/08 08:23:47 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/tab.h"
#include "../../libft/includes/prototypes.h"
#include <stdlib.h>

void		ft_fill_realloc(t_vm *vm)
{
	int		end;
	int		i;

	end = vm->nb_max_process * 2;
	i = vm->nb_max_process;
	while (i < end)
		vm->process_list[i++] = NULL;
}

void		ft_processus_list_add(t_vm *vm, t_process *process)
{
	size_t	i;

	vm->nb_process += 1;
	if (vm->nb_process >= vm->nb_max_process)
	{
		if (!(vm->process_list = realloc(vm->process_list,
		vm->nb_max_process * 2 * sizeof(t_process *))))
			exit(0);
		ft_fill_realloc(vm);
		vm->nb_max_process *= 2;
	}
	i = 0;
	vm->process_list[vm->nb_process - 1] = process;
}

t_process	*ft_processus_tab_front_add(t_process *tab, t_process *process)
{
	process->prev = NULL;
	process->next = tab;
	return (process);
}

void		ft_processus_tab_core_add(t_process *process, t_process *tmp)
{
	while (tmp->next && (tmp->next->no > process->no))
		tmp = tmp->next;
	process->next = tmp->next;
	tmp->next = process;
}

void		ft_processus_tab_add(t_process *process, t_vm *vm, size_t cycle)
{
	process->tab_places = cycle;
	if (vm->tab[cycle] == NULL || (vm->tab[cycle]->no < process->no))
		vm->tab[cycle] = ft_processus_tab_front_add(vm->tab[cycle], process);
	else
		ft_processus_tab_core_add(process, vm->tab[cycle]);
}
