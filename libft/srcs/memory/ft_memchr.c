/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:19:01 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 16:37:11 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_buff;

	s_buff = (unsigned char*)s;
	index = 0;
	while (index < n)
	{
		if (s_buff[index] == (unsigned char)c)
			return (&s_buff[index]);
		index += 1;
	}
	return (NULL);
}
