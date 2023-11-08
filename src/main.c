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

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (1)
	{
		ft_printf("%d", current->num);
		current = current->next;
		if (current != stack)
		{
			ft_printf(" -> ");
		}
		else
			break ;
	}
	ft_printf("\n\n");
}

void	reverse_print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (1)
	{
		ft_printf("%d", current->num);
		current = current->prev;
		if (current != stack)
		{
			ft_printf(" <- ");
		}
		else
			break ;
	}
	ft_printf("\n\n");
}

void	run_tests(t_stack *stack_a, t_stack *stack_b, size_t stack_size)
{
	ft_printf("--- testing start ---\n\n");
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);
	// do_ra(&stack_a);
	do_rra(&stack_a);
	// do_rra(&stack_a);
	// do_rra(&stack_a);
	// do_rra(&stack_a);
	// do_sa(&stack_a);
	// do_pb(&stack_a, &stack_b);
	// do_pb(&stack_a, &stack_b);
	// do_pb(&stack_a, &stack_b);
	// do_pb(&stack_a, &stack_b);
	// do_pa(&stack_a, &stack_b);
	// do_pa(&stack_a, &stack_b);
	// do_pa(&stack_a, &stack_b);
	// do_pa(&stack_a, &stack_b);
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a next %d / %p\n", stack_a->next->num, stack_a->next);
	// stack_a = stack_a->next;
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a next %d / %p\n", stack_a->next->num, stack_a->next);
	// stack_a = stack_a->next;
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a next %d / %p\n\n", stack_a->next->num, stack_a->next);
	// stack_a = stack_a->next;
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a prev %d / %p\n", stack_a->prev->num, stack_a->prev);
	// stack_a = stack_a->prev;
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a prev %d / %p\n", stack_a->prev->num, stack_a->prev);
	// stack_a = stack_a->prev;
	// ft_printf("stack_a %d / %p\n", stack_a->num, stack_a);
	// ft_printf("stack_a prev %d / %p\n", stack_a->prev->num, stack_a->prev);
	// stack_a = stack_a->prev;
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);
	ft_printf("--- testing end ---\n\n");
}

int	main(int argc, char **argv)
{
	t_list	*args_lst;
	size_t	stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		return (0);
	}
	args_lst = parse_argv((argc - 1), (argv + 1));
	if (!is_argv_valid(args_lst))
		return (handle_error(&stack_a, &stack_b, &args_lst));
	stack_size = (argc - 1);
	if (!init_stacks(&stack_a, &stack_b, stack_size))
		return (handle_error(&stack_a, &stack_b, &args_lst));
	fill_stack(&stack_a, args_lst);
	ft_lstclear(&args_lst, free);
	print_stack(stack_a);
	run_tests(stack_a, stack_b, stack_size);
	// sort_three(&stack_a, stack_size);
	print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
