/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 17:32:16 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->size > 1)
	{
		print_error2("env", cmd->node->next->str, "No such file or directory");
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
