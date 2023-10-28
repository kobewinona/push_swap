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

static int	update_stack(t_dlist **stack, long num)
{
	t_dlist	*new_node;
	t_dlist	*last_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_node)
		return (ERROR);
	new_node->num = num;
	new_node->next = NULL;
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		new_node->prev = last_node;
		last_node->next = new_node;
	}
	return (1);
}

static int	is_element_valid(char *element)
{
	int	i;

	i = 0;
	while (element && element[i] != '\0')
	{
		if (!ft_isdigit(element[i]) && !ft_isspace(element[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_dlist	*init_stack(int argc, char **argv)
{
	t_dlist	*stack;
	char	**split_args;
	char	*element;
	int		i;
	int		j;

	stack = NULL;
	i = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i++], ' ');
		if (!split_args)
			return (NULL);
		j = 0;
		while (split_args && split_args[j])
		{
			element = split_args[j++];
			if (!is_element_valid(element))
			{
				print_err_msg(INVALID_ARGS);
				return (NULL);
			}
			if (update_stack(&stack, ft_atol(element)) == ERROR)
			{
				print_err_msg(UNKNOWN_ERROR);
				return (NULL);
			}
		}
	}
	return (stack);
}
