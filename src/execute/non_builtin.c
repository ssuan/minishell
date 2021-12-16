/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:14:41 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 02:16:38 by suan             ###   ########.fr       */
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

// 리다이렉트 처리, 에러메시지 수정
void	non_builtin(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < -1)
		return ;
	if (pid == 0)
		exec_cmd(cmd);
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_state.exit_status = WEXITSTATUS(status);
	}
}
