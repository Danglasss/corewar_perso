/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:30:42 by danglass          #+#    #+#             */
/*   Updated: 2020/05/26 20:37:47 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <stdlib.h>

int		ft_double_option(t_args *filecor)
{
	int index;
	int check;
	int	i;

	index = 0;
	while (index < 4)
	{
		check = 0;
		i = 0;
		while (i < 4)
		{
			if (filecor->option[i++] == index + 1)
				check += 1;
		}
		if (check >= 2)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}

int		ft_check_tab(t_args *filecor, int value)
{
	int	i;

	i = 0;
	while (i < filecor->player_nb)
	{
		if (filecor->option[i++] == value)
			return (TRUE);
	}
	return (FALSE);
}

void	ft_replace_tab(t_args *filecor, int value)
{
	int	i;

	i = 0;
	while (i < filecor->player_nb)
	{
		if (filecor->option[i] == 0)
		{
			filecor->option[i] = value;
			return ;
		}
		i += 1;
	}
}

int		ft_wrong_number_player(t_args *filecor)
{
	int	i;

	i = 0;
	while (i < filecor->player_nb)
	{
		if (filecor->option[i] > filecor->player_nb)
			return (FALSE);
		i += 1;
	}
	return (TRUE);
}

int		ft_get_pos_player(t_args *filecor)
{
	int index;

	if (ft_double_option(filecor) || ft_wrong_number_player(filecor) == FALSE)
		return (EXIT_FAILURE);
	index = 0;
	while (index < filecor->player_nb)
	{
		if (ft_check_tab(filecor, index + 1) == FALSE)
			ft_replace_tab(filecor, index + 1);
		index += 1;
	}
	return (EXIT_SUCCESS);
}
