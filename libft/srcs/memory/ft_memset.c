/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:49:41 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 15:33:33 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s_buff;
	unsigned char	c_buff;

	s_buff = (unsigned char*)b;
	c_buff = (unsigned char)c;
	while (len-- > 0)
		*(s_buff++) = c_buff;
	return (b);
}
