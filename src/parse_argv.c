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
			print_pmt_msg(RESTART_PROMPT, "");
			free_double_arr(split_argv);
			ft_lstclear(args, free);
			exit(1);
		}
		ft_lstadd_back(args, ft_lstnew(content));
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
			print_pmt_msg(RESTART_PROMPT, "");
			exit(1);
		}
		handle_split_argv(&args, split_argv);
		free_double_arr(split_argv);
	}
	return (args);
}
