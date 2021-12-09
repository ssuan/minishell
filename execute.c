/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 17:36:25 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_value(char *key)
{
	int		i;
	int		key_len;

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

char	*find_path(char *cmd)
{
	char		**paths;
	char		*path;
	char		*temp;
	int			i;
	struct stat	s;

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
int	execution(char *cmd)
{
	char	*path;
	char	**cmdlines;
	pid_t	pid;
	pid_t	wpid;
	int ret;

	pid = fork();
	if (pid < -1)
		return (-1);
	cmdlines = ft_split(cmd, ' ');
	path = find_path(cmdlines[0]);
	ret = 0;
	if (pid == 0)
	{
		ret = execve(path, cmdlines, g_state.env);
		if (ret == -1)
		{
			ft_putstr_fd("command not found\n", 2); // 에러메시지 수정
			exit(ret);
		}
	}
	if (pid != 0)
	{
		wpid = waitpid(pid, NULL, 0);
	}
	return (0); // 리턴 값
}