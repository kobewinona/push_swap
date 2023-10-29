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
	t_list	*args_lst;
	t_dlist	*args_dclst;
	t_dlist	*temp;
	int		i;

	args_lst = NULL;
	if (argc <= 1)
	{
		print_err_msg(NO_ARGS);
		return (0);
	}
	args_lst = parse_argv((argc - 1), (argv + 1));
	if (!is_argv_valid(args_lst))
	{
		ft_lstclear(&args_lst, free);
		return (0);
	}
	args_dclst = init_struct(args_lst);
	ft_lstclear(&args_lst, free);
	if (!args_dclst)
		return (0);
	temp = args_dclst;
	i = 0;
	while (i < 15)
	{
		ft_printf("%d -> ", temp->num);
		temp = temp->next;
		i++;
	}
	// add dlstclear func to get rid of memory leaks
	ft_lstclear(&args_lst, free);
	return (1);
}
