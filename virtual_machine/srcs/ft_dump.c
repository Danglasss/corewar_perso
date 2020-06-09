/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:07:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/26 21:04:36 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

/*
** Dump : Fonction qui parcours la VM et Convertie/Print chaque Char en Hexa
*/

void	ft_dump(const unsigned char vm[MEM_SIZE])
{
	int		len;

	len = 0;
	while (len < MEM_SIZE)
	{
		if (len % 64 == 0)
			ft_printf("0x%.4x : ", len);
		if ((len + 1) % 64 == 0)
			ft_printf("%.2x\n", vm[len]);
		else
			ft_printf("%.2x ", vm[len]);
		len++;
	}
}
