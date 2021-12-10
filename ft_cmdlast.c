/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:11:50 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 13:41:10 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
 
t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}
