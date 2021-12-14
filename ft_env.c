/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/14 16:23:28 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->size > 1)
	{
		ft_putstr_fd("env: ", 1);
		ft_putstr_fd(cmd->node->next->str, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		return (127);
	}
	while (i < g_state.env_len)
	{
		ft_putstr_fd(g_state.env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
