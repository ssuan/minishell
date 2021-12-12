/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:16:02 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/12 21:41:55 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int parse_space(char **line, char **save_str, t_node *line_node)
{
	char	*sub_str;

	if(**line == ' ')
	{
		if (*save_str != NULL && **save_str != 0)
		{
			sub_str = ft_strdup(*save_str);
			ft_nodeadd_back(&line_node, ft_nodenew((char *)sub_str));
			free(*save_str);
			*save_str = 0;
		}
		(*line)++;
	}
	return (0);
}
