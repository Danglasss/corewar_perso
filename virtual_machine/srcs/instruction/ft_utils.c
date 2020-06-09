/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:34:14 by paul              #+#    #+#             */
/*   Updated: 2020/06/08 10:31:08 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/op.h"

uint32_t		ft_convert_to_int(unsigned char tab[4])
{
	uint32_t	result;
	int			index;

	result = 0;
	index = 0;
	while (index < 4)
	{
		result |= tab[index];
		if (index < 3)
			result <<= 8;
		index++;
	}
	return (result);
}

void			ft_convert_to_char(t_vm *vm, int reg, int pos)
{
	int			i;

	i = 0;
	pos = (pos >= 0 ? pos : MEM_SIZE + pos);
	while (i < 4)
	{
		vm->vm[pos % MEM_SIZE] = reg;
		pos = (pos > 0 ? pos - 1 : MEM_SIZE + (pos - 1));
		reg >>= 8;
		i += 1;
	}
}

int				ft_parameter_recover_value(t_vm *vm, size_t pc,
					uint32_t tab[2], t_process *process)
{
	if (tab[1] == T_IND)
		return (ft_value_from_address(pc, tab[0], vm));
	if (tab[1] == T_REG)
		return (process->registre[tab[0] - 1]);
	return (tab[0]);
}

int				ft_unrestr_value_from_address(size_t pc, short indirect,
												t_vm *vm)
{
	int			param;
	int			pos;
	uint8_t		tab[4];

	pos = (pc + indirect) % MEM_SIZE;
	tab[0] = vm->vm[pos++ % MEM_SIZE];
	tab[1] = vm->vm[pos++ % MEM_SIZE];
	tab[2] = vm->vm[pos++ % MEM_SIZE];
	tab[3] = vm->vm[pos % MEM_SIZE];
	param = ft_convert_to_int(tab);
	return (param);
}

int				ft_value_from_address(size_t pc, short indirect, t_vm *vm)
{
	int			param;
	int			pos;
	uint8_t		tab[4];

	pos = (pc + (indirect % IDX_MOD)) % MEM_SIZE;
	tab[0] = vm->vm[pos++ % MEM_SIZE];
	tab[1] = vm->vm[pos++ % MEM_SIZE];
	tab[2] = vm->vm[pos++ % MEM_SIZE];
	tab[3] = vm->vm[pos % MEM_SIZE];
	param = ft_convert_to_int(tab);
	return (param);
}
