/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:42:39 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:35:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/tab.h"

int					ft_opt_auth(char c)
{
	int				i;

	i = 0;
	while (i < NB_OPT)
	{
		if (c == g_opt_auth[i++])
			return (TRUE);
	}
	return (FALSE);
}

static void			ft_duplicate(char c, char *tab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (c == tab[i++])
			return ;
	}
	tab[i] = c;
}

static void			ft_flag_opt_set(char tab[NB_OPT], t_flag *c_arg)
{
	int				i;

	i = 0;
	while (tab[i])
		c_arg->flag |= g_bin[(int)tab[i++]];
}

void				ft_option(const char **format, t_flag *c_arg)
{
	char			tab[NB_OPT + 1];

	ft_bzero(tab, NB_OPT + 1);
	while (ft_opt_auth(**format) == TRUE)
	{
		ft_duplicate(**format, tab);
		*format += 1;
	}
	ft_flag_opt_set(tab, c_arg);
}
