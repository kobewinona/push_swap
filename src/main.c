/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:57:40 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 16:57:43 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	if (stack_size <= 5)
		sort_small(stack_a, stack_b, stack_size);
	else
		sort_big(stack_a, stack_b, stack_size);
}

int	main(int argc, char **argv)
{
	t_list	*args_lst;
	size_t	stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	args_lst = parse_argv((argc - 1), (argv + 1));
	if (!args_lst)
		return (handle_error(&stack_a, &stack_b, &args_lst));
	stack_size = ft_lstsize(args_lst);
	if (!is_argv_valid(args_lst))
		return (handle_error(&stack_a, &stack_b, &args_lst));
	stack_a = init_stack(stack_size);
	if (!stack_a)
		return (handle_error(&stack_a, &stack_b, &args_lst));
	fill_stack(&stack_a, args_lst, stack_size);
	ft_lstclear(&args_lst, free);
	if (is_stack_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (1);
	}
	sort_stack(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	return (1);
}
