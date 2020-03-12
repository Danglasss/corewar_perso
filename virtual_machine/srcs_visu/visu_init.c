/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:14:08 by dygouin           #+#    #+#             */
/*   Updated: 2020/03/10 15:37:04 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	color_init();
{
	initpair(1, COlOR_GREY, COLOR_GREY);
	initpair(2, );
	initpair(3, );
	initpair(4, );
	initpair(5, );
	initpair(6, );
	initpair(7, );
	initpair(8, );
	initpair(9, );
	initpair(10, );
	initpair(11, );
}

void	ncurse_init(vm)
{
	t_status	status;

	ft_memalloc(&status, sizeof(t_status));
	status.pause = 1;
	status.speed = 40;
	status.process = /*nombre process vm*/;
	status.delay = 100
	initscr();
	startcolor();
	raw();
	keypad(/*window*/, TRUE);

}
