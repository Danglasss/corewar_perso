/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:06:42 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include <stdarg.h>

static int			ft_signed(long nb)
{
	int				i;

	i = 1;
	if (nb < 0)
	{
		i += 1;
		ft_signed(-(nb / 10));
	}
	if ((nb / 10) > 0)
		ft_signed(nb / 10);
	return (i);
}

static int			ft_unsigned(int base, unsigned long nb)
{
	int				i;

	i = 0;
	while ((nb / base) != 0)
	{
		i += 1;
		nb /= base;
	}
	return (i + 1);
}

int					ft_nb_digit(int base, char *c, ...)
{
	va_list			list;
	unsigned long	ul;
	long			l;

	va_start(list, c);
	if (ft_strcmp(c, "u") == 0)
	{
		ul = (unsigned long)va_arg(list, unsigned long);
		return (ft_unsigned(base, ul));
	}
	if (ft_strcmp(c, "s") == 0)
	{
		l = (long)va_arg(list, long);
		return (ft_signed(l));
	}
	va_end(list);
	return (-1);
}
