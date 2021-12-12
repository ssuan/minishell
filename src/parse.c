/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/10 20:30:54 by sunbchoi         ###   ########.fr       */
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
		//free(실패시 필요)
		//return (FAIL);
		exit(1);
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


t_node	*parse_line(char *line)
{
	t_node	*tmp_node;
	char	*tmp_str;
	char	*save_str;
	char	*free_str;

	save_str = 0;
	tmp_node = (t_node *)ft_calloc(1, sizeof(t_node));
	while (*line != 0)
	{
		if(*line == ' ')
		{
			if (save_str != NULL && *save_str != 0)
			{
				tmp_str = ft_strdup(save_str);
				ft_nodeadd_back(&tmp_node, ft_nodenew((char *)tmp_str));
				// tmp_str = ft_strchr(save_str, ' ');
				// if (tmp_str != NULL) // -> 에러 로직 변경 해야될 수도있음
				// 	printf("%s%s is not commad%s", COLOR_RED, save_str, COLOR_NORMAL);
				free(save_str);
				save_str = 0;
			}
			line++;
		}
		else if(*line == '\'' || *line == '\"')
		{
			if (save_str == NULL)
				save_str = ft_strdup("");
			tmp_str = process_qoute(line);
			if (!tmp_str)
				return (FAIL);
			free_str = save_str;
			line += ft_strlen(tmp_str) + 1 + 1;
			save_str = ft_strjoin(save_str, tmp_str);
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
	return (tmp_node);
}

t_cmd	*node_to_cmd(t_node *node)
{
	t_cmd	*ret_tcmd;
	t_cmd	*cur_tcmd;
	t_cmd	*nxt_tcmd;
	t_node	*cur_node;
	t_node	*tmp_node;
	
	ret_tcmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	cur_tcmd = ret_tcmd;
	cur_node = node->next;
	while (cur_node != 0)
	{
		if (cur_tcmd->node == NULL)
			cur_tcmd->node = cur_node;
		if (ft_strchr(SPECIFIER, (int)cur_node->str[0]) != NULL)
		{
			if (cur_node->next != NULL)
			{
				//SPEC
				nxt_tcmd = ft_cmdnew(NULL);
				ft_cmdadd_back(&ret_tcmd, nxt_tcmd);
				cur_tcmd = nxt_tcmd;
				cur_tcmd->node = cur_node;
				cur_tcmd->size = 1;
				//NEW
				nxt_tcmd = ft_cmdnew(NULL);
				ft_cmdadd_back(&ret_tcmd, nxt_tcmd);
				cur_tcmd = nxt_tcmd;			
			}
			else
			{
				printf("break\n");	
				break ;
			}
		}
		else
			cur_tcmd->size++;
		cur_node = cur_node->next;	
	}
	return (ret_tcmd);
}
