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
# define TRUE 1
# define FALSE 0
# define ERROR -1

// structures
typedef struct s_stack
{
	int				unset;
	ssize_t			num;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;
typedef struct s_chunk
{
	int	start;
	int	end;
	int	size;
}					t_chunk;

// functions
// - src
t_list	*parse_argv(int argc, char **argv);
int		is_argv_valid(t_list *args);
int		handle_error(t_stack **stack_a, t_stack **stack_b, t_list **args_lst);
void	fill_stack(t_stack **stack, t_list *args_lst, size_t stack_size);
int		is_stack_sorted(t_stack *stack_a);

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
void	do_pb(t_stack **stack_a, t_stack **stack_b);

void	sort_stack(t_stack **a, t_stack **b, int stack_size);
void	sort_more_than_five(t_stack **a, t_stack **b, int stack_size);

// - utils
void	print_err_msg(void);
void	print_stack(t_stack *stack, char *stack_name, int index);

void	free_double_arr(char **arr);

t_stack	*init_stack(size_t size);
void	stackadd_front(t_stack **stack, t_stack *node);
int		calculate_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
ssize_t	find_stack_min(t_stack *stack);
ssize_t	find_stack_max(t_stack *stack);
int		count_moves_to_chunk(t_stack *stack, t_chunk *chunk, int stack_size);
int		count_moves_to_index(t_stack *stack, int target_index);
void	move_stack_a(int moves, t_stack **a, int stack_size);
void	move_stack_b(int moves, t_stack **b, int stack_size);
t_chunk	*init_chunk(t_stack **stack, size_t stack_size);

#endif
