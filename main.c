/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/29 20:59:02 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// rl_catch_signals = 0;
// If this variable is non-zero, Readline will install signal handlers for
// SIGINT, SIGQUIT, SIGTERM, SIGHUP, SIGALRM, SIGTSTP, SIGTTIN, and SIGTTOU.	
int	main(int argc, char **argv, char **envp)
{
	rl_catch_signals = 0;
	//set_signal();
	init_env(envp);
	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
	{
		launch_minishell(argv[2]);
		return (g_state.exit_status);
	}
	prompt();
	return (0);
}
