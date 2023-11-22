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

int	count_moves_to_chunk(t_stack *stack, t_chunk *chunk, int stack_size)
{
	int	moves;

	moves = 0;
	if (chunk)
	{
		while (moves <= stack_size)
		{
			if (stack->index >= chunk->start && stack->index <= chunk->end)
				break ;
			stack = stack->next;
			moves++;
		}
	}
	return (moves);
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