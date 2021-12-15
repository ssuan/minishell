/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/15 16:50:29 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// 리다이렉트 처리, 에러메시지 수정
void	non_builtin(t_cmd *cmd)
{
	pid_t	pid;
	char	**cmdlines;
	char	*path;
	int		status;
	int		ret;

	pid = fork();
	if (pid < -1)
		return ;
	if (pid == 0)
	{
		path = find_path(cmd->node->str);
		cmdlines = set_cmds(cmd);
		ret = execve(path, cmdlines, g_state.env);
		free(path);
		free(cmdlines);
		if (ret == -1)
		{
			ft_putstr_fd(cmd->node->str, 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}		
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_state.exit_status = WEXITSTATUS(status);
	}
}

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

void	execution(t_cmd *cmd)
{
	char	*path;
	int		ret;

	if (is_builtin(cmd))
		builtin(cmd);
	else
		non_builtin(cmd);
}
