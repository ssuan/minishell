/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:19:18 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/28 15:37:16 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redirect_in(char *file)
{
	g_state.redir_in = open(file, O_RDONLY);
	if (g_state.redir_in < 0)
	{
		print_error(file, strerror(errno));
		g_state.exit_status = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	redirect_out(char *file)
{
	g_state.redir_out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (g_state.redir_out < 0)
	{
		print_error(file, strerror(errno));
		g_state.exit_status = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	redirect_out_append(char *file)
{
	printf("APPEND IN");
	g_state.redir_out = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (g_state.redir_out < 0)
	{
		print_error(file, strerror(errno));
		g_state.exit_status = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	here_doc(t_cmd *tcmd)
{
	int			fd[2];
	char		*buf;
	pid_t		pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		write(1, "> ", 2);
		while (get_next_line(1, &buf))
		{
			if (!ft_strcmp(buf, tcmd->node->str))
				exit(0);
			write(1, "> ", 2);
			ft_putendl_fd(buf, fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		if (g_state.cmd_cnt == 1)
			wait(0);
	}
}

void	connect_pipe(int fd[2], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}
