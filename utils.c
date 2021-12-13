/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/13 22:22:24 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 2차원 배열 free
int	free_split(char **s)
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
	if (space == ft_strlen(s))
		return (1);
	return (0);
}
