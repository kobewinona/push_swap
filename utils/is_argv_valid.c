/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argv_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:51:36 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/28 18:51:37 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args && split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

static int	is_arg_valid(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] != '-' && arg[i] != '+' && !ft_isdigit(arg[i]))
		return (FALSE);
	else
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		return (FALSE);
	while (arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_argv_valid(int argc, char **argv)
{
	char	**split_args;
	char	*arg;
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		split_args = NULL;
		split_args = ft_split(argv[i++], ' ');
		if (!split_args)
		{
			print_err_msg(UNKNOWN_ERROR);
			exit(1);
		}
		j = 0;
		while (split_args[j])
		{
			arg = split_args[j++];
			if (!is_arg_valid(arg))
				return (FALSE);
		}
		free_split_args(split_args);
	}
	return (TRUE);
}
