/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_space_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:23:01 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/12/10 21:23:38 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int cmd_space_check(t_cmd *tcmd)
{
	t_cmd	*cur_cmd;
	char	*str;
	char	*check;

	cur_cmd = tcmd;
	while (cur_cmd != NULL)
	{
		str = cur_cmd->node->str;
		check = ft_strchr(str, ' ');
		if (check != NULL)
		{
			printf("%sspace error%s\n",COLOR_RED,COLOR_NORMAL);
			return (FAIL);
		}
		cur_cmd = cur_cmd->next;
	}
	return (SUCCESS);
}