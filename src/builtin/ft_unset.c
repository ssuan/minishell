/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:02:34 by suan              #+#    #+#             */
/*   Updated: 2021/12/15 16:24:43 by suan             ###   ########.fr       */
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

// 이차원 배열에 배열 하나만 추가하는 방법이 있나???
// 환경변수 파싱할때 크게 메모리 할당하기?

// find_key 변수 만들기?
// 아니면 len 변수 없애기??
// line 수 줄이기
static void	unset_env(char *key)
{
	char	**temp;
	int		flag;
	int		i;
	int		idx;
	int		len;

	temp = (char **)ft_calloc(g_state.env_len + 1, sizeof(char *));
	if (temp == NULL)
		return ;
	i = -1;
	idx = 0;
	flag = 0;
	len = ft_strlen(key);
	while (++i < g_state.env_len)
	{
		if (!ft_strncmp(key, g_state.env[i], len))
		{
			flag++;
			free(g_state.env[i]);
		}
		else
		{
			temp[idx] = ft_strdup(g_state.env[i]);
			free(g_state.env[i]);
			if (temp[idx] == NULL)
				return ;
			idx++;
		}
	}
	free(g_state.env);
	g_state.env = temp;
	g_state.env_len -= flag;
}

// err msg
// bash: export: `1': not a valid identifier
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
				printf("minishell: unset: not a valid identifier\n");
				return (1);
			}
			else
				unset_env(curr->str);
			curr = curr->next;
		}
	}
	return (0);
}
