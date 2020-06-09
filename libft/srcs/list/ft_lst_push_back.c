/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:24:57 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:29:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_lst_push_back(t_list **begin_lst, void *content, size_t content_size)
{
	t_list	*node;
	t_list	*head;
	t_list	*buff;

	if (!begin_lst)
		return ;
	buff = *begin_lst;
	head = *begin_lst;
	if (!(node = ft_lstnew((const void *)content, content_size)))
		return ;
	if (!buff)
		*begin_lst = node;
	else
	{
		while (buff->next)
			buff = buff->next;
		buff->next = node;
	}
	if (head)
		*begin_lst = head;
}
