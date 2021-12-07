/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/07 17:19:41 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int main(int argc, char **argv, char **envp)
{
	int loop;

	loop = 0;

	initialize_data(argc, argv, envp);
	while (g_state.env[loop] != 0)
	{
		printf("[%d] = [%s]\n", loop, g_state.env[loop]);
		loop++;
	}
	error("TEST");
}*/

int	check_space(char *s)
{
	if (*s == '\0')
		return (FALSE);
	while (*s)
	{
		if (*s == 32 || (*s >= 9 && *s <= 13))
			return (FALSE);
		s++;
	}
	return (TRUE);
}

int main(void)
{
	char	*line;
	
	rl_catch_signals = 0; 
	// If this variable is non-zero, Readline will install signal handlers for SIGINT, SIGQUIT, SIGTERM, SIGHUP, SIGALRM, SIGTSTP, SIGTTIN, and SIGTTOU.
	set_signal();
	while ((line = readline("minishell$ ")))
	{
		if (check_space(line))
			add_history(line);
		free(line);
	}

	// "\x1b[A": UP, "\x1b[B": DOWN, "\x1b[C": RIGHT, "\x1b[D": LEFT
	// \x1b == \033
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\x1b[11C", 1);
	ft_putstr_fd("exit\n", 1);
	return (0);
}
