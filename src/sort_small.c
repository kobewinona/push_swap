/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:42 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/13 13:41:43 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	find_smallest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		moves;
	int		count;
	int		index_to_find;

	count = 0;
	index_to_find = 1;
	while (count < 2)
	{
		current = *stack_a;
		moves = 0;
		while (current->index != index_to_find)
		{
			current = current->next;
			moves++;
		}
		if (moves < 3)
		{
			while (moves--)
				do_ra(stack_a);
		}
		else
		{
			moves = calc_stack_size(*stack_a) - moves;
			while (moves--)
				do_rra(stack_a);
		}
		do_pb(stack_a, stack_b);
		index_to_find = 2;
		count++;
	}
}

static void	sort_three(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (is_stack_sorted(*stack_a) == FALSE)
	{
		if (current->num > current->prev->num)
		{
			if (current->next->num < current->prev->num)
			{
				do_ra(stack_a);
				current = *stack_a;
				continue ;
			}
			if (current->num < current->next->num)
			{
				do_rra(stack_a);
				current = *stack_a;
				continue ;
			}
		}
		do_sa(stack_a);
		current = *stack_a;
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	if (stack_size <= 3)
		sort_three(stack_a);
	else
	{
		find_smallest(stack_a, stack_b);
		sort_three(stack_a);
		if ((*stack_b)->index < (*stack_b)->next->index)
			do_sb(stack_b);
		while (*stack_b)
			do_pa(stack_a, stack_b);
	}
}
