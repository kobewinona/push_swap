/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:41:30 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/15 19:41:30 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_next(t_stack *current, t_chunk *chunk, size_t mid, int rev)
{
	int	moves;

	moves = 0;
	while (moves < mid)
	{
		if (current->index >= chunk->start && current->index <= chunk->end)
			break ;
		if (rev == TRUE)
			current = current->prev;
		else
			current = current->next;
		moves++;
	}
	return (moves);
}

static void	push_to_b(int a1, int a2, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	if (a1 <= a2)
	{
		while (i++ < a1)
			do_ra(stack_a);
	}
	else
	{
		while (i++ <= a2)
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
}

static int	calc_stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	current = stack;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (size);
}

static void	push_to_a(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	t_stack	*current;
	int		target_index;
	int		moves;

	while (*stack_b)
	{
		current = *stack_b;
		moves = 0;
		if (*stack_a)
			target_index = (*stack_a)->index - 1;
		else
			target_index = find_stack_max(*stack_b);
		while (current->index != target_index)
		{
			current = current->next;
			moves++;
			if (current == *stack_b)
				break ;
		}
		if (moves < (calc_stack_size(*stack_b) / 2))
		{
			while (moves--)
				do_rb(stack_b);
		}
		else
		{
			moves = calc_stack_size(*stack_b) - moves;
			while (moves--)
				do_rrb(stack_b);
		}
		do_pa(stack_a, stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	t_chunk	*chunk;
	size_t	mid;
	int		a1;
	int		a2;

	chunk = init_chunk(stack_a, stack_size);
	while (*stack_a)
	{
		mid = stack_size / 2;
		a1 = find_next(*stack_a, chunk, mid, FALSE);
		a2 = find_next((*stack_a)->prev, chunk, mid, TRUE);
		if (mid != 0 && a1 == mid && a2 == mid)
		{
			chunk->start = chunk->end;
			chunk->end = chunk->end + chunk->size;
			continue ;
		}
		push_to_b(a1, a2, stack_a, stack_b);
		stack_size--;
	}
	push_to_a(stack_a, stack_b, stack_size);
	free(chunk);
}
