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

int	main(int argc, char **argv)
{
	t_list	*args_lst;
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_size;

	args_lst = NULL;
	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		return (0);
	}
	args_lst = parse_argv((argc - 1), (argv + 1));
	if (!is_argv_valid(args_lst))
	{
		ft_lstclear(&args_lst, free);
		return (0);
	}
	stack_size = (argc - 1);
	stack_a = init_stack(stack_size);
	if (!stack_a)
	{
		ft_lstclear(&args_lst, free);
		return (0);
	}
	fill_stack(&stack_a, args_lst);
	ft_lstclear(&args_lst, free);
		
	// print stack values
	t_stack *temp1 = stack_a;
	int i = 0;
	while (i < stack_size)
	{
		ft_printf("%d -> ", temp1->num);
		temp1 = temp1->next;
		i++;
	}
	ft_printf("\n\n");
	do_sa(&stack_a);
	t_stack *temp2 = stack_a;
	i = 0;
	while (i < stack_size)
	{
		ft_printf("%d -> ", temp2->num);
		temp2 = temp2->next;
		i++;
	}
	ft_printf("\n\n");

	// free on exit
	free_stack(&stack_a);
	return (1);
}
