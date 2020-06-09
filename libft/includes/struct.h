/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:01:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/31 18:03:49 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSTRUCT_H

# define LIBFTSTRUCT_H

# include <stdlib.h>
# include <stdarg.h>
# include "macro.h"

typedef struct		s_buffer
{
	int				count;
	int				buff_i;
	char			buffer[BUFF_SIZE + 1];
}					t_buffer;

typedef struct		s_flag
{
	int				flag;
	int				lmc;
	int				precision;
	int				radical;
	int				prefix;
	long			nb_s;
	unsigned long	nb_u;
	char			*str;
	va_list			arg;
}					t_flag;

typedef struct		s_base
{
	char			*base_t;
	int				base_l;
}					t_base;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
