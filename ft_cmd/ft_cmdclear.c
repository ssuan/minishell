/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:19:48 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:27:26 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_cmdclear(t_cmd **cmd, void (*del)(void *))
{
	t_cmd	*curr;
	t_cmd	*next;

	if (!cmd || !del)
		return ;
	curr = *cmd;
	while (curr)
	{
		next = curr->next;
		ft_cmddelone(curr, del);
		curr = next;
	}
	*cmd = 0;
}
