/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/30 02:04:17 by suan             ###   ########.fr       */
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

static char	*div_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	if (ft_isalpha(str[0]) || str[0] == '_')
	{
		while (ft_isalnum(str[i]))
			++i;
	}
	key = ft_calloc(sizeof(char), i + 1);
	ft_strlcpy(key, str, i + 1);
	return (key);
}

static int	append_env(char *str, char **s, int i)
{
	char	*key;
	char	*value;
	char	*tmp;

	if (!str[i])
		value = ft_strdup("$");
	else if (ft_strchr("0123456789?$", str[i + 1]))
	{
		if (str[i] == '?')
			value = ft_itoa(g_state.exit_status);
		else if (str[i] == '0')
			value = ft_strdup("minishell");
		else
			value = ft_strdup("");
		++i;
	}
	else
	{
		key = div_key(str + i);
		tmp = find_value(key);
		if (!tmp)
			tmp = "";
		i += (ft_strlen(key));
		free(key);
		value = ft_strdup(tmp);
	}
	tmp = ft_strjoin(*s, value);
	free(*s);
	free(value);
	*s = tmp;
	return (i);
}

// static void	check_env(char **str)
// {
// 	int		i;
// 	char	*key;
// 	char	*value;
// 	char	*s;
// 	char	*tmp;

// 	i = 0;
// 	s = ft_strdup("");
// 	while ((*str)[i])
// 	{
// 		if ((*str)[i] != '$')
// 		{
// 			while ((*str)[i] && (*str)[i] == '$')
// 				++i;
// 		}
// 		if ((*str)[i] == '$')
// 		{
// 			if (!(*str)[i + 1])
// 			{
// 				value = ft_strdup("$");
// 				tmp = ft_strjoin(s, value);
// 				free(s);
// 				free(value);
// 				s = tmp;
// 				break ;
// 			}
// 			if (ft_strchr("0123456789?$", (*str)[i + 1]))
// 			{
// 				if ((*str)[i + 1] == '?')
// 					value = ft_itoa(g_state.exit_status);
// 				else if ((*str)[i + 1] == '0')
// 					value = ft_strdup("minishell");
// 				else
// 					value = ft_strdup("");
// 				i += 2;
// 			}
// 			else
// 			{
// 				key = div_key(*str + i + 1);
// 				tmp = find_value(key);
// 				if (!tmp)
// 					tmp = "";
// 				i += (ft_strlen(key) + 1);
// 				free(key);
// 				value = ft_strdup(tmp);
// 			}
// 			tmp = ft_strjoin(s, value);
// 			free(s);
// 			free(value);
// 			s = tmp;
// 		}
// 		while ((*str)[i] && (*str)[i] != '$')
// 		{
// 			value = ft_calloc(2, sizeof(char));
// 			value[0] = (*str)[i];
// 			++i;
// 			tmp = ft_strjoin(s, value);
// 			free(s);
// 			free(value);
// 			s = tmp;
// 		}
// 	}
// 	free(*str);
// 	*str = s;
// }

static void	check_env(char **str)
{
	int		i;
	char	*value;
	char	*s;
	char	*tmp;

	i = 0;
	s = ft_strdup("");
	while ((*str)[i])
	{
		if ((*str)[i] != '$')
		{
			while ((*str)[i] && (*str)[i] == '$')
				++i;
		}
		if ((*str)[i] == '$')
		{
			if (!(*str)[i + 1])
			{
				i = append_env(*str, &s, i + 1);
				break ;
			}
			i = append_env(*str, &s, i + 1);
		}
		while ((*str)[i] && (*str)[i] != '$')
		{
			value = ft_calloc(2, sizeof(char));
			value[0] = (*str)[i];
			++i;
			tmp = ft_strjoin(s, value);
			free(s);
			free(value);
			s = tmp;
		}
	}
	free(*str);
	*str = s;
}

void	get_env(char **str, int flag)
{
	if (flag == STRING && (*str)[0] == '~')
		check_home(str);
	if (flag == STRING || flag == DQUOTE)
		check_env(str);
}
