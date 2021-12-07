/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:58:37 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:01:23 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_sigint(pid_t pid)
{
	if (pid == -1)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		ft_putstr_fd("\n", 1);
}

void	ft_sigquit(pid_t pid)
{
	if (pid == -1)
		return ;
	else
		ft_putstr_fd("Quit: 3\n", 1);
}

// pid_t waitpid(pid_t pid, int *status, int options)
// 실패 시 -1, 성공 시 종료된 자식 프로세스 ID
// 종료 확인 원하는 pid 지정, -1을 넣으면 wait 함수와 같이 자식프로세스가 종료하기를 기다림
// WNOHANG: 기다리는 pid가 종료되지 않아서 즉시 종료 상태를 회수할 수 없는 경우 호출자는 차단되지 않고 반환값으로 0을 받음
void	handle_signal(int signo)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);if (signo == SIGINT)
		ft_sigint(pid);
	if (signo == SIGQUIT)
		ft_sigquit(pid);
}

// Ctrl-C: SIGINT
// Ctrl-\: SIGQUIT
void	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}