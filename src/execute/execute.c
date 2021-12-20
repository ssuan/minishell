/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/20 19:56:16 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pre_execute(t_cmd *cmd)
{
	t_node	*cur_node;
	t_cmd	*cur_tcmd;
	int		status;
	
	cur_tcmd = cmd;
	g_state.backup_cnt = 1;
	g_state.cmd_cnt = 1;
	g_state.fork = 0;
	while (cur_tcmd != 0)
	{
		cur_node = cur_tcmd->node;
		if (cur_node->flag == PIPE)
			g_state.cmd_cnt++;
		cur_tcmd = cur_tcmd->next;
	}
}

void	connect_redirect(t_cmd *cmd)
{
	t_node	*cur_node;
	t_cmd	*cur_tcmd;
	
	cur_tcmd = cmd;
	cur_node = cur_tcmd->node;
	while (cur_tcmd && cur_node->flag != PIPE)
	{
		cur_node = cur_tcmd->node;
		if (cur_node->flag == REDIR_OUT)
			redirect_out(cur_tcmd->next->node->str);
		else if (cur_node->flag == REDIR_IN)
			redirect_in(cur_tcmd->next->node->str);
		else if (cur_node->flag == REDIR_IN_A)
			redirect_out_append(cur_tcmd->next->node->str);
		// else if (cur_node->flag == REDIR_OUT_A)
		//  	here_doc(cur_node->next);
		cur_tcmd = cur_tcmd->next;
	}
}

void	execute_cmd(t_cmd *cmd)
{
	int		status;
	pid_t	pid;


	if (is_builtin(cmd))
		builtin(cmd);
	else
		non_builtin(cmd);
}

// 파이프, 리다이렉션 처리
void	execute(t_cmd *cmd)
{
	int		fd_stdin;
	int		fd_stdout;
	t_cmd	*cur_tcmd;
	
	pre_execute(cmd);
	cur_tcmd = cmd;
	while (cur_tcmd != 0)
	{
		fd_stdin = dup(STDIN_FILENO);
		fd_stdout = dup(STDOUT_FILENO);		
		if (g_state.cmd_cnt > 1)
			pipe(g_state.pipe_set[1]);
		connect_redirect(cur_tcmd);
		
		if (g_state.exit_status == 1 && g_state.redir_in == -1)
			return ;
			
		execute_cmd(cur_tcmd);
		while (cur_tcmd != 0 && cur_tcmd->next != 0
			&& cur_tcmd->node->flag != PIPE)
			cur_tcmd = cur_tcmd->next;
		cur_tcmd = cur_tcmd->next;
	}
}
