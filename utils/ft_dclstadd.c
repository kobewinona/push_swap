/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:46:11 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 17:46:12 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ft_dlstnew(long value)
{
	t_dlist	*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->num = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new_node)
{
	t_dlist	*current;

	if (!new_node)
		return ;
	if (!(*dlst))
	{
		(*dlst) = new_node;
		(*dlst)->next = NULL;
		(*dlst)->prev = NULL;
	}
	else
	{
		current = *dlst;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
		new_node->next = NULL;
	}
}
