/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:16:33 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

unsigned long	ft_power_signed(long nb, long pow)
{
	if (pow == 0)
		return (1);
	nb = nb * ft_power_signed(nb, pow - 1);
	return (nb);
}

unsigned long	ft_power_unsigned(unsigned long nb, long pow)
{
	if (pow == 0)
		return (1);
	nb = nb * ft_power_unsigned(nb, pow - 1);
	return (nb);
}
