/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/13 01:08:32 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cmd_connect_break(t_cmd *tcmd)
{
	int loop;
	t_node *cur_node;
	t_cmd *cur_tcmd;

	cur_tcmd = tcmd;
	while (cur_tcmd != NULL)
	{
		loop = 0;
		cur_node = cur_tcmd->node;
		cur_node->prev = NULL;
		while (loop++ < cur_tcmd->size - 1)
		{
			cur_node = cur_node->next;
		}
		cur_node->next = NULL;
		cur_tcmd = cur_tcmd->next;
	}
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

// cd pwd export unset env exit