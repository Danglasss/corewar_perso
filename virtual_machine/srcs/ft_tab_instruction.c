/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2020/03/11 13:58:02 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/prototypes.h"

t_instruction	tab_instruction[16] =
{
	{&ft_live, "live", 10, 1, 4, {T_DIR}, {0}},
	{&ft_ld, "ld", 5, 2, 4, {T_DIR | T_IND, T_REG}, {0}},
	{&ft_st, "st", 5, 2, 0, {T_REG, T_IND | T_REG},{0}},
	{&ft_add, "add", 10, 3, 0, {T_REG, T_REG, T_REG}, {0}},
	{&ft_sub, "sub", 10, 3, 0, {T_REG, T_REG, T_REG}, {0}},
	{&ft_and, "and", 6, 3, 4, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_or, "or", 6, 3, 4, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_xor, "xor", 6, 3, 4, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}},
	{&ft_zjmp, "zjmp", 20, 1, 2, {T_DIR}, {0}},
	{&ft_ldi, "ldi", 25, 3, 2, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}},
	{&ft_sti, "sti", 25, 3, 2, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, {0}},
	{&ft_fork, "fork", 800, 1, 2, {T_DIR}, {0}},
	{&ft_lld, "lld", 10, 2, 4, {T_DIR | T_IND, T_REG}, {0}},
	{&ft_lldi, "lldi", 50, 3, 2, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}},
	{&ft_lfork, "lfork", 1000, 1, 2, {T_DIR}, {0}},
	{&ft_aff, "aff", 2, 1, 0, {T_REG}, {0}}
};

/*
t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};
*/