/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:53:41 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/13 01:59:28 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

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