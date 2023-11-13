/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:05 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/30 15:47:06 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next || (*stack)->next->unset)
		return ;
	first = *stack;
	second = first->next;
	last = first->prev;
	if (last != second)
	{
		first->next = second->next;
		second->prev = last;
		last->next = second;
		second->next->prev = first;
	}
	else
	{
		second->prev = first;
		first->next = second;
	}
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
