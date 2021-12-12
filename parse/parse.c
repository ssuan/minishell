/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/13 01:31:33 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	check_syntax_space(char *line)
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
	{
		error_keep("SPACE_ERROR\n");
		return (FAIL);
	}
	else if (**line == '|'
		&& parse_pipe(line, save_str, line_node) == 0)
	{	
		error_keep("PIPE_ERROR\n");
		return (FAIL);
	}
	else if ((**line == '<' || **line == '>')
		&& parse_redir(line, save_str, line_node) == 0)
	{	
		error_keep("REDIR_ERROR\n");
		return (FAIL);
	}
	else if ((**line == '\'' || **line == '\"')
		&& parse_qoute(line, save_str, line_node) == 0)
	{	
		error_keep("QOUTE_ERROR\n");
		return (FAIL);
	}
	return (SUCCESS);
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
		if (ft_strchr(" |\'\"<>", *line) != 0)
		{	
			if (logic_specifi(&line, &save_str, tmp_node) == 0)
				error_keep("KEEP ERROR");
		}
		else
			save_str_join(&line, &save_str);
	}
	if (save_str_node(tmp_node, &save_str) == 0)
		return (0);
	return (tmp_node);
}

// t_cmd	*node_to_cmd(t_node *node)
// {
// 	t_cmd	*ret_tcmd;
// 	t_cmd	*cur_tcmd;
// 	t_cmd	*nxt_tcmd;
// 	t_node	*cur_node;
// 	t_node	*tmp_node;

// 	ret_tcmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
// 	cur_tcmd = ret_tcmd;
// 	cur_node = node->next;
// 	while (cur_node != 0)
// 	{
// 		if (cur_tcmd->node == NULL)
// 			cur_tcmd->node = cur_node;
// 		if (ft_strchr(SPECIFIER, (int)cur_node->str[0]) != NULL)
// 		{
// 			if (cur_node->next != NULL)
// 			{
// 				nxt_tcmd = ft_cmdnew(NULL);
// 				ft_cmdadd_back(&ret_tcmd, nxt_tcmd);
// 				cur_tcmd = nxt_tcmd;
// 				cur_tcmd->node = cur_node;
// 				cur_tcmd->size = 1;
				
// 				nxt_tcmd = ft_cmdnew(NULL);
// 				ft_cmdadd_back(&ret_tcmd, nxt_tcmd);
// 				cur_tcmd = nxt_tcmd;			
// 			}
// 			else
// 			{
// 				printf("break\n");
// 				break ;
// 			}
// 		}
// 		else
// 			cur_tcmd->size++;
// 		cur_node = cur_node->next;
// 	}
// 	return (ret_tcmd);
// }
