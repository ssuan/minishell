/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:24:01 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:30:30 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodeiter(t_node *node, void (*f)(void *))
{
	if (!node || !f)
		return ;
	while (node)
	{
		f(node->contents);
		node = node->next;
	}
}
