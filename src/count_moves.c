/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:01:58 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/21 12:01:59 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_moves_fwd(t_stack *stack, t_chunk *chunk, int stack_size)
{
	t_stack	*current;
	int		moves;

	current = stack;
	moves = 0;
	while (current->index < chunk->start || current->index > chunk->end)
	{
		moves++;
		current = current->next;
		if (current == stack || moves == stack_size)
			return (stack_size);
	}
	return (moves);
}

static int	count_moves_bwd(t_stack *stack, t_chunk *chunk, int stack_size)
{
	t_stack	*current;
	int		moves;

	current = stack;
	moves = 0;
	while (current->index < chunk->start || current->index > chunk->end)
	{
		moves++;
		current = current->prev;
		if (current == stack || moves == stack_size)
			return (stack_size);
	}
	return (moves);
}

int	count_moves_to_chunk(t_stack *stack, t_chunk *chunk, int stack_size)
{
	t_stack	*current;
	int		moves_fwd;
	int		moves_bwd;
	int		moves_res;

	current = stack;
	moves_fwd = 0;
	moves_bwd = 0;
	if (stack && chunk)
	{
		moves_fwd = count_moves_fwd(stack, chunk, stack_size);
		moves_bwd = count_moves_bwd(stack, chunk, stack_size);
	}
	if (moves_fwd <= moves_bwd)
		moves_res = moves_fwd;
	else
		moves_res = stack_size - moves_bwd;
	return (moves_res);
}

int	count_moves_to_index(t_stack *stack, int target_index)
{
	int		moves;

	moves = 0;
	while (stack->index != target_index)
	{
		stack = stack->next;
		moves++;
	}
	return (moves);
}
