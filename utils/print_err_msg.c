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
	write(STDERR_FILENO, BOLD, ft_strlen(BOLD));
	write(STDERR_FILENO, RED_COLOR, ft_strlen(RED_COLOR));
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, RESET_COLOR, ft_strlen(RESET_COLOR));
	write(STDERR_FILENO, REGULAR, ft_strlen(REGULAR));
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}
