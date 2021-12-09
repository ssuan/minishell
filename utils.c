/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:20:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 15:26:16 by suan             ###   ########.fr       */
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
	if (space == (int)ft_strlen(s))
		return (1);
	return (0);
}
