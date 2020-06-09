/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:52:36 by damboule          #+#    #+#             */
/*   Updated: 2020/05/26 18:00:18 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

int		ft_check_int(char *nombr)
{
	int		result;

	result = ft_atoi(nombr);
	if ((result <= 0 && nombr[0] != '0'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_filloption(int *option, int *value, char **args, int index)
{
	if (ft_check_int(args[index + 1]))
		return (EXIT_FAILURE);
	*option = 1;
	*value = ft_atoi(args[index + 1]);
	return (EXIT_SUCCESS);
}

int		ft_get_options(int index, char **args, t_option *option)
{
	if (ft_strcmp(args[index], "--visu") == 0 && (option->visu = 1))
		return (EXIT_SUCCESS);
	else if (ft_strcmp(args[index], "-dump") == 0)
		return (ft_filloption(&option->d[0], &option->d[1], args, index));
	else if (ft_strcmp(args[index], "-v") == 0)
		return (ft_filloption(&option->v[0], &option->v[1], args, index));
	else if (ft_check_int(args[index]) == 0
			&& (ft_strcmp(args[index - 1], "-dump") == 0
				|| ft_strcmp(args[index - 1], "-v") == 0
					|| ft_strcmp(args[index - 1], "-n") == 0))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
