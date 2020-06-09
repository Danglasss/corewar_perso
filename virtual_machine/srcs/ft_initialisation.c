/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 09:50:51 by paul              #+#    #+#             */
/*   Updated: 2020/05/04 15:21:15 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/struct.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/op.h"
#include "../includes/struct.h"
#include <stdbool.h>

int	ft_initialisation(t_vm *vm)
{
	ft_bzero(vm, sizeof(vm[0]));
	ft_bzero(vm->tab, CYCLE_WAIT_MAX * sizeof(t_process *));
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->period[1] = CYCLE_TO_DIE;
	vm->nb_max_process = 64;
	if (!(vm->process_list = (t_process **)ft_memalloc(sizeof(t_process *) * 64)))
		return (false);
	return (true);
}