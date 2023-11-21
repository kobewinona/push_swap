/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:58:46 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 16:58:55 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	handle_split_argv(t_list **args, char **split_argv)
{
	char	*content;
	int		i;
	t_list	*new_node;

	i = 0;
	while (split_argv[i])
	{
		content = ft_strdup(split_argv[i]);
		if (!content)
			return (0);
		new_node = ft_lstnew(content);
		if (!new_node)
			return (0);
		ft_lstadd_back(args, new_node);
		i++;
	}
	return (1);
}

t_list	*parse_argv(int argc, char **argv)
{
	t_list	*args;
	char	**split_argv;
	int		i;

	i = 0;
	args = NULL;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv)
			return (NULL);
		if (!split_argv[0])
		{
			free_double_arr(split_argv);
			return (NULL);
		}
		if (!handle_split_argv(&args, split_argv))
		{
			free_double_arr(split_argv);
			return (NULL);
		}
		free_double_arr(split_argv);
		i++;
	}
	return (args);
}
