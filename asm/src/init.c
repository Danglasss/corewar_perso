/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:03:24 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/12 16:30:29 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		safe_open(char *av)
{
	int fd; 

	if ((fd = open(av, O_RDONLY)) == -1)
		return (FALSE);
	printf("FD\t\t\t"_GREEN"OK"_RESET"\n");
	return (fd);
}

/*
**	We only accept .s files -- ε (empty string) as filename not accepted.
*/

int		check_valid_argv(t_asm *env, char *av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 2] != '.' || av[i - 1] != 's' || !av[i - 3])
	{
		ft_putstr(FILE_ERR);
		return (FALSE);
	}
	if ((env->fd = safe_open(av)) == FALSE)
		return (FALSE);
	av[i - 2] = '\0';
	env->file_name = av;
	printf("CHECK_ARGV\t\t"_GREEN"OK"_RESET"\n");
	return (TRUE);
}

int		init(t_asm *env, char *av)
{
	if (check_valid_argv(env, av) == FALSE)
		return (FALSE);
	if (scan(env) == FALSE)
	{
		ft_putstr(MALLOC_ERR_MSG);
	}
	env->nb_newlines = 1;
	env->nb_char = 1;
	return (TRUE);
}
