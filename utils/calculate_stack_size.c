/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_stack_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:47:40 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/20 21:47:41 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_stack_size(t_stack *stack)
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
