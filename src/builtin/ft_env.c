/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 02:13:10 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->size > 1)
	{
		print_error2("env", cmd->node->next->str, "No such file or directory");
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
			g_state.env[i] = new;
			return ;
		}
		i++;
	}
	return ;
}
