/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 22:17:13 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
