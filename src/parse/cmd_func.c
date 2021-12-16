/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:49:22 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/15 14:22:43 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*process_cmd_logic(t_node **node, t_cmd **tcmd)
{
	t_cmd	*cur_tcmd;
	t_cmd	*nxt_tcmd;
	t_node	*cur_node;

	cur_tcmd = *tcmd;
	cur_node = *node;
	nxt_tcmd = ft_cmdnew(NULL);
	ft_cmdadd_back(tcmd, nxt_tcmd);
	cur_tcmd = nxt_tcmd;
	cur_tcmd->node = cur_node;
	cur_tcmd->size = 1;
	if ((cur_node->next != NULL)
		&& (ft_strchr(SPECIFIER, cur_node->next->str[0]) == 0))
	{
		nxt_tcmd = ft_cmdnew(NULL);
		ft_cmdadd_back(tcmd, nxt_tcmd);
		cur_tcmd = nxt_tcmd;
	}
	return (cur_tcmd);
}

t_cmd	*node_to_cmd(t_node *node)
{
	t_cmd	*tcmd;
	t_cmd	*cur_tcmd;
	t_node	*cur_node;
	t_node	*nxt_node;

	tcmd = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	cur_tcmd = tcmd;
	cur_node = node->next;
	while (cur_node != 0)
	{
		if (cur_tcmd->node == 0)
		{	
			cur_tcmd->node = cur_node;
			cur_tcmd->size = 1;
		}
		else if (ft_strchr(SPECIFIER, (int)cur_node->str[0]) != NULL)
			cur_tcmd = process_cmd_logic(&cur_node, &cur_tcmd);
		else
			cur_tcmd->size++;
		cur_node = cur_node->next;
	}
	free(node);
	return (tcmd);
}
