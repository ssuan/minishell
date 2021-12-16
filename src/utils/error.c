/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:43:31 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/16 02:17:14 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	error(char *msg)
{
	printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
	exit (EXIT_FAILURE);
	return (0);
}

int	error_keep(char *msg)
{
	printf("%sError: %s %s\n", COLOR_RED, msg, COLOR_NORMAL);
	return (0);
}

void	print_error(char *command, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	print_error_exit(char *command, char *msg, int exit_status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(exit_status);
}

void	print_error2(char *command, char *input, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	print_error3(char *command, char *input, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd("\': ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
