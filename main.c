/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/16 02:17:47 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// rl_catch_signals = 0;
// If this variable is non-zero, Readline will install signal handlers for
// SIGINT, SIGQUIT, SIGTERM, SIGHUP, SIGALRM, SIGTSTP, SIGTTIN, and SIGTTOU.	
int	main(int argc, char **argv, char **envp)
{
	rl_catch_signals = 0;
	set_signal();
	init_env(argc, argv, envp);
	prompt();
	return (0);
}
