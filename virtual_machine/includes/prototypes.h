/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:29:36 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/04 15:49:35 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

# define PROTOTYPES_H
# include "./struct.h"

/*
** Dump
*/

void		ft_dump(const unsigned char vm[MEM_SIZE]);

/*
** Parsing
*/

int			ft_get_pos_player(t_args *filecor);
int			ft_print_intro(t_player player[4]);
int			ft_check_int(char *nombr);
int			ft_usage(int usage);
int			ft_free_filecor(t_args *filecor);
int			ft_get_options(int index, char **args, t_option *option);
int			ft_insertion_vm(t_args *filecor,
						unsigned char vm[MEM_SIZE], t_player *player);
int			ft_parse(int nb_args, char **args, t_vm *vm);
int			ft_free_filecor(t_args *filecor);
int			ft_get_options(const int nb_args, char **args, t_option *option);

void		ft_move_pc(t_process *process, int value);
int			ft_get_param_type(t_process *process, t_vm *vm);
void		ft_exec_cycle(t_vm *vm, t_process *tab[1024], size_t cycle);
int			ft_error(void);
void		ft_reset_begin_process_list(t_process *process_list);
void		ft_check(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX]);
int			ft_recover_value_param(uint8_t vm[MEM_SIZE],
									uint32_t param[2], t_process *process);
int			ft_get_value_ram(uint8_t vm[4], int	len);
void		ft_convert_to_char(t_vm *vm, int reg, int pos);
int			ft_value_from_address(size_t pc, short indirect, t_vm *vm);
uint32_t	ft_convert_to_int(unsigned char tab[4]);
int			ft_parameter_recover_value(t_vm *vm, size_t pc,
										uint32_t tab[2], t_process *process);
void		ft_skip_instruction_sequency(t_process *process, t_vm *vm);
void		ft_print_param(int param, int type, int opcode);
int			ft_skip_bad_ocp_parsing(t_vm *vm, t_process *process, int nb_param);
int			ft_param_set_struct(t_process *process, t_vm *vm);
int			ft_convert_ram_to_param(t_vm *vm, int len, int *i_ptr, int j);

int			ft_recover_value_param(uint8_t vm[MEM_SIZE],
									uint32_t param[2], t_process *process);
int			ft_recover_value_ram(uint8_t vm[4], int	len);

int			ft_initialisation(t_vm *vm);
int			ft_check_value_param(t_process *process, t_vm *vm);
int			ft_param_check_type(t_vm *vm, t_process *process);
int			ft_unrestr_value_from_address(size_t pc, short indirect, t_vm *vm);

/*
**	Boucle central du fonctionnement de la VM.
*/

void		ft_loop_dumped(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX]);
void		ft_loop_std(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX]);

/*
**	Loading feature
*/

void		ft_loading_check_processus(t_vm *vm, size_t cycle);
void		ft_loading_try_processus(t_vm *vm, t_process *process,
									size_t cycle);

/*
**	Gestion des processus.
*/

void		ft_processus_list_add(t_vm *vm, t_process *process);
void		ft_processus_tab_add(t_process *process, t_vm *vm, size_t cycle);
t_process	*ft_processus_create(const size_t no, const size_t pc);
t_process	*ft_processus_cpy(t_process *processus, size_t pc, size_t no);
void		ft_processus_rm(t_vm *vm, t_process *tab[1024],
			t_process *process);
void		ft_process_move(t_process *process, t_vm *vm,
			int cycle, int cycle_to_add);
int			ft_processus_player_initialisation(t_vm *vm);
void		ft_move_pc(t_process *process, int value);

/*
**	Prototypes des fonctions pour les instructions ASM.
*/

void		ft_add(t_process *process, t_vm *vm);
void		ft_aff(t_process *process, t_vm *vm);
void		ft_and(t_process *process, t_vm *vm);
void		ft_fork(t_process *process, t_vm *vm);
void		ft_ld(t_process *process, t_vm *vm);
void		ft_ldi(t_process *process, t_vm *vm);
void		ft_lfork(t_process *process, t_vm *vm);
void		ft_live(t_process *process, t_vm *vm);
void		ft_lld(t_process *process, t_vm *vm);
void		ft_lldi(t_process *process, t_vm *vm);
void		ft_or(t_process *process, t_vm *vm);
void		ft_st(t_process *process, t_vm *vm);
void		ft_sti(t_process *process, t_vm *vm);
void		ft_sub(t_process *process, t_vm *vm);
void		ft_xor(t_process *process, t_vm *vm);
void		ft_zjmp(t_process *process, t_vm *vm);

#endif
