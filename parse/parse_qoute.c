/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_qoute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:44:55 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/12 21:54:31 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"


char	*process_qoute(char *line)
{
	char	*pos;
	int		str_len;
	char	*sub_str;

	pos = ft_strchr(line + 1, (int)*line);
	if (pos == NULL)
	{	
		error_keep(STR_SINGLE_QUOTE_ERR);
		return (FAIL);
	}
	else
	{
		str_len = pos - (line + 1);	
		sub_str = ft_substr(line + 1, 0, str_len);
		if (sub_str == NULL)
			return (FAIL);
	}
	return (sub_str);
}

int parse_qoute(char **line, char **save_str, t_node *line_node)
{
	char	*sub_str;
	char	*free_str;

	if (*save_str == NULL)
		*save_str = ft_strdup("");
	sub_str = process_qoute(*line);
	if (!sub_str)
		return (FAIL);
	free_str = *save_str;
	*line += ft_strlen(sub_str) + 1 + 1;
	*save_str = ft_strjoin(*save_str, sub_str);
	free(sub_str);
	free(free_str);
	return (SUCCESS);
}
