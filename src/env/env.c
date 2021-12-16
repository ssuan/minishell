/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:58:39 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 17:32:30 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_value(char *key)
{
	int	i;
	int	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (g_state.env[i] != 0)
	{
		if (!ft_strncmp(g_state.env[i], key, key_len))
			return (g_state.env[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

// str: key=value 형식
// 사용 후 free
char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=')
		i++;
	key = ft_calloc(sizeof(char), i + 1);
	ft_strlcpy(key, str, i + 1);
	return (key);
}

// 사용 후 free
char	*get_value(char *str)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	while (str[i] != '=')
		i++;
	len = ft_strlen(str);
	value = ft_calloc(sizeof(char), len - i + 1);
	ft_strlcpy(value, str + i + 1, len - i + 1);
	return (value);
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
