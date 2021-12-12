/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:19:48 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:27:57 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodeclear(t_node **node, void (*del)(void *))
{
	t_node	*curr;
	t_node	*next;

	if (!node || !del)
		return ;
	curr = *node;
	while (curr)
	{
		next = curr->next;
		ft_nodedelone(curr, del);
		curr = next;
	}
	*node = 0;
}
