/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:36:57 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLOBAL_H
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

static void			ft_reset_arg(t_flag *c_arg)
{
	c_arg->lmc = UNCHANGED;
	c_arg->precision = UNCHANGED;
	c_arg->flag = 0;
	c_arg->radical = 1;
	c_arg->prefix = 0;
}

static void			ft_initialization(t_buffer *buff_s, t_flag *c_arg)
{
	buff_s->count = 0;
	buff_s->buff_i = 0;
	ft_bzero(buff_s->buffer, BUFF_SIZE + 1);
	ft_reset_arg(c_arg);
}

int					ft_printf(const char *format, ...)
{
	t_flag			c_arg;
	t_buffer		buff;

	va_start(c_arg.arg, format);
	ft_initialization(&buff, &c_arg);
	if (!format)
		return (0);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format += 1;
			ft_parser(&format, &buff, &c_arg);
			ft_reset_arg(&c_arg);
		}
		else
			ft_write_in_buffer(&buff, *format, 1);
		if (*format)
			format += 1;
	}
	ft_flush_buffer(&buff);
	return (buff.count);
}
