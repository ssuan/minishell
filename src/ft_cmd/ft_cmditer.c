/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmditer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:24:01 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:27:33 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cmditer(t_cmd *cmd, void (*f)(void *))
{
	if (!cmd || !f)
		return ;
	while (cmd)
	{
		f(cmd->node);
		cmd = cmd->next;
	}
}
