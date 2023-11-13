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

// structures
typedef struct s_stack
{
	int				unset;
	long			num;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// functions
// - src
t_list	*parse_argv(int argc, char **argv);
int		is_argv_valid(t_list *args);
t_stack	*init_stack(size_t size);
int		init_stacks(t_stack **stack_a, t_stack **stack_b, size_t stack_size);
int		handle_error(t_stack **stack_a, t_stack **stack_b, t_list **args_lst);
void	free_stacknode(t_stack **stack);
void	stackadd_front(t_stack **stack, t_stack *node);
void	fill_stack(t_stack **stack, t_list *args_lst);
int		is_stack_sorted(t_stack *stack_a);
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);

void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_b, t_stack **stack_a);

void	sort_small(t_stack **stack_a, t_stack **stack_b, size_t stack_size);

// -utils
void	print_err_msg(void);
void	free_double_arr(char **arr);

#endif
