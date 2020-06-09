/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_player_initialisation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:06:40 by paul              #+#    #+#             */
/*   Updated: 2020/06/01 13:23:41 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/tab.h"
#include <stdbool.h>

static int		ft_processus_create_player(t_vm *vm, const int count,
											const int nb_player)
{
	t_process	*processus;

	vm->last_process = count + 1;
	vm->last_champ_alive = count + 1;
	if (!(processus = ft_processus_create(count + 1,
	(MEM_SIZE / nb_player) * count)))
		return (false);
	processus->registre[0] = -(count + 1);
	ft_processus_list_add(vm, processus);
	if (vm->vm[processus->pc] > 0 && vm->vm[processus->pc] < 17)
	{
		processus->opcode = vm->vm[processus->pc] - 1;
		ft_processus_tab_add(processus, vm,
		g_tab_instruction[processus->opcode].cycle_to_exec);
	}
	else
	{
		processus->opcode = 100;
		ft_processus_tab_add(processus, vm, 0);
	}
	return (true);
}

int				ft_processus_player_initialisation(t_vm *vm)
{
	int			count;
	int			nb_player;

	nb_player = vm->nb_player;
	count = 0;
	while (count < nb_player)
		if (!(ft_processus_create_player(vm, count++, nb_player)))
			return (false);
	return (true);
}
