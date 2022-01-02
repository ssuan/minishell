/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/30 13:36:42 by suan             ###   ########.fr       */
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

static int	check_var(char c, char **value)
{
	int	ret;

	ret = 1;
	if (!c || c == ' ')
		*value = ft_strdup("$");
	else if (ft_strchr("0123456789?$", c))
	{
		if (c == '?')
			*value = ft_itoa(g_state.exit_status);
		else if (c == '0')
			*value = ft_strdup("minishell");
		else
			*value = ft_strdup("");
		++ret;
	}
	return (ret);
}

static int	append_env(char *str, char **s, int i)
{
	char	*key;
	char	*value;
	char	*tmp;
	int		ret;

	if (!str[i] || ft_strchr("0123456789?$ ", str[i]))
		ret = check_var(str[i], &value);
	else
	{
		key = div_key(str + i);
		tmp = find_value(key);
		if (!tmp)
			tmp = "";
		ret = (ft_strlen(key) + 1);
		free(key);
		value = ft_strdup(tmp);
	}
	tmp = ft_strjoin(*s, value);
	free(*s);
	free(value);
	*s = tmp;
	return (ret);
}

static void	check_env(char **str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strdup("");
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			if (!(*str)[i + 1])
			{
				i += append_env(*str, &s, i + 1);
				break ;
			}
			i += append_env(*str, &s, i + 1);
		}
		while ((*str)[i] && (*str)[i] != '$')
			i += append_char(*str, &s, i);
	}
	free(*str);
	*str = s;
}

void	get_env(char **str, int flag)
{
	if (flag == STRING && (*str)[0] == '~' && (!(*str)[1] || (*str)[1] == '/'))
		check_home(str);
	else if (flag == STRING || flag == DQUOTE)
		check_env(str);
}
