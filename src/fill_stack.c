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

static void	sort_arr(long *arr, size_t size)
{
	size_t		i;
	size_t		j;
	long		temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	define_index(long *arr, t_stack **stack, size_t stack_size)
{
	size_t	i;
	size_t	j;
	t_stack	*current;

	i = 0;
	current = *stack;
	while (i < stack_size)
	{
		j = 0;
		while (j < stack_size)
		{
			if (arr[j] == current->num)
				current->index = (j + 1);
			j++;
		}
		current = current->next;
		i++;
	}
}

static int	handle_index(t_stack **stack, size_t stack_size)
{
	long	*arr;
	t_stack	*current;
	int		i;

	arr = (long *)malloc(sizeof(long) * stack_size);
	if (!arr)
		return (ERROR);
	current = *stack;
	i = 0;
	while (1)
	{
		arr[i] = current->num;
		if (current->next == *stack)
			break ;
		current = current->next;
		i++;
	}
	sort_arr(arr, stack_size);
	define_index(arr, stack, stack_size);
	free(arr);
	return (1);
}

void	fill_stack(t_stack **stack, t_list *args_lst, size_t stack_size)
{
	t_stack	*current;

	current = *stack;
	while (args_lst)
	{
		current->num = ft_atoi(args_lst->content);
		current->unset = FALSE;
		current = current->next;
		args_lst = args_lst->next;
	}
	if (handle_index(stack, stack_size) == ERROR)
		handle_error(stack, NULL, &args_lst);
}
