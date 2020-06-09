/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:11 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/28 15:12:29 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../../libft/includes/prototypes.h"

void	ft_aff(t_process *process, t_vm *vm)
{
	if (vm->opt.v[1] & 4)
		ft_printf("Aff : %d\n", process->registre[vm->param[0][0] - 1]);
	ft_skip_instruction_sequency(process, vm);
}
