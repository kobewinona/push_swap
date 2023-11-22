/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:46:34 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/22 13:46:35 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_stack_a(int moves, t_stack **a, int stack_size)
{
	if (stack_size > 1)
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
}

void	move_stack_b(int moves, t_stack **b, int stack_size)
{
	if (stack_size > 1)
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
}
