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

#include "minishell.h"

static int	get_env(char **str)
{
	char	*s;
    char    *tmp;

    //if (**str == '~') 추가

	if (**str != '$')
		return (FAIL);
    s = NULL;
    (*str)++;
	if (**str == '\0')
		return (FAIL);
	if (ft_strchr("0123456789?", **str))
	{
		if (**str == '?')
            s = ft_itoa(g_state.exit_status);
		if (**str == '0')
            s = ft_strdup("minishell");
        if (s == NULL)
            s = ft_strdup("");
        (*str)++;
        tmp = ft_strjoin(s, *str);
        free(*str); // free 제대로 안됨-> 인덱스로 수정
        free(s);
        *str = tmp;
		return (SUCCESS);
	}
	s = find_value(*str);
    printf("#%s\n", s);
    if (s == NULL)
        s = ft_strdup("");
    //free(*str);
    *str = s;
	return (SUCCESS);
}

void    dollor_to_env(t_cmd *cmd)
{
	t_node	*curr;

	curr = cmd->node;
	while (curr)
	{
        printf("%s\n", curr->str);
        get_env(&(curr->str));
        printf("%s\n", curr->str);
		curr = curr->next;
	}
}
