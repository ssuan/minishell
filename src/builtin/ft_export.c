/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:56:14 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 01:28:10 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// 변수 이름은 알파벳(대,소 구분), 숫자, _로 만들 수 있다.
// 첫 문자로 숫자가 올 수 없다.
static int	is_valid_key(char *key)
{
	int	i;

	if (!ft_isalpha(*key) && *key != '_')
		return (FALSE);
	i = 1;
	while (key[i] && key[i] != '=')
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_key_exist(char *str)
{
	int	i;
	int	key_len;

	i = 0;
	key_len = 0;
	while (str[key_len] != '=')
		key_len++;
	while (g_state.env[i] != 0)
	{
		if (!ft_strncmp(g_state.env[i], str, key_len))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	update_value(char *new)
{
	int		i;
	char	*key;
	int		len;

	i = 0;
	key = get_key(new);
	len = ft_strlen(key);
	free(key);
	while (i < g_state.env_len)
	{
		if (!ft_strncmp(new, g_state.env[i], len))
		{
			free(g_state.env[i]);
			g_state.env[i] = ft_strdup(new);
			return ;
		}
		i++;
	}
	return ;
}

static void	set_env(char *new)
{
	char	**temp;
	int		i;

	if (!ft_strchr(new, '='))
		return ;
	if (is_key_exist(new))
	{
		update_value(new);
		return ;
	}
	temp = (char **)ft_calloc(g_state.env_len + 2, sizeof(char *));
	if (temp == NULL)
		return ;
	i = -1;
	while (++i < g_state.env_len)
	{
		temp[i] = ft_strdup(g_state.env[i]);
		free(g_state.env[i]);
		if (temp[i] == NULL)
			return ;
	}
	temp[i] = ft_strdup(new);
	free(g_state.env);
	g_state.env = temp;
	g_state.env_len += 1;
}

int	ft_export(t_cmd *cmd)
{
	t_node	*curr;
	char	**split;

	if (cmd->size == 1)
		print_export();
	else
	{
		curr = cmd->node->next;
		while (curr)
		{
			if (!is_valid_key(curr->str))
			{
				print_error3("export", curr->str, "not a valid identifier");
				return (1);
			}
			else
				set_env(curr->str);
			curr = curr->next;
		}
	}
	return (0);
}
