/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:41:08 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/14 19:34:18 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	save_str_node(t_node *node, char **save_str)
{
	char	*temp_str;

	if (*save_str != NULL && **save_str != 0)
	{
		temp_str = ft_strdup(*save_str);
		if (temp_str == NULL)
			return (FAIL);
		ft_nodeadd_back(&node, ft_nodenew((char *)temp_str));
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

	if (*save_str == NULL)
		*save_str = ft_strdup("");
	if (*save_str == NULL)
		return (0);
	free_str = *save_str;
	tmp_str = (char *)ft_calloc(2, sizeof(char));
	tmp_str[0] = **line;
	*save_str = ft_strjoin(*save_str, tmp_str);
	(*line)++;
	free(free_str);
	free(tmp_str);
	return (SUCCESS);
}
