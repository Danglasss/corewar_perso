/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:39:55 by paul              #+#    #+#             */
/*   Updated: 2020/03/25 19:41:58 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/macro.h"
#include "../../includes/prototypes.h"
#include "../../includes/tab.h"

t_tab	g_f_tab[127] =
{
	['%'] = ft_percent_conversion,
	['X'] = ft_bigx_conversion,
	['c'] = ft_c_conversion,
	['d'] = ft_d_conversion,
	['i'] = ft_d_conversion,
	['o'] = ft_o_conversion,
	['p'] = ft_p_conversion,
	['s'] = ft_s_conversion,
	['u'] = ft_u_conversion,
	['x'] = ft_x_conversion,
};

char	g_auth_c_tab[NB_AUTH_C] =
{
	'+',
	'-',
	' ',
	'#',
	'0',
	'l',
	'h',
	'L',
	'c',
	's',
	'p',
	'd',
	'i',
	'o',
	'u',
	'x',
	'X',
	'%'
};

int		g_bin[127] =
{
	['#'] = SHARP_FLAG,
	['0'] = ZERO_FLAG,
	['+'] = PLUS_FLAG,
	['-'] = MINUS_FLAG,
	[' '] = SPACE_FLAG,
	['h'] = H_FLAG,
	['l'] = MINL_FLAG,
	['L'] = MAJL_FLAG,
	['j'] = MINLL_FLAG,
	['z'] = MINL_FLAG
};

char	g_opt_auth[NB_OPT] =
{
	'#',
	'+',
	'-',
	'0',
	' '
};

char	g_size_auth[NB_SIZE] =
{
	'h',
	'l',
	'L',
	'j',
	'z'
};

char	g_conv_auth[NB_CONV] =
{
	'c',
	's',
	'p',
	'd',
	'i',
	'o',
	'u',
	'x',
	'X',
	'%'
};
