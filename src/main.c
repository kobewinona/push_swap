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

static t_list	*handle_arguments(int argc, char **argv, int *stack_size)
{
	t_list	*args_lst;

	args_lst = parse_argv(argc, argv);
	if (!args_lst)
	{
		print_err_msg();
		return (NULL);
	}
	*stack_size = ft_lstsize(args_lst);
	if (!is_argv_valid(args_lst))
	{
		ft_lstclear(&args_lst, free);
		print_err_msg();
		return (NULL);
	}
	return (args_lst);
}

int	main(int argc, char **argv)
{
	t_list	*args_lst;
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (argc <= 1)
		return (0);
	args_lst = handle_arguments((argc - 1), (argv + 1), &stack_size);
	if (!args_lst)
		return (0);
	a = init_stack(stack_size);
	if (!a)
		return (handle_error(&a, &b, &args_lst));
	fill_stack(&a, args_lst, stack_size);
	ft_lstclear(&args_lst, free);
	if (is_stack_sorted(a))
	{
		free_stack(&a);
		return (1);
	}
	sort_stack(&a, &b, stack_size);
	free_stack(&a);
	return (1);
}
