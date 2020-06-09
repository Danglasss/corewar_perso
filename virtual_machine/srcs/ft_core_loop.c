/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 09:23:15 by paul              #+#    #+#             */
/*   Updated: 2020/06/09 13:38:50 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/struct.h"
#include "../../libft/includes/prototypes.h"

void	ft_loop_dumped(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->cycle <= vm->opt.d[1] && vm->nb_process > 0)
	{
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == vm->period[1] || vm->cycles_to_die <= 0)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
		if (vm->opt.v[1] & 2)
			ft_printf("It is now cycle %zu\n", vm->cycle);
	}
	if (vm->cycle < vm->opt.d[1])
	{
		ft_printf("Contestant %zu, \"%s\", has won !\n",
		vm->last_champ_alive, vm->player_list[vm->last_champ_alive - 1].name);
	}
	else
		ft_dump(vm->vm);
}

void	ft_loop_std(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->nb_process > 0)
	{
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == vm->period[1] || vm->cycles_to_die <= 0)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
		if (vm->opt.v[1] & 2)
			ft_printf("It is now cycle %zu\n", vm->cycle);
	}
	ft_printf("Contestant %zu, \"%s\", has won !\n", vm->last_champ_alive,
	vm->player_list[vm->last_champ_alive - 1].name);
}
