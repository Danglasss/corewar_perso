/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:52:10 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 18:22:55 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef enum	e_instructs
{
	INS_UNKNOWN,
	INS_LIVE,
	INS_LD,
	INS_ST,
	INS_ADD,
	INS_SUB,
	INS_AND,
	INS_OR,
	INS_XOR,
	INS_ZJMP,
	INS_LDI,
	INS_STI,
	INS_FORK,
	INS_LLD,
	INS_LLDI,
	INS_LFORK,
	INS_AFF,
	INS_MAX
}				t_instructs;

typedef enum	e_tokens
{
	TOK_UNKNOWN,
	TOK_LAB,
	TOK_INS,
	TOK_REG,
	TOK_IND,
	TOK_DIR,
	TOK_MAX
}				t_tokens;

typedef enum	e_characters
{
	CHR_COMMENT,
	CHR_LABEL,
	CHR_DIRECT,
	CHR_SEPARATOR,
	CHR_MAX
}				t_characters;


#endif
