/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 13:01:40 by danglass          #+#    #+#             */
/*   Updated: 2020/05/26 20:38:48 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

char	g_player_tab[5][12] =
{
	"* Player 1,",
	"* Player 2,",
	"* Player 3,",
	"* Player 4,",
};

int		ft_print_player(t_player player)
{
	ft_putstr(g_player_tab[player.index_player - 1]);
	ft_putstr(" weighing ");
	ft_putstr(player.size);
	ft_putstr(" bytes, \"");
	ft_putstr(player.name);
	ft_putstr("\" (\"");
	ft_putstr(player.comment);
	ft_putstr("\") !\n");
	return (EXIT_SUCCESS);
}

int		ft_print_intro(t_player player[4])
{
	int		index;
	int		players;
	int		stop;

	index = 0;
	players = 1;
	stop = -1;
	ft_putstr("Introducing contestants...\n");
	while (index < 4)
	{
		if (player[index].index_player == players && (stop = 1))
			ft_print_player(player[index]);
		index++;
		if (index == 4 && stop == 1)
		{
			index = 0;
			players++;
			stop = -1;
		}
	}
	return (EXIT_SUCCESS);
}
