/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:37:41 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_c_conversion(t_buffer *buff, t_flag *c_arg)
{
	c_arg->flag |= C_FLAG;
	if (c_arg->flag & MINUS_FLAG)
	{
		ft_write_in_buffer(buff, (char)va_arg(c_arg->arg, int), 1);
		if (c_arg->lmc > 1)
			ft_write_in_buffer(buff, ' ', c_arg->lmc - 1);
	}
	else
	{
		if (c_arg->lmc > 1 && (c_arg->flag & ZERO_FLAG))
			ft_write_in_buffer(buff, '0', c_arg->lmc - 1);
		else if (c_arg->lmc > 1)
			ft_write_in_buffer(buff, ' ', c_arg->lmc - 1);
		ft_write_in_buffer(buff, (char)va_arg(c_arg->arg, int), 1);
	}
}
