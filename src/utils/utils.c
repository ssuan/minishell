/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/21 14:26:09 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// 2차원 배열 free
int	free_arr2(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (0);
}

int	check_space(char *s)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	if (s[0] == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == '\r' || s[i] == '\v' || s[i] == '\t'
			|| s[i] == '\f')
			return (1);
		else if (s[i] == ' ')
			space++;
		i++;
	}
	if (space == (int)ft_strlen(s))
		return (1);
	return (0);
}

int	cmd_space_check(t_cmd *tcmd)
{
	t_cmd	*cur_cmd;
	char	*str;
	char	*check;

	cur_cmd = tcmd;
	while (cur_cmd != NULL)
	{
		str = cur_cmd->node->str;
		check = ft_strchr(str, ' ');
		if (check != NULL)
		{
			printf("%sspace error%s\n", COLOR_RED, COLOR_NORMAL);
			return (FAIL);
		}
		cur_cmd = cur_cmd->next;
	}
	return (SUCCESS);
}
