/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/06/02 12:34:18 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define HEADER                  1
# define READ_NAME               128
# define READ_COM                2048
# define TO_READ                 682
# define MAGIC	                4
# define READ_EXEC	            4
# define NOT_READ	            4

/*
** define usage
*/

# define USAGE               0
# define NO_ARGS             0
# define PARSING             1
# define FILECOR             2
# define MC_HEADER           3
# define SIZE_NAME           4
# define SIZE_EXEC           5
# define SIZE_COMM           6
# define FALSE_POS           6

# define CYCLE_MAX				15
# define CYCLE_WAIT_MAX			1024
# define STAND_BY				1010
# define ERROR					-1
# define TRUE					1
# define LIMIT_CHAMP				4

# define REG_BIT					64
# define IND_BIT					192
# define DIR_BIT					128

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				4096
# define IDX_MOD				512
# define CHAMP_MAX_SIZE			682

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_IND					2
# define T_DIR					4
# define T_LAB					8

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

#endif
