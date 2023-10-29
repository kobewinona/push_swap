/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:00:05 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 17:00:12 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libftprintf.h"

// magic numbers
# define NULL_TURM 1
# define TRUE 1
# define FALSE 0
# define ERROR -1

// text colors
# define RESET_COLOR "\033[0m"
# define RED_COLOR "\033[31m"
# define GREEN_COLOR "\033[32m"

// text weight
# define REGULAR "\e[0m"
# define BOLD "\e[1m"

// error messages
# define NO_ARGS "No arguments are provided\n"
# define INVALID_ARGS "Invalid arguments\n"
# define UNKNOWN_ERROR "Unknown error occured\n"

// prompt messages
# define RESTART_PROMPT "*** Please try to restart the program\n"

# define ERROR_CAUSE_PROMPT "*** What have caused this error:\n"
# define NOT_INT "\t- some arguments aren't integers\n"
# define BIGGER_THAN_INT "\t- some arguments are bigger than an integer\n"
# define DUBLICATED "\t- some arguments are duplicates\n"

// structures
typedef struct s_dlist
{
	long			num;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

// functions
// - src
t_list	*parse_argv(int argc, char **argv);
int		is_argv_valid(t_list *args);

// -utils
void	print_err_msg(char *err_msg);
void	print_pmt_msg(char *pmt_title, char *pmt_msg);
void	free_double_arr(char **arr);

#endif
