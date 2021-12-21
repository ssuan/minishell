/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/21 18:05:52 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cmd_connect_break(t_cmd *tcmd)
{
	int		loop;
	t_node	*cur_node;
	t_cmd	*cur_tcmd;

	cur_tcmd = tcmd;
	while (cur_tcmd != NULL)
	{
		loop = 1;
		cur_node = cur_tcmd->node;
		cur_node->prev = NULL;
		while (cur_node != NULL && loop++ < cur_tcmd->size)
			cur_node = cur_node->next;
		cur_node->next = NULL;
		cur_tcmd = cur_tcmd->next;
	}
	return (0);
}

int	check_syntax_space(char *line) // 안쓰는 함수?
{
	int	space;
	int	loop;

	space = 0;
	loop = 0;
	if (line == NULL || line[0] == 0)
		return (FAIL);
	while (line[loop])
	{
		if (line[loop] == '\r' || line[loop] == '\v' || line[loop] == '\t'
			|| line[loop] == '\f')
			return (FAIL);
		else if (line[loop] == ' ')
			space++;
		loop++;
	}
	if (space == (int)ft_strlen(line))
		return (FAIL);
	return (SUCCESS);
}

int	logic_specifi(char **line, char **save_str, t_node *line_node)
{
	if ((**line == ' '
			&& parse_space(line, save_str, line_node) == 0))
		return (FAIL);
	else if (**line == '|'
		&& parse_pipe(line, save_str, line_node) == 0)
		return (FAIL);
	else if ((**line == '<' || **line == '>')
		&& parse_redir(line, save_str, line_node) == 0)
		return (FAIL);
	else if ((**line == '\'' || **line == '\"')
		&& parse_quote(line, save_str, line_node) == 0)
		return (FAIL);
	return (SUCCESS);
}

t_node	*parse_line(char *line)
{
	t_node	*tmp_node;
	char	*save_str;

	save_str = 0;
	tmp_node = (t_node *)ft_calloc(1, sizeof(t_node));
	while (*line != 0)
	{
		if (ft_strchr(" |\'\"<>", *line) != 0)
		{	
			if (logic_specifi(&line, &save_str, tmp_node) == 0)
			{	
				free_node(tmp_node);
				return (FAIL);
			}
		}
		else
			save_str_join(&line, &save_str);
	}
	if (save_str_node(tmp_node, &save_str) == 0)
		return (0);
	return (tmp_node);
}

t_cmd	*parsing(char *line)
{
	t_node	*line_node;
	t_cmd	*tcmd;

	line_node = parse_line(line);
	if (!line_node)
		return (0);
	
	print_node(line_node);
	tcmd = node_to_cmd(line_node);
	if (tcmd->node == 0)
	{
		tcmd->node = (t_node *)ft_calloc(sizeof(t_node), 1);
		tcmd->node->str = ft_strdup("");
	}
	cmd_connect_break(tcmd);
	return (tcmd);
}
