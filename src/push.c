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
	t_stack	*dst_curr;
	t_stack	*src_curr;
	t_stack	*temp;

	if (!*stack_src || (*stack_src)->unset)
		return ;
	dst_curr = *stack_dst;
	while (!dst_curr->unset && dst_curr->next != *stack_dst)
		dst_curr = dst_curr->next;
	src_curr = *stack_src;
	while (1)
	{
		if (src_curr->next->unset || src_curr->next == *stack_src)
		{
			dst_curr->num = src_curr->num;
			dst_curr->unset = FALSE;
			src_curr->num = 0;
			src_curr->unset = TRUE;
			break ;
		}
		src_curr = src_curr->next;
	}
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
