/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:16:02 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/29 21:58:53 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse_space(char **line, char **save_str, t_node *line_node)
{
	char	*sub_str;

	if (**line == ' ')
	{
		if (*save_str != 0 && **save_str != 0)
		{
			sub_str = ft_strdup(*save_str);
			if (!sub_str)
				return (0);

	get_env(&sub_str, g_state.flag);
			ft_nodeadd_back(&line_node,
				ft_nodenew((char *)sub_str, g_state.flag));
			g_state.flag = 0;
			free(*save_str);
			*save_str = 0;
		}
	}
	(*line)++;
	return (SUCCESS);
}
