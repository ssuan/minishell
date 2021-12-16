/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 15:50:26 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	check_home(char **str)
{
	char	*s;

	s = find_value("HOME");
	if (s == NULL)
		s = "";
	free(*str);
	*str = ft_strjoin(s, *str + 1);
}

static void	check_var(char **str)
{
	char	*s;
	char	*tmp;

	s = NULL;
	if ((*str)[1] == '?')
		s = ft_itoa(g_state.exit_status);
	if ((*str)[1] == '0')
		s = ft_strdup("minishell");
	if (s == NULL)
		s = ft_strdup("");
	tmp = ft_strjoin(s, *str + 2);
	free(*str);
	free(s);
	*str = tmp;
}

static void	check_env(char **str)
{
	char	*s;
	char	*tmp;

	if ((*str)[0] == '~')
	{
		check_home(str);
		return ;
	}
	if ((*str)[0] != '$' || (*str)[1] == '\0')
		return ;
	if (ft_strchr("0123456789?", (*str)[1]))
	{
		check_var(str);
		return ;
	}
	s = find_value(*str + 1);
	if (s == NULL)
		s = "";
	free(*str);
	*str = ft_strdup(s);
	return ;
}

void	get_env(t_cmd *cmd)
{
	t_node	*curr;

	curr = cmd->node;
	while (curr)
	{
		if (curr->flag == STRING || curr->flag == DQUOTE)
			check_env(&(curr->str));
		curr = curr->next;
	}
}
