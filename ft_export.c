/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:56:14 by suan              #+#    #+#             */
/*   Updated: 2021/12/14 00:01:59 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 변수 이름은 알파벳(대,소 구분), 숫자, _로 만들 수 있다.
// 첫 문자로 숫자가 올 수 없다.
// static? 또는 unset과 공유?
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

int	duplicate(char *key)
{
	int	i;
	int	key_len;

	i = 0;
	key_len = 0;
	while (key[key_len] != '=')
		key_len++;
	while (g_state.env[i] != 0)
	{
		if (!ft_strncmp(g_state.env[i], key, key_len))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

// 이차원 배열에 배열 하나만 추가하는 방법이 있나???
// env 배열 크게 할당하기?
// 키가 중복할 경우 수정하기
static void	set_env(char *new)
{
	char	**temp;
	int		i;

	if (!ft_strchr(new, '='))
		return ;
	temp = (char **)ft_calloc(g_state.env_len + 2, sizeof(char *));
	if (temp == NULL)
		return ;
	i = 0;
	while (i < g_state.env_len)
	{
		temp[i] = ft_strdup(g_state.env[i]);
		if (temp[i] == NULL)
			return ;
		i++;
	}
	temp[i] = ft_strdup(new);
	free(g_state.env);
	g_state.env = temp;
	g_state.env_len += 1;
}

void	ft_export(t_cmd *cmd)
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
			// bash: export: `1': not a valid identifier
			if (!check_key(curr->str))
			{
				printf("minishell: export: not a valid identifier\n");
				g_state.exit_status = 1;
				return ;
			}
			else
				set_env(curr->str);
			curr = curr->next;
		}
	}

	printf("%d\n", g_state.env_len);
	g_state.exit_status = 0;
	return ;
}
