/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:12:25 by suan              #+#    #+#             */
/*   Updated: 2021/12/13 23:05:53 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(void)
{
	int		i;
	char	**copy;

	copy = (char **)ft_calloc(g_state.env_len + 1, sizeof(char *));
	if (copy == NULL)
		return (FAIL);
	i = 0;
	while (i < g_state.env_len)
	{
		copy[i] = ft_strdup(g_state.env[i]);
		if (copy[i] == NULL)
			return (FAIL);
		i++;
	}
	return (copy);
}

void	sort_env(char ***env)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while ((*env)[i])
	{
		j = i + 1;
		while ((*env)[j])
		{
			if (ft_strcmp((*env)[i], (*env)[j]) > 0)
			{
				swap = (*env)[i];
				(*env)[i] = (*env)[j];
				(*env)[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	print_export(void)
{
	int		i;
	char	**env;
	char	**split;

	env = copy_env();
	sort_env(&env);
	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			split = ft_split(env[i], '=');
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(split[0], 1);
			ft_putchar_fd('=', 1);
			ft_putchar_fd('\"', 1);
			ft_putstr_fd(split[1], 1);
			ft_putchar_fd('\"', 1);
			ft_putchar_fd('\n', 1);
			free_split(split);
		}
		i++;
	}
	free_split(env);
}
