/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:30:43 by paul              #+#    #+#             */
/*   Updated: 2020/05/26 21:36:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/op.h"

int		ft_recover_value_ram(uint8_t vm[4], int len)
{
	int	i;
	int	res;

	i = 0;
	while (i < len)
	{
		res = vm[i];
		if (i < len - 1)
			res <<= 8;
		i += 1;
	}
	return (res);
}

int		ft_recover_value_param(uint8_t vm[MEM_SIZE],
								uint32_t param[2], t_process *process)
{
	int	parameter;

	if (param[1] == T_IND)
	{
		parameter = ft_recover_value_ram(vm + process->pc +
		(param[1] % IDX_MOD), 4);
	}
	else if (param[1] == T_REG)
		parameter = process->registre[param[0] - 1];
	else
		parameter = param[0];
	return (parameter);
}
