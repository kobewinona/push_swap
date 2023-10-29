/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pmt_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:59:47 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 16:59:54 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_pmt_msg(char *pmt_title, char *pmt_msg)
{
	ft_printf("%s", pmt_title);
	write(STDOUT_FILENO, BOLD, ft_strlen(BOLD));
	ft_printf("%s\n", pmt_msg);
	write(STDOUT_FILENO, REGULAR, ft_strlen(REGULAR));
}
