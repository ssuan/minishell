/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:03:55 by suan              #+#    #+#             */
/*   Updated: 2021/12/28 15:53:10 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_path(char *cmd)
{
	char		**paths;
	char		*path;
	char		*temp;
	int			i;
	struct stat	s;

	temp = find_value("PATH");
	if (temp == NULL)
		return (NULL);
	paths = ft_split(temp, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin("/", cmd);
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(path, &s) == 0)
		{
			free_arr2(paths);
			return (path);
		}
		free(path);
	}
	free_arr2(paths);
	return (ft_strdup(cmd));
}

char	**set_cmds(t_cmd *cmd)
{
	t_node	*cur_node;
	char	**cmds;
	int		i;

	cmds = ft_calloc(sizeof(char *), cmd->size + 1);
	if (!cmds)
		return (NULL);
	cur_node = cmd->node;
	i = 0;
	while (cur_node != 0)
	{
		cmds[i] = cur_node->str;
		cur_node = cur_node->next;
		i++;
	}
	return (cmds);
}

int	check_redir_token(t_cmd *cur_tcmd)
{
	if (cur_tcmd->next == NULL)
	{
		print_error_token("newline");
		g_state.exit_status = 258;
		return (FAIL);
	}
	if (cur_tcmd->next->node->flag >= 3)
	{
		print_error_token(cur_tcmd->next->node->str);
		g_state.exit_status = 258;
		return (FAIL);
	}
	return (SUCCESS);
}
