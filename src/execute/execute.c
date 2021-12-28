/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/28 14:51:58 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pre_execute(t_cmd *cmd)
{
	t_node	*cur_node;
	t_cmd	*cur_tcmd;
	
	cur_tcmd = cmd;
	g_state.backup_cnt = 1;
	g_state.cmd_cnt = 1;
	g_state.fork = 0;
	while (cur_tcmd != 0)
	{
		cur_node = cur_tcmd->node;
		if (cur_node->flag == PIPE)
		{
			if (!cur_tcmd->prev || (cur_tcmd->prev && cur_tcmd->prev->node->flag >= 3)
			|| !cur_tcmd->next || (cur_tcmd->next && cur_tcmd->next->node->flag >= 3))
				{
					ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
					g_state.exit_status = 258;
					return (FAIL);
				}
			g_state.cmd_cnt++;
		}
		cur_tcmd = cur_tcmd->next;
	}
	return (SUCCESS);
}

int	connect_redirect(t_cmd *cmd)
{
	t_node	*cur_node;
	t_cmd	*cur_tcmd;
	int		redir_check;
	
	cur_tcmd = cmd;
	cur_node = cur_tcmd->node;
	redir_check = 0;
	g_state.redir_in = 0;
	g_state.redir_out = 1;
	while (cur_tcmd && redir_check == 0)
	{
		cur_node = cur_tcmd->node;
		if (cur_node->flag > 3)
			redir_check = 1;
		if (redir_check && cur_tcmd->next == NULL)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
			g_state.exit_status = 258;
			return (FAIL);
		}
		if (redir_check && cur_tcmd->next->node->flag >= 3)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(cur_tcmd->next->node->str, 2);
			ft_putstr_fd("'\n", 2);
			g_state.exit_status = 258;
			return (FAIL);
		}
		if (cur_node->flag == REDIR_OUT)
			redirect_out(cur_tcmd->next->node->str);
		else if (cur_node->flag == REDIR_IN)
			redirect_in(cur_tcmd->next->node->str);
		else if (cur_node->flag == REDIR_OUT_A)
			redirect_out_append(cur_tcmd->next->node->str);
		else if (cur_node->flag == REDIR_IN_A)
		 	here_doc(cur_tcmd->next);
		cur_tcmd = cur_tcmd->next;
	}
	return (SUCCESS);
}

void	execute_cmd(t_cmd *cmd)
{
	connect_redirect(cmd);
	if (g_state.exit_status == 1 && g_state.redir_in == -1)
		return ;
	if (is_builtin(cmd))
		builtin_div(cmd);
	else
		non_builtin(cmd);
}

void
	backup_execute(int *stdin, int *stdout)
{
	g_state.pipe_set[0][0] = g_state.pipe_set[1][0];
	g_state.pipe_set[0][1] = g_state.pipe_set[1][1];
	dup2(*stdin, STDIN_FILENO);
	dup2(*stdout, STDOUT_FILENO);
	close(*stdin);
	close(*stdout);
	g_state.backup_cnt++;
}

void	execute(t_cmd *cmd)
{
	int		fd_stdin;
	int		fd_stdout;
	int		status;
	t_cmd	*cur_tcmd;
	
	if (pre_execute(cmd) == FAIL)
		return ;
	cur_tcmd = cmd;
	while (cur_tcmd != 0)
	{
		fd_stdin = dup(STDIN_FILENO);
		fd_stdout = dup(STDOUT_FILENO);		
		if (g_state.cmd_cnt > 1)
			pipe(g_state.pipe_set[1]);
		execute_cmd(cur_tcmd);
		backup_execute(&fd_stdin, &fd_stdout);
		while (cur_tcmd != 0 && cur_tcmd->next != 0
			&& cur_tcmd->node->flag != PIPE)
			cur_tcmd = cur_tcmd->next;
		cur_tcmd = cur_tcmd->next;
	}
	if (g_state.fork)
	{
		while (waitpid(-1, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				g_state.exit_status = WEXITSTATUS(status);
		}
	}
}
