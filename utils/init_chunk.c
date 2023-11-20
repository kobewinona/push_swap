/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:22:22 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/16 17:22:23 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	*init_chunk(t_stack **stack, size_t stack_size)
{
	ssize_t	min_num;
	ssize_t	max_num;
	t_chunk	*chunk;
	ssize_t	chunks_amount;
	// double	m;
	// double	b;
	// int		num_chunks;

	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	// m = 0.015;
	// b = 3.5;
	// num_chunks = (int)(m * stack_size + b);
	// ft_printf("num_chunks %d\n", num_chunks);
	if (stack_size <= 100)
		chunks_amount = 5;
	else if (stack_size <= 500)
		chunks_amount = 11;
	min_num = 1;
	max_num = find_stack_max(*stack);
	// chunk->size = (max_num - min_num) / num_chunks;
	chunk->size = (max_num - min_num) / chunks_amount;
	if (chunk->size == 0)
		chunk->size = 1;
	chunk->start = min_num;
	chunk->end = chunk->size;
	return (chunk);
}
