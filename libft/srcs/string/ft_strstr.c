/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:49:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 16:51:27 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;
	char	*h_buff;
	char	*n_buff;

	index = 0;
	h_buff = (char *)haystack;
	n_buff = (char *)needle;
	if (n_buff[0] == 0)
		return (h_buff);
	while (*h_buff != '\0')
	{
		while (h_buff[index] == n_buff[index] && n_buff[index] != 0)
			index += 1;
		if (!(n_buff[index]))
			return (h_buff);
		else
			index = 0;
		h_buff += 1;
	}
	return (NULL);
}
