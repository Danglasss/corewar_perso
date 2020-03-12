/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:52:36 by damboule          #+#    #+#             */
/*   Updated: 2020/03/12 14:53:23 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_check_int(char *nombr)
{
	int		result;

	result = ft_atoi(nombr);
	if ((result == 0 && nombr[0] != '0') || result > 10000)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_filloption(int (*option)[2], char **args, int index)
{
	if (ft_check_int(args[index + 1]))
		return (EXIT_FAILURE);
	*option[0] = 1;
	*option[1] = ft_atoi(args[index + 1]);
	return (EXIT_SUCCESS);
}

int		ft_get_options(int index, char **args, t_option *option)
{
	if (ft_strcmp(args[index], "-visu") == 0 && (option->visu = 1))
		return (EXIT_SUCCESS);	
	else if (ft_strcmp(args[index], "-dump") == 0)
		return (ft_filloption(&option->d, args, index));
	else if (ft_strcmp(args[index], "-v") == 0)
		return (ft_filloption(&option->v, args, index));
	else if (ft_check_int(args[index]) == 0
			&& (ft_strcmp(args[index - 1], "-dump") == 0
				|| ft_strcmp(args[index - 1], "-v") == 0
					|| ft_strcmp(args[index - 1], "-n") == 0))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
