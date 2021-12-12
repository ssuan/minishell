/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:24:30 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 20:34:51 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new)
{
	if (!cmd || !new)
		return ;
	new->next = *cmd;
	new->prev = NULL;
	(*cmd)->prev = new;
	*cmd = new;
}
