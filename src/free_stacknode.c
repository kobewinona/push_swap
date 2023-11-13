/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacknode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:45:37 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/13 15:45:38 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacknode(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	ft_printf("stack num %d\n", (*stack)->num);
	if (*stack)
	{
		first = *stack;
		second = first->next;
		last = first->prev;
		if (first == last)
		{
			free(first);
			first = NULL;
			return ;
		}
		second->prev = last;
		last->next = second;
		*stack = second;
		free(first);
		first = NULL;
	}
}
