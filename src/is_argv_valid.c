/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argv_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:58:28 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 16:58:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_arg_int(char	*arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i += 1;
	if (!ft_isdigit(arg[i]))
		return (FALSE);
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_arg_bigger_than_int(char	*arg)
{
	long	num;

	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (FALSE);
	return (TRUE);
}

static int	is_arg_duplicated(char *str1, char *str2)
{
	long	num1;
	long	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num1 == num2)
		return (TRUE);
	return (FALSE);
}

static int	is_args_duplicated(t_list *args)
{
	t_list	*current;
	t_list	*next;

	current = args;
	while (current && current->next)
	{
		next = current->next;
		while (next && next->content)
		{
			if (is_arg_duplicated(current->content, next->content))
				return (TRUE);
			next = next->next;
		}
		current = current->next;
	}
	return (FALSE);
}

int	is_argv_valid(t_list *args)
{
	t_list	*curr_arg;

	curr_arg = args;
	while (curr_arg)
	{
		if (!is_arg_int(curr_arg->content))
			return (FALSE);
		if (!is_arg_bigger_than_int(curr_arg->content))
			return (FALSE);
		curr_arg = curr_arg->next;
	}
	if (is_args_duplicated(args))
		return (FALSE);
	return (TRUE);
}
