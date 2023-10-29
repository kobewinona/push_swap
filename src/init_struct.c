/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:30:58 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 17:30:59 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	convert_dlst_into_circular(t_dlist **dlst)
{
	t_dlist	*head;
	t_dlist	*current;
	t_dlist	*tail;

	head = *dlst;
	current = head;
	while (current->next)
		current = current->next;
	tail = current;
	if (head && tail)
	{
		head->prev = tail;
		tail->next = head;
	}
}

t_dlist	*init_struct(t_list *args_lst)
{
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist	*new_node;

	head = NULL;
	tail = NULL;
	while (args_lst)
	{
		new_node = ft_dlstnew(ft_atoi(args_lst->content));
		if (!new_node)
			return (NULL);
		if (!head)
		{
			head = new_node;
			tail = head;
		}
		else
		{
			ft_dlstadd_back(&tail, new_node);
			tail = new_node;
		}
		args_lst = args_lst->next;
	}
	convert_dlst_into_circular(&head);
	return (head);
}
