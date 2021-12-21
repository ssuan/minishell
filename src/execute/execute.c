/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:16:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/21 18:48:16 by suan             ###   ########.fr       */
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
			if (!cur_tcmd->prev || (cur_tcmd->prev && cur_tcmd->prev->node->flag >= 4)
			|| !cur_tcmd->next || (cur_tcmd->next && cur_tcmd->next->node->flag >= 4))
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
	while (cur_tcmd && redir_check == 0)
	{
		cur_node = cur_tcmd->node;
		print_cmd(cur_tcmd);
		if (cur_node->flag > 3)
			redir_check = 1;
		if (redir_check && cur_tcmd->next == NULL)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
			g_state.exit_status = 258;
			return (FAIL);
		}
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
	return (SUCCESS);
}

void	execute_cmd(t_cmd *cmd)
{
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
	
	if (pre_execute(cmd) == FAIL)
		return ;
	cur_tcmd = cmd;
	while (cur_tcmd != 0)
	{
		fd_stdin = dup(STDIN_FILENO);
		fd_stdout = dup(STDOUT_FILENO);		
		if (g_state.cmd_cnt > 1)
			pipe(g_state.pipe_set[1]);
		if (connect_redirect(cur_tcmd) == FAIL)
			return ;
		
		if (g_state.exit_status == 1 && g_state.redir_in == -1)
			return ;
			
		execute_cmd(cur_tcmd);
		while (cur_tcmd != 0 && cur_tcmd->next != 0
			&& cur_tcmd->node->flag != PIPE)
			cur_tcmd = cur_tcmd->next;
		cur_tcmd = cur_tcmd->next;
	}
}
