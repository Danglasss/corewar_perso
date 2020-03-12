/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:36:55 by damboule          #+#    #+#             */
/*   Updated: 2020/03/12 14:54:20 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_getoccur(char *args, const char *cor)
{
	int length;
	int answer;

	answer = 1;
	length = ft_strlen(args) - 4;
	if (length >= 1)
		answer = ft_strncmp(args + length, cor, 3);
	return (answer);
}

int		ft_get_filecor(int nb_args, char **args, t_args *filecor, t_option *op)
{
	int		index;

	index = 0;
	while (index < nb_args)
	{
		if (ft_strcmp(args[index], "-n") == 0
				&& ft_check_int(args[index + 1]) == 0)
			filecor->pos[filecor->player_nb] = ft_atoi(args[index + 1]);
		else if (ft_getoccur(args[index], ".cor") == 0
				&& filecor->player_nb <= 4)
			filecor->champ[filecor->player_nb++] = ft_strdup(args[index]);
		else if (ft_get_options(index, args, op))
			return (EXIT_FAILURE);
		index++;
	}
	if (filecor->player_nb >= 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		ft_get_args(const int nb_arg, char **arg, t_args *filecor, t_option *op)
{
	if (nb_arg == NO_ARGS)
		return (ft_usage(0));
	if (ft_get_filecor(nb_arg, arg, filecor, op))
		return (ft_usage(1));
	return (EXIT_SUCCESS);
}

int		ft_parse(int nb_args, char **args, unsigned char vm[MEM_SIZE])
{
	t_args			filecor;
	t_option		option;
	t_player		players[4];

	ft_bzero(&players, sizeof(players));
	ft_bzero(&option, sizeof(option));
	ft_bzero(&filecor, sizeof(filecor));
	if (!(filecor.champ = (char **)ft_memalloc(sizeof(char *) * (4 + 1))))
		return (EXIT_FAILURE);
	if (ft_get_args(nb_args, args, &filecor, &option))
		return (ft_free_filecor(&filecor));
	if (ft_insertion_vm(&filecor, vm, players))
		return (ft_free_filecor(&filecor));
	ft_free_filecor(&filecor);
	exit(1);
	return (EXIT_SUCCESS);
}
