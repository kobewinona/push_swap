/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:04:44 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/07 19:04:48 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stacks(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	*stack_a = init_stack(stack_size);
	if (!*stack_a)
		return (FALSE);
	*stack_b = init_stack(stack_size);
	if (!*stack_a)
	{
		free_stack(stack_a);
		return (FALSE);
	}
	return (TRUE);
}
