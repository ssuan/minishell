/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:53:41 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/14 19:34:05 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	free_node(t_node *node)
{
	t_node	*cur_node;
	t_node	*nxt_node;
	char	*str;

	cur_node = node;
	while (cur_node != 0)
	{
		nxt_node = cur_node->next;
		str = cur_node->str;
		if (str != NULL)
			free(str);
		free(cur_node);
		cur_node = nxt_node;
	}
	return (SUCCESS);
}

int	free_cmd(t_cmd *tcmd)
{
	t_node	*cur_node;
	t_node	*nxt_node;
	t_cmd	*cur_cmd;
	t_cmd	*nxt_cmd;

	cur_cmd = tcmd;
	while (cur_cmd != 0)
	{
		cur_node = cur_cmd->node;
		while (cur_node != NULL)
		{
			if (cur_node->str != NULL)
				free(cur_node->str);
			nxt_node = cur_node->next;
			free(cur_node);
			cur_node = nxt_node;
		}
		nxt_cmd = cur_cmd->next;
		free(cur_cmd);
		cur_cmd = nxt_cmd;
	}
	return (0);
}
