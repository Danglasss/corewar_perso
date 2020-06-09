/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:42:11 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 16:46:29 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_lst(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		lst = lst->next;
	}
}
