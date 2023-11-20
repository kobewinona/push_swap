/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:00:13 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/16 16:00:14 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

ssize_t	find_stack_max(t_stack *stack)
{
	t_stack	*current;
	ssize_t	max_num;

	current = stack;
	max_num = 0;
	while (1)
	{
		if (current->index > max_num)
			max_num = (ssize_t)current->index;
		if (current->next == stack)
			break ;
		current = current->next;
	}
	return (max_num);
}
