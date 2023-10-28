/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:37:41 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/28 19:37:42 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split_argv(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

static void	handle_split_argv(t_list **args, char **split_argv)
{
	char	*content;
	int		i;

	i = 0;
	while (split_argv[i])
	{
		content = ft_strdup(split_argv[i]);
		if (!content)
		{
			print_err_msg(UNKNOWN_ERROR);
			free_split_argv(split_argv);
			ft_lstclear(args, free);
			exit(1);
		}
		ft_lstadd_back(args, ft_lstnew(content));
		free(content);
		i++;
	}
}

t_list	*parse_argv(int argc, char **argv)
{
	t_list	*args;
	char	**split_argv;
	int		i;

	args = NULL;
	i = 0;
	while (i < argc)
	{
		split_argv = ft_split(argv[i++], ' ');
		if (!split_argv)
		{
			print_err_msg(UNKNOWN_ERROR);
			exit(1);
		}
		handle_split_argv(&args, split_argv);
		free_split_argv(split_argv);
	}
	return (args);
}
