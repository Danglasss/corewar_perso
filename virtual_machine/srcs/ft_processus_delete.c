/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_delete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:02:50 by paul              #+#    #+#             */
/*   Updated: 2020/06/08 08:24:14 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

void	ft_process_list_slide_up(t_process **process_list, int i, int nb)
{
	while (i < nb)
	{
		process_list[i] = process_list[i + 1];
		i += 1;
	}
}

void	ft_processus_list_rm(t_vm *vm, t_process *process)
{
	int	i;

	i = 0;
	while (vm->process_list[i] != process)
		i += 1;
	ft_process_list_slide_up(vm->process_list, i, vm->nb_process);
}

void	ft_processus_tab_rm(t_process *tab[1024], t_process *process)
{
	t_process	*tmp;

	tmp = tab[process->tab_places];
	if (tmp == process)
		tab[process->tab_places] = tmp->next;
	else
	{
		while (tmp->next != NULL && (tmp->next != process))
			tmp = tmp->next;
		tmp->next = process->next;
	}
	free(process);
}

void	ft_processus_rm(t_vm *vm, t_process *tab[1024], t_process *process)
{
	ft_processus_list_rm(vm, process);
	ft_processus_tab_rm(tab, process);
	vm->nb_process -= 1;
}
