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
	t_list	*args;
	t_list	*temp;

	args = NULL;
	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		return (0);
	}
	args = parse_argv((argc - 1), (argv + 1));
	if (!is_argv_valid(args))
	{
		ft_lstclear(&args, free);
		return (0);
	}
	temp = args;
	while (temp)
	{
		ft_printf("%s -> ", temp->content);
		temp = temp->next;
	}
	ft_lstclear(&args, free);
	return (1);
}
