/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:41:08 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/30 18:23:31 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	save_str_node(t_node *node, char **save_str)
{
	char	*temp_str;

	if (*save_str != NULL)
	{
		temp_str = ft_strdup(*save_str);
		if (temp_str == NULL)
			return (FAIL);
		ft_nodeadd_back(&node, ft_nodenew((char *)temp_str, g_state.flag));
		g_state.flag = 0;
		free(*save_str);
		*save_str = 0;
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	save_str_join(char **line, char **save_str)
{
	char	*free_str;
	char	*tmp_str;
	int		i;

	if (*save_str == NULL)
		*save_str = ft_strdup("");
	if (*save_str == NULL)
		return (0);
	free_str = *save_str;
	i = 0;
	while (!ft_strchr(" |\'\"<>", (*line)[i]))
		++i;
	tmp_str = (char *)ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(tmp_str, *line, i + 1);
	get_env(&tmp_str, g_state.flag);
	*save_str = ft_strjoin(*save_str, tmp_str);
	*line += i;
	free(free_str);
	free(tmp_str);
	return (SUCCESS);
}
