/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:16:32 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/07 15:11:28 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_seting(char **envp)
{
	int	loop;

	loop = 0;
	while (envp[loop] != 0)
		loop++;
	g_state.env_len = loop;
	g_state.env = (char **)ft_calloc(g_state.env_len + 1, sizeof(char *));
	if (g_state.env == NULL)
		return (FAIL);
	loop = 0;
	while (loop < g_state.env_len)
	{
		g_state.env[loop] = ft_strdup(envp[loop]);
		if (g_state.env[loop] == NULL)
			error(STR_ENV_SETTING_ERR);
		loop++;
	}
	return (SUCCESS);
}

int	initialize_data(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	env_seting(envp);
	return (SUCCESS);
}
