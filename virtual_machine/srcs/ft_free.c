/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:14:40 by damboule          #+#    #+#             */
/*   Updated: 2020/03/11 14:53:04 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

void		free_tab(char **filecor)
{
	int		index;

	index = 0;
	while (index < 5)
	{
		filecor[index] = NULL;
		free(filecor[index]);
		index++;
	}
	filecor = NULL;
	free(filecor);
}

int		ft_free_filecor(t_args *filecor)
{
	free_tab(filecor->champ);
	filecor = NULL;
	return (1);
}
