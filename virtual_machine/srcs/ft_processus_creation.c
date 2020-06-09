/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_creation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:02:44 by paul              #+#    #+#             */
/*   Updated: 2020/06/04 17:28:53 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/tab.h"

t_process		*ft_processus_cpy(t_process *processus, size_t pc, size_t no)
{
	t_process	*new_processus;

	if (!(new_processus = ft_processus_create(no, pc)))
		return (NULL);
	ft_memcpy(&(new_processus->registre), &(processus->registre),
	16 * sizeof(int));
	new_processus->carry = processus->carry;
	return (new_processus);
}

t_process		*ft_processus_create(const size_t no, const size_t pc)
{
	t_process	*processus;

	if (!(processus = (t_process *)ft_memalloc(sizeof(t_process))))
		return (NULL);
	processus->no = no;
	processus->pc = pc % MEM_SIZE;
	return (processus);
}
