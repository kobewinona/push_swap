/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:47:18 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/28 14:47:19 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// some arguments aren’t integers
// some arguments are bigger than an integer
// some arguments are duplicates
// use checker to check all edge cases for invalid arguments

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;

	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		return (0);
	}
	stack_a = init_stack((argc - 1), (argv + 1));
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		ft_printf("(%d) -> ", stack_a->num);
		stack_a = stack_a->next;
	}
	return (1);
}
