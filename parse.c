/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/09 12:27:23 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_syntax_space(char *line)
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


char	*process_qoute(t_cmd *cmd, char *line)
{
	char	*pos;
	int		cmd_len;
	char	*sub_str;

	pos = ft_strchr(line + 1, (int)*line);
	if (pos == NULL)
	{	
		printf("%s%s%s\n", COLOR_RED, STR_SINGLE_QUOTE_ERR,COLOR_NORMAL);
		return (FAIL);
	}
	else
	{
		cmd_len = pos - (line + 1);
		if (cmd != NULL)
			sub_str = ft_substr(line + 1, 0, cmd_len);
	}
	return (sub_str);
}

t_cmd	*parse_cmd(char *line)
{
	t_cmd	*cmd;
	char	*pos;
	t_node	*tmp_node;
	char	*tmp_str;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	tmp_node = (t_node *)ft_calloc(1, sizeof(t_node));
	while (*line != 0)
	{
		if(*line == ' ')
			line++;
		if(*line == '\'' || *line == '\"')
		{
			tmp_str = process_qoute(cmd, line);
			if (!tmp_str)
				return (FAIL);
			ft_nodeadd_back(&tmp_node, ft_nodenew((char *) tmp_str));
			printf("SUB[%s]\n", tmp_str);
		}

	}
	
	
	// if (check_space(line) == NULL)
	// {
	// 	free(line); // 가정 -> get_next_line에서 사용 할수도 있음
	// 	return (FAIL);
	// }
	
}