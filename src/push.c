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

static void	push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*dst_first;
	t_stack	*src_first;
	t_stack	*src_second;
	t_stack	*src_last;

	if (!*stack_src || (*stack_src)->unset)
		return ;
	dst_first = *stack_dst;
	src_first = *stack_src;
	src_second = src_first->next;
	src_last = src_first->prev;
	src_last = src_second;
	src_second->prev = src_last;
	if (dst_first)
	{
		dst_first = src_first;
		dst_first->next = dst_first;
		dst_first->prev = dst_first;
	}
	else
	{
		src_first->prev = dst_first->prev;
		dst_first->prev = src_first;
	}
}

// static void	push(t_stack **stack_dst, t_stack **stack_src)
// {
// 	t_stack	*dst_curr;
// 	t_stack	*src_curr;
// 	t_stack	*temp;

// 	if (!*stack_src || (*stack_src)->unset)
// 		return ;
// 	dst_curr = *stack_dst;
// 	while (!dst_curr->unset && dst_curr->next != *stack_dst)
// 		dst_curr = dst_curr->next;
// 	src_curr = *stack_src;
// 	while (1)
// 	{
// 		if (src_curr->next->unset || src_curr->next == *stack_src)
// 		{
// 			dst_curr->num = src_curr->num;
// 			dst_curr->unset = FALSE;
// 			src_curr->num = 0;
// 			src_curr->unset = TRUE;
// 			break ;
// 		}
// 		src_curr = src_curr->next;
// 	}
// }

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
