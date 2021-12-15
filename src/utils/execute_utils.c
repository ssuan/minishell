/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:03:55 by suan              #+#    #+#             */
/*   Updated: 2021/12/15 18:04:30 by suan             ###   ########.fr       */
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
			free_split(paths);
			return (path);
		}
		free(path);
	}
	free_split(paths);
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
