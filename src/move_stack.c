/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:22:16 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/21 12:22:16 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_stack_a(int moves, t_stack **a, int stack_size)
{
	if (moves < (stack_size / 2))
	{
		while (moves--)
			do_ra(a);
	}
	else
	{
		moves = stack_size - moves;
		while (moves--)
			do_rra(a);
	}
}

void	move_stack_b(int moves, t_stack **b, int stack_size)
{
	if (moves < (stack_size / 2))
	{
		while (moves--)
			do_rb(b);
	}
	else
	{
		moves = stack_size - moves;
		while (moves--)
			do_rrb(b);
	}
}
