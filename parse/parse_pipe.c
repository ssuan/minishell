/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:02:49 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/14 16:04:05 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	process_pipe(t_node *node, char *line, char *save_str)
{
	char	*node_str;

	if (save_str_node(node, &save_str) == 0)
		return (0);
	node_str = ft_strdup("|");
	if (node_str == 0)
		return (FAIL);
	ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
	return (1);
}

int	parse_pipe(char **line, char **save_str, t_node *line_node)
{
	int	check;

	check = process_pipe(line_node, *line, *save_str);
	if (check == FAIL)
		return (FAIL);
	*line += 1;
	*save_str = 0;
	return (SUCCESS);
}
