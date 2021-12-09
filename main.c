/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/09 17:27:08 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt(void)
{
	char	*line;

	// exit 입력하면 종료
	while ((line = readline("\033[34mminishell$ \033[0m")))
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
