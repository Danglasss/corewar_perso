/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:08:29 by paul              #+#    #+#             */
/*   Updated: 2020/05/26 21:11:12 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include <stdbool.h>

/*
**	Fonction qui convertit les len-prochain bit en int.
*/

int		ft_convert_ram_to_param(t_vm *vm, int len, int *i_ptr, int j)
{
	int	index;

	index = *i_ptr;
	while (index < len)
	{
		vm->param[j][0] |= vm->vm[index % MEM_SIZE];
		if (index < len - 1)
			vm->param[j][0] <<= 8;
		index += 1;
	}
	*i_ptr = index;
	return (true);
}
