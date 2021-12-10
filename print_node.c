/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:07:22 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/10 18:51:26 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_node(t_node *line_node)
{
	t_node	*cur_node;

	/* NODE CHECK */
	cur_node = line_node;
	while (cur_node->next != 0)
	{
		cur_node = cur_node->next;
		if(cur_node != 0)
		printf("node[%s]\n", cur_node->str);
	}	
	printf("-----PREV CHECK-------");
	// NODE PREV
	while (cur_node != 0)
	{
		if(cur_node != 0)
		printf("node[%s]\n", cur_node->str);
		cur_node = cur_node->prev;
	}
	printf("________________");
}
	
void	print_cmd(t_cmd *tcmd)
{
	t_cmd	*cur_tcmd;
	t_node	*cur_node;
	int		loop;

	cur_tcmd = tcmd;
	while (cur_tcmd != 0)
	{
		cur_node = cur_tcmd->node;
		loop = 0;
		while (cur_node != NULL)
		{
			printf("[%s]", cur_node->str);
			cur_node = cur_node->next;
		}
		printf("\n");
		cur_tcmd = cur_tcmd->next;
	}
	printf("________________\n");
}