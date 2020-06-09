/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:39:26 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_s_conversion(t_buffer *buff, t_flag *c_arg)
{
	int		len;
	char	*str;

	str = (char *)va_arg(c_arg->arg, char *);
	if (!str)
		str = "(null)";
	len = (c_arg->precision != UNCHANGED && c_arg->precision < ft_strlen(str)
	? c_arg->precision : ft_strlen(str));
	if (!(c_arg->flag & MINUS_FLAG) && (c_arg->lmc > len) &&
	(c_arg->flag & ZERO_FLAG))
		ft_write_in_buffer(buff, '0', c_arg->lmc - len);
	else if (!(c_arg->flag & MINUS_FLAG) && (c_arg->lmc > len))
		ft_write_in_buffer(buff, ' ', c_arg->lmc - len);
	ft_putstr_buffer(buff, str, len);
	if ((c_arg->flag & MINUS_FLAG) && (c_arg->lmc > len))
		ft_write_in_buffer(buff, ' ', c_arg->lmc - len);
}
