/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/14 18:14:48 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->size > 1)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd->node->next->str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
	while (i < g_state.env_len)
	{
		ft_putstr_fd(g_state.env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}

void	env_update(char *key, char *value)
{
	int		i;
	int		len;
	char	*new;
	char	*temp;

	i = 0;
	len = ft_strlen(key);
	temp = ft_strjoin(key, "=");
	new = ft_strjoin(temp, value);
	free(temp);
	while (i < g_state.env_len)
	{
		if (!ft_strncmp(key, g_state.env[i], len))
		{
			free(g_state.env[i]);
			g_state.env[i] = ft_strdup(new);
			return ;
		}
		i++;
	}
	return ;
}
