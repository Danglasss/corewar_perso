/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:01:18 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/10 23:03:17 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		set_buffer(t_scan *scan)
{
	ft_bzero(scan, sizeof(t_scan));
	if (!(scan->buffer = (char *)ft_memalloc(sizeof(char) * BASE_MALLOC + 1)))
		return (FALSE);
	scan->reload = 1;
	return (TRUE);
}

static int		increase_buffer(t_scan *scan)
{
	char	*new_buffer;

	new_buffer = NULL;
	if (!(new_buffer = (char *)ft_memalloc(sizeof(char) 
					* BASE_MALLOC * ++scan->reload + 1)))
		return (FALSE);
	new_buffer = ft_strcpy(new_buffer, scan->buffer);
	free(scan->buffer);
	scan->buffer = new_buffer;
	return (TRUE);
}

static int		copy_fr_index(t_scan *scan, char *src, long index)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		scan->buffer[index] = src[i];
		index++;
		i++;
	}
	scan->buffer[index] = '\0';
	return (index);
}

static int		check_first_lines(t_scan scan)
{
	int i;

	i = 0;
	if (scan.buffer[0] == '\0')
		return (FALSE);
	while (scan.buffer[i] && ft_isspace(scan.buffer[i]) != 0)
		i++;
	if (!scan.buffer || scan.buffer[i++] != '.')
		return (FALSE);	
	if (!scan.buffer || (scan.buffer[i] != 'n' && scan.buffer[i] != 'c'))
		return (FALSE);	
	return (TRUE);
}

int			scan(t_asm *env)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	t_scan	scan;

	if (set_buffer(&scan) == FALSE)
		return (FALSE);
	while ((ret = read(env->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		scan.buff_len += ret;
		if (scan.buff_len >= (long)BASE_MALLOC * scan.reload)
			if (increase_buffer(&scan) == FALSE)
				return (FALSE);
		scan.index = copy_fr_index(&scan, buff, scan.index);
		if (scan.reload == 10)
			if (check_first_lines(scan) == FALSE)
			{	
				printf(_RED"\nSCAN PROBLEM\n\n"_RESET);
				break ;
			}
	}
	env->scan = scan;
	printf("SCAN\t\t\t"_GREEN"OK"_RESET"\n");
	return (TRUE);
}
