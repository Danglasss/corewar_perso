/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:13:43 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

static void			ft_signed_conversion(long nb, t_base *base, long order,
t_buffer *buff)
{
	long			digit;

	if (order >= 0)
	{
		digit = ft_power_signed(base->base_l, order);
		if (nb < 0)
		{
			ft_write_in_buffer(buff, base->base_t[-(nb / digit)], 1);
			nb += -(nb / digit) * digit;
			ft_signed_conversion(-nb, base, order - 1, buff);
		}
		else
		{
			ft_write_in_buffer(buff, base->base_t[nb / digit], 1);
			nb -= (nb / digit) * digit;
			ft_signed_conversion(nb, base, order - 1, buff);
		}
	}
}

static void			ft_unsigned_conversion(unsigned long nb, t_base *base,
int order, t_buffer *buff)
{
	unsigned long	digit;

	if (order >= 0)
	{
		digit = ft_power_unsigned(base->base_l, order);
		if (order >= 0)
		{
			ft_write_in_buffer(buff, base->base_t[nb / digit], 1);
			nb -= (nb / digit) * digit;
			ft_unsigned_conversion(nb, base, order - 1, buff);
		}
	}
}

unsigned int		ft_order(t_flag *c_arg, char type, int base_l)
{
	unsigned long	order;
	unsigned long	tmp_ulong;
	long			tmp_long;

	order = 0;
	tmp_ulong = c_arg->nb_u;
	tmp_long = c_arg->nb_s;
	if (type == 'u')
	{
		order = 0;
		while (tmp_ulong)
		{
			tmp_ulong /= base_l;
			order += 1;
		}
	}
	if (type == 's')
	{
		while (tmp_long)
		{
			tmp_long /= base_l;
			order += 1;
		}
	}
	return (order > 0 ? order - 1 : 0);
}

void				ft_convert_to_base(t_buffer *buff, t_flag *c_arg,
int type, char *b)
{
	t_base			base;
	unsigned int	order;

	base.base_t = b;
	base.base_l = ft_strlen(b);
	if (type == 'u')
	{
		order = ft_order(c_arg, 'u', base.base_l);
		ft_unsigned_conversion(c_arg->nb_u, &base, order, buff);
	}
	if (type == 's')
	{
		order = ft_order(c_arg, 's', base.base_l);
		ft_signed_conversion(c_arg->nb_s, &base, order, buff);
	}
}
