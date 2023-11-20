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
		stackadd_front(&stack, new_node);
		i++;
	}
	return (stack);
}
