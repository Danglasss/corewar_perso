/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:41:59 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/10 23:08:29 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

# include "tokens.h"
# include "op.h"
# include "../../libft/includes/libft.h"

/*
** Program constants
*/

# define TRUE 				1
# define FALSE 				0
# define MAX_INSTRUCTIONS	16
# define BUFF_SIZE			10//8192
# define BASE_MALLOC		20//16384

/*
** Error messages
*/

# define FILE_ERROR			"Please specify an input file ending with .s\n"

# define COUCOU				printf("COUCOU\n")
typedef struct	s_scan
{
	char		*buffer;
	int			buff_len;
	int			reload;
	long		index;
}				t_scan;

typedef struct	s_token
{
//	e_tokens


}				t_token;

typedef struct 	s_asm
{
	int 		fd;
	char		*file_name;
	char		*champ_name;
	char		*comment;
	t_scan		scan;
}				t_asm;


int				init(t_asm *env, char *av);
int				check_valid_argv(t_asm *env, char *av);
int				safe_open(char *av);
int				scan(t_asm *env);


/*
** Colors
*/ 

# define _RED			"\x1b[31m"
# define _BLUE			"\x1b[34m"	
# define _GREEN			"\x1b[32m"
# define _RESET			"\x1b[0m"	

#endif
