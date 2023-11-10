/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:15:54 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/07 19:15:55 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_stack *stack_a)
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

void	sort_three(t_stack **stack_a, size_t stack_size)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack_a;
	while (is_sorted(*stack_a) == FALSE)
	{
		if (current->num > current->prev->num)
		{
			do_ra(stack_a);
			current = *stack_a;
		}
		if (current->num < current->prev->num)
		{
			do_rra(stack_a);
			current = *stack_a;
		}
		if (current->num > current->next->num)
		{
			do_sa(stack_a);
			current = *stack_a;
		}
		i++;
	}
}
