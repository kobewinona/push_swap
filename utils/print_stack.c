/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:03:21 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/20 20:03:24 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *stack_name, int index)
{
	t_stack	*current;

	if (stack)
	{
		current = stack;
		ft_printf("%s: ", stack_name);
		while (1)
		{
			if (index == TRUE)
				ft_printf("%d", current->index);
			else
				ft_printf("%d", current->num);
			current = current->next;
			if (current != stack)
			{
				ft_printf(" -> ");
			}
			else
				break ;
		}
		ft_printf("\n\n");
	}
}
