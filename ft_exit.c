/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:54:34 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 22:04:34 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_digit(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

void	ft_exit(t_cmd *cmd)
{
	if (cmd->size == 1)
		g_state.exit_status = 0;
	else if (cmd->size == 2 && check_digit(cmd->node->next->str))
		g_state.exit_status = ft_atoi(cmd->node->str) % 256;
	else if (cmd->size > 1 && !check_digit(cmd->node->next->str))
	{
		ft_putstr_fd("numeric argument required\n", 2);
		g_state.exit_status = -1;
		return ;
	}
	else if (cmd->size > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_state.exit_status = 1;
		return ;
	}
	if (cmd->next && !ft_strcmp(cmd->next->node->str, "|"))
		return ;
	exit(g_state.exit_status % 256);
}
