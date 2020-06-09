/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:38:44 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_o_conversion(t_buffer *buff, t_flag *c_arg)
{
	int	max;

	c_arg->flag |= O_FLAG;
	max = ft_pre_conversion(c_arg, 'u', 8);
	if (c_arg->precision == 0 && c_arg->nb_u == 0 &&
	!(c_arg->flag & SHARP_FLAG))
		c_arg->radical = 0;
	if (!(c_arg->flag & MINUS_FLAG) && !(c_arg->flag & ZERO_FLAG))
		ft_padding(buff, c_arg);
	ft_prefix(buff, c_arg);
	if (c_arg->flag & ZERO_FLAG)
		ft_padding(buff, c_arg);
	if (c_arg->precision > c_arg->radical)
		ft_write_in_buffer(buff, '0', c_arg->precision - c_arg->radical);
	if (c_arg->radical)
		ft_convert_to_base(buff, c_arg, 'u', "01234567");
	if (c_arg->flag & MINUS_FLAG && (c_arg->lmc > (max + c_arg->prefix)))
		ft_padding(buff, c_arg);
}
