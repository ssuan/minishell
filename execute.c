/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/10 15:22:14 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_value(char *key)
{
	int i;
	int key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (g_state.env[i] != 0)
	{
		if (!ft_strncmp(g_state.env[i], key, key_len))
			return (g_state.env[i] + key_len + 1); // 1: =
		i++;
	}
	return (NULL);
}

char *find_path(char *cmd)
{
	char **paths;
	char *path;
	char *temp;
	int i;
	struct stat s;

	temp = find_value("PATH");
	paths = ft_split(temp, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin("/", cmd);
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(path, &s) == 0)
			return (path);
		free(path);
	}
	return (ft_strdup(cmd));
}

// 빌트인 함수 확인, 리다이렉트 처리, 리턴 값, 에러메시지 수정
// int	execution(char **cmd)로 수정, split 함수 제거
// 리턴 값
int non_builtin(t_cmd *cmd)
{
	char **cmdlines;
	char *path;
	pid_t pid;
	pid_t wpid;
	int ret;

	pid = fork();
	if (pid < -1)
		return (-1);
	path = find_path(cmd->node->str);
	cmdlines = set_cmds(cmd);
	if (pid == 0)
	{
		ret = execve(path, cmdlines, g_state.env);
		if (ret == -1)
		{
			ft_putstr_fd(cmd->node->str, 2);		  // 에러메시지 수정
			ft_putstr_fd(": command not found\n", 2); // 에러메시지 수정
			exit(ret);
		}
	}
	if (pid != 0)
	{
		wpid = waitpid(pid, NULL, 0);
	}

	// 함수로 빼기
	int i = -1;
	while (cmdlines[++i])
		free(cmdlines[i]);
	free(cmdlines);
	return (0);
}

int builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit"))
		ft_exit(cmd);
	if (!ft_strcmp(cmd->node->str, "pwd"))
		ft_pwd();
	return (0);
}

int is_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->node->str, "exit") || !ft_strcmp(cmd->node->str, "pwd"))
		return (TRUE);
	return (FALSE);
}

// 빌트인 함수 확인, 리다이렉트 처리, 리턴 값, 에러메시지 수정
int execution(t_cmd *cmd)
{
	char *path;
	int ret;

	if (is_builtin(cmd))
		builtin(cmd);
	else
		non_builtin(cmd);

	return (0); // 리턴 값
}
