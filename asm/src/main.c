/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:55 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/12 17:35:46 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		reach_cmd_comname(t_asm *env, t_scan *scan)
{
	pass_whitespaces(env, scan);
	if (!*scan->buffer || *scan->buffer != '.')
		return (FALSE);
	return (TRUE);
}

int		check_max_size(char *dupped, int choice)
{
	int		len;

	len = ft_strlen(dupped);
	if (choice == CHOICE_CHAMP && len > PROG_NAME_LENGTH)
	{
		ft_putstr(CHAMP_SIZE_ERR);
		return (FALSE);
	}
	else if (choice == CHOICE_COM && len > COMMENT_LENGTH)
	{
		ft_putstr(COMMENT_SIZE_ERR);
		return (FALSE);
	}
	return (TRUE);
}

int		get_comname(t_asm *env, t_scan *scan, int choice)
{
	char	*dupped;
	
	choice == CHOICE_CHAMP 
			? (forward_buffer(env, ft_strlen(NAME_CMD_STRING)))
			: (forward_buffer(env, ft_strlen(COMMENT_CMD_STRING)));
	pass_whitespaces(env, scan);
//	printf("== %c\n", *scan->buffer);
	if (*scan->buffer++ != '"')
		return (FALSE);
	if (!(dupped = ft_strcdup(scan->buffer, '"')))
		return (ERRNO_MALLOC);
	if (check_max_size(dupped, choice) == FALSE)
		return (ERRNO_SIZE);
	choice == CHOICE_CHAMP ? (env->champ_name = dupped) : (env->comment = dupped);
	forward_buffer(env, ft_strlen(dupped) + 2);
//	printf("dupped = %s\n", dupped);
	return (TRUE);
}

int		name_comment(t_asm *env, t_scan *scan)
{
	int choice;

	choice = FALSE;
	if (reach_cmd_comname(env, scan) == FALSE)
	{
		printf(_RED"PROBLEM BEFORE \t\t.NAME\n"_RESET);
		return (FALSE);
	}
	if (ft_strncmp(scan->buffer, NAME_CMD_STRING, 5) == 0)
		choice = CHOICE_CHAMP;
	else if (ft_strncmp(scan->buffer, COMMENT_CMD_STRING, 8) == 0)
		choice = CHOICE_COM;
	if (choice == FALSE || (env->error = get_comname(env, scan, choice)) <= FALSE)
		return (env->error);
	if (env->champ_name == NULL || env->comment == NULL)
		return (name_comment(env, scan));			

	return (TRUE);


}

int		lexer(t_asm *env)
{
	if ((env->error = name_comment(env, &env->scan)) <= FALSE)
		return (FALSE);
	printf("NAME-COMMENT\t\t"_GREEN"OK"_RESET"\n");
	env->fd = env->fd;

	return (TRUE);

}

int		main(int ac, char **av)
{
	t_asm	env;

	ft_bzero(&env, sizeof(t_asm));
	if (ac != 2 || init(&env, av[1]) == FALSE)
	{
		printf("INIT	"_RED"PROBLEM"_RESET"\n");
		return (FALSE);
	}
	if (lexer(&env) == FALSE)
		printf(_RED"LEXER\t\t	PROBLEM"_RESET"\n");
//	parse();
//	write();
	printf("\n\nEnd of buff reading @ "_BLUE"[%d:%d]"_RESET"\n", 
					env.nb_newlines, env.nb_char);
//	printf("file_name = %s\n", env.file_name);
	printf("error = %d\n", env.error);
	printf("champ_name = %s\n", env.champ_name);
	printf("comment = %s\n", env.comment);
	return (0);
}
