/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:02:39 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 19:40:18 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTTAB_H

# define LIBFTTAB_H

typedef void				(*t_tab)(t_buffer *, t_flag *);

extern char	*g_m_tab[64];
extern t_tab	g_f_tab[127];
extern char	g_auth_c_tab[NB_AUTH_C];
extern int	g_bin[127];
extern char	g_opt_auth[NB_OPT];
extern char	g_size_auth[NB_SIZE];
extern char	g_conv_auth[NB_CONV];
#endif
