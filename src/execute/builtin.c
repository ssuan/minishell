/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:14:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/28 17:46:27 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	exec_builtin(t_cmd *cmd)
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

static void	fork_builtin(t_cmd *tcmd)
{
	pid_t	pid;

	g_state.fork = 1;
	pid = fork();
	if (pid == 0)
	{
		set_pipe();
		exec_builtin(tcmd);
		exit(g_state.exit_status);
	}
	else if (g_state.backup_cnt != 1)
	{
		close(g_state.pipe_set[0][0]);
		close(g_state.pipe_set[0][1]);
	}
}

void	builtin(t_cmd *tcmd)
{
	t_node	*cur_node;

	cur_node = tcmd->node;
	if (!ft_strcmp(cur_node->str, "pwd") || \
		!ft_strcmp(cur_node->str, "echo") || \
		!ft_strcmp(cur_node->str, "env"))
	{
		fork_builtin(tcmd);
	}
	else if (!ft_strcmp(cur_node->str, "exit"))
	{
		exec_builtin(tcmd);
	}
	else if (tcmd->next && !ft_strcmp(cur_node->str, "export"))
	{
		fork_builtin(tcmd);
	}
	else if (!ft_strcmp(cur_node->str, "cd") || \
			!ft_strcmp(cur_node->str, "export") || \
			(!ft_strcmp(cur_node->str, "unset") && g_state.cmd_cnt == 1))
	{
		set_pipe();
		exec_builtin(tcmd);
	}
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
