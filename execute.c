/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/13 21:37:34 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 리다이렉트 처리, 에러메시지 수정
void	non_builtin(t_cmd *cmd)
{
	pid_t	pid;
	char	**cmdlines;
	char	*path;
	int		status;

	pid = fork();
	if (pid < -1)
		return ;
	path = find_path(cmd->node->str);
	cmdlines = set_cmds(cmd);
	if (pid == 0)
	{
		if (execve(path, cmdlines, g_state.env) == -1)
		{
			ft_putstr_fd(cmd->node->str, 2);
			ft_putstr_fd(": command not found\n", 2);
			free_split(cmdlines);
			exit(127);
		}
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_state.exit_status = WEXITSTATUS(status);
	}
	free_split(cmdlines);
}

void	builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit"))
		ft_exit(cmd);
	if (!ft_strcmp(cmd->node->str, "pwd"))
		ft_pwd();
	if (!ft_strcmp(cmd->node->str, "echo"))
		ft_echo(cmd);
	if (!ft_strcmp(cmd->node->str, "env"))
		ft_env();
}

int	is_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit")
		|| !ft_strcmp(cmd->node->str, "pwd")
		|| !ft_strcmp(cmd->node->str, "echo")
		|| !ft_strcmp(cmd->node->str, "env"))
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
//	printf("%d\n", g_state.exit_status);
}
