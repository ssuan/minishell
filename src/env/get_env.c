/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:28:44 by suan              #+#    #+#             */
/*   Updated: 2021/12/29 21:55:31 by suan             ###   ########.fr       */
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

// static void	check_var(char **str)
// {
// 	char	*s;
// 	char	*tmp;

// 	s = NULL;
// 	if ((*str)[1] == '?')
// 		s = ft_itoa(g_state.exit_status);
// 	if ((*str)[1] == '0')
// 		s = ft_strdup("minishell");
// 	if (s == NULL)
// 		s = ft_strdup("");
// 	tmp = ft_strjoin(s, *str + 2);
// 	free(*str);
// 	free(s);
// 	*str = tmp;
// }

static char	*div_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	if (ft_isalpha(str[0]) || str[0] != '_')
	{
		while (ft_isalnum(str[i]))
			++i;
	}
	key = ft_calloc(sizeof(char), i + 1);
	ft_strlcpy(key, str, i + 1);
	return (key);
}

static void	check_env(char **str)
{
	int		i;
	char	*key;
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
			key = div_key(*str + i + 1);
			if (!*key)
			{
				value = ft_strdup("$");
				tmp = ft_strjoin(s, value);
				free(s);
				free(value);
				s = tmp;
				break ;
			}
			// 키가 없으면 ($만 들어오는 경우) $ 붙이기
			// check_var 부분도 추가하기
			value = ft_strdup(find_value(key));
			printf("key: %s\n", key);
			printf("value: %s\n", value);
			tmp = ft_strjoin(s, value);
			free(s);
			free(value);
			s = tmp;
			i += (ft_strlen(key) + 1);
			free(key);
		}
		while ((*str)[i] && (*str)[i] != '$')
		{
			value = ft_calloc(2, sizeof(char));
			value[0] = (*str)[i];
			tmp = ft_strjoin(s, value);
			free(s);
			free(value);
			s = tmp;
			printf("(*str)[i]: %c\n", (*str)[i]);
			++i;
		}

	}
	free(*str);
	*str = s;
	// if ((*str)[0] != '$' || (*str)[1] == '\0')
	// 	return ;
	// if (ft_strchr("0123456789?", (*str)[1]))
	// {
	// 	check_var(str);
	// 	return ;
	// }
	// s = find_value(*str + 1);
	// if (s == NULL)
	// 	s = "";
	// free(*str);
	// *str = ft_strdup(s);
	// return ;
}

void	get_env(char **str, int flag)
{
	if (flag == STRING && (*str)[0] == '~')
		check_home(str);
	if (flag == STRING || flag == DQUOTE)
		check_env(str);
}
