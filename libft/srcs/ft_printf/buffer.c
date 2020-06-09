/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:09:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:34:11 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include <unistd.h>

void	ft_flush_buffer(t_buffer *buff)
{
	buff->count += buff->buff_i;
	write(1, buff->buffer, buff->buff_i);
	ft_bzero(buff->buffer, BUFF_SIZE + 1);
	buff->buff_i = 0;
}

void	ft_putstr_buffer(t_buffer *buff, char *str, int len)
{
	while (len > (BUFF_SIZE - buff->buff_i))
	{
		len -= BUFF_SIZE - buff->buff_i;
		ft_strncpy(buff->buffer + buff->buff_i, str, BUFF_SIZE - buff->buff_i);
		str += BUFF_SIZE - buff->buff_i;
		buff->buff_i += BUFF_SIZE - buff->buff_i;
		ft_flush_buffer(buff);
	}
	if (len)
	{
		ft_strncpy(buff->buffer + buff->buff_i, str, len);
		buff->buff_i += len;
	}
}

void	ft_write_in_buffer(t_buffer *buff, char c, int len)
{
	while (len > (BUFF_SIZE - buff->buff_i))
	{
		len -= BUFF_SIZE - buff->buff_i;
		while (buff->buff_i < BUFF_SIZE)
		{
			buff->buffer[buff->buff_i] = c;
			buff->buff_i += 1;
		}
		ft_flush_buffer(buff);
	}
	while (len)
	{
		buff->buffer[buff->buff_i] = c;
		buff->buff_i += 1;
		len -= 1;
	}
}
