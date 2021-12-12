/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:27:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 18:31:57 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdmap(t_cmd *cmd, void *(*f)(void *), void (*del)(void *))
{
	t_cmd	*new;
	t_cmd	*map;

	if (!cmd || !f)
		return (0);
	map = 0;
	while (cmd)
	{
		new = ft_cmdnew((*f)(cmd->node));
		if (!new)
		{
			ft_cmdclear(&map, del);
			return (0);
		}
		ft_cmdadd_back(&map, new);
		cmd = cmd->next;
	}
	return (map);
}
