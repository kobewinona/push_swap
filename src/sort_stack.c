/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:48:43 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/21 12:48:44 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		moves;
	int		count;
	int		target_index;

	count = 0;
	target_index = 1;
	while (count < 2)
	{
		current = *a;
		moves = count_moves_to_index(current, target_index);
		move_stack_a(moves, a, calculate_stack_size(*a));
		do_pb(a, b);
		target_index = 2;
		count++;
	}
}

static void	sort_three(t_stack **a)
{
	t_stack	*current;

	while (is_stack_sorted(*a) == FALSE)
	{
		current = *a;
		if (current->num > current->prev->num)
		{
			if (current->next->num < current->prev->num)
			{
				do_ra(a);
				continue ;
			}
			if (current->num < current->next->num)
			{
				do_rra(a);
				continue ;
			}
		}
		do_sa(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size <= 3)
		sort_three(a);
	else if (stack_size <= 5)
	{
		push_to_b(a, b);
		sort_three(a);
		if ((*b)->index < (*b)->next->index)
			do_sb(b);
		while (*b)
			do_pa(a, b);
	}
	else
		sort_more_than_five(a, b, stack_size);
}
