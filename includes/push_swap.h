/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:03:21 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/27 17:03:22 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libftprintf.h"
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>

// magic numbers
# define NULL_TURM 1
# define TRUE 1
# define FALSE 0
# define ERROR -1

// colors
# define RESET_COLOR "\033[0m"
# define RED_COLOR "\033[31m"
# define GREEN_COLOR "\033[32m"

// error messages
# define NO_ARGS "No arguments are provided\n\n" \
	"*** Please make sure that:\n" \
	"\t- at least 1 arg is provided\n" \
	"\t- arguments are integers only\n" \
	"\t- arguments must be seperated by spaces"

# define INVALID_ARGS "Invalid arguments\n\n" \
	"*** What might have caused this error:\n" \
	"\t- some arguments aren't integers\n" \
	"\t- some arguments are bigger than an integer\n" \
	"\t- some arguments are duplicates"

# define UNKNOWN_ERROR "Unknown error occured\n\n" \
	"*** Please try again:\n"

// structures
typedef struct s_dlist
{
	long			num;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

// functions
void	print_err_msg(char *err_msg);
int		is_argv_valid(int argc, char **argv);
t_dlist	*init_stack(int argc, char **argv);

#endif