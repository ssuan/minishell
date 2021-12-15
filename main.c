/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/15 14:10:35 by sunbchoi         ###   ########.fr       */
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
		loop = 1;
		cur_node = cur_tcmd->node;
		cur_node->prev = NULL;
		//printf("SIZE [%d] \nNODE = [%s] ", cur_tcmd->size, cur_node->str); 
		while(cur_node != NULL && loop++ < cur_tcmd->size )
		{
			cur_node = cur_node->next;
		//	printf("[%s]", cur_node->str);
		}
		//printf("\n");
		cur_node->next = NULL;
		cur_tcmd = cur_tcmd->next;
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_node	*line_node;
	t_cmd	*tcmd;
	
	t_cmd	*cur_tcmd;
	t_node	*cur_node;
	
	// initialize_data(argc, argv, envp);
	// line_node = parse_line("echo \'abd cc<><\'>> ||| > \' asd bb\'d !! ");
	// tcmd = node_to_cmd(line_node);
	// cmd_connect_break(tcmd);
	// free_cmd(tcmd);
	
	// line_node = parse_line("echo abd ccd");
	// tcmd = node_to_cmd(line_node);
	// cmd_connect_break(tcmd);
	// free_cmd(tcmd);
	
	line_node = parse_line("echo abd ccd");
	tcmd = node_to_cmd(line_node);
	cmd_connect_break(tcmd);
	free_cmd(tcmd);
	
	line_node = parse_line("|||||");
	print_node(line_node);
	tcmd = node_to_cmd(line_node);
	cmd_connect_break(tcmd);
	free_cmd(tcmd);
	// cmd_connect_break(tcmd);
	line_node = parse_line("|||||");
	print_node(line_node);
	tcmd = node_to_cmd(line_node);
	cmd_connect_break(tcmd);
	free_cmd(tcmd);
	line_node = parse_line("|||||");
	print_node(line_node);
	tcmd = node_to_cmd(line_node);
	cmd_connect_break(tcmd);
	free_cmd(tcmd);
	

	system("leaks a.out");
	return (0);
}
