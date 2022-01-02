/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:14:41 by suan              #+#    #+#             */
/*   Updated: 2022/01/02 22:24:15 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//https://www.it-note.kr/173
static void	exec_file(char *file)
{
	char		*cmd[2];
	struct stat	s;

	cmd[0] = file;
	cmd[1] = 0;
	if (stat(file, &s) == 0)
	{
		if (S_ISDIR(s.st_mode))
			print_error_exit(cmd[0], "is a directory", 126);
		else if (S_ISREG(s.st_mode))
		{
			if (!(s.st_mode & S_IXUSR))
				print_error_exit(cmd[0], "Permission denied", 126);
			if (execve(file, cmd, g_state.env) == -1)
				print_error_exit(cmd[0], "command not found", 127);
		}
	}
	print_error_exit(cmd[0], "No such file or directory", 127);
}

static void	exec_cmd(t_cmd *cmd)
{
	char	**cmdlines;
	char	*path;
	int		ret;

	if (!ft_strcmp(cmd->node->str, "."))
		print_error_exit(cmd->node->str, "filename argument required", 2);
	if (ft_strchr(cmd->node->str, '/'))
		exec_file(cmd->node->str);
	path = find_path(cmd->node->str);
	if (path == NULL)
		print_error_exit(cmd->node->str, "No such file or directory", 127);
	cmdlines = set_cmds(cmd);
	ret = execve(path, cmdlines, g_state.env);
	free(path);
	free(cmdlines);
	if (ret == -1)
		print_error_exit(cmd->node->str, "command not found", 127);
}

void	set_pipe(void)
{
	if (g_state.backup_cnt != 1 && g_state.redir_in == 0 && \
		g_state.exit_status != -1)
		connect_pipe(g_state.pipe_set[0], STDIN_FILENO);
	if (g_state.backup_cnt < g_state.cmd_cnt && g_state.redir_out == 1 && \
		g_state.exit_status != -1)
		connect_pipe(g_state.pipe_set[1], STDOUT_FILENO);
	if (g_state.redir_in != 0)
	{
		dup2(g_state.redir_in, STDIN_FILENO);
		close(g_state.redir_in);
	}
	if (g_state.redir_out != 1)
	{
		dup2(g_state.redir_out, STDOUT_FILENO);
		close(g_state.redir_out);
	}
}

// 리다이렉트 처리, 에러메시지 수정
void	non_builtin(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	g_state.fork = 1;
	pid = fork();
	if (pid < -1)
		return ;
	if (pid == 0)
	{
		set_pipe();
		exec_cmd(cmd);
	}
	else
		close(g_state.pipe_set[1][1]);
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_state.exit_status = WEXITSTATUS(status);
	}
}
