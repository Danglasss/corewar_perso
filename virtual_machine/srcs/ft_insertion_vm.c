/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:59:05 by damboule          #+#    #+#             */
/*   Updated: 2020/03/12 17:11:36 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_convert_to_int(unsigned char tab[4])
{
	int		result;
	int		index;

	result = 0;
	index = 0;
	while (index < 4)
	{
		result |= tab[index];
		if (index < 3)
			result <<= 8;
		index++;
	}
	return (result);
}

void	ft_cpy_printablechar(char *dst, unsigned char *src, int max)
{
	int index;
	int	a;

	a = 0;
	index = 0;
	while (index < max)
	{
		if (src[index])
		{
			dst[a] = src[index];
			a++;
		}
		index++;
	}
	dst[index] = '\0';
	return ;
}

int		ft_players_data(int fd, char *player, int value_read)
{
	unsigned char	name[value_read];

	if (read(fd, name, value_read) < value_read)
		return (EXIT_FAILURE);
	if (MAGIC == value_read && ft_convert_to_int(name) != COREWAR_EXEC_MAGIC)
		return (EXIT_FAILURE);
//	if (SIZE_EXEC == value_read) //&& name != )
	ft_cpy_printablechar(player, name, value_read);
	return (EXIT_SUCCESS);
}

int		ft_read(const char *filecor,
				unsigned char vm[MEM_SIZE], int write_pos, t_player *player)
{
	char	skip[NOT_READ + 1];
	int		fd;
	
	if ((fd = open(filecor, O_RDONLY)) == -1)
		return (ft_usage(3));
	if (ft_players_data(fd, player->magic, MAGIC))
		return (ft_usage(4));
	if (ft_players_data(fd, player->name, READ_NAME))
		return (ft_usage(4));
	read(fd, skip, NOT_READ);
	if (ft_players_data(fd, player->size, SIZE_EXEC))
		return (ft_usage(5));
	if (ft_players_data(fd, player->comment, READ_COM))
		return (ft_usage(5));
	read(fd, skip, NOT_READ);
	if (read(fd, vm + write_pos, TO_READ + 1) > TO_READ)
		return (ft_usage(6));
	return (EXIT_SUCCESS);
}

int		ft_insertion_vm(const t_args *filecor,
						unsigned char vm[MEM_SIZE], t_player player[4])
{
	int		write_pos;
	int		nb_champ;

	nb_champ = 0;
	while (filecor->champ[nb_champ] != NULL)
	{
		write_pos = (MEM_SIZE / filecor->player_nb) * nb_champ;
		if (ft_read(filecor->champ[nb_champ], vm, write_pos, &player[nb_champ]))
			return (EXIT_FAILURE);
		nb_champ++;
	}
	return (EXIT_SUCCESS);
}
