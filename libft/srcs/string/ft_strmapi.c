/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:34:24 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:32:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	index;

	index = 0;
	if (s != NULL)
	{
		str = ft_strdup(s);
		if (!str)
			return (NULL);
	}
	else
		return (NULL);
	while (str[index] != 0)
	{
		str[index] = f(index, str[index]);
		index += 1;
	}
	return (str);
}
