/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/10 21:21:57 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cmd_connect_break(t_cmd *tcmd)
{
	int		loop;
	t_node	*cur_node;
	t_cmd	*cur_tcmd;

	cur_tcmd = tcmd;
	while (cur_tcmd != NULL)
	{
		loop = 0;
		cur_node = cur_tcmd->node;
		cur_node->prev = NULL;
		while(loop++ < cur_tcmd->size - 1)
		{
			cur_node = cur_node->next;
		}
		cur_node->next = NULL;
		cur_tcmd = cur_tcmd->next;
	}
	return (0);
}

int cmd_space_check(t_cmd *tcmd)
{
	t_cmd	*cur_cmd;
	char	*str;
	char	*check;

	cur_cmd = tcmd;
	while (cur_cmd != NULL)
	{
		str = cur_cmd->node->str;
		check = ft_strchr(str, ' ');
		if (check != NULL)
		{
			printf("%sspace error%s\n",COLOR_RED,COLOR_NORMAL);
			return (FAIL);
		}
		cur_cmd = cur_cmd->next;
	}
	return (SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	t_node	*line_node;
	t_cmd	*tcmd;
	
	t_cmd	*cur_tcmd;
	t_node	*cur_node;
	
	initialize_data(argc, argv, envp);
	line_node = parse_line("echo \" \"");
	//print_node(line_node);
	tcmd = node_to_cmd(line_node);
	cmd_connect_break(tcmd);
	print_cmd(tcmd);
	
	return (0);
}
