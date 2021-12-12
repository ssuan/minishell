/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:30:32 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/13 01:23:30 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	process_redir(t_node *node, char *line, char *save_str)
{
	char	*node_str;

	if (save_str_node(node, &save_str) == 0)
		return (0);
	if ((*(line + 1) != 0 ) && *line == *(line + 1))
	{
		node_str = (char *)ft_calloc(3, sizeof(char));
		node_str[0] = *line;
		node_str[1] = *line;
		ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
		return (2);
	}
	else
	{
		node_str = (char *)ft_calloc(2, sizeof(char));
		node_str[0] = *line;
		ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
		return (1);
	}
	return (0);
}

int	parse_redir(char **line, char **save_str, t_node *line_node)
{
	int	check;

	check = process_redir(line_node, *line, *save_str);
	if (check == FAIL)
		return (FAIL);
	*line += check;
	*save_str = 0;
	return (SUCCESS);
}
