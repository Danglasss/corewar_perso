#ifndef DEBUG_H
# define DEBUG_H

#include "./struct.h"

void	ft_debug_processus(t_process *processus);
void	ft_debug_processus_list(t_process *processus_list);
void	ft_debug_params(unsigned int param[3][2]);
void	ft_print_bit_32(int i);
#endif