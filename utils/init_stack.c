/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:23 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/27 17:06:24 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// some arguments aren’t integers
// some arguments are bigger than an integer
// some arguments are duplicates
// use checker to check all edge cases for invalid arguments

static int	count_elements(int argc, char **argv)
{
	size_t	count;
	char	**split_args;
	int		i;
	int		j;
	
	i = 0;
	count = 0;
	while (i < argc)
	{
		j = 0;
		split_args = ft_split(argv[i], ' ');
		if (split_args)
		{
			while (split_args[j++])
				count++;
		}
		i++;
	}
	return (count);
}

static int	has_dublicates(int *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (stack && stack[i])
	{
		j = 0;
		while (stack[j])
		{
			if (i != j && stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*init_stack(int argc, char **argv)
{
	int		*stack;
	char	**split_args;
	long	num;
	size_t	i;
	size_t	j;
	int		k;

	stack = (int *)malloc((count_elements(argc, argv) + 1) * sizeof(int));
	if (!stack)
		return (NULL);
	split_args = NULL;
	i = 0;
	k = 0;
	while (k < argc)
	{
		split_args = ft_split(argv[k++], ' ');
		if (!split_args)
		{
			free(stack);
			return (NULL);
		}
		j = 0;
		while (split_args && split_args[j])
		{
			num = ft_atol(split_args[j]);
			if (num > INT_MAX)
				return (NULL);
			stack[i] = num;
			i++;
			j++;
		}
	}
	stack[i] = 0;
	if (has_dublicates(stack))
		return (NULL);
	return (stack);
}