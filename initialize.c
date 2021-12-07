/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:16:32 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/07 14:57:54 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_seting(char **envp)
{
	int	loop;
	int	len;

	loop = 0;
	while (envp[loop] != 0)
		loop++;
	len = loop;
	g_state.env = (char **)ft_calloc(len + 1, sizeof(char *));
	if (g_state.env == NULL)
		return (FAIL);
	loop = 0;
	while (loop < len)
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
