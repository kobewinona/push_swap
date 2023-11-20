/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:43:13 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/30 17:43:14 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (*stack)
	{
		current = *stack;
		while (1)
		{
			next = current->next;
			free(current);
			current = next;
			if (next == *stack)
				break ;
		}
		*stack = NULL;
	}
}
