/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:23:05 by paul              #+#    #+#             */
/*   Updated: 2020/05/28 15:14:15 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

int		ft_check_decreasing(t_vm *vm)
{
	if (vm->nb_live >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->opt.v[1] & 2)
			ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
		vm->no_decrease_check = 0;
	}
	else
		vm->no_decrease_check += 1;
	return (vm->no_decrease_check);
}

void	ft_is_alive(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	int	i;

	i = vm->nb_process - 1;
	while (i >= 0)
	{
		if (vm->process_list[i]->cycle_last_live
			<= (vm->cycle - vm->cycles_to_die))
		{
			if (vm->opt.v[1] & 8)
			{
				ft_printf("Process %zu hasn't lived for %zu cycles (CTD %d)\n",
				vm->process_list[i]->no,
				vm->cycle - vm->process_list[i]->cycle_last_live,
				vm->cycles_to_die);
			}
			ft_processus_rm(vm, tab, vm->process_list[i]);
		}
		i -= 1;
	}
}

void	ft_reset_period(t_vm *vm)
{
	vm->period[0] = 0;
	vm->period[1] = vm->cycles_to_die;
}

void	ft_check(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	ft_is_alive(vm, tab);
	if (ft_check_decreasing(vm) == MAX_CHECKS)
	{
		vm->no_decrease_check = 0;
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->opt.v[1] & 2)
			ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
	}
	vm->nb_live = 0;
	ft_reset_period(vm);
}
