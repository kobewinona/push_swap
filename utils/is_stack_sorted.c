/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:45:09 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/10 15:45:09 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (1)
	{
		if (current->next == stack_a)
			break ;
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
