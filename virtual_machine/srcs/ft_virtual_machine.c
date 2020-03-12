/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_virtual_machine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:27:38 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/11 13:39:13 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/virtual_machine.h"
#include "../includes/struct.h"

void	ft_create_vm(t_vm *vm_struct)
{
	vm_struct->player_list = NULL;
	vm_struct->param[0][0] = 0;
	vm_struct->param[0][1] = 0;
	vm_struct->param[1][0] = 0;
	vm_struct->param[1][1] = 0;
	vm_struct->param[2][0] = 0;
	vm_struct->param[2][1] = 0;

	bzero(vm_struct->vm, MEM_SIZE);
	vm_struct->vm[0] = 1;
	vm_struct->vm[1] = 144;
	vm_struct->vm[2] = 255;
	vm_struct->vm[3] = 255;
	vm_struct->vm[4] = 255;
	vm_struct->vm[5] = 255;
	vm_struct->vm[6] = 2;
	vm_struct->vm[7] = 2;
	vm_struct->vm[8] = 84;
	vm_struct->vm[9] = 2;
	vm_struct->vm[10] = 3;
	vm_struct->vm[11] = 4;
	
	vm_struct->vm[2048] = 1;
	vm_struct->vm[2049] = 144;
	vm_struct->vm[2050] = 255;
	vm_struct->vm[2051] = 255;
	vm_struct->vm[2052] = 255;
	vm_struct->vm[2053] = 255;
	vm_struct->vm[2054] = 2;
	vm_struct->vm[2055] = 2;
	vm_struct->vm[2056] = 84;
	vm_struct->vm[2057] = 2;
	vm_struct->vm[2058] = 3;
	vm_struct->vm[2059] = 4;

}