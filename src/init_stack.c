/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:30:50 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/30 17:30:52 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
	{
		*stack = node;
		(*stack)->next = node;
		(*stack)->prev = node;
	}
	else
	{
		first = *stack;
		last = first->prev;
		last->next = node;
		node->next = first;
		node->prev = last;
		first->prev = node;
	}
}

t_stack	*init_stack(size_t size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->unset = TRUE;
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		stackadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
