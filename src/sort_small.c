/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:42 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/13 13:41:43 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (is_stack_sorted(*stack_a) == FALSE)
	{
		if (current->num > current->prev->num)
		{
			if (current->next->num < current->prev->num)
			{
				do_ra(stack_a);
				current = *stack_a;
				continue ;
			}
			if (current->num < current->next->num)
			{
				do_rra(stack_a);
				current = *stack_a;
				continue ;
			}
		}
		do_sa(stack_a);
		current = *stack_a;
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	if (stack_size <= 3)
		sort_three(stack_a);
	else
	{
		do_pb(stack_a, stack_b);
		ft_printf("stack a: ");
		print_stack(*stack_a);
		ft_printf("stack b: ");
		print_stack(*stack_b);
		do_pb(stack_a, stack_b);
		ft_printf("stack a: ");
		print_stack(*stack_a);
		ft_printf("stack b: ");
		print_stack(*stack_b);
		do_pa(stack_a, stack_b);
		ft_printf("stack a: ");
		print_stack(*stack_a);
		ft_printf("stack b: ");
		print_stack(*stack_b);
		do_pa(stack_a, stack_b);
		ft_printf("stack a: ");
		print_stack(*stack_a);
		ft_printf("stack b: ");
		print_stack(*stack_b);
	}
}
