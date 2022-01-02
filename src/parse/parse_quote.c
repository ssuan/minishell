/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:44:55 by sunbchoi          #+#    #+#             */
/*   Updated: 2022/01/02 23:07:49 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*process_quote(char *line)
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

static void	quote_flag(char c)
{
	if (c == '\'')
		g_state.flag = SQUOTE;
	if (c == '\"')
		g_state.flag = DQUOTE;
}

int	parse_quote(char **line, char **save_str)
{
	char	*sub_str;
	char	*free_str;

	quote_flag(**line);
	sub_str = process_quote(*line);
	if (!sub_str)
	{
		if (*save_str)
		{
			free(*save_str);
			*save_str = NULL;
		}
		return (FAIL);
	}
	if (*save_str == NULL)
		*save_str = ft_strdup("");
	free_str = *save_str;
	*line += ft_strlen(sub_str) + 1 + 1;
	get_env(&sub_str, g_state.flag);
	g_state.flag = 0;
	*save_str = ft_strjoin(*save_str, sub_str);
	free(sub_str);
	free(free_str);
	return (SUCCESS);
}
