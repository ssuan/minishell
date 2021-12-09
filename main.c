/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/09 17:12:01 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

// int main(int argc, char **argv, char **envp)
// {
// 	int loop;

// 	loop = 0;

// 	initialize_data(argc, argv, envp);
// 	while (g_state.env[loop] != 0)
// 	{
// 		printf("[%d] = [%s]\n", loop, g_state.env[loop]);
// 		loop++;
// 	}
// 	error("TEST");
// }

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
		ret = execve(path, cmdlines, NULL);
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

int	prompt(void)
{
	char	*line;

	while ((line = readline("minishell$ ")))
	{
		if (!check_space(line))
		{
			add_history(line);
			execution(line);
		}
		free(line);
	}
	// "\x1b[A": UP, "\x1b[B": DOWN, "\x1b[C": RIGHT, "\x1b[D": LEFT
	// \x1b == \033
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\x1b[11C", 1);
	ft_putstr_fd("exit\n", 1);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	rl_catch_signals = 0; 
	// If this variable is non-zero, Readline will install signal handlers for SIGINT, SIGQUIT, SIGTERM, SIGHUP, SIGALRM, SIGTSTP, SIGTTIN, and SIGTTOU.
	set_signal();
	initialize_data(argc, argv, envp);
	prompt();
	return (0);
}
