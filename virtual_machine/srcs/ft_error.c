/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:08:59 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/26 21:07:47 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

char	g_tab[7][128] =
{
	"No valid \".cor\" file found.\n",
	"Option or file \".cor\" are invalid : \"--help\" for usage.\n",
	"The file \".cor\" can't ba open.\n",
	"Probleme with the magic header.\n",
	"Probleme with size of the champion name.\n",
	"Probleme with size of the executable code.\n",
	"Probleme with size of the comment.\n"
	"-n number is too low or to hight or is double.\n"
};

void	ft_print_error(int usage)
{
	ft_putstr(g_tab[usage]);
}

int		ft_usage(int usage)
{
	if (usage == 0)
	{
		ft_putstr("| Usage: ./corewar [-d N -v N | -n]");
		ft_putstr(" <champion1.cor> <...> |\n");
		ft_putstr(" ####  VERBOSE\n");
		ft_putstr("-v N	: Verbosity levels (0 : Show only essentials)\n\n");
		ft_putstr("####  VISUALISATEUR ");
		ft_putstr("\n-visu   : Bonus viewer cant");
		ft_putstr(" print memory with colors...\n\n");
		ft_putstr("####  PLAYER_POSITION\n");
		ft_putstr("-n N    : Choice the positionement of the players\n\n");
		ft_putstr("####  DUMP\n");
		ft_putstr("-dump N : Print the memory after N cycle\n\n");
	}
	else
		ft_print_error(usage - 1);
	return (EXIT_FAILURE);
}
