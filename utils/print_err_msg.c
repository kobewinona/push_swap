/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:59:29 by dklimkin          #+#    #+#             */
/*   Updated: 2023/10/29 16:59:37 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_err_msg(char *err_msg)
{
	write(STDOUT_FILENO, BOLD, ft_strlen(BOLD));
	write(STDOUT_FILENO, RED_COLOR, ft_strlen(RED_COLOR));
	write(STDOUT_FILENO, "Error: ", 7);
	write(STDOUT_FILENO, RESET_COLOR, ft_strlen(RESET_COLOR));
	write(STDOUT_FILENO, REGULAR, ft_strlen(REGULAR));
	ft_printf("%s\n", err_msg);
}
