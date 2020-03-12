/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:08:59 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/12 14:18:29 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

char	tab[6][128] = 
{
	"No valid \".cor\" file found.\n",
	"Option are invalid : \"--help\" for usage.\n",
	"The file \".cor\" is not valid.\n",
	"Probleme about the joueur name.\n",
	"The size of the champion is to small.\n",
	"The size of the champion is to big.\n"
};

void	ft_print_error(int usage)
{
	ft_putstr(tab[usage]);
}

int		ft_usage(int usage)
{
	if (usage == 0)
	{
		ft_putstr("Usage: ./corewar [-d N -v N | -n] <champion1.cor> <...>\n");
		ft_putstr("#### TEXT OUTPUT MODE");
		ft_putstr(" ###################################################\n\n");
		ft_putstr("-v N	: Verbosity levels\n");
		ft_putstr("\n          - 0 : Show only essentials\n\n");
		ft_putstr("####  VISUALISATEUR ");
		ft_putstr(" ###################################################\n\n");
		ft_putstr("-n        : Incredible visu from our mate\n\n");
	}
	else
		ft_print_error(usage - 1);
	return (EXIT_FAILURE);
}