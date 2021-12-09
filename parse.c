/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/09 17:55:29 by sunbchoi         ###   ########.fr       */
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


char	*process_qoute(char *line)
{
	char	*pos;
	int		str_len;
	char	*sub_str;

	pos = ft_strchr(line + 1, (int)*line);
	if (pos == NULL)
	{
		printf("%s%s%s\n", COLOR_RED, STR_SINGLE_QUOTE_ERR,COLOR_NORMAL);
		//free(필요)
		return (FAIL);
	}
	else
	{
		str_len = pos - (line + 1);	
		sub_str = ft_substr(line + 1, 0, str_len);
		if (sub_str == NULL)
			return (NULL);
	}
	return (sub_str);
}

int	process_pipe(t_node *node,char *line, char *save_str)
{
	char	*node_str;

	if (save_str != NULL && *save_str != 0)
	{
		node_str = ft_strdup(save_str);
		ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
		free(save_str);
	}
	node_str = ft_strdup("|");
	ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
	return (1);
}

int process_redir(t_node *node,char *line, char *save_str)
{
	char	*node_str;

	if (save_str != NULL && *save_str != 0)
	{
		node_str = ft_strdup(save_str);	
		ft_nodeadd_back(&node, ft_nodenew((char *)node_str));
		free(save_str);
	}
	if((*(line + 1) != 0 ) && *line == *(line + 1))
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


t_node	*parse_cmd(char *line)
{
	t_node	*tmp_node;
	char	*tmp_str;
	char	*save_str;
	char	*free_str;

	save_str = 0;
	tmp_node = (t_node *)ft_calloc(1, sizeof(t_node));
	while (*line != 0)
	{
	//	printf("CUR[%c]\n", *line);
		if(*line == ' ')
		{
			if (save_str != NULL && *save_str != 0)
			{
				tmp_str = ft_strdup(save_str);
				ft_nodeadd_back(&tmp_node, ft_nodenew((char *)tmp_str));
				free(save_str);
				save_str = 0;
			}
			line++;
		}
		else if(*line == '\'' || *line == '\"')
		{
			if (save_str == NULL)
			{
			//	printf("[!]");
				save_str = ft_strdup("");
			}
			tmp_str = process_qoute(line);
			if (!tmp_str)
				return (FAIL);
			free_str = save_str;
			save_str = ft_strjoin(save_str, tmp_str);
			line += ft_strlen(save_str) + 1 + 1;
			free(tmp_str);
			free(free_str);
		}
		else if(*line == '|' )
		{
			line += process_pipe(tmp_node, line, save_str);
			save_str = 0;
		}
		else if(*line == '<' || *line == '>')
		{
			line += process_redir(tmp_node, line, save_str);
			save_str = 0;
		}
		else
		{
			if (save_str == NULL)
				save_str = ft_strdup("");
			free_str = save_str;
			tmp_str = (char *)ft_calloc(2, sizeof(char));
			tmp_str[0] = *line;
			save_str = ft_strjoin(save_str, tmp_str);
			line++;
			free(free_str);
			free(tmp_str);
		}
	}
	if (save_str != NULL && *save_str != 0)
	{
		tmp_str = ft_strdup(save_str);
		ft_nodeadd_back(&tmp_node, ft_nodenew((char *)tmp_str));
		free(save_str);
	}
	while (tmp_node != 0)
	{
		tmp_node = tmp_node->next;
		if(tmp_node != 0)
			printf("node[%s]\n", tmp_node->contents);
	}
	return (0);
}