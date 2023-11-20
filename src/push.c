/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:03:00 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/07 14:03:01 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	remove_source_node(t_stack **stack_src)
{
	t_stack	*src_first;
	t_stack	*src_second;
	t_stack	*src_last;

	src_first = *stack_src;
	src_second = src_first->next;
	src_last = src_first->prev;
	if (src_first == src_second)
		*stack_src = NULL;
	else
	{
		src_last->next = src_second;
		src_second->prev = src_last;
		*stack_src = src_second;
	}
}

static void	add_to_dest(t_stack **stack_dst, t_stack *node)
{
	t_stack	*dst_first;
	t_stack	*dst_last;

	dst_first = *stack_dst;
	if (dst_first)
		dst_last = dst_first->prev;
	else
		dst_last = NULL;
	if (dst_first)
	{
		node->next = dst_first;
		node->prev = dst_last;
		dst_first->prev = node;
		dst_last->next = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
	}
	*stack_dst = node;
}

static void	push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*src_first;

	if (!*stack_src || (*stack_src)->unset)
		return ;
	src_first = *stack_src;
	remove_source_node(stack_src);
	add_to_dest(stack_dst, src_first);
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
