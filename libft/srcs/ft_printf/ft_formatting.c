/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:41:49 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/31 18:39:14 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_arg_recover(t_flag *c_arg, char type, int base_l)
{
	if (type == 's')
	{
		ft_arg_signed(c_arg);
		c_arg->nb_u = 0;
		c_arg->radical = ft_radical_signed(c_arg->nb_s);
	}
	else
	{
		ft_arg_unsigned(c_arg);
		c_arg->nb_s = 0;
		c_arg->radical = ft_radical_unsigned(c_arg->nb_u, base_l);
	}
}

int		ft_pre_conversion(t_flag *c_arg, char type, int base_l)
{
	int	max;

	ft_arg_recover(c_arg, type, base_l);
	if (c_arg->precision == 0 && c_arg->nb_s == 0 && c_arg->nb_u == 0 &&
	!((c_arg->flag & SHARP_FLAG) && (c_arg->flag & O_FLAG)))
		c_arg->radical = 0;
	max = ft_max(c_arg->precision, c_arg->radical);
	if (((c_arg->flag & D_FLAG) && c_arg->nb_s >= 0 &&
	((PLUS_FLAG & c_arg->flag) || (SPACE_FLAG & c_arg->flag)))
	|| c_arg->nb_s < 0)
		c_arg->prefix += 1;
	if ((c_arg->flag & O_FLAG) && (SHARP_FLAG & c_arg->flag) &&
	c_arg->nb_u > 0)
		c_arg->radical += 1;
	if ((((c_arg->flag & X_FLAG) || (c_arg->flag & BIGX_FLAG)) &&
	(c_arg->flag & SHARP_FLAG) && c_arg->nb_u > 0) ||
	(c_arg->flag & P_FLAG))
		c_arg->prefix += 2;
	return (max);
}

void	ft_prefix(t_buffer *buff, t_flag *c_arg)
{
	int max;

	max = ft_max(c_arg->precision, c_arg->radical);
	if (c_arg->nb_s >= 0 && (PLUS_FLAG & c_arg->flag) && (c_arg->flag & D_FLAG))
		ft_write_in_buffer(buff, '+', 1);
	if (c_arg->nb_s >= 0 && (SPACE_FLAG & c_arg->flag) &&
	(c_arg->flag & D_FLAG))
		ft_write_in_buffer(buff, ' ', 1);
	if (c_arg->nb_s < 0)
		ft_write_in_buffer(buff, '-', 1);
	if ((c_arg->flag & O_FLAG) && (SHARP_FLAG & c_arg->flag)
	&& c_arg->nb_u > 0)
		ft_write_in_buffer(buff, '0', 1);
	if (((c_arg->flag & X_FLAG) && (c_arg->flag & SHARP_FLAG)
	&& c_arg->nb_u > 0) || (c_arg->flag & P_FLAG))
		ft_putstr_buffer(buff, "0x", 2);
	if ((c_arg->flag & BIGX_FLAG) && (c_arg->flag & SHARP_FLAG)
	&& c_arg->nb_u > 0)
		ft_putstr_buffer(buff, "0X", 2);
}

void	ft_padding(t_buffer *buff, t_flag *c_arg)
{
	int	max;

	max = ft_max(c_arg->precision, c_arg->radical);
	if (c_arg->lmc > (max + c_arg->prefix))
	{
		if (c_arg->flag & ZERO_FLAG && !(c_arg->flag & MINUS_FLAG))
			ft_write_in_buffer(buff, '0', c_arg->lmc - (max + c_arg->prefix));
		else if (!(c_arg->flag & ZERO_FLAG))
			ft_write_in_buffer(buff, ' ', c_arg->lmc - (max + c_arg->prefix));
	}
}
