/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:34:11 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/30 17:34:11 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack(t_stack **stack, t_list *args_lst)
{
	t_stack	*next;
	t_stack	*current;

	if (*stack)
	{
		current = (*stack);
		while (1)
		{
			current->num = ft_atoi(args_lst->content);
			current->unset = FALSE;
			args_lst = args_lst->next;
			if (current->next == *stack)
				break ;
			current = current->next;
		}
	}
}
