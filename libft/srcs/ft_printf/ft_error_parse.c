/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:55:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_error_parse(t_buffer *buff, t_flag *c_arg, char c)
{
	int sup;

	c_arg->radical = 1;
	sup = ft_higher_value(1, c_arg->lmc, UNCHANGED);
	if ((c_arg->flag & MINUS_FLAG))
		ft_write_in_buffer(buff, c, 1);
	if (!(c_arg->flag & MINUS_FLAG) && (c_arg->flag & ZERO_FLAG))
		ft_write_in_buffer(buff, '0', sup - c_arg->radical);
	if (c_arg->lmc != UNCHANGED)
		ft_write_in_buffer(buff, ' ', sup - c_arg->radical);
	if (!(c_arg->flag & MINUS_FLAG))
		ft_write_in_buffer(buff, c, 1);
}
