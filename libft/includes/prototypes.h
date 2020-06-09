/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:00:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/01 11:58:13 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPROTOTYPES_H

# define LIBFTPROTOTYPES_H
# include "struct.h"
# include <stdlib.h>

/*
**	GET_NEXT_LINE
*/

int				get_next_line(const int fd, char **line);

/*
**	FT_PRINTF
*/

int				ft_printf(const char *restrict format, ...);
void			ft_parser(const char **format, t_buffer *buff, t_flag *c_arg);
void			ft_write_in_buffer(t_buffer *buff_s, char c, int len);
void			ft_putstr_buffer(t_buffer *buff, char *str, int len);
void			ft_error_parse(t_buffer *buff_s, t_flag *c_arg, char c);
void			ft_flush_buffer(t_buffer *buff);
void			ft_option(const char **format, t_flag *c_arg);
void			ft_lmc_precision(const char **format, t_flag *c_arg, int state);
void			ft_size(const char **format, t_flag *c_arg);
int				ft_opt_auth(char c);
void			ft_convert_to_base(t_buffer *buff, t_flag *c_arg,
				int type, char *b);
unsigned int	ft_order(t_flag *c_arg, char type, int base_l);
void			ft_arg_signed(t_flag *c_arg);
void			ft_arg_unsigned(t_flag *c_arg);
int				ft_radical_unsigned(unsigned long nb, int base);
int				ft_radical_signed(long nb);
int				ft_pre_conversion(t_flag *c_arg, char type, int base_l);
void			ft_prefix(t_buffer *buff, t_flag *c_arg);
void			ft_padding(t_buffer *buff, t_flag *c_arg);
unsigned long	ft_power_signed(long nb, long pow);
unsigned long	ft_power_unsigned(unsigned long nb, long pow);
void			ft_o_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_u_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_p_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_x_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_bigx_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_d_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_i_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_c_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_s_conversion(t_buffer *buff, t_flag *c_arg);
void			ft_percent_conversion(t_buffer *buff, t_flag *c_arg);
int				ft_higher_value(int a, int b, int c);
int				ft_nb_digit(int base, char *c, ...);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	MEMORY
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
**	STRING
*/

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoinf(char *s1, char *s2, int flag);

/*
**	LIST
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lst_push_back(t_list **begin_lst, void *content,
	size_t content_size);
void			ft_print_lst(t_list *lst);

/*
**	CHARACTER
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	CONVERSION
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
	const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_min(int a, int b);
int				ft_max(int a, int b);

#endif
