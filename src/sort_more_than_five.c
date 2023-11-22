/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:04:51 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/21 18:04:52 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		target_index;
	int		moves;

	if (*a)
	{
		moves = count_moves_to_index(*a, find_stack_min(*a));
		move_stack_a(moves, a, calculate_stack_size(*a));
	}
	while (*b)
	{
		current = *b;
		moves = 0;
		if (*a)
			target_index = (*a)->index - 1;
		else
			target_index = find_stack_max(*b);
		moves = count_moves_to_index(current, target_index);
		move_stack_b(moves, b, calculate_stack_size(*b));
		do_pa(a, b);
	}
}

void	sort_more_than_five(t_stack **a, t_stack **b, int stack_size)
{
	t_chunk	*chunk;
	int		moves;

	chunk = init_chunk(a, stack_size);
	while (*a && find_stack_min(*a) < chunk->min_sorted)
	{
		moves = count_moves_to_chunk(*a, chunk, stack_size);
		if (moves >= stack_size)
		{
			chunk->start = chunk->end;
			chunk->end = chunk->end + chunk->size;
			if (chunk->end >= chunk->min_sorted)
				chunk->end = chunk->min_sorted - 1;
			continue ;
		}
		move_stack_a(moves, a, stack_size);
		do_pb(a, b);
		stack_size--;
	}
	push_to_a(a, b);
	free(chunk);
}
