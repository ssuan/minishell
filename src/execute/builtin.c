/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:14:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 02:15:20 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit"))
		ft_exit(cmd);
	if (!ft_strcmp(cmd->node->str, "pwd"))
		g_state.exit_status = ft_pwd();
	if (!ft_strcmp(cmd->node->str, "echo"))
		g_state.exit_status = ft_echo(cmd);
	if (!ft_strcmp(cmd->node->str, "env"))
		g_state.exit_status = ft_env(cmd);
	if (!ft_strcmp(cmd->node->str, "export"))
		g_state.exit_status = ft_export(cmd);
	if (!ft_strcmp(cmd->node->str, "unset"))
		g_state.exit_status = ft_unset(cmd);
	if (!ft_strcmp(cmd->node->str, "cd"))
		g_state.exit_status = ft_cd(cmd);
}

int	is_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit")
		|| !ft_strcmp(cmd->node->str, "pwd")
		|| !ft_strcmp(cmd->node->str, "echo")
		|| !ft_strcmp(cmd->node->str, "env")
		|| !ft_strcmp(cmd->node->str, "export")
		|| !ft_strcmp(cmd->node->str, "unset")
		|| !ft_strcmp(cmd->node->str, "cd"))
		return (TRUE);
	return (FALSE);
}
