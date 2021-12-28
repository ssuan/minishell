/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:54:34 by suan              #+#    #+#             */
/*   Updated: 2021/12/28 17:48:47 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_digit(char *s)
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
		g_state.exit_status = ft_atoi(cmd->node->next->str);
	else if (cmd->size > 1 && !check_digit(cmd->node->next->str))
	{
		print_error2("exit", cmd->node->next->str, "numeric argument required");
		g_state.exit_status = 255;
	}
	else if (cmd->size > 2)
	{
		print_error("exit", "too many arguments");
		g_state.exit_status = 1;
		return ;
	}
	if ((cmd->next && cmd->next->node->flag == PIPE)
		|| (cmd->prev && cmd->prev->node->flag == PIPE))
		return ;
	ft_putstr_fd("exit\n", 2);
	exit(g_state.exit_status % 256);
}
