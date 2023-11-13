/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:56:08 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/13 14:56:08 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stackadd_front(t_stack **stack, t_stack *node)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
	{
		node->next = node;
		node->prev = node;
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
	*stack = node;
}
