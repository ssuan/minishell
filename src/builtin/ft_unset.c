/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:02:34 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 01:20:16 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// 변수 이름은 알파벳(대,소 구분), 숫자, _로 만들 수 있다.
// 첫 문자로 숫자가 올 수 없다.
static int	check_key(char *key)
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

static int	is_same_key(char *key, char *env)
{
	int	key_len;

	key_len = ft_strlen(key);
	if (!ft_strncmp(key, env, key_len))
		return (TRUE);
	return (FALSE);
}

static void	unset_env(char *key)
{
	char	**temp;
	int		flag;
	int		i;
	int		idx;

	temp = (char **)ft_calloc(g_state.env_len + 1, sizeof(char *));
	if (temp == NULL)
		return ;
	i = -1;
	idx = 0;
	flag = 0;
	while (++i < g_state.env_len)
	{
		if (is_same_key(key, g_state.env[i]))
			flag++;
		else
		{
			temp[idx] = ft_strdup(g_state.env[i]);
			if (temp[idx] == NULL)
				return ;
			idx++;
		}
		free(g_state.env[i]);
	}
	free(g_state.env);
	g_state.env = temp;
	g_state.env_len -= flag;
}

int	ft_unset(t_cmd *cmd)
{
	t_node	*curr;
	char	**split;

	if (cmd->size == 1)
		return (0);
	else
	{
		curr = cmd->node->next;
		while (curr)
		{
			if (!check_key(curr->str))
			{
				print_error3("unset", curr->str, "not a valid identifier");
				return (1);
			}
			else
				unset_env(curr->str);
			curr = curr->next;
		}
	}
	return (0);
}
