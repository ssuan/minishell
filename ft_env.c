/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/13 21:38:07 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	int	i;

	i = 0;
	while (i < g_state.env_len)
	{
		ft_putstr_fd(g_state.env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	g_state.exit_status = 0;
}