/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisateur.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:52:10 by dygouin           #+#    #+#             */
/*   Updated: 2020/03/10 15:37:09 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISATEUR_H
# define VISUALISATEUR_H

#include <ncurses.h>
#include <signal.h>
#include "struct.h"

#define COLOR_GREY 20
#define COLOR_WHITE 21

#define ESC 32
#define SPACE 27

typedef struct		s_windows
{
	WINDOW		*game;
	WINDOW		*infos;
}					t_windows

typedef struct		s_status
{
	int		pause;
	int		speed;
	int		process;
	int		delay;
}					t_status

#endif
