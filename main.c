/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/10 21:00:27 by sunbchoi         ###   ########.fr       */
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

int prompt(void)
{
	char *line;

	t_node *line_node;
	t_cmd *tcmd;

	// exit 입력하면 종료
	while ((line = readline("\033[34mminishell$ \033[0m")))
	{
		if (!check_space(line))
		{
			line_node = parse_line(line);
			// print_node(line_node);
			tcmd = node_to_cmd(line_node);
			cmd_connect_break(tcmd);
			// print_cmd(tcmd);
			// tcmd = parsing(line);
			add_history(line);
			execution(tcmd);
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
