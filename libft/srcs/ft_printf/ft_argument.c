/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 02:08:30 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

int					ft_radical_unsigned(unsigned long nb, int base)
{
	int				res;

	res = 1;
	if (!(nb / base))
		return (1);
	return (res += ft_radical_unsigned(nb / base, base));
}

int					ft_radical_signed(long nb)
{
	int				res;

	res = 1;
	if (!(nb / 10))
		return (1);
	if (nb < 0)
		return (res += ft_radical_signed(-(nb / 10)));
	return (res += ft_radical_signed(nb / 10));
}

void				ft_arg_unsigned(t_flag *c_arg)
{
	if ((c_arg->flag & MINL_FLAG) || (c_arg->flag & P_FLAG))
		c_arg->nb_u = (unsigned long)va_arg(c_arg->arg, unsigned long);
	else if (c_arg->flag & H_FLAG)
		c_arg->nb_u = (unsigned short)va_arg(c_arg->arg, unsigned int);
	else if (c_arg->flag & HH_FLAG)
		c_arg->nb_u = (unsigned char)va_arg(c_arg->arg, unsigned int);
	else if (c_arg->flag & MINLL_FLAG)
		c_arg->nb_u = (unsigned long long)va_arg(c_arg->arg,
		unsigned long long);
	else
		c_arg->nb_u = (unsigned int)va_arg(c_arg->arg, unsigned int);
}

void				ft_arg_signed(t_flag *c_arg)
{
	if (c_arg->flag & H_FLAG)
		c_arg->nb_s = (short)va_arg(c_arg->arg, int);
	else if (c_arg->flag & HH_FLAG)
		c_arg->nb_s = (char)va_arg(c_arg->arg, int);
	else if (c_arg->flag & MINL_FLAG)
		c_arg->nb_s = (long)va_arg(c_arg->arg, long);
	else if (c_arg->flag & MINLL_FLAG)
		c_arg->nb_s = (long long)va_arg(c_arg->arg, long long);
	else
		c_arg->nb_s = (int)va_arg(c_arg->arg, int);
}
