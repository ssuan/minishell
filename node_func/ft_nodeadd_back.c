/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:15:06 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:03:58 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodeadd_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!node || !new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	last = ft_lstlast(*node);
	new->next = 0;
	last->next = new;
	new->prev = last;
}
