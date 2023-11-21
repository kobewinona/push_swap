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

static void	push_to_b(int moves_fwd, int moves_bwd, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (moves_fwd <= moves_bwd)
	{
		while (i++ < moves_fwd)
			do_ra(a);
	}
	else
	{
		while (i++ <= moves_bwd)
			do_rra(a);
	}
	do_pb(a, b);
}

static void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		target_index;
	int		moves;

	while (*b)
	{
		current = *b;
		moves = 0;
		if (*a)
			target_index = (*a)->index - 1;
		else
			target_index = find_stack_max(*b);
		moves = count_moves_to_index_fwd(current, target_index);
		move_stack_b(moves, b, calculate_stack_size(*b));
		do_pa(a, b);
	}
}

void	sort_more_than_five(t_stack **a, t_stack **b, int stack_size)
{
	t_chunk	*chunk;
	int		mid;
	int		moves_fwd;
	int		moves_bwd;

	chunk = init_chunk(a, stack_size);
	while (*a)
	{
		mid = stack_size / 2;
		moves_fwd = count_moves_to_chunk_fwd(*a, chunk);
		moves_bwd = count_moves_to_chunk_bwd((*a)->prev, chunk);
		if (mid != 0 && moves_fwd == mid && moves_bwd == mid)
		{
			chunk->start = chunk->end;
			chunk->end = chunk->end + chunk->size;
			continue ;
		}
		push_to_b(moves_fwd, moves_bwd, a, b);
		stack_size--;
	}
	push_to_a(a, b);
	free(chunk);
}
