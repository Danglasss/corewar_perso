/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:17:18 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/12 18:46:04 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_newline_update(t_asm *env)
{
	env->nb_char += 1;
	if (*env->scan.buffer == '\n')
	{	
		env->nb_newlines += 1;
		env->nb_char = 0;
	}
}

void    pass_whitespaces(t_asm *env, t_scan *scan)
{
	while (*scan->buffer && ft_isspace(*scan->buffer) != 0)
	{
		check_newline_update(env);
		scan->buffer++;
	}
}

int		jump_comment(char **buffer)
{
	int size; 

	printf("[0] == %c\n", *buffer[0]);
	if (*buffer[0] == '#')
	{
		size = ft_strclen(*buffer, '\n');
		printf("%d\n", size);
		*buffer += size;
		printf("== %c\n", **buffer);
		return (TRUE);
	}
	return (FALSE);

}

void	forward_buffer(t_asm *env, int size)
{
	int i;

	i = 0;
	while (*env->scan.buffer && i < size)
	{
		env->nb_char += 1;
		if (*env->scan.buffer == '\n')
		{
			env->nb_newlines += 1;
			env->nb_char = 1;
		}
		i++;
		env->scan.buffer += 1;
	}
}
