/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:05:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:35:31 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/tab.h"

static void	ft_size_flag(char c, int double_c, t_flag *c_arg)
{
	int		mask;

	mask = g_bin[(int)c];
	if (double_c == TRUE)
		mask <<= 1;
	c_arg->flag |= mask;
}

void		ft_size(const char **format, t_flag *c_arg)
{
	int		i;

	i = 0;
	while (i < NB_SIZE)
	{
		if (**format == g_size_auth[i++])
		{
			if ((*(*format + 1) == **format)
			|| (c_arg->flag & g_bin[(int)**format]))
			{
				ft_size_flag(**format, TRUE, c_arg);
				*format += 2;
			}
			else
			{
				ft_size_flag(**format, FALSE, c_arg);
				*format += 1;
			}
			i = NB_SIZE;
		}
	}
}
