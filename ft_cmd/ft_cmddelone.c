/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmddelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:18:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 18:31:06 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_cmddelone(t_cmd *cmd, void (*del)(void *))
{
	if (!cmd || !del)
		return ;
	del(cmd->node);
	free(cmd);
}
