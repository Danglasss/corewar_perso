/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:17:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 16:47:56 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static unsigned int	digit_count(int n)
{
	unsigned int	count;

	count = 0;
	while ((n / 10) != 0)
	{
		count += 1;
		n /= 10;
	}
	return (count + 1);
}

char				*ft_itoa(int n)
{
	char			*str;
	char			sign;
	int				count;

	sign = 0;
	count = digit_count(n);
	if (n < 0)
		sign += 1;
	if (!(str = (char*)malloc(sizeof(char) * (count + sign + 1))))
		return (NULL);
	str[count + sign] = 0;
	if (n < 0)
		str[0] = '-';
	while (count > 0)
	{
		str[count + sign - 1] = abs_value(n % 10) + '0';
		count -= 1;
		n /= 10;
	}
	return (str);
}
