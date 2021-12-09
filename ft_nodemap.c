/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:27:04 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 18:31:57 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*ft_nodemap(t_node *node, void *(*f)(void *), void (*del)(void *))
{
	t_node	*new;
	t_node	*map;

	if (!node || !f)
		return (0);
	map = 0;
	while (node)
	{
		new = ft_nodenew((*f)(node->str));
		if (!new)
		{
			ft_nodeclear(&map, del);
			return (0);
		}
		ft_nodeadd_back(&map, new);
		node = node->next;
	}
	return (map);
}
