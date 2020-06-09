/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:57:08 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:32:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*new;
	t_list	*buff;

	buff = NULL;
	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		buff = f(lst);
		ft_lst_push_back(&new, buff->content, buff->content_size);
		free(buff);
		lst = lst->next;
	}
	return (new);
}
