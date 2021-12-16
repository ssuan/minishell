/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:44:55 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/16 18:28:49 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*process_quote(char *line)
{
	char	*pos;
	int		str_len;
	char	*sub_str;

	pos = ft_strchr(line + 1, (int)*line);
	if (pos == NULL)
	{
		print_error("quote", "This Syntex has only one quote charictor");
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

int	parse_quote(char **line, char **save_str, t_node *line_node)
{
	char	*sub_str;
	char	*free_str;

	if (**line == '\'')
		g_state.flag = SQUOTE;
	if (**line == '\"')
		g_state.flag = DQUOTE;
	sub_str = process_quote(*line);
	if (!sub_str)
	{
		if (*save_str)
		{
			free(*save_str);
			*save_str = 0;
		}
		return (FAIL);
	}
	if (*save_str == NULL)
		*save_str = ft_strdup("");
	free_str = *save_str;
	*line += ft_strlen(sub_str) + 1 + 1;
	*save_str = ft_strjoin(*save_str, sub_str);
	free(sub_str);
	free(free_str);
	return (SUCCESS);
}
