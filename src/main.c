/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:47:18 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/28 14:47:19 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// some arguments aren’t integers
// some arguments are bigger than an integer
// some arguments are duplicates
// use checker to check all edge cases for invalid arguments

int	main(int argc, char **argv)
{
	t_list	*args;
	t_list	*temp;

	args = NULL;
	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		print_pmt_msg(VALID_ARGS_PROMPT, VALID_ARGS);
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
