/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/15 14:29:02 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// $ 처리(환경변수)
// 수정 끝나면 echo $ 부분 수정하기

// rl_catch_signals = 0;
// If this variable is non-zero, Readline will install signal handlers for
// SIGINT, SIGQUIT, SIGTERM, SIGHUP, SIGALRM, SIGTSTP, SIGTTIN, and SIGTTOU.	
int	main(int argc, char **argv, char **envp)
{
	rl_catch_signals = 0;
	set_signal();
	initialize_data(argc, argv, envp);
	prompt();
	return (0);
}

// cd pwd export unset env exit