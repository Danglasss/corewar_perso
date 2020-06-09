/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:32:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	index;
	size_t	s1_len;

	index = 0;
	s1_len = ft_strlen(s1);
	while (s2[index] != 0)
	{
		s1[index + s1_len] = s2[index];
		index += 1;
	}
	s1[index + s1_len] = 0;
	return (s1);
}
