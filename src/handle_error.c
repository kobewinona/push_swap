/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:26 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/13 15:25:27 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_error(t_stack **stack_a, t_stack **stack_b, t_list **args_lst)
{
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
	if (*args_lst)
		ft_lstclear(args_lst, free);
	return (0);
}
