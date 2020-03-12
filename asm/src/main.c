/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:55 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/10 23:11:26 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	t_asm	env;

	ft_bzero(&env, sizeof(t_asm));
	if (ac != 2 || init(&env, av[1]) == FALSE)
	{
		printf("INIT	"_RED"PROBLEM"_RESET"\n");
		return (FALSE);
	}
	printf("file_name = %s\n", env.file_name);
	return (0);
}
