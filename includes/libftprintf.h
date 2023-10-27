/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:50:10 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/09 11:50:11 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_fdata
{
	int		justify;
	char	pad;
	int		is_preceded_with_space;
	int		is_preceded_with_0x;
	int		is_sign_forced;
	ssize_t	width;
	ssize_t	precision;
	ssize_t	precision_len;
	char	spec;
	void	*content;
	char	*hex_string;
	ssize_t	len;
}			t_fdata;
typedef int	(*t_print_func)(t_fdata *);
int		ft_printf(const char *arg, ...);
int		is_valid_fdata(const char *arg);
int		is_char_in_set(char const c, char const *set);
int		count_dec_len(long n);
size_t	count_hex_len(unsigned long n);
void	count_precision_len(int n, t_fdata *fdata);
char	*create_p_xstr(void *content, ssize_t len);
char	*create_x_xtrs(void *content, ssize_t len, char spec);
int		print_precision(ssize_t len, t_fdata *fdata);
size_t	record_ftags(t_fdata *fdata, const char *arg);
int		print_preceeding_flags(long n, t_fdata *fdata);
int		print_width(t_fdata *fdata);
int		print_with_width(t_print_func print_func, t_fdata *fdata);
int		print_ld(long n, t_fdata *fdata);
void	print_c_with_tags(t_fdata *fdata);
void	print_s_with_tags(t_fdata *fdata);
void	print_p_with_tags(t_fdata *fdata);
void	print_di_with_tags(t_fdata *fdata);
void	print_u_with_tags(t_fdata *fdata);
void	print_x_with_tags(t_fdata *fdata);

#endif