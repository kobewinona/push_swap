/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:45 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/16 15:58:46 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

ssize_t	find_stack_min(t_stack *stack)
{
	t_stack	*current;
	ssize_t	min_num;

	current = stack;
	min_num = find_stack_max(stack);
	while (1)
	{
		if (current->index < min_num)
			min_num = (ssize_t)current->index;
		if (current->next == stack)
			break ;
		current = current->next;
	}
	return (min_num);
}
