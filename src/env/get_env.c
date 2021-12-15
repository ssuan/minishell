/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/14 19:05:38 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	get_env_value(char **str)
{
	char	*s;
	char	*tmp;
	int		i;

	// if (**str == '~') 추가

	i = 0;
	if ((*str)[i] != '$')
		return (FAIL);
	s = NULL;
	i++;
	if ((*str)[i] == '\0')
		return (FAIL);
	if (ft_strchr("0123456789?", (*str)[i]))
	{
		if ((*str)[i] == '?')
			s = ft_itoa(g_state.exit_status);
		if ((*str)[i] == '0')
			s = ft_strdup("minishell");
		if (s == NULL)
			s = ft_strdup("");
		i++;
		tmp = ft_strjoin(s, *str + i);
		free(*str);
		free(s);
		*str = tmp;
		return (SUCCESS);
	}
	s = find_value(*str + i);
	if (s == NULL)
		s = ft_strdup("");
	free(*str);
	*str = s;
	return (SUCCESS);
}

void get_env(t_cmd *cmd)
{
	t_node *curr;

	curr = cmd->node;
	while (curr)
	{
		get_env_value(&(curr->str)); // check_env?
		curr = curr->next;
	}
}
